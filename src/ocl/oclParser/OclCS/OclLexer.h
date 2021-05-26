
// Generated from OclLexer.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"


namespace OclCS {


class  OclLexer : public antlr4::Lexer {
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

  explicit OclLexer(antlr4::CharStream *input);
  ~OclLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace OclCS
