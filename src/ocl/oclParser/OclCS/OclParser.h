
// Generated from OclParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace OclCS {


class  OclParser : public antlr4::Parser {
public:
  enum {
    COMMENTS = 1, IF = 2, THEN = 3, ELSE = 4, ENDIF = 5, IN = 6, PRE = 7, 
    LET = 8, ITERATE = 9, SELF = 10, TUPLE = 11, NULLEXP = 12, INVALID = 13, 
    PACKAGE = 14, ENDPACKAGE = 15, CONTEXT = 16, STATIC = 17, DEF = 18, 
    INV = 19, BODY = 20, POST = 21, INIT = 22, DERIVE = 23, COLLECTION = 24, 
    BAG = 25, ORDEREDSET = 26, SEQUENCE = 27, SET = 28, OCLBOOLEAN = 29, 
    OCLINTEGER = 30, OCLREAL = 31, OCLSTRING = 32, OCLUNLIMITEDNAT = 33, 
    SEQRANGE = 34, OCLANY = 35, OCLINVALID = 36, OCLMESSAGE = 37, OCLVOID = 38, 
    OCLSTATE = 39, INT = 40, REAL = 41, BOOL = 42, STRING_LITERAL = 43, 
    COLON = 44, COLONCOLON = 45, COMMA = 46, SEMI = 47, LPAREN = 48, RPAREN = 49, 
    LBRACE = 50, RBRACE = 51, LBRACK = 52, RBRACK = 53, RARROW = 54, LT = 55, 
    GT = 56, LTE = 57, GTE = 58, ASSIGN = 59, INEQUAL = 60, QUESTION = 61, 
    STAR = 62, PLUS_ASSIGN = 63, PLUS = 64, KEYOR = 65, KEYAND = 66, KEYXOR = 67, 
    IMPLIES = 68, RANGE = 69, DOT = 70, AT = 71, SLASH = 72, UNDERSCORE = 73, 
    DHAT = 74, HAT = 75, MINUS = 76, NOT = 77, PIPE = 78, ID = 79, WS = 80, 
    ERRCHAR = 81
  };

  enum {
    RuleExpressionInOclCS = 0, RuleOclExpressionCS = 1, RuleParentedExpCS = 2, 
    RuleVariableExpCS = 3, RuleSimpleNameCS = 4, RuleRestrictedKeywordCS = 5, 
    RuleUnreservedSimpleNameCS = 6, RulePathNameCS = 7, RuleLiteralExpCS = 8, 
    RuleEnumLiteralExpCS = 9, RuleCollectionLiteralExpCS = 10, RuleCollectionTypeIdentifierCS = 11, 
    RuleCollectionLiteralPartsCS = 12, RuleCollectionRangeCS = 13, RulePrefixedExp = 14, 
    RulePrimitiveLiteralExpCS = 15, RuleTupleLiteralExpCS = 16, RuleUnlimitedNaturalLiteralExpCS = 17, 
    RuleIntegerLiteralExpCS = 18, RuleRealLiteralExpCS = 19, RuleStringLiteralExpCS = 20, 
    RuleBooleanLiteralExpCS = 21, RuleTypeLiteralExpCS = 22, RuleIteratorExpCS = 23, 
    RuleIterateExpCS = 24, RuleVariableDeclarationCS = 25, RuleTypeCS = 26, 
    RulePrimitiveTypeCS = 27, RuleOclTypeCS = 28, RuleCollectionTypeCS = 29, 
    RuleTupleTypeCS = 30, RuleOperationCallExpCS_A = 31, RuleOperationCallExpCS_B = 32, 
    RulePropertyCallExpCS_A = 33, RulePropertyCallExpCS_B = 34, RuleAssociationClassCallExpCS_A = 35, 
    RuleAssociationClassCallExpCS_B = 36, RuleIsMarkedPreCS = 37, RuleLetExpCS = 38, 
    RuleOclMessageExpCS = 39, RuleOclMessageArgumentsCS = 40, RuleIfExpCS = 41, 
    RuleNullLiteralExpCS = 42, RuleInvalidLiteralExpCS = 43, RuleUnaryLiteralExpCS = 44, 
    RuleBinaryLiteralExpCS = 45, RulePackageDeclarationCS = 46, RuleContextDeclarationCS = 47, 
    RuleClassifierContextDeclCS = 48, RuleOperationContextDeclCS = 49, RulePropertyContextDeclCS = 50, 
    RuleDefExpressionCS = 51, RuleInvOrDefCS = 52, RuleInitOrDerValueListCS = 53, 
    RuleInitOrDerValueCS = 54, RulePrePostOrBodyDeclCS = 55, RulePrePostBodyExpCS = 56, 
    RuleOperationCS = 57
  };

