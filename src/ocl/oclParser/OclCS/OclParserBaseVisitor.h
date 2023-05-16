
// Generated from OclParser.g4 by ANTLR 4.12.0

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

  virtual std::any visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOclExpressionCS(OclParser::OclExpressionCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParentedExpCS(OclParser::ParentedExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableExpCS(OclParser::VariableExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleNameCS(OclParser::SimpleNameCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathNameCS(OclParser::PathNameCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralExpCS(OclParser::LiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionRangeCS(OclParser::CollectionRangeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefixedExp(OclParser::PrefixedExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIteratorExpCS(OclParser::IteratorExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIterateExpCS(OclParser::IterateExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeCS(OclParser::TypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOclTypeCS(OclParser::OclTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTupleTypeCS(OclParser::TupleTypeCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsMarkedPreCS(OclParser::IsMarkedPreCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLetExpCS(OclParser::LetExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOclMessageExpCS(OclParser::OclMessageExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfExpCS(OclParser::IfExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContextDeclarationCS(OclParser::ContextDeclarationCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefExpressionCS(OclParser::DefExpressionCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvOrDefCS(OclParser::InvOrDefCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitOrDerValueListCS(OclParser::InitOrDerValueListCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrePostBodyExpCS(OclParser::PrePostBodyExpCSContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperationCS(OclParser::OperationCSContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace OclCS
