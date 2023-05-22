
// Generated from OclLexer.g4 by ANTLR 4.12.0

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

  explicit OclLexer(antlr4::CharStream *input);

  ~OclLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace OclCS
