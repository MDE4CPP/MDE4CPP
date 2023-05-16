
// Generated from OclParser.g4 by ANTLR 4.12.0

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
    virtual std::any visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *context) = 0;

    virtual std::any visitOclExpressionCS(OclParser::OclExpressionCSContext *context) = 0;

    virtual std::any visitParentedExpCS(OclParser::ParentedExpCSContext *context) = 0;

    virtual std::any visitVariableExpCS(OclParser::VariableExpCSContext *context) = 0;

    virtual std::any visitSimpleNameCS(OclParser::SimpleNameCSContext *context) = 0;

    virtual std::any visitRestrictedKeywordCS(OclParser::RestrictedKeywordCSContext *context) = 0;

    virtual std::any visitUnreservedSimpleNameCS(OclParser::UnreservedSimpleNameCSContext *context) = 0;

    virtual std::any visitPathNameCS(OclParser::PathNameCSContext *context) = 0;

    virtual std::any visitLiteralExpCS(OclParser::LiteralExpCSContext *context) = 0;

    virtual std::any visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *context) = 0;

    virtual std::any visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *context) = 0;

    virtual std::any visitCollectionTypeIdentifierCS(OclParser::CollectionTypeIdentifierCSContext *context) = 0;

    virtual std::any visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *context) = 0;

    virtual std::any visitCollectionRangeCS(OclParser::CollectionRangeCSContext *context) = 0;

    virtual std::any visitPrefixedExp(OclParser::PrefixedExpContext *context) = 0;

    virtual std::any visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *context) = 0;

    virtual std::any visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *context) = 0;

    virtual std::any visitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *context) = 0;

    virtual std::any visitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *context) = 0;

    virtual std::any visitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *context) = 0;

    virtual std::any visitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *context) = 0;

    virtual std::any visitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *context) = 0;

    virtual std::any visitTypeLiteralExpCS(OclParser::TypeLiteralExpCSContext *context) = 0;

    virtual std::any visitIteratorExpCS(OclParser::IteratorExpCSContext *context) = 0;

    virtual std::any visitIterateExpCS(OclParser::IterateExpCSContext *context) = 0;

    virtual std::any visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *context) = 0;

    virtual std::any visitTypeCS(OclParser::TypeCSContext *context) = 0;

    virtual std::any visitPrimitiveTypeCS(OclParser::PrimitiveTypeCSContext *context) = 0;

    virtual std::any visitOclTypeCS(OclParser::OclTypeCSContext *context) = 0;

    virtual std::any visitCollectionTypeCS(OclParser::CollectionTypeCSContext *context) = 0;

    virtual std::any visitTupleTypeCS(OclParser::TupleTypeCSContext *context) = 0;

    virtual std::any visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *context) = 0;

    virtual std::any visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *context) = 0;

    virtual std::any visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *context) = 0;

    virtual std::any visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *context) = 0;

    virtual std::any visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *context) = 0;

    virtual std::any visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *context) = 0;

    virtual std::any visitIsMarkedPreCS(OclParser::IsMarkedPreCSContext *context) = 0;

    virtual std::any visitLetExpCS(OclParser::LetExpCSContext *context) = 0;

    virtual std::any visitOclMessageExpCS(OclParser::OclMessageExpCSContext *context) = 0;

    virtual std::any visitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *context) = 0;

    virtual std::any visitIfExpCS(OclParser::IfExpCSContext *context) = 0;

    virtual std::any visitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *context) = 0;

    virtual std::any visitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *context) = 0;

    virtual std::any visitUnaryLiteralExpCS(OclParser::UnaryLiteralExpCSContext *context) = 0;

    virtual std::any visitBinaryLiteralExpCS(OclParser::BinaryLiteralExpCSContext *context) = 0;

    virtual std::any visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *context) = 0;

    virtual std::any visitContextDeclarationCS(OclParser::ContextDeclarationCSContext *context) = 0;

    virtual std::any visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *context) = 0;

    virtual std::any visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *context) = 0;

    virtual std::any visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *context) = 0;

    virtual std::any visitDefExpressionCS(OclParser::DefExpressionCSContext *context) = 0;

    virtual std::any visitInvOrDefCS(OclParser::InvOrDefCSContext *context) = 0;

    virtual std::any visitInitOrDerValueListCS(OclParser::InitOrDerValueListCSContext *context) = 0;

    virtual std::any visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *context) = 0;

    virtual std::any visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *context) = 0;

    virtual std::any visitPrePostBodyExpCS(OclParser::PrePostBodyExpCSContext *context) = 0;

    virtual std::any visitOperationCS(OclParser::OperationCSContext *context) = 0;


};

}  // namespace OclCS
