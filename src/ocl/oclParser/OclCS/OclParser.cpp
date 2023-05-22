
// Generated from OclParser.g4 by ANTLR 4.12.0


#include "OclParserVisitor.h"

#include "OclParser.h"


using namespace antlrcpp;
using namespace OclCS;

using namespace antlr4;

namespace {

struct OclParserStaticData final {
  OclParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  OclParserStaticData(const OclParserStaticData&) = delete;
  OclParserStaticData(OclParserStaticData&&) = delete;
  OclParserStaticData& operator=(const OclParserStaticData&) = delete;
  OclParserStaticData& operator=(OclParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag oclparserParserOnceFlag;
OclParserStaticData *oclparserParserStaticData = nullptr;

void oclparserParserInitialize() {
  assert(oclparserParserStaticData == nullptr);
  auto staticData = std::make_unique<OclParserStaticData>(
    std::vector<std::string>{
      "expressionInOclCS", "oclExpressionCS", "parentedExpCS", "variableExpCS", 
      "simpleNameCS", "restrictedKeywordCS", "unreservedSimpleNameCS", "pathNameCS", 
      "literalExpCS", "enumLiteralExpCS", "collectionLiteralExpCS", "collectionTypeIdentifierCS", 
      "collectionLiteralPartsCS", "collectionRangeCS", "prefixedExp", "primitiveLiteralExpCS", 
      "tupleLiteralExpCS", "unlimitedNaturalLiteralExpCS", "integerLiteralExpCS", 
      "realLiteralExpCS", "stringLiteralExpCS", "booleanLiteralExpCS", "typeLiteralExpCS", 
      "iteratorExpCS", "iterateExpCS", "variableDeclarationCS", "typeCS", 
      "primitiveTypeCS", "oclTypeCS", "collectionTypeCS", "tupleTypeCS", 
      "operationCallExpCS_A", "operationCallExpCS_B", "propertyCallExpCS_A", 
      "propertyCallExpCS_B", "associationClassCallExpCS_A", "associationClassCallExpCS_B", 
      "isMarkedPreCS", "letExpCS", "oclMessageExpCS", "oclMessageArgumentsCS", 
      "ifExpCS", "nullLiteralExpCS", "invalidLiteralExpCS", "unaryLiteralExpCS", 
      "binaryLiteralExpCS", "packageDeclarationCS", "contextDeclarationCS", 
      "classifierContextDeclCS", "operationContextDeclCS", "propertyContextDeclCS", 
      "defExpressionCS", "invOrDefCS", "initOrDerValueListCS", "initOrDerValueCS", 
      "prePostOrBodyDeclCS", "prePostBodyExpCS", "operationCS"
    },
    std::vector<std::string>{
    },
    std::vector<std::string>{
      "", "COMMENTS", "IF", "THEN", "ELSE", "ENDIF", "IN", "PRE", "LET", 
      "ITERATE", "SELF", "TUPLE", "NULLEXP", "INVALID", "PACKAGE", "ENDPACKAGE", 
      "CONTEXT", "STATIC", "DEF", "INV", "BODY", "POST", "INIT", "DERIVE", 
      "COLLECTION", "BAG", "ORDEREDSET", "SEQUENCE", "SET", "OCLBOOLEAN", 
      "OCLINTEGER", "OCLREAL", "OCLSTRING", "OCLUNLIMITEDNAT", "SEQRANGE", 
      "OCLANY", "OCLINVALID", "OCLMESSAGE", "OCLVOID", "OCLSTATE", "INT", 
      "REAL", "BOOL", "STRING_LITERAL", "COLON", "COLONCOLON", "COMMA", 
      "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
      "RARROW", "LT", "GT", "LTE", "GTE", "ASSIGN", "INEQUAL", "QUESTION", 
      "STAR", "PLUS_ASSIGN", "PLUS", "KEYOR", "KEYAND", "KEYXOR", "IMPLIES", 
      "RANGE", "DOT", "AT", "SLASH", "UNDERSCORE", "DHAT", "HAT", "MINUS", 
      "NOT", "PIPE", "ID", "WS", "ERRCHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,81,759,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,1,0,1,0,3,0,119,8,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,3,1,131,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,155,8,1,10,1,12,1,158,9,1,1,2,1,
  	2,1,2,1,2,1,3,1,3,3,3,166,8,3,1,4,1,4,1,5,1,5,1,5,1,5,3,5,174,8,5,1,6,
  	1,6,3,6,178,8,6,1,7,1,7,1,7,1,7,1,7,1,7,5,7,186,8,7,10,7,12,7,189,9,7,
  	1,8,1,8,1,8,1,8,1,8,3,8,196,8,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,3,10,205,
  	8,10,1,10,1,10,1,11,1,11,1,12,1,12,3,12,213,8,12,1,12,1,12,1,12,3,12,
  	218,8,12,5,12,220,8,12,10,12,12,12,223,9,12,1,13,1,13,1,13,1,13,1,13,
  	1,13,3,13,231,8,13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,243,8,15,1,16,1,16,1,16,1,16,1,16,5,16,250,8,16,10,16,12,16,253,
  	9,16,3,16,255,8,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,
  	1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,3,23,277,8,23,1,23,
  	1,23,3,23,281,8,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,
  	292,8,23,10,23,12,23,295,9,23,3,23,297,8,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,5,23,309,8,23,10,23,12,23,312,9,23,1,23,1,23,
  	3,23,316,8,23,3,23,318,8,23,1,24,1,24,1,24,1,24,1,24,1,24,3,24,326,8,
  	24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,3,25,336,8,25,1,25,1,25,3,
  	25,340,8,25,1,26,1,26,1,26,1,26,1,26,3,26,347,8,26,1,27,1,27,1,28,1,28,
  	1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,5,30,363,8,30,10,30,
  	12,30,366,9,30,3,30,368,8,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,
  	5,31,378,8,31,10,31,12,31,381,9,31,3,31,383,8,31,1,31,1,31,1,31,1,31,
  	1,31,1,31,1,31,1,31,5,31,393,8,31,10,31,12,31,396,9,31,3,31,398,8,31,
  	1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,5,31,409,8,31,10,31,12,31,
  	412,9,31,3,31,414,8,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,
  	31,5,31,426,8,31,10,31,12,31,429,9,31,3,31,431,8,31,1,31,1,31,1,31,1,
  	31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,5,31,444,8,31,10,31,12,31,447,9,
  	31,3,31,449,8,31,1,31,1,31,3,31,453,8,31,1,32,1,32,1,32,1,32,1,32,5,32,
  	460,8,32,10,32,12,32,463,9,32,3,32,465,8,32,1,32,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,5,32,475,8,32,10,32,12,32,478,9,32,3,32,480,8,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,5,32,489,8,32,10,32,12,32,492,9,32,3,32,
  	494,8,32,1,32,1,32,3,32,498,8,32,1,33,1,33,1,33,3,33,503,8,33,1,33,1,
  	33,1,33,1,33,1,33,3,33,510,8,33,3,33,512,8,33,1,34,1,34,3,34,516,8,34,
  	1,35,1,35,1,35,1,35,1,35,1,35,5,35,524,8,35,10,35,12,35,527,9,35,1,35,
  	1,35,3,35,531,8,35,1,35,3,35,534,8,35,1,36,1,36,1,36,1,36,1,36,5,36,541,
  	8,36,10,36,12,36,544,9,36,1,36,1,36,3,36,548,8,36,1,36,3,36,551,8,36,
  	1,37,1,37,1,37,1,38,1,38,1,38,1,38,5,38,560,8,38,10,38,12,38,563,9,38,
  	1,38,1,38,1,38,1,39,1,39,1,39,1,39,3,39,572,8,39,1,39,1,39,1,39,1,39,
  	1,39,1,39,3,39,580,8,39,1,39,1,39,3,39,584,8,39,1,40,1,40,1,40,3,40,589,
  	8,40,1,40,3,40,592,8,40,1,40,1,40,1,40,1,40,3,40,598,8,40,1,40,3,40,601,
  	8,40,5,40,603,8,40,10,40,12,40,606,9,40,1,41,1,41,1,41,1,41,1,41,1,41,
  	1,41,1,41,1,42,1,42,1,43,1,43,1,44,1,44,1,45,1,45,1,46,1,46,1,46,5,46,
  	627,8,46,10,46,12,46,630,9,46,1,46,1,46,1,46,5,46,635,8,46,10,46,12,46,
  	638,9,46,3,46,640,8,46,1,47,1,47,1,47,3,47,645,8,47,1,48,1,48,1,48,1,
  	48,1,48,1,48,1,48,1,48,1,48,1,48,3,48,657,8,48,1,49,1,49,1,49,1,49,1,
  	50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,51,1,
  	51,1,51,3,51,679,8,51,1,52,1,52,3,52,683,8,52,1,52,1,52,1,52,3,52,688,
  	8,52,1,52,1,52,3,52,692,8,52,1,52,1,52,3,52,696,8,52,1,53,5,53,699,8,
  	53,10,53,12,53,702,9,53,1,54,1,54,1,54,1,54,1,55,5,55,709,8,55,10,55,
  	12,55,712,9,55,1,56,1,56,3,56,716,8,56,1,56,1,56,1,56,1,57,1,57,1,57,
  	1,57,1,57,1,57,1,57,5,57,728,8,57,10,57,12,57,731,9,57,3,57,733,8,57,
  	1,57,1,57,1,57,3,57,738,8,57,1,57,1,57,1,57,1,57,1,57,5,57,745,8,57,10,
  	57,12,57,748,9,57,3,57,750,8,57,1,57,1,57,1,57,3,57,755,8,57,3,57,757,
  	8,57,1,57,0,2,2,14,58,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,
  	82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,0,10,2,0,62,
  	62,72,72,2,0,64,64,76,76,1,0,24,28,2,0,40,40,62,62,1,0,29,33,1,0,35,38,
  	1,0,76,77,2,0,55,60,65,68,1,0,22,23,2,0,7,7,20,21,821,0,118,1,0,0,0,2,
  	130,1,0,0,0,4,159,1,0,0,0,6,165,1,0,0,0,8,167,1,0,0,0,10,173,1,0,0,0,
  	12,177,1,0,0,0,14,179,1,0,0,0,16,195,1,0,0,0,18,197,1,0,0,0,20,201,1,
  	0,0,0,22,208,1,0,0,0,24,212,1,0,0,0,26,230,1,0,0,0,28,232,1,0,0,0,30,
  	242,1,0,0,0,32,244,1,0,0,0,34,258,1,0,0,0,36,260,1,0,0,0,38,262,1,0,0,
  	0,40,264,1,0,0,0,42,266,1,0,0,0,44,268,1,0,0,0,46,317,1,0,0,0,48,319,
  	1,0,0,0,50,332,1,0,0,0,52,346,1,0,0,0,54,348,1,0,0,0,56,350,1,0,0,0,58,
  	352,1,0,0,0,60,357,1,0,0,0,62,452,1,0,0,0,64,497,1,0,0,0,66,511,1,0,0,
  	0,68,513,1,0,0,0,70,517,1,0,0,0,72,535,1,0,0,0,74,552,1,0,0,0,76,555,
  	1,0,0,0,78,583,1,0,0,0,80,591,1,0,0,0,82,607,1,0,0,0,84,615,1,0,0,0,86,
  	617,1,0,0,0,88,619,1,0,0,0,90,621,1,0,0,0,92,639,1,0,0,0,94,644,1,0,0,
  	0,96,656,1,0,0,0,98,658,1,0,0,0,100,662,1,0,0,0,102,678,1,0,0,0,104,695,
  	1,0,0,0,106,700,1,0,0,0,108,703,1,0,0,0,110,710,1,0,0,0,112,713,1,0,0,
  	0,114,756,1,0,0,0,116,119,3,2,1,0,117,119,3,92,46,0,118,116,1,0,0,0,118,
  	117,1,0,0,0,119,1,1,0,0,0,120,121,6,1,-1,0,121,131,3,28,14,0,122,131,
  	3,64,32,0,123,131,3,68,34,0,124,131,3,72,36,0,125,131,3,4,2,0,126,131,
  	3,6,3,0,127,131,3,16,8,0,128,131,3,76,38,0,129,131,3,82,41,0,130,120,
  	1,0,0,0,130,122,1,0,0,0,130,123,1,0,0,0,130,124,1,0,0,0,130,125,1,0,0,
  	0,130,126,1,0,0,0,130,127,1,0,0,0,130,128,1,0,0,0,130,129,1,0,0,0,131,
  	156,1,0,0,0,132,133,10,9,0,0,133,134,7,0,0,0,134,155,3,2,1,10,135,136,
  	10,8,0,0,136,137,7,1,0,0,137,155,3,2,1,9,138,139,10,6,0,0,139,140,3,90,
  	45,0,140,141,3,2,1,7,141,155,1,0,0,0,142,143,10,17,0,0,143,155,3,62,31,
  	0,144,145,10,15,0,0,145,155,3,66,33,0,146,147,10,13,0,0,147,155,3,70,
  	35,0,148,149,10,11,0,0,149,155,3,46,23,0,150,151,10,10,0,0,151,155,3,
  	48,24,0,152,153,10,2,0,0,153,155,3,78,39,0,154,132,1,0,0,0,154,135,1,
  	0,0,0,154,138,1,0,0,0,154,142,1,0,0,0,154,144,1,0,0,0,154,146,1,0,0,0,
  	154,148,1,0,0,0,154,150,1,0,0,0,154,152,1,0,0,0,155,158,1,0,0,0,156,154,
  	1,0,0,0,156,157,1,0,0,0,157,3,1,0,0,0,158,156,1,0,0,0,159,160,5,48,0,
  	0,160,161,3,2,1,0,161,162,5,49,0,0,162,5,1,0,0,0,163,166,5,10,0,0,164,
  	166,3,8,4,0,165,163,1,0,0,0,165,164,1,0,0,0,166,7,1,0,0,0,167,168,5,79,
  	0,0,168,9,1,0,0,0,169,174,3,22,11,0,170,174,3,54,27,0,171,174,3,56,28,
  	0,172,174,5,11,0,0,173,169,1,0,0,0,173,170,1,0,0,0,173,171,1,0,0,0,173,
  	172,1,0,0,0,174,11,1,0,0,0,175,178,3,8,4,0,176,178,3,10,5,0,177,175,1,
  	0,0,0,177,176,1,0,0,0,178,13,1,0,0,0,179,180,6,7,-1,0,180,181,3,8,4,0,
  	181,187,1,0,0,0,182,183,10,1,0,0,183,184,5,45,0,0,184,186,3,12,6,0,185,
  	182,1,0,0,0,186,189,1,0,0,0,187,185,1,0,0,0,187,188,1,0,0,0,188,15,1,
  	0,0,0,189,187,1,0,0,0,190,196,3,18,9,0,191,196,3,20,10,0,192,196,3,32,
  	16,0,193,196,3,30,15,0,194,196,3,44,22,0,195,190,1,0,0,0,195,191,1,0,
  	0,0,195,192,1,0,0,0,195,193,1,0,0,0,195,194,1,0,0,0,196,17,1,0,0,0,197,
  	198,3,14,7,0,198,199,5,45,0,0,199,200,3,8,4,0,200,19,1,0,0,0,201,202,
  	3,22,11,0,202,204,5,50,0,0,203,205,3,24,12,0,204,203,1,0,0,0,204,205,
  	1,0,0,0,205,206,1,0,0,0,206,207,5,51,0,0,207,21,1,0,0,0,208,209,7,2,0,
  	0,209,23,1,0,0,0,210,213,3,26,13,0,211,213,3,2,1,0,212,210,1,0,0,0,212,
  	211,1,0,0,0,213,221,1,0,0,0,214,217,5,46,0,0,215,218,3,26,13,0,216,218,
  	3,2,1,0,217,215,1,0,0,0,217,216,1,0,0,0,218,220,1,0,0,0,219,214,1,0,0,
  	0,220,223,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,222,25,1,0,0,0,223,
  	221,1,0,0,0,224,225,3,2,1,0,225,226,5,69,0,0,226,227,3,2,1,0,227,231,
  	1,0,0,0,228,229,5,34,0,0,229,231,3,2,1,0,230,224,1,0,0,0,230,228,1,0,
  	0,0,231,27,1,0,0,0,232,233,3,88,44,0,233,234,3,2,1,0,234,29,1,0,0,0,235,
  	243,3,36,18,0,236,243,3,38,19,0,237,243,3,40,20,0,238,243,3,42,21,0,239,
  	243,3,34,17,0,240,243,3,84,42,0,241,243,3,86,43,0,242,235,1,0,0,0,242,
  	236,1,0,0,0,242,237,1,0,0,0,242,238,1,0,0,0,242,239,1,0,0,0,242,240,1,
  	0,0,0,242,241,1,0,0,0,243,31,1,0,0,0,244,245,5,11,0,0,245,254,5,50,0,
  	0,246,251,3,50,25,0,247,248,5,46,0,0,248,250,3,50,25,0,249,247,1,0,0,
  	0,250,253,1,0,0,0,251,249,1,0,0,0,251,252,1,0,0,0,252,255,1,0,0,0,253,
  	251,1,0,0,0,254,246,1,0,0,0,254,255,1,0,0,0,255,256,1,0,0,0,256,257,5,
  	51,0,0,257,33,1,0,0,0,258,259,7,3,0,0,259,35,1,0,0,0,260,261,5,40,0,0,
  	261,37,1,0,0,0,262,263,5,41,0,0,263,39,1,0,0,0,264,265,5,43,0,0,265,41,
  	1,0,0,0,266,267,5,42,0,0,267,43,1,0,0,0,268,269,3,52,26,0,269,45,1,0,
  	0,0,270,271,5,54,0,0,271,272,3,8,4,0,272,280,5,48,0,0,273,276,3,50,25,
  	0,274,275,5,46,0,0,275,277,3,50,25,0,276,274,1,0,0,0,276,277,1,0,0,0,
  	277,278,1,0,0,0,278,279,5,78,0,0,279,281,1,0,0,0,280,273,1,0,0,0,280,
  	281,1,0,0,0,281,282,1,0,0,0,282,283,3,2,1,0,283,284,5,49,0,0,284,318,
  	1,0,0,0,285,286,5,70,0,0,286,287,3,8,4,0,287,296,5,48,0,0,288,293,3,2,
  	1,0,289,290,5,46,0,0,290,292,3,2,1,0,291,289,1,0,0,0,292,295,1,0,0,0,
  	293,291,1,0,0,0,293,294,1,0,0,0,294,297,1,0,0,0,295,293,1,0,0,0,296,288,
  	1,0,0,0,296,297,1,0,0,0,297,298,1,0,0,0,298,299,5,49,0,0,299,318,1,0,
  	0,0,300,301,5,70,0,0,301,318,3,8,4,0,302,303,5,70,0,0,303,315,3,8,4,0,
  	304,305,5,52,0,0,305,310,3,2,1,0,306,307,5,46,0,0,307,309,3,2,1,0,308,
  	306,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,311,1,0,0,0,311,313,1,
  	0,0,0,312,310,1,0,0,0,313,314,5,53,0,0,314,316,1,0,0,0,315,304,1,0,0,
  	0,315,316,1,0,0,0,316,318,1,0,0,0,317,270,1,0,0,0,317,285,1,0,0,0,317,
  	300,1,0,0,0,317,302,1,0,0,0,318,47,1,0,0,0,319,320,5,54,0,0,320,321,5,
  	9,0,0,321,325,5,48,0,0,322,323,3,50,25,0,323,324,5,47,0,0,324,326,1,0,
  	0,0,325,322,1,0,0,0,325,326,1,0,0,0,326,327,1,0,0,0,327,328,3,50,25,0,
  	328,329,5,78,0,0,329,330,3,2,1,0,330,331,5,49,0,0,331,49,1,0,0,0,332,
  	335,3,8,4,0,333,334,5,44,0,0,334,336,3,52,26,0,335,333,1,0,0,0,335,336,
  	1,0,0,0,336,339,1,0,0,0,337,338,5,59,0,0,338,340,3,2,1,0,339,337,1,0,
  	0,0,339,340,1,0,0,0,340,51,1,0,0,0,341,347,3,14,7,0,342,347,3,58,29,0,
  	343,347,3,60,30,0,344,347,3,54,27,0,345,347,3,56,28,0,346,341,1,0,0,0,
  	346,342,1,0,0,0,346,343,1,0,0,0,346,344,1,0,0,0,346,345,1,0,0,0,347,53,
  	1,0,0,0,348,349,7,4,0,0,349,55,1,0,0,0,350,351,7,5,0,0,351,57,1,0,0,0,
  	352,353,3,22,11,0,353,354,5,48,0,0,354,355,3,52,26,0,355,356,5,49,0,0,
  	356,59,1,0,0,0,357,358,5,11,0,0,358,367,5,48,0,0,359,364,3,50,25,0,360,
  	361,5,46,0,0,361,363,3,50,25,0,362,360,1,0,0,0,363,366,1,0,0,0,364,362,
  	1,0,0,0,364,365,1,0,0,0,365,368,1,0,0,0,366,364,1,0,0,0,367,359,1,0,0,
  	0,367,368,1,0,0,0,368,369,1,0,0,0,369,370,5,49,0,0,370,61,1,0,0,0,371,
  	372,5,54,0,0,372,373,3,8,4,0,373,382,5,48,0,0,374,379,3,2,1,0,375,376,
  	5,46,0,0,376,378,3,2,1,0,377,375,1,0,0,0,378,381,1,0,0,0,379,377,1,0,
  	0,0,379,380,1,0,0,0,380,383,1,0,0,0,381,379,1,0,0,0,382,374,1,0,0,0,382,
  	383,1,0,0,0,383,384,1,0,0,0,384,385,5,49,0,0,385,453,1,0,0,0,386,387,
  	5,70,0,0,387,388,3,8,4,0,388,397,5,48,0,0,389,394,3,2,1,0,390,391,5,46,
  	0,0,391,393,3,2,1,0,392,390,1,0,0,0,393,396,1,0,0,0,394,392,1,0,0,0,394,
  	395,1,0,0,0,395,398,1,0,0,0,396,394,1,0,0,0,397,389,1,0,0,0,397,398,1,
  	0,0,0,398,399,1,0,0,0,399,400,5,49,0,0,400,453,1,0,0,0,401,402,5,70,0,
  	0,402,403,3,8,4,0,403,404,3,74,37,0,404,413,5,48,0,0,405,410,3,2,1,0,
  	406,407,5,46,0,0,407,409,3,2,1,0,408,406,1,0,0,0,409,412,1,0,0,0,410,
  	408,1,0,0,0,410,411,1,0,0,0,411,414,1,0,0,0,412,410,1,0,0,0,413,405,1,
  	0,0,0,413,414,1,0,0,0,414,415,1,0,0,0,415,416,5,49,0,0,416,453,1,0,0,
  	0,417,418,5,70,0,0,418,419,3,14,7,0,419,420,5,45,0,0,420,421,3,8,4,0,
  	421,430,5,48,0,0,422,427,3,2,1,0,423,424,5,46,0,0,424,426,3,2,1,0,425,
  	423,1,0,0,0,426,429,1,0,0,0,427,425,1,0,0,0,427,428,1,0,0,0,428,431,1,
  	0,0,0,429,427,1,0,0,0,430,422,1,0,0,0,430,431,1,0,0,0,431,432,1,0,0,0,
  	432,433,5,49,0,0,433,453,1,0,0,0,434,435,5,70,0,0,435,436,3,14,7,0,436,
  	437,5,45,0,0,437,438,3,8,4,0,438,439,3,74,37,0,439,448,5,48,0,0,440,445,
  	3,2,1,0,441,442,5,46,0,0,442,444,3,2,1,0,443,441,1,0,0,0,444,447,1,0,
  	0,0,445,443,1,0,0,0,445,446,1,0,0,0,446,449,1,0,0,0,447,445,1,0,0,0,448,
  	440,1,0,0,0,448,449,1,0,0,0,449,450,1,0,0,0,450,451,5,49,0,0,451,453,
  	1,0,0,0,452,371,1,0,0,0,452,386,1,0,0,0,452,401,1,0,0,0,452,417,1,0,0,
  	0,452,434,1,0,0,0,453,63,1,0,0,0,454,455,3,8,4,0,455,464,5,48,0,0,456,
  	461,3,2,1,0,457,458,5,46,0,0,458,460,3,2,1,0,459,457,1,0,0,0,460,463,
  	1,0,0,0,461,459,1,0,0,0,461,462,1,0,0,0,462,465,1,0,0,0,463,461,1,0,0,
  	0,464,456,1,0,0,0,464,465,1,0,0,0,465,466,1,0,0,0,466,467,5,49,0,0,467,
  	498,1,0,0,0,468,469,3,8,4,0,469,470,3,74,37,0,470,479,5,48,0,0,471,476,
  	3,2,1,0,472,473,5,46,0,0,473,475,3,2,1,0,474,472,1,0,0,0,475,478,1,0,
  	0,0,476,474,1,0,0,0,476,477,1,0,0,0,477,480,1,0,0,0,478,476,1,0,0,0,479,
  	471,1,0,0,0,479,480,1,0,0,0,480,481,1,0,0,0,481,482,5,49,0,0,482,498,
  	1,0,0,0,483,484,3,14,7,0,484,493,5,48,0,0,485,490,3,2,1,0,486,487,5,46,
  	0,0,487,489,3,2,1,0,488,486,1,0,0,0,489,492,1,0,0,0,490,488,1,0,0,0,490,
  	491,1,0,0,0,491,494,1,0,0,0,492,490,1,0,0,0,493,485,1,0,0,0,493,494,1,
  	0,0,0,494,495,1,0,0,0,495,496,5,49,0,0,496,498,1,0,0,0,497,454,1,0,0,
  	0,497,468,1,0,0,0,497,483,1,0,0,0,498,65,1,0,0,0,499,500,5,70,0,0,500,
  	502,3,8,4,0,501,503,3,74,37,0,502,501,1,0,0,0,502,503,1,0,0,0,503,512,
  	1,0,0,0,504,505,5,70,0,0,505,506,3,14,7,0,506,507,5,45,0,0,507,509,3,
  	8,4,0,508,510,3,74,37,0,509,508,1,0,0,0,509,510,1,0,0,0,510,512,1,0,0,
  	0,511,499,1,0,0,0,511,504,1,0,0,0,512,67,1,0,0,0,513,515,3,8,4,0,514,
  	516,3,74,37,0,515,514,1,0,0,0,515,516,1,0,0,0,516,69,1,0,0,0,517,518,
  	5,70,0,0,518,530,3,8,4,0,519,520,5,50,0,0,520,525,3,2,1,0,521,522,5,46,
  	0,0,522,524,3,2,1,0,523,521,1,0,0,0,524,527,1,0,0,0,525,523,1,0,0,0,525,
  	526,1,0,0,0,526,528,1,0,0,0,527,525,1,0,0,0,528,529,5,51,0,0,529,531,
  	1,0,0,0,530,519,1,0,0,0,530,531,1,0,0,0,531,533,1,0,0,0,532,534,3,74,
  	37,0,533,532,1,0,0,0,533,534,1,0,0,0,534,71,1,0,0,0,535,547,3,8,4,0,536,
  	537,5,50,0,0,537,542,3,2,1,0,538,539,5,46,0,0,539,541,3,2,1,0,540,538,
  	1,0,0,0,541,544,1,0,0,0,542,540,1,0,0,0,542,543,1,0,0,0,543,545,1,0,0,
  	0,544,542,1,0,0,0,545,546,5,51,0,0,546,548,1,0,0,0,547,536,1,0,0,0,547,
  	548,1,0,0,0,548,550,1,0,0,0,549,551,3,74,37,0,550,549,1,0,0,0,550,551,
  	1,0,0,0,551,73,1,0,0,0,552,553,5,71,0,0,553,554,5,7,0,0,554,75,1,0,0,
  	0,555,556,5,8,0,0,556,561,3,50,25,0,557,558,5,46,0,0,558,560,3,50,25,
  	0,559,557,1,0,0,0,560,563,1,0,0,0,561,559,1,0,0,0,561,562,1,0,0,0,562,
  	564,1,0,0,0,563,561,1,0,0,0,564,565,5,6,0,0,565,566,3,2,1,0,566,77,1,
  	0,0,0,567,568,5,74,0,0,568,569,3,8,4,0,569,571,5,48,0,0,570,572,3,80,
  	40,0,571,570,1,0,0,0,571,572,1,0,0,0,572,573,1,0,0,0,573,574,5,49,0,0,
  	574,584,1,0,0,0,575,576,5,75,0,0,576,577,3,8,4,0,577,579,5,48,0,0,578,
  	580,3,80,40,0,579,578,1,0,0,0,579,580,1,0,0,0,580,581,1,0,0,0,581,582,
  	5,49,0,0,582,584,1,0,0,0,583,567,1,0,0,0,583,575,1,0,0,0,584,79,1,0,0,
  	0,585,588,5,61,0,0,586,587,5,44,0,0,587,589,3,52,26,0,588,586,1,0,0,0,
  	588,589,1,0,0,0,589,592,1,0,0,0,590,592,3,2,1,0,591,585,1,0,0,0,591,590,
  	1,0,0,0,592,604,1,0,0,0,593,600,5,46,0,0,594,597,5,61,0,0,595,596,5,44,
  	0,0,596,598,3,52,26,0,597,595,1,0,0,0,597,598,1,0,0,0,598,601,1,0,0,0,
  	599,601,3,2,1,0,600,594,1,0,0,0,600,599,1,0,0,0,601,603,1,0,0,0,602,593,
  	1,0,0,0,603,606,1,0,0,0,604,602,1,0,0,0,604,605,1,0,0,0,605,81,1,0,0,
  	0,606,604,1,0,0,0,607,608,5,2,0,0,608,609,3,2,1,0,609,610,5,3,0,0,610,
  	611,3,2,1,0,611,612,5,4,0,0,612,613,3,2,1,0,613,614,5,5,0,0,614,83,1,
  	0,0,0,615,616,5,12,0,0,616,85,1,0,0,0,617,618,5,13,0,0,618,87,1,0,0,0,
  	619,620,7,6,0,0,620,89,1,0,0,0,621,622,7,7,0,0,622,91,1,0,0,0,623,624,
  	5,14,0,0,624,628,3,14,7,0,625,627,3,94,47,0,626,625,1,0,0,0,627,630,1,
  	0,0,0,628,626,1,0,0,0,628,629,1,0,0,0,629,631,1,0,0,0,630,628,1,0,0,0,
  	631,632,5,15,0,0,632,640,1,0,0,0,633,635,3,94,47,0,634,633,1,0,0,0,635,
  	638,1,0,0,0,636,634,1,0,0,0,636,637,1,0,0,0,637,640,1,0,0,0,638,636,1,
  	0,0,0,639,623,1,0,0,0,639,636,1,0,0,0,640,93,1,0,0,0,641,645,3,100,50,
  	0,642,645,3,96,48,0,643,645,3,98,49,0,644,641,1,0,0,0,644,642,1,0,0,0,
  	644,643,1,0,0,0,645,95,1,0,0,0,646,647,5,16,0,0,647,648,3,14,7,0,648,
  	649,3,104,52,0,649,657,1,0,0,0,650,651,5,16,0,0,651,652,3,8,4,0,652,653,
  	5,44,0,0,653,654,3,14,7,0,654,655,3,104,52,0,655,657,1,0,0,0,656,646,
  	1,0,0,0,656,650,1,0,0,0,657,97,1,0,0,0,658,659,5,16,0,0,659,660,3,114,
  	57,0,660,661,3,110,55,0,661,99,1,0,0,0,662,663,5,16,0,0,663,664,3,14,
  	7,0,664,665,5,45,0,0,665,666,3,8,4,0,666,667,5,44,0,0,667,668,3,52,26,
  	0,668,669,3,106,53,0,669,101,1,0,0,0,670,671,3,50,25,0,671,672,5,59,0,
  	0,672,673,3,2,1,0,673,679,1,0,0,0,674,675,3,114,57,0,675,676,5,59,0,0,
  	676,677,3,2,1,0,677,679,1,0,0,0,678,670,1,0,0,0,678,674,1,0,0,0,679,103,
  	1,0,0,0,680,682,5,19,0,0,681,683,3,8,4,0,682,681,1,0,0,0,682,683,1,0,
  	0,0,683,684,1,0,0,0,684,685,5,44,0,0,685,696,3,2,1,0,686,688,5,17,0,0,
  	687,686,1,0,0,0,687,688,1,0,0,0,688,689,1,0,0,0,689,691,5,18,0,0,690,
  	692,3,8,4,0,691,690,1,0,0,0,691,692,1,0,0,0,692,693,1,0,0,0,693,694,5,
  	44,0,0,694,696,3,102,51,0,695,680,1,0,0,0,695,687,1,0,0,0,696,105,1,0,
  	0,0,697,699,3,108,54,0,698,697,1,0,0,0,699,702,1,0,0,0,700,698,1,0,0,
  	0,700,701,1,0,0,0,701,107,1,0,0,0,702,700,1,0,0,0,703,704,7,8,0,0,704,
  	705,5,44,0,0,705,706,3,2,1,0,706,109,1,0,0,0,707,709,3,112,56,0,708,707,
  	1,0,0,0,709,712,1,0,0,0,710,708,1,0,0,0,710,711,1,0,0,0,711,111,1,0,0,
  	0,712,710,1,0,0,0,713,715,7,9,0,0,714,716,3,8,4,0,715,714,1,0,0,0,715,
  	716,1,0,0,0,716,717,1,0,0,0,717,718,5,44,0,0,718,719,3,2,1,0,719,113,
  	1,0,0,0,720,721,3,14,7,0,721,722,5,45,0,0,722,723,3,8,4,0,723,732,5,48,
  	0,0,724,729,3,50,25,0,725,726,5,46,0,0,726,728,3,50,25,0,727,725,1,0,
  	0,0,728,731,1,0,0,0,729,727,1,0,0,0,729,730,1,0,0,0,730,733,1,0,0,0,731,
  	729,1,0,0,0,732,724,1,0,0,0,732,733,1,0,0,0,733,734,1,0,0,0,734,735,5,
  	49,0,0,735,737,5,44,0,0,736,738,3,52,26,0,737,736,1,0,0,0,737,738,1,0,
  	0,0,738,757,1,0,0,0,739,740,3,8,4,0,740,749,5,48,0,0,741,746,3,50,25,
  	0,742,743,5,46,0,0,743,745,3,50,25,0,744,742,1,0,0,0,745,748,1,0,0,0,
  	746,744,1,0,0,0,746,747,1,0,0,0,747,750,1,0,0,0,748,746,1,0,0,0,749,741,
  	1,0,0,0,749,750,1,0,0,0,750,751,1,0,0,0,751,752,5,49,0,0,752,754,5,44,
  	0,0,753,755,3,52,26,0,754,753,1,0,0,0,754,755,1,0,0,0,755,757,1,0,0,0,
  	756,720,1,0,0,0,756,739,1,0,0,0,757,115,1,0,0,0,87,118,130,154,156,165,
  	173,177,187,195,204,212,217,221,230,242,251,254,276,280,293,296,310,315,
  	317,325,335,339,346,364,367,379,382,394,397,410,413,427,430,445,448,452,
  	461,464,476,479,490,493,497,502,509,511,515,525,530,533,542,547,550,561,
  	571,579,583,588,591,597,600,604,628,636,639,644,656,678,682,687,691,695,
  	700,710,715,729,732,737,746,749,754,756
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  oclparserParserStaticData = staticData.release();
}

}

OclParser::OclParser(TokenStream *input) : OclParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

OclParser::OclParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  OclParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *oclparserParserStaticData->atn, oclparserParserStaticData->decisionToDFA, oclparserParserStaticData->sharedContextCache, options);
}

OclParser::~OclParser() {
  //delete _interpreter;
}

const atn::ATN& OclParser::getATN() const {
  return *oclparserParserStaticData->atn;
}

std::string OclParser::getGrammarFileName() const {
  return "OclParser.g4";
}

const std::vector<std::string>& OclParser::getRuleNames() const {
  return oclparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& OclParser::getVocabulary() const {
  return oclparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView OclParser::getSerializedATN() const {
  return oclparserParserStaticData->serializedATN;
}


//----------------- ExpressionInOclCSContext ------------------------------------------------------------------

OclParser::ExpressionInOclCSContext::ExpressionInOclCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::OclExpressionCSContext* OclParser::ExpressionInOclCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

OclParser::PackageDeclarationCSContext* OclParser::ExpressionInOclCSContext::packageDeclarationCS() {
  return getRuleContext<OclParser::PackageDeclarationCSContext>(0);
}


size_t OclParser::ExpressionInOclCSContext::getRuleIndex() const {
  return OclParser::RuleExpressionInOclCS;
}


std::any OclParser::ExpressionInOclCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitExpressionInOclCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::ExpressionInOclCSContext* OclParser::expressionInOclCS() {
  ExpressionInOclCSContext *_localctx = _tracker.createInstance<ExpressionInOclCSContext>(_ctx, getState());
  enterRule(_localctx, 0, OclParser::RuleExpressionInOclCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::IF:
      case OclParser::LET:
      case OclParser::SELF:
      case OclParser::TUPLE:
      case OclParser::NULLEXP:
      case OclParser::INVALID:
      case OclParser::COLLECTION:
      case OclParser::BAG:
      case OclParser::ORDEREDSET:
      case OclParser::SEQUENCE:
      case OclParser::SET:
      case OclParser::OCLBOOLEAN:
      case OclParser::OCLINTEGER:
      case OclParser::OCLREAL:
      case OclParser::OCLSTRING:
      case OclParser::OCLUNLIMITEDNAT:
      case OclParser::OCLANY:
      case OclParser::OCLINVALID:
      case OclParser::OCLMESSAGE:
      case OclParser::OCLVOID:
      case OclParser::INT:
      case OclParser::REAL:
      case OclParser::BOOL:
      case OclParser::STRING_LITERAL:
      case OclParser::LPAREN:
      case OclParser::STAR:
      case OclParser::MINUS:
      case OclParser::NOT:
      case OclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(116);
        oclExpressionCS(0);
        break;
      }

      case OclParser::EOF:
      case OclParser::PACKAGE:
      case OclParser::CONTEXT: {
        enterOuterAlt(_localctx, 2);
        setState(117);
        packageDeclarationCS();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OclExpressionCSContext ------------------------------------------------------------------

OclParser::OclExpressionCSContext::OclExpressionCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::PrefixedExpContext* OclParser::OclExpressionCSContext::prefixedExp() {
  return getRuleContext<OclParser::PrefixedExpContext>(0);
}

OclParser::OperationCallExpCS_BContext* OclParser::OclExpressionCSContext::operationCallExpCS_B() {
  return getRuleContext<OclParser::OperationCallExpCS_BContext>(0);
}

OclParser::PropertyCallExpCS_BContext* OclParser::OclExpressionCSContext::propertyCallExpCS_B() {
  return getRuleContext<OclParser::PropertyCallExpCS_BContext>(0);
}

OclParser::AssociationClassCallExpCS_BContext* OclParser::OclExpressionCSContext::associationClassCallExpCS_B() {
  return getRuleContext<OclParser::AssociationClassCallExpCS_BContext>(0);
}

OclParser::ParentedExpCSContext* OclParser::OclExpressionCSContext::parentedExpCS() {
  return getRuleContext<OclParser::ParentedExpCSContext>(0);
}

OclParser::VariableExpCSContext* OclParser::OclExpressionCSContext::variableExpCS() {
  return getRuleContext<OclParser::VariableExpCSContext>(0);
}

OclParser::LiteralExpCSContext* OclParser::OclExpressionCSContext::literalExpCS() {
  return getRuleContext<OclParser::LiteralExpCSContext>(0);
}

OclParser::LetExpCSContext* OclParser::OclExpressionCSContext::letExpCS() {
  return getRuleContext<OclParser::LetExpCSContext>(0);
}

OclParser::IfExpCSContext* OclParser::OclExpressionCSContext::ifExpCS() {
  return getRuleContext<OclParser::IfExpCSContext>(0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::OclExpressionCSContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::OclExpressionCSContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

tree::TerminalNode* OclParser::OclExpressionCSContext::STAR() {
  return getToken(OclParser::STAR, 0);
}

tree::TerminalNode* OclParser::OclExpressionCSContext::SLASH() {
  return getToken(OclParser::SLASH, 0);
}

tree::TerminalNode* OclParser::OclExpressionCSContext::PLUS() {
  return getToken(OclParser::PLUS, 0);
}

tree::TerminalNode* OclParser::OclExpressionCSContext::MINUS() {
  return getToken(OclParser::MINUS, 0);
}

OclParser::BinaryLiteralExpCSContext* OclParser::OclExpressionCSContext::binaryLiteralExpCS() {
  return getRuleContext<OclParser::BinaryLiteralExpCSContext>(0);
}

OclParser::OperationCallExpCS_AContext* OclParser::OclExpressionCSContext::operationCallExpCS_A() {
  return getRuleContext<OclParser::OperationCallExpCS_AContext>(0);
}

OclParser::PropertyCallExpCS_AContext* OclParser::OclExpressionCSContext::propertyCallExpCS_A() {
  return getRuleContext<OclParser::PropertyCallExpCS_AContext>(0);
}

OclParser::AssociationClassCallExpCS_AContext* OclParser::OclExpressionCSContext::associationClassCallExpCS_A() {
  return getRuleContext<OclParser::AssociationClassCallExpCS_AContext>(0);
}

OclParser::IteratorExpCSContext* OclParser::OclExpressionCSContext::iteratorExpCS() {
  return getRuleContext<OclParser::IteratorExpCSContext>(0);
}

OclParser::IterateExpCSContext* OclParser::OclExpressionCSContext::iterateExpCS() {
  return getRuleContext<OclParser::IterateExpCSContext>(0);
}

OclParser::OclMessageExpCSContext* OclParser::OclExpressionCSContext::oclMessageExpCS() {
  return getRuleContext<OclParser::OclMessageExpCSContext>(0);
}


size_t OclParser::OclExpressionCSContext::getRuleIndex() const {
  return OclParser::RuleOclExpressionCS;
}


std::any OclParser::OclExpressionCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOclExpressionCS(this);
  else
    return visitor->visitChildren(this);
}


OclParser::OclExpressionCSContext* OclParser::oclExpressionCS() {
   return oclExpressionCS(0);
}

OclParser::OclExpressionCSContext* OclParser::oclExpressionCS(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  OclParser::OclExpressionCSContext *_localctx = _tracker.createInstance<OclExpressionCSContext>(_ctx, parentState);
  OclParser::OclExpressionCSContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, OclParser::RuleOclExpressionCS, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(121);
      prefixedExp();
      break;
    }

    case 2: {
      setState(122);
      operationCallExpCS_B();
      break;
    }

    case 3: {
      setState(123);
      propertyCallExpCS_B();
      break;
    }

    case 4: {
      setState(124);
      associationClassCallExpCS_B();
      break;
    }

    case 5: {
      setState(125);
      parentedExpCS();
      break;
    }

    case 6: {
      setState(126);
      variableExpCS();
      break;
    }

    case 7: {
      setState(127);
      literalExpCS();
      break;
    }

    case 8: {
      setState(128);
      letExpCS();
      break;
    }

    case 9: {
      setState(129);
      ifExpCS();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(154);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(132);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(133);
          _la = _input->LA(1);
          if (!(_la == OclParser::STAR

          || _la == OclParser::SLASH)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(134);
          oclExpressionCS(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(135);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(136);
          _la = _input->LA(1);
          if (!(_la == OclParser::PLUS

          || _la == OclParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(137);
          oclExpressionCS(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(138);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(139);
          binaryLiteralExpCS();
          setState(140);
          oclExpressionCS(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(142);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(143);
          operationCallExpCS_A();
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(144);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(145);
          propertyCallExpCS_A();
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(146);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(147);
          associationClassCallExpCS_A();
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(148);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(149);
          iteratorExpCS();
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(150);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(151);
          iterateExpCS();
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<OclExpressionCSContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleOclExpressionCS);
          setState(152);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(153);
          oclMessageExpCS();
          break;
        }

        default:
          break;
        } 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParentedExpCSContext ------------------------------------------------------------------

OclParser::ParentedExpCSContext::ParentedExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::ParentedExpCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

OclParser::OclExpressionCSContext* OclParser::ParentedExpCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

tree::TerminalNode* OclParser::ParentedExpCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}


size_t OclParser::ParentedExpCSContext::getRuleIndex() const {
  return OclParser::RuleParentedExpCS;
}


std::any OclParser::ParentedExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitParentedExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::ParentedExpCSContext* OclParser::parentedExpCS() {
  ParentedExpCSContext *_localctx = _tracker.createInstance<ParentedExpCSContext>(_ctx, getState());
  enterRule(_localctx, 4, OclParser::RuleParentedExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(OclParser::LPAREN);
    setState(160);
    oclExpressionCS(0);
    setState(161);
    match(OclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableExpCSContext ------------------------------------------------------------------

OclParser::VariableExpCSContext::VariableExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::VariableExpCSContext::SELF() {
  return getToken(OclParser::SELF, 0);
}

OclParser::SimpleNameCSContext* OclParser::VariableExpCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}


size_t OclParser::VariableExpCSContext::getRuleIndex() const {
  return OclParser::RuleVariableExpCS;
}


std::any OclParser::VariableExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitVariableExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::VariableExpCSContext* OclParser::variableExpCS() {
  VariableExpCSContext *_localctx = _tracker.createInstance<VariableExpCSContext>(_ctx, getState());
  enterRule(_localctx, 6, OclParser::RuleVariableExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::SELF: {
        enterOuterAlt(_localctx, 1);
        setState(163);
        match(OclParser::SELF);
        break;
      }

      case OclParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(164);
        simpleNameCS();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleNameCSContext ------------------------------------------------------------------

OclParser::SimpleNameCSContext::SimpleNameCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::SimpleNameCSContext::ID() {
  return getToken(OclParser::ID, 0);
}


size_t OclParser::SimpleNameCSContext::getRuleIndex() const {
  return OclParser::RuleSimpleNameCS;
}


std::any OclParser::SimpleNameCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitSimpleNameCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::SimpleNameCSContext* OclParser::simpleNameCS() {
  SimpleNameCSContext *_localctx = _tracker.createInstance<SimpleNameCSContext>(_ctx, getState());
  enterRule(_localctx, 8, OclParser::RuleSimpleNameCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(OclParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RestrictedKeywordCSContext ------------------------------------------------------------------

OclParser::RestrictedKeywordCSContext::RestrictedKeywordCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::CollectionTypeIdentifierCSContext* OclParser::RestrictedKeywordCSContext::collectionTypeIdentifierCS() {
  return getRuleContext<OclParser::CollectionTypeIdentifierCSContext>(0);
}

OclParser::PrimitiveTypeCSContext* OclParser::RestrictedKeywordCSContext::primitiveTypeCS() {
  return getRuleContext<OclParser::PrimitiveTypeCSContext>(0);
}

OclParser::OclTypeCSContext* OclParser::RestrictedKeywordCSContext::oclTypeCS() {
  return getRuleContext<OclParser::OclTypeCSContext>(0);
}

tree::TerminalNode* OclParser::RestrictedKeywordCSContext::TUPLE() {
  return getToken(OclParser::TUPLE, 0);
}


size_t OclParser::RestrictedKeywordCSContext::getRuleIndex() const {
  return OclParser::RuleRestrictedKeywordCS;
}


std::any OclParser::RestrictedKeywordCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitRestrictedKeywordCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::RestrictedKeywordCSContext* OclParser::restrictedKeywordCS() {
  RestrictedKeywordCSContext *_localctx = _tracker.createInstance<RestrictedKeywordCSContext>(_ctx, getState());
  enterRule(_localctx, 10, OclParser::RuleRestrictedKeywordCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::COLLECTION:
      case OclParser::BAG:
      case OclParser::ORDEREDSET:
      case OclParser::SEQUENCE:
      case OclParser::SET: {
        enterOuterAlt(_localctx, 1);
        setState(169);
        collectionTypeIdentifierCS();
        break;
      }

      case OclParser::OCLBOOLEAN:
      case OclParser::OCLINTEGER:
      case OclParser::OCLREAL:
      case OclParser::OCLSTRING:
      case OclParser::OCLUNLIMITEDNAT: {
        enterOuterAlt(_localctx, 2);
        setState(170);
        primitiveTypeCS();
        break;
      }

      case OclParser::OCLANY:
      case OclParser::OCLINVALID:
      case OclParser::OCLMESSAGE:
      case OclParser::OCLVOID: {
        enterOuterAlt(_localctx, 3);
        setState(171);
        oclTypeCS();
        break;
      }

      case OclParser::TUPLE: {
        enterOuterAlt(_localctx, 4);
        setState(172);
        match(OclParser::TUPLE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnreservedSimpleNameCSContext ------------------------------------------------------------------

OclParser::UnreservedSimpleNameCSContext::UnreservedSimpleNameCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::SimpleNameCSContext* OclParser::UnreservedSimpleNameCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

OclParser::RestrictedKeywordCSContext* OclParser::UnreservedSimpleNameCSContext::restrictedKeywordCS() {
  return getRuleContext<OclParser::RestrictedKeywordCSContext>(0);
}


size_t OclParser::UnreservedSimpleNameCSContext::getRuleIndex() const {
  return OclParser::RuleUnreservedSimpleNameCS;
}


std::any OclParser::UnreservedSimpleNameCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitUnreservedSimpleNameCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::UnreservedSimpleNameCSContext* OclParser::unreservedSimpleNameCS() {
  UnreservedSimpleNameCSContext *_localctx = _tracker.createInstance<UnreservedSimpleNameCSContext>(_ctx, getState());
  enterRule(_localctx, 12, OclParser::RuleUnreservedSimpleNameCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        simpleNameCS();
        break;
      }

      case OclParser::TUPLE:
      case OclParser::COLLECTION:
      case OclParser::BAG:
      case OclParser::ORDEREDSET:
      case OclParser::SEQUENCE:
      case OclParser::SET:
      case OclParser::OCLBOOLEAN:
      case OclParser::OCLINTEGER:
      case OclParser::OCLREAL:
      case OclParser::OCLSTRING:
      case OclParser::OCLUNLIMITEDNAT:
      case OclParser::OCLANY:
      case OclParser::OCLINVALID:
      case OclParser::OCLMESSAGE:
      case OclParser::OCLVOID: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        restrictedKeywordCS();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathNameCSContext ------------------------------------------------------------------

OclParser::PathNameCSContext::PathNameCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::SimpleNameCSContext* OclParser::PathNameCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

OclParser::PathNameCSContext* OclParser::PathNameCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::PathNameCSContext::COLONCOLON() {
  return getToken(OclParser::COLONCOLON, 0);
}

OclParser::UnreservedSimpleNameCSContext* OclParser::PathNameCSContext::unreservedSimpleNameCS() {
  return getRuleContext<OclParser::UnreservedSimpleNameCSContext>(0);
}


size_t OclParser::PathNameCSContext::getRuleIndex() const {
  return OclParser::RulePathNameCS;
}


std::any OclParser::PathNameCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPathNameCS(this);
  else
    return visitor->visitChildren(this);
}


OclParser::PathNameCSContext* OclParser::pathNameCS() {
   return pathNameCS(0);
}

OclParser::PathNameCSContext* OclParser::pathNameCS(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  OclParser::PathNameCSContext *_localctx = _tracker.createInstance<PathNameCSContext>(_ctx, parentState);
  OclParser::PathNameCSContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, OclParser::RulePathNameCS, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(180);
    simpleNameCS();
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PathNameCSContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePathNameCS);
        setState(182);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(183);
        match(OclParser::COLONCOLON);
        setState(184);
        unreservedSimpleNameCS(); 
      }
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LiteralExpCSContext ------------------------------------------------------------------

OclParser::LiteralExpCSContext::LiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::EnumLiteralExpCSContext* OclParser::LiteralExpCSContext::enumLiteralExpCS() {
  return getRuleContext<OclParser::EnumLiteralExpCSContext>(0);
}

OclParser::CollectionLiteralExpCSContext* OclParser::LiteralExpCSContext::collectionLiteralExpCS() {
  return getRuleContext<OclParser::CollectionLiteralExpCSContext>(0);
}

OclParser::TupleLiteralExpCSContext* OclParser::LiteralExpCSContext::tupleLiteralExpCS() {
  return getRuleContext<OclParser::TupleLiteralExpCSContext>(0);
}

OclParser::PrimitiveLiteralExpCSContext* OclParser::LiteralExpCSContext::primitiveLiteralExpCS() {
  return getRuleContext<OclParser::PrimitiveLiteralExpCSContext>(0);
}

OclParser::TypeLiteralExpCSContext* OclParser::LiteralExpCSContext::typeLiteralExpCS() {
  return getRuleContext<OclParser::TypeLiteralExpCSContext>(0);
}


size_t OclParser::LiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleLiteralExpCS;
}


std::any OclParser::LiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::LiteralExpCSContext* OclParser::literalExpCS() {
  LiteralExpCSContext *_localctx = _tracker.createInstance<LiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 16, OclParser::RuleLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(190);
      enumLiteralExpCS();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(191);
      collectionLiteralExpCS();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(192);
      tupleLiteralExpCS();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(193);
      primitiveLiteralExpCS();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(194);
      typeLiteralExpCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumLiteralExpCSContext ------------------------------------------------------------------

OclParser::EnumLiteralExpCSContext::EnumLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::PathNameCSContext* OclParser::EnumLiteralExpCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::EnumLiteralExpCSContext::COLONCOLON() {
  return getToken(OclParser::COLONCOLON, 0);
}

OclParser::SimpleNameCSContext* OclParser::EnumLiteralExpCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}


size_t OclParser::EnumLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleEnumLiteralExpCS;
}


std::any OclParser::EnumLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitEnumLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::EnumLiteralExpCSContext* OclParser::enumLiteralExpCS() {
  EnumLiteralExpCSContext *_localctx = _tracker.createInstance<EnumLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 18, OclParser::RuleEnumLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    pathNameCS(0);
    setState(198);
    match(OclParser::COLONCOLON);
    setState(199);
    simpleNameCS();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CollectionLiteralExpCSContext ------------------------------------------------------------------

OclParser::CollectionLiteralExpCSContext::CollectionLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::CollectionTypeIdentifierCSContext* OclParser::CollectionLiteralExpCSContext::collectionTypeIdentifierCS() {
  return getRuleContext<OclParser::CollectionTypeIdentifierCSContext>(0);
}

tree::TerminalNode* OclParser::CollectionLiteralExpCSContext::LBRACE() {
  return getToken(OclParser::LBRACE, 0);
}

tree::TerminalNode* OclParser::CollectionLiteralExpCSContext::RBRACE() {
  return getToken(OclParser::RBRACE, 0);
}

OclParser::CollectionLiteralPartsCSContext* OclParser::CollectionLiteralExpCSContext::collectionLiteralPartsCS() {
  return getRuleContext<OclParser::CollectionLiteralPartsCSContext>(0);
}


size_t OclParser::CollectionLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleCollectionLiteralExpCS;
}


std::any OclParser::CollectionLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitCollectionLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::CollectionLiteralExpCSContext* OclParser::collectionLiteralExpCS() {
  CollectionLiteralExpCSContext *_localctx = _tracker.createInstance<CollectionLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 20, OclParser::RuleCollectionLiteralExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    collectionTypeIdentifierCS();

    setState(202);
    match(OclParser::LBRACE);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4611984535817567492) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & 11) != 0)) {
      setState(203);
      collectionLiteralPartsCS();
    }
    setState(206);
    match(OclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CollectionTypeIdentifierCSContext ------------------------------------------------------------------

OclParser::CollectionTypeIdentifierCSContext::CollectionTypeIdentifierCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::CollectionTypeIdentifierCSContext::SET() {
  return getToken(OclParser::SET, 0);
}

tree::TerminalNode* OclParser::CollectionTypeIdentifierCSContext::BAG() {
  return getToken(OclParser::BAG, 0);
}

tree::TerminalNode* OclParser::CollectionTypeIdentifierCSContext::SEQUENCE() {
  return getToken(OclParser::SEQUENCE, 0);
}

tree::TerminalNode* OclParser::CollectionTypeIdentifierCSContext::COLLECTION() {
  return getToken(OclParser::COLLECTION, 0);
}

tree::TerminalNode* OclParser::CollectionTypeIdentifierCSContext::ORDEREDSET() {
  return getToken(OclParser::ORDEREDSET, 0);
}


size_t OclParser::CollectionTypeIdentifierCSContext::getRuleIndex() const {
  return OclParser::RuleCollectionTypeIdentifierCS;
}


std::any OclParser::CollectionTypeIdentifierCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitCollectionTypeIdentifierCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::CollectionTypeIdentifierCSContext* OclParser::collectionTypeIdentifierCS() {
  CollectionTypeIdentifierCSContext *_localctx = _tracker.createInstance<CollectionTypeIdentifierCSContext>(_ctx, getState());
  enterRule(_localctx, 22, OclParser::RuleCollectionTypeIdentifierCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 520093696) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CollectionLiteralPartsCSContext ------------------------------------------------------------------

OclParser::CollectionLiteralPartsCSContext::CollectionLiteralPartsCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OclParser::CollectionRangeCSContext *> OclParser::CollectionLiteralPartsCSContext::collectionRangeCS() {
  return getRuleContexts<OclParser::CollectionRangeCSContext>();
}

OclParser::CollectionRangeCSContext* OclParser::CollectionLiteralPartsCSContext::collectionRangeCS(size_t i) {
  return getRuleContext<OclParser::CollectionRangeCSContext>(i);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::CollectionLiteralPartsCSContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::CollectionLiteralPartsCSContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

std::vector<tree::TerminalNode *> OclParser::CollectionLiteralPartsCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::CollectionLiteralPartsCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::CollectionLiteralPartsCSContext::getRuleIndex() const {
  return OclParser::RuleCollectionLiteralPartsCS;
}


std::any OclParser::CollectionLiteralPartsCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitCollectionLiteralPartsCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::CollectionLiteralPartsCSContext* OclParser::collectionLiteralPartsCS() {
  CollectionLiteralPartsCSContext *_localctx = _tracker.createInstance<CollectionLiteralPartsCSContext>(_ctx, getState());
  enterRule(_localctx, 24, OclParser::RuleCollectionLiteralPartsCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(210);
      collectionRangeCS();
      break;
    }

    case 2: {
      setState(211);
      oclExpressionCS(0);
      break;
    }

    default:
      break;
    }
    setState(221);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == OclParser::COMMA) {
      setState(214);
      match(OclParser::COMMA);
      setState(217);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(215);
        collectionRangeCS();
        break;
      }

      case 2: {
        setState(216);
        oclExpressionCS(0);
        break;
      }

      default:
        break;
      }
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CollectionRangeCSContext ------------------------------------------------------------------

OclParser::CollectionRangeCSContext::CollectionRangeCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::CollectionRangeCSContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::CollectionRangeCSContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

tree::TerminalNode* OclParser::CollectionRangeCSContext::RANGE() {
  return getToken(OclParser::RANGE, 0);
}

tree::TerminalNode* OclParser::CollectionRangeCSContext::SEQRANGE() {
  return getToken(OclParser::SEQRANGE, 0);
}


size_t OclParser::CollectionRangeCSContext::getRuleIndex() const {
  return OclParser::RuleCollectionRangeCS;
}


std::any OclParser::CollectionRangeCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitCollectionRangeCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::CollectionRangeCSContext* OclParser::collectionRangeCS() {
  CollectionRangeCSContext *_localctx = _tracker.createInstance<CollectionRangeCSContext>(_ctx, getState());
  enterRule(_localctx, 26, OclParser::RuleCollectionRangeCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::IF:
      case OclParser::LET:
      case OclParser::SELF:
      case OclParser::TUPLE:
      case OclParser::NULLEXP:
      case OclParser::INVALID:
      case OclParser::COLLECTION:
      case OclParser::BAG:
      case OclParser::ORDEREDSET:
      case OclParser::SEQUENCE:
      case OclParser::SET:
      case OclParser::OCLBOOLEAN:
      case OclParser::OCLINTEGER:
      case OclParser::OCLREAL:
      case OclParser::OCLSTRING:
      case OclParser::OCLUNLIMITEDNAT:
      case OclParser::OCLANY:
      case OclParser::OCLINVALID:
      case OclParser::OCLMESSAGE:
      case OclParser::OCLVOID:
      case OclParser::INT:
      case OclParser::REAL:
      case OclParser::BOOL:
      case OclParser::STRING_LITERAL:
      case OclParser::LPAREN:
      case OclParser::STAR:
      case OclParser::MINUS:
      case OclParser::NOT:
      case OclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        oclExpressionCS(0);
        setState(225);
        match(OclParser::RANGE);
        setState(226);
        oclExpressionCS(0);
        break;
      }

      case OclParser::SEQRANGE: {
        enterOuterAlt(_localctx, 2);
        setState(228);
        match(OclParser::SEQRANGE);
        setState(229);
        oclExpressionCS(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrefixedExpContext ------------------------------------------------------------------

OclParser::PrefixedExpContext::PrefixedExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::UnaryLiteralExpCSContext* OclParser::PrefixedExpContext::unaryLiteralExpCS() {
  return getRuleContext<OclParser::UnaryLiteralExpCSContext>(0);
}

OclParser::OclExpressionCSContext* OclParser::PrefixedExpContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}


size_t OclParser::PrefixedExpContext::getRuleIndex() const {
  return OclParser::RulePrefixedExp;
}


std::any OclParser::PrefixedExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPrefixedExp(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PrefixedExpContext* OclParser::prefixedExp() {
  PrefixedExpContext *_localctx = _tracker.createInstance<PrefixedExpContext>(_ctx, getState());
  enterRule(_localctx, 28, OclParser::RulePrefixedExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    unaryLiteralExpCS();
    setState(233);
    oclExpressionCS(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveLiteralExpCSContext ------------------------------------------------------------------

OclParser::PrimitiveLiteralExpCSContext::PrimitiveLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::IntegerLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::integerLiteralExpCS() {
  return getRuleContext<OclParser::IntegerLiteralExpCSContext>(0);
}

OclParser::RealLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::realLiteralExpCS() {
  return getRuleContext<OclParser::RealLiteralExpCSContext>(0);
}

OclParser::StringLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::stringLiteralExpCS() {
  return getRuleContext<OclParser::StringLiteralExpCSContext>(0);
}

OclParser::BooleanLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::booleanLiteralExpCS() {
  return getRuleContext<OclParser::BooleanLiteralExpCSContext>(0);
}

OclParser::UnlimitedNaturalLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::unlimitedNaturalLiteralExpCS() {
  return getRuleContext<OclParser::UnlimitedNaturalLiteralExpCSContext>(0);
}

OclParser::NullLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::nullLiteralExpCS() {
  return getRuleContext<OclParser::NullLiteralExpCSContext>(0);
}

OclParser::InvalidLiteralExpCSContext* OclParser::PrimitiveLiteralExpCSContext::invalidLiteralExpCS() {
  return getRuleContext<OclParser::InvalidLiteralExpCSContext>(0);
}


size_t OclParser::PrimitiveLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RulePrimitiveLiteralExpCS;
}


std::any OclParser::PrimitiveLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPrimitiveLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PrimitiveLiteralExpCSContext* OclParser::primitiveLiteralExpCS() {
  PrimitiveLiteralExpCSContext *_localctx = _tracker.createInstance<PrimitiveLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 30, OclParser::RulePrimitiveLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(235);
      integerLiteralExpCS();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(236);
      realLiteralExpCS();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(237);
      stringLiteralExpCS();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(238);
      booleanLiteralExpCS();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(239);
      unlimitedNaturalLiteralExpCS();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(240);
      nullLiteralExpCS();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(241);
      invalidLiteralExpCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TupleLiteralExpCSContext ------------------------------------------------------------------

OclParser::TupleLiteralExpCSContext::TupleLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::TupleLiteralExpCSContext::TUPLE() {
  return getToken(OclParser::TUPLE, 0);
}

tree::TerminalNode* OclParser::TupleLiteralExpCSContext::LBRACE() {
  return getToken(OclParser::LBRACE, 0);
}

tree::TerminalNode* OclParser::TupleLiteralExpCSContext::RBRACE() {
  return getToken(OclParser::RBRACE, 0);
}

std::vector<OclParser::VariableDeclarationCSContext *> OclParser::TupleLiteralExpCSContext::variableDeclarationCS() {
  return getRuleContexts<OclParser::VariableDeclarationCSContext>();
}

OclParser::VariableDeclarationCSContext* OclParser::TupleLiteralExpCSContext::variableDeclarationCS(size_t i) {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(i);
}

std::vector<tree::TerminalNode *> OclParser::TupleLiteralExpCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::TupleLiteralExpCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::TupleLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleTupleLiteralExpCS;
}


std::any OclParser::TupleLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitTupleLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::TupleLiteralExpCSContext* OclParser::tupleLiteralExpCS() {
  TupleLiteralExpCSContext *_localctx = _tracker.createInstance<TupleLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 32, OclParser::RuleTupleLiteralExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(OclParser::TUPLE);
    setState(245);
    match(OclParser::LBRACE);
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OclParser::ID) {
      setState(246);
      variableDeclarationCS();
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == OclParser::COMMA) {
        setState(247);
        match(OclParser::COMMA);
        setState(248);
        variableDeclarationCS();
        setState(253);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(256);
    match(OclParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnlimitedNaturalLiteralExpCSContext ------------------------------------------------------------------

OclParser::UnlimitedNaturalLiteralExpCSContext::UnlimitedNaturalLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::UnlimitedNaturalLiteralExpCSContext::INT() {
  return getToken(OclParser::INT, 0);
}

tree::TerminalNode* OclParser::UnlimitedNaturalLiteralExpCSContext::STAR() {
  return getToken(OclParser::STAR, 0);
}


size_t OclParser::UnlimitedNaturalLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleUnlimitedNaturalLiteralExpCS;
}


std::any OclParser::UnlimitedNaturalLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitUnlimitedNaturalLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::UnlimitedNaturalLiteralExpCSContext* OclParser::unlimitedNaturalLiteralExpCS() {
  UnlimitedNaturalLiteralExpCSContext *_localctx = _tracker.createInstance<UnlimitedNaturalLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 34, OclParser::RuleUnlimitedNaturalLiteralExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    _la = _input->LA(1);
    if (!(_la == OclParser::INT

    || _la == OclParser::STAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerLiteralExpCSContext ------------------------------------------------------------------

OclParser::IntegerLiteralExpCSContext::IntegerLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::IntegerLiteralExpCSContext::INT() {
  return getToken(OclParser::INT, 0);
}


size_t OclParser::IntegerLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleIntegerLiteralExpCS;
}


std::any OclParser::IntegerLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::IntegerLiteralExpCSContext* OclParser::integerLiteralExpCS() {
  IntegerLiteralExpCSContext *_localctx = _tracker.createInstance<IntegerLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 36, OclParser::RuleIntegerLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(OclParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealLiteralExpCSContext ------------------------------------------------------------------

OclParser::RealLiteralExpCSContext::RealLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::RealLiteralExpCSContext::REAL() {
  return getToken(OclParser::REAL, 0);
}


size_t OclParser::RealLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleRealLiteralExpCS;
}


std::any OclParser::RealLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitRealLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::RealLiteralExpCSContext* OclParser::realLiteralExpCS() {
  RealLiteralExpCSContext *_localctx = _tracker.createInstance<RealLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 38, OclParser::RuleRealLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(OclParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringLiteralExpCSContext ------------------------------------------------------------------

OclParser::StringLiteralExpCSContext::StringLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::StringLiteralExpCSContext::STRING_LITERAL() {
  return getToken(OclParser::STRING_LITERAL, 0);
}


size_t OclParser::StringLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleStringLiteralExpCS;
}


std::any OclParser::StringLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitStringLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::StringLiteralExpCSContext* OclParser::stringLiteralExpCS() {
  StringLiteralExpCSContext *_localctx = _tracker.createInstance<StringLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 40, OclParser::RuleStringLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(OclParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralExpCSContext ------------------------------------------------------------------

OclParser::BooleanLiteralExpCSContext::BooleanLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::BooleanLiteralExpCSContext::BOOL() {
  return getToken(OclParser::BOOL, 0);
}


size_t OclParser::BooleanLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleBooleanLiteralExpCS;
}


std::any OclParser::BooleanLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::BooleanLiteralExpCSContext* OclParser::booleanLiteralExpCS() {
  BooleanLiteralExpCSContext *_localctx = _tracker.createInstance<BooleanLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 42, OclParser::RuleBooleanLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(OclParser::BOOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeLiteralExpCSContext ------------------------------------------------------------------

OclParser::TypeLiteralExpCSContext::TypeLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::TypeCSContext* OclParser::TypeLiteralExpCSContext::typeCS() {
  return getRuleContext<OclParser::TypeCSContext>(0);
}


size_t OclParser::TypeLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleTypeLiteralExpCS;
}


std::any OclParser::TypeLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitTypeLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::TypeLiteralExpCSContext* OclParser::typeLiteralExpCS() {
  TypeLiteralExpCSContext *_localctx = _tracker.createInstance<TypeLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 44, OclParser::RuleTypeLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    typeCS();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IteratorExpCSContext ------------------------------------------------------------------

OclParser::IteratorExpCSContext::IteratorExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::IteratorExpCSContext::RARROW() {
  return getToken(OclParser::RARROW, 0);
}

OclParser::SimpleNameCSContext* OclParser::IteratorExpCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::IteratorExpCSContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::IteratorExpCSContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

std::vector<OclParser::VariableDeclarationCSContext *> OclParser::IteratorExpCSContext::variableDeclarationCS() {
  return getRuleContexts<OclParser::VariableDeclarationCSContext>();
}

OclParser::VariableDeclarationCSContext* OclParser::IteratorExpCSContext::variableDeclarationCS(size_t i) {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(i);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::PIPE() {
  return getToken(OclParser::PIPE, 0);
}

std::vector<tree::TerminalNode *> OclParser::IteratorExpCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::DOT() {
  return getToken(OclParser::DOT, 0);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::LBRACK() {
  return getToken(OclParser::LBRACK, 0);
}

tree::TerminalNode* OclParser::IteratorExpCSContext::RBRACK() {
  return getToken(OclParser::RBRACK, 0);
}


size_t OclParser::IteratorExpCSContext::getRuleIndex() const {
  return OclParser::RuleIteratorExpCS;
}


std::any OclParser::IteratorExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitIteratorExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::IteratorExpCSContext* OclParser::iteratorExpCS() {
  IteratorExpCSContext *_localctx = _tracker.createInstance<IteratorExpCSContext>(_ctx, getState());
  enterRule(_localctx, 46, OclParser::RuleIteratorExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(270);
      match(OclParser::RARROW);
      setState(271);
      simpleNameCS();
      setState(272);
      match(OclParser::LPAREN);
      setState(280);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(273);
        variableDeclarationCS();
        setState(276);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == OclParser::COMMA) {
          setState(274);
          match(OclParser::COMMA);
          setState(275);
          variableDeclarationCS();
        }
        setState(278);
        match(OclParser::PIPE);
        break;
      }

      default:
        break;
      }
      setState(282);
      oclExpressionCS(0);
      setState(283);
      match(OclParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(285);
      match(OclParser::DOT);
      setState(286);
      simpleNameCS();
      setState(287);
      match(OclParser::LPAREN);
      setState(296);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(288);
        oclExpressionCS(0);
        setState(293);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(289);
          match(OclParser::COMMA);
          setState(290);
          oclExpressionCS(0);
          setState(295);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(298);
      match(OclParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(300);
      match(OclParser::DOT);
      setState(301);
      simpleNameCS();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(302);
      match(OclParser::DOT);
      setState(303);
      simpleNameCS();
      setState(315);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(304);
        match(OclParser::LBRACK);

        setState(305);
        oclExpressionCS(0);
        setState(310);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(306);
          match(OclParser::COMMA);
          setState(307);
          oclExpressionCS(0);
          setState(312);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(313);
        match(OclParser::RBRACK);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterateExpCSContext ------------------------------------------------------------------

OclParser::IterateExpCSContext::IterateExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::IterateExpCSContext::RARROW() {
  return getToken(OclParser::RARROW, 0);
}

tree::TerminalNode* OclParser::IterateExpCSContext::ITERATE() {
  return getToken(OclParser::ITERATE, 0);
}

tree::TerminalNode* OclParser::IterateExpCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

std::vector<OclParser::VariableDeclarationCSContext *> OclParser::IterateExpCSContext::variableDeclarationCS() {
  return getRuleContexts<OclParser::VariableDeclarationCSContext>();
}

OclParser::VariableDeclarationCSContext* OclParser::IterateExpCSContext::variableDeclarationCS(size_t i) {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(i);
}

tree::TerminalNode* OclParser::IterateExpCSContext::PIPE() {
  return getToken(OclParser::PIPE, 0);
}

OclParser::OclExpressionCSContext* OclParser::IterateExpCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

tree::TerminalNode* OclParser::IterateExpCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

tree::TerminalNode* OclParser::IterateExpCSContext::SEMI() {
  return getToken(OclParser::SEMI, 0);
}


size_t OclParser::IterateExpCSContext::getRuleIndex() const {
  return OclParser::RuleIterateExpCS;
}


std::any OclParser::IterateExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitIterateExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::IterateExpCSContext* OclParser::iterateExpCS() {
  IterateExpCSContext *_localctx = _tracker.createInstance<IterateExpCSContext>(_ctx, getState());
  enterRule(_localctx, 48, OclParser::RuleIterateExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(OclParser::RARROW);
    setState(320);
    match(OclParser::ITERATE);
    setState(321);
    match(OclParser::LPAREN);
    setState(325);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(322);
      variableDeclarationCS();
      setState(323);
      match(OclParser::SEMI);
      break;
    }

    default:
      break;
    }
    setState(327);
    variableDeclarationCS();
    setState(328);
    match(OclParser::PIPE);
    setState(329);
    oclExpressionCS(0);
    setState(330);
    match(OclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationCSContext ------------------------------------------------------------------

OclParser::VariableDeclarationCSContext::VariableDeclarationCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::SimpleNameCSContext* OclParser::VariableDeclarationCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::VariableDeclarationCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}

OclParser::TypeCSContext* OclParser::VariableDeclarationCSContext::typeCS() {
  return getRuleContext<OclParser::TypeCSContext>(0);
}

tree::TerminalNode* OclParser::VariableDeclarationCSContext::ASSIGN() {
  return getToken(OclParser::ASSIGN, 0);
}

OclParser::OclExpressionCSContext* OclParser::VariableDeclarationCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}


size_t OclParser::VariableDeclarationCSContext::getRuleIndex() const {
  return OclParser::RuleVariableDeclarationCS;
}


std::any OclParser::VariableDeclarationCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::VariableDeclarationCSContext* OclParser::variableDeclarationCS() {
  VariableDeclarationCSContext *_localctx = _tracker.createInstance<VariableDeclarationCSContext>(_ctx, getState());
  enterRule(_localctx, 50, OclParser::RuleVariableDeclarationCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    simpleNameCS();
    setState(335);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OclParser::COLON) {
      setState(333);
      match(OclParser::COLON);
      setState(334);
      typeCS();
    }
    setState(339);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(337);
      match(OclParser::ASSIGN);
      setState(338);
      oclExpressionCS(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeCSContext ------------------------------------------------------------------

OclParser::TypeCSContext::TypeCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::PathNameCSContext* OclParser::TypeCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

OclParser::CollectionTypeCSContext* OclParser::TypeCSContext::collectionTypeCS() {
  return getRuleContext<OclParser::CollectionTypeCSContext>(0);
}

OclParser::TupleTypeCSContext* OclParser::TypeCSContext::tupleTypeCS() {
  return getRuleContext<OclParser::TupleTypeCSContext>(0);
}

OclParser::PrimitiveTypeCSContext* OclParser::TypeCSContext::primitiveTypeCS() {
  return getRuleContext<OclParser::PrimitiveTypeCSContext>(0);
}

OclParser::OclTypeCSContext* OclParser::TypeCSContext::oclTypeCS() {
  return getRuleContext<OclParser::OclTypeCSContext>(0);
}


size_t OclParser::TypeCSContext::getRuleIndex() const {
  return OclParser::RuleTypeCS;
}


std::any OclParser::TypeCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitTypeCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::TypeCSContext* OclParser::typeCS() {
  TypeCSContext *_localctx = _tracker.createInstance<TypeCSContext>(_ctx, getState());
  enterRule(_localctx, 52, OclParser::RuleTypeCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(341);
        pathNameCS(0);
        break;
      }

      case OclParser::COLLECTION:
      case OclParser::BAG:
      case OclParser::ORDEREDSET:
      case OclParser::SEQUENCE:
      case OclParser::SET: {
        enterOuterAlt(_localctx, 2);
        setState(342);
        collectionTypeCS();
        break;
      }

      case OclParser::TUPLE: {
        enterOuterAlt(_localctx, 3);
        setState(343);
        tupleTypeCS();
        break;
      }

      case OclParser::OCLBOOLEAN:
      case OclParser::OCLINTEGER:
      case OclParser::OCLREAL:
      case OclParser::OCLSTRING:
      case OclParser::OCLUNLIMITEDNAT: {
        enterOuterAlt(_localctx, 4);
        setState(344);
        primitiveTypeCS();
        break;
      }

      case OclParser::OCLANY:
      case OclParser::OCLINVALID:
      case OclParser::OCLMESSAGE:
      case OclParser::OCLVOID: {
        enterOuterAlt(_localctx, 5);
        setState(345);
        oclTypeCS();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveTypeCSContext ------------------------------------------------------------------

OclParser::PrimitiveTypeCSContext::PrimitiveTypeCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::PrimitiveTypeCSContext::OCLBOOLEAN() {
  return getToken(OclParser::OCLBOOLEAN, 0);
}

tree::TerminalNode* OclParser::PrimitiveTypeCSContext::OCLINTEGER() {
  return getToken(OclParser::OCLINTEGER, 0);
}

tree::TerminalNode* OclParser::PrimitiveTypeCSContext::OCLREAL() {
  return getToken(OclParser::OCLREAL, 0);
}

tree::TerminalNode* OclParser::PrimitiveTypeCSContext::OCLSTRING() {
  return getToken(OclParser::OCLSTRING, 0);
}

tree::TerminalNode* OclParser::PrimitiveTypeCSContext::OCLUNLIMITEDNAT() {
  return getToken(OclParser::OCLUNLIMITEDNAT, 0);
}


size_t OclParser::PrimitiveTypeCSContext::getRuleIndex() const {
  return OclParser::RulePrimitiveTypeCS;
}


std::any OclParser::PrimitiveTypeCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPrimitiveTypeCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PrimitiveTypeCSContext* OclParser::primitiveTypeCS() {
  PrimitiveTypeCSContext *_localctx = _tracker.createInstance<PrimitiveTypeCSContext>(_ctx, getState());
  enterRule(_localctx, 54, OclParser::RulePrimitiveTypeCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16642998272) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OclTypeCSContext ------------------------------------------------------------------

OclParser::OclTypeCSContext::OclTypeCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::OclTypeCSContext::OCLANY() {
  return getToken(OclParser::OCLANY, 0);
}

tree::TerminalNode* OclParser::OclTypeCSContext::OCLINVALID() {
  return getToken(OclParser::OCLINVALID, 0);
}

tree::TerminalNode* OclParser::OclTypeCSContext::OCLMESSAGE() {
  return getToken(OclParser::OCLMESSAGE, 0);
}

tree::TerminalNode* OclParser::OclTypeCSContext::OCLVOID() {
  return getToken(OclParser::OCLVOID, 0);
}


size_t OclParser::OclTypeCSContext::getRuleIndex() const {
  return OclParser::RuleOclTypeCS;
}


std::any OclParser::OclTypeCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOclTypeCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OclTypeCSContext* OclParser::oclTypeCS() {
  OclTypeCSContext *_localctx = _tracker.createInstance<OclTypeCSContext>(_ctx, getState());
  enterRule(_localctx, 56, OclParser::RuleOclTypeCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396075520) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CollectionTypeCSContext ------------------------------------------------------------------

OclParser::CollectionTypeCSContext::CollectionTypeCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::CollectionTypeIdentifierCSContext* OclParser::CollectionTypeCSContext::collectionTypeIdentifierCS() {
  return getRuleContext<OclParser::CollectionTypeIdentifierCSContext>(0);
}

tree::TerminalNode* OclParser::CollectionTypeCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

OclParser::TypeCSContext* OclParser::CollectionTypeCSContext::typeCS() {
  return getRuleContext<OclParser::TypeCSContext>(0);
}

tree::TerminalNode* OclParser::CollectionTypeCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}


size_t OclParser::CollectionTypeCSContext::getRuleIndex() const {
  return OclParser::RuleCollectionTypeCS;
}


std::any OclParser::CollectionTypeCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitCollectionTypeCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::CollectionTypeCSContext* OclParser::collectionTypeCS() {
  CollectionTypeCSContext *_localctx = _tracker.createInstance<CollectionTypeCSContext>(_ctx, getState());
  enterRule(_localctx, 58, OclParser::RuleCollectionTypeCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    collectionTypeIdentifierCS();
    setState(353);
    match(OclParser::LPAREN);
    setState(354);
    typeCS();
    setState(355);
    match(OclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TupleTypeCSContext ------------------------------------------------------------------

OclParser::TupleTypeCSContext::TupleTypeCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::TupleTypeCSContext::TUPLE() {
  return getToken(OclParser::TUPLE, 0);
}

tree::TerminalNode* OclParser::TupleTypeCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

tree::TerminalNode* OclParser::TupleTypeCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

std::vector<OclParser::VariableDeclarationCSContext *> OclParser::TupleTypeCSContext::variableDeclarationCS() {
  return getRuleContexts<OclParser::VariableDeclarationCSContext>();
}

OclParser::VariableDeclarationCSContext* OclParser::TupleTypeCSContext::variableDeclarationCS(size_t i) {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(i);
}

std::vector<tree::TerminalNode *> OclParser::TupleTypeCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::TupleTypeCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::TupleTypeCSContext::getRuleIndex() const {
  return OclParser::RuleTupleTypeCS;
}


std::any OclParser::TupleTypeCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitTupleTypeCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::TupleTypeCSContext* OclParser::tupleTypeCS() {
  TupleTypeCSContext *_localctx = _tracker.createInstance<TupleTypeCSContext>(_ctx, getState());
  enterRule(_localctx, 60, OclParser::RuleTupleTypeCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(OclParser::TUPLE);
    setState(358);
    match(OclParser::LPAREN);
    setState(367);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OclParser::ID) {
      setState(359);
      variableDeclarationCS();
      setState(364);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == OclParser::COMMA) {
        setState(360);
        match(OclParser::COMMA);
        setState(361);
        variableDeclarationCS();
        setState(366);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(369);
    match(OclParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationCallExpCS_AContext ------------------------------------------------------------------

OclParser::OperationCallExpCS_AContext::OperationCallExpCS_AContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::OperationCallExpCS_AContext::RARROW() {
  return getToken(OclParser::RARROW, 0);
}

OclParser::SimpleNameCSContext* OclParser::OperationCallExpCS_AContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::OperationCallExpCS_AContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

tree::TerminalNode* OclParser::OperationCallExpCS_AContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::OperationCallExpCS_AContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::OperationCallExpCS_AContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

std::vector<tree::TerminalNode *> OclParser::OperationCallExpCS_AContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::OperationCallExpCS_AContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}

tree::TerminalNode* OclParser::OperationCallExpCS_AContext::DOT() {
  return getToken(OclParser::DOT, 0);
}

OclParser::IsMarkedPreCSContext* OclParser::OperationCallExpCS_AContext::isMarkedPreCS() {
  return getRuleContext<OclParser::IsMarkedPreCSContext>(0);
}

OclParser::PathNameCSContext* OclParser::OperationCallExpCS_AContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::OperationCallExpCS_AContext::COLONCOLON() {
  return getToken(OclParser::COLONCOLON, 0);
}


size_t OclParser::OperationCallExpCS_AContext::getRuleIndex() const {
  return OclParser::RuleOperationCallExpCS_A;
}


std::any OclParser::OperationCallExpCS_AContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOperationCallExpCS_A(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OperationCallExpCS_AContext* OclParser::operationCallExpCS_A() {
  OperationCallExpCS_AContext *_localctx = _tracker.createInstance<OperationCallExpCS_AContext>(_ctx, getState());
  enterRule(_localctx, 62, OclParser::RuleOperationCallExpCS_A);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(452);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(371);
      match(OclParser::RARROW);
      setState(372);
      simpleNameCS();
      setState(373);
      match(OclParser::LPAREN);
      setState(382);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(374);
        oclExpressionCS(0);
        setState(379);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(375);
          match(OclParser::COMMA);
          setState(376);
          oclExpressionCS(0);
          setState(381);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(384);
      match(OclParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(386);
      match(OclParser::DOT);
      setState(387);
      simpleNameCS();
      setState(388);
      match(OclParser::LPAREN);
      setState(397);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(389);
        oclExpressionCS(0);
        setState(394);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(390);
          match(OclParser::COMMA);
          setState(391);
          oclExpressionCS(0);
          setState(396);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(399);
      match(OclParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(401);
      match(OclParser::DOT);
      setState(402);
      simpleNameCS();
      setState(403);
      isMarkedPreCS();
      setState(404);
      match(OclParser::LPAREN);
      setState(413);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(405);
        oclExpressionCS(0);
        setState(410);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(406);
          match(OclParser::COMMA);
          setState(407);
          oclExpressionCS(0);
          setState(412);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(415);
      match(OclParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(417);
      match(OclParser::DOT);
      setState(418);
      pathNameCS(0);
      setState(419);
      match(OclParser::COLONCOLON);
      setState(420);
      simpleNameCS();
      setState(421);
      match(OclParser::LPAREN);
      setState(430);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(422);
        oclExpressionCS(0);
        setState(427);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(423);
          match(OclParser::COMMA);
          setState(424);
          oclExpressionCS(0);
          setState(429);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(432);
      match(OclParser::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(434);
      match(OclParser::DOT);
      setState(435);
      pathNameCS(0);
      setState(436);
      match(OclParser::COLONCOLON);
      setState(437);
      simpleNameCS();
      setState(438);
      isMarkedPreCS();
      setState(439);
      match(OclParser::LPAREN);
      setState(448);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(440);
        oclExpressionCS(0);
        setState(445);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(441);
          match(OclParser::COMMA);
          setState(442);
          oclExpressionCS(0);
          setState(447);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(450);
      match(OclParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationCallExpCS_BContext ------------------------------------------------------------------

OclParser::OperationCallExpCS_BContext::OperationCallExpCS_BContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::SimpleNameCSContext* OclParser::OperationCallExpCS_BContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::OperationCallExpCS_BContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

tree::TerminalNode* OclParser::OperationCallExpCS_BContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::OperationCallExpCS_BContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::OperationCallExpCS_BContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

std::vector<tree::TerminalNode *> OclParser::OperationCallExpCS_BContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::OperationCallExpCS_BContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}

OclParser::IsMarkedPreCSContext* OclParser::OperationCallExpCS_BContext::isMarkedPreCS() {
  return getRuleContext<OclParser::IsMarkedPreCSContext>(0);
}

OclParser::PathNameCSContext* OclParser::OperationCallExpCS_BContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}


size_t OclParser::OperationCallExpCS_BContext::getRuleIndex() const {
  return OclParser::RuleOperationCallExpCS_B;
}


std::any OclParser::OperationCallExpCS_BContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOperationCallExpCS_B(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OperationCallExpCS_BContext* OclParser::operationCallExpCS_B() {
  OperationCallExpCS_BContext *_localctx = _tracker.createInstance<OperationCallExpCS_BContext>(_ctx, getState());
  enterRule(_localctx, 64, OclParser::RuleOperationCallExpCS_B);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(497);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(454);
      simpleNameCS();
      setState(455);
      match(OclParser::LPAREN);
      setState(464);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(456);
        oclExpressionCS(0);
        setState(461);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(457);
          match(OclParser::COMMA);
          setState(458);
          oclExpressionCS(0);
          setState(463);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(466);
      match(OclParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(468);
      simpleNameCS();
      setState(469);
      isMarkedPreCS();
      setState(470);
      match(OclParser::LPAREN);
      setState(479);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(471);
        oclExpressionCS(0);
        setState(476);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(472);
          match(OclParser::COMMA);
          setState(473);
          oclExpressionCS(0);
          setState(478);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(481);
      match(OclParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(483);
      pathNameCS(0);
      setState(484);
      match(OclParser::LPAREN);
      setState(493);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4611984518637698308) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & 11) != 0)) {
        setState(485);
        oclExpressionCS(0);
        setState(490);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(486);
          match(OclParser::COMMA);
          setState(487);
          oclExpressionCS(0);
          setState(492);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(495);
      match(OclParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyCallExpCS_AContext ------------------------------------------------------------------

OclParser::PropertyCallExpCS_AContext::PropertyCallExpCS_AContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::PropertyCallExpCS_AContext::DOT() {
  return getToken(OclParser::DOT, 0);
}

OclParser::SimpleNameCSContext* OclParser::PropertyCallExpCS_AContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

OclParser::IsMarkedPreCSContext* OclParser::PropertyCallExpCS_AContext::isMarkedPreCS() {
  return getRuleContext<OclParser::IsMarkedPreCSContext>(0);
}

OclParser::PathNameCSContext* OclParser::PropertyCallExpCS_AContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::PropertyCallExpCS_AContext::COLONCOLON() {
  return getToken(OclParser::COLONCOLON, 0);
}


size_t OclParser::PropertyCallExpCS_AContext::getRuleIndex() const {
  return OclParser::RulePropertyCallExpCS_A;
}


std::any OclParser::PropertyCallExpCS_AContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPropertyCallExpCS_A(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PropertyCallExpCS_AContext* OclParser::propertyCallExpCS_A() {
  PropertyCallExpCS_AContext *_localctx = _tracker.createInstance<PropertyCallExpCS_AContext>(_ctx, getState());
  enterRule(_localctx, 66, OclParser::RulePropertyCallExpCS_A);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(511);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(499);
      match(OclParser::DOT);
      setState(500);
      simpleNameCS();
      setState(502);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
      case 1: {
        setState(501);
        isMarkedPreCS();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(504);
      match(OclParser::DOT);
      setState(505);
      pathNameCS(0);
      setState(506);
      match(OclParser::COLONCOLON);
      setState(507);
      simpleNameCS();
      setState(509);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
      case 1: {
        setState(508);
        isMarkedPreCS();
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyCallExpCS_BContext ------------------------------------------------------------------

OclParser::PropertyCallExpCS_BContext::PropertyCallExpCS_BContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::SimpleNameCSContext* OclParser::PropertyCallExpCS_BContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

OclParser::IsMarkedPreCSContext* OclParser::PropertyCallExpCS_BContext::isMarkedPreCS() {
  return getRuleContext<OclParser::IsMarkedPreCSContext>(0);
}


size_t OclParser::PropertyCallExpCS_BContext::getRuleIndex() const {
  return OclParser::RulePropertyCallExpCS_B;
}


std::any OclParser::PropertyCallExpCS_BContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPropertyCallExpCS_B(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PropertyCallExpCS_BContext* OclParser::propertyCallExpCS_B() {
  PropertyCallExpCS_BContext *_localctx = _tracker.createInstance<PropertyCallExpCS_BContext>(_ctx, getState());
  enterRule(_localctx, 68, OclParser::RulePropertyCallExpCS_B);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    simpleNameCS();
    setState(515);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(514);
      isMarkedPreCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssociationClassCallExpCS_AContext ------------------------------------------------------------------

OclParser::AssociationClassCallExpCS_AContext::AssociationClassCallExpCS_AContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_AContext::DOT() {
  return getToken(OclParser::DOT, 0);
}

OclParser::SimpleNameCSContext* OclParser::AssociationClassCallExpCS_AContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_AContext::LBRACE() {
  return getToken(OclParser::LBRACE, 0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::AssociationClassCallExpCS_AContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::AssociationClassCallExpCS_AContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_AContext::RBRACE() {
  return getToken(OclParser::RBRACE, 0);
}

OclParser::IsMarkedPreCSContext* OclParser::AssociationClassCallExpCS_AContext::isMarkedPreCS() {
  return getRuleContext<OclParser::IsMarkedPreCSContext>(0);
}

std::vector<tree::TerminalNode *> OclParser::AssociationClassCallExpCS_AContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_AContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::AssociationClassCallExpCS_AContext::getRuleIndex() const {
  return OclParser::RuleAssociationClassCallExpCS_A;
}


std::any OclParser::AssociationClassCallExpCS_AContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitAssociationClassCallExpCS_A(this);
  else
    return visitor->visitChildren(this);
}

OclParser::AssociationClassCallExpCS_AContext* OclParser::associationClassCallExpCS_A() {
  AssociationClassCallExpCS_AContext *_localctx = _tracker.createInstance<AssociationClassCallExpCS_AContext>(_ctx, getState());
  enterRule(_localctx, 70, OclParser::RuleAssociationClassCallExpCS_A);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    match(OclParser::DOT);
    setState(518);
    simpleNameCS();
    setState(530);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(519);
      match(OclParser::LBRACE);
      setState(520);
      oclExpressionCS(0);
      setState(525);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == OclParser::COMMA) {
        setState(521);
        match(OclParser::COMMA);
        setState(522);
        oclExpressionCS(0);
        setState(527);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(528);
      match(OclParser::RBRACE);
      break;
    }

    default:
      break;
    }
    setState(533);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      setState(532);
      isMarkedPreCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssociationClassCallExpCS_BContext ------------------------------------------------------------------

OclParser::AssociationClassCallExpCS_BContext::AssociationClassCallExpCS_BContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::SimpleNameCSContext* OclParser::AssociationClassCallExpCS_BContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_BContext::LBRACE() {
  return getToken(OclParser::LBRACE, 0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::AssociationClassCallExpCS_BContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::AssociationClassCallExpCS_BContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_BContext::RBRACE() {
  return getToken(OclParser::RBRACE, 0);
}

OclParser::IsMarkedPreCSContext* OclParser::AssociationClassCallExpCS_BContext::isMarkedPreCS() {
  return getRuleContext<OclParser::IsMarkedPreCSContext>(0);
}

std::vector<tree::TerminalNode *> OclParser::AssociationClassCallExpCS_BContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::AssociationClassCallExpCS_BContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::AssociationClassCallExpCS_BContext::getRuleIndex() const {
  return OclParser::RuleAssociationClassCallExpCS_B;
}


std::any OclParser::AssociationClassCallExpCS_BContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitAssociationClassCallExpCS_B(this);
  else
    return visitor->visitChildren(this);
}

OclParser::AssociationClassCallExpCS_BContext* OclParser::associationClassCallExpCS_B() {
  AssociationClassCallExpCS_BContext *_localctx = _tracker.createInstance<AssociationClassCallExpCS_BContext>(_ctx, getState());
  enterRule(_localctx, 72, OclParser::RuleAssociationClassCallExpCS_B);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(535);
    simpleNameCS();
    setState(547);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      setState(536);
      match(OclParser::LBRACE);
      setState(537);
      oclExpressionCS(0);
      setState(542);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == OclParser::COMMA) {
        setState(538);
        match(OclParser::COMMA);
        setState(539);
        oclExpressionCS(0);
        setState(544);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(545);
      match(OclParser::RBRACE);
      break;
    }

    default:
      break;
    }
    setState(550);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      setState(549);
      isMarkedPreCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IsMarkedPreCSContext ------------------------------------------------------------------

OclParser::IsMarkedPreCSContext::IsMarkedPreCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::IsMarkedPreCSContext::AT() {
  return getToken(OclParser::AT, 0);
}

tree::TerminalNode* OclParser::IsMarkedPreCSContext::PRE() {
  return getToken(OclParser::PRE, 0);
}


size_t OclParser::IsMarkedPreCSContext::getRuleIndex() const {
  return OclParser::RuleIsMarkedPreCS;
}


std::any OclParser::IsMarkedPreCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitIsMarkedPreCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::IsMarkedPreCSContext* OclParser::isMarkedPreCS() {
  IsMarkedPreCSContext *_localctx = _tracker.createInstance<IsMarkedPreCSContext>(_ctx, getState());
  enterRule(_localctx, 74, OclParser::RuleIsMarkedPreCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(OclParser::AT);
    setState(553);
    match(OclParser::PRE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LetExpCSContext ------------------------------------------------------------------

OclParser::LetExpCSContext::LetExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::LetExpCSContext::LET() {
  return getToken(OclParser::LET, 0);
}

std::vector<OclParser::VariableDeclarationCSContext *> OclParser::LetExpCSContext::variableDeclarationCS() {
  return getRuleContexts<OclParser::VariableDeclarationCSContext>();
}

OclParser::VariableDeclarationCSContext* OclParser::LetExpCSContext::variableDeclarationCS(size_t i) {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(i);
}

tree::TerminalNode* OclParser::LetExpCSContext::IN() {
  return getToken(OclParser::IN, 0);
}

OclParser::OclExpressionCSContext* OclParser::LetExpCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

std::vector<tree::TerminalNode *> OclParser::LetExpCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::LetExpCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::LetExpCSContext::getRuleIndex() const {
  return OclParser::RuleLetExpCS;
}


std::any OclParser::LetExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitLetExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::LetExpCSContext* OclParser::letExpCS() {
  LetExpCSContext *_localctx = _tracker.createInstance<LetExpCSContext>(_ctx, getState());
  enterRule(_localctx, 76, OclParser::RuleLetExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    match(OclParser::LET);
    setState(556);
    variableDeclarationCS();
    setState(561);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == OclParser::COMMA) {
      setState(557);
      match(OclParser::COMMA);
      setState(558);
      variableDeclarationCS();
      setState(563);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(564);
    match(OclParser::IN);
    setState(565);
    oclExpressionCS(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OclMessageExpCSContext ------------------------------------------------------------------

OclParser::OclMessageExpCSContext::OclMessageExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::OclMessageExpCSContext::DHAT() {
  return getToken(OclParser::DHAT, 0);
}

OclParser::SimpleNameCSContext* OclParser::OclMessageExpCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::OclMessageExpCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

tree::TerminalNode* OclParser::OclMessageExpCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

OclParser::OclMessageArgumentsCSContext* OclParser::OclMessageExpCSContext::oclMessageArgumentsCS() {
  return getRuleContext<OclParser::OclMessageArgumentsCSContext>(0);
}

tree::TerminalNode* OclParser::OclMessageExpCSContext::HAT() {
  return getToken(OclParser::HAT, 0);
}


size_t OclParser::OclMessageExpCSContext::getRuleIndex() const {
  return OclParser::RuleOclMessageExpCS;
}


std::any OclParser::OclMessageExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOclMessageExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OclMessageExpCSContext* OclParser::oclMessageExpCS() {
  OclMessageExpCSContext *_localctx = _tracker.createInstance<OclMessageExpCSContext>(_ctx, getState());
  enterRule(_localctx, 78, OclParser::RuleOclMessageExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(583);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::DHAT: {
        enterOuterAlt(_localctx, 1);
        setState(567);
        match(OclParser::DHAT);
        setState(568);
        simpleNameCS();
        setState(569);
        match(OclParser::LPAREN);
        setState(571);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 6917827527851392260) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 76)) & 11) != 0)) {
          setState(570);
          oclMessageArgumentsCS();
        }
        setState(573);
        match(OclParser::RPAREN);
        break;
      }

      case OclParser::HAT: {
        enterOuterAlt(_localctx, 2);
        setState(575);
        match(OclParser::HAT);
        setState(576);
        simpleNameCS();
        setState(577);
        match(OclParser::LPAREN);
        setState(579);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 6917827527851392260) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 76)) & 11) != 0)) {
          setState(578);
          oclMessageArgumentsCS();
        }
        setState(581);
        match(OclParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OclMessageArgumentsCSContext ------------------------------------------------------------------

OclParser::OclMessageArgumentsCSContext::OclMessageArgumentsCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::OclMessageArgumentsCSContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::OclMessageArgumentsCSContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

std::vector<tree::TerminalNode *> OclParser::OclMessageArgumentsCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::OclMessageArgumentsCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}

std::vector<tree::TerminalNode *> OclParser::OclMessageArgumentsCSContext::QUESTION() {
  return getTokens(OclParser::QUESTION);
}

tree::TerminalNode* OclParser::OclMessageArgumentsCSContext::QUESTION(size_t i) {
  return getToken(OclParser::QUESTION, i);
}

std::vector<tree::TerminalNode *> OclParser::OclMessageArgumentsCSContext::COLON() {
  return getTokens(OclParser::COLON);
}

tree::TerminalNode* OclParser::OclMessageArgumentsCSContext::COLON(size_t i) {
  return getToken(OclParser::COLON, i);
}

std::vector<OclParser::TypeCSContext *> OclParser::OclMessageArgumentsCSContext::typeCS() {
  return getRuleContexts<OclParser::TypeCSContext>();
}

OclParser::TypeCSContext* OclParser::OclMessageArgumentsCSContext::typeCS(size_t i) {
  return getRuleContext<OclParser::TypeCSContext>(i);
}


size_t OclParser::OclMessageArgumentsCSContext::getRuleIndex() const {
  return OclParser::RuleOclMessageArgumentsCS;
}


std::any OclParser::OclMessageArgumentsCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOclMessageArgumentsCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OclMessageArgumentsCSContext* OclParser::oclMessageArgumentsCS() {
  OclMessageArgumentsCSContext *_localctx = _tracker.createInstance<OclMessageArgumentsCSContext>(_ctx, getState());
  enterRule(_localctx, 80, OclParser::RuleOclMessageArgumentsCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(591);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::QUESTION: {
        setState(585);
        match(OclParser::QUESTION);
        setState(588);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == OclParser::COLON) {
          setState(586);
          match(OclParser::COLON);
          setState(587);
          typeCS();
        }
        break;
      }

      case OclParser::IF:
      case OclParser::LET:
      case OclParser::SELF:
      case OclParser::TUPLE:
      case OclParser::NULLEXP:
      case OclParser::INVALID:
      case OclParser::COLLECTION:
      case OclParser::BAG:
      case OclParser::ORDEREDSET:
      case OclParser::SEQUENCE:
      case OclParser::SET:
      case OclParser::OCLBOOLEAN:
      case OclParser::OCLINTEGER:
      case OclParser::OCLREAL:
      case OclParser::OCLSTRING:
      case OclParser::OCLUNLIMITEDNAT:
      case OclParser::OCLANY:
      case OclParser::OCLINVALID:
      case OclParser::OCLMESSAGE:
      case OclParser::OCLVOID:
      case OclParser::INT:
      case OclParser::REAL:
      case OclParser::BOOL:
      case OclParser::STRING_LITERAL:
      case OclParser::LPAREN:
      case OclParser::STAR:
      case OclParser::MINUS:
      case OclParser::NOT:
      case OclParser::ID: {
        setState(590);
        oclExpressionCS(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(604);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == OclParser::COMMA) {
      setState(593);
      match(OclParser::COMMA);
      setState(600);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case OclParser::QUESTION: {
          setState(594);
          match(OclParser::QUESTION);
          setState(597);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == OclParser::COLON) {
            setState(595);
            match(OclParser::COLON);
            setState(596);
            typeCS();
          }
          break;
        }

        case OclParser::IF:
        case OclParser::LET:
        case OclParser::SELF:
        case OclParser::TUPLE:
        case OclParser::NULLEXP:
        case OclParser::INVALID:
        case OclParser::COLLECTION:
        case OclParser::BAG:
        case OclParser::ORDEREDSET:
        case OclParser::SEQUENCE:
        case OclParser::SET:
        case OclParser::OCLBOOLEAN:
        case OclParser::OCLINTEGER:
        case OclParser::OCLREAL:
        case OclParser::OCLSTRING:
        case OclParser::OCLUNLIMITEDNAT:
        case OclParser::OCLANY:
        case OclParser::OCLINVALID:
        case OclParser::OCLMESSAGE:
        case OclParser::OCLVOID:
        case OclParser::INT:
        case OclParser::REAL:
        case OclParser::BOOL:
        case OclParser::STRING_LITERAL:
        case OclParser::LPAREN:
        case OclParser::STAR:
        case OclParser::MINUS:
        case OclParser::NOT:
        case OclParser::ID: {
          setState(599);
          oclExpressionCS(0);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(606);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfExpCSContext ------------------------------------------------------------------

OclParser::IfExpCSContext::IfExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::IfExpCSContext::IF() {
  return getToken(OclParser::IF, 0);
}

std::vector<OclParser::OclExpressionCSContext *> OclParser::IfExpCSContext::oclExpressionCS() {
  return getRuleContexts<OclParser::OclExpressionCSContext>();
}

OclParser::OclExpressionCSContext* OclParser::IfExpCSContext::oclExpressionCS(size_t i) {
  return getRuleContext<OclParser::OclExpressionCSContext>(i);
}

tree::TerminalNode* OclParser::IfExpCSContext::THEN() {
  return getToken(OclParser::THEN, 0);
}

tree::TerminalNode* OclParser::IfExpCSContext::ELSE() {
  return getToken(OclParser::ELSE, 0);
}

tree::TerminalNode* OclParser::IfExpCSContext::ENDIF() {
  return getToken(OclParser::ENDIF, 0);
}


size_t OclParser::IfExpCSContext::getRuleIndex() const {
  return OclParser::RuleIfExpCS;
}


std::any OclParser::IfExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitIfExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::IfExpCSContext* OclParser::ifExpCS() {
  IfExpCSContext *_localctx = _tracker.createInstance<IfExpCSContext>(_ctx, getState());
  enterRule(_localctx, 82, OclParser::RuleIfExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    match(OclParser::IF);
    setState(608);
    oclExpressionCS(0);
    setState(609);
    match(OclParser::THEN);
    setState(610);
    oclExpressionCS(0);
    setState(611);
    match(OclParser::ELSE);
    setState(612);
    oclExpressionCS(0);
    setState(613);
    match(OclParser::ENDIF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NullLiteralExpCSContext ------------------------------------------------------------------

OclParser::NullLiteralExpCSContext::NullLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::NullLiteralExpCSContext::NULLEXP() {
  return getToken(OclParser::NULLEXP, 0);
}


size_t OclParser::NullLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleNullLiteralExpCS;
}


std::any OclParser::NullLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitNullLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::NullLiteralExpCSContext* OclParser::nullLiteralExpCS() {
  NullLiteralExpCSContext *_localctx = _tracker.createInstance<NullLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 84, OclParser::RuleNullLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    match(OclParser::NULLEXP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvalidLiteralExpCSContext ------------------------------------------------------------------

OclParser::InvalidLiteralExpCSContext::InvalidLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::InvalidLiteralExpCSContext::INVALID() {
  return getToken(OclParser::INVALID, 0);
}


size_t OclParser::InvalidLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleInvalidLiteralExpCS;
}


std::any OclParser::InvalidLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitInvalidLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::InvalidLiteralExpCSContext* OclParser::invalidLiteralExpCS() {
  InvalidLiteralExpCSContext *_localctx = _tracker.createInstance<InvalidLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 86, OclParser::RuleInvalidLiteralExpCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    match(OclParser::INVALID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryLiteralExpCSContext ------------------------------------------------------------------

OclParser::UnaryLiteralExpCSContext::UnaryLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::UnaryLiteralExpCSContext::MINUS() {
  return getToken(OclParser::MINUS, 0);
}

tree::TerminalNode* OclParser::UnaryLiteralExpCSContext::NOT() {
  return getToken(OclParser::NOT, 0);
}


size_t OclParser::UnaryLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleUnaryLiteralExpCS;
}


std::any OclParser::UnaryLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitUnaryLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::UnaryLiteralExpCSContext* OclParser::unaryLiteralExpCS() {
  UnaryLiteralExpCSContext *_localctx = _tracker.createInstance<UnaryLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 88, OclParser::RuleUnaryLiteralExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(619);
    _la = _input->LA(1);
    if (!(_la == OclParser::MINUS

    || _la == OclParser::NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryLiteralExpCSContext ------------------------------------------------------------------

OclParser::BinaryLiteralExpCSContext::BinaryLiteralExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::LT() {
  return getToken(OclParser::LT, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::LTE() {
  return getToken(OclParser::LTE, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::GTE() {
  return getToken(OclParser::GTE, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::GT() {
  return getToken(OclParser::GT, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::ASSIGN() {
  return getToken(OclParser::ASSIGN, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::INEQUAL() {
  return getToken(OclParser::INEQUAL, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::KEYAND() {
  return getToken(OclParser::KEYAND, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::KEYOR() {
  return getToken(OclParser::KEYOR, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::KEYXOR() {
  return getToken(OclParser::KEYXOR, 0);
}

tree::TerminalNode* OclParser::BinaryLiteralExpCSContext::IMPLIES() {
  return getToken(OclParser::IMPLIES, 0);
}


size_t OclParser::BinaryLiteralExpCSContext::getRuleIndex() const {
  return OclParser::RuleBinaryLiteralExpCS;
}


std::any OclParser::BinaryLiteralExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitBinaryLiteralExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::BinaryLiteralExpCSContext* OclParser::binaryLiteralExpCS() {
  BinaryLiteralExpCSContext *_localctx = _tracker.createInstance<BinaryLiteralExpCSContext>(_ctx, getState());
  enterRule(_localctx, 90, OclParser::RuleBinaryLiteralExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    _la = _input->LA(1);
    if (!(((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & 15423) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageDeclarationCSContext ------------------------------------------------------------------

OclParser::PackageDeclarationCSContext::PackageDeclarationCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::PackageDeclarationCSContext::PACKAGE() {
  return getToken(OclParser::PACKAGE, 0);
}

OclParser::PathNameCSContext* OclParser::PackageDeclarationCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::PackageDeclarationCSContext::ENDPACKAGE() {
  return getToken(OclParser::ENDPACKAGE, 0);
}

std::vector<OclParser::ContextDeclarationCSContext *> OclParser::PackageDeclarationCSContext::contextDeclarationCS() {
  return getRuleContexts<OclParser::ContextDeclarationCSContext>();
}

OclParser::ContextDeclarationCSContext* OclParser::PackageDeclarationCSContext::contextDeclarationCS(size_t i) {
  return getRuleContext<OclParser::ContextDeclarationCSContext>(i);
}


size_t OclParser::PackageDeclarationCSContext::getRuleIndex() const {
  return OclParser::RulePackageDeclarationCS;
}


std::any OclParser::PackageDeclarationCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPackageDeclarationCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PackageDeclarationCSContext* OclParser::packageDeclarationCS() {
  PackageDeclarationCSContext *_localctx = _tracker.createInstance<PackageDeclarationCSContext>(_ctx, getState());
  enterRule(_localctx, 92, OclParser::RulePackageDeclarationCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(639);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::PACKAGE: {
        enterOuterAlt(_localctx, 1);
        setState(623);
        match(OclParser::PACKAGE);
        setState(624);
        pathNameCS(0);
        setState(628);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::CONTEXT) {
          setState(625);
          contextDeclarationCS();
          setState(630);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(631);
        match(OclParser::ENDPACKAGE);
        break;
      }

      case OclParser::EOF:
      case OclParser::CONTEXT: {
        enterOuterAlt(_localctx, 2);
        setState(636);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::CONTEXT) {
          setState(633);
          contextDeclarationCS();
          setState(638);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContextDeclarationCSContext ------------------------------------------------------------------

OclParser::ContextDeclarationCSContext::ContextDeclarationCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::PropertyContextDeclCSContext* OclParser::ContextDeclarationCSContext::propertyContextDeclCS() {
  return getRuleContext<OclParser::PropertyContextDeclCSContext>(0);
}

OclParser::ClassifierContextDeclCSContext* OclParser::ContextDeclarationCSContext::classifierContextDeclCS() {
  return getRuleContext<OclParser::ClassifierContextDeclCSContext>(0);
}

OclParser::OperationContextDeclCSContext* OclParser::ContextDeclarationCSContext::operationContextDeclCS() {
  return getRuleContext<OclParser::OperationContextDeclCSContext>(0);
}


size_t OclParser::ContextDeclarationCSContext::getRuleIndex() const {
  return OclParser::RuleContextDeclarationCS;
}


std::any OclParser::ContextDeclarationCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitContextDeclarationCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::ContextDeclarationCSContext* OclParser::contextDeclarationCS() {
  ContextDeclarationCSContext *_localctx = _tracker.createInstance<ContextDeclarationCSContext>(_ctx, getState());
  enterRule(_localctx, 94, OclParser::RuleContextDeclarationCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(644);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(641);
      propertyContextDeclCS();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(642);
      classifierContextDeclCS();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(643);
      operationContextDeclCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassifierContextDeclCSContext ------------------------------------------------------------------

OclParser::ClassifierContextDeclCSContext::ClassifierContextDeclCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::ClassifierContextDeclCSContext::CONTEXT() {
  return getToken(OclParser::CONTEXT, 0);
}

OclParser::PathNameCSContext* OclParser::ClassifierContextDeclCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

OclParser::InvOrDefCSContext* OclParser::ClassifierContextDeclCSContext::invOrDefCS() {
  return getRuleContext<OclParser::InvOrDefCSContext>(0);
}

OclParser::SimpleNameCSContext* OclParser::ClassifierContextDeclCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::ClassifierContextDeclCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}


size_t OclParser::ClassifierContextDeclCSContext::getRuleIndex() const {
  return OclParser::RuleClassifierContextDeclCS;
}


std::any OclParser::ClassifierContextDeclCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitClassifierContextDeclCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::ClassifierContextDeclCSContext* OclParser::classifierContextDeclCS() {
  ClassifierContextDeclCSContext *_localctx = _tracker.createInstance<ClassifierContextDeclCSContext>(_ctx, getState());
  enterRule(_localctx, 96, OclParser::RuleClassifierContextDeclCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(656);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(646);
      match(OclParser::CONTEXT);
      setState(647);
      pathNameCS(0);
      setState(648);
      invOrDefCS();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(650);
      match(OclParser::CONTEXT);
      setState(651);
      simpleNameCS();
      setState(652);
      match(OclParser::COLON);
      setState(653);
      pathNameCS(0);
      setState(654);
      invOrDefCS();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContextDeclCSContext ------------------------------------------------------------------

OclParser::OperationContextDeclCSContext::OperationContextDeclCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::OperationContextDeclCSContext::CONTEXT() {
  return getToken(OclParser::CONTEXT, 0);
}

OclParser::OperationCSContext* OclParser::OperationContextDeclCSContext::operationCS() {
  return getRuleContext<OclParser::OperationCSContext>(0);
}

OclParser::PrePostOrBodyDeclCSContext* OclParser::OperationContextDeclCSContext::prePostOrBodyDeclCS() {
  return getRuleContext<OclParser::PrePostOrBodyDeclCSContext>(0);
}


size_t OclParser::OperationContextDeclCSContext::getRuleIndex() const {
  return OclParser::RuleOperationContextDeclCS;
}


std::any OclParser::OperationContextDeclCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOperationContextDeclCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OperationContextDeclCSContext* OclParser::operationContextDeclCS() {
  OperationContextDeclCSContext *_localctx = _tracker.createInstance<OperationContextDeclCSContext>(_ctx, getState());
  enterRule(_localctx, 98, OclParser::RuleOperationContextDeclCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(658);
    match(OclParser::CONTEXT);
    setState(659);
    operationCS();
    setState(660);
    prePostOrBodyDeclCS();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContextDeclCSContext ------------------------------------------------------------------

OclParser::PropertyContextDeclCSContext::PropertyContextDeclCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::PropertyContextDeclCSContext::CONTEXT() {
  return getToken(OclParser::CONTEXT, 0);
}

OclParser::PathNameCSContext* OclParser::PropertyContextDeclCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::PropertyContextDeclCSContext::COLONCOLON() {
  return getToken(OclParser::COLONCOLON, 0);
}

OclParser::SimpleNameCSContext* OclParser::PropertyContextDeclCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::PropertyContextDeclCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}

OclParser::TypeCSContext* OclParser::PropertyContextDeclCSContext::typeCS() {
  return getRuleContext<OclParser::TypeCSContext>(0);
}

OclParser::InitOrDerValueListCSContext* OclParser::PropertyContextDeclCSContext::initOrDerValueListCS() {
  return getRuleContext<OclParser::InitOrDerValueListCSContext>(0);
}


size_t OclParser::PropertyContextDeclCSContext::getRuleIndex() const {
  return OclParser::RulePropertyContextDeclCS;
}


std::any OclParser::PropertyContextDeclCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPropertyContextDeclCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PropertyContextDeclCSContext* OclParser::propertyContextDeclCS() {
  PropertyContextDeclCSContext *_localctx = _tracker.createInstance<PropertyContextDeclCSContext>(_ctx, getState());
  enterRule(_localctx, 100, OclParser::RulePropertyContextDeclCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(662);
    match(OclParser::CONTEXT);
    setState(663);
    pathNameCS(0);
    setState(664);
    match(OclParser::COLONCOLON);
    setState(665);
    simpleNameCS();
    setState(666);
    match(OclParser::COLON);
    setState(667);
    typeCS();
    setState(668);
    initOrDerValueListCS();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefExpressionCSContext ------------------------------------------------------------------

OclParser::DefExpressionCSContext::DefExpressionCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::VariableDeclarationCSContext* OclParser::DefExpressionCSContext::variableDeclarationCS() {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(0);
}

tree::TerminalNode* OclParser::DefExpressionCSContext::ASSIGN() {
  return getToken(OclParser::ASSIGN, 0);
}

OclParser::OclExpressionCSContext* OclParser::DefExpressionCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

OclParser::OperationCSContext* OclParser::DefExpressionCSContext::operationCS() {
  return getRuleContext<OclParser::OperationCSContext>(0);
}


size_t OclParser::DefExpressionCSContext::getRuleIndex() const {
  return OclParser::RuleDefExpressionCS;
}


std::any OclParser::DefExpressionCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitDefExpressionCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::DefExpressionCSContext* OclParser::defExpressionCS() {
  DefExpressionCSContext *_localctx = _tracker.createInstance<DefExpressionCSContext>(_ctx, getState());
  enterRule(_localctx, 102, OclParser::RuleDefExpressionCS);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(678);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(670);
      variableDeclarationCS();
      setState(671);
      match(OclParser::ASSIGN);
      setState(672);
      oclExpressionCS(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(674);
      operationCS();
      setState(675);
      match(OclParser::ASSIGN);
      setState(676);
      oclExpressionCS(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvOrDefCSContext ------------------------------------------------------------------

OclParser::InvOrDefCSContext::InvOrDefCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::InvOrDefCSContext::INV() {
  return getToken(OclParser::INV, 0);
}

tree::TerminalNode* OclParser::InvOrDefCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}

OclParser::OclExpressionCSContext* OclParser::InvOrDefCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

OclParser::SimpleNameCSContext* OclParser::InvOrDefCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::InvOrDefCSContext::DEF() {
  return getToken(OclParser::DEF, 0);
}

OclParser::DefExpressionCSContext* OclParser::InvOrDefCSContext::defExpressionCS() {
  return getRuleContext<OclParser::DefExpressionCSContext>(0);
}

tree::TerminalNode* OclParser::InvOrDefCSContext::STATIC() {
  return getToken(OclParser::STATIC, 0);
}


size_t OclParser::InvOrDefCSContext::getRuleIndex() const {
  return OclParser::RuleInvOrDefCS;
}


std::any OclParser::InvOrDefCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitInvOrDefCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::InvOrDefCSContext* OclParser::invOrDefCS() {
  InvOrDefCSContext *_localctx = _tracker.createInstance<InvOrDefCSContext>(_ctx, getState());
  enterRule(_localctx, 104, OclParser::RuleInvOrDefCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(695);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OclParser::INV: {
        enterOuterAlt(_localctx, 1);
        setState(680);
        match(OclParser::INV);
        setState(682);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == OclParser::ID) {
          setState(681);
          simpleNameCS();
        }
        setState(684);
        match(OclParser::COLON);
        setState(685);
        oclExpressionCS(0);
        break;
      }

      case OclParser::STATIC:
      case OclParser::DEF: {
        enterOuterAlt(_localctx, 2);
        setState(687);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == OclParser::STATIC) {
          setState(686);
          match(OclParser::STATIC);
        }
        setState(689);
        match(OclParser::DEF);
        setState(691);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == OclParser::ID) {
          setState(690);
          simpleNameCS();
        }
        setState(693);
        match(OclParser::COLON);
        setState(694);
        defExpressionCS();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitOrDerValueListCSContext ------------------------------------------------------------------

OclParser::InitOrDerValueListCSContext::InitOrDerValueListCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OclParser::InitOrDerValueCSContext *> OclParser::InitOrDerValueListCSContext::initOrDerValueCS() {
  return getRuleContexts<OclParser::InitOrDerValueCSContext>();
}

OclParser::InitOrDerValueCSContext* OclParser::InitOrDerValueListCSContext::initOrDerValueCS(size_t i) {
  return getRuleContext<OclParser::InitOrDerValueCSContext>(i);
}


size_t OclParser::InitOrDerValueListCSContext::getRuleIndex() const {
  return OclParser::RuleInitOrDerValueListCS;
}


std::any OclParser::InitOrDerValueListCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitInitOrDerValueListCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::InitOrDerValueListCSContext* OclParser::initOrDerValueListCS() {
  InitOrDerValueListCSContext *_localctx = _tracker.createInstance<InitOrDerValueListCSContext>(_ctx, getState());
  enterRule(_localctx, 106, OclParser::RuleInitOrDerValueListCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == OclParser::INIT

    || _la == OclParser::DERIVE) {
      setState(697);
      initOrDerValueCS();
      setState(702);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitOrDerValueCSContext ------------------------------------------------------------------

OclParser::InitOrDerValueCSContext::InitOrDerValueCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::InitOrDerValueCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}

OclParser::OclExpressionCSContext* OclParser::InitOrDerValueCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

tree::TerminalNode* OclParser::InitOrDerValueCSContext::INIT() {
  return getToken(OclParser::INIT, 0);
}

tree::TerminalNode* OclParser::InitOrDerValueCSContext::DERIVE() {
  return getToken(OclParser::DERIVE, 0);
}


size_t OclParser::InitOrDerValueCSContext::getRuleIndex() const {
  return OclParser::RuleInitOrDerValueCS;
}


std::any OclParser::InitOrDerValueCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitInitOrDerValueCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::InitOrDerValueCSContext* OclParser::initOrDerValueCS() {
  InitOrDerValueCSContext *_localctx = _tracker.createInstance<InitOrDerValueCSContext>(_ctx, getState());
  enterRule(_localctx, 108, OclParser::RuleInitOrDerValueCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    _la = _input->LA(1);
    if (!(_la == OclParser::INIT

    || _la == OclParser::DERIVE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(704);
    match(OclParser::COLON);
    setState(705);
    oclExpressionCS(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrePostOrBodyDeclCSContext ------------------------------------------------------------------

OclParser::PrePostOrBodyDeclCSContext::PrePostOrBodyDeclCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OclParser::PrePostBodyExpCSContext *> OclParser::PrePostOrBodyDeclCSContext::prePostBodyExpCS() {
  return getRuleContexts<OclParser::PrePostBodyExpCSContext>();
}

OclParser::PrePostBodyExpCSContext* OclParser::PrePostOrBodyDeclCSContext::prePostBodyExpCS(size_t i) {
  return getRuleContext<OclParser::PrePostBodyExpCSContext>(i);
}


size_t OclParser::PrePostOrBodyDeclCSContext::getRuleIndex() const {
  return OclParser::RulePrePostOrBodyDeclCS;
}


std::any OclParser::PrePostOrBodyDeclCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPrePostOrBodyDeclCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PrePostOrBodyDeclCSContext* OclParser::prePostOrBodyDeclCS() {
  PrePostOrBodyDeclCSContext *_localctx = _tracker.createInstance<PrePostOrBodyDeclCSContext>(_ctx, getState());
  enterRule(_localctx, 110, OclParser::RulePrePostOrBodyDeclCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3145856) != 0)) {
      setState(707);
      prePostBodyExpCS();
      setState(712);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrePostBodyExpCSContext ------------------------------------------------------------------

OclParser::PrePostBodyExpCSContext::PrePostBodyExpCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OclParser::PrePostBodyExpCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}

OclParser::OclExpressionCSContext* OclParser::PrePostBodyExpCSContext::oclExpressionCS() {
  return getRuleContext<OclParser::OclExpressionCSContext>(0);
}

tree::TerminalNode* OclParser::PrePostBodyExpCSContext::PRE() {
  return getToken(OclParser::PRE, 0);
}

tree::TerminalNode* OclParser::PrePostBodyExpCSContext::POST() {
  return getToken(OclParser::POST, 0);
}

tree::TerminalNode* OclParser::PrePostBodyExpCSContext::BODY() {
  return getToken(OclParser::BODY, 0);
}

OclParser::SimpleNameCSContext* OclParser::PrePostBodyExpCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}


size_t OclParser::PrePostBodyExpCSContext::getRuleIndex() const {
  return OclParser::RulePrePostBodyExpCS;
}


std::any OclParser::PrePostBodyExpCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitPrePostBodyExpCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::PrePostBodyExpCSContext* OclParser::prePostBodyExpCS() {
  PrePostBodyExpCSContext *_localctx = _tracker.createInstance<PrePostBodyExpCSContext>(_ctx, getState());
  enterRule(_localctx, 112, OclParser::RulePrePostBodyExpCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(713);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3145856) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(715);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OclParser::ID) {
      setState(714);
      simpleNameCS();
    }
    setState(717);
    match(OclParser::COLON);
    setState(718);
    oclExpressionCS(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationCSContext ------------------------------------------------------------------

OclParser::OperationCSContext::OperationCSContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OclParser::PathNameCSContext* OclParser::OperationCSContext::pathNameCS() {
  return getRuleContext<OclParser::PathNameCSContext>(0);
}

tree::TerminalNode* OclParser::OperationCSContext::COLONCOLON() {
  return getToken(OclParser::COLONCOLON, 0);
}

OclParser::SimpleNameCSContext* OclParser::OperationCSContext::simpleNameCS() {
  return getRuleContext<OclParser::SimpleNameCSContext>(0);
}

tree::TerminalNode* OclParser::OperationCSContext::LPAREN() {
  return getToken(OclParser::LPAREN, 0);
}

tree::TerminalNode* OclParser::OperationCSContext::RPAREN() {
  return getToken(OclParser::RPAREN, 0);
}

tree::TerminalNode* OclParser::OperationCSContext::COLON() {
  return getToken(OclParser::COLON, 0);
}

std::vector<OclParser::VariableDeclarationCSContext *> OclParser::OperationCSContext::variableDeclarationCS() {
  return getRuleContexts<OclParser::VariableDeclarationCSContext>();
}

OclParser::VariableDeclarationCSContext* OclParser::OperationCSContext::variableDeclarationCS(size_t i) {
  return getRuleContext<OclParser::VariableDeclarationCSContext>(i);
}

OclParser::TypeCSContext* OclParser::OperationCSContext::typeCS() {
  return getRuleContext<OclParser::TypeCSContext>(0);
}

std::vector<tree::TerminalNode *> OclParser::OperationCSContext::COMMA() {
  return getTokens(OclParser::COMMA);
}

tree::TerminalNode* OclParser::OperationCSContext::COMMA(size_t i) {
  return getToken(OclParser::COMMA, i);
}


size_t OclParser::OperationCSContext::getRuleIndex() const {
  return OclParser::RuleOperationCS;
}


std::any OclParser::OperationCSContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OclParserVisitor*>(visitor))
    return parserVisitor->visitOperationCS(this);
  else
    return visitor->visitChildren(this);
}

OclParser::OperationCSContext* OclParser::operationCS() {
  OperationCSContext *_localctx = _tracker.createInstance<OperationCSContext>(_ctx, getState());
  enterRule(_localctx, 114, OclParser::RuleOperationCS);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(756);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(720);
      pathNameCS(0);
      setState(721);
      match(OclParser::COLONCOLON);
      setState(722);
      simpleNameCS();
      setState(723);
      match(OclParser::LPAREN);
      setState(732);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == OclParser::ID) {
        setState(724);
        variableDeclarationCS();
        setState(729);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(725);
          match(OclParser::COMMA);
          setState(726);
          variableDeclarationCS();
          setState(731);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(734);
      match(OclParser::RPAREN);
      setState(735);
      match(OclParser::COLON);
      setState(737);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 532559169536) != 0) || _la == OclParser::ID) {
        setState(736);
        typeCS();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(739);
      simpleNameCS();
      setState(740);
      match(OclParser::LPAREN);
      setState(749);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == OclParser::ID) {
        setState(741);
        variableDeclarationCS();
        setState(746);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == OclParser::COMMA) {
          setState(742);
          match(OclParser::COMMA);
          setState(743);
          variableDeclarationCS();
          setState(748);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(751);
      match(OclParser::RPAREN);
      setState(752);
      match(OclParser::COLON);
      setState(754);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 532559169536) != 0) || _la == OclParser::ID) {
        setState(753);
        typeCS();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool OclParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return oclExpressionCSSempred(antlrcpp::downCast<OclExpressionCSContext *>(context), predicateIndex);
    case 7: return pathNameCSSempred(antlrcpp::downCast<PathNameCSContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool OclParser::oclExpressionCSSempred(OclExpressionCSContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 17);
    case 4: return precpred(_ctx, 15);
    case 5: return precpred(_ctx, 13);
    case 6: return precpred(_ctx, 11);
    case 7: return precpred(_ctx, 10);
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool OclParser::pathNameCSSempred(PathNameCSContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void OclParser::initialize() {
  ::antlr4::internal::call_once(oclparserParserOnceFlag, oclparserParserInitialize);
}
