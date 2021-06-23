#ifndef OCLPARSERCUSTOMVISITOR_H
#define OCLPARSERCUSTOMVISITOR_H

#include "OclParserBaseVisitor.h"

#include <ocl/Expressions/AssociationClassCallExp.hpp>
#include <ocl/Expressions/PropertyCallExp.hpp>
#include <ocl/Expressions/OperationCallExp.hpp>
#include <ocl/Expressions/BooleanLiteralExp.hpp>

#include <fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/StringValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/BooleanValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/IntegerValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/RealValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp>
#include <fUML/Semantics/Values/Value.hpp>

using namespace ocl::Expressions;

namespace OclCS {

class OclParserCustomVisitor : public OclParserBaseVisitor
{
public:
    virtual antlrcpp::Any visitChildren(antlr4::tree::ParseTree *node) override;

    // virtual antlrcpp::Any visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) override;

    virtual antlrcpp::Any visitOclExpressionCS(OclParser::OclExpressionCSContext *ctx) override;

    virtual antlrcpp::Any visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) override;

    virtual antlrcpp::Any visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) override;

    virtual antlrcpp::Any visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) override;

    virtual antlrcpp::Any visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) override;

    virtual antlrcpp::Any visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) override;

    virtual antlrcpp::Any visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) override;

    virtual antlrcpp::Any visitArgumentsCS(OclParser::ArgumentsCSContext *ctx) override;

    virtual antlrcpp::Any visitVariableExpCS(OclParser::VariableExpCSContext *ctx) override;

    virtual antlrcpp::Any visitLetExpCS(OclParser::LetExpCSContext *ctx) override;

    virtual antlrcpp::Any visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) override;

    virtual antlrcpp::Any visitLetExpSubCS(OclParser::LetExpSubCSContext *ctx) override;

    virtual antlrcpp::Any visitTypeCS(OclParser::TypeCSContext *ctx) override;

    virtual antlrcpp::Any visitPathNameCS(OclParser::PathNameCSContext *ctx) override;

    virtual antlrcpp::Any visitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *ctx) override;

    virtual antlrcpp::Any visitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *ctx) override;

    virtual antlrcpp::Any visitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *ctx) override;

    virtual antlrcpp::Any visitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *ctx) override;

    virtual antlrcpp::Any visitOclTypeCS(OclParser::OclTypeCSContext *ctx) override;

    virtual antlrcpp::Any visitSimpleNameCS(OclParser::SimpleNameCSContext *ctx) override;

    virtual antlrcpp::Any visitPrefixedExp(OclParser::PrefixedExpContext *ctx) override;

    virtual antlrcpp::Any visitInfixedExpCS(OclParser::InfixedExpCSContext *ctx) override;

    virtual antlrcpp::Any visitTupleTypeCS(OclParser::TupleTypeCSContext *ctx) override;

    virtual antlrcpp::Any visitVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext *ctx) override;

    virtual antlrcpp::Any visitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) override;

    virtual antlrcpp::Any visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) override;

    virtual antlrcpp::Any visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) override;

    virtual antlrcpp::Any visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) override;

    virtual antlrcpp::Any visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx) override;

    virtual antlrcpp::Any visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) override;

    virtual antlrcpp::Any visitCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext *ctx) override;

    virtual antlrcpp::Any visitIteratorExpCS(OclParser::IteratorExpCSContext *ctx) override;

    virtual antlrcpp::Any visitIterateExpCS(OclParser::IterateExpCSContext *ctx) override;

    virtual antlrcpp::Any visitIfExpCS(OclParser::IfExpCSContext *ctx) override;

    virtual antlrcpp::Any visitParametersCS(OclParser::ParametersCSContext *ctx) override;

    virtual antlrcpp::Any visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) override;

    virtual antlrcpp::Any visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) override;

    virtual antlrcpp::Any visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) override;

    virtual antlrcpp::Any visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) override;

    virtual antlrcpp::Any visitInvOrDefCS(OclParser::InvOrDefCSContext *ctx) override;

    virtual antlrcpp::Any visitOperationCS(OclParser::OperationCSContext *ctx) override;

    virtual antlrcpp::Any visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) override;

    virtual antlrcpp::Any visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) override;

private:
    bool arithmeticExpr(OclParser::OclExpressionCSContext *ctx);
    std::shared_ptr<OclExpression> plusAndMinus(OclParser::OclExpressionCSContext* expr1, OclParser::OclExpressionCSContext* expr2, bool isPlus);
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> doOperation(OclParser::BinaryLiteralExpCSContext* binCS, double left, double right);
    std::shared_ptr<BooleanLiteralExp> createBooleanLiteralExp(bool value);
    std::shared_ptr<VariableExp> createVariableExp(std::shared_ptr<Variable> var);
    int retrieveInt(std::shared_ptr<fUML::Semantics::Values::Value> value);
    bool visitForBoolExp(CSTNode *ctx, OclParser::OclExpressionCSContext *oclExpCS, OclParser::SimpleNameCSContext *simpleNameCS);
    bool visitOperationCallExpCS(CSTNode* ctx, std::shared_ptr<OperationCallExp> exp, std::string simpleName, bool isImplicit);
    bool visitPropertyCallExpCS(CSTNode* ctx, std::shared_ptr<PropertyCallExp> exp, std::string simpleName, bool isPre, bool isImplicit);
    bool visitAssociationCallExpCS(CSTNode *ctx, OclParser::ArgumentsCSContext *argCS, std::shared_ptr<AssociationClassCallExp> exp,
                                   std::string simpleName, bool isPre, bool isImplicit);
    std::string getPath(std::vector<std::string> path);
};
}
#endif // OCLPARSERCUSTOMVISITOR_H
