
  #include "CSTNode.h"


// Generated from OclParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "OclParser.h"


namespace OclCS {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by OclParser.
 */
class  OclParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by OclParser.
   */
    virtual antlrcpp::Any visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *context) = 0;

    virtual antlrcpp::Any visitOclExpressionCS(OclParser::OclExpressionCSContext *context) = 0;

    virtual antlrcpp::Any visitVariableExpCS(OclParser::VariableExpCSContext *context) = 0;

    virtual antlrcpp::Any visitSimpleNameCS(OclParser::SimpleNameCSContext *context) = 0;

    virtual antlrcpp::Any visitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *context) = 0;

    virtual antlrcpp::Any visitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *context) = 0;

    virtual antlrcpp::Any visitPathNameCS(OclParser::PathNameCSContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpCS(OclParser::LiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *context) = 0;

    virtual antlrcpp::Any visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *context) = 0;

    virtual antlrcpp::Any visitCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext *context) = 0;

    virtual antlrcpp::Any visitCollectionRangeCS(OclParser::CollectionRangeCSContext *context) = 0;

    virtual antlrcpp::Any visitPrefixedExp(OclParser::PrefixedExpContext *context) = 0;

    virtual antlrcpp::Any visitInfixedExpCS(OclParser::InfixedExpCSContext *context) = 0;

    virtual antlrcpp::Any visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitIteratorExpCS(OclParser::IteratorExpCSContext *context) = 0;

    virtual antlrcpp::Any visitIterateExpCS(OclParser::IterateExpCSContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *context) = 0;

    virtual antlrcpp::Any visitTypeCS(OclParser::TypeCSContext *context) = 0;

    virtual antlrcpp::Any visitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *context) = 0;

    virtual antlrcpp::Any visitOclTypeCS(OclParser::OclTypeCSContext *context) = 0;

    virtual antlrcpp::Any visitCollectionTypeCS(OclParser::CollectionTypeCSContext *context) = 0;

    virtual antlrcpp::Any visitTupleTypeCS(OclParser::TupleTypeCSContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext *context) = 0;

    virtual antlrcpp::Any visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *context) = 0;

    virtual antlrcpp::Any visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *context) = 0;

    virtual antlrcpp::Any visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *context) = 0;

    virtual antlrcpp::Any visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *context) = 0;

    virtual antlrcpp::Any visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *context) = 0;

    virtual antlrcpp::Any visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *context) = 0;

    virtual antlrcpp::Any visitIsMarkedPreCS(OclParser::IsMarkedPreCSContext *context) = 0;

    virtual antlrcpp::Any visitArgumentsCS(OclParser::ArgumentsCSContext *context) = 0;

    virtual antlrcpp::Any visitLetExpCS(OclParser::LetExpCSContext *context) = 0;

    virtual antlrcpp::Any visitLetExpSubCS(OclParser::LetExpSubCSContext *context) = 0;

    virtual antlrcpp::Any visitOclMessageExpCS(OclParser::OclMessageExpCSContext *context) = 0;

    virtual antlrcpp::Any visitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *context) = 0;

    virtual antlrcpp::Any visitOclMessageArgCS(OclParser::OclMessageArgCSContext *context) = 0;

    virtual antlrcpp::Any visitIfExpCS(OclParser::IfExpCSContext *context) = 0;

    virtual antlrcpp::Any visitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext *context) = 0;

    virtual antlrcpp::Any visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *context) = 0;

    virtual antlrcpp::Any visitContextDeclarationCS(OclParser::ContextDeclarationCSContext *context) = 0;

    virtual antlrcpp::Any visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *context) = 0;

    virtual antlrcpp::Any visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *context) = 0;

    virtual antlrcpp::Any visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *context) = 0;

    virtual antlrcpp::Any visitDefExpressionCS(OclParser::DefExpressionCSContext *context) = 0;

    virtual antlrcpp::Any visitInvOrDefCS(OclParser::InvOrDefCSContext *context) = 0;

    virtual antlrcpp::Any visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *context) = 0;

    virtual antlrcpp::Any visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *context) = 0;

    virtual antlrcpp::Any visitOperationCS(OclParser::OperationCSContext *context) = 0;

    virtual antlrcpp::Any visitParametersCS(OclParser::ParametersCSContext *context) = 0;


};

}  // namespace OclCS
