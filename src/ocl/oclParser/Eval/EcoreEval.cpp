#include "EcoreEval.h"

#include <iostream>
#include <algorithm>
//#include <abstractDataTypes/Any.hpp>
#include <ecore/EcoreAny.hpp>
#include <ecore/EcoreContainerAny.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EObject.hpp>

#include "../Utilities/ConstStrings.h"
#include "../Utilities/OclConversion.h"
#include "EcoreEnvironment.h"

#include <ocl/Expressions/ExpressionInOcl.hpp>

// LiteralExp
#include <ocl/Expressions/EnumLiteralExp.hpp>
#include <ocl/Expressions/NullLiteralExp.hpp>
#include <ocl/Expressions/InvalidLiteralExp.hpp>
#include <ocl/Expressions/PrimitiveLiteralExp.hpp>
#include <ocl/Expressions/BooleanLiteralExp.hpp>
#include <ocl/Expressions/StringLiteralExp.hpp>
#include <ocl/Expressions/RealLiteralExp.hpp>
#include <ocl/Expressions/UnlimitedNaturalExp.hpp>
#include <ocl/Expressions/IntegerLiteralExp.hpp>
#include <ocl/Expressions/CollectionLiteralExp.hpp>
#include <ocl/Expressions/CollectionLiteralParts.hpp>
#include <ocl/Expressions/CollectionRange.hpp>
#include <ocl/Expressions/CollectionItem.hpp>
#include <ocl/Expressions/TupleLiteralExp.hpp>
#include <ocl/Expressions/TupleLiteralPart.hpp>

// CallExp
#include <ocl/Expressions/AssociationClassCallExp.hpp>
#include <ocl/Expressions/PropertyCallExp.hpp>
#include <ocl/Expressions/OperationCallExp.hpp>
#include <ocl/Expressions/IteratorExp.hpp>
#include <ocl/Expressions/IterateExp.hpp>
#include <ocl/Expressions/SurroundingType.hpp>

// IfExp
#include <ocl/Expressions/IfExp.hpp>

// VarExp
#include <ocl/Expressions/VariableExp.hpp>

// LetExp
#include <ocl/Expressions/LetExp.hpp>

// TypeExp
#include <ocl/Expressions/TypeExp.hpp>
#include <ocl/Expressions/TupleTypeExp.hpp>
#include <ocl/Expressions/CollectionTypeExp.hpp>

// MessageExp
#include <ocl/Expressions/MessageExp.hpp>
#include <ocl/Expressions/MessageArguments.hpp>

// MiscExp
#include <ocl/Expressions/PrefixedExp.hpp>
#include <ocl/Expressions/VarDeclarationExp.hpp>
#include <ocl/Expressions/ParentedExp.hpp>
#include <ocl/Expressions/OperatorExp.hpp>

// ContextExp
#include <ocl/Expressions/PackageDeclarationExp.hpp>
//#include <ocl/Expressions/ContextDeclarationExp.hpp>
#include <ocl/Expressions/PropertyContextDeclExp.hpp>
#include <ocl/Expressions/ClassifierContextDeclExp.hpp>
#include <ocl/Expressions/OperationContextDeclExp.hpp>
#include <ocl/Expressions/OperationContextExp.hpp>
#include <ocl/Expressions/PrePostBodyListExp.hpp>
#include <ocl/Expressions/PrePostBodyExp.hpp>
#include <ocl/Expressions/PrePostBody.hpp>
#include <ocl/Expressions/InitOrDerValueListExp.hpp>
#include <ocl/Expressions/InitOrDerValueExp.hpp>
#include <ocl/Expressions/InvOrDefExp.hpp>
#include <ocl/Expressions/DefExp.hpp>
#include <ocl/Expressions/ExpressionsPackage.hpp>

using namespace ocl::Expressions;
using namespace Eval;
using namespace Utilities;

EcoreEval::EcoreEval() {};

EcoreEval::~EcoreEval() {};

// ######################
// ### Misc Functions ###
// ######################

// returns an nullptr
std::shared_ptr<Any> EcoreEval::defaultResult() {

    return nullptr;

}

// visit the given node
std::shared_ptr<Any> EcoreEval::visitNode(std::shared_ptr<Any> node) {

    if (node == nullptr) {
        //TODO add error
        //node is nullptr
        return defaultResult();
    }
    
    std::shared_ptr<Any> nodeResult = callEvalFunction(node);

    //## after node is visited ##
    
    std::shared_ptr<ocl::Expressions::OclExpression> oclExp = castEcoreArgument<ocl::Expressions::OclExpression>(node);
    
    if (oclExp != nullptr) {

        // an applied_element is set -> manage a CallExp
        // e.g. self.this.that
        if (oclExp->getAppliedElement() != nullptr) {
            nodeResult = handleAppliedElement(oclExp->getAppliedElement(), nodeResult);
        }
    }
    
    //## return statements ##

    if (nodeResult == nullptr) {
        // TODO maybe handle differ
        // NullExp, OperationCall with non return function can be Nullptr
        return defaultResult();

    } else {
        return nodeResult;
    }

}

//count the '()' in an expression chain
// recursively
int EcoreEval::parentCounter(std::shared_ptr<ocl::Expressions::OclExpression> checkExp) {

    std::shared_ptr<ocl::Expressions::ParentedExp> parentedExp = std::dynamic_pointer_cast<ocl::Expressions::ParentedExp>(checkExp);
    
    // count parentedExp
    while (parentedExp != nullptr) {
        return 1 + parentCounter(parentedExp->getInnerExp());
    }

    std::shared_ptr<ocl::Expressions::OperatorExp> operaExp = std::dynamic_pointer_cast<ocl::Expressions::OperatorExp>(checkExp);

    int leftCounter = 0;
    int rightCounter = 0;
    
    if (operaExp != nullptr) {
        // count over operaExp
        leftCounter = parentCounter(operaExp->getLeftHandOperand());
        rightCounter = parentCounter(operaExp->getRightHandOperand());
    }

    if (leftCounter > rightCounter) {
        return leftCounter;
    } else if (leftCounter < rightCounter) {
        return rightCounter;
    } else {
        return 0;
    }

}

// compare two floats
bool EcoreEval::floatCompare(double f1, double f2)
{
    static constexpr auto epsilon = 1.0e-05f;
    if (std::abs(f1 - f2) <= epsilon)
        return true;
    return std::abs(f1 - f2) <= epsilon * std::max(std::abs(f1), std::abs(f2));
}

// try to find the given name inside a tuple
// return the value or nullptr
std::shared_ptr<Any> EcoreEval::findInTuple(std::shared_ptr<Any> tuple, const std::string& name) {

    //try to get the input as tuple
    std::shared_ptr<Bag<std::tuple<std::string, std::shared_ptr<Any>>>> castedTupleBag = nullptr;
    try
    {
        castedTupleBag = tuple->get<std::shared_ptr<Bag<std::tuple<std::string, std::shared_ptr<Any>>>>>();
    }
    catch(...){}

    // cast not successful
    if (castedTupleBag == nullptr) {
        return nullptr;
    }

    size_t tupleSize = castedTupleBag->size();

    // loop variables
    std::shared_ptr<std::tuple<std::string, std::shared_ptr<Any>>> elem = nullptr;

    for (size_t i = 0; i < tupleSize; i++)
    {
        elem = castedTupleBag->at(i);
        if (elem == nullptr) {
            return nullptr;
        }
        // return found elem
        if (std::get<0>(*elem) == name) {
            return std::get<1>(*elem);
        }
    }

    return nullptr;
}

// ######################
// ### Eval Functions ###
// ######################

// ### evalExpressionInOcl ###
// check if the bodyExp is presented and call it
std::shared_ptr<Any> EcoreEval::evalExpressionInOcl(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::ExpressionInOcl> expInOcl = castEcoreArgument<ocl::Expressions::ExpressionInOcl>(exp);

    if (expInOcl == nullptr) {

        //TODO add error
        //expInOcl is not an ExpressionInOcl
        return defaultResult();

    }

    if (expInOcl->getBodyExpression() == nullptr) {

        //TODO add error
        // no body expression means nothing to evaluate
        return defaultResult();

    }

    // ## main part ##
    // get the bodyExp and call the EvalFunction
    std::shared_ptr<ocl::Expressions::OclExpression> oclExp = expInOcl->getBodyExpression();

    // create an EcoreAny for further processing
    std::shared_ptr<Any> anyValue = eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(oclExp, oclExp->getMetaElementID());

    // call switch function
    // no further evaluation steps here
    return visitNode(anyValue);

}

// ### evalTupleLiteralExp ###
// try to create the tuple
std::shared_ptr<Any> EcoreEval::evalTupleLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::TupleLiteralExp> tupLitExp = castEcoreArgument<ocl::Expressions::TupleLiteralExp>(exp);

    if (tupLitExp == nullptr) {
        //TODO add error
        //have to be an colLitExp
        return defaultResult();
    }

    //basic structure of tuples
    // to be able to refer values inside a tuple with a name,
    // each tuple element have to be a (name,value) pair
    // std::shared_ptr<Bag<std::tuple<std::string, std::shared_ptr<Any>>>> results in (std::tuple<std::string, std::shared_ptr<Any>>, ...)
    // without shared_ptr/ std -> Bag<tuple<string, Any>> results in (tuple<string, Any>, ...)

    //std::shared_ptr<Bag<std::tuple<std::string, std::shared_ptr<Any>>>> tupleType;

    std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> tupleParts = tupLitExp->getPart();

    size_t partSize = tupleParts->size();

    // create empty tuple
    std::shared_ptr<Bag<std::tuple<std::string, std::shared_ptr<Any>>>> returnTupleBag = std::make_shared<Bag<std::tuple<std::string, std::shared_ptr<Any>>>>(Bag<std::tuple<std::string, std::shared_ptr<Any>>>());

    //return empty tuple
    if (partSize == 0) {

        return eAny(returnTupleBag, 0, true);
    }

    // go through all elements and evaluate them
    // first: name
    // second: value eval
    // --> custom evaluation of VarDeclExp, otherwise the values would be set in the env

    //to avoid doubled names
    std::list<std::string> names = std::list<std::string>();
    std::string name;

    //save current context for possible reset inside loop
    std::shared_ptr<Any> oldContext = m_env->getContextVariable();

    //current loop elem
    std::shared_ptr<ocl::Expressions::VarDeclarationExp> elem = nullptr;
    //current loop elem assigned Expression
    std::shared_ptr<ocl::Expressions::OclExpression> elemExp;
    // current loop elem Result
    std::shared_ptr<Any> elemResult = nullptr;

    //the new elem inside the tuple
    std::shared_ptr<std::tuple<std::string, std::shared_ptr<Any>>> newTupleElem = nullptr;

    for (size_t i = 0; i < partSize; i++)
    {
        // current elem
        elem = tupleParts->at(i);

        // get the name
        name = elem->getVarName();

        // check if the name is already used
        std::list<std::string>::iterator foundStr = std::find(names.begin(), names.end(), name);
        if (foundStr == names.end()) {
            names.push_back(name);
        } else {
            //TODO add error
            //tried to assign twice (or more) the same name in one tuple
            return defaultResult();
        }

        //try to evaluate the expression
        // at this point it is not already possible to access variables of this tuple
        elemExp = elem->getAssignedOclExp();
        if (elemExp == nullptr) {
            //TODO add error
            //tuple values have to be initialized
            return defaultResult();
        }

        elemResult = visitNode(eEcoreAny(elemExp, elemExp->getMetaElementID()));

        //append element (name, value)
        newTupleElem = std::make_shared<std::tuple<std::string, std::shared_ptr<Any>>>(std::make_tuple(name, elemResult));
        returnTupleBag->add(newTupleElem);

        //TODO type check for each elem
        //elem->getVarType();

        //reset context if necessary
        if (m_env->getContextVariable() != oldContext) {
            m_env->setContextVariable(oldContext);
        }        
    }
    
    //return the tuple
    return eAny(returnTupleBag, 0, true);

}

