
  #include "CSTNode.h"


// Generated from OclParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "OclParserVisitor.h"


namespace OclCS {

/**
 * This class provides an empty implementation of OclParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  OclParserBaseVisitor : public OclParserVisitor {
public:

  virtual antlrcpp::Any visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOclExpressionCS(OclParser::OclExpressionCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableExpCS(OclParser::VariableExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleNameCS(OclParser::SimpleNameCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPathNameCS(OclParser::PathNameCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpCS(OclParser::LiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionRangeCS(OclParser::CollectionRangeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrefixedExp(OclParser::PrefixedExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInfixedExpCS(OclParser::InfixedExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIteratorExpCS(OclParser::IteratorExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterateExpCS(OclParser::IterateExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeCS(OclParser::TypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOclTypeCS(OclParser::OclTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTupleTypeCS(OclParser::TupleTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsMarkedPreCS(OclParser::IsMarkedPreCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentsCS(OclParser::ArgumentsCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLetExpCS(OclParser::LetExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLetExpSubCS(OclParser::LetExpSubCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOclMessageExpCS(OclParser::OclMessageExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOclMessageArgCS(OclParser::OclMessageArgCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpCS(OclParser::IfExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContextDeclarationCS(OclParser::ContextDeclarationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefExpressionCS(OclParser::DefExpressionCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInvOrDefCS(OclParser::InvOrDefCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperationCS(OclParser::OperationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParametersCS(OclParser::ParametersCSContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace OclCS
