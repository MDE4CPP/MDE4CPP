#include "OclParserCustomVisitor.h"
#include "CSTNode.h"
#include "../Utilities/OclReflection.h"
#include "../Utilities/EnvironmentFactory.h"

#include <abstractDataTypes/Bag.hpp>
#include <abstractDataTypes/Subset.hpp>
#include <abstractDataTypes/SubsetUnion.hpp>
#include <abstractDataTypes/Union.hpp>
#include <abstractDataTypes/Any.hpp>

#include <ecore/ecorePackage.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/ecoreFactory.hpp>
#include <types/typesFactory.hpp>
#include <types/typesPackage.hpp>

#include <ocl/Expressions/ExpressionsFactory.hpp>
#include <ocl/Expressions/EnumLiteralExp.hpp>
#include <ocl/Expressions/NavigationCallExp.hpp>
#include <ocl/Expressions/ExpressionInOcl.hpp>
#include <ocl/Expressions/OclExpression.hpp>
#include <ocl/Expressions/VariableExp.hpp>
#include <ocl/Expressions/Variable.hpp>
#include <ocl/Expressions/LetExp.hpp>
#include <ocl/Expressions/TypeExp.hpp>
#include <ocl/Expressions/CollectionLiteralExp.hpp>
#include <ocl/Expressions/CollectionItem.hpp>
#include <ocl/Expressions/CollectionRange.hpp>
#include <ocl/Expressions/CollectionLiteralPart.hpp>
#include <ocl/Expressions/CollectionKind.hpp>
#include <ocl/Expressions/PrimitiveLiteralExp.hpp>
#include <ocl/Expressions/InfixedExp.hpp>
#include <ocl/Expressions/IterateExp.hpp>
#include <ocl/Expressions/IteratorExp.hpp>
#include <ocl/Expressions/IntegerLiteralExp.hpp>
#include <ocl/Expressions/RealLiteralExp.hpp>
#include <ocl/Expressions/BooleanLiteralExp.hpp>
#include <ocl/Expressions/StringLiteralExp.hpp>
#include <ocl/Expressions/UnlimitedNaturalExp.hpp>
#include <ocl/Expressions/TupleLiteralExp.hpp>
#include <ocl/Expressions/TupleLiteralPart.hpp>
#include <ocl/Expressions/InvalidLiteralExp.hpp>
#include <ocl/Expressions/NullLiteralExp.hpp>

#include <ocl/Types/TypesFactory.hpp>
#include <ocl/Types/CollectionType.hpp>
#include <ocl/Types/BagType.hpp>
#include <ocl/Types/OrderedSetType.hpp>
#include <ocl/Types/SetType.hpp>
#include <ocl/Types/SequenceType.hpp>
#include <ocl/Types/AnyType.hpp>
#include <ocl/Types/InvalidType.hpp>
#include <ocl/Types/MessageType.hpp>
#include <ocl/Types/VoidType.hpp>
#include <ocl/Types/TupleType.hpp>
#include <ocl/Types/NameTypeBinding.hpp>

#include <ocl/Values/ValuesFactory.hpp>
#include <ocl/Values/NameValueBinding.hpp>
#include <ocl/Values/Element.hpp>
#include <ocl/Values/ObjectValue.hpp>
#include <ocl/Values/CollectionValue.hpp>
#include <ocl/Values/SequenceTypeValue.hpp>
#include <ocl/Values/BagTypeValue.hpp>
#include <ocl/Values/SetTypeValue.hpp>
#include <ocl/Values/OrderedSetTypeValue.hpp>
#include <ocl/Values/TupleValue.hpp>
#include <ocl/Values/UndefinedValue.hpp>

#include <fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp>

#include <uml/umlFactory.hpp>
#include <uml/umlPackage.hpp>
#include <uml/Enumeration.hpp>
#include <uml/impl/EnumerationImpl.hpp>
#include <uml/EnumerationLiteral.hpp>

#include <ocl/Evaluations/EvaluationsFactory.hpp>
#include <ocl/Evaluations/EvalEnvironment.hpp>
#include <ocl/Evaluations/EnumLiteralExpEval.hpp>
#include <ocl/Evaluations/VariableExpEval.hpp>
#include <ocl/Evaluations/OperationCallExpEval.hpp>
#include <ocl/Evaluations/PropertyCallExpEval.hpp>
#include <ocl/Evaluations/LetExpEval.hpp>
#include <ocl/Evaluations/IterateExpEval.hpp>
#include <ocl/Evaluations/TupleLiteralExpEval.hpp>
#include <ocl/Evaluations/AssociationClassCallExpEval.hpp>
#include <ocl/Evaluations/IntegerLiteralExpEval.hpp>
#include <ocl/Evaluations/BooleanLiteralExpEval.hpp>
#include <ocl/Evaluations/RealLiteralExpEval.hpp>
#include <ocl/Evaluations/UnlimitedNaturalLiteralExpEval.hpp>
#include <ocl/Evaluations/StringLiteralExpEval.hpp>
#include <ocl/Evaluations/UnspecifiedValueExpEval.hpp>
#include <ocl/Evaluations/CollectionLiteralExpEval.hpp>

using namespace Utilities;
using namespace ocl::Values;
using namespace ocl::Types;
using namespace ocl::Evaluations;