// ### evalCollectionLiteralExp ###
// try to create the Collection
std::shared_ptr<Any> EcoreEval::evalCollectionLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::CollectionLiteralExp> colLitExp = castEcoreArgument<ocl::Expressions::CollectionLiteralExp>(exp);

    if (colLitExp == nullptr) {
        //TODO add error
        //have to be an colLitExp
        return defaultResult();
    }

    //get the kind of collection
    std::string colKind;

    switch (colLitExp->getKind())
    {
    case ocl::Expressions::CollectionKind::BAG:
        colKind = Utilities::CONST_BAG;
        break;
    case ocl::Expressions::CollectionKind::SEQUENCE:
        colKind = Utilities::CONST_SEQUENCE;
        break;
    case ocl::Expressions::CollectionKind::SET:
        colKind = Utilities::CONST_SET;
        break;
    case ocl::Expressions::CollectionKind::ORDEREDSET:
        colKind = Utilities::CONST_ORDEREDSET;
        break;
    case ocl::Expressions::CollectionKind::COLLECTION:
        colKind = "";
        break;          
    }

    if(colKind.empty()) {
        //TODO add error
        // no valid Collection kind
        return defaultResult();
    }

    //create empty bag
    std::shared_ptr<Bag<Any>> collection = std::make_shared<Bag<Any>>(Bag<Any>());
    
    //2 possibilities
    std::shared_ptr<Bag<ocl::Expressions::CollectionLiteralPart>> parts = colLitExp->getPart();
    if (!parts->empty()) {
        //handle parts

        //evaluate each expression
        size_t partSize = parts->size();

        //save current context
        std::shared_ptr<Any> oldContext = m_env->getContextVariable();

        std::shared_ptr<Any> itemResult = nullptr;
        std::shared_ptr<ocl::Expressions::CollectionLiteralPart> elem = nullptr;
        std::shared_ptr<ocl::Expressions::CollectionItem> item = nullptr; 
        std::shared_ptr<ocl::Expressions::CollectionRange> range = nullptr;

        std::shared_ptr<Any> upperBound = nullptr;
        std::shared_ptr<Any> lowerBound = nullptr;

        int upperBoundInt = 0;
        int lowerBoundInt = 0;

        
        for (size_t i = 0; i < partSize; i++)
        {
            elem = parts->at(i);
            //collection Item
            item = std::dynamic_pointer_cast<ocl::Expressions::CollectionItem>(elem); 
            if (item != nullptr) {

                //evaluate the item and add if not nullptr
                // type check have to be done above e.g. in the variableDeclExp
                itemResult = visitNode(eEcoreAny(item->getItem(), item->getItem()->getMetaElementID()));
                if (itemResult != nullptr) {
                    collection->add(itemResult);
                }

            } else {

                //collection Range
                range = std::dynamic_pointer_cast<ocl::Expressions::CollectionRange>(elem);
                if (range == nullptr) {
                    //TODO add error
                    // collection element (range) could not be evaluated
                    return defaultResult();
                }

                //evaluate the rangeExp
                upperBound = visitNode(eEcoreAny(range->getLast(), range->getLast()->getMetaElementID()));
                //reset context if necessary for lower bound
                if (m_env->getContextVariable() != oldContext) {
                    m_env->setContextVariable(oldContext);
                }
                lowerBound = visitNode(eEcoreAny(range->getFirst(), range->getFirst()->getMetaElementID()));
                // here context reset will be automatically after if exp
                // check if valid Expr
                if (upperBound->getTypeId() != ecore::ecorePackage::EINT_CLASS || lowerBound->getTypeId() != ecore::ecorePackage::EINT_CLASS) {
                    //TODO add error
                    // collection Sequence have to have integer bounds
                    return defaultResult();
                }

                // add integers
                upperBoundInt = upperBound->get<int>();
                lowerBoundInt = lowerBound->get<int>();

                //add the range to the collection
                if (upperBoundInt >= lowerBoundInt) {
                    // e.g. 0..10
                    for (int i = lowerBoundInt; i <= upperBoundInt; i++) {
                        collection->add(eAny<int>(i, ecore::ecorePackage::EINT_CLASS, false));
                    }
                } else {
                    // e.g. 10..0
                    for (int i = lowerBoundInt; i >= upperBoundInt; i--) {
                        collection->add(eAny<int>(i, ecore::ecorePackage::EINT_CLASS, false));
                    }
                }
            }// END of else part: if(item != nullptr)
            if (m_env->getContextVariable() != oldContext) {
                m_env->setContextVariable(oldContext);
            }
        } //END of for (size_t i = 0; i < partSize; i++)

        return eAny(collection, 0, true);
        

    } else {
        //create empty bag
        std::shared_ptr<Any> returnValue = eAny(collection, 0, true);
        return returnValue;
    }

    return defaultResult();
}

// ### evalLetExp ###
// create an new env for the bodyExpr with the declared variable in it
std::shared_ptr<Any> EcoreEval::evalLetExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::LetExp> letExp = castEcoreArgument<ocl::Expressions::LetExp>(exp);

    if (letExp == nullptr) {
        //TODO add error
        //have to be an letExp
        return defaultResult();
    }

    const std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>>& declaredVarExp = letExp->getVariables();
    const std::shared_ptr<ocl::Expressions::OclExpression>& bodyExp = letExp->getIn();

    //create bodyEnv to encapsulate variables
    std::shared_ptr<EcoreEnvironment> bodyEnv = std::make_shared<EcoreEnvironment>(EcoreEnvironment(m_env, m_env->getSelfVariable()));
    std::shared_ptr<EcoreEval> bodyEval = std::make_shared<EcoreEval>(EcoreEval(bodyEnv));

    //declared variables in body env

    size_t declaredVarExpSize = declaredVarExp->size();
    for (size_t i = 0; i < declaredVarExpSize; i++)
    {
        bodyEval->visitNode(eEcoreAny(declaredVarExp->at(i), declaredVarExp->at(i)->getMetaElementID()));
    }

    //evaluate the expression

    std::shared_ptr<Any> result = bodyEval->visitNode(eEcoreAny(bodyExp, bodyExp->getMetaElementID()));

    return result;
    
}

// ### evalIfExp ###
// evaluate given ifExp
std::shared_ptr<Any> EcoreEval::evalIfExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::IfExp> ifExp = castEcoreArgument<ocl::Expressions::IfExp>(exp);

    if (ifExp == nullptr) {
        //TODO add error
        //have to be an varExp
        return defaultResult();
    }

    std::shared_ptr<ocl::Expressions::OclExpression> conditionExp = ifExp->getCondition();

    //eval condition

    //save current context
    std::shared_ptr<Any> oldContext = m_env->getContextVariable();

    //evaluate condition
    std::shared_ptr<Any> conditionResult = visitNode(eEcoreAny(conditionExp, conditionExp->getMetaElementID()));
    bool condition = false;

    //reset context if necessary
    if (m_env->getContextVariable() != oldContext) {
        m_env->setContextVariable(oldContext);
    }

    if (conditionResult == nullptr) {
        //TODO add error
        //condition can't be evaluated
        return defaultResult();
    } 
    else if (conditionResult != nullptr && conditionResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {
        condition = conditionResult->get<bool>();

    } else {
        //TODO add error
        //condition is not a bool
        return defaultResult();
    }

    //actual if Expr

    // necessary to create an new environment to encapsulate variables inside the conditions
    std::shared_ptr<EcoreEnvironment> bodyEnv = std::make_shared<EcoreEnvironment>(EcoreEnvironment(m_env, m_env->getSelfVariable()));
    std::shared_ptr<EcoreEval> bodyEval = std::make_shared<EcoreEval>(EcoreEval(bodyEnv));

    if (condition) {

        //evaluate thenExp

        std::shared_ptr<ocl::Expressions::OclExpression> thenExp = ifExp->getThenExpression();

        //eval thenExp
        std::shared_ptr<Any> thenResult = bodyEval->visitNode(eEcoreAny(thenExp, thenExp->getMetaElementID()));      
        
        if (thenResult == nullptr) {
            //TODO add error
            //then Expr could not be evaluated
            return defaultResult();
        }

        return thenResult;

    } else {
        //evaluate elseExp

        std::shared_ptr<ocl::Expressions::OclExpression> elseExp = ifExp->getElseExpression();

        //eval elseExp
        std::shared_ptr<Any> elseResult = bodyEval->visitNode(eEcoreAny(elseExp, elseExp->getMetaElementID()));

        if (elseResult == nullptr) {
            //TODO add error
            //else Expr could not be evaluated
            return defaultResult();
        }

        return elseResult;
    }

    //TODO add error
    // result can't be returned in if Expr
    return defaultResult();

}

// ### evalVariableExp ###
// return the variable with the given name
std::shared_ptr<Any> EcoreEval::evalVariableExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::VariableExp> varExp = castEcoreArgument<ocl::Expressions::VariableExp>(exp);

    if (varExp == nullptr) {
        //TODO add error
        //have to be an varExp
        return defaultResult();
    }
    
    // get referredVar Name
    std::string varName = varExp->getReferredVariable();
    std::shared_ptr<Any> returnVar = m_env->lookupVariableName(varName);

    if (returnVar == nullptr) {

        // TODO add error
        // error given varName not found
        return defaultResult();
        
    }

    return returnVar;

}

