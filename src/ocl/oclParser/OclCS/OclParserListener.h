
  #include "CSTNode.h"


// Generated from OclParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "OclParser.h"


namespace OclCS {

/**
 * This interface defines an abstract listener for a parse tree produced by OclParser.
 */
class  OclParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) = 0;
  virtual void exitExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) = 0;

  virtual void enterOclExpressionCS(OclParser::OclExpressionCSContext *ctx) = 0;
  virtual void exitOclExpressionCS(OclParser::OclExpressionCSContext *ctx) = 0;

  virtual void enterVariableExpCS(OclParser::VariableExpCSContext *ctx) = 0;
  virtual void exitVariableExpCS(OclParser::VariableExpCSContext *ctx) = 0;

  virtual void enterSimpleNameCS(OclParser::SimpleNameCSContext *ctx) = 0;
  virtual void exitSimpleNameCS(OclParser::SimpleNameCSContext *ctx) = 0;

  virtual void enterRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *ctx) = 0;
  virtual void exitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *ctx) = 0;

  virtual void enterUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *ctx) = 0;
  virtual void exitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *ctx) = 0;

  virtual void enterPathNameCS(OclParser::PathNameCSContext *ctx) = 0;
  virtual void exitPathNameCS(OclParser::PathNameCSContext *ctx) = 0;

  virtual void enterLiteralExpCS(OclParser::LiteralExpCSContext *ctx) = 0;
  virtual void exitLiteralExpCS(OclParser::LiteralExpCSContext *ctx) = 0;

  virtual void enterEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) = 0;
  virtual void exitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) = 0;

  virtual void enterCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) = 0;
  virtual void exitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) = 0;

  virtual void enterCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *ctx) = 0;
  virtual void exitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *ctx) = 0;

  virtual void enterCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) = 0;
  virtual void exitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) = 0;

  virtual void enterCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext *ctx) = 0;
  virtual void exitCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext *ctx) = 0;

  virtual void enterCollectionRangeCS(OclParser::CollectionRangeCSContext *ctx) = 0;
  virtual void exitCollectionRangeCS(OclParser::CollectionRangeCSContext *ctx) = 0;

  virtual void enterPrefixedExp(OclParser::PrefixedExpContext *ctx) = 0;
  virtual void exitPrefixedExp(OclParser::PrefixedExpContext *ctx) = 0;

  virtual void enterInfixedExpCS(OclParser::InfixedExpCSContext *ctx) = 0;
  virtual void exitInfixedExpCS(OclParser::InfixedExpCSContext *ctx) = 0;

  virtual void enterPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx) = 0;
  virtual void exitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx) = 0;

  virtual void enterTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) = 0;
  virtual void exitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) = 0;

  virtual void enterUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *ctx) = 0;
  virtual void exitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *ctx) = 0;

  virtual void enterIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *ctx) = 0;
  virtual void exitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *ctx) = 0;

  virtual void enterRealLiteralExpCS(OclParser::RealLiteralExpCSContext *ctx) = 0;
  virtual void exitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *ctx) = 0;

  virtual void enterStringLiteralExpCS(OclParser::StringLiteralExpCSContext *ctx) = 0;
  virtual void exitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *ctx) = 0;

  virtual void enterBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *ctx) = 0;
  virtual void exitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *ctx) = 0;

  virtual void enterTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext *ctx) = 0;
  virtual void exitTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext *ctx) = 0;

  virtual void enterIteratorExpCS(OclParser::IteratorExpCSContext *ctx) = 0;
  virtual void exitIteratorExpCS(OclParser::IteratorExpCSContext *ctx) = 0;

  virtual void enterIterateExpCS(OclParser::IterateExpCSContext *ctx) = 0;
  virtual void exitIterateExpCS(OclParser::IterateExpCSContext *ctx) = 0;

  virtual void enterVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) = 0;
  virtual void exitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) = 0;

  virtual void enterTypeCS(OclParser::TypeCSContext *ctx) = 0;
  virtual void exitTypeCS(OclParser::TypeCSContext *ctx) = 0;

  virtual void enterPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *ctx) = 0;
  virtual void exitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *ctx) = 0;

  virtual void enterOclTypeCS(OclParser::OclTypeCSContext *ctx) = 0;
  virtual void exitOclTypeCS(OclParser::OclTypeCSContext *ctx) = 0;

  virtual void enterCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) = 0;
  virtual void exitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) = 0;

  virtual void enterTupleTypeCS(OclParser::TupleTypeCSContext *ctx) = 0;
  virtual void exitTupleTypeCS(OclParser::TupleTypeCSContext *ctx) = 0;

  virtual void enterVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext *ctx) = 0;
  virtual void exitVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext *ctx) = 0;

  virtual void enterOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) = 0;
  virtual void exitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) = 0;

  virtual void enterOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) = 0;
  virtual void exitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) = 0;

  virtual void enterPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) = 0;
  virtual void exitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) = 0;

  virtual void enterPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) = 0;
  virtual void exitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) = 0;

  virtual void enterAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) = 0;
  virtual void exitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) = 0;

  virtual void enterAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) = 0;
  virtual void exitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) = 0;

  virtual void enterIsMarkedPreCS(OclParser::IsMarkedPreCSContext *ctx) = 0;
  virtual void exitIsMarkedPreCS(OclParser::IsMarkedPreCSContext *ctx) = 0;

  virtual void enterArgumentsCS(OclParser::ArgumentsCSContext *ctx) = 0;
  virtual void exitArgumentsCS(OclParser::ArgumentsCSContext *ctx) = 0;

  virtual void enterLetExpCS(OclParser::LetExpCSContext *ctx) = 0;
  virtual void exitLetExpCS(OclParser::LetExpCSContext *ctx) = 0;

  virtual void enterLetExpSubCS(OclParser::LetExpSubCSContext *ctx) = 0;
  virtual void exitLetExpSubCS(OclParser::LetExpSubCSContext *ctx) = 0;

  virtual void enterOclMessageExpCS(OclParser::OclMessageExpCSContext *ctx) = 0;
  virtual void exitOclMessageExpCS(OclParser::OclMessageExpCSContext *ctx) = 0;

  virtual void enterOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *ctx) = 0;
  virtual void exitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *ctx) = 0;

  virtual void enterOclMessageArgCS(OclParser::OclMessageArgCSContext *ctx) = 0;
  virtual void exitOclMessageArgCS(OclParser::OclMessageArgCSContext *ctx) = 0;

  virtual void enterIfExpCS(OclParser::IfExpCSContext *ctx) = 0;
  virtual void exitIfExpCS(OclParser::IfExpCSContext *ctx) = 0;

  virtual void enterNullLiteralExpCS(OclParser::NullLiteralExpCSContext *ctx) = 0;
  virtual void exitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *ctx) = 0;

  virtual void enterInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *ctx) = 0;
  virtual void exitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *ctx) = 0;

  virtual void enterUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext *ctx) = 0;
  virtual void exitUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext *ctx) = 0;

  virtual void enterBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext *ctx) = 0;
  virtual void exitBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext *ctx) = 0;

  virtual void enterPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) = 0;
  virtual void exitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) = 0;

  virtual void enterContextDeclarationCS(OclParser::ContextDeclarationCSContext *ctx) = 0;
  virtual void exitContextDeclarationCS(OclParser::ContextDeclarationCSContext *ctx) = 0;

  virtual void enterClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) = 0;
  virtual void exitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) = 0;

  virtual void enterOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) = 0;
  virtual void exitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) = 0;

  virtual void enterPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) = 0;
  virtual void exitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) = 0;

  virtual void enterDefExpressionCS(OclParser::DefExpressionCSContext *ctx) = 0;
  virtual void exitDefExpressionCS(OclParser::DefExpressionCSContext *ctx) = 0;

  virtual void enterInvOrDefCS(OclParser::InvOrDefCSContext *ctx) = 0;
  virtual void exitInvOrDefCS(OclParser::InvOrDefCSContext *ctx) = 0;

  virtual void enterInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) = 0;
  virtual void exitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) = 0;

  virtual void enterPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) = 0;
  virtual void exitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) = 0;

  virtual void enterOperationCS(OclParser::OperationCSContext *ctx) = 0;
  virtual void exitOperationCS(OclParser::OperationCSContext *ctx) = 0;

  virtual void enterParametersCS(OclParser::ParametersCSContext *ctx) = 0;
  virtual void exitParametersCS(OclParser::ParametersCSContext *ctx) = 0;


};

}  // namespace OclCS