  explicit OclParser(antlr4::TokenStream *input);

  OclParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~OclParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ExpressionInOclCSContext;
  class OclExpressionCSContext;
  class ParentedExpCSContext;
  class VariableExpCSContext;
  class SimpleNameCSContext;
  class RestrictedKeywordCSContext;
  class UnreservedSimpleNameCSContext;
  class PathNameCSContext;
  class LiteralExpCSContext;
  class EnumLiteralExpCSContext;
  class CollectionLiteralExpCSContext;
  class CollectionTypeIdentifierCSContext;
  class CollectionLiteralPartsCSContext;
  class CollectionRangeCSContext;
  class PrefixedExpContext;
  class PrimitiveLiteralExpCSContext;
  class TupleLiteralExpCSContext;
  class UnlimitedNaturalLiteralExpCSContext;
  class IntegerLiteralExpCSContext;
  class RealLiteralExpCSContext;
  class StringLiteralExpCSContext;
  class BooleanLiteralExpCSContext;
  class TypeLiteralExpCSContext;
  class IteratorExpCSContext;
  class IterateExpCSContext;
  class VariableDeclarationCSContext;
  class TypeCSContext;
  class PrimitiveTypeCSContext;
  class OclTypeCSContext;
  class CollectionTypeCSContext;
  class TupleTypeCSContext;
  class OperationCallExpCS_AContext;
  class OperationCallExpCS_BContext;
  class PropertyCallExpCS_AContext;
  class PropertyCallExpCS_BContext;
  class AssociationClassCallExpCS_AContext;
  class AssociationClassCallExpCS_BContext;
  class IsMarkedPreCSContext;
  class LetExpCSContext;
  class OclMessageExpCSContext;
  class OclMessageArgumentsCSContext;
  class IfExpCSContext;
  class NullLiteralExpCSContext;
  class InvalidLiteralExpCSContext;
  class UnaryLiteralExpCSContext;
  class BinaryLiteralExpCSContext;
  class PackageDeclarationCSContext;
  class ContextDeclarationCSContext;
  class ClassifierContextDeclCSContext;
  class OperationContextDeclCSContext;
  class PropertyContextDeclCSContext;
  class DefExpressionCSContext;
  class InvOrDefCSContext;
  class InitOrDerValueListCSContext;
  class InitOrDerValueCSContext;
  class PrePostOrBodyDeclCSContext;
  class PrePostBodyExpCSContext;
  class OperationCSContext; 

  class  ExpressionInOclCSContext : public antlr4::ParserRuleContext {
  public:
    ExpressionInOclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OclExpressionCSContext *oclExpressionCS();
    PackageDeclarationCSContext *packageDeclarationCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionInOclCSContext* expressionInOclCS();