// ### evalOperationCall ###
// try to perform the operation
std::shared_ptr<Any> EcoreEval::evalOperationCallExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::OperationCallExp> operExp = castEcoreArgument<ocl::Expressions::OperationCallExp>(exp);

    if (operExp == nullptr) {
        //TODO add error
        //have to be operation Exp
        return defaultResult();
    }

    std::string operName = operExp->getReferredOperation();
    std::shared_ptr<Bag<ocl::Expressions::OclExpression>> operArgs = operExp->getArgument();
    
    //check if it is an collection operation
    if (operExp->isIsRArrow()) {

        //check if context is an collection
        if (!m_env->getContextVariable()->isContainer()) {
            //TODO add error
            // an collection operation can only be called on an collection
            return defaultResult();
        }

        //TODO collection type
        return handleCollectionOperationsOverOpCall(operName, m_env->getContextVariable(), "", operArgs);

    }  else {
        // an default operation call
        
        //get the operation
        const std::shared_ptr<Any>& eAnyOper = m_env->lookupOperationName(operName, m_env->getContextVariable());

        if (eAnyOper == nullptr) {
            //TODO add error
            // operation could not be found in 'm_env->getContextVariable()'
            return defaultResult();
        }

        // for later use in eInvoke
        const std::shared_ptr<ecore::EOperation>& eOper = castEcoreArgument<ecore::EOperation>(eAnyOper);

        //eval the arguments

        //eval Arguments for operation call
        const std::shared_ptr<Bag<Any>>& evaledArgBag = std::make_shared<Bag<Any>>(Bag<Any>());
        size_t argSize = operArgs->size();
        //active element
        std::shared_ptr<Any> evaledArg = nullptr;
        //old context to handle context changes
        std::shared_ptr<Any> oldContext = m_env->getContextVariable();
        for (size_t i = 0; i < argSize; i++)
        {
            evaledArg = visitNode(eEcoreAny(operArgs->at(i), operArgs->at(i)->getMetaElementID()));
            if (evaledArg == nullptr) {
                //TODO add error
                //evaluation of 'evalArg' failed
                return defaultResult();
            }
            //add the result
            evaledArgBag->add(evaledArg);

            //reset context if it changes
            if (m_env->getContextVariable() != oldContext) {
                m_env->setContextVariable(oldContext);
            }
        }
        
        //call the operation and return result

        //get the eObject of the current Context
        const std::shared_ptr<ecore::EObject>& opCaller = castEcoreArgument<ecore::EObject>(m_env->getContextVariable());
    
        std::shared_ptr<Any> result = opCaller->eInvoke(eOper, evaledArgBag);

        return result;

    } //END of an default operation call

    return defaultResult();

}

// ### evalPropertyCall ###
// search the property in self or in the given evalVar
std::shared_ptr<Any> EcoreEval::evalPropertyCallExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::PropertyCallExp> propExp = castEcoreArgument<ocl::Expressions::PropertyCallExp>(exp);

    if (propExp == nullptr) {
        //TODO add error
        //have to be propExp
        return defaultResult();
    }

    std::shared_ptr<std::list<std::string>> path;

    //extract path (can be a single name)
    path = Utilities::oclCV::extractPath(propExp->getReferredProperty());
    
    // check which context to choose
    std::shared_ptr<Any> currentContext = m_env->getContextVariable();
    
    if (currentContext != nullptr) {
        
        //because of a possible path, m_env->lookup() can't be used here
        // it would be always search in 'self'
        
        // iterate through list of path
        std::list<std::string>::iterator it;
        for (it = path->begin(); it != path->end(); ++it) {
            
            // it is possible that this is a tuple
            // look as element in tuple
            if (currentContext->isContainer()){
                currentContext = findInTuple(currentContext, *it);
            } else {
                // look as variable
                currentContext = m_env->lookupPropertyName(*it, currentContext);
            }
        }
    }
    
    //in case of declared variables within the query e.g. loop variables
    //try to find the name in the env variables (including loop variables)    
    if (currentContext == nullptr) {

        std::list<std::string>::iterator it;
        currentContext = m_env->lookupNamedElement(path->front());
        if (currentContext != nullptr) {
            path->erase(path->begin());
            for (it = path->begin(); it != path->end(); ++it) {
                currentContext = m_env->lookupPropertyName(*it, currentContext);
            }
        }
    }

    return currentContext;
}

// ### evalBooleanLiteralExp ###
// get the Boolean
std::shared_ptr<Any> EcoreEval::evalBooleanLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::BooleanLiteralExp> boolExp = castEcoreArgument<ocl::Expressions::BooleanLiteralExp>(exp);

    if (boolExp == nullptr) {
        // TODO add error
        // input is no BooleanLiteralExp
        return defaultResult();
    }

    return eAny<bool>(boolExp->isBooleanSymbol(), ecore::ecorePackage::EBOOLEAN_CLASS, false);
}

// ### evalStringLiteralExp ###
// get the String
std::shared_ptr<Any> EcoreEval::evalStringLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::StringLiteralExp> strExp = castEcoreArgument<ocl::Expressions::StringLiteralExp>(exp);

    if (strExp == nullptr) {
        // TODO add error
        // input is no StringLiteralExp
        return defaultResult();
    }

    return eAny<std::string>(strExp->getStringSymbol(), ecore::ecorePackage::ESTRING_CLASS, false);

}

// ### evalUnlimitedNaturalExp ###
// get the Number
std::shared_ptr<Any> EcoreEval::evalUnlimitedNaturalLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> unNaExp = castEcoreArgument<ocl::Expressions::UnlimitedNaturalExp>(exp);

    if (unNaExp == nullptr) {
        // TODO add error
        // input is no UnlimitedNaturalLiteralExp
        return defaultResult();
    }

    return eAny<int>(unNaExp->getUnlimitedNaturalSymbol(), ecore::ecorePackage::EINT_CLASS, false);

}

// ### evalIntegerLiteralExp ###
// get the Integer
std::shared_ptr<Any> EcoreEval::evalIntegerLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::IntegerLiteralExp> intExp = castEcoreArgument<ocl::Expressions::IntegerLiteralExp>(exp);

    if (intExp == nullptr) {
        // TODO add error
        // input is no IntegerLiteralExp
        return defaultResult();
    }

    return eAny<int>(intExp->getIntegerSymbol(), ecore::ecorePackage::EINT_CLASS, false);

}

// ### evalRealLiteralExp ###
// get the Real
std::shared_ptr<Any> EcoreEval::evalRealLiteralExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::RealLiteralExp> realExp = castEcoreArgument<ocl::Expressions::RealLiteralExp>(exp);

    if (realExp == nullptr) {
        // TODO add error
        // input is no IntegerLiteralExp
        return defaultResult();
    }

    return eAny<double>(realExp->getRealSymbol(), ecore::ecorePackage::EDOUBLE_CLASS, false);

}

