#include "OclParserCustomVisitor.h"

#include <algorithm>

#include <ecore/ecoreFactory.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EEnumLiteral.hpp>

#include "../Utilities/OclConversion.h"
#include "../Utilities/ConstStrings.h"

#include <ocl/Expressions/ExpressionsFactory.hpp>
//#include <ocl/Expressions/CollectionKind.hpp>
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

using namespace Utilities;

namespace OclCS {

    // ##################
    // ### from antlr ###
    // ##################    

    // just for comparison
    // virtual std::any visitChildren(ParseTree *node) override {
    //   std::any result = defaultResult();
    //   size_t n = node->children.size();
    //   for (size_t i = 0; i < n; i++) {
    //     if (!shouldVisitNextChild(node, result)) {
    //       break;
    //     }

    //     std::any childResult = node->children[i]->accept(this);
    //     result = aggregateResult(std::move(result), std::move(childResult));
    //   }

    //   return result;
    // }
    
    // default Result is nullptr
    std::any OclParserCustomVisitor::defaultResult() {

        std::any empty;
        
        return empty;

    }

    // connect the results to a tree
    std::any OclParserCustomVisitor::aggregateResult(std::any aggregate, std::any nextResult) {
        
        //TODO multiple cases have to be distinguished (e.g. normal, NavExp, IfExp, ...)

        
        // Debug info
        // std::cout << "---------------------------------------------" << std::endl;
        // std::cout << "Aggregate name: " << aggregate.type().name() << std::endl;
        // std::cout << "nextResult name: " << nextResult.type().name() << std::endl;
        // std::cout << "---------------------------------------------" << std::endl;

        //only aggregate have a value
        if (aggregate.has_value() and !nextResult.has_value()) {

            // Debug info
            // std::cout << "---------------------------------------------" << std::endl;
            // std::cout << "Aggregate name: " << aggregate.type().name() << std::endl;
            // std::cout << "---------------------------------------------" << std::endl;
            
            return aggregate;
        
        }

        //only nextResult have a value
        if (!aggregate.has_value() and nextResult.has_value()) {

            // Debug info
            // std::cout << "---------------------------------------------" << std::endl;
            // std::cout << "nextResult name: " << nextResult.type().name() << std::endl;
            // std::cout << "---------------------------------------------" << std::endl;
            
            return nextResult;

        }

        //both have a value
        if (aggregate.has_value() and nextResult.has_value()) {

            // Debug info
            // std::cout << "---------------------------------------------" << std::endl;
            // std::cout << "Aggregate name: " << aggregate.type().name() << std::endl;
            // std::cout << "nextResult name: " << nextResult.type().name() << std::endl;
            // std::cout << "---------------------------------------------" << std::endl;
            
            // #########################
            // ### aggregate handler ###
            // #########################
            
            //ExpressionInOcl
            //append bodyExp
            if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {

                handleExpressionInOcl(aggregate, nextResult);
            }
            //collectionLiteralExp
            //append all "CollectionLiteralPart" from CollectionLiteralParts
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionLiteralExp>)) {

                handleCollectionLiteralExpression(aggregate, nextResult);
            }
            //collectionLiteralParts
            //append either collectionRange or create and append CollectionItem 
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionLiteralParts>)) {

                handleCollectionLiteralParts(aggregate, nextResult);
            }
            //collectionRange -> append upper and lower bound (first and last)
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionRange>)) {
     
                handleCollectionRange(aggregate, nextResult);  
            }
            //TupleLiteralExpression -> append TupleLiteralParts
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::TupleLiteralExp>)) {

                handleTupleLiteralExpression(aggregate, nextResult);

            }
            //AssociationClassCallExpression -> append qualifier
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::AssociationClassCallExp>)) {

                handleAssociationClassExp(aggregate, nextResult);

            }
            //OperationCallExpression -> append arguments
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::OperationCallExp>)) {

                handleOperationCallExp(aggregate, nextResult);

            }
            // Iterator -> append oclExp as correct part (see function)
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::IteratorExp>)) {

                handleIteratorExp(aggregate, nextResult);

            }
            // Iterate -> append oclExp as correct part (see function)
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::IterateExp>)) {

                handleIterateExp(aggregate, nextResult);

            }
            //IfExpression -> append expression parts
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::IfExp>)) {

                handleIfExp(aggregate, nextResult);

            }
            //LetExpression -> append VarDecExp
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::LetExp>)) {

                handleLetExp(aggregate, nextResult);

            }
            //CollectionTypeExpression -> append innerType
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionTypeExp>)) {

                handleCollectionTypeExp(aggregate, nextResult);

            }
            // VarDecExp -> append oclExp to assignedOclExp
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {

                handleVarDeclarationExp(aggregate, nextResult);

            }
            // MessageExpression -> append oclExp from MessageArgumts
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::MessageExp>)) {

                handleMessageExp(aggregate, nextResult);

            }
            // MessageArguments -> append oclExp as MessageArguments
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::MessageArguments>)) {

                handleMessageArguments(aggregate, nextResult);

            }
            // "-" and "NOT"
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::PrefixedExp>)) {

                handlePrefixedExp(aggregate, nextResult);

            }
            // Expressions in "()"
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::ParentedExp>)) {

                handleParentedExp(aggregate, nextResult);

            }
            // set left and right Operand of OperatorExp
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::OperatorExp>)) {

                handleOperatorExp(aggregate, nextResult);

            }
            // add PackageDeclarationExp add contextDeclarations
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::PackageDeclarationExp>)) {

                handlePackageContextDeclExp(aggregate, nextResult);

            }
            // add ClassifierContextDeclExp add invOrDefExpr
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>)) {

                handleClassifierContextDeclExp(aggregate, nextResult);

            }
            // add PropertyContextDeclExp add missing parts
            // append typeExpr and initOrDerivedValueList
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>)) {

                handlePropertyContextDeclExp(aggregate, nextResult);

            }
            // add operationContextDeclExpr missing parts
            // append operationContextExpr and prePostBodyListExpr
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::OperationContextDeclExp>)) {

                handleOperationContextDecl(aggregate, nextResult);

            }
            // append optional parts
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::OperationContextExp>)) {

                handleOperationContextExp(aggregate, nextResult);

            }
            // add pre, post, body
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::PrePostBodyListExp>)) {

                handlePrePostBodyListExp(aggregate, nextResult);

            }
            // add bodyExp
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::PrePostBodyExp>)) {

                handlePrePostBodyExp(aggregate, nextResult);

            }
            // add init, derived expr
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>)) {

                handleInitOrDerValueListExp(aggregate, nextResult);

            }
            // add bodyExp
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::InitOrDerValueExp>)) {

                handleInitOrDerValueExp(aggregate, nextResult);

            }
            // add refferedExp
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::InvOrDefExp>)) {

                handleInvOrDefExp(aggregate, nextResult);

            }
            // add frontExpr and bodyExpr
            else if (aggregate.type() == typeid(std::shared_ptr<ocl::Expressions::DefExp>)) {

                handleDefExp(aggregate, nextResult);

            }

            // ##########################
            // ### nextResult handler ###
            // ##########################

            // set "source" in AssociationCallExp and set "appliedElement" in oclExp
            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::AssociationClassCallExp>)) {

                nR_HandlingAssociationCallExp(aggregate, nextResult);

            }
            //set "source" in PropertyCallExp and set "appliedElement" in oclExp
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::PropertyCallExp>)) {

                nR_HandlingPropertyCallExp(aggregate, nextResult);

            }
            //set "source" in OperationCallExp and set "appliedElement" in oclExp
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::OperationCallExp>)) {

                nR_HandlingOperationCallExp(aggregate, nextResult);

            }
            //set "source" in IteratorExp and set "appliedElement" in oclExp
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::IteratorExp>)) {

                nR_HandlingIteratorExp(aggregate, nextResult);

            }
            //set "source" in IterateExp and set "appliedElement" in oclExp
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::IterateExp>)) {

                nR_HandlingIterateExp(aggregate, nextResult);

            }
            //set the "target" in a MessageExp
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::MessageExp>)) {

                nR_HandlingMessageExp(aggregate, nextResult);

            }

        }

        //default case
        return aggregate;

    };

    // ###############################################################
    // ### handling tasks for differnet cases in aggregateResult() ###
    // ###############################################################

    // ### handleExpInOcl ###
    //append the bodyExp
    // set topExp
    void OclParserCustomVisitor::handleExpressionInOcl(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::ExpressionInOcl> expInOcl = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(aggregate);

        //get nextResult Expression
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        if (oclExp == nullptr) {

            //TODO error
            // only oclExp are allowed at this point

        } else {

            // set the connection for the top expression
            expInOcl->setBodyExpression(oclExp);
            oclExp->setTopExpression(expInOcl);

        }
    }   
    
    // ### handleCollectionLiteralExpression ###
    //append all CollectionParts from CollectionLiteralParts
    void OclParserCustomVisitor::handleCollectionLiteralExpression(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::CollectionLiteralExp> colLitExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionLiteralExp>>(aggregate);

        //get nextResult
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionLiteralParts>)) {

            //get aggreggate Expression
            std::shared_ptr<ocl::Expressions::CollectionLiteralParts> colLitParts = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionLiteralParts>>(nextResult);

            // Debug
            // std::cout << "bag items in colLitParts " << colLitParts->getLiteralParts()->size() << std::endl;

            //iterate through all literalParts from CollectionLiteralParts and add them to collectionLiteralExp
            for(size_t i = 0; i < colLitParts->getLiteralParts()->size(); i++) {

                std::shared_ptr<CollectionLiteralPart> colPart = colLitParts->getLiteralParts()->at(i);
                colLitExp->getPart()->add(colPart);

                // Debug
                // std::cout << "add colPart to ColLitExp" << std::endl;
            }
        } else {

            //TODO addError
            // only collectionLiteralParts are allowed at this point
        }
    }

    // ### handleCollectionLiteralParts ###
    // collect all collection parts (neccessary because of the grammar structure)
    void OclParserCustomVisitor::handleCollectionLiteralParts(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::CollectionLiteralParts> colLitParts = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionLiteralParts>>(aggregate);

        //get nextResult value
        //first try as oclExp
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        //second try as collectionRange
        if (oclExp == nullptr) {

            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionRange>)) {
                
                // add collection range to collectionLiteralParts
                std::shared_ptr<ocl::Expressions::CollectionRange> colRa = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionRange>>(nextResult);
                colLitParts->getLiteralParts()->add(colRa);
                
                // Debug
                // std::cout << "add colRange" << std::endl;

                }
                else {
                //no cast was succesfull
                //either theres a wrong query
                //or an abstract oclExp was set as nextResult (see Utilities::oclCV::exp2oclExp())
                //TODO add error
                }
        } else {
            //it is an oclExp
            //create CollectionLiteralItem and add to collectionLiteralParts
            std::shared_ptr<CollectionItem> colItem = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionItem();

            //set oclExp as item of CollectionItem
            colItem->setItem(oclExp);
            //set Collection item as part of collectionLiteralParts

            // Debug
            // std::cout << "add colItem" << std::endl;
            
            colLitParts->getLiteralParts()->add(colItem);

        }
    }

    // ### handleCollectionRange ###
    // append first and last oclExp
    void OclParserCustomVisitor::handleCollectionRange(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::CollectionRange> colRa = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionRange>>(aggregate);

        //get nextResult
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        if (oclExp == nullptr) {
            //an error occured
            //TODO add error management
            //throw std::invalid_argument("In aggregateResult() -> collectionRange case: std::any value couldn't be converted to oclExpression.");
        }
        //set first
        else if (colRa->getFirst() == nullptr) {
            colRa->setFirst(oclExp); 

            // Debug
            // std::cout << "handleCollectionRange(): set first" << std::endl;

        }
        //else (because of depth first search) last have to be set
        else {
            colRa->setLast(oclExp);

            // Debug
            // std::cout << "handleCollectionRange(): set last" << std::endl;

        }
    }

    // ### handleTupleLiteralExpression ###
    // TupleLiteralExpression -> append TupleLiteralParts
    void OclParserCustomVisitor::handleTupleLiteralExpression(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::TupleLiteralExp> tupExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleLiteralExp>>(aggregate);

        //check if nextResult is from VarDeclarationExp type, only then it can be correctly appended
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {

            //cast as varDecExp and append to TupleLiteralExp
            std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);

            // Debug
            // std::cout << "Added an varDecExp" << std::endl;
            
            tupExp->getPart()->add(varDecExp);

        } else {

            //TODO
            //error: only varDecExp are valid at this point

        }
    }

    // ### handleAssociationClassExp ###
    // append qualifier and set parentNav for qualifier
    void OclParserCustomVisitor::handleAssociationClassExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::AssociationClassCallExp> assExp = std::any_cast<std::shared_ptr<ocl::Expressions::AssociationClassCallExp>>(aggregate);

        //get nextResult
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        if (oclExp == nullptr) {
            //TODO add error
            //the qualifier to append is not a oclExp
        } else {
            //add qualifierExp and set parentNav
            assExp->getQualifier()->add(oclExp);
            oclExp->setParentNav(assExp);

            // Debug
            // std::cout << "handleAssociationClass: append qualifier" << std::endl;
        }

    }

    // ### handlePropertyCallExp ###
    //void OclParserCustomVisitor::handlePropertyCallExp(std::any aggregate, std::any nextResult) {}

    // ### handleOperationCallExp ###
    // append arguments and set parentCall in each argument (oclExpression)
    void OclParserCustomVisitor::handleOperationCallExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::OperationCallExp> opExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationCallExp>>(aggregate);

        //get nextResult
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        if (oclExp == nullptr) {

            //TODO error
            //no cast was successfull
            //the given argument is not an oclExpression

        } else {

            //append argument and set parentCall in argument
            opExp->getArgument()->add(oclExp);
            oclExp->setParentCall(opExp);

            // Debug
            // std::cout << "handleOperationCall: append argument" << std::endl;

        }

    }

    // ### handleIteratorExp###
    // append varDecExp (as iterator in Collection Operation)
    // or append bodyOclExp
    // or append oclExp (as iterator in impl Collection Operation)
    void OclParserCustomVisitor::handleIteratorExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::IteratorExp> itoExp = std::any_cast<std::shared_ptr<ocl::Expressions::IteratorExp>>(aggregate);

        // Debug 
        // std::cout << "handleIteratorExp: Enter function" << std::endl;
        // std::cout << itoExp->isIsCollectionOperation() << std::endl;

        // if it is an CollectionOperation
        // set the VarDecExp (max. 2) or the body oclExp
        if (itoExp->isIsCollectionOperation()) {

            // only varDecExp are allowed
            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {

                // create Exp and append to Iterator
                std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);

                itoExp->getIterator()->add(varDecExp);

                // Debug 
                // std::cout << "handleIteratorExp: set a VarDecExp for a Collection Operation" << std::endl;

            }  
            else {

                //set the loop body owner
                //get nextResult
                std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

                if (oclExp == nullptr) {
                    //TODO error
                    // only oclExp are allowed
                    // missing oclBodyExp

                    // Debug 
                    // std::cout << "handleIteratorExp: Error missing oclBodyExp" << std::endl;

                } else {
                    itoExp->setBody(oclExp);
                    oclExp->setLoopBodyOwner(itoExp);

                    // Debug 
                    // std::cout << "handleIteratorExp: set a oclExp for a Collection Operation as loop body" << std::endl;

                }  
            }

        } else {

            // Debug 
            // std::cout << "handleIteratorExp: Enter no CollectionOperation Part" << std::endl;

            //else append as oclExp (implicit Collection Iterator)
            // add as Iterator Var
            // set the LoopExp in the oclExp
            //get nextResult
            std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

            if (oclExp == nullptr) {

                //TODO add error
                // only oclExp are allowed at this point

                // Debug 
                // std::cout << "handleIteratorExp: Error no oclExp" << std::endl;

            } else {

                itoExp->getIterator()->add(oclExp);
                oclExp->setLoopExp(itoExp);

                // Debug 
                // std::cout << "handleIteratorExp: set a oclExp as loop iterator for implicit Collect Iterator" << std::endl;

            }
        }
    }

    // ### handleIterateExp ###
    // add the iterators variables
    // and the bodyOclExp
    void OclParserCustomVisitor::handleIterateExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::IterateExp> iterExp = std::any_cast<std::shared_ptr<ocl::Expressions::IterateExp>>(aggregate);

        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {

                // create Exp and append to Iterator
                std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);

                iterExp->getIterator()->add(varDecExp);

                // Debug 
                // std::cout << "handleIterateExp: set a VarDecExp for a Collection Operation" << std::endl;

            }  
            else {

                //set the loop body owner
                //get nextResult
                std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

                if (oclExp == nullptr) {
                    //TODO error
                    // only oclExp are allowed
                    // missing oclBodyExp
                } else {
                    iterExp->setBody(oclExp);
                    oclExp->setLoopBodyOwner(iterExp);

                    // Debug 
                    // std::cout << "handleIterateExp: set a oclExp for a Collection Operation as loop body" << std::endl;

                }  
            }
    }

    // ### handleIfExp ###
    // append all parts of the expressions
    void OclParserCustomVisitor::handleIfExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::IfExp> ifExp = std::any_cast<std::shared_ptr<ocl::Expressions::IfExp>>(aggregate);

        //get nextResult
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        if (oclExp == nullptr) {

            //TODO add error
            //Expression have to be an OclExp

        } else {

            //set the if condtion else expression and else expression
            //all parts must be set (see OCL spec)

            //because of depth first search
            //the parts can be set in the correct order by checking what is already set
            if (ifExp->getCondition() == nullptr) {
                ifExp->setCondition(oclExp);
                oclExp->setIfOwner(ifExp);

                // Debug
                //std::cout << "set If Condition" << std::endl;

            }
            else if (ifExp->getThenExpression() == nullptr) {
                ifExp->setThenExpression(oclExp);
                oclExp->setThenOwner(ifExp);

                // Debug
                //std::cout << "set Then Expression" << std::endl;

            }
            else if (ifExp->getElseExpression() == nullptr) {
                ifExp->setElseExpression(oclExp);
                oclExp->setElseOwner(ifExp);

                // Debug
                //std::cout << "set Else Expression" << std::endl;
            }

        }


    }

    //### handle LetExp ###
    //append all variableDeclarations
    void OclParserCustomVisitor::handleLetExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::LetExp> letExp = std::any_cast<std::shared_ptr<ocl::Expressions::LetExp>>(aggregate);

        std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp;

        //get referredOclExp and set as varDecExp, they are only allowed at this point
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {

            varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);

            // Debug
            // std::cout << "LetExp: set a VarDecExp" << std::endl;

        } else {

            //check if it is an oclExp and set as "in" 
            //get nextResult
            std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);
            if (oclExp == nullptr) {

                //TODO add error
                //either the varDecExp is missing (the variables part of the letExp) or the "in" part of the letExp
            } else {

                //set the "in" part of the letExp
                letExp->setIn(oclExp);

                // Debug
                //std::cout << "LetExp: set in Exp" << std::endl;

            }
        }

        //add to the variabel list and set initExp in VarDecExp
        letExp->getVariables()->add(varDecExp);
        varDecExp->setInitExpression(letExp);

    }

    
    // ### handleTupleTypeExp ###
    // append "parts"
    void OclParserCustomVisitor::handleTupleTypeExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::TupleTypeExp> tTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleTypeExp>>(aggregate);

        //check if nextResult is from VarDeclarationExp type, only then it can be correctly appended
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {

            //cast as varDecExp and append to TupleLiteralExp
            std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);

            // Debug
            // std::cout << "TupleTypeExp: Added an varDecExp" << std::endl;
            
            tTypeExp->getPart()->add(varDecExp);

        } else {

            //TODO
            //error: only varDecExp are valid at this point

        }

    }

    // ### handleCollectionTypeExp ###
    // append innerType
    void OclParserCustomVisitor::handleCollectionTypeExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::CollectionTypeExp> cTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionTypeExp>>(aggregate);

        //check if nextResult is an TypeExp
        //set if possible the innerType variable
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TypeExp>)) {

            //innerType is a TypeExp

            //get nextResult Expression
            std::shared_ptr<ocl::Expressions::TypeExp> innerTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TypeExp>>(nextResult);
            cTypeExp->setInnerType(innerTypeExp);

            // Debug
            // std::cout << "CollectionTypeExp: Set TypeExp as innerType" << std::endl;

        } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TupleTypeExp>)) {

            //innerType is a TupleTypeExp
            
            //get nextResult Expression
            std::shared_ptr<ocl::Expressions::TupleTypeExp> innerTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleTypeExp>>(nextResult);
            cTypeExp->setInnerType(innerTypeExp);

            // Debug
            // std::cout << "CollectionTypeExp: Set TupleTypeExp as innerType" << std::endl;

        } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionTypeExp>)){

            //innerType is a CollectionTypeExp
            
            //get nextResult Expression
            std::shared_ptr<ocl::Expressions::CollectionTypeExp> innerTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionTypeExp>>(nextResult);
            cTypeExp->setInnerType(innerTypeExp);

            // Debug
            // std::cout << "CollectionTypeExp: Set CollectionTypeExp as innerType" << std::endl;

        } else {

            //TODO add error
            // inner type must be an TypeExp

        }
    }

    void OclParserCustomVisitor::handleMessageExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::MessageExp> mesExp = std::any_cast<std::shared_ptr<ocl::Expressions::MessageExp>>(aggregate);

        //check if nextResult is MessageArguments and append the single arguments if so
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::MessageArguments>)) {

            //get aggreggate Expression
            std::shared_ptr<ocl::Expressions::MessageArguments> mesAr = std::any_cast<std::shared_ptr<ocl::Expressions::MessageArguments>>(nextResult);

            //iterate through all messageArguments and add them to MessageExpression
            for(size_t i = 0; i < mesAr->getReferredOclExpressions()->size(); i++) {

                std::shared_ptr<OclExpression> oclExp = mesAr->getReferredOclExpressions()->at(i);
                mesExp->getArgument()->add(oclExp);

                // Debug
                // std::cout << "MessageExp: add message Argument to Argument list" << std::endl;
            }

        }

    }

    void OclParserCustomVisitor::handleMessageArguments(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::MessageArguments> mesAr = std::any_cast<std::shared_ptr<ocl::Expressions::MessageArguments>>(aggregate);

        //get nextResult
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

            if (oclExp == nullptr) {

                //no cast was succesfull
                //either theres a wrong query
                //or an abstract oclExp was set as nextResult (see Utilities::oclCV::exp2oclExp())
                //TODO add error

            } else {

                //messageArgs or TypeExp
                mesAr->getReferredOclExpressions()->add(oclExp);

                // Debug
                // std::cout << "MessageArguments: appended oclExp" << std::endl;

            }

    }

    // ### handleVarDeclarationExp ###
    // append oclExp to assignedOclExp
    void OclParserCustomVisitor::handleVarDeclarationExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(aggregate);
        
        //check if the (optional) TypeExp isn't already set and if not, try to set
        if (varDecExp->getVarType() == nullptr) {

            //try all type variants
            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TypeExp>)) {

                //get aggreggate Expression
                std::shared_ptr<ocl::Expressions::TypeExp> typeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TypeExp>>(nextResult);
                //set Type
                varDecExp->setVarType(typeExp);

                // Debug
                // std::cout << "VarDeclarationExp: Set TypeExp as Type" << std::endl;

            } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TupleTypeExp>)) {

                //get aggreggate Expression
                std::shared_ptr<ocl::Expressions::TupleTypeExp> tTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleTypeExp>>(nextResult);
                //set Type
                varDecExp->setVarType(tTypeExp);

                // Debug
                // std::cout << "VarDeclarationExp: Set TupleTypeExp as Type" << std::endl;

            } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionTypeExp>)) {

                //get aggreggate Expression
                std::shared_ptr<ocl::Expressions::CollectionTypeExp> cTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionTypeExp>>(nextResult);
                //set Type
                varDecExp->setVarType(cTypeExp);

                // Debug
                // std::cout << "VarDeclarationExp: Set CollectionTypeExp as Type" << std::endl;

            }
        } else {

            //get nextResult as (optional) assignedExp
            std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

            if (oclExp == nullptr) {

                //no cast was succesfull
                //either theres a wrong query
                //or an abstract oclExp was set as nextResult (see Utilities::oclCV::exp2oclExp())
                //TODO add error

            } else {

                //append (optional) assigned OclExp
                varDecExp->setAssignedOclExp(oclExp);

                // Debug
                // std::cout << "VarDeclarationExp: Assign optional Expression" << std::endl;

            }
        }  
    }

    // ### handlePrefixedExp ###
    // add the referredExp
    //void OclParserCustomVisitor::handlePrefixedExp(std::any aggregate, std::any nextResult) {
    void OclParserCustomVisitor::handlePrefixedExp(std::any aggregate, std::any nextResult) {    

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::PrefixedExp> preExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrefixedExp>>(aggregate);

        //get referredOclExp and set as referredExp
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        if (oclExp == nullptr) {

            //TODO add error
            //there must be an oclExp

        } else {

            //if an operatorExp is found, the prefixedExp have to be downset to the left operand
            // so that e.g.: -2+3 will evaluate as such and not as -(2+3)
            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::OperatorExp>)) {

                //cast oclExp to operatorExp
                std::shared_ptr<ocl::Expressions::OperatorExp> operExp = std::dynamic_pointer_cast<ocl::Expressions::OperatorExp>(oclExp);

                // Debug
                // std::cout << "handlePrefixedExp: Found OperatorExp" << std::endl;                
                
                //find the most left operatorExp and change the leftOperator (see else{})
                while (operExp!=nullptr)
                {

                    //check if left operand is also an operatorExp
                    if (std::dynamic_pointer_cast<ocl::Expressions::OperatorExp>(operExp->getLeftHandOperand())) {

                        // if so get down to this operatorExp
                        operExp = std::dynamic_pointer_cast<ocl::Expressions::OperatorExp>(operExp->getLeftHandOperand());

                        // Debug
                        // std::cout << "handlePrefixedExp: Get down an OperatorExp" << std::endl;

                    } else {

                        //create a prefixedExp with the same unarySymbol as the old PrefixedExp
                        // set the unarySymbol of the old PrefixedExp to "IGNORE"
                        // otherwise the connection to the upper expressions will be lost
                        
                        // Debug
                        // std::shared_ptr<ocl::Expressions::IntegerLiteralExp> interExp = std::dynamic_pointer_cast<ocl::Expressions::IntegerLiteralExp>(operExp->getLeftHandOperand());
                        // std::cout << "Bottom left exp Value: " << interExp->getSymbol() << std::endl;
                        
                        //create new PrefixedExp
                        std::shared_ptr<PrefixedExp> newPreExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPrefixedExp();
                        
                        //copy unarySymbol from the old preExp
                        newPreExp->setUnarySymbol(preExp->getUnarySymbol());
                        
                        //get the current leftOperand
                        std::shared_ptr<ocl::Expressions::OclExpression> leftOperand = operExp->getLeftHandOperand();
                        
                        //set correct referredExp
                        newPreExp->setReferredExpression(leftOperand);
                        
                        //set correct leftOperand
                        operExp->setLeftHandOperand(newPreExp);

                        //mark (old) preExp as to be ignored
                        preExp->setUnarySymbol(Utilities::CONST_IGNORE);

                        //terminate loop
                        operExp = nullptr;

                        // Debug
                        // std::cout << "handlePrefixedExp: Found bottom OperatorExp" << std::endl;

                    }

                    // append the expression to make it later callable
                    preExp->setReferredExpression(oclExp);
                    
                }

            } else {

                // normal set referredExp
                preExp->setReferredExpression(oclExp);
            }
        }
    }

    // ### handleParentedExp ###
    // append innerExp
    void OclParserCustomVisitor::handleParentedExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::ParentedExp> parExp = std::any_cast<std::shared_ptr<ocl::Expressions::ParentedExp>>(aggregate);

        //get referredOclExp
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        // set as innerExp
        if (oclExp == nullptr) {

            //TODO add error
            //there must be an oclExp

        } else {
            parExp->setInnerExp(oclExp);
        }
    }

    
    // ### handleOperatorExp ###
    // append left and right operand
    void OclParserCustomVisitor::handleOperatorExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::OperatorExp> operExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperatorExp>>(aggregate);

        //get referredOclExp
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        // set as innerExp
        if (oclExp == nullptr) {

            //TODO add error
            //there must be an oclExp

        } else {
            
            // set the operands
            // because of depth first search it can be set this way
            if (operExp->getLeftHandOperand() == nullptr) {
                operExp->setLeftHandOperand(oclExp);

                // Debug
                // std::cout << "handleOperatorExp: Set Left Operand" << std::endl;

            } else {
                operExp->setRightHandOperand(oclExp);

                // Debug
                // std::cout << "handleOperatorExp: Set Right Operand" << std::endl;

            }
        }
    }

    // ### handlePackageContextDeclExp ###
    // append contextDeclarations
    void OclParserCustomVisitor::handlePackageContextDeclExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::PackageDeclarationExp> paDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PackageDeclarationExp>>(aggregate);

        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>)) {

            std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> claDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>>(nextResult);
            paDeclExp->getContextDeclarations()->add(claDeclExp);

        } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>)) {

            std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> propDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>>(nextResult);
            paDeclExp->getContextDeclarations()->add(propDeclExp);

        } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::OperationContextDeclExp>)) {

            std::shared_ptr<ocl::Expressions::OperationContextDeclExp> operaDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextDeclExp>>(nextResult);
            paDeclExp->getContextDeclarations()->add(operaDeclExp);

        } else {

            // TODO add error
            // must be an ContextDeclarationExp

        }

    }

    // ### handleClassifierContextDeclExp ###
    // append invOrDecExpr
    void OclParserCustomVisitor::handleClassifierContextDeclExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> claDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>>(aggregate);

        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::InvOrDefExp>)) {
            std::shared_ptr<ocl::Expressions::InvOrDefExp> invOdefExp = std::any_cast<std::shared_ptr<ocl::Expressions::InvOrDefExp>>(nextResult);
            claDeclExp->setInvOrDevExp(invOdefExp);
        } else {

            //TODO add error
            // only InvOrDevExp are allowed at this point

        }
    }

    
    // ### handlePropertyContextDecl ###
    // append typeExpr and initOrDerivedValueList
    void OclParserCustomVisitor::handlePropertyContextDeclExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> propDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>>(aggregate);

        //set type of the property
        if (propDeclExp->getPropType() == nullptr) {

            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TypeExp>)) {
                std::shared_ptr<ocl::Expressions::TypeExp> typeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TypeExp>>(nextResult);
                propDeclExp->setPropType(typeExp);
            }
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TupleTypeExp>)) {
                std::shared_ptr<ocl::Expressions::TupleTypeExp> tupleTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleTypeExp>>(nextResult);
                propDeclExp->setPropType(tupleTypeExp);
            }
            else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionTypeExp>)) {
                std::shared_ptr<ocl::Expressions::CollectionTypeExp> colTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionTypeExp>>(nextResult);
                propDeclExp->setPropType(colTypeExp);
            }

        //set InitOrDerValuesExpr
        } else if (propDeclExp->getInitOrDerValues() == nullptr) {

            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>)) {

                std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> iOdExp = std::any_cast<std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>>(nextResult);
                propDeclExp->setInitOrDerValues(iOdExp);

            }

        } else {

            //TODO error
            // wrong expr input

        }
        
    }

    // ### handleOperationContextDecl ###
    // append operationContextExpr and prePostBodyListExpr
    void OclParserCustomVisitor::handleOperationContextDecl(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::OperationContextDeclExp> operaDeclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextDeclExp>>(aggregate);

        // append as operationContext (operation Argument)
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::OperationContextExp>)
            && operaDeclExp->getOperationContext() == nullptr) {

            std::shared_ptr<ocl::Expressions::OperationContextExp> operaExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextExp>>(nextResult);
            operaDeclExp->setOperationContext(operaExp);

        }
        // append as PrePostBodyExpressions (Pre, Post, Body Expressions)
        else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::PrePostBodyListExp>)
                   && operaDeclExp->getPrePostBodyExpressions() == nullptr) {

            std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ppbListExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrePostBodyListExp>>(nextResult);
            operaDeclExp->setPrePostBodyExpressions(ppbListExp);

        } else {

            //TODO add error
            //wrong Expr at this point
        }
    }

    // ### handleOperationContextExp ###
    // append all (optional) varDeclExp and the (optional) typeExp
    void OclParserCustomVisitor::handleOperationContextExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::OperationContextExp> operaExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextExp>>(aggregate);
        
        // append as VarDeclExp (operation Arguments)
        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {
        
            std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);

            operaExp->getInputParameters()->add(varDecExp);

        }
        // try add as TypeExp (3 possebilities)
        else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TypeExp>)) {

            std::shared_ptr<ocl::Expressions::TypeExp> typeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TypeExp>>(nextResult);

            operaExp->setReturnType(typeExp);

        }
        else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::TupleTypeExp>)) {

            std::shared_ptr<ocl::Expressions::TupleTypeExp> tupleTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleTypeExp>>(nextResult);

            operaExp->setReturnType(tupleTypeExp);

        }
        else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::CollectionTypeExp>)) {

            std::shared_ptr<ocl::Expressions::CollectionTypeExp> colTypeExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionTypeExp>>(nextResult);

            operaExp->setReturnType(colTypeExp);

        } else {

            //TODO
            // add error no allowed Exp at this point

        }

    }

    // ### handlePrePostBodyListExp ###
    // append Pre, Post, Body Expr
    void OclParserCustomVisitor::handlePrePostBodyListExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::PrePostBodyListExp> ppbListExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrePostBodyListExp>>(aggregate);

        // Debug
        // std::cout << "handlePrePostBodyListExp: Enter Exp" << std::endl;

        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::PrePostBodyExp>)) {

            std::shared_ptr<ocl::Expressions::PrePostBodyExp> ppbExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrePostBodyExp>>(nextResult);

            // add to the correct list
            if (ppbExp->getKind() == ocl::Expressions::PrePostBody::PRE) {
                ppbListExp->getPreExpressionList()->add(ppbExp);
            } else if (ppbExp->getKind() == ocl::Expressions::PrePostBody::POST) {
                ppbListExp->getPostExpressionList()->add(ppbExp);
            } else {
                ppbListExp->getBodyExpressionList()->add(ppbExp);
            }

            // Debug
            // std::cout << "handlePrePostBodyListExp: Appended Pre or Post or Body Exp" << std::endl;

        } else {

            //TODO add error
            // nextResult must be an PrePostBodyExp

        }

    }

    // ### handlePrePostBodyExp ###
    // append bodyExp
    void OclParserCustomVisitor::handlePrePostBodyExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::PrePostBodyExp> ppbExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrePostBodyExp>>(aggregate);

        //get referredOclExp
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        // set as innerExp
        if (oclExp == nullptr) {

            //TODO add error
            //there must be an oclExp

        } else {
            ppbExp->setBodyExpression(oclExp);
        }

    }

    // ### handleInitOrDerValueListExp ###
    // append Init, Derived Expr
    void OclParserCustomVisitor::handleInitOrDerValueListExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> iOdListExp = std::any_cast<std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>>(aggregate);

        if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::InitOrDerValueExp>)) {

            std::shared_ptr<ocl::Expressions::InitOrDerValueExp> iOdExp = std::any_cast<std::shared_ptr<ocl::Expressions::InitOrDerValueExp>>(nextResult);

            //add in the correct list
            if (iOdExp->getKind() == Utilities::CONST_INIT) {
                iOdListExp->getInitExpressionList()->add(iOdExp);
            } else {
                iOdListExp->getDerExpressionList()->add(iOdExp);
            }

        } else {

            //TODO add error
            // nextResult must be an InitOrDerValueExp

        }

    }

    // ### handleInitOrDerValueExp ###
    // append bodyExp
    void OclParserCustomVisitor::handleInitOrDerValueExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::InitOrDerValueExp> iOdExp = std::any_cast<std::shared_ptr<ocl::Expressions::InitOrDerValueExp>>(aggregate);

        //get referredOclExp
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);

        // set as innerExp
        if (oclExp == nullptr) {

            //TODO add error
            //there must be an oclExp

        } else {
            iOdExp->setBodyExpression(oclExp);
        }

    }

    // ### handleInvOrDefExp ###
    // append referredExp
    void OclParserCustomVisitor::handleInvOrDefExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::InvOrDefExp> invOrDefExp = std::any_cast<std::shared_ptr<ocl::Expressions::InvOrDefExp>>(aggregate);

        // DEF Exp allow only defExp as refferedExp
        if (invOrDefExp->getKind() != Utilities::CONST_INV) {

            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::DefExp>)) {
                //get aggreggate Expression
                std::shared_ptr<ocl::Expressions::DefExp> defExp = std::any_cast<std::shared_ptr<ocl::Expressions::DefExp>>(nextResult);
                invOrDefExp->setReferredExpression(defExp);

            } else {
                // TODO add error
                // only defExpr are allowed
            }
        } else {

            //get referredOclExp
            std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);
            
            // set as refferedExp
            if (oclExp == nullptr) {
                //TODO add error
                //there must be an oclExp
            } else {
                invOrDefExp->setReferredExpression(oclExp);
            }
        }

    }

    // ### handleDefExp ##
    // append frontExpr and bodyExpr
    void OclParserCustomVisitor::handleDefExp(std::any aggregate, std::any nextResult) {

        //get aggreggate Expression
        std::shared_ptr<ocl::Expressions::DefExp> defExp = std::any_cast<std::shared_ptr<ocl::Expressions::DefExp>>(aggregate);
        
        // check which part of the expre is meant
        // depth first search -> check if frontExpr is set
        if (defExp->getFrontExp() != nullptr) {

            if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {
                std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDecExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(nextResult);
                defExp->setFrontExp(varDecExp); 
            } else if (nextResult.type() == typeid(std::shared_ptr<ocl::Expressions::OperationContextExp>)) {
                std::shared_ptr<ocl::Expressions::OperationContextExp> operaExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextExp>>(nextResult);
                defExp->setFrontExp(operaExp); 
            } else {

                //TODO add error
                // only those two Expressions are allowed as front Expr

            }

        } else {

            // set bodyExpr

            //get referredOclExp
            std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(nextResult);
            
            // set as refferedExp
            if (oclExp == nullptr) {
                //TODO add error
                //there must be an oclExp
            } else {
                defExp->setBodyExp(oclExp);
            }
        }
    }

    // ####################################
    // ### nextResultHandling Functions ###
    // ####################################

    // ### nR_HandlingAssociationCallExp ###
    //set "source" in AssociationCallExp and set "appliedElement" in oclExp
    void OclParserCustomVisitor::nR_HandlingAssociationCallExp(std::any aggregate, std::any nextResult) {

        //get aggregate
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(aggregate);

        if (oclExp == nullptr) {

            //TODO error
            // if it is an ExpInOcl self is used as source (context)
            // or an non oclExp

        } else {

            setAppliedElement<std::shared_ptr<ocl::Expressions::AssociationClassCallExp>>(aggregate, nextResult);

        }
        
    }

    // ### nR_HandlingPropertyCallExp ###
    //set "source" in PropertyCallExp and set "appliedElement" in oclExp
    void OclParserCustomVisitor::nR_HandlingPropertyCallExp(std::any aggregate, std::any nextResult) {

        //get aggregate
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(aggregate);

        if (oclExp == nullptr) {

            //TODO error
            // if it is an ExpInOcl self is used as source (context)
            // or an non oclExp

        } else {
            
            setAppliedElement<std::shared_ptr<ocl::Expressions::PropertyCallExp>>(aggregate, nextResult);
            
        }
    }

    // ### nR_HandlingOperationCallExp ###
    //set "source" in OperationCallExp and set "appliedElement" in oclExp
    void OclParserCustomVisitor::nR_HandlingOperationCallExp(std::any aggregate, std::any nextResult) {

        //get aggregate
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(aggregate);

        if (oclExp == nullptr) {

            //TODO error
            // if it is an ExpInOcl self is used as source (context)
            // or an non oclExp

        } else {

            setAppliedElement<std::shared_ptr<ocl::Expressions::OperationCallExp>>(aggregate, nextResult);

        }
    }

    // ### nR_HandlingIteratorExp ###
    //set "source" in IteratorExp and set "appliedElement" in oclExp
    void OclParserCustomVisitor::nR_HandlingIteratorExp(std::any aggregate, std::any nextResult) {

        //get aggregate
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(aggregate);

        if (oclExp == nullptr) {

            //TODO error
            // if it is an ExpInOcl self is used as source (context)
            // or an non oclExp

        } else {

            setAppliedElement<std::shared_ptr<ocl::Expressions::IteratorExp>>(aggregate, nextResult);
            
        }
    }

    // ### nR_HandlingIterateExp ###
    //set "source" in IterateExp and set "appliedElement" in oclExp
    void OclParserCustomVisitor::nR_HandlingIterateExp(std::any aggregate, std::any nextResult) {

       //get aggregate
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(aggregate);

        if (oclExp == nullptr) {

            //TODO error
            // if it is an ExpInOcl self is used as source (context)
            // or an non oclExp

        } else {

            setAppliedElement<std::shared_ptr<ocl::Expressions::IterateExp>>(aggregate, nextResult);

        }
    }

    // ### nR_HandlingMessageExp ###
    //set the "target" in a MessageExp
    void OclParserCustomVisitor::nR_HandlingMessageExp(std::any aggregate, std::any nextResult) {

        //get aggregate
        std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(aggregate);


        if (oclExp == nullptr) {

            //TODO
            // if it is an ExpInOcl self is used as source (context)
            // or an non oclExp

        } else {

            //get nextResult
            std::shared_ptr<ocl::Expressions::MessageExp> mesExp = std::any_cast<std::shared_ptr<ocl::Expressions::MessageExp>>(nextResult);
            mesExp->setTarget(oclExp);
        }
    }


    // ###########################
    // ### customVisitChildren ###
    // ###########################
    
    // visit the children of the given node and add them to the parent node
    // using the aggregateResult() Function
    std::any OclParserCustomVisitor::customVisitChildren(std::any node, antlr4::tree::ParseTree *antlrTree) {

        std::any result = node;
        size_t n = antlrTree->children.size();
        for (size_t i = 0; i < n; i++) {
            // if (!shouldVisitNextChild(node, result)) {
            // break;
            // }

            std::any childResult = antlrTree->children[i]->accept(this);
            result = OclParserCustomVisitor::aggregateResult(std::move(result), std::move(childResult));
        }

        return result;

    };

    // #######################
    // ### ExpressionInOcl ###
    // #######################
    
    // ### ExpressionInOclCS ###
    // top expression of any OCL Expression
    std::any OclParserCustomVisitor::visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) {

        // create ExpressionInOclCS
        std::shared_ptr<ExpressionInOcl> expInOcl = ocl::Expressions::ExpressionsFactory::eInstance()->createExpressionInOcl();

        //bodyExpression will be appended in aggregateResult

        // Debug
        // std::cout << "visitExpressionInOcl: " << expInOcl->getMetaElementID() << std::endl;

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(expInOcl);

        return customVisitChildren(result, ctx);

    };

    // #####################
    // ### OclExpression ###
    // #####################    
    
    // ### OclExpression ###
    // to handle Rules that are not seperated by a custom Rule (e.g. because no mutual left-recursive in antlr4)
    // Operators e.g.: +,-,*,/,<,>,...
    std::any OclParserCustomVisitor::visitOclExpressionCS(OclParser::OclExpressionCSContext *ctx) {

        std::any emptyResult;
        
        //check if an operatorExpression is present
        // create if necessary
        // operands will be added in aggregateResult
        if (ctx->binaryLiteralExpCS() != nullptr) {

            // <, >, <>, <=, ...
            //create Exp
            std::shared_ptr<OperatorExp> operExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperatorExp();

            // get operator and set
            std::string oper = ctx->binaryLiteralExpCS()->getText();
            operExp->setOperator(oper);

            // Debug
            // std::cout << "oclExp: Set " << oper << " as operator" << std::endl;

            // make an any for the Exp
            std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperatorExp>>(operExp);

            return customVisitChildren(result, ctx);

        } else if (ctx->STAR() != nullptr || ctx->SLASH() != nullptr) {

            // *, /
            //create Exp
            std::shared_ptr<OperatorExp> operExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperatorExp();

            // set correct operator
            if (ctx->STAR() != nullptr) {
                operExp->setOperator(Utilities::CONST_STAR);

                // Debug
                // std::cout << "oclExp: Set '*' as operator" << std::endl;

            } else {
                operExp->setOperator(Utilities::CONST_SLASH);

                // Debug
                // std::cout << "oclExp: Set '/' as operator" << std::endl;

            }

            // make an any for the Exp
            std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperatorExp>>(operExp);

            return customVisitChildren(result, ctx);

        } else if (ctx->PLUS() != nullptr || ctx->MINUS() != nullptr) {

            // +, -
            //create Exp
            std::shared_ptr<OperatorExp> operExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperatorExp();

            // set correct operator
            if (ctx->PLUS() != nullptr) {
                operExp->setOperator(Utilities::CONST_PLUS);

                // Debug
                // std::cout << "oclExp: Set '+' as operator" << std::endl;

            } else {
                operExp->setOperator(Utilities::CONST_MINUS);

                // Debug
                // std::cout << "oclExp: Set '-' as operator" << std::endl;

            }

            // make an any for the Exp
            std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperatorExp>>(operExp);

            return customVisitChildren(result, ctx);

        }

        //if no Expression is created emptyResult will be set
        // to ignore this Expression in the resultTree
        return customVisitChildren(emptyResult, ctx);

    }

    // ##########################
    // ### LiteralExpressions ###
    // ##########################

    // ### EnumLiteralExpCS ###
    std::any OclParserCustomVisitor::visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) {
        
        //create Exp
        std::shared_ptr<EnumLiteralExp> EnumExp = ocl::Expressions::ExpressionsFactory::eInstance()->createEnumLiteralExp();

        //get enum name with path as String
        std::string enumLitStr = ctx->getText();

        //two ways of implementation
        //currently the second one is used because the base model (the model on which the query is made) is unknown at this state 

        // # 1 #
        //ignore the enum name
        //create enum literal and set literal name
        //by ocl spec this should be a reference, but the base model is not known yet
        std::shared_ptr<ecore::EEnumLiteral> enumLitObj = ecore::ecoreFactory::eInstance()->createEEnumLiteral();
        std::string litNameStr = enumLitStr.substr((enumLitStr.find_last_of(Utilities::CONST_COLONCOLON)+1));
        enumLitObj->setLiteral(litNameStr);

        //set newly created enum Object
        EnumExp->setReferredEnumLiteral(enumLitObj);

        // # 2 #
        //store complete enum name and enum literal name as string
        //to resolve later at the evaluation (where the base model is known) 
        EnumExp->setReferredEnumLiteralStr(enumLitStr);

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::EnumLiteralExp>>(EnumExp);

        return customVisitChildren(result, ctx);

    };


    // ### NullLiteralExpCS ###
    std::any OclParserCustomVisitor::visitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<NullLiteralExp> nullExp = ocl::Expressions::ExpressionsFactory::eInstance()->createNullLiteralExp();

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::NullLiteralExp>>(nullExp);

        return customVisitChildren(result, ctx);

    };

    // ### InvalidLiteralExpCS ###
    std::any OclParserCustomVisitor::visitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<InvalidLiteralExp> invalidExp = ocl::Expressions::ExpressionsFactory::eInstance()->createInvalidLiteralExp();

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::InvalidLiteralExp>>(invalidExp);

        return customVisitChildren(result, ctx);

    }; 
    
    
    // ### BooleanLiteralExpCS ###
    std::any OclParserCustomVisitor::visitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *ctx) {

        //create Expression
        std::shared_ptr<BooleanLiteralExp> boolExp = ocl::Expressions::ExpressionsFactory::eInstance()->createBooleanLiteralExp();

        //extract information from grammar (bool value)
        std::string b_str = ctx->BOOL()->getSymbol()->getText();
        bool b = (b_str == Utilities::CONST_TRUE) ? true : false;
        
        // from PrimitiveLiteralExp
        boolExp->setSymbol(b_str);
        
        // from BooleanLiteralExp
        boolExp->setBooleanSymbol(b);

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::BooleanLiteralExp>>(boolExp);

        return customVisitChildren(result, ctx);

    };

    // ### StringLiteralExpCS ###
    std::any OclParserCustomVisitor::visitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<StringLiteralExp> stringExp = ocl::Expressions::ExpressionsFactory::eInstance()->createStringLiteralExp();

        //get string from query
        std::string s_str = ctx->STRING_LITERAL()->getSymbol()->getText();

        char removeChars[] = "'\"";

        for (size_t i = 0; i < strlen(removeChars); i++)
        {
            s_str.erase (std::remove(s_str.begin(), s_str.end(), removeChars[i]), s_str.end());
        }
        

        // from PrimitiveLiteralExp
        stringExp->setSymbol(s_str);
        
        // from StringLiteralExp
        stringExp->setStringSymbol(s_str);

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::StringLiteralExp>>(stringExp);

        return customVisitChildren(result, ctx);
  
    };

    // ### RealLiteralExpCS ###
    std::any OclParserCustomVisitor::visitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<RealLiteralExp> realExp = ocl::Expressions::ExpressionsFactory::eInstance()->createRealLiteralExp();

        //get real as string from query
        std::string r_str = ctx->REAL()->getSymbol()->getText();

        //from PrimitiveLiteralExp
        realExp->setSymbol(r_str);

        //from RealLiteralExp
        realExp->setRealSymbol(std::stod(r_str));

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::RealLiteralExp>>(realExp);

        return customVisitChildren(result, ctx);
        
    };

    // ### UnlimitedNaturalLiteralExpCS ###
    std::any OclParserCustomVisitor::visitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<UnlimitedNaturalExp> unNatExp = ocl::Expressions::ExpressionsFactory::eInstance()->createUnlimitedNaturalExp();

        //get unNat as string from query
        std::string u_str = ctx->getText();
        
        //from PrimitiveExpression
        unNatExp->setSymbol(u_str);

        //from UnlimitednaturalExpression
        //set the unNatSymbol to either -1 for infinity (*)
        //or to the given integer
        if (u_str.compare(Utilities::CONST_STAR) == 0) {
            unNatExp->setUnlimitedNaturalSymbol(-1);
        } else {
            unNatExp->setUnlimitedNaturalSymbol(std::stoi(u_str));
        }

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp>>(unNatExp);

        return customVisitChildren(result, ctx);

    };

    // ### IntegerLiteralExpCS ###
    std::any OclParserCustomVisitor::visitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<IntegerLiteralExp> intExp = ocl::Expressions::ExpressionsFactory::eInstance()->createIntegerLiteralExp();

        //get int as string from query
        std::string i_str = ctx->INT()->getSymbol()->getText();

        //from PrimitiveLiteralExp
        intExp->setSymbol(i_str);

        //from IntegerLiteralExp
        intExp->setIntegerSymbol(std::stoi(i_str));

        // Debug
        // std::cout << "IntegerLiteralExp: set " << i_str << " as integer" << std::endl;
       
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::IntegerLiteralExp>>(intExp);

        return customVisitChildren(result, ctx);

    };

    // ### CollectionLiteralExpCS ###
    std::any OclParserCustomVisitor::visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<CollectionLiteralExp> colExp = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionLiteralExp();

        //get collection kind
        std::string colKi_str = ctx->collectionTypeIdentifierCS()->getText();

        //set collection kind
        if (colKi_str.compare(Utilities::CONST_SET) == 0) {
            colExp->setKind(ocl::Expressions::CollectionKind::SET);
        }
        else if (colKi_str.compare(Utilities::CONST_ORDEREDSET) == 0) {
            colExp->setKind(ocl::Expressions::CollectionKind::ORDEREDSET);
        }
        else if (colKi_str.compare(Utilities::CONST_SEQUENCE) == 0) {
            colExp->setKind(ocl::Expressions::CollectionKind::SEQUENCE);
        }
        else if (colKi_str.compare(Utilities::CONST_BAG) == 0) {
            colExp->setKind(ocl::Expressions::CollectionKind::BAG);
        }
        //this is not allowed
        else if (colKi_str.compare(Utilities::CONST_COLLECTION) == 0) {
            //TODO error management
            //e.g.: 'Collection' is an abstract super class
            //valid collections are: Set, orderedSet, Sequence, Bag
        }  

        //TODO the collection literals will be added via customVisitChildren and aggreagateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::CollectionLiteralExp>>(colExp);

        return customVisitChildren(result, ctx);

    };

    // ### CollectionLiteralPartsCS ###
    //to create an collector for all collectionItems (neccessary because of the grammar structure)
    //parts will be added alter in aggregate result
    std::any OclParserCustomVisitor::visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::CollectionLiteralParts> litPartsExp = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionLiteralParts();

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::CollectionLiteralParts>>(litPartsExp);

        return customVisitChildren(result, ctx);

    }

    // ### CollectionRangeCS ###
    //to distinguish between a range and a single item later in aggregate result
    std::any OclParserCustomVisitor::visitCollectionRangeCS(OclParser::CollectionRangeCSContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::CollectionRange> colRa = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionRange();

        //because the Lexer trys to find the longest matching Rule to a String
        // it is neccessary to define a special Rule for this case otherwise
        // an Real will be missinterpretated (e.g.: 1..2 as 1. Real is wrong) 
        if (ctx->SEQRANGE() != nullptr) {

            //SEQSTRING = Minus? DecimalNumeral Range
            
            std::shared_ptr<PrefixedExp> preExp;
            
            std::string seqString = ctx->SEQRANGE()->getText();
            
            //erase unecessary parts
            seqString.erase(seqString.find(Utilities::CONST_DOTDOT), 2);

            // check if an prefix is set
            if (seqString.find(Utilities::CONST_MINUS) != std::string::npos) {
                
                preExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPrefixedExp();
                preExp->setUnarySymbol(Utilities::CONST_MINUS);

                //removes "-" for further processing
                seqString.erase(seqString.find(Utilities::CONST_MINUS), 1);

            }

            //get int from string
            int first = stoi(seqString);

            //create IntExp and set values
            std::shared_ptr<IntegerLiteralExp> intExp = ocl::Expressions::ExpressionsFactory::eInstance()->createIntegerLiteralExp();
            intExp->setIntegerSymbol(first);
            intExp->setSymbol(seqString);
            
            // set the correct expression as "first" of collectionRange
            if (preExp != nullptr) {
                colRa->setFirst(preExp);

                // Debug
                // std::cout << "collectionRange: set PrefixedExp as first" << std::endl;

            } else {
                colRa->setFirst(intExp);

                // Debug
                // std::cout << "collectionRange: set IntExp as first" << std::endl;

            }
            
        }
        
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::CollectionRange>>(colRa);

        return customVisitChildren(result, ctx);

    }

    // ### TupleLiteralExpCS ###
    std::any OclParserCustomVisitor::visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::TupleLiteralExp> tupExp = ocl::Expressions::ExpressionsFactory::eInstance()->createTupleLiteralExp();

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::TupleLiteralExp>>(tupExp);

        return customVisitChildren(result, ctx);

    }

    // #######################
    // ### CallExpressions ###
    // #######################

    // ### AssociationClassExp_A
    std::any OclParserCustomVisitor::visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::AssociationClassCallExp> assExp = ocl::Expressions::ExpressionsFactory::eInstance()->createAssociationClassCallExp();

        //from CallExp will be set in CustomVisitor

        //from FeatureCallExp

        assExp->setIsPre((ctx->isMarkedPreCS() != nullptr));

        //from NavigationCallExp will be set in CustomVisitor

        //from AssociationClassCallExp

        std::string refAssClName = ctx->simpleNameCS()->getText();
        assExp->setReferredAssociationClass(refAssClName);
        
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::AssociationClassCallExp>>(assExp);

        return customVisitChildren(result, ctx);
        
    }

    // ### AssociationClassExp_B
    std::any OclParserCustomVisitor::visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::AssociationClassCallExp> assExp = ocl::Expressions::ExpressionsFactory::eInstance()->createAssociationClassCallExp();

        //from CallExp will be set in CustomVisitor

        //from FeatureCallExp

        assExp->setIsPre((ctx->isMarkedPreCS() != nullptr));

        //from NavigationCallExp will be set in CustomVisitor

        //from AssociationClassCallExp

        std::string refAssClName = ctx->simpleNameCS()->getText();
        assExp->setReferredAssociationClass(refAssClName);
        
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::AssociationClassCallExp>>(assExp);

        return customVisitChildren(result, ctx);
        
    }

    // ### propertyCallExpCS_A ###
    // set refferedProperty name
    std::any OclParserCustomVisitor::visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::PropertyCallExp> propExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPropertyCallExp();

        //from CallExp will be set in CustomVisitor

        //from FeatureCallExp

        propExp->setIsPre((ctx->isMarkedPreCS() != nullptr));

        //from PropertyClassCallExp
        //set propertyName with (optional) path
        std::string propName = ctx->simpleNameCS()->getText();
        
        if (ctx->pathNameCS() != nullptr) {
            std::string pathName = ctx->pathNameCS()->getText();
            propName.insert(0, pathName + Utilities::CONST_COLONCOLON);
        }

        propExp->setReferredProperty(propName);

        //from NavigationCallExp

        propExp->setNavigationSource(propName);

        // Debug
        // std::cout << "PropertyCallCS_A: set as PropName: " << propName << std::endl;
        
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PropertyCallExp>>(propExp);

        return customVisitChildren(result, ctx);

    }

    // ### propertyCallExpCS_B ###
    // set referredProperty name
    std::any OclParserCustomVisitor::visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::PropertyCallExp> propExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPropertyCallExp();

        //from CallExp will be set in CustomVisitor

        //from FeatureCallExp

        propExp->setIsPre((ctx->isMarkedPreCS() != nullptr));

        //from NavigationCallExp will be set in CustomVisitor

        //from PropertyCallExp
        //set propertyName
        std::string propName = ctx->simpleNameCS()->getText();
        propExp->setReferredProperty(propName);

        //from NavigationCallExp
        propExp->setNavigationSource(propName);

        // Debug
        // std::cout << "PropertyCallCS_B: set as PropName: " << propName << std::endl;
        
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PropertyCallExp>>(propExp);

        return customVisitChildren(result, ctx);

    }

    // ### operationCallExpCS_A ###
    // set referredOperation name
    std::any OclParserCustomVisitor::visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::OperationCallExp> opExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationCallExp();

        //from CallExp will be set in CustomVisitor

        //from FeatureCallExp

        opExp->setIsPre((ctx->isMarkedPreCS() != nullptr));

        //from OperationCallExp
        //set propertyName with (optional) path
        std::string opName = ctx->simpleNameCS()->getText();
        
        if (ctx->pathNameCS() != nullptr) {
            std::string pathName = ctx->pathNameCS()->getText();
            opName.insert(0, pathName + Utilities::CONST_COLONCOLON);
        }

        opExp->setReferredOperation(opName);

        //for later use in eval, to check if it is an collection Operation
        opExp->setIsRArrow(ctx->RARROW()!=nullptr); 

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperationCallExp>>(opExp);

        return customVisitChildren(result, ctx);

    }

    // ### operationCallExpCS_B ###
    // set referredOperation name
    std::any OclParserCustomVisitor::visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::OperationCallExp> opExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationCallExp();

        //from CallExp will be set in CustomVisitor

        //from FeatureCallExp

        opExp->setIsPre((ctx->isMarkedPreCS() != nullptr));

        //from OperationCallExp
        //set propertyName with path or simple name
        std::string opName;
        
        if (ctx->pathNameCS() != nullptr) {
            std::string opName = ctx->pathNameCS()->getText();
        } else if (ctx->pathNameCS() != nullptr) {
            std::string opName = ctx->simpleNameCS()->getText();
        } else {
            //TODO error
            //no operation name is set
            //this case shouldn't be reachable
        }

        opExp->setReferredOperation(opName); 

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperationCallExp>>(opExp);

        return customVisitChildren(result, ctx);

    }

    // ### IteratorExp ###
    // set iteratorName
    // check if it is an implicit Iterator Call
    // check it it is an Collection Operation Call
    std::any OclParserCustomVisitor::visitIteratorExpCS(OclParser::IteratorExpCSContext *ctx) {

        // create Exp
        std::shared_ptr<ocl::Expressions::IteratorExp> itoExp = ocl::Expressions::ExpressionsFactory::eInstance()->createIteratorExp();

        // check if it is an implicit "collect iterator"
        itoExp->setIsImplCollectIterator(ctx->RARROW() == nullptr);
        
        // check if it is an Collection Operation
        itoExp->setIsCollectionOperation(ctx->RARROW() != nullptr);

        // set sourrunding Type (Brackets, Paren, None)
        // for later use in the Evaluation Parts
        if (ctx->LPAREN() != nullptr) {
            itoExp->setSourrundedBy(ocl::Expressions::SurroundingType::PAREN);
        } else if (ctx->LBRACK() != nullptr) {
            itoExp->setSourrundedBy(ocl::Expressions::SurroundingType::BRACKETS);
        } else {
            itoExp->setSourrundedBy(ocl::Expressions::SurroundingType::NONE);
        }

        // get iterator Operation Name or name of the Collection
        std::string itoName = ctx->simpleNameCS()->getText();

        // set iterName
        itoExp->setIterName(itoName);

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::IteratorExp>>(itoExp);

        return customVisitChildren(result, ctx);
    }

    // ### IterateExp ###
    // special kind of iterate function
    // iterName is always "iterate"
    // iterate Collection Operation can parameterized as all other collection Operations
    std::any OclParserCustomVisitor::visitIterateExpCS(OclParser::IterateExpCSContext *ctx) {

        // create Exp
        std::shared_ptr<ocl::Expressions::IterateExp> iterExp = ocl::Expressions::ExpressionsFactory::eInstance()->createIterateExp();

        // the iterateExp is always an Collection Exp
        iterExp->setIsCollectionOperation(true);

        // get iterater Operation Name or name of the Collection
        std::string iterName = ctx->ITERATE()->getText();

        // set iterName
        iterExp->setIterName(iterName);

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::IterateExp>>(iterExp);

        return customVisitChildren(result, ctx);

    }

    // #####################
    // ### If Expression ###
    // #####################

    // ### If Expression ###
    std::any OclParserCustomVisitor::visitIfExpCS(OclParser::IfExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<ocl::Expressions::IfExp> ifExp = ocl::Expressions::ExpressionsFactory::eInstance()->createIfExp();

        //the conditions will be added in the customVisitor

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::IfExp>>(ifExp);

        return customVisitChildren(result, ctx);

    }

    // ###########################
    // ### Variable Expression ###
    // ###########################

    // ### VariableExp ###
    //set variable name as string
    std::any OclParserCustomVisitor::visitVariableExpCS(OclParser::VariableExpCSContext *ctx) {

        // Debug
        // std::cout << "VariableExp: entered" << std::endl;
        
        //create Exp
        std::shared_ptr<VariableExp> varExp = ocl::Expressions::ExpressionsFactory::eInstance()->createVariableExp();

        //set Variable name as string for later reuse
        //either self or a simpleName is set a Variable name
        if (ctx->SELF() != nullptr) {
            varExp->setReferredVariable(Utilities::CONST_SELF);

            // Debug
            // std::cout << "VariableExp: created a 'self' variableExp" << std::endl;


        } else {
            std::string varName = ctx->simpleNameCS()->getText();
            varExp->setReferredVariable(varName);

            // Debug
            // std::cout << "VariableExp: created a " << varName << " variableExp" << std::endl;

        }

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::VariableExp>>(varExp);

        return customVisitChildren(result, ctx);

    }

    // ######################
    // ### Let Expression ###
    // ######################

    // ### LetExp ###
    // create LetExp
    //other parts will be set in customVisitChildren
    std::any OclParserCustomVisitor::visitLetExpCS(OclParser::LetExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<LetExp> letExp = ocl::Expressions::ExpressionsFactory::eInstance()->createLetExp();

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::LetExp>>(letExp);

        return customVisitChildren(result, ctx);

    }

    // ########################
    // ### Type Expressions ###
    // ########################

    // ### TypeExp ###
    // create Expression and set referredType
    // or check if it is a TupleTypeExp or CollectionTypeExp
    std::any OclParserCustomVisitor::visitTypeCS(OclParser::TypeCSContext *ctx) {

        std::any result;
        
        if (ctx->tupleTypeCS() != nullptr) {

            // Debug
            // std::cout << "TypeExp: passed to TupleTypeExp" << std::endl;
            
            // nothing to do in this function, pass to the TupleTypeExp
            return customVisitChildren(result, ctx);

        } else if (ctx->collectionTypeCS() != nullptr) {

            // Debug
            // std::cout << "TypeExp: passed to CollectionTypeExp" << std::endl;
            
            // nothing to do in this function, pass to the CollectionTypeExp
            return customVisitChildren(result, ctx);

        } else {

            // the type can be set directly

            //create Exp
            std::shared_ptr<TypeExp> typeExp = ocl::Expressions::ExpressionsFactory::eInstance()->createTypeExp();

            std::string type;
            
            // check in which form the type is given
            if (ctx->pathNameCS() != nullptr) {
                type = ctx->pathNameCS()->getText();
            } else if (ctx->primitiveTypeCS() != nullptr) {
                type = ctx->primitiveTypeCS()->getText();
            } else /*(ctx->oclTypeCS() != nullptr) must be the last option*/ {
                type = ctx->oclTypeCS()->getText();
            }

            //set the type
            typeExp->setReferredType(type);

            // Debug
            // std::cout << "TypeExp: set referredType to " << type << std::endl;

            // make an any for the Exp
            std::any result = std::make_any<std::shared_ptr<ocl::Expressions::TypeExp>>(typeExp);

            return customVisitChildren(result, ctx);
        }

    }

    // ### TupleTypeExp ###
    // create Expression and set referredType 
    std::any OclParserCustomVisitor::visitTupleTypeCS(OclParser::TupleTypeCSContext *ctx) {

        //create Exp
        std::shared_ptr<TupleTypeExp> tTypeExp = ocl::Expressions::ExpressionsFactory::eInstance()->createTupleTypeExp();

        //get Type
        std::string type = ctx->TUPLE()->getText();
        
        //from TypeExp
        tTypeExp->setReferredType(type);

        //"parts" will be appended in customVisitChildren

        // Debug
        // std::cout << "TupleTypeExp: set referredType to " << type << std::endl;

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::TupleTypeExp>>(tTypeExp);

        return customVisitChildren(result, ctx);

    }
    
    // ### CollectionTypeExp ###
    // create Expression and add referredType 
    std::any OclParserCustomVisitor::visitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) {

        //create Exp
        std::shared_ptr<CollectionTypeExp> cTypeExp = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionTypeExp();

        //get Type
        std::string type = ctx->collectionTypeIdentifierCS()->getText();
        
        //from TypeExp
        cTypeExp->setReferredType(type);

        // Debug
        // std::cout << "CollectionTypeExp: set referredType to " << type << std::endl;

        //TypeCS will be appended in customVisitChildren

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::CollectionTypeExp>>(cTypeExp);

        return customVisitChildren(result, ctx);

    }

    // ###########################
    // ### Message Expressions ###
    // ###########################

    // ### MessageExpression ###
    // create the expressions
    std::any OclParserCustomVisitor::visitOclMessageExpCS(OclParser::OclMessageExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<MessageExp> mesExp = ocl::Expressions::ExpressionsFactory::eInstance()->createMessageExp();

        //appendeing of the other parts will be handled in aggregateResult
        
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::MessageExp>>(mesExp);

        return customVisitChildren(result, ctx);


    }
    
    // ### MessageArgumets ###
    // create the expressions
    //collects in the aggregateResult function all argumnts
    std::any OclParserCustomVisitor::visitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *ctx) {

        //create Exp
        std::shared_ptr<MessageArguments> mesAr = ocl::Expressions::ExpressionsFactory::eInstance()->createMessageArguments();

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::MessageArguments>>(mesAr);

        return customVisitChildren(result, ctx);

    }

    // ########################
    // ### Misc Expressions ###
    // ########################

    //### prefixedExp ###
    std::any OclParserCustomVisitor::visitPrefixedExp(OclParser::PrefixedExpContext *ctx) {

        //not in oclSpec but necessary to handle "-" and "NOT"

        //create Exp
        std::shared_ptr<PrefixedExp> preExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPrefixedExp();

        //get unary symbol
        std::string unarySymbol_str = ctx->unaryLiteralExpCS()->getText();

        //set unarySymbol
        preExp->setUnarySymbol(unarySymbol_str);

        //TODO add referredExp in aggregateResult
        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PrefixedExp>>(preExp);

        return customVisitChildren(result, ctx);

    };

    //### variableDeclarationExp ###
    std::any OclParserCustomVisitor::visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) {

        //not in oclSpec but necessary to handle variable Declaration e.g. in TupleExp

        //create Exp
        std::shared_ptr<VarDeclarationExp> varDecExp = ocl::Expressions::ExpressionsFactory::eInstance()->createVarDeclarationExp();

        //get and set varName

        std::string varName = ctx->simpleNameCS()->getText();

        varDecExp->setVarName(varName);

        // Debug
        // std::cout << "VarDecExp: set " << varName << " as Variable Name" << std::endl;

        //varType (optional) will be set in customVisitChildren

        //optional assignedOclExp will be added in aggregateResult()

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(varDecExp);

        return customVisitChildren(result, ctx);

    }

    // ### parentedExpCS ###
    // an expression the marks that an oclExp is in "()"
    std::any OclParserCustomVisitor::visitParentedExpCS(OclParser::ParentedExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<ParentedExp> parExp = ocl::Expressions::ExpressionsFactory::eInstance()->createParentedExp();

        //innerExp will be set in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::ParentedExp>>(parExp);

        return customVisitChildren(result, ctx);

    }

    // ###########################
    // ### Context Expressions ###
    // ###########################

    // ### PackageDeclarationCS ###
    // create Expr and (optional) path
    std::any OclParserCustomVisitor::visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) {

        //create Exp
        std::shared_ptr<PackageDeclarationExp> paDeclExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPackageDeclarationExp();

        //set (optional) path
        if (ctx->pathNameCS() != nullptr) {
            std::string path = ctx->pathNameCS()->getText();
            paDeclExp->setPath(path);
        }

        // contextDeclarations will be added in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PackageDeclarationExp>>(paDeclExp);

        return customVisitChildren(result, ctx);

    }
    
    // ### ClassifierContextDeclCS ###
    // create Expr and append classifierName
    std::any OclParserCustomVisitor::visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) {

        //create Exp
        std::shared_ptr<ClassifierContextDeclExp> clasDeclExp = ocl::Expressions::ExpressionsFactory::eInstance()->createClassifierContextDeclExp();

        //set operation Name with (optional) path
        std::string clPath = ctx->pathNameCS()->getText();
        
        if (ctx->simpleNameCS() != nullptr) {
            std::string clName = ctx->simpleNameCS()->getText();
            clPath = (clName + Utilities::CONST_COLONCOLON + clPath);
        }

        clasDeclExp->setClassifierName(clPath);

        //invOrDefExp will be added in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>>(clasDeclExp);

        return customVisitChildren(result, ctx);

    }
    
    // ### PropertyContextDeclCS ###
    // create Expr and set name
    std::any OclParserCustomVisitor::visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) {

        //create Exp
        std::shared_ptr<PropertyContextDeclExp> propDeclExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPropertyContextDeclExp();

        //get name
        std::string name = ctx->simpleNameCS()->getText();
        std::string path = ctx->pathNameCS()->getText();

        propDeclExp->setName(path + Utilities::CONST_COLONCOLON + name);

        //other parts will be added in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>>(propDeclExp);

        return customVisitChildren(result, ctx);

    }
    
    // ### OperationContextDeclCS ###
    // create Expr
    std::any OclParserCustomVisitor::visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) {

        //create Exp
        std::shared_ptr<OperationContextDeclExp> operaDeclExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationContextDeclExp();

        //rest parts will be appended in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperationContextDeclExp>>(operaDeclExp);

        return customVisitChildren(result, ctx);

    }
    
    // ### OperationExpCS ###
    // part of OperationContextDeclaration
    std::any OclParserCustomVisitor::visitOperationCS(OclParser::OperationCSContext *ctx) {

        //create Exp
        std::shared_ptr<OperationContextExp> operaExp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationContextExp();

        //set operation Name with (optional) path
        std::string opName = ctx->simpleNameCS()->getText();
        
        if (ctx->pathNameCS() != nullptr) {
            std::string pathName = ctx->pathNameCS()->getText();
            opName.insert(0, pathName + Utilities::CONST_COLONCOLON);
        }

        operaExp->setOperationName(opName);

        //variableDecl and Type will be set in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::OperationContextExp>>(operaExp);

        return customVisitChildren(result, ctx);

    }

    // ### PrePostBodyExpCS ###
    std::any OclParserCustomVisitor::visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) {

        //create Exp
        std::shared_ptr<PrePostBodyListExp> ppbListExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPrePostBodyListExp();

        // parts will be appended in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PrePostBodyListExp>>(ppbListExp);

        return customVisitChildren(result, ctx);


    }

    // ### PrePostBodyExpCS ###
    // part of OperationContextDeclaratuion
    std::any OclParserCustomVisitor::visitPrePostBodyExpCS(OclParser::PrePostBodyExpCSContext *ctx) {

        //create Exp
        std::shared_ptr<PrePostBodyExp> ppbExp = ocl::Expressions::ExpressionsFactory::eInstance()->createPrePostBodyExp();
        
        // set Pre, Post, Body
        if (ctx->PRE() != nullptr) {
            ppbExp->setKind(ocl::Expressions::PrePostBody::PRE);
        } else if (ctx->POST() != nullptr) {
            ppbExp->setKind(ocl::Expressions::PrePostBody::POST);
        } else {
            ppbExp->setKind(ocl::Expressions::PrePostBody::BODY);
        }

        
        // set exp name if set
        if (ctx->simpleNameCS() != nullptr) {
                std::string name = ctx->simpleNameCS()->getText();
                ppbExp->setName(name);
            }

        //bodyExp will be set in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::PrePostBodyExp>>(ppbExp);

        return customVisitChildren(result, ctx);

    }

    // ### InitOrDerValueCS ###
    // create Exp
    std::any OclParserCustomVisitor::visitInitOrDerValueListCS(OclParser::InitOrDerValueListCSContext *ctx) {

        //create Exp
        std::shared_ptr<InitOrDerValueListExp> iOdListExp = ocl::Expressions::ExpressionsFactory::eInstance()->createInitOrDerValueListExp();

        //parts will be set in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>>(iOdListExp);

        return customVisitChildren(result, ctx);


    }

    // ### InitOrDerValueCS ###
    // set Init or Derived as kind
    std::any OclParserCustomVisitor::visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) {

        //create Exp
        std::shared_ptr<InitOrDerValueExp> iOdExp = ocl::Expressions::ExpressionsFactory::eInstance()->createInitOrDerValueExp();

        if (ctx->INIT() != nullptr) {
            iOdExp->setKind(Utilities::CONST_INIT);
        } else {
            iOdExp->setKind(Utilities::CONST_DERIVED);
        }

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::InitOrDerValueExp>>(iOdExp);

        return customVisitChildren(result, ctx);

    }

    // ### InvOrDefExp ### 
    // create Inv or Def Exp
    std::any OclParserCustomVisitor::visitInvOrDefCS(OclParser::InvOrDefCSContext *ctx) {

        //create Exp
        std::shared_ptr<InvOrDefExp> invOdefExp = ocl::Expressions::ExpressionsFactory::eInstance()->createInvOrDefExp();

        // set (optional) name
        if (ctx->simpleNameCS() != nullptr) {
            
            std::string name = ctx->simpleNameCS()->getText();
            invOdefExp->setName(name);

        }

        // referredExp will be set in aggregateResult

        // set Kind
        if (ctx->INV() != nullptr) {
            invOdefExp->setKind(Utilities::CONST_INV);
        } else if (ctx->STATIC() != nullptr) {
            invOdefExp->setKind(Utilities::CONST_STATICDEF);
        } else {
            invOdefExp->setKind(Utilities::CONST_DEF);
        }

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::InvOrDefExp>>(invOdefExp);

        return customVisitChildren(result, ctx);

    }

    // ### DefExpressionCS ###
    // create Exp 
    std::any OclParserCustomVisitor::visitDefExpressionCS(OclParser::DefExpressionCSContext *ctx) {

        //create Exp
        std::shared_ptr<DefExp> defExp = ocl::Expressions::ExpressionsFactory::eInstance()->createDefExp();

        //rest parts will be appended in aggregateResult

        // make an any for the Exp
        std::any result = std::make_any<std::shared_ptr<ocl::Expressions::DefExp>>(defExp);

        return customVisitChildren(result, ctx);

    }

}