  class  OclExpressionCSContext : public antlr4::ParserRuleContext {
  public:
    OclExpressionCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrefixedExpContext *prefixedExp();
    OperationCallExpCS_BContext *operationCallExpCS_B();
    PropertyCallExpCS_BContext *propertyCallExpCS_B();
    AssociationClassCallExpCS_BContext *associationClassCallExpCS_B();
    ParentedExpCSContext *parentedExpCS();
    VariableExpCSContext *variableExpCS();
    LiteralExpCSContext *literalExpCS();
    LetExpCSContext *letExpCS();
    IfExpCSContext *ifExpCS();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    BinaryLiteralExpCSContext *binaryLiteralExpCS();
    OperationCallExpCS_AContext *operationCallExpCS_A();
    PropertyCallExpCS_AContext *propertyCallExpCS_A();
    AssociationClassCallExpCS_AContext *associationClassCallExpCS_A();
    IteratorExpCSContext *iteratorExpCS();
    IterateExpCSContext *iterateExpCS();
    OclMessageExpCSContext *oclMessageExpCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclExpressionCSContext* oclExpressionCS();
  OclExpressionCSContext* oclExpressionCS(int precedence);
  class  ParentedExpCSContext : public antlr4::ParserRuleContext {
  public:
    ParentedExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    OclExpressionCSContext *oclExpressionCS();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParentedExpCSContext* parentedExpCS();

  class  VariableExpCSContext : public antlr4::ParserRuleContext {
  public:
    VariableExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELF();
    SimpleNameCSContext *simpleNameCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableExpCSContext* variableExpCS();

  class  SimpleNameCSContext : public antlr4::ParserRuleContext {
  public:
    SimpleNameCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleNameCSContext* simpleNameCS();

  class  RestrictedKeywordCSContext : public antlr4::ParserRuleContext {
  public:
    RestrictedKeywordCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionTypeIdentifierCSContext *collectionTypeIdentifierCS();
    PrimitiveTypeCSContext *primitiveTypeCS();
    OclTypeCSContext *oclTypeCS();
    antlr4::tree::TerminalNode *TUPLE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RestrictedKeywordCSContext* restrictedKeywordCS();

  class  UnreservedSimpleNameCSContext : public antlr4::ParserRuleContext {
  public:
    UnreservedSimpleNameCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    RestrictedKeywordCSContext *restrictedKeywordCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnreservedSimpleNameCSContext* unreservedSimpleNameCS();

  class  PathNameCSContext : public antlr4::ParserRuleContext {
  public:
    PathNameCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    UnreservedSimpleNameCSContext *unreservedSimpleNameCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathNameCSContext* pathNameCS();
  PathNameCSContext* pathNameCS(int precedence);
  class  LiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    LiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnumLiteralExpCSContext *enumLiteralExpCS();
    CollectionLiteralExpCSContext *collectionLiteralExpCS();
    TupleLiteralExpCSContext *tupleLiteralExpCS();
    PrimitiveLiteralExpCSContext *primitiveLiteralExpCS();
    TypeLiteralExpCSContext *typeLiteralExpCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralExpCSContext* literalExpCS();

  class  EnumLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    EnumLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    SimpleNameCSContext *simpleNameCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumLiteralExpCSContext* enumLiteralExpCS();

  class  CollectionLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    CollectionLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionTypeIdentifierCSContext *collectionTypeIdentifierCS();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    CollectionLiteralPartsCSContext *collectionLiteralPartsCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionLiteralExpCSContext* collectionLiteralExpCS();

  class  CollectionTypeIdentifierCSContext : public antlr4::ParserRuleContext {
  public:
    CollectionTypeIdentifierCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *BAG();
    antlr4::tree::TerminalNode *SEQUENCE();
    antlr4::tree::TerminalNode *COLLECTION();
    antlr4::tree::TerminalNode *ORDEREDSET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionTypeIdentifierCSContext* collectionTypeIdentifierCS();

  class  CollectionLiteralPartsCSContext : public antlr4::ParserRuleContext {
  public:
    CollectionLiteralPartsCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CollectionRangeCSContext *> collectionRangeCS();
    CollectionRangeCSContext* collectionRangeCS(size_t i);
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionLiteralPartsCSContext* collectionLiteralPartsCS();

  class  CollectionRangeCSContext : public antlr4::ParserRuleContext {
  public:
    CollectionRangeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *SEQRANGE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionRangeCSContext* collectionRangeCS();