// ### evalIteratorExp ###
// manage various collection operations and index calling
std::shared_ptr<Any> EcoreEval::evalIteratorExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::IteratorExp> iteroExp = castEcoreArgument<ocl::Expressions::IteratorExp>(exp);

    if (iteroExp == nullptr) {
        //TODO add error
        //can't cast to iteratorExp
        return defaultResult();
    }

    const std::shared_ptr<Any>& context = m_env->getContextVariable();

    // ###                                                   ###
    // ### check if it is an direct OCL collection Operation ###
    // ###                                                   ###
    
    
    if (iteroExp->isIsCollectionOperation()) {

        //check if the context is an container of multiple values
        if (!context->isContainer()) {

            //TODO add error
            //context of iterateExp is no container
            return defaultResult();
        }

        // ###                ###
        // ### Pre Conditions ###
        // ###                ###

        //define loop vars

        //optional
        std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDeclElem1;
        //optional
        std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDeclElem2;

        //the storage for the loop vars
        std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> loopVars = std::make_shared<Bag<ocl::Expressions::VarDeclarationExp>>(Bag<ocl::Expressions::VarDeclarationExp>());  
        
        //check the vars

        if (iteroExp->getIterator()->size() == 1) {
            varDeclElem1 = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(iteroExp->getIterator()->at(0));
            loopVars->add(varDeclElem1);
        }

        //max. 2 VarDecl. are possible
        if (iteroExp->getIterator()->size() == 2) {
            varDeclElem1 = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(iteroExp->getIterator()->at(0));
            loopVars->add(varDeclElem1);
            varDeclElem2 = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(iteroExp->getIterator()->at(1));
            loopVars->add(varDeclElem2);
        }

        //reminder the case where no iterator is set will be handled as OperationCall

        // ###            ###
        // ### Loop Setup ###
        // ###            ###

        std::shared_ptr<Any> result = defaultResult();

        // get the bodyExp
        std::shared_ptr<ocl::Expressions::OclExpression> bodyExp = iteroExp->getBody();    

        // no explicit loop variable is set
        // per grammar definition this case is possible
        // but in practice this case will be handled by an OperationCallExp
        if (loopVars->size() == 0) {

            // call the select operations
            if (iteroExp->getIterName() == Utilities::SELECT_OPER_NAME) {
                return oclSelectReject(true, bodyExp, loopVars, context, "");
            }
            // call the reject operations
            else if (iteroExp->getIterName() == Utilities::REJECT_OPER_NAME) {
                return oclSelectReject(false, bodyExp, loopVars, context, "");
            }
        } else if (loopVars->size() == 1) {

            // call the operations
            if (iteroExp->getIterName() == Utilities::SELECT_OPER_NAME) {
                return oclSelectReject(true, bodyExp, loopVars, context, "");
            }
            // call the operations
            else if (iteroExp->getIterName() == Utilities::REJECT_OPER_NAME) {
                return oclSelectReject(false, bodyExp, loopVars, context, "");
            }
        }
    

    } // END of iteroExp->isIsCollectionOperation()

    // ###                         ###
    // ### indexing call           ###
    // ### collection[oclExp, ...] ###
    // ###                         ###

    if (iteroExp->getSourrundedBy() == ocl::Expressions::SurroundingType::BRACKETS) {
        
        //get the collection name
        std::string collectionName = iteroExp->getIterName();
        //update the context
        std::shared_ptr<Any> collectionContext = m_env->lookupPropertyName(collectionName, context);
        if (collectionContext == nullptr) {
            //TODO add error
            // collection 'collectionName' could not be found in 'context'
            return defaultResult();
        } else {
            m_env->setContextVariable(collectionContext);
        }
        
        
        // ### defines what kind the iterable object is ###
        // ### eObjBag or Any Bag                       ###
        bool asEObjBag = false;
        
        //first variant get the context as EObjectContainer
        std::shared_ptr<ecore::EcoreContainerAny> ecoreConAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(m_env->getContextVariable());
        std::shared_ptr<Bag<ecore::EObject>> contextObjBag;

        //second variant as Bag<Any>
        std::shared_ptr<Bag<Any>> iterateBag;

        size_t bagSize = 0;
        
        if (ecoreConAny != nullptr) {
            //used later to choose the correct loop
            asEObjBag = true;
            // case 1 as eObjBag
            contextObjBag = ecoreConAny->getAsEObjectContainer();
            bagSize = contextObjBag->size();

        } else {
            // case 2 as iterateBag
            try
            {
                iterateBag = context->get<std::shared_ptr<Bag<Any>>>();
            }
            catch(...){}

            if (iterateBag == nullptr) {
                //TODO add error
                // can't cast context to a iterable object
                return defaultResult();
            }
            bagSize = iterateBag->size();
        }
        // END of defines what kind the iterable object is

        // ###                      ###
        // ### qualifier evaluation ###
        // ###                      ###
        
        // the qualifier are stored in the iteratorBag
        std::shared_ptr<Bag<ocl::Expressions::OclExpression>> qualifierExpBag = iteroExp->getIterator();
        size_t qualifierSize = qualifierExpBag->size();

        //special case no qualifier means just return the complete collection
        if (qualifierSize == 0) {
            
            //also 1 element will be returned as original collection
            return collectionContext;
            
        } else if (qualifierSize == 1) {

            //get the qualifiers as int
            // one qualifier means return only the element 

            //get the current qualifier
            std::shared_ptr<Any> qualExpResult = visitNode(eEcoreAny(qualifierExpBag->at(0), qualifierExpBag->at(0)->getMetaElementID()));
            if (qualExpResult == nullptr) {
                //TODO add error
                // could not evaluate qualifier at 'i'
                return defaultResult();
            } else if (qualExpResult->getTypeId() != ecore::ecorePackage::EINT_CLASS) {
                //TODO add error
                // qualifier at 'i' have to be an int
                return defaultResult();
            }
            int qualifier = qualExpResult->get<int>();

            if (qualifier < 0 || (long long unsigned int)qualifier >= bagSize) {
                //TODO add error
                // index out of range or negative
                return defaultResult();
            }

            // return the element at index
            if (asEObjBag) {
                return eEcoreAny(contextObjBag->at(qualifier), contextObjBag->at(qualifier)->getMetaElementID());
            } else {
                return iterateBag->at(qualifier);
            }

        } else {

            // multiple qualifiers means return a Bag with the elements

            std::vector<int> qualifiers = {};           
            //if the context have to be reset
            std::shared_ptr<Any> old_context = m_env->getContextVariable();
            for (size_t i = 0; i < qualifierSize; i++)
            {
                //get the current qualifier
                std::shared_ptr<Any> elemResult = visitNode(eEcoreAny(qualifierExpBag->at(i), qualifierExpBag->at(i)->getMetaElementID()));

                //reset context if necessary
                if (m_env->getContextVariable() != old_context) {
                    m_env->setContextVariable(old_context);
                }

                if (elemResult == nullptr) {
                    //TODO add error
                    // could not evaluate qualifier at 'i'
                    return defaultResult();
                } else if (elemResult->getTypeId() != ecore::ecorePackage::EINT_CLASS) {
                    //TODO add error
                    // qualifier at 'i' have to be an int
                    return defaultResult();
                }
                int qualifier = elemResult->get<int>();
                qualifiers.push_back(qualifier);
            } //END of for (size_t i = 0; i < qualifierSize; i++)

            std::shared_ptr<Bag<Any>> resultBag = std::make_shared<Bag<Any>>(Bag<Any>());
            
            size_t qualSize = qualifiers.size();
            
            //create the return bag
            if (asEObjBag) {

                //input is Bag<ecore::EObject>
                
                for (size_t i = 0; i < qualSize; i++)
                {
                    int index = qualifiers.at(i);
                    if (index < 0 || (long long unsigned int)index >= bagSize) {
                        //TODO add error
                        // index out of range or negative
                        return defaultResult();
                    }
                    resultBag->add(eEcoreAny(contextObjBag->at(index), contextObjBag->at(index)->getMetaElementID()));
                }
                return eAny(resultBag, 0, true);
                
            } else {
                //input is Bag<Any>
                for (size_t i = 0; i < qualSize; i++)
                {
                    int index = qualifiers.at(i);
                    if (index < 0 || (long long unsigned int)index >= bagSize) {
                        //TODO add error
                        // index out of range or negative
                        return defaultResult();
                    }
                    resultBag->add(iterateBag->at(index));
                }
                return eAny(resultBag, 0, true);
            } // END of if (asEObjBag) else part
        } //END of else: multiple qualifiers mean return a Bag with the elements
    } // END of iteroExp->getSurroundedBy() == ocl::Expressions::SurroundingType::BRACKETS

    //TODO add error
    // could not evaluate IteratorExp
    return defaultResult();

}

// ### evalIterateExp ###
// manage "iterate" Exp
std::shared_ptr<Any> EcoreEval::evalIterateExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::IterateExp> iterExp = castEcoreArgument<ocl::Expressions::IterateExp>(exp);

    if (iterExp == nullptr) {
        //TODO add error
        //can't cast to iteratorExp
        return defaultResult();
    }
    
    // ###                ###
    // ### Pre Conditions ###
    // ###                ###

    const std::shared_ptr<Any>& context = m_env->getContextVariable();

    //check if context is present
    if (context == nullptr) {

        //TODO add error
        //context is nullptr
        return defaultResult();
    }
    
    //check if the context is an container of multiple values
    if (!context->isContainer()) {

        //TODO add error
        //context of iterateExp is no container
        return defaultResult();
    }

    //define element and accumulator

    //mandatory
    std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDeclAcc;
    //optional
    std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDeclElem; 

    //max. 2 VarDecl. are possible
    //if 1 -> it must be acc
    if (iterExp->getIterator()->size() == 1) {
        varDeclAcc = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(iterExp->getIterator()->at(0));
    }

    //max. 2 VarDecl. are possible
    //if 2 -> the first one is the elem and the second one is acc
    if (iterExp->getIterator()->size() == 2) {
        varDeclAcc = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(iterExp->getIterator()->at(1));
        varDeclElem = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(iterExp->getIterator()->at(0));
    }

    if (varDeclAcc == nullptr) {
        //TODO add error
        //the accumulator variable is not set
        return defaultResult();
    }

    //defines what kind the iterable object is
    // eObjBag or Any Bag
    bool asEObjBag = false;
    
    //first variant get the context as EObjectContainer
    std::shared_ptr<ecore::EcoreContainerAny> ecoreConAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(context);
    std::shared_ptr<Bag<ecore::EObject>> contextObjBag;
    size_t bagSize;
    //second variant as Bag<Any>
    std::shared_ptr<Bag<Any>> iterateBag;
    
    if (ecoreConAny != nullptr) {
        //used later to choose the correct loop
        asEObjBag = true;
        // case 1 as eObjBag
        contextObjBag = ecoreConAny->getAsEObjectContainer();
        bagSize = contextObjBag->size();

    } else {

        // case 2 as iterateBag
        try
        {
            iterateBag = context->get<std::shared_ptr<Bag<Any>>>();
        }
        catch(...){}

        if (iterateBag == nullptr) {
            //TODO add error
            // can't cast context to a iterable object
            return defaultResult();
        }

        bagSize = iterateBag->size();

    }

    //apply the oclExp to every element in the eObjContainer
    // necessary to create an new environment to encapsulate loop variables
    std::shared_ptr<EcoreEnvironment> bodyEnv = std::make_shared<EcoreEnvironment>(EcoreEnvironment(m_env, m_env->getSelfVariable()));
    std::shared_ptr<EcoreEval> bodyEval = std::make_shared<EcoreEval>(EcoreEval(bodyEnv));

    if (varDeclElem != nullptr) {
        // the iterator have not to be saved here
        bodyEval->visitNode(eEcoreAny(varDeclElem, varDeclElem->getMetaElementID()));
    }
    //because VarDeclExp does not return the variable per OCL Spec definition
    bodyEval->visitNode(eEcoreAny(varDeclAcc, varDeclAcc->getMetaElementID()));
    std::shared_ptr<Any> acc = bodyEnv->lookupNamedElement(varDeclAcc->getVarName());

    if (acc == nullptr) {
        //TODO add error
        // acc isn't initialized
        return defaultResult();
    }

    // TODO distinguish between Collection types //

    // get the bodyExp
    std::shared_ptr<ocl::Expressions::OclExpression> bodyExp = iterExp->getBody();
    
    // create the result variable for the loop
    std::shared_ptr<Any> result = defaultResult();

    // ###                   ###
    // ### 2x2 cases of loop ###
    // ###                   ###
    
    // first 2 cases with eObjBag
    if (asEObjBag) {

        //contextObjBag is used here
        
        // start evaluating with given varDeclElem
        if(varDeclElem != nullptr) {
        std::string varDeclName = varDeclElem->getVarName();

        //start a loop through all elements of the bag
        // call every time the bodyOclExp
        bool isChanged = false;
        for (size_t i = 0; i < bagSize; i++) {

            const std::shared_ptr<ecore::EObject>& elem = contextObjBag->at(i);
            //replace the variable behind the varDeclName
            isChanged = bodyEnv->changeNamedElement(varDeclName, eEcoreAny<std::shared_ptr<ecore::EObject>>(elem, elem->getMetaElementID()));
            if (!isChanged) {
                //TODO add error
                //the iterator variable could not be updated
                //maybe incompatible type of elem
                return defaultResult();
            }
            //call the visitNode Function in the bodyEnv, in this expression will also the acc be set
            // because it is in the bodyEnv NamedElements
            result = bodyEval->visitNode(eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(bodyExp, bodyExp->getMetaElementID()));

            }
        } else {
            
            //only acc is set
            for (size_t i = 0; i < bagSize; i++) {

                const std::shared_ptr<ecore::EObject>& elem = contextObjBag->at(i);
                //for every loop call the current context changes to the active elem
                bodyEnv->setContextVariable(eEcoreAny(elem, elem->getMetaElementID()));
                //call the visitNode Function in the bodyEnv, in this expression will also the acc be set
                // because it is in the bodyEnv NamedElements
                result = bodyEval->visitNode(eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(bodyExp, bodyExp->getMetaElementID()));
            }
        }
    } // end of first 2 cases with eObjBag
    else { // second 2 cases with iterateBag

        //iterateBag is used here

        if(varDeclElem != nullptr) {
            std::string varDeclName = varDeclElem->getVarName();

            //start a loop through all elements of the bag
            // call every time the bodyOclExp
            bool isChanged = false;
            for (size_t i = 0; i < bagSize; i++) {

                //because elem is set as variable in the bodyEnv, it will also update if used in the loop
                const std::shared_ptr<Any>& elem = iterateBag->at(i);
                //replace the variable behind the varDeclName
                isChanged = bodyEnv->changeNamedElement(varDeclName, elem);
                if (!isChanged) {
                    //TODO add error
                    //the iterator variable could not be updated
                    //maybe incompatible type of elem
                    return defaultResult();
                }
                //call the visitNode Function in the bodyEnv, in this expression will also the acc be set
                // because it is in the bodyEnv NamedElements
                result = bodyEval->visitNode(eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(bodyExp, bodyExp->getMetaElementID()));

            }
        } else {
            
            //only acc is set
            for (size_t i = 0; i < bagSize; i++) {

                //because elem is set as variable in the bodyEnv, it will also update if used in the loop
                const std::shared_ptr<Any>& elem = iterateBag->at(i);
                //for every loop call the current context changes to the active elem
                bodyEnv->setContextVariable(elem);
                //call the visitNode Function in the bodyEnv, in this expression will also the acc be set
                // because it is in the bodyEnv NamedElements
                result = bodyEval->visitNode(eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(bodyExp, bodyExp->getMetaElementID()));
            }
        }
    } // end of second 2 cases with iterateBag

    // TODO handle type specifications //



    // ###                 ###
    // ### after loop work ###
    // ###                 ###

    return result;

}

