lexer grammar OclLexer;

 import OclFragments;

// -------------------------
// Comments

COMMENTS
 	: (DocComment
 	|  BlockComment
	|  LineComment ) -> channel(HIDDEN)
	;


// -------------------------
// OCL Keywords

IF				: If		;
THEN			: Then		;
ELSE			: Else		;
ENDIF			: EndIf		;
IN				: In		;
PRE				: Pre		;
LET				: Let		;
ITERATE 		: Iterate	;
SELF 			: Self		;
TUPLE 			: Tuple		;
NULLEXP			: NullExp	;
INVALID 		: Invalid	;

PACKAGE			: Package	;
ENDPACKAGE		: EndPackage;
CONTEXT			: Context	;
STATIC			: Static	;
DEF				: Def		;
INV				: Inv		;
BODY			: Body		;
POST			: Post		;
INIT			: Init		;
DERIVE			: Derive	;

// -----------------------------------
// OCL Collections

COLLECTION 		: Collection	;
BAG 			: Bag			;
ORDEREDSET 		: OrderedSet	;
SEQUENCE 		: Sequence		;
SET 			: Set			;

// -----------------------------------
// OCL Primitive Types

OCLBOOLEAN 		: OclBoolean		;
OCLINTEGER 		: OclInteger		;
OCLREAL 		: OclReal			;
OCLSTRING 		: OclString			;
OCLUNLIMITEDNAT : OclUnlimitedNat	;

// -----------------------------------

//Sequence Range
//neccessary because otherwise it can be missinterpreted as REAL

SEQRANGE
		 : Minus? DecimalNumeral Range
		 ;

// OCL Types

OCLANY 			: OclAny		;
OCLINVALID 		: OclInvalid	;
OCLMESSAGE 		: OclMessage	;
OCLVOID 		: OclVoid		;
OCLSTATE 		: OclState		;
	
INT	: DecimalNumeral 	
	;
	
REAL
	: DecimalFloatingPointLiteral 	
	;
	
BOOL
	: BoolLiteral 	
	;

STRING_LITERAL
	: SQuoteLiteral
	;

// -------------------------
// Punctuation

COLON		: Colon			;
COLONCOLON	: DColon		;
COMMA		: Comma			;
SEMI		: Semi			;
LPAREN		: LParen		;
RPAREN		: RParen		;
LBRACE		: LBrace		;
RBRACE		: RBrace		;
LBRACK		: LBrack		;
RBRACK		: RBrack		;
RARROW		: RArrow		;
LT			: Lt			;
GT			: Gt			;
LTE			: Lte			;
GTE			: Gte			;
ASSIGN		: Equal			;
INEQUAL   	: InEqual		;
QUESTION	: Question		;
STAR		: Star			;
PLUS_ASSIGN	: PlusAssign	;
PLUS		: Plus			;
KEYOR		: KeyOr			;
KEYAND		: KeyAnd		;
KEYXOR		: KeyXor		;
IMPLIES		: Implies		;
RANGE		: Range			;
DOT			: Dot			;
AT			: At			;
SLASH		: Slash			;
UNDERSCORE	: Underscore	;
DHAT		: DHat			;
HAT			: Hat			;
MINUS		: Minus			;
NOT 		: Not			;
PIPE		: Pipe			;

// -------------------------
// Identifiers : the position after the keywords is important

ID	: NameStartChar NameChar* ;

// -------------------------
// Whitespace

WS	:	( Hws | Vws )+	-> channel(HIDDEN)	;

ERRCHAR
	:	.	-> channel(HIDDEN)
	;