  class  PrefixedExpContext : public antlr4::ParserRuleContext {
  public:
    PrefixedExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryLiteralExpCSContext *unaryLiteralExpCS();
    OclExpressionCSContext *oclExpressionCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrefixedExpContext* prefixedExp();

  class  PrimitiveLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerLiteralExpCSContext *integerLiteralExpCS();
    RealLiteralExpCSContext *realLiteralExpCS();
    StringLiteralExpCSContext *stringLiteralExpCS();
    BooleanLiteralExpCSContext *booleanLiteralExpCS();
    UnlimitedNaturalLiteralExpCSContext *unlimitedNaturalLiteralExpCS();
    NullLiteralExpCSContext *nullLiteralExpCS();
    InvalidLiteralExpCSContext *invalidLiteralExpCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveLiteralExpCSContext* primitiveLiteralExpCS();

  class  TupleLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    TupleLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TUPLE();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleLiteralExpCSContext* tupleLiteralExpCS();

  class  UnlimitedNaturalLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    UnlimitedNaturalLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *STAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnlimitedNaturalLiteralExpCSContext* unlimitedNaturalLiteralExpCS();

  class  IntegerLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    IntegerLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntegerLiteralExpCSContext* integerLiteralExpCS();

  class  RealLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    RealLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RealLiteralExpCSContext* realLiteralExpCS();

  class  StringLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    StringLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLiteralExpCSContext* stringLiteralExpCS();

  class  BooleanLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    BooleanLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanLiteralExpCSContext* booleanLiteralExpCS();

  class  TypeLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    TypeLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeCSContext *typeCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeLiteralExpCSContext* typeLiteralExpCS();

  class  IteratorExpCSContext : public antlr4::ParserRuleContext {
  public:
    IteratorExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RARROW();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    antlr4::tree::TerminalNode *PIPE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IteratorExpCSContext* iteratorExpCS();

  class  IterateExpCSContext : public antlr4::ParserRuleContext {
  public:
    IterateExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RARROW();
    antlr4::tree::TerminalNode *ITERATE();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    antlr4::tree::TerminalNode *PIPE();
    OclExpressionCSContext *oclExpressionCS();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IterateExpCSContext* iterateExpCS();

  class  VariableDeclarationCSContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *COLON();
    TypeCSContext *typeCS();
    antlr4::tree::TerminalNode *ASSIGN();
    OclExpressionCSContext *oclExpressionCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationCSContext* variableDeclarationCS();

  class  TypeCSContext : public antlr4::ParserRuleContext {
  public:
    TypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathNameCSContext *pathNameCS();
    CollectionTypeCSContext *collectionTypeCS();
    TupleTypeCSContext *tupleTypeCS();
    PrimitiveTypeCSContext *primitiveTypeCS();
    OclTypeCSContext *oclTypeCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeCSContext* typeCS();

  class  PrimitiveTypeCSContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OCLBOOLEAN();
    antlr4::tree::TerminalNode *OCLINTEGER();
    antlr4::tree::TerminalNode *OCLREAL();
    antlr4::tree::TerminalNode *OCLSTRING();
    antlr4::tree::TerminalNode *OCLUNLIMITEDNAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveTypeCSContext* primitiveTypeCS();

  class  OclTypeCSContext : public antlr4::ParserRuleContext {
  public:
    OclTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OCLANY();
    antlr4::tree::TerminalNode *OCLINVALID();
    antlr4::tree::TerminalNode *OCLMESSAGE();
    antlr4::tree::TerminalNode *OCLVOID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclTypeCSContext* oclTypeCS();

  class  CollectionTypeCSContext : public antlr4::ParserRuleContext {
  public:
    CollectionTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionTypeIdentifierCSContext *collectionTypeIdentifierCS();
    antlr4::tree::TerminalNode *LPAREN();
    TypeCSContext *typeCS();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionTypeCSContext* collectionTypeCS();

  class  TupleTypeCSContext : public antlr4::ParserRuleContext {
  public:
    TupleTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TUPLE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleTypeCSContext* tupleTypeCS();