// ### evalPrefixedExp ###
// check if 'not' or '-' or 'IGNORE' and evaluate correctly
// e.g. negate bool, make numbers negative
std::shared_ptr<Any> EcoreEval::evalPrefixedExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::PrefixedExp> prefExp = castEcoreArgument<ocl::Expressions::PrefixedExp>(exp);

    if (prefExp == nullptr) {
        //TODO add error
        // have to be an PrefixedExp
        return defaultResult();
    }

    // get the body Expression and evaluate it
    std::shared_ptr<ocl::Expressions::OclExpression> bodyExp = prefExp->getReferredExpression();
    std::shared_ptr<Any> bodyNode = eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(bodyExp, bodyExp->getMetaElementID());

    std::shared_ptr<Any> result = visitNode(bodyNode);

    //pass the expression -> during the leading '-' Problem
    // see in the CustomVisitor -> handleAppliedElement Function
    if(prefExp->getUnarySymbol() == Utilities::CONST_IGNORE) {
        return result;
    }

    // try to cast as bool -> 'NOT' case
    if(prefExp->getUnarySymbol() == Utilities::CONST_NOT) {

        // negate directly as bool
        if (result->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {

            bool boolResult = result->get<bool>();
            result = eAny<bool>(!boolResult, ecore::ecorePackage::EBOOLEAN_CLASS, false);
            return result;

        }
    }

    // try to cast as number -> '-' case
    if(prefExp->getUnarySymbol() == Utilities::CONST_MINUS) {

        // negate as integer
        if (result->getTypeId() == ecore::ecorePackage::EINT_CLASS) {

            int intResult = result->get<int>();
            result = eAny<int>(-intResult, ecore::ecorePackage::EINT_CLASS, false);
            return result;

        }

        // negate as real/double
        if (result->getTypeId() == ecore::ecorePackage::EDOUBLE_CLASS) {

            double doubleResult = result->get<double>();
            result = eAny<double>(-doubleResult, ecore::ecorePackage::EDOUBLE_CLASS, false);
            return result;
        }

        //TODO add error
        //result could not be negated
    }
    return defaultResult();
}

// ### evalOperatorExp ###
// try to eval operators like +, ==, <>, *, ...
std::shared_ptr<Any> EcoreEval::evalOperatorExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::OperatorExp> operaExp = castEcoreArgument<ocl::Expressions::OperatorExp>(exp);

    if (operaExp == nullptr) {
        //TODO add error
        // have to be an OperatorExp
        return defaultResult();
    }

    std::shared_ptr<ocl::Expressions::OclExpression> leftOperand = operaExp->getLeftHandOperand();
    std::shared_ptr<ocl::Expressions::OclExpression> rightOperand = operaExp->getRightHandOperand();

    std::shared_ptr<ocl::Expressions::ParentedExp> leftParentOperand = std::dynamic_pointer_cast<ocl::Expressions::ParentedExp>(leftOperand);
    std::shared_ptr<ocl::Expressions::ParentedExp> rightParentOperand = std::dynamic_pointer_cast<ocl::Expressions::ParentedExp>(rightOperand);

    std::shared_ptr<Any> rightResult;
    std::shared_ptr<Any> leftResult;

    //save the old context if an operand changes it, it have to be reset afterwards
    std::shared_ptr<Any> oldContext = m_env->getContextVariable();

    //check parentheses
    if (rightParentOperand != nullptr && leftParentOperand != nullptr) {
        //both are parented

        //check which one have more inner '()'
        int leftInnerParentCounter = parentCounter(leftParentOperand);
        int rightInnerParentCounter = parentCounter(rightParentOperand);
        
        if (rightInnerParentCounter > leftInnerParentCounter) {
            //right side have more '()'
            
            rightResult = visitNode(eEcoreAny(rightOperand, rightOperand->getMetaElementID()));
            //reset the context if necessary
            if (m_env->getContextVariable() != oldContext) {
                m_env->setContextVariable(oldContext);
            }
            leftResult = visitNode(eEcoreAny(leftOperand, leftOperand->getMetaElementID()));
            //reset the context if necessary
            if (m_env->getContextVariable() != oldContext) {
                m_env->setContextVariable(oldContext);
            }

        } else {
            //left side have more '()' or both equal

            leftResult = visitNode(eEcoreAny(leftOperand, leftOperand->getMetaElementID()));
            //reset the context if necessary
            if (m_env->getContextVariable() != oldContext) {
                m_env->setContextVariable(oldContext);
            }
            rightResult = visitNode(eEcoreAny(rightOperand, rightOperand->getMetaElementID()));
            //reset the context if necessary
            if (m_env->getContextVariable() != oldContext) {
                m_env->setContextVariable(oldContext);
            }
        }

    } else if (rightParentOperand != nullptr && leftParentOperand == nullptr) {
        //rightOperand is parented

        rightResult = visitNode(eEcoreAny(rightOperand, rightOperand->getMetaElementID()));
        //reset the context if necessary
        if (m_env->getContextVariable() != oldContext) {
            m_env->setContextVariable(oldContext);
        }
        leftResult = visitNode(eEcoreAny(leftOperand, leftOperand->getMetaElementID()));
        //reset the context if necessary
        if (m_env->getContextVariable() != oldContext) {
            m_env->setContextVariable(oldContext);
        }

    } else {
        //left is parented or none is parented

        leftResult = visitNode(eEcoreAny(leftOperand, leftOperand->getMetaElementID()));
        //reset the context if necessary
        if (m_env->getContextVariable() != oldContext) {
            m_env->setContextVariable(oldContext);
        }
        rightResult = visitNode(eEcoreAny(rightOperand, rightOperand->getMetaElementID()));
        //reset the context if necessary
        if (m_env->getContextVariable() != oldContext) {
            m_env->setContextVariable(oldContext);
        }
    }//END of check parentheses

    std::string operation = operaExp->getOperator();

    //primitive type check
    bool leftIntPrimitive = (leftResult->getTypeId() == ecore::ecorePackage::EINT_CLASS);
    bool rightIntPrimitive = (rightResult->getTypeId() == ecore::ecorePackage::EINT_CLASS);

    bool leftDoublePrimitive = (leftResult->getTypeId() == ecore::ecorePackage::EDOUBLE_CLASS);
    bool rightDoublePrimitive = (rightResult->getTypeId() == ecore::ecorePackage::EDOUBLE_CLASS);

    bool leftStringPrimitive = (leftResult->getTypeId() == ecore::ecorePackage::ESTRING_CLASS);
    bool rightStringPrimitive = (rightResult->getTypeId() == ecore::ecorePackage::ESTRING_CLASS);

    bool leftBoolPrimitive = (leftResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS);
    bool rightBoolPrimitive = (rightResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS);

    //primitive Operation type
    bool isIntOperation = leftIntPrimitive && rightIntPrimitive;
    bool isDoubleOperation = leftDoublePrimitive && rightDoublePrimitive;
    bool isStringOperation = leftStringPrimitive && rightStringPrimitive;
    bool isIntDoubleOperation = leftIntPrimitive && rightDoublePrimitive;
    bool isDoubleIntOperation = leftDoublePrimitive && rightIntPrimitive;
    bool isBooleanOperation = leftBoolPrimitive && rightBoolPrimitive;
    
    // ###                          ###
    // ### +, -, *, /, <, <=, >, >= ###
    // ###                          ###

    // primitive values
    if (operation == Utilities::CONST_PLUS || operation == Utilities::CONST_MINUS
     || operation == Utilities::CONST_STAR || operation == Utilities::CONST_SLASH
     || operation == Utilities::CONST_LT || operation == Utilities::CONST_LTE
     || operation == Utilities::CONST_GT || operation == Utilities::CONST_GTE) {

        // Integer + Integer
        if (isIntOperation) {
            int left = leftResult->get<int>();
            int right = rightResult->get<int>();
            if (operation == Utilities::CONST_PLUS) {
                return addition(left, right);
            }
            else if (operation == Utilities::CONST_MINUS) {
                return subtraction(left, right);
            }
            else if (operation == Utilities::CONST_STAR) {
                return multiplication(left, right);
            }
            else if (operation == Utilities::CONST_SLASH) {
                return division(left, right);
            }
            else if(operation == Utilities::CONST_LT) {
                return primLT(left, right);
            }
            else if(operation == Utilities::CONST_LTE) {
                return primLTE(left, right);
            }
            else if(operation == Utilities::CONST_GT) {
                return primGT(left, right);
            }
            else if(operation == Utilities::CONST_GTE) {
                return primGTE(left, right);
            }
        }

        // Double + Double
        if (isDoubleOperation) {
            double left = leftResult->get<double>();
            double right = rightResult->get<double>();
            if (operation == Utilities::CONST_PLUS) {
                return addition(left, right);
            }
            else if (operation == Utilities::CONST_MINUS) {
                return subtraction(left, right);
            }
            else if (operation == Utilities::CONST_STAR) {
                return multiplication(left, right);
            }
            else if (operation == Utilities::CONST_SLASH) {
                return division(left, right);
            }
            else if(operation == Utilities::CONST_LT) {
                return primLT(left, right);
            }
            else if(operation == Utilities::CONST_LTE) {
                return primLTE(left, right);
            }
            else if(operation == Utilities::CONST_GT) {
                return primGT(left, right);
            }
            else if(operation == Utilities::CONST_GTE) {
                return primGTE(left, right);
            }    
        }

        // String + String
        if (isStringOperation) {
            std::string left = leftResult->get<std::string>();
            std::string right = rightResult->get<std::string>();
            if (operation == Utilities::CONST_PLUS) {
                return addition(left, right);
            }
            else if(operation == Utilities::CONST_LT) {
                return primLT(left, right);
            }
            else if(operation == Utilities::CONST_LTE) {
                return primLTE(left, right);
            }
            else if(operation == Utilities::CONST_GT) {
                return primGT(left, right);
            }
            else if(operation == Utilities::CONST_GTE) {
                return primGTE(left, right);
            }
        }

        // Integer + Double
        if (isIntDoubleOperation) {
            int left = leftResult->get<int>();
            double right = rightResult->get<double>();
            if (operation == Utilities::CONST_PLUS) {
                return addition(left, right);
            }
            else if (operation == Utilities::CONST_MINUS) {
                return subtraction(left, right);
            }
            else if (operation == Utilities::CONST_STAR) {
                return multiplication(left, right);
            }
            else if (operation == Utilities::CONST_SLASH) {
                return division(left, right);
            }
            else if(operation == Utilities::CONST_LT) {
                return primLT(left, right);
            }
            else if(operation == Utilities::CONST_LTE) {
                return primLTE(left, right);
            }
            else if(operation == Utilities::CONST_GT) {
                return primGT(left, right);
            }
            else if(operation == Utilities::CONST_GTE) {
                return primGTE(left, right);
            }
        }

        // Double + Integer
        if (isDoubleIntOperation) {
            double left = leftResult->get<double>();
            int right = rightResult->get<int>();
            if (operation == Utilities::CONST_PLUS) {
                return addition(left, right);
            }
            else if (operation == Utilities::CONST_MINUS) {
                return subtraction(left, right);
            }
            else if (operation == Utilities::CONST_STAR) {
                return multiplication(left, right);
            }
            else if (operation == Utilities::CONST_SLASH) {
                return division(left, right);
            }
            else if(operation == Utilities::CONST_LT) {
                return primLT(left, right);
            }
            else if(operation == Utilities::CONST_LTE) {
                return primLTE(left, right);
            }
            else if(operation == Utilities::CONST_GT) {
                return primGT(left, right);
            }
            else if(operation == Utilities::CONST_GTE) {
                return primGTE(left, right);
            }
        }
    } //End of if (operation == Utilities::CONST_PLUS || operation == Utilities::CONST_MINUS || operation == Utilities::CONST_STAR || operation == Utilities::CONST_SLASH )

    // ###        ###
    // ### =, <> ###
    // ###        ###


    if (operation == Utilities::CONST_EQUAL || operation == Utilities::CONST_UNEQUAL) {

        bool result = false;
        
        //primitive type
        // Integer + Integer
        if (isIntOperation) {
            int left = leftResult->get<int>();
            int right = rightResult->get<int>();
            result = (operation == Utilities::CONST_EQUAL) ? left == right : left != right;
            return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
        }

        // Double + Double
        if (isDoubleOperation) {
            double left = leftResult->get<double>();
            double right = rightResult->get<double>();
            result = (operation == Utilities::CONST_EQUAL) ? floatCompare(left, right) : !floatCompare(left, right);
            return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
        }

        // String + String
        if (isStringOperation) {
            std::string left = leftResult->get<std::string>();
            std::string right = rightResult->get<std::string>();
            result = (operation == Utilities::CONST_EQUAL) ? left == right : left != right;
            return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
        }

        // Integer + Double
        if (isIntDoubleOperation) {
            int left = leftResult->get<int>();
            double right = rightResult->get<double>();
            result = (operation == Utilities::CONST_EQUAL) ? floatCompare(left, right) : !floatCompare(left, right);
            return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
        }

        // Double + Integer
        if (isDoubleIntOperation) {
            double left = leftResult->get<double>();
            int right = rightResult->get<int>();
            result = (operation == Utilities::CONST_EQUAL) ? floatCompare(left, right) : !floatCompare(left, right);
            return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
        }

        // no primitive type
        // try as EObject

        std::shared_ptr<ecore::EObject> leftEObj = castEcoreArgument<ecore::EObject>(leftResult);
        std::shared_ptr<ecore::EObject> rightEObj = castEcoreArgument<ecore::EObject>(rightResult);

        if (leftEObj != nullptr && rightEObj != nullptr) {
            result = leftEObj.get() == rightEObj.get();
            return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
        } else {
            //TODO add error
            //can't compare arguments
            return defaultResult();
        }

    } //end of if (operation == Utilities::CONST_EQUAL || operation == Utilities::CONST_UNEQUAL)

    // logic operators
    if (operation == Utilities::CONST_OR || operation == Utilities::CONST_AND 
     || operation == Utilities::CONST_XOR || operation == Utilities::CONST_IMPLIES) {

        if(isBooleanOperation) {

            bool left = leftResult->get<bool>();
            bool right = rightResult->get<bool>();

            if (operation == Utilities::CONST_AND) {
                return eAny(left && right, ecore::ecorePackage::EBOOLEAN_CLASS, false);
            }

            if (operation == Utilities::CONST_OR) {
                return eAny(left || right, ecore::ecorePackage::EBOOLEAN_CLASS, false);
            }

            if (operation == Utilities::CONST_XOR) {
                return eAny(left != right, ecore::ecorePackage::EBOOLEAN_CLASS, false);
            }

            if (operation == Utilities::CONST_IMPLIES) {
                return eAny(!left || right, ecore::ecorePackage::EBOOLEAN_CLASS, false);
            }
        }
     } //END of Boolean Operators

    // unhandled operand or types
    return defaultResult();
}

