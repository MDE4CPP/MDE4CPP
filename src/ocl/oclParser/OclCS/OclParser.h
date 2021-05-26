
  #include "CSTNode.h"


// Generated from OclParser.g4 by ANTLR 4.9

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
    OCLANY = 34, OCLINVALID = 35, OCLMESSAGE = 36, OCLVOID = 37, OCLSTATE = 38, 
    INT = 39, REAL = 40, BOOL = 41, STRING_LITERAL = 42, COLON = 43, COLONCOLON = 44, 
    COMMA = 45, SEMI = 46, LPAREN = 47, RPAREN = 48, LBRACE = 49, RBRACE = 50, 
    LBRACK = 51, RBRACK = 52, RARROW = 53, LT = 54, GT = 55, LTE = 56, GTE = 57, 
    ASSIGN = 58, INEQUAL = 59, QUESTION = 60, STAR = 61, PLUS_ASSIGN = 62, 
    PLUS = 63, KEYOR = 64, KEYAND = 65, IMPLIES = 66, RANGE = 67, DOT = 68, 
    AT = 69, SLASH = 70, UNDERSCORE = 71, DHAT = 72, HAT = 73, MINUS = 74, 
    NOT = 75, PIPE = 76, ID = 77, WS = 78, ERRCHAR = 79
  };

  enum {
    RuleExpressionInOclCS = 0, RuleOclExpressionCS = 1, RuleVariableExpCS = 2, 
    RuleSimpleNameCS = 3, RuleRestrictedKeywordCS = 4, RuleUnreservedSimpleNameCS = 5, 
    RulePathNameCS = 6, RuleLiteralExpCS = 7, RuleEnumLiteralExpCS = 8, 
    RuleCollectionLiteralExpCS = 9, RuleCollectionTypeIdentifierCS = 10, 
    RuleCollectionLiteralPartsCS = 11, RuleCollectionLiteralPartCS = 12, 
    RuleCollectionRangeCS = 13, RulePrefixedExp = 14, RuleInfixedExpCS = 15, 
    RulePrimitiveLiteralExpCS = 16, RuleTupleLiteralExpCS = 17, RuleUnlimitedNaturalLiteralExpCS = 18, 
    RuleIntegerLiteralExpCS = 19, RuleRealLiteralExpCS = 20, RuleStringLiteralExpCS = 21, 
    RuleBooleanLiteralExpCS = 22, RuleTypeLiteralExpCS = 23, RuleIteratorExpCS = 24, 
    RuleIterateExpCS = 25, RuleVariableDeclarationCS = 26, RuleTypeCS = 27, 
    RulePrimitiveTypeCS = 28, RuleOclTypeCS = 29, RuleCollectionTypeCS = 30, 
    RuleTupleTypeCS = 31, RuleVariableDeclarationListCS = 32, RuleOperationCallExpCS_A = 33, 
    RuleOperationCallExpCS_B = 34, RulePropertyCallExpCS_A = 35, RulePropertyCallExpCS_B = 36, 
    RuleAssociationClassCallExpCS_A = 37, RuleAssociationClassCallExpCS_B = 38, 
    RuleIsMarkedPreCS = 39, RuleArgumentsCS = 40, RuleLetExpCS = 41, RuleLetExpSubCS = 42, 
    RuleOclMessageExpCS = 43, RuleOclMessageArgumentsCS = 44, RuleOclMessageArgCS = 45, 
    RuleIfExpCS = 46, RuleNullLiteralExpCS = 47, RuleInvalidLiteralExpCS = 48, 
    RuleUnaryLiteralExpCS = 49, RuleBinaryLiteralExpCS = 50, RulePackageDeclarationCS = 51, 
    RuleContextDeclarationCS = 52, RuleClassifierContextDeclCS = 53, RuleOperationContextDeclCS = 54, 
    RulePropertyContextDeclCS = 55, RuleDefExpressionCS = 56, RuleInvOrDefCS = 57, 
    RuleInitOrDerValueCS = 58, RulePrePostOrBodyDeclCS = 59, RuleOperationCS = 60, 
    RuleParametersCS = 61
  };

  explicit OclParser(antlr4::TokenStream *input);
  ~OclParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ExpressionInOclCSContext;
  class OclExpressionCSContext;
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
  class CollectionLiteralPartCSContext;
  class CollectionRangeCSContext;
  class PrefixedExpContext;
  class InfixedExpCSContext;
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
  class VariableDeclarationListCSContext;
  class OperationCallExpCS_AContext;
  class OperationCallExpCS_BContext;
  class PropertyCallExpCS_AContext;
  class PropertyCallExpCS_BContext;
  class AssociationClassCallExpCS_AContext;
  class AssociationClassCallExpCS_BContext;
  class IsMarkedPreCSContext;
  class ArgumentsCSContext;
  class LetExpCSContext;
  class LetExpSubCSContext;
  class OclMessageExpCSContext;
  class OclMessageArgumentsCSContext;
  class OclMessageArgCSContext;
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
  class InitOrDerValueCSContext;
  class PrePostOrBodyDeclCSContext;
  class OperationCSContext;
  class ParametersCSContext; 

  class  ExpressionInOclCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    ExpressionInOclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionInOclCSContext* expressionInOclCS();

  class  OclExpressionCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OclExpressionCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrefixedExpContext *prefixedExp();
    OperationCallExpCS_BContext *operationCallExpCS_B();
    PropertyCallExpCS_BContext *propertyCallExpCS_B();
    AssociationClassCallExpCS_BContext *associationClassCallExpCS_B();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    VariableExpCSContext *variableExpCS();
    LiteralExpCSContext *literalExpCS();
    LetExpCSContext *letExpCS();
    IfExpCSContext *ifExpCS();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    OperationCallExpCS_AContext *operationCallExpCS_A();
    PropertyCallExpCS_AContext *propertyCallExpCS_A();
    AssociationClassCallExpCS_AContext *associationClassCallExpCS_A();
    IteratorExpCSContext *iteratorExpCS();
    IterateExpCSContext *iterateExpCS();
    InfixedExpCSContext *infixedExpCS();
    OclMessageExpCSContext *oclMessageExpCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclExpressionCSContext* oclExpressionCS();
  OclExpressionCSContext* oclExpressionCS(int precedence);
  class  VariableExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    VariableExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELF();
    SimpleNameCSContext *simpleNameCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableExpCSContext* variableExpCS();

  class  SimpleNameCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    SimpleNameCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleNameCSContext* simpleNameCS();

  class  RestrictedKeywordCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    RestrictedKeywordCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionTypeIdentifierCSContext *collectionTypeIdentifierCS();
    PrimitiveTypeCSContext *primitiveTypeCS();
    OclTypeCSContext *oclTypeCS();
    antlr4::tree::TerminalNode *TUPLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RestrictedKeywordCSContext* restrictedKeywordCS();

  class  UnreservedSimpleNameCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    UnreservedSimpleNameCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    RestrictedKeywordCSContext *restrictedKeywordCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnreservedSimpleNameCSContext* unreservedSimpleNameCS();

  class  PathNameCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PathNameCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    UnreservedSimpleNameCSContext *unreservedSimpleNameCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathNameCSContext* pathNameCS();
  PathNameCSContext* pathNameCS(int precedence);
  class  LiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    LiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnumLiteralExpCSContext *enumLiteralExpCS();
    CollectionLiteralExpCSContext *collectionLiteralExpCS();
    TupleLiteralExpCSContext *tupleLiteralExpCS();
    PrimitiveLiteralExpCSContext *primitiveLiteralExpCS();
    TypeLiteralExpCSContext *typeLiteralExpCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralExpCSContext* literalExpCS();

  class  EnumLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    EnumLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    SimpleNameCSContext *simpleNameCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumLiteralExpCSContext* enumLiteralExpCS();

  class  CollectionLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    CollectionLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionTypeIdentifierCSContext *collectionTypeIdentifierCS();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    CollectionLiteralPartsCSContext *collectionLiteralPartsCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionLiteralExpCSContext* collectionLiteralExpCS();

  class  CollectionTypeIdentifierCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    CollectionTypeIdentifierCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *BAG();
    antlr4::tree::TerminalNode *SEQUENCE();
    antlr4::tree::TerminalNode *COLLECTION();
    antlr4::tree::TerminalNode *ORDEREDSET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionTypeIdentifierCSContext* collectionTypeIdentifierCS();

  class  CollectionLiteralPartsCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    CollectionLiteralPartsCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionLiteralPartCSContext *collectionLiteralPartCS();
    antlr4::tree::TerminalNode *COMMA();
    CollectionLiteralPartsCSContext *collectionLiteralPartsCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionLiteralPartsCSContext* collectionLiteralPartsCS();

  class  CollectionLiteralPartCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    CollectionLiteralPartCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionRangeCSContext *collectionRangeCS();
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionLiteralPartCSContext* collectionLiteralPartCS();

  class  CollectionRangeCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    CollectionRangeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *RANGE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionRangeCSContext* collectionRangeCS();

  class  PrefixedExpContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PrefixedExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryLiteralExpCSContext *unaryLiteralExpCS();
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrefixedExpContext* prefixedExp();

  class  InfixedExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    InfixedExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BinaryLiteralExpCSContext *binaryLiteralExpCS();
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InfixedExpCSContext* infixedExpCS();

  class  PrimitiveLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveLiteralExpCSContext* primitiveLiteralExpCS();

  class  TupleLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    TupleLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TUPLE();
    antlr4::tree::TerminalNode *LBRACE();
    VariableDeclarationListCSContext *variableDeclarationListCS();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleLiteralExpCSContext* tupleLiteralExpCS();

  class  UnlimitedNaturalLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    UnlimitedNaturalLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *STAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnlimitedNaturalLiteralExpCSContext* unlimitedNaturalLiteralExpCS();

  class  IntegerLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    IntegerLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntegerLiteralExpCSContext* integerLiteralExpCS();

  class  RealLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    RealLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RealLiteralExpCSContext* realLiteralExpCS();

  class  StringLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    StringLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLiteralExpCSContext* stringLiteralExpCS();

  class  BooleanLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    BooleanLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanLiteralExpCSContext* booleanLiteralExpCS();

  class  TypeLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    TypeLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeCSContext *typeCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeLiteralExpCSContext* typeLiteralExpCS();

  class  IteratorExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    IteratorExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RARROW();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    OclExpressionCSContext *oclExpressionCS();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<VariableDeclarationCSContext *> variableDeclarationCS();
    VariableDeclarationCSContext* variableDeclarationCS(size_t i);
    antlr4::tree::TerminalNode *PIPE();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *DOT();
    ArgumentsCSContext *argumentsCS();
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IteratorExpCSContext* iteratorExpCS();

  class  IterateExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IterateExpCSContext* iterateExpCS();

  class  VariableDeclarationCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    VariableDeclarationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *COLON();
    TypeCSContext *typeCS();
    antlr4::tree::TerminalNode *ASSIGN();
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationCSContext* variableDeclarationCS();

  class  TypeCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    TypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathNameCSContext *pathNameCS();
    CollectionTypeCSContext *collectionTypeCS();
    TupleTypeCSContext *tupleTypeCS();
    PrimitiveTypeCSContext *primitiveTypeCS();
    OclTypeCSContext *oclTypeCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeCSContext* typeCS();

  class  PrimitiveTypeCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PrimitiveTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OCLBOOLEAN();
    antlr4::tree::TerminalNode *OCLINTEGER();
    antlr4::tree::TerminalNode *OCLREAL();
    antlr4::tree::TerminalNode *OCLSTRING();
    antlr4::tree::TerminalNode *OCLUNLIMITEDNAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveTypeCSContext* primitiveTypeCS();

  class  OclTypeCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OclTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OCLANY();
    antlr4::tree::TerminalNode *OCLINVALID();
    antlr4::tree::TerminalNode *OCLMESSAGE();
    antlr4::tree::TerminalNode *OCLVOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclTypeCSContext* oclTypeCS();

  class  CollectionTypeCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    CollectionTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CollectionTypeIdentifierCSContext *collectionTypeIdentifierCS();
    antlr4::tree::TerminalNode *LPAREN();
    TypeCSContext *typeCS();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CollectionTypeCSContext* collectionTypeCS();

  class  TupleTypeCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    TupleTypeCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TUPLE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    VariableDeclarationListCSContext *variableDeclarationListCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TupleTypeCSContext* tupleTypeCS();

  class  VariableDeclarationListCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    VariableDeclarationListCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationCSContext *variableDeclarationCS();
    antlr4::tree::TerminalNode *COMMA();
    VariableDeclarationListCSContext *variableDeclarationListCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationListCSContext* variableDeclarationListCS();

  class  OperationCallExpCS_AContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OperationCallExpCS_AContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RARROW();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgumentsCSContext *argumentsCS();
    antlr4::tree::TerminalNode *DOT();
    IsMarkedPreCSContext *isMarkedPreCS();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationCallExpCS_AContext* operationCallExpCS_A();

  class  OperationCallExpCS_BContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OperationCallExpCS_BContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgumentsCSContext *argumentsCS();
    IsMarkedPreCSContext *isMarkedPreCS();
    PathNameCSContext *pathNameCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationCallExpCS_BContext* operationCallExpCS_B();

  class  PropertyCallExpCS_AContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PropertyCallExpCS_AContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    SimpleNameCSContext *simpleNameCS();
    IsMarkedPreCSContext *isMarkedPreCS();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyCallExpCS_AContext* propertyCallExpCS_A();

  class  PropertyCallExpCS_BContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PropertyCallExpCS_BContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    IsMarkedPreCSContext *isMarkedPreCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyCallExpCS_BContext* propertyCallExpCS_B();

  class  AssociationClassCallExpCS_AContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    AssociationClassCallExpCS_AContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LBRACE();
    ArgumentsCSContext *argumentsCS();
    antlr4::tree::TerminalNode *RBRACE();
    IsMarkedPreCSContext *isMarkedPreCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssociationClassCallExpCS_AContext* associationClassCallExpCS_A();

  class  AssociationClassCallExpCS_BContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    AssociationClassCallExpCS_BContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LBRACE();
    ArgumentsCSContext *argumentsCS();
    antlr4::tree::TerminalNode *RBRACE();
    IsMarkedPreCSContext *isMarkedPreCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssociationClassCallExpCS_BContext* associationClassCallExpCS_B();

  class  IsMarkedPreCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    IsMarkedPreCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *PRE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsMarkedPreCSContext* isMarkedPreCS();

  class  ArgumentsCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    ArgumentsCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OclExpressionCSContext *oclExpressionCS();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsCSContext *argumentsCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsCSContext* argumentsCS();

  class  LetExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    LetExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    VariableDeclarationCSContext *variableDeclarationCS();
    LetExpSubCSContext *letExpSubCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetExpCSContext* letExpCS();

  class  LetExpSubCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    LetExpSubCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    VariableDeclarationCSContext *variableDeclarationCS();
    LetExpSubCSContext *letExpSubCS();
    antlr4::tree::TerminalNode *IN();
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetExpSubCSContext* letExpSubCS();

  class  OclMessageExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OclMessageExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DHAT();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    OclMessageArgumentsCSContext *oclMessageArgumentsCS();
    antlr4::tree::TerminalNode *HAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclMessageExpCSContext* oclMessageExpCS();

  class  OclMessageArgumentsCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OclMessageArgumentsCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OclMessageArgCSContext *oclMessageArgCS();
    antlr4::tree::TerminalNode *COMMA();
    OclMessageArgumentsCSContext *oclMessageArgumentsCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclMessageArgumentsCSContext* oclMessageArgumentsCS();

  class  OclMessageArgCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OclMessageArgCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUESTION();
    antlr4::tree::TerminalNode *COLON();
    TypeCSContext *typeCS();
    OclExpressionCSContext *oclExpressionCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OclMessageArgCSContext* oclMessageArgCS();

  class  IfExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    IfExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<OclExpressionCSContext *> oclExpressionCS();
    OclExpressionCSContext* oclExpressionCS(size_t i);
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *ENDIF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfExpCSContext* ifExpCS();

  class  NullLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    NullLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULLEXP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NullLiteralExpCSContext* nullLiteralExpCS();

  class  InvalidLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    InvalidLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INVALID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvalidLiteralExpCSContext* invalidLiteralExpCS();

  class  UnaryLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    UnaryLiteralExpCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryLiteralExpCSContext* unaryLiteralExpCS();

  class  BinaryLiteralExpCSContext : public antlr4::ParserRuleContext, public CSTNode {
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
    antlr4::tree::TerminalNode *IMPLIES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinaryLiteralExpCSContext* binaryLiteralExpCS();

  class  PackageDeclarationCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PackageDeclarationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *ENDPACKAGE();
    std::vector<ContextDeclarationCSContext *> contextDeclarationCS();
    ContextDeclarationCSContext* contextDeclarationCS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageDeclarationCSContext* packageDeclarationCS();

  class  ContextDeclarationCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    ContextDeclarationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyContextDeclCSContext *propertyContextDeclCS();
    ClassifierContextDeclCSContext *classifierContextDeclCS();
    OperationContextDeclCSContext *operationContextDeclCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContextDeclarationCSContext* contextDeclarationCS();

  class  ClassifierContextDeclCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    ClassifierContextDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTEXT();
    PathNameCSContext *pathNameCS();
    InvOrDefCSContext *invOrDefCS();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassifierContextDeclCSContext* classifierContextDeclCS();

  class  OperationContextDeclCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OperationContextDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTEXT();
    OperationCSContext *operationCS();
    PrePostOrBodyDeclCSContext *prePostOrBodyDeclCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationContextDeclCSContext* operationContextDeclCS();

  class  PropertyContextDeclCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PropertyContextDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTEXT();
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *COLON();
    TypeCSContext *typeCS();
    InitOrDerValueCSContext *initOrDerValueCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyContextDeclCSContext* propertyContextDeclCS();

  class  DefExpressionCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    DefExpressionCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationCSContext *variableDeclarationCS();
    antlr4::tree::TerminalNode *ASSIGN();
    OclExpressionCSContext *oclExpressionCS();
    OperationCSContext *operationCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefExpressionCSContext* defExpressionCS();

  class  InvOrDefCSContext : public antlr4::ParserRuleContext, public CSTNode {
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InvOrDefCSContext* invOrDefCS();

  class  InitOrDerValueCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    InitOrDerValueCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INIT();
    antlr4::tree::TerminalNode *COLON();
    OclExpressionCSContext *oclExpressionCS();
    InitOrDerValueCSContext *initOrDerValueCS();
    antlr4::tree::TerminalNode *DERIVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitOrDerValueCSContext* initOrDerValueCS();

  class  PrePostOrBodyDeclCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    PrePostOrBodyDeclCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRE();
    antlr4::tree::TerminalNode *COLON();
    OclExpressionCSContext *oclExpressionCS();
    SimpleNameCSContext *simpleNameCS();
    PrePostOrBodyDeclCSContext *prePostOrBodyDeclCS();
    antlr4::tree::TerminalNode *POST();
    antlr4::tree::TerminalNode *BODY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrePostOrBodyDeclCSContext* prePostOrBodyDeclCS();

  class  OperationCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    OperationCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathNameCSContext *pathNameCS();
    antlr4::tree::TerminalNode *COLONCOLON();
    SimpleNameCSContext *simpleNameCS();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COLON();
    ParametersCSContext *parametersCS();
    TypeCSContext *typeCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationCSContext* operationCS();

  class  ParametersCSContext : public antlr4::ParserRuleContext, public CSTNode {
  public:
    ParametersCSContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationCSContext *variableDeclarationCS();
    antlr4::tree::TerminalNode *COMMA();
    ParametersCSContext *parametersCS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersCSContext* parametersCS();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool oclExpressionCSSempred(OclExpressionCSContext *_localctx, size_t predicateIndex);
  bool pathNameCSSempred(PathNameCSContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace OclCS