  class  OperationCallExpCS_AContext : public antlr4::ParserRuleContext {
  public:
    OperationCallExpCS_AContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RARROW();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *DOT();
    IsMarkedPreCSContext *isMarkedPreCS();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationCallExpCS_AContext* operationCallExpCS_A();

  class  OperationCallExpCS_BContext : public antlr4::ParserRuleContext {
  public:
    OperationCallExpCS_BContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    IsMarkedPreCSContext *isMarkedPreCS();
    PathNameCSContext *pathNameCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationCallExpCS_BContext* operationCallExpCS_B();

  class  PropertyCallExpCS_AContext : public antlr4::ParserRuleContext {
  public:
    PropertyCallExpCS_AContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    SimpleNameCSContext *simpleNameCS();
    IsMarkedPreCSContext *isMarkedPreCS();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyCallExpCS_AContext* propertyCallExpCS_A();

  class  PropertyCallExpCS_BContext : public antlr4::ParserRuleContext {
  public:
    PropertyCallExpCS_BContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    IsMarkedPreCSContext *isMarkedPreCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyCallExpCS_BContext* propertyCallExpCS_B();

  class  AssociationClassCallExpCS_AContext : public antlr4::ParserRuleContext {
  public:
    AssociationClassCallExpCS_AContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    IsMarkedPreCSContext *isMarkedPreCS();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssociationClassCallExpCS_AContext* associationClassCallExpCS_A();

  class  AssociationClassCallExpCS_BContext : public antlr4::ParserRuleContext {
  public:
    AssociationClassCallExpCS_BContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    IsMarkedPreCSContext *isMarkedPreCS();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssociationClassCallExpCS_BContext* associationClassCallExpCS_B();

  class  IsMarkedPreCSContext : public antlr4::ParserRuleContext {
  public:
    IsMarkedPreCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *PRE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsMarkedPreCSContext* isMarkedPreCS();

  class  LetExpCSContext : public antlr4::ParserRuleContext {
  public:
    LetExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    antlr4::tree::TerminalNode *IN();
    OclExpressionCSContext *oclExpressionCS();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetExpCSContext* letExpCS();

  class  OclMessageExpCSContext : public antlr4::ParserRuleContext {
  public:
    OclMessageExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DHAT();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    OclMessageArgumentsCSContext *oclMessageArgumentsCS();
    antlr4::tree::TerminalNode *HAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclMessageExpCSContext* oclMessageExpCS();