// ### evalParentedExp ###
// eval the expression in parents and return it
std::shared_ptr<Any> EcoreEval::evalParentedExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::ParentedExp> parExp = castEcoreArgument<ocl::Expressions::ParentedExp>(exp);

    if (parExp == nullptr) {
        //TODO add error
        // have to be an varDecExp
        return defaultResult();
    }

    std::shared_ptr<ocl::Expressions::OclExpression> innerExp =  parExp->getInnerExp();

    if (innerExp == nullptr) {
        //TODO add error
        // inner Expression is not set
        return defaultResult();
    } else {
        return visitNode(eEcoreAny(innerExp, innerExp->getMetaElementID()));
    }

}

// ### evalVarDeclExp ###
// create the Variable and add them to the env
// if an assignedExp is set, add it to the env too
// if not add the empty variable to the env
// returns nullptr per OCL Defintion
std::shared_ptr<Any> EcoreEval::evalVarDeclExp(std::shared_ptr<Any> exp) {

    std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = castEcoreArgument<ocl::Expressions::VarDeclarationExp>(exp);

    if (varDecExp == nullptr) {
        //TODO add error
        // have to be an varDecExp
        return defaultResult();
    }

    // ###          ###
    // ### initPart ###
    // ###          ###
    
    // the type of the variable (optional)
    std::shared_ptr<ocl::Expressions::TypeExp> typeExp = varDecExp->getVarType();

    // the assignedExp of the variable (optional)
    std::shared_ptr<ocl::Expressions::OclExpression> assignedExp = varDecExp->getAssignedOclExp();

    std::shared_ptr<Any> assignedResult;
    // if an initExpression is set, get the initialization value
    if (assignedExp != nullptr) {
        assignedResult = visitNode(eEcoreAny(assignedExp, assignedExp->getMetaElementID()));
    }

    // ###                                              ###
    // ### check type conformity, an assignedExp is set ###
    // ###                                              ###

    //check if a type is set and the assignedExp type in it conforms
    if (assignedExp != nullptr && typeExp != nullptr) {
  
        //collectionType
        std::shared_ptr<ocl::Expressions::CollectionTypeExp> colType = std::dynamic_pointer_cast<ocl::Expressions::CollectionTypeExp>(typeExp);
        if (colType != nullptr) {
            if (!assignedResult->isContainer()) {
                //TODO add error
                // initResult is no container
                return defaultResult();
            }

            //TODO check inner type and add correctly as type name

            bool isAdded = m_env->addElement(varDecExp->getVarName(), assignedResult, false, colType->getReferredType());
            if (!isAdded) {
                //TODO add error
                //the new variable name is already in use
                return defaultResult(); 
            }
            //TODO check Container Type (Bag, Sequence, ...)
            
            // per OCL Spec. do not return the added exp
            return defaultResult();

        }

        // tuple type
        std::shared_ptr<ocl::Expressions::TupleTypeExp> tupleType = std::dynamic_pointer_cast<ocl::Expressions::TupleTypeExp>(typeExp);
        if (tupleType != nullptr) {
            if (!assignedResult->isContainer()) {
                //TODO add error
                // initResult is no container
                return defaultResult();
            }           
            //TODO check Container Type (Tuple Specification)
            //TODO check inner type and add correctly as type name
            bool isAdded = m_env->addElement(varDecExp->getVarName(), assignedResult, false, tupleType->getReferredType());
            if (!isAdded) {
                //TODO add error
                // the new variable name is already in use
                return defaultResult(); 
            }            
        }

        //singleType
        if (assignedResult->isContainer()) {
            //TODO add error
            //tried to assign a container to a single value
            return defaultResult();
        }
        std::string typeName = typeExp->getReferredType();
        std::string initTypeName = m_env->getTypeName(assignedResult);

        if (typeName != initTypeName) {
            bool failure = true;
            if (typeName == Utilities::UNLIMITEDNATURAL_NAME && initTypeName == Utilities::EINT_NAME) {
                failure = false;
            }
            if (failure) {
                //TODO add error
                //variable type and assignedExp type are not equal
                return defaultResult();
            }
        }

        // try to add the new variable
        bool isAdded = m_env->addElement(varDecExp->getVarName(), assignedResult, false, initTypeName);
        if (!isAdded) {
            //TODO add error
            // the new variable name is already in use
            return defaultResult(); 
        }

        //per OCL Spec. do not return the added exp
        return defaultResult();

        
    } // END of typeExp != nullptr && assignedExp != nullptr

    // ###                  ###
    // ### only type is set ###
    // ###                  ###

    if (assignedExp == nullptr && typeExp != nullptr) {

        // try to add as empty variable
        bool isAdded = m_env->addElement(varDecExp->getVarName(), nullptr, false, typeExp->getReferredType());
        if (!isAdded) {
            //TODO add error
            // the new variable name is already in use
            return defaultResult(); 
        }

        // nullptr will be returned because only the variable name (with type) is added to the env
        return defaultResult();

    }

    // ###                         ###
    // ### only assignedExp is set ###
    // ###                         ###

    if (assignedExp != nullptr && typeExp == nullptr) {

        // try to add as empty variable
        bool isAdded = m_env->addElement(varDecExp->getVarName(), assignedResult, false, m_env->getTypeName(assignedResult));
        if (!isAdded) {
            //TODO add error
            // the new variable name is already in use
            return defaultResult(); 
        }

        //per OCL Spec. do not return the added exp
        return defaultResult();

    }

    // ###                      ###
    // ### only var name is set ###
    // ###                      ###

    if (assignedExp == nullptr && typeExp == nullptr) {

        // try to add as empty variable
        bool isAdded = m_env->addElement(varDecExp->getVarName(), nullptr, false, "");
        if (!isAdded) {
            //TODO add error
            // the new variable name is already in use
            return defaultResult(); 
        }

        // nullptr will be returned because only the variable name is added to the env
        return defaultResult();

    }

    //TODO add error
    //can't create variable
    return defaultResult();

}