namespace OclCS {

antlrcpp::Any OclParserCustomVisitor::visitChildren(antlr4::tree::ParseTree *node)
{
    size_t n = node->children.size();
    CSTNode* cstNode = dynamic_cast<CSTNode*>(node);
    for (size_t i = 0; i < n; i++) {
        antlr4::tree::ParseTree *currentNode = node->children[i];
        CSTNode* currentCST = dynamic_cast<CSTNode*>(currentNode);
        currentCST->setEnv(cstNode->getEnv());
        currentCST->setErrorListener(cstNode->getErrorListener());
        if(currentNode->accept(this)) {
            cstNode->setAST(currentCST->getAST());
        }
        else {
            return false;
        }
    }
    return true;
}

antlrcpp::Any OclParserCustomVisitor::visitOclExpressionCS(OclParser::OclExpressionCSContext *ctx)
{
    if(ctx->oclExpressionCS(0) != nullptr)
    {
        OclParser::OclExpressionCSContext* expr = ctx->oclExpressionCS(0);
        expr->setEnv(ctx->getEnv());
        expr->setErrorListener(ctx->getErrorListener());

        if(visitOclExpressionCS(expr)) {
            if(ctx->operationCallExpCS_A()) {
                OclParser::OperationCallExpCS_AContext* opCS = ctx->operationCallExpCS_A(); // get the CS node
                std::shared_ptr<OperationCallExp> opAS = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationCallExp(); // create the AS node
                std::shared_ptr<OclExpression> src = std::dynamic_pointer_cast<OclExpression>(expr->getAST()); // get the source expression
                opAS->setSource(src); // update the source of the AS node
                opCS->setAST(opAS);  // update the AS node of the CS node
                opCS->setEnv(ctx->getEnv()); // update the environment of the CS node
                opCS->setErrorListener(ctx->getErrorListener());

                if(visitOperationCallExpCS_A(opCS)) { // manage the OperationCallExpCS_A
                    ctx->setAST(opCS->getAST());    // retrieve the result AS node
                    return true;
                }
            }
            else if(ctx->propertyCallExpCS_A()) {
                OclParser::PropertyCallExpCS_AContext* proCS = ctx->propertyCallExpCS_A(); // get the CS node
                std::shared_ptr<PropertyCallExp> proAS = ocl::Expressions::ExpressionsFactory::eInstance()->createPropertyCallExp(); // create the AS node
                std::shared_ptr<OclExpression> src = std::dynamic_pointer_cast<OclExpression>(expr->getAST()); // get the source expression
                proAS->setSource(src); // update the source of the AS node
                proCS->setAST(proAS);  // update the AS node of the CS node
                proCS->setEnv(ctx->getEnv()); // update the environment of the CS node
                proCS->setErrorListener(ctx->getErrorListener());

                if(visitPropertyCallExpCS_A(proCS)) { // manage the propertyCallExpCS_A
                    ctx->setAST(proCS->getAST());    // retrieve the result AS node
                    return true;
                }
            }
            else if(ctx->associationClassCallExpCS_A()) {
                OclParser::AssociationClassCallExpCS_AContext* assCS = ctx->associationClassCallExpCS_A(); // get the CS node
                std::shared_ptr<AssociationClassCallExp> assAS = ocl::Expressions::ExpressionsFactory::eInstance()->createAssociationClassCallExp(); // get the AS node
                std::shared_ptr<OclExpression> src = std::dynamic_pointer_cast<OclExpression>(expr->getAST()); // get the source expression
                assAS->setSource(src); // update the source of the AS node
                assCS->setAST(assAS);  // update the AS node of the CS node
                assCS->setEnv(ctx->getEnv()); // update the environment of the CS node
                assCS->setErrorListener(ctx->getErrorListener());

                if(visitAssociationClassCallExpCS_A(assCS)) {
                    ctx->setAST(assCS->getAST());
                    return true;
                }
            }
            else if(ctx->infixedExpCS()) {
                OclParser::InfixedExpCSContext* infCS = ctx->infixedExpCS(); // get the CS node
                std::shared_ptr<InfixedExp> infAS = ocl::Expressions::ExpressionsFactory::eInstance()->createInfixedExp(); // create the AS node
                std::shared_ptr<OclExpression> src = std::dynamic_pointer_cast<OclExpression>(expr->getAST()); // get the source expression
                infAS->setSource(src); // update the source of the AS node
                infCS->setAST(infAS);  // update the AS node of the CS node
                infCS->setEnv(ctx->getEnv()); // update the environment of the CS node
                infCS->setErrorListener(ctx->getErrorListener());

                if(visitInfixedExpCS(infCS)) { // manage the OperationCallExpCS_A
                    ctx->setAST(infCS->getAST());    // retrieve the result AS node
                    return true;
                }
            }
            else if(ctx->iteratorExpCS()) {
                OclParser::IteratorExpCSContext* iterCS = ctx->iteratorExpCS(); // get the CS node
                std::shared_ptr<IteratorExp> iterAS = ocl::Expressions::ExpressionsFactory::eInstance()->createIteratorExp(); // create the AS node
                std::shared_ptr<OclExpression> src = std::dynamic_pointer_cast<OclExpression>(expr->getAST()); // get the source expression
                iterAS->setSource(src); // update the source of the AS node
                iterCS->setAST(iterAS);  // update the AS node of the CS node
                iterCS->setEnv(ctx->getEnv()); // update the environment of the CS node
                iterCS->setErrorListener(ctx->getErrorListener());

                if(visitIteratorExpCS(iterCS)) { // manage the OperationCallExpCS_A
                    ctx->setAST(iterCS->getAST());    // retrieve the result AS node
                    return true;
                }
            }
            else if(ctx->iterateExpCS()) {
                OclParser::IterateExpCSContext* iterCS = ctx->iterateExpCS(); // get the CS node
                std::shared_ptr<IterateExp> iterAS = ocl::Expressions::ExpressionsFactory::eInstance()->createIterateExp(); // create the AS node
                std::shared_ptr<OclExpression> src = std::dynamic_pointer_cast<OclExpression>(expr->getAST()); // get the source expression
                iterAS->setName("iterate");
                iterAS->setSource(src); // update the source of the AS node
                iterCS->setAST(iterAS);  // update the AS node of the CS node
                iterCS->setEnv(ctx->getEnv()); // update the environment of the CS node
                iterCS->setErrorListener(ctx->getErrorListener());

                if(visitIterateExpCS(iterCS)) { // manage the OperationCallExpCS_A
                    ctx->setAST(iterCS->getAST());    // retrieve the result AS node
                    return true;
                }
            }
            else if(ctx->oclExpressionCS(1) != nullptr) {

                OclParser::OclExpressionCSContext* expr2 = ctx->oclExpressionCS(1); // get the CS node
                expr2->setEnv(ctx->getEnv()); // update the environment of the CS node
                expr2->setErrorListener(ctx->getErrorListener());

                if(visitOclExpressionCS(expr2)) {
                    return arithmeticExpr(ctx);
                }
            }
            else if(ctx->LPAREN() != nullptr && ctx->RPAREN() != nullptr) {
                ctx->setAST(expr->getAST());
                return true;
            }
            else if(ctx->oclMessageExpCS()) {

            }
            return false;
        }
    }

    return visitChildren(ctx);
}

bool OclParserCustomVisitor::visitOperationCallExpCS(CSTNode* ctx, std::shared_ptr<OperationCallExp> exp, std::string simpleName, bool isImplicit)
{
    std::shared_ptr<ecore::EClass> eClass;
    std::shared_ptr<fUML::Semantics::Values::Value> srcValue;

    if(isImplicit) {
        std::shared_ptr<Variable> varImpl = ctx->getEnv()->getSelfVariable();

        eClass = std::dynamic_pointer_cast<ecore::EClass>(varImpl->getEType());
        srcValue = varImpl->getValue();
    } else {
        eClass = std::dynamic_pointer_cast<ecore::EClass>(exp->getSource()->getEType());
        srcValue = exp->getSource()->getInstance()->getResultValue();
    }

    std::shared_ptr<ecore::EOperation> eoper = OclReflection::lookupOperation(eClass, simpleName, exp->getArgument());
    if(eoper != nullptr) {
        std::shared_ptr<OperationCallExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOperationCallExpEval();
        std::shared_ptr<fUML::Semantics::Values::Value> objValue = OclReflection::createValue(eoper, exp->getArgument(), srcValue);

        expEval->setModel(exp);
        expEval->setResultValue(objValue);

        exp->setName(simpleName);
        exp->setInstance(expEval);
        exp->setSource(exp->getSource());
        exp->setEType(eoper->getEType());
        exp->setReferredOperation(eoper);

        return true;
    }
    std::string error = "Unrecognized operation: " + simpleName + "(";
    for(size_t i = 0; i < exp->getArgument()->size(); i++) {
        if(i != 0) {
            error += ", ";
        }
        error += exp->getArgument()->at(i)->getInstance()->getResultValue()->toString();
    }
    error += ")";
    ctx->getErrorListener()->syntaxError(error);
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx)
{
    //OclParser::OclExpressionCSContext* expr = ctx->oclExpressionCS();
    OclParser::ArgumentsCSContext* argCS = ctx->argumentsCS();
    OclParser::IsMarkedPreCSContext* isPreCS = ctx->isMarkedPreCS();
    OclParser::PathNameCSContext* pathNameCS = ctx->pathNameCS();

    std::shared_ptr<OperationCallExp> exp = std::dynamic_pointer_cast<OperationCallExp>(ctx->getAST()); // get the AS with the updated source
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();

    if(pathNameCS != nullptr && isPreCS != nullptr) { // J

    }
    else if(pathNameCS != nullptr) { // I

    }
    else if(isPreCS != nullptr) { // E

    }
    else if(ctx->DOT() != nullptr) { // C
        if(argCS != nullptr) {
            argCS->setEnv(ctx->getEnv());
            argCS->setErrorListener(ctx->getErrorListener());
            argCS->setAST(exp);
            visitArgumentsCS(argCS);
        }

        return visitOperationCallExpCS(ctx, exp, simpleName, false);
    }
    else if(ctx->RARROW() != nullptr) { // B
        if(argCS != nullptr) {
            argCS->setEnv(ctx->getEnv());
            argCS->setErrorListener(ctx->getErrorListener());
            argCS->setAST(exp);
            visitArgumentsCS(argCS);
        }

        return visitOperationCallExpCS(ctx, exp, simpleName, false);
    }
    /*else if(expr != nullptr) { // A
        expr->setEnv(ctx->getEnv());
        expr->setErrorListener(ctx->getErrorListener());

        if(visitOclExpressionCS(expr)) {
            exp->getArgument()->add(expr->getAST());
            return visitOperationCallExpCS(ctx, exp, simpleName, false);
        }
    }*/

    ctx->getErrorListener()->syntaxError("Unknown Error!");
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx)
{
    std::shared_ptr<OperationCallExp> exp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationCallExp();
    ctx->setAST(exp);

    OclParser::SimpleNameCSContext* simCS = ctx->simpleNameCS();
    //OclParser::OclExpressionCSContext* expr = ctx->oclExpressionCS();
    OclParser::ArgumentsCSContext* argCS = ctx->argumentsCS();
    OclParser::IsMarkedPreCSContext* isPreCS = ctx->isMarkedPreCS();
    OclParser::PathNameCSContext* pathNameCS = ctx->pathNameCS();

    if(simCS != nullptr && isPreCS != nullptr) { // F

    }
    else if(simCS != nullptr) { // D
        std::string simpleName = simCS->ID()->getSymbol()->getText();

        if(argCS != nullptr) {
            argCS->setEnv(ctx->getEnv());
            argCS->setErrorListener(ctx->getErrorListener());
            argCS->setAST(exp);
            visitArgumentsCS(argCS);
        }

        return visitOperationCallExpCS(ctx, exp, simpleName, true);
    }
    else if(pathNameCS != nullptr) { // G

    }
    /*else if(simCS != nullptr && expr != nullptr) { // H
        std::string simpleName = simCS->ID()->getSymbol()->getText();
        expr->setEnv(ctx->getEnv());
        expr->setErrorListener(ctx->getErrorListener());

        if(visitOclExpressionCS(expr)) {
            exp->getArgument()->add(expr->getAST());
            return visitOperationCallExpCS(ctx, exp, simpleName, true);
        }
    }*/

    ctx->getErrorListener()->syntaxError("Unknown Error!");
    return false;
}

bool OclParserCustomVisitor::visitPropertyCallExpCS(CSTNode* ctx, std::shared_ptr<PropertyCallExp> exp, std::string simpleName, bool isPre, bool isImplicit)
{
    std::shared_ptr<ecore::EClass> eClass;
    std::shared_ptr<fUML::Semantics::Values::Value> srcValue;

    if(isImplicit) {
        std::shared_ptr<Variable> varImpl = ctx->getEnv()->lookup(simpleName);
        if(varImpl == nullptr) {
            varImpl = ctx->getEnv()->getSelfVariable();
            eClass = std::dynamic_pointer_cast<ecore::EClass>(varImpl->getEType());
            srcValue = varImpl->getValue();
        }
        else {
            std::shared_ptr<PropertyCallExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createPropertyCallExpEval();
            expEval->setModel(exp);
            expEval->setResultValue(varImpl->getValue());
            exp->setName(simpleName);
            exp->setInstance(expEval);
            return true;
        }
    }
    else {
        eClass = std::dynamic_pointer_cast<ecore::EClass>(exp->getSource()->getEType());
        srcValue = exp->getSource()->getInstance()->getResultValue();
    }

    if(isPre) {
        std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(srcValue);
        // retrieve the context at the previous state
        if(objValue != nullptr && !objValue->getHistory()->empty()) {
            std::shared_ptr<LocalSnapshot> lastSnapshot = objValue->getHistory()->at(objValue->getHistory()->size() - 1);
            for(size_t i = 0; i < objValue->getHistory()->size(); i++) {
                std::shared_ptr<LocalSnapshot> lastSnapshot = objValue->getHistory()->at(i);
                if(lastSnapshot->getIsPre()) {
                    if(!lastSnapshot->getBindings()->empty()) {
                        std::shared_ptr<fUML::Semantics::Values::Value> prevObj = lastSnapshot->getBindings()->at(0)->getValue();
                        if(prevObj != nullptr) {
                            srcValue = prevObj;
                            break;
                        }
                    }
                }
            }
        }
    }

    std::shared_ptr<ecore::EAttribute> eatt = OclReflection::lookupProperty(eClass, simpleName);
    if(eatt != nullptr) {
        std::shared_ptr<PropertyCallExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createPropertyCallExpEval();
        std::shared_ptr<fUML::Semantics::Values::Value> objValue = OclReflection::createValue(eatt, srcValue, ctx->getEnv()->getLevel());

        expEval->setModel(exp);
        expEval->setResultValue(objValue);

        exp->setName(simpleName);
        exp->setInstance(expEval);
        exp->setSource(exp->getSource());
        exp->setEType(eatt->getEType());
        exp->setReferredProperty(eatt);
        exp->setIsPre(isPre);
        return true;
    }
    else { // Association
        std::shared_ptr<ecore::EReference> eref = OclReflection::lookupAssociationClass(eClass, simpleName);
        if(eref != nullptr) {
            std::shared_ptr<AssociationClassCallExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createAssociationClassCallExpEval();
            std::shared_ptr<AssociationClassCallExp> assExpr = ocl::Expressions::ExpressionsFactory::eInstance()->createAssociationClassCallExp();
            std::shared_ptr<fUML::Semantics::Values::Value> objValue = OclReflection::createValue(eref, srcValue, ctx->getEnv()->getLevel());

            expEval->setModel(assExpr);
            expEval->setResultValue(objValue);

            assExpr->setName(simpleName);
            assExpr->setInstance(expEval);
            assExpr->setSource(exp->getSource());
            assExpr->setEType(eref->getEType());
            assExpr->setReferredAssociationClass(eref);
            assExpr->setIsPre(isPre);
            ctx->setAST(assExpr);
            return true;
        }
    }
    ctx->getErrorListener()->syntaxError("Unrecognized variable: ("+ simpleName +")");
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx)
{
    std::shared_ptr<PropertyCallExp> exp = std::dynamic_pointer_cast<PropertyCallExp>(ctx->getAST()); // get the AS with the updated source
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
    OclParser::PathNameCSContext* pathName = ctx->pathNameCS();

    if(pathName == nullptr) { // A
        return visitPropertyCallExpCS(ctx, exp, simpleName, ctx->isMarkedPreCS() != nullptr, false);
    }

    ctx->getErrorListener()->syntaxError("Unknown Error!");
    return false;
}
antlrcpp::Any OclParserCustomVisitor::visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx)
{
    std::shared_ptr<PropertyCallExp> exp = ocl::Expressions::ExpressionsFactory::eInstance()->createPropertyCallExp();
    ctx->setAST(exp);

    if(ctx->simpleNameCS() != nullptr) { // B
        std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
        return visitPropertyCallExpCS(ctx, exp, simpleName, ctx->isMarkedPreCS() != nullptr, true);
    }

    ctx->getErrorListener()->syntaxError("Unknown Error!");
    return false;
}

bool OclParserCustomVisitor::visitAssociationCallExpCS(CSTNode *ctx, OclParser::ArgumentsCSContext *argCS, std::shared_ptr<AssociationClassCallExp> exp,
                                                       std::string simpleName, bool isPre, bool isImplicit)
{
    std::shared_ptr<ecore::EClass> eClass;
    std::shared_ptr<fUML::Semantics::Values::Value> srcValue;

    if(isImplicit) {
        std::shared_ptr<Variable> varImpl = ctx->getEnv()->getSelfVariable();

        eClass = std::dynamic_pointer_cast<ecore::EClass>(varImpl->getEType());
        srcValue = varImpl->getValue();
    } else {
        eClass = std::dynamic_pointer_cast<ecore::EClass>(exp->getSource()->getEType());
        srcValue = exp->getSource()->getInstance()->getResultValue();
    }

    std::shared_ptr<ecore::EReference> eref = OclReflection::lookupAssociationClass(eClass, simpleName);
    if(eref != nullptr) {
        std::shared_ptr<AssociationClassCallExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createAssociationClassCallExpEval();
        std::shared_ptr<fUML::Semantics::Values::Value> objValue = OclReflection::createValue(eref, srcValue, ctx->getEnv()->getLevel());

        expEval->setModel(exp);
        expEval->setResultValue(objValue);

        exp->setName(simpleName);
        exp->setInstance(expEval);
        exp->setSource(exp->getSource());
        exp->setEType(eref->getEType());
        exp->setReferredAssociationClass(eref);
        exp->setIsPre(isPre);

        if(argCS != nullptr) {
            argCS->setEnv(ctx->getEnv());
            argCS->setErrorListener(ctx->getErrorListener());
            argCS->setAST(exp);
            visitArgumentsCS(argCS);
        }
        return true;
    }
    ctx->getErrorListener()->syntaxError("Unrecognized variable: ("+ simpleName +")");
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx)
{
    std::shared_ptr<AssociationClassCallExp> exp = std::dynamic_pointer_cast<AssociationClassCallExp>(ctx->getAST()); // get the AS with the updated source
    OclParser::ArgumentsCSContext *argCS = ctx->argumentsCS();
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();

    return visitAssociationCallExpCS(ctx, argCS, exp, simpleName, ctx->isMarkedPreCS() != nullptr, false);
}

antlrcpp::Any OclParserCustomVisitor::visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx)
{
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
    OclParser::ArgumentsCSContext* argCS = ctx->argumentsCS();
    std::shared_ptr<AssociationClassCallExp> exp = ocl::Expressions::ExpressionsFactory::eInstance()->createAssociationClassCallExp();
    ctx->setAST(exp);

    return visitAssociationCallExpCS(ctx, argCS, exp, simpleName, ctx->isMarkedPreCS() != nullptr, true);
}