  class  OclMessageArgumentsCSContext : public antlr4::ParserRuleContext {
  public:
    OclMessageArgumentsCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUESTION();
    antlr4::tree::TerminalNode* QUESTION(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<TypeCSContext *> typeCS();
    TypeCSContext* typeCS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclMessageArgumentsCSContext* oclMessageArgumentsCS();

  class  IfExpCSContext : public antlr4::ParserRuleContext {
  public:
    IfExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *ENDIF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfExpCSContext* ifExpCS();

  class  NullLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    NullLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULLEXP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NullLiteralExpCSContext* nullLiteralExpCS();

  class  InvalidLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    InvalidLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INVALID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvalidLiteralExpCSContext* invalidLiteralExpCS();

  class  UnaryLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    UnaryLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryLiteralExpCSContext* unaryLiteralExpCS();

  class  BinaryLiteralExpCSContext : public antlr4::ParserRuleContext {
  public:
    BinaryLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LTE();
    antlr4::tree::TerminalNode *GTE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *INEQUAL();
    antlr4::tree::TerminalNode *KEYAND();
    antlr4::tree::TerminalNode *KEYOR();
    antlr4::tree::TerminalNode *KEYXOR();
    antlr4::tree::TerminalNode *IMPLIES();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinaryLiteralExpCSContext* binaryLiteralExpCS();

  class  PackageDeclarationCSContext : public antlr4::ParserRuleContext {
  public:
    PackageDeclarationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *ENDPACKAGE();
    std::vector<ContextDeclarationCSContext *> contextDeclarationCS();
    ContextDeclarationCSContext* contextDeclarationCS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageDeclarationCSContext* packageDeclarationCS();

  class  ContextDeclarationCSContext : public antlr4::ParserRuleContext {
  public:
    ContextDeclarationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyContextDeclCSContext *propertyContextDeclCS();
    ClassifierContextDeclCSContext *classifierContextDeclCS();
    OperationContextDeclCSContext *operationContextDeclCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContextDeclarationCSContext* contextDeclarationCS();

  class  ClassifierContextDeclCSContext : public antlr4::ParserRuleContext {
  public:
    ClassifierContextDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTEXT();
    PathNameCSContext *pathNameCS();
    InvOrDefCSContext *invOrDefCS();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *COLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassifierContextDeclCSContext* classifierContextDeclCS();

  class  OperationContextDeclCSContext : public antlr4::ParserRuleContext {
  public:
    OperationContextDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTEXT();
    OperationCSContext *operationCS();
    PrePostOrBodyDeclCSContext *prePostOrBodyDeclCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationContextDeclCSContext* operationContextDeclCS();

  class  PropertyContextDeclCSContext : public antlr4::ParserRuleContext {
  public:
    PropertyContextDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTEXT();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *COLON();
    TypeCSContext *typeCS();
    InitOrDerValueListCSContext *initOrDerValueListCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyContextDeclCSContext* propertyContextDeclCS();

  class  DefExpressionCSContext : public antlr4::ParserRuleContext {
  public:
    DefExpressionCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationCSContext *variableDeclarationCS();
    antlr4::tree::TerminalNode *ASSIGN();
    OclExpressionCSContext *oclExpressionCS();
    OperationCSContext *operationCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefExpressionCSContext* defExpressionCS();

  class  InvOrDefCSContext : public antlr4::ParserRuleContext {
  public:
    InvOrDefCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INV();
    antlr4::tree::TerminalNode *COLON();
    OclExpressionCSContext *oclExpressionCS();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *DEF();
    DefExpressionCSContext *defExpressionCS();
    antlr4::tree::TerminalNode *STATIC();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvOrDefCSContext* invOrDefCS();

  class  InitOrDerValueListCSContext : public antlr4::ParserRuleContext {
  public:
    InitOrDerValueListCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InitOrDerValueCSContext *> initOrDerValueCS();
    InitOrDerValueCSContext* initOrDerValueCS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitOrDerValueListCSContext* initOrDerValueListCS();

  class  InitOrDerValueCSContext : public antlr4::ParserRuleContext {
  public:
    InitOrDerValueCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    OclExpressionCSContext *oclExpressionCS();
    antlr4::tree::TerminalNode *INIT();
    antlr4::tree::TerminalNode *DERIVE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitOrDerValueCSContext* initOrDerValueCS();

  class  PrePostOrBodyDeclCSContext : public antlr4::ParserRuleContext {
  public:
    PrePostOrBodyDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrePostBodyExpCSContext *> prePostBodyExpCS();
    PrePostBodyExpCSContext* prePostBodyExpCS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrePostOrBodyDeclCSContext* prePostOrBodyDeclCS();

  class  PrePostBodyExpCSContext : public antlr4::ParserRuleContext {
  public:
    PrePostBodyExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    OclExpressionCSContext *oclExpressionCS();
    antlr4::tree::TerminalNode *PRE();
    antlr4::tree::TerminalNode *POST();
    antlr4::tree::TerminalNode *BODY();
    SimpleNameCSContext *simpleNameCS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrePostBodyExpCSContext* prePostBodyExpCS();

  class  OperationCSContext : public antlr4::ParserRuleContext {
  public:
    OperationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COLON();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    TypeCSContext *typeCS();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationCSContext* operationCS();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool oclExpressionCSSempred(OclExpressionCSContext *_localctx, size_t predicateIndex);
  bool pathNameCSSempred(PathNameCSContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace OclCS