// ##########################
// ### Handling Functions ###
// ##########################   

// ### handleAppliedElement ###
// in case in the OclExpression have a 'appliedElement' set handle this here
// updating the contextVariable here
// this call is after any direct children calls
// reset the context afterwards if necessary
std::shared_ptr<Any> EcoreEval::handleAppliedElement(std::shared_ptr<ocl::Expressions::CallExp> appliedElement, std::shared_ptr<Any> parentResult) {

    // save the old context
    std::shared_ptr<Any> old_context = m_env->getContextVariable();
    
    // change the current context
    m_env->setContextVariable(parentResult);

    //create any expression and evaluate
    std::shared_ptr<Any> anyValue = eEcoreAny<std::shared_ptr<ocl::Expressions::OclExpression>>(appliedElement, appliedElement->getMetaElementID());
    
    std::shared_ptr<Any> result = visitNode(anyValue);
    
    // reset the context afterwards if necessary
    if (old_context != m_env->getContextVariable()) {
        m_env->setContextVariable(old_context);
    }
    
    return result;

}

// ### handleCollectionOperations ###
// do the collection operation
// this is called via an OperationCallExp, when no iterator variable is explicitly set
std::shared_ptr<Any> EcoreEval::handleCollectionOperationsOverOpCall(std::string operName, std::shared_ptr<Any> collection, std::string collectionType, std::shared_ptr<Bag<ocl::Expressions::OclExpression>> bodyArgs) {

    //TODO use of collectionType argument
    
    //unpack the collection
    // as Bag<ecore::EObject>
    std::shared_ptr<ecore::EcoreContainerAny> eContAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(collection);
    std::shared_ptr<Bag<ecore::EObject>> eObjBag = nullptr;

    //as Bag<Any>
    std::shared_ptr<Bag<Any>> anyBag = nullptr;

    // as Bag<ecore::EObject>
    if (eContAny != nullptr) {
        eObjBag = eContAny->getAsEObjectContainer();
    }
    else { //try as Bag<Any>
        try
        {
            anyBag = collection->get<std::shared_ptr<Bag<Any>>>();
        }
        catch(...){
            //TODO add error
            // could not evaluate collection
            return defaultResult();
        }
    }

    std::shared_ptr<Any> result;
    
    //check if operation can be handled

    //# including operation #
    if (operName == Utilities::INCLUDING_OPER_NAME) {
        result = oclIncluding(bodyArgs, anyBag, eObjBag, "");
    }
    //# select operation #
    else if (operName == Utilities::SELECT_OPER_NAME) {
        if (bodyArgs->size() != 1) {
            //TODO add error
            //in this constellation only one arg is allowed ...->select(oneArg)
            return defaultResult();
        }
        result = oclSelectReject(true, bodyArgs->at(0), nullptr, collection, "");
    } else if (operName == Utilities::REJECT_OPER_NAME) {
        if (bodyArgs->size() != 1) {
            //TODO add error
            //in this constellation only one arg is allowed ...->reject(oneArg)
            return defaultResult();
        }
        result = oclSelectReject(false, bodyArgs->at(0), nullptr, collection, "");
    }

    //TODO add error
    // collection operation is not handled
    return result;

}

// ####################
// ### oclFunctions ###
// ####################

// ### OclIncluding ###
// manage the ocl Including Operation
std::shared_ptr<Any> EcoreEval::oclIncluding(std::shared_ptr<Bag<ocl::Expressions::OclExpression>> bodyArgs, std::shared_ptr<Bag<Any>> oclCollection, std::shared_ptr<Bag<ecore::EObject>> eObjBag, std::string oclCollectionType) {

    //check if only one Argument is given
    if (bodyArgs->size() != 1) {
        //TODO add error
        //wrong number of arguments for operation
        return defaultResult();
    }

    // eval the argument
    std::shared_ptr<Any> ecoreAny = eEcoreAny(bodyArgs->at(0), bodyArgs->at(0)->getMetaElementID());
    std::shared_ptr<Any> bodyResult = visitNode(ecoreAny);

    //TODO check if result is valid (type check)
    //TODO distinguish collection types

    // define the returnCollection
    std::shared_ptr<Any> returnCollection;

    if (oclCollection != nullptr) {
        returnCollection = eAny(oclCollection, 0, true);
    } else if (eObjBag != nullptr) {
        //try to define the metaID
        // TODO improve this
        unsigned long long metaID = (eObjBag->size() > 0) ? eObjBag->at(0)->getMetaElementID() : ecore::ecorePackage::EOBJECT_CLASS;
        returnCollection = eEcoreContainerAny(eObjBag, metaID);
    } else {
        //TODO add error
        // no valid return collection
        return defaultResult();
    }

    //add element to collection if it is not empty   
    if (bodyResult != nullptr) {

        //add into anyBag
        if (oclCollection != nullptr) {
            oclCollection->add(bodyResult);
        }

        //add into eObjBag
        // TODO type check currently this is UNSAFE
        else /*(eObjBag != nullptr)*/ {
            //try to cast as eObject
            std::shared_ptr<ecore::EObject> bodyObj = castEcoreArgument<ecore::EObject>(bodyResult);
            if (bodyObj != nullptr) {
                eObjBag->add(bodyObj);
            } else {
                //TODO add error
                // the bodyResult can't be casted to eObj;
            }
        }
    }

    return returnCollection;

}