antlrcpp::Any OclParserCustomVisitor::visitVariableExpCS(OclParser::VariableExpCSContext *ctx)
{
    std::shared_ptr<VariableExp> exp = ocl::Expressions::ExpressionsFactory::eInstance()->createVariableExp();
    ctx->setAST(exp);

    std::shared_ptr<VariableExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createVariableExpEval();
    expEval->setModel(exp);

    if(ctx->SELF() || ctx->simpleNameCS()) {
        std::string name = (ctx->SELF()) ? ctx->SELF()->getSymbol()->getText()
                                         : ctx->simpleNameCS()->ID()->getSymbol()->getText();

        std::shared_ptr<Variable> var = ctx->getEnv()->lookup(name);
        expEval->setResultValue(var->getValue());

        exp->setName(name);
        exp->setInstance(expEval);
        exp->setReferredVariable(var);
        exp->setEType(var->getEType());

        return true;
    }

    ctx->getErrorListener()->syntaxError("Unknown Error!");
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitLetExpCS(OclParser::LetExpCSContext *ctx)
{
    std::shared_ptr<LetExp> letExp = ocl::Expressions::ExpressionsFactory::eInstance()->createLetExp();
    std::shared_ptr<Environment> env = EnvironmentFactory::getInstance().createEnvironment(ctx->getEnv());
    OclParser::VariableDeclarationCSContext *varDeclCS = ctx->variableDeclarationCS();
    varDeclCS->setEnv(env);
    varDeclCS->setErrorListener(ctx->getErrorListener());

    if(visitVariableDeclarationCS(varDeclCS)) {
        std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(varDeclCS->getAST());
        OclParser::LetExpSubCSContext *letsubCS = ctx->letExpSubCS();
        letsubCS->setEnv(env);
        letsubCS->setErrorListener(ctx->getErrorListener());

        if(visitLetExpSubCS(letsubCS)) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> varValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
            std::shared_ptr<LetExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createLetExpEval();

            varValue->setValue(varExp->getName());
            expEval->setModel(letExp);
            expEval->setVariable(varValue);
            expEval->setIn(letsubCS->getAST()->getInstance());
            expEval->setResultValue(letsubCS->getAST()->getInstance()->getResultValue());

            letExp->setVariable(varExp->getReferredVariable());
            letExp->setIn(letsubCS->getAST());
            letExp->setInstance(expEval);

            ctx->setAST(letExp);
            return true;
        }
    }

    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx)
{
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
    OclParser::OclExpressionCSContext* exprCS = ctx->oclExpressionCS();
    OclParser::TypeCSContext* typeCS = ctx->typeCS();

    if(ctx->getEnv()->lookup(simpleName) == nullptr) {
        std::shared_ptr<ecore::EClassifier> type = nullptr;
        std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
        std::shared_ptr<VariableExp> varExp = ocl::Expressions::ExpressionsFactory::eInstance()->createVariableExp();
        std::shared_ptr<VariableExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createVariableExpEval();

        if(exprCS != nullptr) {
            exprCS->setEnv(ctx->getEnv());
            exprCS->setErrorListener(ctx->getErrorListener());
            if(visitOclExpressionCS(exprCS)) {
                std::shared_ptr<OclExpression> oclExp = exprCS->getAST();
                type = oclExp->getEType();
                expEval->setResultValue(oclExp->getInstance()->getResultValue());
            }
        }
        else {
            expEval->setResultValue(ocl::Values::ValuesFactory::eInstance()->createUndefinedValue());
        }

        if(typeCS != nullptr) {
            typeCS->setEnv(ctx->getEnv());
            typeCS->setErrorListener(ctx->getErrorListener());
            if(visitTypeCS(typeCS)) {
                std::shared_ptr<TypeExp> typeExp = std::dynamic_pointer_cast<TypeExp>(typeCS->getAST());
                if(type != nullptr && !OclReflection::kindOf(type, typeExp->getReferredType())) {
                    ctx->getErrorListener()->syntaxError("The type and the value of the variable ("+ simpleName +") are not compatible");
                    return false;
                }
                type = typeExp->getReferredType();
            }
            else {
                return false;
            }
        }

        var->setValue(expEval->getResultValue());
        var->setName(simpleName);
        var->setEType(type);
        ctx->getEnv()->addElement(simpleName, var, false);

        expEval->setModel(varExp);
        varExp->setName(simpleName);
        varExp->setInstance(expEval);
        varExp->setReferredVariable(var);
        varExp->setEType(var->getEType());

        ctx->setAST(varExp);
        return true;
    }
    else {
        ctx->getErrorListener()->syntaxError("The variable ("+ simpleName +") must be unique in the current scope");
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitLetExpSubCS(OclParser::LetExpSubCSContext *ctx)
{
    if(ctx->COMMA() != nullptr) {
        OclParser::VariableDeclarationCSContext *varDeclCS = ctx->variableDeclarationCS();
        varDeclCS->setEnv(ctx->getEnv());
        varDeclCS->setErrorListener(ctx->getErrorListener());

        if(visitVariableDeclarationCS(varDeclCS)) {
            std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(varDeclCS->getAST());
            OclParser::LetExpSubCSContext *letsubCS = ctx->letExpSubCS();
            letsubCS->setEnv(ctx->getEnv());
            letsubCS->setErrorListener(ctx->getErrorListener());

            if(visitLetExpSubCS(letsubCS)) {
                ctx->setAST(letsubCS->getAST());
                return true;
            }
        }
    }
    else {
        OclParser::OclExpressionCSContext *oclExp = ctx->oclExpressionCS();
        oclExp->setEnv(ctx->getEnv());
        oclExp->setErrorListener(ctx->getErrorListener());

        if(visitOclExpressionCS(oclExp)) {
            ctx->setAST(oclExp->getAST());
            return true;
        }
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitTypeCS(OclParser::TypeCSContext *ctx)
{
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();
    OclParser::CollectionTypeCSContext* collCS = ctx->collectionTypeCS();
    OclParser::TupleTypeCSContext* tupleCS = ctx->tupleTypeCS();
    OclParser::PrimitiveTypeCSContext* priCS = ctx->primitiveTypeCS();
    OclParser::OclTypeCSContext* oclTypeCS = ctx->oclTypeCS();

    std::shared_ptr<TypeExp> typeAS = ocl::Expressions::ExpressionsFactory::eInstance()->createTypeExp();
    ctx->setAST(typeAS);

    if(pathCS != nullptr) {
        pathCS->setEnv(ctx->getEnv());
        pathCS->setErrorListener(ctx->getErrorListener());
        antlrcpp::Any result =  visitPathNameCS(pathCS);
        std::vector<std::string> seq = result.as<std::vector<std::string>>();
        std::shared_ptr<Variable> var = ctx->getEnv()->lookupPathName(seq);
        if(var != nullptr) {
            std::shared_ptr<ecore::EClassifier> ref = var->getEType();
            std::shared_ptr<OclExpEval> typeEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOclExpEval();
            std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
            objValue->setValue(ref);
            typeEval->setResultValue(objValue);
            typeAS->setInstance(typeEval);
            typeAS->setReferredType(ref);
            typeAS->setEType(ref);
            return true;
        }
        else{
            std::string path = getPath(seq);
            ctx->getErrorListener()->syntaxError("The path ("+ path +") must be unique in the current scope");
        }
    }
    else if(collCS != nullptr) {
        collCS->setAST(typeAS);
        collCS->setEnv(ctx->getEnv());
        collCS->setErrorListener(ctx->getErrorListener());
        if(visitCollectionTypeCS(collCS)) {
            return true;
        }
    }
    else if(tupleCS != nullptr) {
        tupleCS->setAST(typeAS);
        tupleCS->setEnv(ctx->getEnv());
        tupleCS->setErrorListener(ctx->getErrorListener());
        if(visitTupleTypeCS(tupleCS)) {
            return true;
        }
    }
    else if(priCS != nullptr) {
        std::shared_ptr<ecore::EClassifier> ref = nullptr;
        if(priCS->OCLBOOLEAN() != nullptr) {
            ref = ::types::typesPackage::eInstance()->getBoolean_Class();
        }
        else if(priCS->OCLSTRING() != nullptr) {
            ref = ::types::typesPackage::eInstance()->getString_Class();
        }
        else if(priCS->OCLREAL() != nullptr) {
            ref = ::types::typesPackage::eInstance()->getReal_Class();
        }
        else if(priCS->OCLINTEGER() != nullptr) {
            ref = ::types::typesPackage::eInstance()->getInteger_Class();
        }
        else {
            ref = ::types::typesPackage::eInstance()->getUnlimitedNatural_Class();
        }
        std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
        std::shared_ptr<OclExpEval> typeEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOclExpEval();

        objValue->setValue(ref);
        typeEval->setResultValue(objValue);
        typeAS->setInstance(typeEval);
        typeAS->setReferredType(ref);
        typeAS->setEType(ref);
        return true;
    }
    else if(oclTypeCS != nullptr) {
        std::shared_ptr<ecore::EClassifier> ref = nullptr;
        if(oclTypeCS->OCLANY() != nullptr) {
            ref = ocl::Types::TypesFactory::eInstance()->createAnyType();
        }
        else if(oclTypeCS->OCLINVALID() != nullptr) {
            ref = ocl::Types::TypesFactory::eInstance()->createInvalidType();
        }
        else if(oclTypeCS->OCLMESSAGE() != nullptr) {
            ref = ocl::Types::TypesFactory::eInstance()->createMessageType();
        }
        else {
            ref = ocl::Types::TypesFactory::eInstance()->createVoidType();
        }
        std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
        std::shared_ptr<OclExpEval> typeEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOclExpEval();

        objValue->setValue(ref);
        typeEval->setResultValue(objValue);
        typeAS->setInstance(typeEval);
        typeAS->setReferredType(ref);
        typeAS->setEType(ref);
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitPathNameCS(OclParser::PathNameCSContext *ctx)
{
    OclParser::SimpleNameCSContext* simpleCS = ctx->simpleNameCS();
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();
    OclParser::UnreservedSimpleNameCSContext* unreCS = ctx->unreservedSimpleNameCS();

    if(simpleCS != nullptr) {
        std::string simpleName = simpleCS->ID()->getSymbol()->getText();
        vector<std::string> seq {simpleName};
        return seq;
    }
    else {
        pathCS->setEnv(ctx->getEnv());
        pathCS->setErrorListener(ctx->getErrorListener());
        antlrcpp::Any result1 = visitPathNameCS(pathCS);
        vector<std::string> seq = result1.as<vector<std::string>>();

        antlrcpp::Any result2 = visitUnreservedSimpleNameCS(unreCS);
        std::string unresName = result2.as<std::string>();
        seq.push_back(unresName);
        return seq;
    }
    return vector<std::string>();
}

antlrcpp::Any OclParserCustomVisitor::visitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *ctx)
{
    if(ctx->collectionTypeIdentifierCS() != nullptr) {
        return visitCollectionTypeIdentifierCS(ctx->collectionTypeIdentifierCS());
    }
    else if(ctx->primitiveTypeCS() != nullptr) {
        return visitPrimitiveTypeCS(ctx->primitiveTypeCS());
    }
    else if(ctx->oclTypeCS() != nullptr) {
        return visitOclTypeCS(ctx->oclTypeCS());
    }
    else {
        return ctx->TUPLE()->getSymbol()->getText();
    }
}

antlrcpp::Any OclParserCustomVisitor::visitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *ctx)
{
    OclParser::SimpleNameCSContext* simpleCS = ctx->simpleNameCS();
    OclParser::RestrictedKeywordCSContext* restCS = ctx->restrictedKeywordCS();

    if(simpleCS != nullptr) {
        return simpleCS->ID()->getSymbol()->getText();
    }
    else {
        return visitRestrictedKeywordCS(restCS);
    }
}

antlrcpp::Any OclParserCustomVisitor::visitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *ctx)
{
    if(ctx->OCLBOOLEAN() != nullptr) {
        return ctx->OCLBOOLEAN()->getSymbol()->getText();
    }
    else if(ctx->OCLINTEGER() != nullptr) {
        return ctx->OCLINTEGER()->getSymbol()->getText();
    }
    else if(ctx->OCLREAL() != nullptr) {
        return ctx->OCLREAL()->getSymbol()->getText();
    }
    else if(ctx->OCLSTRING() != nullptr) {
        return ctx->OCLSTRING()->getSymbol()->getText();
    }
    else {
        return ctx->OCLUNLIMITEDNAT()->getSymbol()->getText();
    }
}

antlrcpp::Any OclParserCustomVisitor::visitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *ctx)
{
    if(ctx->SET() != nullptr) {
        return ctx->SET()->getSymbol()->getText();
    }
    else if(ctx->BAG() != nullptr) {
        return ctx->BAG()->getSymbol()->getText();
    }
    else if(ctx->SEQUENCE() != nullptr) {
        return ctx->SEQUENCE()->getSymbol()->getText();
    }
    else if(ctx->COLLECTION() != nullptr) {
        return ctx->COLLECTION()->getSymbol()->getText();
    }
    else {
        return ctx->ORDEREDSET()->getSymbol()->getText();
    }
}

antlrcpp::Any OclParserCustomVisitor::visitOclTypeCS(OclParser::OclTypeCSContext *ctx)
{
    if(ctx->OCLANY() != nullptr) {
        return ctx->OCLANY()->getSymbol()->getText();
    }
    else if(ctx->OCLINVALID() != nullptr) {
        return ctx->OCLINVALID()->getSymbol()->getText();
    }
    else if(ctx->OCLMESSAGE() != nullptr) {
        return ctx->OCLMESSAGE()->getSymbol()->getText();
    }
    else {
        return ctx->OCLVOID()->getSymbol()->getText();
    }
}

antlrcpp::Any OclParserCustomVisitor::visitSimpleNameCS(OclParser::SimpleNameCSContext *ctx)
{
    return ctx->ID()->getSymbol()->getText();
}

antlrcpp::Any OclParserCustomVisitor::visitPrefixedExp(OclParser::PrefixedExpContext *ctx)
{
    OclParser::OclExpressionCSContext* exprCS = ctx->oclExpressionCS();
    exprCS->setEnv(ctx->getEnv());
    exprCS->setErrorListener(ctx->getErrorListener());

    if(visitOclExpressionCS(exprCS)) {
        std::shared_ptr<OclExpression> exprAS = exprCS->getAST();
        std::shared_ptr<fUML::Semantics::Values::Value> value = exprAS->getInstance()->getResultValue();
        ctx->setAST(exprAS);

        if(ctx->unaryLiteralExpCS()->NOT() != nullptr) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(value);
            if(boolValue != nullptr) {
                boolValue->setValue(!boolValue->isValue());
                return true;
            }
            ctx->getErrorListener()->syntaxError("The keyword (not) must be applied to boolean expression");
        }
        else  { // ctx->unaryLiteralExpCS()->MINUS() != nullptr
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(value);
            if(intValue != nullptr) {
                intValue->setValue(-intValue->getValue());
                return true;
            }
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(value);
            if(realValue != nullptr) {
                realValue->setValue(-realValue->getValue());
                return true;
            }
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> unlimitedValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(value);
            if(unlimitedValue != nullptr) {
                unlimitedValue->setValue(-unlimitedValue->getValue());
                return true;
            }
            ctx->getErrorListener()->syntaxError("The negative prefix (-) must be applied to numeric expression");
        }
    }

    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitInfixedExpCS(OclParser::InfixedExpCSContext *ctx)
{
    std::shared_ptr<InfixedExp> infExpr = std::dynamic_pointer_cast<InfixedExp>(ctx->getAST());
    OclParser::OclExpressionCSContext* expr = ctx->oclExpressionCS();
    OclParser::BinaryLiteralExpCSContext* binCS = ctx->binaryLiteralExpCS();
    std::shared_ptr<OclExpEval> infEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOclExpEval();

    infExpr->setInstance(infEval);
    expr->setEnv(ctx->getEnv());
    expr->setErrorListener(ctx->getErrorListener());

    if(visitOclExpressionCS(expr)) {
        std::shared_ptr<OclExpression> leftExpr = infExpr->getSource();
        std::shared_ptr<OclExpression> rightExpr = expr->getAST();
        std::shared_ptr<fUML::Semantics::Values::Value> leftvalue = leftExpr->getInstance()->getResultValue();
        std::shared_ptr<fUML::Semantics::Values::Value> rightvalue = rightExpr->getInstance()->getResultValue();

        if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::StringValue>(leftvalue)) {
            if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::StringValue>(rightvalue)) {
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> leftString = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(leftvalue);
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> rightString = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(rightvalue);
                bool result = false;
                if(binCS->LT() != nullptr) { // leftString < rigtString
                    result = leftString->getValue() < rightString->getValue();
                }
                else if(binCS->GT() != nullptr) { // leftString > rigtString
                    result = leftString->getValue() > rightString->getValue();
                }
                else if(binCS->LTE() != nullptr) { // leftString <= rigtString
                    result = leftString->getValue() <= rightString->getValue();
                }
                else if(binCS->GTE() != nullptr) { // leftString >= rigtString
                    result = leftString->getValue() >= rightString->getValue();
                }
                else if(binCS->ASSIGN() != nullptr) { // leftString == rigtString
                    result = leftString->getValue() == rightString->getValue();
                }
                else if(binCS->INEQUAL() != nullptr) { // leftString != rigtString
                    result = leftString->getValue() != rightString->getValue();
                }
                else {
                    ctx->getErrorListener()->syntaxError("The possible binary operations between two string are : <, >, <=, >=, =, <>, +");
                    return false;
                }
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                boolValue->setValue(result);
                infEval->setResultValue(boolValue);
                infExpr->setEType(type);
                return true;
            }
            else {
                ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left value string must also be a string");
                return false;
            }
        }
        else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::BooleanValue>(leftvalue)) {
            if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::BooleanValue>(rightvalue)) {
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> leftBool = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(leftvalue);
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> rightBool = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(rightvalue);
                bool result = false;
                if(binCS->ASSIGN() != nullptr) { // leftBool == rightBool
                    result = leftBool->isValue() == rightBool->isValue();
                }
                else if(binCS->INEQUAL() != nullptr) { // leftBool != rightBool
                    result = leftBool->isValue() != rightBool->isValue();
                }
                else if(binCS->KEYOR() != nullptr) { // leftBool || rightBool
                    result = leftBool->isValue() || rightBool->isValue();
                }
                else if(binCS->KEYAND() != nullptr) { // leftBool && rightBool
                    result = leftBool->isValue() && rightBool->isValue();
                }
                else if(binCS->IMPLIES() != nullptr) { // leftBool => rightBool
                    result = !leftBool->isValue() || rightBool->isValue();
                }
                else {
                    ctx->getErrorListener()->syntaxError("The possible binary operations between two boolean are : or, and, =, <>, implies");
                    return false;
                }
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                infExpr->setEType(type);
                boolValue->setValue(result);
                infEval->setResultValue(boolValue);
                return true;
            }
            else {
                ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left value string must also be a string");
                return false;
            }
        }
        if(OclReflection::instanceOf<CollectionValue>(leftvalue)) {
            if(OclReflection::instanceOf<CollectionValue>(rightvalue)) {
                std::shared_ptr<CollectionValue> leftCol = std::dynamic_pointer_cast<CollectionValue>(leftvalue);
                std::shared_ptr<CollectionValue> rightCol = std::dynamic_pointer_cast<CollectionValue>(rightvalue);
                bool result = false;
                if(binCS->ASSIGN() != nullptr) { // leftCol == rightCol
                    result = leftCol->equals(rightCol);
                }
                else if(binCS->INEQUAL() != nullptr) { // leftCol <> rightCol
                    result = !leftCol->equals(rightCol);
                }
                else {
                    ctx->getErrorListener()->syntaxError("The possible binary operations between two collections are : =, <>");
                    return false;
                }
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                infExpr->setEType(type);
                boolValue->setValue(result);
                infEval->setResultValue(boolValue);
                return true;
            }
            else {
                ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left collection value must also be a collection");
                return false;
            }
        }
        else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(leftvalue) || std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(leftvalue) != nullptr) {
            int leftInt = retrieveInt(leftvalue);
            if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(rightvalue) || std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(rightvalue) != nullptr) {
                int rightInt = retrieveInt(rightvalue);
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = doOperation(binCS, leftInt, rightInt);
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                infExpr->setEType(type);
                infEval->setResultValue(boolValue);
                return true;
            }
            else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue)) {
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> rightReal = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue);
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = doOperation(binCS, leftInt, rightReal->getValue());
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                infExpr->setEType(type);
                infEval->setResultValue(boolValue);
                return true;
            }
            else {
                ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left integer value must be an integer, an unlimiteNatural, or a real");
            }
        }
        else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(leftvalue)) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> leftReal = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(leftvalue);
            if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(rightvalue) || std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(rightvalue) != nullptr) {
                int rightInt = retrieveInt(rightvalue);
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = doOperation(binCS, leftReal->getValue(), rightInt);
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                infExpr->setEType(type);
                infEval->setResultValue(boolValue);
                return true;
            }
            else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue)) {
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> rightReal = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue);
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = doOperation(binCS, leftReal->getValue(), rightReal->getValue());
                std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
                infExpr->setEType(type);
                infEval->setResultValue(boolValue);
                return true;
            }
            else {
                ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left real value must be an integer, an unlimiteNatural, or a real");
            }
        }
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitTupleTypeCS(OclParser::TupleTypeCSContext *ctx)
{
    std::shared_ptr<TupleType> tupleType = ocl::Types::TypesFactory::eInstance()->createTupleType();
    std::shared_ptr<TypeExp> typeAS = std::dynamic_pointer_cast<TypeExp>(ctx->getAST());
    std::shared_ptr<OclExpEval> typeEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOclExpEval();
    std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
    objValue->setValue(tupleType);
    typeEval->setResultValue(objValue);
    typeAS->setInstance(typeEval);
    typeAS->setReferredType(tupleType);
    typeAS->setEType(tupleType);

    if(ctx->variableDeclarationListCS() != nullptr) {
        OclParser::VariableDeclarationListCSContext *listDeclCS = ctx->variableDeclarationListCS();
        listDeclCS->setEnv(ctx->getEnv());
        listDeclCS->setErrorListener(ctx->getErrorListener());

        if(visitVariableDeclarationListCS(listDeclCS)) {
            std::shared_ptr<CollectionLiteralExp> collExp = std::dynamic_pointer_cast<CollectionLiteralExp>(listDeclCS->getAST());
            for(size_t i = 0; i < collExp->getPart()->size(); i++) {
                std::shared_ptr<CollectionItem> collItem = std::dynamic_pointer_cast<CollectionItem>(collExp->getPart()->at(i));
                std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(collItem->getItem());
                std::shared_ptr<NameTypeBinding> nameType = ocl::Types::TypesFactory::eInstance()->createNameTypeBinding();
                nameType->setName(varExp->getName());
                nameType->setType(varExp->getEType());
                tupleType->getParts()->add(nameType);
            }
            return true;
        }
        return false;
    }
    return true;
}
antlrcpp::Any OclParserCustomVisitor::visitVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext *ctx)
{
    OclParser::VariableDeclarationCSContext *varDeclCS = ctx->variableDeclarationCS();
    varDeclCS->setEnv(ctx->getEnv());
    varDeclCS->setErrorListener(ctx->getErrorListener());

    if(visitVariableDeclarationCS(varDeclCS)) {
        std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(varDeclCS->getAST());
        std::shared_ptr<CollectionLiteralExp> collExp = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionLiteralExp();
        std::shared_ptr<CollectionItem> collItem = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionItem();
        collItem->setItem(varExp);
        collExp->getPart()->add(collItem);

        if(ctx->variableDeclarationListCS() != nullptr) {
            OclParser::VariableDeclarationListCSContext *listDeclCS = ctx->variableDeclarationListCS();
            listDeclCS->setEnv(ctx->getEnv());
            listDeclCS->setErrorListener(ctx->getErrorListener());

            if(visitVariableDeclarationListCS(listDeclCS)) {
                std::shared_ptr<CollectionLiteralExp> innerColl = std::dynamic_pointer_cast<CollectionLiteralExp>(listDeclCS->getAST());
                for(size_t i = 0; i < innerColl->getPart()->size(); i++) {
                    collExp->getPart()->add(innerColl->getPart()->at(i));
                }
            }
        }

        ctx->setAST(collExp);
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx)
{
    OclParser::CollectionTypeIdentifierCSContext* collID = ctx->collectionTypeIdentifierCS();
    OclParser::TypeCSContext* typeCS = ctx->typeCS();

    typeCS->setEnv(ctx->getEnv());
    typeCS->setErrorListener(ctx->getErrorListener());

    if(visitTypeCS(typeCS)) {
        std::shared_ptr<TypeExp> typeAS = std::dynamic_pointer_cast<TypeExp>(ctx->getAST());
        std::shared_ptr<TypeExp> innerType = std::dynamic_pointer_cast<TypeExp>(typeCS->getAST());
        std::shared_ptr<CollectionType> collType = nullptr;

        if(collID->BAG() != nullptr) {
            collType = ocl::Types::TypesFactory::eInstance()->createBagType();
        }
        else if(collID->SET() != nullptr) {
            collType = ocl::Types::TypesFactory::eInstance()->createSetType();
        }
        else if(collID->ORDEREDSET() != nullptr) {
            collType = ocl::Types::TypesFactory::eInstance()->createOrderedSetType();
        }
        else if(collID->SEQUENCE() != nullptr) {
            collType = ocl::Types::TypesFactory::eInstance()->createSequenceType();
        }
        else {
            collType = ocl::Types::TypesFactory::eInstance()->createCollectionType();
        }
        collType->setElementType(innerType->getReferredType());
        std::shared_ptr<OclExpEval> typeEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOclExpEval();
        std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
        objValue->setValue(collType);
        typeEval->setResultValue(objValue);
        typeAS->setInstance(typeEval);
        typeAS->setReferredType(collType);
        typeAS->setEType(collType);
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx)
{
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();

    pathCS->setEnv(ctx->getEnv());
    pathCS->setErrorListener(ctx->getErrorListener());
    vector<std::string> seq = visitPathNameCS(pathCS).as<vector<std::string>>();
    std::shared_ptr<Variable> var = ctx->getEnv()->lookupPathName(seq);
    std::shared_ptr<uml::EnumerationLiteral> literal = nullptr;

    if(var != nullptr) {
        std::shared_ptr<ecore::EEnum> type = std::dynamic_pointer_cast<ecore::EEnum>(var->getEType());
        if(type != nullptr) {
            std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(var->getValue());
            std::shared_ptr<ecore::EEnum> en = std::dynamic_pointer_cast<ecore::EEnum>(objValue->getValue());
            std::shared_ptr<Bag<ecore::EEnumLiteral>> literals = en->getELiterals();
            for (size_t i = 0; i < literals->size(); i++) {
                if(literals->at(i)->getName() == simpleName) {
                    std::shared_ptr<uml::EnumerationLiteral> new_literal = uml::umlFactory::eInstance()->createEnumerationLiteral();
                    new_literal->setName(literals->at(i)->getName());
                    literal = new_literal;
                    break;
                }
            }
        }
        else if (var->getEType()->getClassifierID() == uml::umlPackage::ENUMERATION_CLASS) {
            std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(var->getValue());
            std::shared_ptr<uml::Enumeration> en = std::dynamic_pointer_cast<uml::Enumeration>(objValue->getValue());
            std::shared_ptr<Bag<uml::EnumerationLiteral>> literals = en->getOwnedLiteral();

            for (size_t i = 0; i < literals->size(); i++) {
                if(literals->at(i)->getName() == simpleName) {
                    literal = literals->at(i);
                    break;
                }
            }
        }
    }

    if(literal != nullptr) {
        std::shared_ptr<EnumLiteralExp> enumExp = ocl::Expressions::ExpressionsFactory::eInstance()->createEnumLiteralExp();
        std::shared_ptr<EnumLiteralExpEval> enumEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createEnumLiteralExpEval();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue();

        value->setLiteral(literal);
        enumEval->setResultValue(value);
        enumEval->setModel(enumExp);
        enumExp->setReferredEnumLiteral(literal);
        enumExp->setInstance(enumEval);
        enumExp->setEType(var->getEType());
        ctx->setAST(enumExp);
        return true;
    }

    ctx->getErrorListener()->syntaxError("Unknown enum literal ("+ simpleName +")");
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx)
{
    OclParser::CollectionTypeIdentifierCSContext* collTypeCS = ctx->collectionTypeIdentifierCS();
    OclParser::CollectionLiteralPartsCSContext* collPartsCS = ctx->collectionLiteralPartsCS();
    std::shared_ptr<CollectionLiteralExp> collExp = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionLiteralExp();

    ctx->setAST(collExp);

    if(collPartsCS != nullptr) {
        collPartsCS->setAST(collExp);
        collPartsCS->setEnv(ctx->getEnv());
        collPartsCS->setErrorListener(ctx->getErrorListener());
        if(!visitCollectionLiteralPartsCS(collPartsCS)) {
            return false;
        }
    }
    std::shared_ptr<CollectionLiteralExpEval> collEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createCollectionLiteralExpEval();
    std::shared_ptr<CollectionType> type = nullptr;
    std::shared_ptr<CollectionValue> value = nullptr;
    if(collTypeCS->SET() != nullptr) {
        std::shared_ptr<SetTypeValue> setValue = ocl::Values::ValuesFactory::eInstance()->createSetTypeValue();
        std::shared_ptr<SetType> setType = ocl::Types::TypesFactory::eInstance()->createSetType();
        setValue->setModel(setType);
        collExp->setKind(CollectionKind::SET);
        value = setValue;
        type = setType;
    }
    else if(collTypeCS->ORDEREDSET() != nullptr) {
        std::shared_ptr<OrderedSetTypeValue> ordSetValue = ocl::Values::ValuesFactory::eInstance()->createOrderedSetTypeValue();
        std::shared_ptr<OrderedSetType> ordSetType = ocl::Types::TypesFactory::eInstance()->createOrderedSetType();
        ordSetValue->setModel(ordSetType);
        collExp->setKind(CollectionKind::ORDEREDSET);
        value = ordSetValue;
        type = ordSetType;
    }
    else if(collTypeCS->SEQUENCE() != nullptr) {
        std::shared_ptr<SequenceTypeValue> seqValue = ocl::Values::ValuesFactory::eInstance()->createSequenceTypeValue();
        std::shared_ptr<SequenceType> seqType = ocl::Types::TypesFactory::eInstance()->createSequenceType();
        seqValue->setModel(seqType);
        collExp->setKind(CollectionKind::SEQUENCE);
        value = seqValue;
        type = seqType;
    }
    else {
        std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
        std::shared_ptr<BagType> bagType = ocl::Types::TypesFactory::eInstance()->createBagType();
        bagValue->setModel(bagType);
        collExp->setKind(CollectionKind::BAG);
        value = bagValue;
        type = bagType;
    }

    collEval->setResultValue(value);
    collExp->setEType(type);
    collExp->setInstance(collEval);

    std::shared_ptr<ecore::EClassifier> itemType = type->getElementType();

    for(size_t i = 0; i < collExp->getPart()->size(); i++) {
        std::shared_ptr<CollectionLiteralPart> part = collExp->getPart()->at(i);

        if(std::dynamic_pointer_cast<CollectionItem>(part) != nullptr) {
            std::shared_ptr<CollectionItem> item = std::dynamic_pointer_cast<CollectionItem>(part);
            value->addValue(item->getItem()->getInstance()->getResultValue());

            if(itemType != nullptr) {
                if(!itemType->eClass()->isSuperTypeOf(item->getItem()->getEType()->eClass()) &&
                        itemType->getClassifierID() == item->getItem()->getEType()->getClassifierID()) {
                    ctx->getErrorListener()->syntaxError("The elements types and collection type must be compatible");
                    return false;
                }
            }
            else {
                itemType = item->getItem()->getEType();
            }
        }
        else { // collectionRange
            std::shared_ptr<CollectionRange> range = std::dynamic_pointer_cast<CollectionRange>(part);
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> firstVal =
                    std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(range->getFirst()->getInstance()->getResultValue());
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> lastVal =
                    std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(range->getLast()->getInstance()->getResultValue());
            /*std::shared_ptr<IntegerLiteralExp> firstExp = std::dynamic_pointer_cast<IntegerLiteralExp>(range->getFirst());
            std::shared_ptr<IntegerLiteralExp> lastExp = std::dynamic_pointer_cast<IntegerLiteralExp>(range->getLast());

            for (int i = firstExp->getIntegerSymbol(); i <= lastExp->getIntegerSymbol(); i++) {
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
                intValue->setValue(i);
                value->addValue(intValue);
            }*/

            for (int i = firstVal->getValue(); i <= lastVal->getValue(); i++) {
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
                intValue->setValue(i);
                value->addValue(intValue);
            }
        }
    }

    if(type->getElementType() == nullptr) {
        type->setElementType(itemType);
    }
    return true;
}

antlrcpp::Any OclParserCustomVisitor::visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx)
{
    OclParser::VariableDeclarationListCSContext* varDeclListCS = ctx->variableDeclarationListCS();

    varDeclListCS->setEnv(ctx->getEnv());
    varDeclListCS->setErrorListener(ctx->getErrorListener());

    if(visitVariableDeclarationListCS(varDeclListCS)) {
        std::shared_ptr<TupleLiteralExp> tupleExp = ocl::Expressions::ExpressionsFactory::eInstance()->createTupleLiteralExp();
        std::shared_ptr<TupleLiteralExpEval> tupleEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createTupleLiteralExpEval();
        std::shared_ptr<TupleType> tupleType = ocl::Types::TypesFactory::eInstance()->createTupleType();
        std::shared_ptr<TupleValue> tupleValue = ocl::Values::ValuesFactory::eInstance()->createTupleValue();
        std::shared_ptr<CollectionLiteralExp> collExp = std::dynamic_pointer_cast<CollectionLiteralExp>(varDeclListCS->getAST());

        tupleEval->setResultValue(tupleValue);
        tupleExp->setInstance(tupleEval);
        tupleExp->setEType(tupleType);
        tupleValue->setModel(tupleType);
        tupleType->setInstance(tupleValue);
        ctx->setAST(tupleExp);

        for(size_t i = 0; i < collExp->getPart()->size(); i++) {
            std::shared_ptr<CollectionItem> collItem = std::dynamic_pointer_cast<CollectionItem>(collExp->getPart()->at(i));
            std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(collItem->getItem());
            std::shared_ptr<TupleLiteralPart> part = ocl::Expressions::ExpressionsFactory::eInstance()->createTupleLiteralPart();
            std::shared_ptr<NameTypeBinding> nameType = ocl::Types::TypesFactory::eInstance()->createNameTypeBinding();
            std::shared_ptr<NameValueBinding> nameValue = ocl::Values::ValuesFactory::eInstance()->createNameValueBinding();
            std::shared_ptr<ecore::EAttribute> attr = ecore::ecoreFactory::eInstance()->createEAttribute();

            attr->setName(varExp->getName());
            nameType->setName(varExp->getName());
            nameValue->setName(varExp->getName());
            attr->setEType(varExp->getEType());
            nameType->setType(varExp->getEType());
            nameValue->setValue(varExp->getInstance()->getResultValue());

            part->setAttribute(attr);

            tupleType->getParts()->add(nameType);
            tupleValue->getElements()->add(nameValue);
            tupleExp->getPart()->add(part);
        }
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx)
{
    OclParser::IntegerLiteralExpCSContext* intCS = ctx->integerLiteralExpCS();
    OclParser::RealLiteralExpCSContext* realCS = ctx->realLiteralExpCS();
    OclParser::StringLiteralExpCSContext* stringCS = ctx->stringLiteralExpCS();
    OclParser::BooleanLiteralExpCSContext* boolCS = ctx->booleanLiteralExpCS();
    OclParser::NullLiteralExpCSContext* nullCS = ctx->nullLiteralExpCS();
    OclParser::UnlimitedNaturalLiteralExpCSContext* unlimitedCS = ctx->unlimitedNaturalLiteralExpCS();

    if(intCS != nullptr) {
        std::shared_ptr<IntegerLiteralExp> intExp = ocl::Expressions::ExpressionsFactory::eInstance()->createIntegerLiteralExp();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
        std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getInteger_Class();
        std::shared_ptr<IntegerLiteralExpEval> intEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createIntegerLiteralExpEval();
        int symbol = std::atoi(intCS->INT()->getSymbol()->getText().c_str());

        intValue->setValue(symbol);
        intEval->setResultValue(intValue);
        intExp->setIntegerSymbol(symbol);
        intExp->setEType(type);
        intExp->setInstance(intEval);
        ctx->setAST(intExp);
    }
    else if(unlimitedCS != nullptr) {
        std::shared_ptr<UnlimitedNaturalExp> unlExp = ocl::Expressions::ExpressionsFactory::eInstance()->createUnlimitedNaturalExp();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> unlValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createUnlimitedNaturalValue();
        std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getUnlimitedNatural_Class();
        std::shared_ptr<UnlimitedNaturalLiteralExpEval> unEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createUnlimitedNaturalLiteralExpEval();
        int symbol = std::atoi(unlimitedCS->INT()->getSymbol()->getText().c_str());

        unlValue->setValue(symbol);
        unEval->setResultValue(unlValue);
        unlExp->setUnlimitedNaturalSymbol(symbol);
        unlExp->setEType(type);
        unlExp->setInstance(unEval);
        ctx->setAST(unlExp);
    }
    else if(realCS != nullptr) {
        std::shared_ptr<RealLiteralExp> realExp = ocl::Expressions::ExpressionsFactory::eInstance()->createRealLiteralExp();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
        std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getReal_Class();
        std::shared_ptr<RealLiteralExpEval> realEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createRealLiteralExpEval();
        double symbol = std::atof(realCS->REAL()->getSymbol()->getText().c_str());

        realValue->setValue(symbol);
        realEval->setResultValue(realValue);
        realExp->setRealSymbol(symbol);
        realExp->setEType(type);
        realExp->setInstance(realEval);
        ctx->setAST(realExp);
    }
    else if(stringCS != nullptr) {
        std::shared_ptr<StringLiteralExp> stringExp = ocl::Expressions::ExpressionsFactory::eInstance()->createStringLiteralExp();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
        std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getString_Class();
        std::shared_ptr<StringLiteralExpEval> stringEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createStringLiteralExpEval();
        string symbol = stringCS->STRING_LITERAL()->getSymbol()->getText();

        stringValue->setValue(symbol);
        stringEval->setResultValue(stringValue);
        stringExp->setSymbol(symbol);
        stringExp->setEType(type);
        stringExp->setInstance(stringEval);
        ctx->setAST(stringExp);
    }
    else if(boolCS != nullptr) {
        bool symbol = (boolCS->BOOL()->getSymbol()->getText() == "true") ? true : false;
        std::shared_ptr<BooleanLiteralExp> boolExp = createBooleanLiteralExp(symbol);
        ctx->setAST(boolExp);
    }
    else if(nullCS != nullptr) {
        std::shared_ptr<NullLiteralExp> nullExp = ocl::Expressions::ExpressionsFactory::eInstance()->createNullLiteralExp();
        std::shared_ptr<VoidType> type = ocl::Types::TypesFactory::eInstance()->createVoidType();
        std::shared_ptr<StringLiteralExpEval> stringEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createStringLiteralExpEval();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();

        stringValue->setValue("Null");
        stringEval->setResultValue(stringValue);
        nullExp->setInstance(stringEval);
        nullExp->setEType(type);
        ctx->setAST(nullExp);
    }
    else { // invalid expression
        std::shared_ptr<InvalidLiteralExp> invExp = ocl::Expressions::ExpressionsFactory::eInstance()->createInvalidLiteralExp();
        std::shared_ptr<InvalidType> type = ocl::Types::TypesFactory::eInstance()->createInvalidType();
        std::shared_ptr<StringLiteralExpEval> stringEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createStringLiteralExpEval();
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();

        stringValue->setValue("Invalid");
        stringEval->setResultValue(stringValue);
        invExp->setInstance(stringEval);
        invExp->setEType(type);
        ctx->setAST(invExp);
    }
    return true;
}

antlrcpp::Any OclParserCustomVisitor::visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx)
{
    OclParser::CollectionLiteralPartCSContext* collPart = ctx->collectionLiteralPartCS();

    collPart->setAST(ctx->getAST());
    collPart->setEnv(ctx->getEnv());
    collPart->setErrorListener(ctx->getErrorListener());

    if(visitCollectionLiteralPartCS(collPart)) {
        if(ctx->collectionLiteralPartsCS() != nullptr) {
            OclParser::CollectionLiteralPartsCSContext* collPartsCS = ctx->collectionLiteralPartsCS();

            collPartsCS->setAST(ctx->getAST());
            collPartsCS->setEnv(ctx->getEnv());
            collPartsCS->setErrorListener(ctx->getErrorListener());

            return visitCollectionLiteralPartsCS(collPartsCS);
        }
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext *ctx)
{
    OclParser::CollectionRangeCSContext* collRangeCS = ctx->collectionRangeCS();
    OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();
    std::shared_ptr<CollectionLiteralExp> collExp = std::dynamic_pointer_cast<CollectionLiteralExp>(ctx->getAST());

    if(collRangeCS != nullptr) {
        OclParser::OclExpressionCSContext* oclExp1 = collRangeCS->oclExpressionCS(0);
        OclParser::OclExpressionCSContext* oclExp2 = collRangeCS->oclExpressionCS(1);

        oclExp1->setEnv(ctx->getEnv());
        oclExp2->setEnv(ctx->getEnv());
        oclExp1->setErrorListener(ctx->getErrorListener());
        oclExp2->setErrorListener(ctx->getErrorListener());

        if(visitOclExpressionCS(oclExp1) && visitOclExpressionCS(oclExp2)) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> firstVal =
                    std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(oclExp1->getAST()->getInstance()->getResultValue());
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> lastVal =
                    std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(oclExp2->getAST()->getInstance()->getResultValue());
            //std::shared_ptr<IntegerLiteralExp> intExp1 = std::dynamic_pointer_cast<IntegerLiteralExp>(oclExp1->getAST());
            //std::shared_ptr<IntegerLiteralExp> intExp2 = std::dynamic_pointer_cast<IntegerLiteralExp>(oclExp2->getAST());

            if(firstVal != nullptr && lastVal != nullptr) {
                if(firstVal->getValue() <= lastVal->getValue()) {
                    std::shared_ptr<CollectionRange> collRange = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionRange();
                    collRange->setFirst(oclExp1->getAST());
                    collRange->setLast(oclExp2->getAST());
                    collRange->setEType(oclExp1->getAST()->getEType());
                    collExp->getPart()->add(collRange);
                    return true;
                }
                else {
                    ctx->getErrorListener()->syntaxError("The first integer of the collection range must be smaller than the last one");
                }
            }
            else {
                ctx->getErrorListener()->syntaxError("The first and last elements of the collection range must be integer");
            }
        }
    }
    else if(oclExpCS != nullptr) {
        oclExpCS->setEnv(ctx->getEnv());
        oclExpCS->setErrorListener(ctx->getErrorListener());

        if(visitOclExpressionCS(oclExpCS)) {
            std::shared_ptr<CollectionItem> collItem = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionItem();
            collItem->setItem(oclExpCS->getAST());
            collExp->getPart()->add(collItem);
            return true;
        }
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitIteratorExpCS(OclParser::IteratorExpCSContext *ctx)
{
    /*
    OclParser::VariableDeclarationCSContext* var1CS = ctx->variableDeclarationCS(0);
    OclParser::VariableDeclarationCSContext* var2CS = ctx->variableDeclarationCS(1);
    OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();
    std::shared_ptr<IteratorExp> iterExp = std::dynamic_pointer_cast<IteratorExp>(ctx->getAST());
    std::shared_ptr<Variable> iterator = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
    std::shared_ptr<CollectionLiteralExp> collExp = std::dynamic_pointer_cast<CollectionLiteralExp>(iterExp->getSource());
    iterExp->setName(ctx->simpleNameCS()->ID()->getSymbol()->getText());

    if(oclExpCS != nullptr) { // case A
        if(var1CS != nullptr) {
            var1CS->setEnv(ctx->getEnv());
            var1CS->setErrorListener(ctx->getErrorListener());
            if(!visitVariableDeclarationCS(var1CS)) {
                return false;
            }
            std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(var1CS->getAST());
            iterator = varExp->getReferredVariable();
        }
        else {
            iterator->setName("");
            iterator->setEType(collExp->getEType());
        }
        var2CS->setEnv(ctx->getEnv());
        var2CS->setErrorListener(ctx->getErrorListener());
        if(!visitVariableDeclarationCS(var2CS)) {
            return false;
        }
        if(collExp->getEType()->eClass()->isSuperTypeOf(iterator->getEType()->eClass()) ||
                collExp->getEType()->getClassifierID() == iterator->getEType()->getClassifierID()) {
            std::shared_ptr<Environment> env = EnvironmentFactory::getInstance().createEnvironment(ctx->getEnv());
            std::shared_ptr<VariableExp> var2Expr = std::dynamic_pointer_cast<VariableExp>(var2CS->getAST());
            std::shared_ptr<Variable> iterator2 = var2Expr->getReferredVariable();

            env->addElement(iterator->getName(), iterator, true);
            env->addElement(iterator2->getName(), iterator2, true);
            oclExpCS->setEnv(env);
            oclExpCS->setErrorListener(ctx->getErrorListener());

            for(size_t i = 0; i < collExp->getPart()->size(); i++) {
                std::shared_ptr<CollectionLiteralPart> part = collExp->getPart()->at(i);

                if(OclReflection::instanceOf<CollectionItem>(part)) {
                    std::shared_ptr<CollectionItem> item = std::dynamic_pointer_cast<CollectionItem>(part);
                    iterator->setValue(item->getItem()->getInstance()->getResultValue());
                    if(!visitOclExpressionCS(oclExpCS)){
                        return false;
                    }
                    std::shared_ptr<OclExpression> oclExpAS = oclExpCS->getAST();

                    if(oclExpAS->getEType()->getClassifierID() == resultExp->getEType()->getClassifierID()) {
                        result->setValue(oclExpAS->getInstance()->getResultValue());
                        iterExp->setBody(oclExpAS);
                    }
                    else {
                        ctx->getErrorListener()->syntaxError("The result type is different from the declaration");
                        return false;
                    }
                }
                else { // collectionRange
                    std::shared_ptr<CollectionRange> range = std::dynamic_pointer_cast<CollectionRange>(part);
                    std::shared_ptr<IntegerLiteralExp> firstExp = std::dynamic_pointer_cast<IntegerLiteralExp>(range->getFirst());
                    std::shared_ptr<IntegerLiteralExp> lastExp = std::dynamic_pointer_cast<IntegerLiteralExp>(range->getLast());
                    int i = firstExp->getIntegerSymbol();
                    while (i < lastExp->getIntegerSymbol()) {
                        std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
                        intValue->setValue(i);
                        iterator->setValue(intValue);
                        if(!visitOclExpressionCS(oclExpCS)){
                            return false;
                        }
                        std::shared_ptr<OclExpression> oclExpAS = oclExpCS->getAST();

                        if(oclExpAS->getEType()->getClassifierID() == resultExp->getEType()->getClassifierID()) {
                            result->setValue(oclExpAS->getInstance()->getResultValue());
                            iterExp->setBody(oclExpAS);
                            i++;
                        }
                        else {
                            ctx->getErrorListener()->syntaxError("The result type is different from the declaration");
                            return false;
                        }
                    }
                }
            }
            //iterExp->setResult(result);
            iterExp->getInstance()->setResultValue(result->getValue());
    }

    */
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitIterateExpCS(OclParser::IterateExpCSContext *ctx)
{
    OclParser::VariableDeclarationCSContext* var1CS = ctx->variableDeclarationCS(0);
    OclParser::VariableDeclarationCSContext* var2CS = ctx->variableDeclarationCS(1);
    OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();
    std::shared_ptr<IterateExp> iterExp = std::dynamic_pointer_cast<IterateExp>(ctx->getAST());
    std::shared_ptr<IterateExpEval> iterEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createIterateExpEval();
    std::shared_ptr<Variable> iterator = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
    std::shared_ptr<CollectionLiteralExp> collExp = std::dynamic_pointer_cast<CollectionLiteralExp>(iterExp->getSource());

    if(collExp != nullptr) {
        if(var1CS != nullptr && var2CS != nullptr) {
            var1CS->setEnv(ctx->getEnv());
            var1CS->setErrorListener(ctx->getErrorListener());
            if(!visitVariableDeclarationCS(var1CS)) {
                return false;
            }
            std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(var1CS->getAST());
            iterator = varExp->getReferredVariable();
        }
        else {
            iterator->setName("");
            iterator->setEType(collExp->getEType());
        }
        if(var2CS != nullptr) {
            var2CS->setEnv(ctx->getEnv());
            var2CS->setErrorListener(ctx->getErrorListener());
            if(!visitVariableDeclarationCS(var2CS)) {
                return false;
            }
        }
        else {
            var2CS = var1CS;
            var2CS->setEnv(ctx->getEnv());
            var2CS->setErrorListener(ctx->getErrorListener());
            if(!visitVariableDeclarationCS(var2CS)) {
                return false;
            }
        }

        iterExp->setInstance(iterEval);
        std::shared_ptr<CollectionType> collType = std::dynamic_pointer_cast<CollectionType>(collExp->getEType());
        std::shared_ptr<ecore::EClassifier> itemType = collType->getElementType();

        if(itemType->eClass()->isSuperTypeOf(iterator->getEType()->eClass()) ||
                itemType->getClassifierID() == iterator->getEType()->getClassifierID()) {
            std::shared_ptr<Environment> env = EnvironmentFactory::getInstance().createEnvironment(ctx->getEnv());
            std::shared_ptr<CollectionValue> collValue = std::dynamic_pointer_cast<CollectionValue>(collExp->getInstance()->getResultValue());
            std::shared_ptr<VariableExp> resultExp = std::dynamic_pointer_cast<VariableExp>(var2CS->getAST());
            std::shared_ptr<Variable> result = resultExp->getReferredVariable();

            env->addElement(iterator->getName(), iterator, true);
            env->addElement(result->getName(), result, true);
            oclExpCS->setEnv(env);
            oclExpCS->setErrorListener(ctx->getErrorListener());

            for(size_t i = 0; i < collValue->getElements()->size(); i++) {
                std::shared_ptr<Element> elem = collValue->getElements()->at(i);
                iterator->setValue(elem->getValue());
                if(!visitOclExpressionCS(oclExpCS)){
                    return false;
                }
                std::shared_ptr<OclExpression> oclExpAS = oclExpCS->getAST();

                if(oclExpAS->getEType()->getClassifierID() == resultExp->getEType()->getClassifierID()) {
                    result->setValue(oclExpAS->getInstance()->getResultValue());
                    iterExp->setBody(oclExpAS);
                }
                else {
                    ctx->getErrorListener()->syntaxError("The result type is different from the declaration");
                    return false;
                }
            }
            iterExp->setResult(result);
            iterExp->getInstance()->setResultValue(result->getValue());
            return true;
        }
        else {
            ctx->getErrorListener()->syntaxError("The iterator type must be compatible with the collection type");
        }
    }
    else {
        ctx->getErrorListener()->syntaxError("The source of the (iterate) operation must be a collection literal");
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitIfExpCS(OclParser::IfExpCSContext *ctx)
{
    OclParser::OclExpressionCSContext* ifExprCS = ctx->oclExpressionCS(0);
    OclParser::OclExpressionCSContext* thenExprCS = ctx->oclExpressionCS(1);
    OclParser::OclExpressionCSContext* elseExprCS = ctx->oclExpressionCS(2);

    ifExprCS->setEnv(ctx->getEnv());
    thenExprCS->setEnv(ctx->getEnv());
    elseExprCS->setEnv(ctx->getEnv());
    ifExprCS->setErrorListener(ctx->getErrorListener());
    thenExprCS->setErrorListener(ctx->getErrorListener());
    elseExprCS->setErrorListener(ctx->getErrorListener());

    if(visitOclExpressionCS(ifExprCS)) {
        std::shared_ptr<OclExpression> ifExpr = ifExprCS->getAST();
        if(ifExpr->getEType()->getClassifierID() == ::types::typesPackage::BOOLEAN_CLASS) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(ifExpr->getInstance()->getResultValue());
            if(value->isValue()) {
                if(visitOclExpressionCS(thenExprCS)) {
                    ctx->setAST(thenExprCS->getAST());
                    return true;
                }
            }
            else if(visitOclExpressionCS(elseExprCS)) {
                ctx->setAST(elseExprCS->getAST());
                return true;
            }
        }
        else {
            ctx->getErrorListener()->syntaxError("The condition of the If expression must return a boolean");
        }
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitParametersCS(OclParser::ParametersCSContext *ctx)
{
    OclParser::VariableDeclarationCSContext *varDeclCS = ctx->variableDeclarationCS();
    varDeclCS->setEnv(ctx->getEnv());
    varDeclCS->setErrorListener(ctx->getErrorListener());

    if(visitVariableDeclarationCS(varDeclCS)) {
        std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(varDeclCS->getAST());
        std::shared_ptr<CollectionLiteralExp> collExp = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionLiteralExp();
        std::shared_ptr<CollectionItem> collItem = ocl::Expressions::ExpressionsFactory::eInstance()->createCollectionItem();
        collItem->setItem(varExp);
        collExp->getPart()->add(collItem);

        if(ctx->parametersCS() != nullptr) {
            OclParser::ParametersCSContext* paramCS = ctx->parametersCS();
            paramCS->setEnv(ctx->getEnv());
            paramCS->setErrorListener(ctx->getErrorListener());

            if(visitParametersCS(paramCS)) {
                std::shared_ptr<CollectionLiteralExp> innerColl = std::dynamic_pointer_cast<CollectionLiteralExp>(paramCS->getAST());
                for(size_t i = 0; i < innerColl->getPart()->size(); i++) {
                    collExp->getPart()->add(innerColl->getPart()->at(i));
                }
            }
        }

        ctx->setAST(collExp);
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx)
{
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();

    if(pathCS != nullptr) {
        pathCS->setEnv(ctx->getEnv());
        pathCS->setErrorListener(ctx->getErrorListener());
        vector<std::string> seq = visitPathNameCS(pathCS).as<vector<std::string>>();
        std::shared_ptr<Variable> var = ctx->getEnv()->lookupPathName(seq);

        if(var != nullptr) {
            ctx->getEnv()->addElement(var->getName(), var, true);
            if(ctx->contextDeclarationCS().size() > 0) {
                std::shared_ptr<OclExpression> resultExp = nullptr;
                for(OclParser::ContextDeclarationCSContext* contextCS : ctx->contextDeclarationCS()) {
                    contextCS->setEnv(ctx->getEnv());
                    contextCS->setErrorListener(ctx->getErrorListener());
                    if(visitContextDeclarationCS(contextCS)) {
                        resultExp = contextCS->getAST();
                    }
                    else{
                        return false;
                    }
                }
                ctx->setAST(resultExp);
                return true;
            }
            else {
                ctx->setAST(createVariableExp(var));
            }
        }
        else {
            std::string path = getPath(seq);
            ctx->getErrorListener()->syntaxError("The path ("+ path +") cannot be found");
        }
    }
    else {
        std::shared_ptr<OclExpression> resultExp = nullptr;
        for(OclParser::ContextDeclarationCSContext* contextCS : ctx->contextDeclarationCS()) {
            contextCS->setEnv(ctx->getEnv());
            contextCS->setErrorListener(ctx->getErrorListener());
            if(visitContextDeclarationCS(contextCS)) {
                resultExp = contextCS->getAST();
            }
            else{
                return false;
            }
        }
        ctx->setAST(resultExp);
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx)
{
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();
    OclParser::SimpleNameCSContext* simpleNameCS = ctx->simpleNameCS();
    OclParser::TypeCSContext* typeCS = ctx->typeCS();
    OclParser::InitOrDerValueCSContext* initDerCS = ctx->initOrDerValueCS();

    pathCS->setEnv(ctx->getEnv());
    pathCS->setErrorListener(ctx->getErrorListener());
    vector<std::string> seq = visitPathNameCS(pathCS).as<vector<std::string>>();
    std::shared_ptr<Variable> var = ctx->getEnv()->lookupPathName(seq);

    if(var != nullptr) {
        std::shared_ptr<Environment> env = ctx->getEnv();
        std::string simpleName = simpleNameCS->ID()->getSymbol()->getText();

        std::shared_ptr<ecore::EClass> eClass = std::dynamic_pointer_cast<ecore::EClass>(var->getEType());
        std::shared_ptr<ecore::EAttribute> eatt = nullptr;
        std::shared_ptr<ecore::EReference> eref = nullptr;
        std::shared_ptr<ecore::EStructuralFeature> feature = nullptr;

        if((eatt = OclReflection::lookupProperty(eClass, simpleName)) != nullptr) {
            feature = eatt;
        }
        else if((eref = OclReflection::lookupAssociationClass(eClass, simpleName)) != nullptr) {
            feature = eref;
        }

        if(feature != nullptr) {
            typeCS->setEnv(env);
            typeCS->setErrorListener(ctx->getErrorListener());
            if(visitTypeCS(typeCS)) {
                std::shared_ptr<TypeExp> typeExp = std::dynamic_pointer_cast<TypeExp>(typeCS->getAST());
                initDerCS->setEnv(env);
                initDerCS->setErrorListener(ctx->getErrorListener());
                if(visitInitOrDerValueCS(initDerCS)) {
                    std::shared_ptr<OclExpression> oclExp = initDerCS->getAST();
                    if(OclReflection::kindOf(oclExp->getEType(), typeExp->getReferredType())) {
                        std::shared_ptr<fUML::Semantics::Values::Value> value = nullptr;
                        std::shared_ptr<fUML::Semantics::Values::Value> resultValue = oclExp->getInstance()->getResultValue();

                        if(initDerCS->INIT() != nullptr) {
                            std::shared_ptr<AnyObject> any = feature->getDefaultValue();
                            value = OclReflection::createValue(feature, any);
                            std::shared_ptr<BooleanLiteralExp> boolExp = createBooleanLiteralExp(resultValue->equals(value));
                            ctx->setAST(boolExp);
                            return true;
                        }
                        else {
                            std::shared_ptr<ObjectValue> new_value = std::dynamic_pointer_cast<ObjectValue>(var->getValue());
                            std::shared_ptr<ecore::EObject> new_object  = new_value->getValue();

                            if(new_object != nullptr) {
                                value = OclReflection::createValue(feature, new_value, initDerCS->getEnv()->getLevel());
                                std::shared_ptr<BooleanLiteralExp> boolExp = createBooleanLiteralExp(resultValue->equals(value));
                                ctx->setAST(boolExp);
                                return true;
                            }
                            else {
                                ctx->getErrorListener()->syntaxError("The entered context value is not a valid object");
                            }
                        }
                    }
                    else {
                        ctx->getErrorListener()->syntaxError("The declared type must be conform to the init/derived result type");
                    }
                }
            }
        }
        else {
            ctx->getErrorListener()->syntaxError("Unrecognized variable: ("+ simpleName +")");
        }
    }
    else {
        std::string path = getPath(seq);
        ctx->getErrorListener()->syntaxError("The path ("+ path +") cannot be found");
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx)
{
    OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();
    oclExpCS->setEnv(ctx->getEnv());
    oclExpCS->setErrorListener(ctx->getErrorListener());

    if(visitOclExpressionCS(oclExpCS)) {
        ctx->setAST(oclExpCS->getAST());
        return true;
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx)
{
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();
    OclParser::SimpleNameCSContext* simpleNameCS = ctx->simpleNameCS();
    OclParser::InvOrDefCSContext* invDefCS = ctx->invOrDefCS();

    pathCS->setEnv(ctx->getEnv());
    pathCS->setErrorListener(ctx->getErrorListener());
    vector<std::string> seq = visitPathNameCS(pathCS).as<vector<std::string>>();
    std::shared_ptr<Variable> var = ctx->getEnv()->lookupPathName(seq);

    if(var != nullptr) {
        if(simpleNameCS != nullptr) {
            std::string simpleName = simpleNameCS->ID()->getSymbol()->getText();
            ctx->getEnv()->addElement(simpleName, var, false);
        }

        invDefCS->setEnv(ctx->getEnv());
        invDefCS->setErrorListener(ctx->getErrorListener());
        if(visitInvOrDefCS(invDefCS)) {
            ctx->setAST(invDefCS->getAST());
            return true;
        }
    }
    else {
        std::string path = getPath(seq);
        ctx->getErrorListener()->syntaxError("The path ("+ path +") cannot be found");
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitInvOrDefCS(OclParser::InvOrDefCSContext *ctx)
{
    if(ctx->INV() != nullptr) { // invariant
        OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();
        oclExpCS->setEnv(ctx->getEnv());
        oclExpCS->setErrorListener(ctx->getErrorListener());

        return visitForBoolExp(ctx, oclExpCS, ctx->simpleNameCS());
    }
    else { // define
        if(ctx->defExpressionCS()->variableDeclarationCS() != nullptr) {
            OclParser::VariableDeclarationCSContext* varDeclCS = ctx->defExpressionCS()->variableDeclarationCS();
            OclParser::OclExpressionCSContext* oclExpCS = ctx->defExpressionCS()->oclExpressionCS();

            varDeclCS->setEnv(ctx->getEnv());
            oclExpCS->setEnv(ctx->getEnv());
            varDeclCS->setErrorListener(ctx->getErrorListener());
            oclExpCS->setErrorListener(ctx->getErrorListener());

            if(visitVariableDeclarationCS(varDeclCS) && visitOclExpressionCS(oclExpCS)) {
                std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(varDeclCS->getAST());
                std::shared_ptr<Variable> var = varExp->getReferredVariable();

                if(ctx->simpleNameCS() != nullptr) {
                    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
                    var->setName(simpleName);
                }
                varExp->getInstance()->setResultValue(oclExpCS->getAST()->getInstance()->getResultValue());
                var->setValue(oclExpCS->getAST()->getInstance()->getResultValue());
                var->setInitExpression(oclExpCS->getAST());
                ctx->getEnv()->addElement(var->getName(), var, false);
                ctx->setAST(varExp);
                return true;
            }
        }
        else {
            OclParser::OperationCSContext* opeCS = ctx->defExpressionCS()->operationCS();
            OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();

            opeCS->setEnv(ctx->getEnv());
            oclExpCS->setEnv(ctx->getEnv());
            opeCS->setErrorListener(ctx->getErrorListener());
            oclExpCS->setErrorListener(ctx->getErrorListener());

            if(visitOperationCS(opeCS) && visitOclExpressionCS(oclExpCS)) {
                std::shared_ptr<OperationCallExp> opeExp = std::dynamic_pointer_cast<OperationCallExp>(opeCS->getAST());
                std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();

                if(ctx->simpleNameCS() != nullptr) {
                    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
                    var->setName(simpleName);
                }
                var->setEType(opeExp->getReferredOperation()->eClass());
                var->setValue(oclExpCS->getAST()->getInstance()->getResultValue());
                var->setInitExpression(oclExpCS->getAST());
                ctx->getEnv()->getRootEnv()->addElement(var->getName(), var, false);
                ctx->setAST(opeExp);
                return true;
            }
        }
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitOperationCS(OclParser::OperationCSContext *ctx)
{
    OclParser::PathNameCSContext* pathCS = ctx->pathNameCS();
    std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
    OclParser::TypeCSContext* typeCS = ctx->typeCS();
    OclParser::ParametersCSContext* paramCS = ctx->parametersCS();
    std::shared_ptr<Variable> var = nullptr;

    if(pathCS != nullptr) {
        pathCS->setEnv(ctx->getEnv());
        pathCS->setErrorListener(ctx->getErrorListener());
        vector<std::string> seq = visitPathNameCS(pathCS).as<vector<std::string>>();
        var = ctx->getEnv()->lookupPathName(seq);
    }
    else {
        var = ctx->getEnv()->getSelfVariable();
    }

    if(var != nullptr) {
        std::shared_ptr<OperationCallExp> exp = ocl::Expressions::ExpressionsFactory::eInstance()->createOperationCallExp();
        std::shared_ptr<ecore::EClass> eClass = std::dynamic_pointer_cast<ecore::EClass>(var->getEType());
        exp->setSource(createVariableExp(var));

        if(paramCS != nullptr) {
            paramCS->setEnv(ctx->getEnv());
            paramCS->setErrorListener(ctx->getErrorListener());
            if(!visitParametersCS(paramCS)) {
                return false;
            }
            std::shared_ptr<CollectionLiteralExp> innerColl = std::dynamic_pointer_cast<CollectionLiteralExp>(paramCS->getAST());
            for(size_t i = 0; i < innerColl->getPart()->size(); i++) {
                std::shared_ptr<CollectionItem> item = std::dynamic_pointer_cast<CollectionItem>(innerColl->getPart()->at(i));
                exp->getArgument()->add(item->getItem());
            }
        }

        std::shared_ptr<ecore::EOperation> eoper = OclReflection::lookupOperation(eClass, simpleName, exp->getArgument());
        if(eoper != nullptr) {

            if(typeCS != nullptr) {
                typeCS->setEnv(ctx->getEnv());
                typeCS->setErrorListener(ctx->getErrorListener());
                if(!visitTypeCS(typeCS)) {
                    return false;
                }
                std::shared_ptr<TypeExp> typeExp = std::dynamic_pointer_cast<TypeExp>(typeCS->getAST());
                if(typeExp->getReferredType()->getClassifierID() != eoper->getEType()->getClassifierID()) {
                    ctx->getErrorListener()->syntaxError("The declared type must be conform to the operation type");
                    return false;
                }
            }

            std::shared_ptr<OperationCallExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createOperationCallExpEval();
            std::shared_ptr<fUML::Semantics::Values::Value> objValue = OclReflection::createValue(eoper, exp->getArgument(), var->getValue());

            expEval->setModel(exp);
            expEval->setResultValue(objValue);

            exp->setName(simpleName);
            exp->setInstance(expEval);
            exp->setEType(eoper->getEType());
            exp->setReferredOperation(eoper);
            ctx->setAST(exp);

            return true;
        }
        else {
            std::string error = "Unrecognized operation: " + simpleName + "(";
            for(size_t i = 0; i < exp->getArgument()->size(); i++) {
                if(i != 0) {
                    error += ", ";
                }
                error += exp->getArgument()->at(i)->getInstance()->getResultValue()->toString();
            }
            error += ")";
            ctx->getErrorListener()->syntaxError(error);
        }
    }
    else {
        ctx->getErrorListener()->syntaxError("Unknown variable ("+ simpleName +")");
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx)
{
    OclParser::OperationCSContext* opeCS = ctx->operationCS();
    OclParser::PrePostOrBodyDeclCSContext* ppbCS = ctx->prePostOrBodyDeclCS();

    opeCS->setEnv(ctx->getEnv());
    opeCS->setErrorListener(ctx->getErrorListener());

    if(visitOperationCS(opeCS)) {
        std::shared_ptr<OperationCallExp> opeExp = std::dynamic_pointer_cast<OperationCallExp>(opeCS->getAST());
        std::shared_ptr<ecore::EOperation> ope = opeExp->getReferredOperation();

        for(size_t i = 0; i < opeExp->getArgument()->size(); i++) {
            std::shared_ptr<VariableExp> varExp = std::dynamic_pointer_cast<VariableExp>(opeExp->getArgument()->at(i));
            std::shared_ptr<Variable> var = varExp->getReferredVariable();
            ctx->getEnv()->addElement(var->getName(), var, true);
        }

        ppbCS->setAST(opeExp);
        ppbCS->setEnv(ctx->getEnv());
        ppbCS->setErrorListener(ctx->getErrorListener());

        if(visitPrePostOrBodyDeclCS(ppbCS)) {
            ctx->setAST(ppbCS->getAST());
            return true;
        }
    }
    return false;
}

antlrcpp::Any OclParserCustomVisitor::visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx)
{
    OclParser::OclExpressionCSContext* oclExpCS = ctx->oclExpressionCS();

    oclExpCS->setEnv(ctx->getEnv());
    oclExpCS->setErrorListener(ctx->getErrorListener());

    if(ctx->PRE() != nullptr) {
        return visitForBoolExp(ctx, oclExpCS, ctx->simpleNameCS());
    }
    else if(ctx->POST() != nullptr) {
        std::shared_ptr<OperationCallExp> opeExp = std::dynamic_pointer_cast<OperationCallExp>(ctx->getAST());
        std::shared_ptr<fUML::Semantics::Values::Value> objValue = opeExp->getInstance()->getResultValue();
        std::shared_ptr<ObjectValue> selfValue = std::dynamic_pointer_cast<ObjectValue>(opeExp->getSource()->getInstance()->getResultValue());
        std::shared_ptr<Variable> self = ctx->getEnv()->getSelfVariable();

        // update the environment with the post context object (object after executing the operation)
        if(selfValue != nullptr && !selfValue->getHistory()->empty()) {
            std::shared_ptr<LocalSnapshot> lastSnapshot = selfValue->getHistory()->at(selfValue->getHistory()->size() - 1);
            if(!lastSnapshot->getBindings()->empty()) {
                std::shared_ptr<fUML::Semantics::Values::Value> postObj = lastSnapshot->getBindings()->at(0)->getValue();
                if(postObj != nullptr) {
                    self->setValue(postObj);
                }
            }
        }

        if(objValue != nullptr && std::dynamic_pointer_cast<UndefinedValue>(objValue) == nullptr) {
            std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();

            var->setName("result");
            var->setValue(objValue);
            ctx->getEnv()->addElement(var->getName(), var, false);
        }
        return visitForBoolExp(ctx, oclExpCS, ctx->simpleNameCS());
    }
    else {
        if(visitOclExpressionCS(oclExpCS)) {
            std::shared_ptr<OclExpression> oclExp = oclExpCS->getAST();
            std::shared_ptr<OperationCallExp> opeExp = std::dynamic_pointer_cast<OperationCallExp>(ctx->getAST());

            /*
            std::shared_ptr<fUML::Semantics::Values::Value> operValue = opeExp->getInstance()->getResultValue();
            std::shared_ptr<fUML::Semantics::Values::Value> exprValue = oclExp->getInstance()->getResultValue();
            std::shared_ptr<BooleanLiteralExp> boolExp = createBooleanLiteralExp(operValue->equals(exprValue));
            ctx->setAST(boolExp);
            */

            if(oclExp->getEType()->getClassifierID() != opeExp->getEType()->getClassifierID()) {
                ctx->getErrorListener()->syntaxError("The body return type must be conform to the operation type");
                return false;
            }

            if(ctx->simpleNameCS() != nullptr) {
                std::string simpleName = ctx->simpleNameCS()->ID()->getSymbol()->getText();
                std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();

                var->setName(simpleName);
                var->setValue(oclExp->getInstance()->getResultValue());
                var->setInitExpression(oclExp);
                ctx->getEnv()->addElement(var->getName(), var, false);
            }
            ctx->setAST(oclExp);
            return true;
        }
    }
    return false;
}

bool OclParserCustomVisitor::arithmeticExpr(OclParser::OclExpressionCSContext *ctx)
{
    std::shared_ptr<OclExpression> leftExpr = ctx->oclExpressionCS(0)->getAST();
    std::shared_ptr<OclExpression> rightExpr = ctx->oclExpressionCS(1)->getAST();
    std::shared_ptr<fUML::Semantics::Values::Value> leftvalue = leftExpr->getInstance()->getResultValue();
    std::shared_ptr<fUML::Semantics::Values::Value> rightvalue = rightExpr->getInstance()->getResultValue();

    if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(leftvalue) || std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(leftvalue) != nullptr) {
        int leftInt = retrieveInt(leftvalue);
        if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(rightvalue) || std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(rightvalue) != nullptr) {
            int rightInt = retrieveInt(rightvalue);
            int result = 0;
            if(ctx->PLUS() != nullptr) { // leftInt + rightReal
                result = leftInt + rightInt;
            }
            else if(ctx->MINUS() != nullptr) { // leftInt - rightReal
                result = leftInt - rightInt;
            }
            if(ctx->STAR() != nullptr) { // leftInt * rightInt
                result = leftInt * rightInt;
            }
            else if(ctx->SLASH() != nullptr) { // leftInt / rightInt
                result = leftInt / rightInt;
            }
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
            std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getInteger_Class();
            std::shared_ptr<IntegerLiteralExp> resultExpr = ExpressionsFactory::eInstance()->createIntegerLiteralExp();
            std::shared_ptr<IntegerLiteralExpEval> resultEval = EvaluationsFactory::eInstance()->createIntegerLiteralExpEval();

            intValue->setValue(result);
            resultEval->setResultValue(intValue);
            resultExpr->setEType(type);
            resultExpr->setInstance(resultEval);
            resultExpr->setIntegerSymbol(result);
            ctx->setAST(resultExpr);
            return true;
        }
        else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue)) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> rightReal = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue);
            double result = 0;
            if(ctx->PLUS() != nullptr) { // leftInt + rightReal
                result = leftInt + rightReal->getValue();
            }
            else if(ctx->MINUS() != nullptr) { // leftInt - rightReal
                result = leftInt - rightReal->getValue();
            }
            else if(ctx->STAR() != nullptr) { // leftInt * rightReal
                result = leftInt * rightReal->getValue();
            }
            else if(ctx->SLASH() != nullptr) { // leftInt / rightReal
                result = leftInt / rightReal->getValue();
            }
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
            std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getReal_Class();
            std::shared_ptr<RealLiteralExp> resultExpr = ExpressionsFactory::eInstance()->createRealLiteralExp();
            std::shared_ptr<RealLiteralExpEval> resultEval = EvaluationsFactory::eInstance()->createRealLiteralExpEval();

            realValue->setValue(result);
            resultEval->setResultValue(realValue);
            resultExpr->setEType(type);
            resultExpr->setInstance(resultEval);
            resultExpr->setRealSymbol(result);
            ctx->setAST(resultExpr);
            return true;
        }
        else {
            ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left integer value must be an integer, an unlimiteNatural, or a real");
        }
    }
    else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(leftvalue)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> leftReal = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(leftvalue);
        if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(rightvalue) || std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(rightvalue) != nullptr) {
            int rightInt = retrieveInt(rightvalue);
            double result = 0;
            if(ctx->PLUS() != nullptr) { // leftReal + rightInt
                result = leftReal->getValue() + rightInt;
            }
            else if(ctx->MINUS() != nullptr) { // leftReal - rightInt
                result = leftReal->getValue() - rightInt;
            }
            else if(ctx->STAR() != nullptr) { // leftReal * rightInt
                result = leftReal->getValue() * rightInt;
            }
            else if(ctx->SLASH() != nullptr) { // leftReal / rightInt
                result = leftReal->getValue() / rightInt;
            }
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
            std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getReal_Class();
            std::shared_ptr<RealLiteralExp> resultExpr = ExpressionsFactory::eInstance()->createRealLiteralExp();
            std::shared_ptr<RealLiteralExpEval> resultEval = EvaluationsFactory::eInstance()->createRealLiteralExpEval();

            realValue->setValue(result);
            resultEval->setResultValue(realValue);
            resultExpr->setEType(type);
            resultExpr->setInstance(resultEval);
            resultExpr->setRealSymbol(result);
            ctx->setAST(resultExpr);
            return true;
        }
        else if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue)) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> rightReal = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(rightvalue);
            double result = 0;
            if(ctx->PLUS() != nullptr) { // leftReal + rightReal
                result = leftReal->getValue() + rightReal->getValue();
            }
            else if(ctx->MINUS() != nullptr) { // leftReal - rightReal
                result = leftReal->getValue() - rightReal->getValue();
            }
            else if(ctx->STAR() != nullptr) { // leftReal * rightReal
                result = leftReal->getValue() * rightReal->getValue();
            }
            else if(ctx->SLASH() != nullptr) { // leftReal / rightReal
                result = leftReal->getValue() / rightReal->getValue();
            }
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
            std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getReal_Class();
            std::shared_ptr<RealLiteralExp> resultExpr = ExpressionsFactory::eInstance()->createRealLiteralExp();
            std::shared_ptr<RealLiteralExpEval> resultEval = EvaluationsFactory::eInstance()->createRealLiteralExpEval();

            realValue->setValue(result);
            resultEval->setResultValue(realValue);
            resultExpr->setEType(type);
            resultExpr->setInstance(resultEval);
            resultExpr->setRealSymbol(result);
            ctx->setAST(resultExpr);
            return true;
        }
        else {
            ctx->getErrorListener()->syntaxError("The right value of a binary operation with a left real value must be an integer, an unlimiteNatural, or a real");
        }
    }
    else {
        ctx->getErrorListener()->syntaxError("The left and right value of a binary operation must be integers, unlimiteNaturals, or reals");
    }
    return false;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> OclParserCustomVisitor::doOperation(OclParser::BinaryLiteralExpCSContext *binCS, double left, double right)
{
    bool result = false;
    if(binCS->LT() != nullptr) { // leftReal < right
        result = left < right;
    }
    else if(binCS->GT() != nullptr) { // leftReal > right
        result = left > right;
    }
    else if(binCS->LTE() != nullptr) { // leftReal <= right
        result = left <= right;
    }
    else if(binCS->GTE() != nullptr) { // leftReal >= right
        result = left >= right;
    }
    else if(binCS->ASSIGN() != nullptr) { // leftReal == right
        result = left == right;
    }
    else if(binCS->INEQUAL() != nullptr) { // leftReal != right
        result = left != right;
    }
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
    boolValue->setValue(result);
    return boolValue;
}

std::shared_ptr<BooleanLiteralExp> OclParserCustomVisitor::createBooleanLiteralExp(bool value)
{
    std::shared_ptr<BooleanLiteralExp> boolExp = ocl::Expressions::ExpressionsFactory::eInstance()->createBooleanLiteralExp();
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
    std::shared_ptr<ecore::EClassifier> type = ::types::typesPackage::eInstance()->getBoolean_Class();
    std::shared_ptr<BooleanLiteralExpEval> boolEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createBooleanLiteralExpEval();

    boolValue->setValue(value);
    boolEval->setResultValue(boolValue);
    boolExp->setBooleanSymbol(value);
    boolExp->setEType(type);
    boolExp->setInstance(boolEval);

    return boolExp;
}

std::shared_ptr<VariableExp> OclParserCustomVisitor::createVariableExp(std::shared_ptr<Variable> var)
{
    std::shared_ptr<VariableExp> exp = ocl::Expressions::ExpressionsFactory::eInstance()->createVariableExp();
    std::shared_ptr<VariableExpEval> expEval = ocl::Evaluations::EvaluationsFactory::eInstance()->createVariableExpEval();

    expEval->setModel(exp);
    expEval->setResultValue(var->getValue());

    exp->setName(var->getName());
    exp->setInstance(expEval);
    exp->setReferredVariable(var);
    exp->setEType(var->getEType());
    return exp;
}

int OclParserCustomVisitor::retrieveInt(std::shared_ptr<fUML::Semantics::Values::Value> value)
{
    int intValue = 0;
    if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(value)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> left = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(value);
        intValue = left->getValue();
    }
    else {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> left = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(value);
        intValue = left->getValue();
    }
    return intValue;
}

bool OclParserCustomVisitor::visitForBoolExp(CSTNode *ctx, OclParser::OclExpressionCSContext *oclExpCS, OclParser::SimpleNameCSContext *simpleNameCS)
{
    if(visitOclExpressionCS(oclExpCS)) {
        std::shared_ptr<OclExpression> boolExp = oclExpCS->getAST();
        std::shared_ptr<fUML::Semantics::Values::Value> boolValue = boolExp->getInstance()->getResultValue();

        if(OclReflection::instanceOf<fUML::Semantics::SimpleClassifiers::BooleanValue>(boolValue)) {
            if(simpleNameCS != nullptr) {
                std::string simpleName = simpleNameCS->ID()->getSymbol()->getText();
                std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();

                var->setName(simpleName);
                var->setValue(boolValue);
                var->setInitExpression(boolExp);
                ctx->getEnv()->addElement(var->getName(), var, false);
            }
            ctx->setAST(boolExp);
            return true;
        }
        else {
            ctx->getErrorListener()->syntaxError("The Result of an invariant must be a boolean");
        }
    }
    return false;
}

string OclParserCustomVisitor::getPath(std::vector<string> path)
{
    std::string str;
    for(size_t i = 0; i < path.size(); i++) {
        if(i == 0) str = path[i];
        else str += "::" + path[i];
    }
    return str;
}

antlrcpp::Any OclParserCustomVisitor::visitArgumentsCS(OclParser::ArgumentsCSContext *ctx)
{
    OclParser::OclExpressionCSContext* expr = ctx->oclExpressionCS();
    OclParser::ArgumentsCSContext* arguments = ctx->argumentsCS();

    expr->setEnv(ctx->getEnv());
    expr->setErrorListener(ctx->getErrorListener());
    visitOclExpressionCS(expr);

    if(std::dynamic_pointer_cast<NavigationCallExp>(ctx->getAST()) != nullptr) {
        std::shared_ptr<NavigationCallExp> navExpr = std::dynamic_pointer_cast<NavigationCallExp>(ctx->getAST());
        navExpr->getQualifier()->add(expr->getAST());
    }
    else {
        std::shared_ptr<OperationCallExp> opExpr = std::dynamic_pointer_cast<OperationCallExp>(ctx->getAST());
        opExpr->getArgument()->add(expr->getAST());
    }

    if(arguments != nullptr) {
        arguments->setEnv(ctx->getEnv());
        arguments->setErrorListener(ctx->getErrorListener());
        arguments->setAST(ctx->getAST());
        visitArgumentsCS(arguments);
    }
    return true;
}
}
