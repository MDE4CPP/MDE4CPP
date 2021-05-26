lexer grammar OclFragments ;

 //import OclUnicode;

// -----------------------------------
// Whitespace & Comments

fragment Bol			: Vws Hws*		;
fragment Ws				: Hws | Vws		;
fragment Hws			: [ \t]			;
fragment Vws			: '\r'? [\n\f]	;

fragment DocComment		: '/**' .*? ('*/' | EOF)	;
fragment BlockComment	: '/*'  .*? ('*/' | EOF)	;

fragment LineComment	: '//' ~[\r\n]* 							;
fragment LineCommentExt	: '//' ~[\r\n]* ( '\r'? '\n' Hws* '//' ~[\r\n]* )*	;


// -----------------------------------
// Escapes

// Any kind of escaped character that we can embed within ANTLR literal strings.
fragment EscSeq
	:	Esc
		( [btnfr"'\\]	// The standard escaped character set such as tab, newline, etc.
		| UnicodeEsc	// A Unicode escape sequence
		| .				// Invalid escape character
		| EOF			// Incomplete at EOF
		)
	;

fragment EscAny
	:	Esc .
	;

fragment UnicodeEsc
	:	'u' (HexDigit (HexDigit (HexDigit HexDigit?)?)?)?
	;

fragment OctalEscape
	:	OctalDigit
	|	OctalDigit OctalDigit
	|	[0-3] OctalDigit OctalDigit
	;


// -----------------------------------
// Numerals

fragment HexNumeral
	:	'0' [xX] HexDigits
	;

fragment OctalNumeral
	:	'0' '_' OctalDigits
	;

fragment DecimalNumeral
	:	'0'
	|	[1-9] DecDigit*
	;

fragment BinaryNumeral
	:	'0' [bB] BinaryDigits
	;


// -----------------------------------
// Digits

fragment HexDigits		: HexDigit+		;
fragment DecDigits		: DecDigit+		;
fragment OctalDigits	: OctalDigit+	;
fragment BinaryDigits	: BinaryDigit+	;

fragment HexDigit		: [0-9a-fA-F]	;
fragment DecDigit		: [0-9]			;
fragment OctalDigit		: [0-7]			;
fragment BinaryDigit	: [01]			;


// -----------------------------------
// Literals

fragment BoolLiteral	: True | False								;

fragment CharLiteral	: SQuote ( EscSeq | ~['\r\n\\] )  SQuote	;
fragment SQuoteLiteral	: SQuote ( EscSeq | ~['\r\n\\] )* SQuote	;
fragment DQuoteLiteral	: DQuote ( EscSeq | ~["\r\n\\] )* DQuote	;
fragment USQuoteLiteral	: SQuote ( EscSeq | ~['\r\n\\] )* 			;

fragment DecimalFloatingPointLiteral
	:   DecDigits Dot DecDigits? ExponentPart? FloatTypeSuffix?
	|   Dot DecDigits ExponentPart? FloatTypeSuffix?
	|	DecDigits ExponentPart FloatTypeSuffix?
	|	DecDigits FloatTypeSuffix
	;

fragment ExponentPart
	:	[eE] [+-]? DecDigits
	;

fragment FloatTypeSuffix
	:	[fFdD]
	;

fragment HexadecimalFloatingPointLiteral
	:	HexSignificand BinaryExponent FloatTypeSuffix?
	;

fragment HexSignificand
	:   HexNumeral Dot?
	|   '0' [xX] HexDigits? Dot HexDigits
	;

fragment BinaryExponent
	:	[pP] [+-]? DecDigits
	;


// -----------------------------------
// Java-type Character sets

fragment NameChar
	:	NameStartChar
	|	'0'..'9'
	|	Underscore
	|	'\u00B7'
	|	'\u0300'..'\u036F'
	|	'\u203F'..'\u2040'
	;

fragment NameStartChar
	:	'A'..'Z'
	|	'a'..'z'
	|	'\u00C0'..'\u00D6'
	|	'\u00D8'..'\u00F6'
	|	'\u00F8'..'\u02FF'
	|	'\u0370'..'\u037D'
	|	'\u037F'..'\u1FFF'
	|	'\u200C'..'\u200D'
	|	'\u2070'..'\u218F'
	|	'\u2C00'..'\u2FEF'
	|	'\u3001'..'\uD7FF'
	|	'\uF900'..'\uFDCF'
	|	'\uFDF0'..'\uFFFD'
	;	// ignores | ['\u10000-'\uEFFFF] ;


fragment JavaLetter
	:   [a-zA-Z$_] // "java letters" below 0xFF
//	|	JavaUnicodeChars
	;

fragment JavaLetterOrDigit
	:   [a-zA-Z0-9$_] // "java letters or digits" below 0xFF
//	|	JavaUnicodeChars
	;

// covers all characters above 0xFF which are not a surrogate
// and UTF-16 surrogate pairs encodings for U+10000 to U+10FFFF
//fragment JavaUnicodeChars
//	: ~[\u0000-\u00FF\uD800-\uDBFF]		{Character.isJavaIdentifierPart(_input.LA(-1))}?
//	|  [\uD800-\uDBFF] [\uDC00-\uDFFF]	{Character.isJavaIdentifierPart(Character.toCodePoint((char)_input.LA(-2), (char)_input.LA(-1)))}?
//	;

// -----------------------------------
// OCL Keywords

fragment If				: 'if'		;
fragment Then			: 'then'	;
fragment Else			: 'else'	;
fragment EndIf			: 'endif'	;
fragment In				: 'in'		;
fragment Let			: 'let'		;
fragment Iterate 		: 'iterate'	;
fragment Self 			: 'self'	;
fragment Tuple 			: 'Tuple'	;
fragment NullExp		: 'null'	;
fragment Invalid 		: 'invalid'	;
fragment Not 			: 'not'		;
fragment Implies 		: 'implies'	;
fragment KeyOr 			: 'or'		;
fragment KeyAnd 		: 'and'		;
fragment Xor 			: 'xor'		;

fragment Package 		: 'package'		;
fragment EndPackage		: 'endpackage'	;
fragment Context		: 'context'		;
fragment Static			: 'static'		;
fragment Def			: 'def'			;
fragment Inv			: 'inv'			;
fragment Body			: 'body'		;
fragment Post			: 'post'		;
fragment Pre			: 'pre'			;
fragment Init			: 'init'		;
fragment Derive			: 'derive'		;

// -----------------------------------
// Types

fragment Boolean		: 'boolean'	;
fragment Byte			: 'byte'	;
fragment Short			: 'short'	;
fragment Int			: 'int'		;
fragment Long			: 'long'	;
fragment Char			: 'char'	;
fragment Float			: 'float'	;
fragment Double 		: 'double'	;

fragment True		 	: 'true'	;
fragment False			: 'false'	;

// -----------------------------------
// Collections

fragment Collection		: 'Collection'			;
fragment Bag			: 'Bag'			;
fragment OrderedSet		: 'OrderedSet'	;
fragment Sequence		: 'Sequence'	;
fragment Set			: 'Set'			;

// -----------------------------------
// OCL Primitive Types

fragment OclBoolean			: 'Boolean'			;
fragment OclInteger			: 'Integer'			;
fragment OclReal			: 'Real'			;
fragment OclString			: 'String'			;
fragment OclUnlimitedNat	: 'UnlimitedNatural';

// -----------------------------------
// OCL Types

fragment OclAny				: 'OclAny'		;
fragment OclInvalid			: 'OclInvalid'	;
fragment OclMessage			: 'OclMessage'	;
fragment OclVoid			: 'OclVoid'		;
fragment OclState			: 'OclState'	;

// -----------------------------------
// Symbols

fragment Esc			: '\\'	;
fragment Colon			: ':'	;
fragment DColon			: '::'	;
fragment SQuote			: '\''	;
fragment DQuote			: '"'	;
fragment BQuote			: '`'	;
fragment LParen			: '('	;
fragment RParen			: ')'	;
fragment LBrace			: '{'	;
fragment RBrace			: '}'	;
fragment LBrack			: '['	;
fragment RBrack			: ']'	;
fragment RArrow			: '->'	;
fragment Lt				: '<'	;
fragment Gt				: '>'	;
fragment REqual			: '=>'	;
fragment Lte			: '<='	;
fragment Gte			: '>='	;
fragment Equal			: '='	;
fragment InEqual		: '<>'	;
fragment NotEqual		: '!='	;
fragment Question		: '?'	;
fragment Bang			: '!'	;
fragment Star			: '*'	;
fragment Slash			: '/'	;
fragment Percent		: '%'	;
fragment Caret			: '^'	;
fragment Plus			: '+'	;
fragment Minus			: '-'	;
fragment PlusAssign		: '+='	;
fragment MinusAssign	: '-='	;
fragment MulAssign		: '*='	;
fragment DivAssign		: '/='	;
fragment AndAssign		: '&='	;
fragment OrAssign		: '|='	;
fragment XOrAssign		: '^='	;
fragment ModAssign		: '%='	;
fragment Underscore		: '_'	;
fragment Pipe			: '|'	;
fragment Amp			: '&'	;
fragment And			: '&&'	;
fragment Or				: '||'	;
fragment Inc			: '++'	;
fragment Dec			: '--'	;
fragment LShift			: '<<'	;
fragment RShift			: '>>'	;
fragment Dollar			: '$'	;
fragment Comma			: ','	;
fragment Semi			: ';'	;
fragment Dot			: '.'	;
fragment Range			: '..'	;
fragment Ellipsis		: '...'	;
fragment At				: '@'	;
fragment Pound			: '#'	;
fragment Tilde			: '~'	;
fragment Hat			: '^'	;
fragment DHat			: '^^'	;