// ### OclSelectReject ###
// manage the ocl Select Operation
//if loopVars is set to nullptr -> it will be interpreted as 0 loopVars
std::shared_ptr<Any> EcoreEval::oclSelectReject(bool isSelect, std::shared_ptr<ocl::Expressions::OclExpression> bodyExp, std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> loopVars, std::shared_ptr<Any> inputCollection, std::string collectionType) {

    //TODO use of collection types
    // default case is Bag<Any>
    
    //if loopVars is set to nullptr -> it will be interpreted as 0 loopVars
    size_t num_loopVars = (loopVars!=nullptr) ? loopVars->size() : 0;

    if (num_loopVars > 1) {
        //TODO add error
        // for 'select'/'reject' at most 1 iterator variable is allowed
        return defaultResult();
    }

    // check if container is Bag<eObj> or Bag<Any>
    bool inputCollectionIsEObjBag = false;

    // check if eObjBag
    std::shared_ptr<ecore::EcoreContainerAny> eContAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(inputCollection);
    std::shared_ptr<Bag<ecore::EObject>> eObjBag = nullptr;

    if (eContAny != nullptr) {
        eObjBag = eContAny->getAsEObjectContainer();
        inputCollectionIsEObjBag = (eObjBag!=nullptr);
    }
    
    //check if Bag<Any>
    std::shared_ptr<Bag<Any>> inputAnyBag = nullptr;

    if (!inputCollectionIsEObjBag) {
        try{
            inputAnyBag = inputCollection->get<std::shared_ptr<Bag<Any>>>();
        }catch(...){}

        if (inputAnyBag == nullptr) {
            //TODO add error
            //inputCollection could not be casted to iterable object
            return defaultResult();
        }
    }

    // necessary to create an new environment to encapsulate loop variables
    std::shared_ptr<EcoreEnvironment> bodyEnv = std::make_shared<EcoreEnvironment>(EcoreEnvironment(m_env, m_env->getSelfVariable()));
    std::shared_ptr<EcoreEval> bodyEval = std::make_shared<EcoreEval>(EcoreEval(bodyEnv));
    
    // 2x2 loop possibilities

    //create returnBag
    std::shared_ptr<Bag<Any>> returnBag = std::make_shared<Bag<Any>>(Bag<Any>());

    // result of the bodyExp
    std::shared_ptr<Any> bodyResult;
    // the result of a select body have to be an bool
    bool bodyResultBool = false;
    
    // no explicit iterator is set
    // first two cases
    if (num_loopVars == 0) {

        // result collection is an eObjBag
        if (inputCollectionIsEObjBag) {

            std::shared_ptr<ecore::EObject> elem;
            
            size_t eObjBagSize = eObjBag->size();
            for (size_t i = 0; i < eObjBagSize; i++){
                
                // get the current elem
                elem = eObjBag->at(i);
                //update the context var
                bodyEnv->setContextVariable(eEcoreAny(elem, elem->getMetaElementID()));
                
                //eval body exp
                bodyResult = bodyEval->visitNode(eEcoreAny(bodyExp, bodyExp->getMetaElementID()));

                //try to cast the body exp to bool
                if (bodyResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {
                    bodyResultBool = bodyResult->get<bool>();
                } else {
                    //TODO add error
                    //bodyExp of select/reject operation could not be casted to bool
                    return defaultResult();
                }

                //add the elem to the returnBag
                // only if the bodyExp evaluates to true (select) or false (reject)
                if ((bodyResultBool && isSelect) || (!bodyResultBool && !isSelect)) {
                    returnBag->add(eEcoreAny(elem, elem->getMetaElementID()));
                }
            }// END of for (size_t i = 0; i < eObjBagSize; i++)
        }// END of if (inputCollectionIsEObjBag)

        //as anyBag
        else {
            std::shared_ptr<Any> elem;
            
            size_t bagSize = inputAnyBag->size();
            for (size_t i = 0; i < bagSize; i++){
                
                // get the current elem
                elem = inputAnyBag->at(i);
                //update the context var
                bodyEnv->setContextVariable(elem);
                
                //eval body exp
                bodyResult = bodyEval->visitNode(eEcoreAny(bodyExp, bodyExp->getMetaElementID()));

                //try to cast the body exp to bool
                if (bodyResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {
                    bodyResultBool = bodyResult->get<bool>();
                } else {
                    //TODO add error
                    //bodyExp of select/reject operation could not be casted to bool
                    return defaultResult();
                }

                //add the elem to the returnBag
                // only if the bodyExp evaluates to true (select) or false (reject)
                if ((bodyResultBool && isSelect) || (!bodyResultBool && !isSelect)) {
                    returnBag->add(elem);
                }
            }// END of for (size_t i = 0; i < bagSize; i++)
        } // END of else (as anyBag)
    }// END of num_loopVars == 0

    else if (num_loopVars == 1) {

        //second 2 cases with explicit iterator Variable

        //evaluate iterator variable
        //this will also add the iterator to the env
        std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = loopVars->at(0);
        bodyEval->visitNode(eEcoreAny(varDecExp, varDecExp->getMetaElementID()));
        std::string iteratorName = varDecExp->getVarName();

        // control variable for the iterator variable
        bool isChanged = false;
        
        //as eObjBag
        if (inputCollectionIsEObjBag) {

            //the current elem
            std::shared_ptr<ecore::EObject> elem;
            
            // bag size and control variable
            size_t eObjBagSize = eObjBag->size();

            for (size_t i = 0; i < eObjBagSize; i++) {

                //get the current obj
                elem = eObjBag->at(i);
                //try to update the current obj
                isChanged = bodyEnv->changeNamedElement(iteratorName, eEcoreAny(elem, elem->getMetaElementID()));
                if (!isChanged) {
                    //TODO add error
                    //the iterator variable could not be updated
                    //maybe incompatible type of elem
                    return defaultResult();
                }

                //execute the bodyExp with the current elem
                bodyResult = bodyEval->visitNode(eEcoreAny(bodyExp, bodyExp->getMetaElementID()));
                //try to cast the body exp to bool
                if (bodyResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {
                    bodyResultBool = bodyResult->get<bool>();
                } else {
                    //TODO add error
                    //bodyExp of select/reject operation could not be casted to bool
                    return defaultResult();
                }
                //add  the elem to the returnBag
                // only if the bodyExp evaluates to true (select)
                if (bodyResultBool && elem != nullptr && isSelect) {
                    returnBag->add(eEcoreAny(elem, elem->getMetaElementID()));
                } else if (!bodyResultBool && elem != nullptr && !isSelect) {
                    // or if false (reject)
                    returnBag->add(eEcoreAny(elem, elem->getMetaElementID()));
                }
            } //END of for (size_t i = 0; i < eObjBagSize; i++)
        }//END of if (inputCollectionIsEObjBag)
        
        //as anyBag
        else {

            // current loop elem
            std::shared_ptr<Any> elem;
            
            size_t bagSize = inputAnyBag->size();
            for (size_t i = 0; i < bagSize; i++){
                
                // get the current elem
                elem = inputAnyBag->at(i);

                isChanged = bodyEnv->changeNamedElement(iteratorName, elem);
                if (!isChanged) {
                    //TODO add error
                    //the iterator variable could not be updated
                    //maybe incompatible type of elem
                    return defaultResult();
                }
                
                //eval bodyExp
                bodyResult = bodyEval->visitNode(eEcoreAny(bodyExp, bodyExp->getMetaElementID()));

                //try to cast the body exp to bool
                if (bodyResult->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {
                    bodyResultBool = bodyResult->get<bool>();
                } else {
                    //TODO add error
                    //bodyExp of select/reject operation could not be casted to bool
                    return defaultResult();
                }

                //add  the elem to the returnBag
                // only if the bodyExp evaluates to true (select)
                if (bodyResultBool && elem != nullptr && isSelect) {
                    returnBag->add(elem);
                } else if (!bodyResultBool && elem != nullptr && !isSelect) {
                    // or if false (reject)
                    returnBag->add(elem);
                }
            }// END of for (size_t i = 0; i < bagSize; i++)
        } // END of else (as anyBag)
    }// END of num_loopVars == 1

    //return the result
    return eAny(returnBag, 0, true);

} //END of EcoreEval::oclSelect

// ########################
// ### callEvalFunction ###
// ########################

std::shared_ptr<Any> EcoreEval::callEvalFunction(std::shared_ptr<Any> exp) {

    const unsigned long inputTypeId = exp->getTypeId();

    std::shared_ptr<Any> result;

    switch (inputTypeId)
    {
    case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_CLASS:
        //ExpressionInOcl
        result = evalExpressionInOcl(exp);
        break;

    // case ocl::Expressions::ExpressionsPackage::INVALIDLITERALEXP_CLASS:
    //     //will return nullptr
    //     //InvalidLiteralExpEval
    //     break;

    case ocl::Expressions::ExpressionsPackage::TUPLELITERALEXP_CLASS:
        //TupleLiteralExpEval
        result = evalTupleLiteralExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::COLLECTIONLITERALEXP_CLASS:
        //CollectionLiteralExpEval
        result = evalCollectionLiteralExp(exp);
        break;

    // case ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_CLASS:
    //     //not needed
    //     //CollectionLiteralItemEval
    //     break;
    
    // case ocl::Expressions::ExpressionsPackage::COLLECTIONRANGE_CLASS:
    //     //not needed
    //     //CollectionRangeEval
    //     break;
    
    // case ocl::Expressions::ExpressionsPackage::NULLLITERALEXP_CLASS:
    //     //will return nullptr
    //     //NullLiteralExpEval
    //     break;

    case ocl::Expressions::ExpressionsPackage::ENUMLITERALEXP_CLASS:
        //TODO
        //EnumLitExpEval
        break;
    
    case ocl::Expressions::ExpressionsPackage::BOOLEANLITERALEXP_CLASS:
        //BooleanLitExpEval
        result = evalBooleanLiteralExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::STRINGLITERALEXP_CLASS:
        //StringLiteralExpEval
        result = evalStringLiteralExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::UNLIMITEDNATURALEXP_CLASS:
        //UnlimitedNaturalLiteralExpEval
        result = evalUnlimitedNaturalLiteralExp(exp);
        break;
    
    case ocl::Expressions::ExpressionsPackage::INTEGERLITERALEXP_CLASS:
        //IntegerLiteralExpEval
        result = evalIntegerLiteralExp(exp);
        break;
    
    case ocl::Expressions::ExpressionsPackage::REALLITERALEXP_CLASS:
        //RealLiteralExpEval
        result = evalRealLiteralExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::OPERATIONCALLEXP_CLASS:
        //OperationCallExpEval
        result = evalOperationCallExp(exp);
        break;
    
    case ocl::Expressions::ExpressionsPackage::ASSOCIATIONCLASSCALLEXP_CLASS:
        //TODO
        //AssociationClassCallExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::PROPERTYCALLEXP_CLASS:
        //PropertyCallExpEval
        result = evalPropertyCallExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::ITERATOREXP_CLASS:
        //IteratorExpEval
        result = evalIteratorExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::ITERATEEXP_CLASS:
        //IterateExpEval
        result = evalIterateExp(exp);
        break;

    // case ocl::Expressions::ExpressionsPackage::TYPEEXP_CLASS:
    //     //not needed
    //     break;

    // case ocl::Expressions::ExpressionsPackage::TUPLETYPEEXP_CLASS:
    //     //not needed
    //     //TupleTypeExpEval
    //     break;

    // case ocl::Expressions::ExpressionsPackage::COLLECTIONTYPEEXP_CLASS:
    //     //not needed
    //     //CollectionTypeExpEval
    //     break;
    
    case ocl::Expressions::ExpressionsPackage::LETEXP_CLASS:
        //LetExpEval
        result = evalLetExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::IFEXP_CLASS:
        //IfExpEval
        result = evalIfExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::VARIABLEEXP_CLASS:
        //VariableExp
        result = evalVariableExp(exp);
        break;
    
    case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_CLASS:
        //TODO
        //PackageDeclExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::PROPERTYCONTEXTDECLEXP_CLASS:
        //TODO
        //PropertyContextDeclExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::CLASSIFIERCONTEXTDECLEXP_CLASS:
        //TODO
        //ClassifierContextDeclExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTDECLEXP_CLASS:
        //TODO
        //OperationContextDeclExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::OPERATIONCONTEXTEXP_CLASS:
        //TODO
        //OperationContextExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::PREPOSTBODYLISTEXP_CLASS:
        //TODO
        //PrePostBodyListExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::PREPOSTBODYEXP_CLASS:
        //TODO
        //PrePostBodyExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::INITORDERVALUELISTEXP_CLASS:
        //TODO
        //InitOrDerValueListExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::INITORDERVALUEEXP_CLASS:
        //TODO
        //InitOrDerValueExpEval
        break;
    
    case ocl::Expressions::ExpressionsPackage::INVORDEFEXP_CLASS:
        //TODO
        //InvOrDefExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::DEFEXP_CLASS:
        //TODO
        //DefExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::PREFIXEDEXP_CLASS:
        //PrefixedExpEval
        result = evalPrefixedExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::OPERATOREXP_CLASS:
        //OperatorExpEval
        result = evalOperatorExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::PARENTEDEXP_CLASS:
        //ParentedExpEval
        return evalParentedExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::VARDECLARATIONEXP_CLASS:
        //VarDeclExpEval
        result = evalVarDeclExp(exp);
        break;

    case ocl::Expressions::ExpressionsPackage::MESSAGEEXP_CLASS:
        //TODO
        //MessageExpEval
        break;

    case ocl::Expressions::ExpressionsPackage::MESSAGEARGUMENTS_CLASS:
        //TODO
        //MessageArgumentsEval
        break;

    // case ocl::Expressions::ExpressionsPackage::UNSPECIFIEDVALUEEXP_CLASS:
    //     //will return nullptr
    //     //UnspecificValueExpEval
    //     break;

    // case ocl::Expressions::ExpressionsPackage::STATEEXP_CLASS:
    //     //UNUSED
    //     //StateExpEval
    //     break;

    // case ocl::Expressions::ExpressionsPackage::INFIXEDEXP_CLASS:
    //     //MOVED INTO OPERATOREXP
    //     //UnspecificValueExpEval
    //     break;

    }

    return result;

};