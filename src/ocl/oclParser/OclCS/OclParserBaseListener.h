
  #include "CSTNode.h"


// Generated from OclParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "OclParserListener.h"


namespace OclCS {

/**
 * This class provides an empty implementation of OclParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  OclParserBaseListener : public OclParserListener {
public:

  virtual void enterExpressionInOclCS(OclParser::ExpressionInOclCSContext * /*ctx*/) override { }
  virtual void exitExpressionInOclCS(OclParser::ExpressionInOclCSContext * /*ctx*/) override { }

  virtual void enterOclExpressionCS(OclParser::OclExpressionCSContext * /*ctx*/) override { }
  virtual void exitOclExpressionCS(OclParser::OclExpressionCSContext * /*ctx*/) override { }

  virtual void enterVariableExpCS(OclParser::VariableExpCSContext * /*ctx*/) override { }
  virtual void exitVariableExpCS(OclParser::VariableExpCSContext * /*ctx*/) override { }

  virtual void enterSimpleNameCS(OclParser::SimpleNameCSContext * /*ctx*/) override { }
  virtual void exitSimpleNameCS(OclParser::SimpleNameCSContext * /*ctx*/) override { }

  virtual void enterRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext * /*ctx*/) override { }
  virtual void exitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext * /*ctx*/) override { }

  virtual void enterUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext * /*ctx*/) override { }
  virtual void exitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext * /*ctx*/) override { }

  virtual void enterPathNameCS(OclParser::PathNameCSContext * /*ctx*/) override { }
  virtual void exitPathNameCS(OclParser::PathNameCSContext * /*ctx*/) override { }

  virtual void enterLiteralExpCS(OclParser::LiteralExpCSContext * /*ctx*/) override { }
  virtual void exitLiteralExpCS(OclParser::LiteralExpCSContext * /*ctx*/) override { }

  virtual void enterEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext * /*ctx*/) override { }
  virtual void exitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext * /*ctx*/) override { }

  virtual void enterCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext * /*ctx*/) override { }
  virtual void exitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext * /*ctx*/) override { }

  virtual void enterCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext * /*ctx*/) override { }
  virtual void exitCollectionLiteralPartCS(OclParser::CollectionLiteralPartCSContext * /*ctx*/) override { }

  virtual void enterCollectionRangeCS(OclParser::CollectionRangeCSContext * /*ctx*/) override { }
  virtual void exitCollectionRangeCS(OclParser::CollectionRangeCSContext * /*ctx*/) override { }

  virtual void enterPrefixedExp(OclParser::PrefixedExpContext * /*ctx*/) override { }
  virtual void exitPrefixedExp(OclParser::PrefixedExpContext * /*ctx*/) override { }

  virtual void enterInfixedExpCS(OclParser::InfixedExpCSContext * /*ctx*/) override { }
  virtual void exitInfixedExpCS(OclParser::InfixedExpCSContext * /*ctx*/) override { }

  virtual void enterPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterRealLiteralExpCS(OclParser::RealLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitRealLiteralExpCS(OclParser::RealLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterStringLiteralExpCS(OclParser::StringLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitStringLiteralExpCS(OclParser::StringLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterIteratorExpCS(OclParser::IteratorExpCSContext * /*ctx*/) override { }
  virtual void exitIteratorExpCS(OclParser::IteratorExpCSContext * /*ctx*/) override { }

  virtual void enterIterateExpCS(OclParser::IterateExpCSContext * /*ctx*/) override { }
  virtual void exitIterateExpCS(OclParser::IterateExpCSContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationCS(OclParser::VariableDeclarationCSContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationCS(OclParser::VariableDeclarationCSContext * /*ctx*/) override { }

  virtual void enterTypeCS(OclParser::TypeCSContext * /*ctx*/) override { }
  virtual void exitTypeCS(OclParser::TypeCSContext * /*ctx*/) override { }

  virtual void enterPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext * /*ctx*/) override { }
  virtual void exitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext * /*ctx*/) override { }

  virtual void enterOclTypeCS(OclParser::OclTypeCSContext * /*ctx*/) override { }
  virtual void exitOclTypeCS(OclParser::OclTypeCSContext * /*ctx*/) override { }

  virtual void enterCollectionTypeCS(OclParser::CollectionTypeCSContext * /*ctx*/) override { }
  virtual void exitCollectionTypeCS(OclParser::CollectionTypeCSContext * /*ctx*/) override { }

  virtual void enterTupleTypeCS(OclParser::TupleTypeCSContext * /*ctx*/) override { }
  virtual void exitTupleTypeCS(OclParser::TupleTypeCSContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationListCS(OclParser::VariableDeclarationListCSContext * /*ctx*/) override { }

  virtual void enterOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext * /*ctx*/) override { }
  virtual void exitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext * /*ctx*/) override { }

  virtual void enterOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext * /*ctx*/) override { }
  virtual void exitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext * /*ctx*/) override { }

  virtual void enterPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext * /*ctx*/) override { }
  virtual void exitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext * /*ctx*/) override { }

  virtual void enterPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext * /*ctx*/) override { }
  virtual void exitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext * /*ctx*/) override { }

  virtual void enterAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext * /*ctx*/) override { }
  virtual void exitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext * /*ctx*/) override { }

  virtual void enterAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext * /*ctx*/) override { }
  virtual void exitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext * /*ctx*/) override { }

  virtual void enterIsMarkedPreCS(OclParser::IsMarkedPreCSContext * /*ctx*/) override { }
  virtual void exitIsMarkedPreCS(OclParser::IsMarkedPreCSContext * /*ctx*/) override { }

  virtual void enterArgumentsCS(OclParser::ArgumentsCSContext * /*ctx*/) override { }
  virtual void exitArgumentsCS(OclParser::ArgumentsCSContext * /*ctx*/) override { }

  virtual void enterLetExpCS(OclParser::LetExpCSContext * /*ctx*/) override { }
  virtual void exitLetExpCS(OclParser::LetExpCSContext * /*ctx*/) override { }

  virtual void enterLetExpSubCS(OclParser::LetExpSubCSContext * /*ctx*/) override { }
  virtual void exitLetExpSubCS(OclParser::LetExpSubCSContext * /*ctx*/) override { }

  virtual void enterOclMessageExpCS(OclParser::OclMessageExpCSContext * /*ctx*/) override { }
  virtual void exitOclMessageExpCS(OclParser::OclMessageExpCSContext * /*ctx*/) override { }

  virtual void enterOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext * /*ctx*/) override { }
  virtual void exitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext * /*ctx*/) override { }

  virtual void enterOclMessageArgCS(OclParser::OclMessageArgCSContext * /*ctx*/) override { }
  virtual void exitOclMessageArgCS(OclParser::OclMessageArgCSContext * /*ctx*/) override { }

  virtual void enterIfExpCS(OclParser::IfExpCSContext * /*ctx*/) override { }
  virtual void exitIfExpCS(OclParser::IfExpCSContext * /*ctx*/) override { }

  virtual void enterNullLiteralExpCS(OclParser::NullLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitNullLiteralExpCS(OclParser::NullLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext * /*ctx*/) override { }
  virtual void exitBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext * /*ctx*/) override { }

  virtual void enterPackageDeclarationCS(OclParser::PackageDeclarationCSContext * /*ctx*/) override { }
  virtual void exitPackageDeclarationCS(OclParser::PackageDeclarationCSContext * /*ctx*/) override { }

  virtual void enterContextDeclarationCS(OclParser::ContextDeclarationCSContext * /*ctx*/) override { }
  virtual void exitContextDeclarationCS(OclParser::ContextDeclarationCSContext * /*ctx*/) override { }

  virtual void enterClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext * /*ctx*/) override { }
  virtual void exitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext * /*ctx*/) override { }

  virtual void enterOperationContextDeclCS(OclParser::OperationContextDeclCSContext * /*ctx*/) override { }
  virtual void exitOperationContextDeclCS(OclParser::OperationContextDeclCSContext * /*ctx*/) override { }

  virtual void enterPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext * /*ctx*/) override { }
  virtual void exitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext * /*ctx*/) override { }

  virtual void enterDefExpressionCS(OclParser::DefExpressionCSContext * /*ctx*/) override { }
  virtual void exitDefExpressionCS(OclParser::DefExpressionCSContext * /*ctx*/) override { }

  virtual void enterInvOrDefCS(OclParser::InvOrDefCSContext * /*ctx*/) override { }
  virtual void exitInvOrDefCS(OclParser::InvOrDefCSContext * /*ctx*/) override { }

  virtual void enterInitOrDerValueCS(OclParser::InitOrDerValueCSContext * /*ctx*/) override { }
  virtual void exitInitOrDerValueCS(OclParser::InitOrDerValueCSContext * /*ctx*/) override { }

  virtual void enterPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext * /*ctx*/) override { }
  virtual void exitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext * /*ctx*/) override { }

  virtual void enterOperationCS(OclParser::OperationCSContext * /*ctx*/) override { }
  virtual void exitOperationCS(OclParser::OperationCSContext * /*ctx*/) override { }

  virtual void enterParametersCS(OclParser::ParametersCSContext * /*ctx*/) override { }
  virtual void exitParametersCS(OclParser::ParametersCSContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace OclCS
