parser grammar OclParser;

options {
	tokenVocab = OclLexer;
}

//@header {
//  #include "CSTNode.h"
//}


// -------------------------
// expressionInOclCS :  set up the initial environment of an  ocl expression.

expressionInOclCS
	:	oclExpressionCS
	|	packageDeclarationCS
	;  

// -------------------------
// oclExpressionCS :  has several production rules, one for each subclass of OclExpression.
/*
 * ANTLR4 supports only direct left recursion so the following rule will be rewritten : 
 
oclExpressionCS
	:	callExpCS
	|	variableExpCS
	|	literalExpCS
	|	letExpCS
	|	oclMessageExpCS
	|	ifExpCS
	;
*/

oclExpressionCS
	:	prefixedExp
	|	oclExpressionCS operationCallExpCS_A
	|	operationCallExpCS_B
	|	oclExpressionCS propertyCallExpCS_A
	|	propertyCallExpCS_B
	|	oclExpressionCS associationClassCallExpCS_A
	|	associationClassCallExpCS_B
	|	oclExpressionCS iteratorExpCS
	|	oclExpressionCS iterateExpCS
	|	oclExpressionCS (STAR | SLASH) oclExpressionCS
	|	oclExpressionCS (PLUS | MINUS) oclExpressionCS
//	|	LPAREN oclExpressionCS RPAREN
	|	parentedExpCS
//	|	oclExpressionCS infixedExpCS
	|	oclExpressionCS binaryLiteralExpCS oclExpressionCS
	|	variableExpCS
	|	literalExpCS
	|	letExpCS
	|	oclExpressionCS oclMessageExpCS
	|	ifExpCS
	;


//--------------------------

parentedExpCS
	:	LPAREN oclExpressionCS RPAREN
	;

// -------------------------
// -------------------------
// variableExpCS :  A variable expression is just a name that refers to a variable or self.
	
variableExpCS
	: 	SELF
	|	simpleNameCS
	;

// -------------------------
// simpleNameCS :  must be a name of a visible VariableDeclaration in the current environment.
	
simpleNameCS
	: 	ID
	;
 
// -------------------------
// restrictedKeywordCS : represents any name that is not a reserved keyword.
	
restrictedKeywordCS
	: 	collectionTypeIdentifierCS
	|	primitiveTypeCS
	|	oclTypeCS
	|	TUPLE
	;

// -------------------------
// unreservedSimpleNameCS : represents any name that is not a reserved keyword.
	
unreservedSimpleNameCS
	: 	simpleNameCS
	|	restrictedKeywordCS
	;
	
// -------------------------
// pathNameCS : represents a path name, which is held in its ast as a sequence of Strings.
	
pathNameCS
	: 	simpleNameCS
	|	pathNameCS COLONCOLON unreservedSimpleNameCS
	;

// -------------------------
// literalExpCS : represents literal expressions.
	
literalExpCS
	: 	enumLiteralExpCS
	|	collectionLiteralExpCS
	|	tupleLiteralExpCS
	|	primitiveLiteralExpCS
	|	typeLiteralExpCS
	;
	
// -------------------------
// enumLiteralExpCS : represents Enumeration Literal expressions.
	
enumLiteralExpCS
	: 	pathNameCS COLONCOLON simpleNameCS
	;
	
// -------------------------
// collectionLiteralExpCS : represents a collection literal expression.
// any collection elements are now seperate childs of the collectionLiteralExp
collectionLiteralExpCS
	//: 	collectionTypeIdentifierCS (LBRACE collectionLiteralPartsCS? RBRACE)
	: collectionTypeIdentifierCS (LBRACE collectionLiteralPartsCS? RBRACE)
	;
	
// -------------------------
// collectionTypeIdentifierCS : represents the type identifier in a collection literal expression.
	
collectionTypeIdentifierCS
	: 	SET
	|	BAG
	|	SEQUENCE
	|	COLLECTION
	|	ORDEREDSET
	;	
	
// -------------------------
// collectionLiteralPartsCS : describes a sequence of items that are the contents of a collection literal.
	
collectionLiteralPartsCS
//	: 	collectionLiteralPartCS (COMMA collectionLiteralPartsCS)?
	: 	(collectionRangeCS | oclExpressionCS) (COMMA (collectionRangeCS | oclExpressionCS))*
	;	
	
// -------------------------
// collectionLiteralPartCS : 
	
//collectionLiteralPartCS
//	: 	collectionRangeCS (COMMA collectionLiteralPartCS)?
//	|	oclExpressionCS (COMMA collectionLiteralPartCS)?
//	;	
	
// -------------------------
// collectionRangeCS : supports the use of a value or range of values in a collection of values.
	
collectionRangeCS
	: 	oclExpressionCS RANGE oclExpressionCS 
	|	SEQRANGE oclExpressionCS
	;	

// -------------------------
// The PrefixedExp syntax supports the application of zero or more prefix unary operators to an expression.
	
prefixedExp
	: 	unaryLiteralExpCS oclExpressionCS
	;

// -------------------------
// The InfixedExp syntax supports the application of zero or more infix binary operators between expression terms.

//infixedExpCS
//	: 	binaryLiteralExpCS oclExpressionCS
//	;

// -------------------------
// primitiveLiteralExpCS : includes Real, Boolean, UnlimitedNatural, Integer, and String literals.
	
primitiveLiteralExpCS
	: 	integerLiteralExpCS
	|	realLiteralExpCS
	|	stringLiteralExpCS
	|	booleanLiteralExpCS
	|	unlimitedNaturalLiteralExpCS
	|	nullLiteralExpCS
	|	invalidLiteralExpCS
	;	
	
// -------------------------
// tupleLiteralExpCS : represents tuple literal expressions.
// any tuple elements are now seperate childs of the TupleLiteralExp
	
tupleLiteralExpCS
//	: 	TUPLE LBRACE variableDeclarationListCS RBRACE
	:   TUPLE LBRACE (variableDeclarationCS (COMMA variableDeclarationCS)*)? RBRACE
	;	
	
// -------------------------
// unlimitedNaturalLiteralExpCS : represents unlimited natural literal expressions.
	
unlimitedNaturalLiteralExpCS
	: 	INT
	|	STAR
	;
	
// -------------------------
// integerLiteralExpCS : represents integer literal expressions.
	
integerLiteralExpCS
	: 	INT
	;
	
// -------------------------
// realLiteralExpCS : represents real literal expressions.
	
realLiteralExpCS
	: 	REAL
	;
	
// -------------------------
// stringLiteralExpCS : represents string literal expressions.
	
stringLiteralExpCS
	: 	STRING_LITERAL
	;
	
// -------------------------
// booleanLiteralExpCS : represents real literal expressions.
	
booleanLiteralExpCS
	: 	BOOL
	;
	
// -------------------------
// typeLiteralExpCS : references a type name.
	
typeLiteralExpCS
	: 	typeCS
	;

// -------------------------
// iteratorExpCS :  The first alternative is a straightforward Iterator expression, 
// 		with optional iterator variable. The second and third alternatives are so-called 
//		implicit collect iterators. B is for operations and C for attributes, D for navigations, and E for
//		associationclasses.

iteratorExpCS
	: 	RARROW simpleNameCS
		LPAREN
			(variableDeclarationCS (COMMA variableDeclarationCS)? PIPE)? oclExpressionCS
		RPAREN
	|	DOT simpleNameCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN
	|	DOT simpleNameCS
	|	DOT simpleNameCS (LBRACK (oclExpressionCS (COMMA oclExpressionCS)*) RBRACK)?
	;
// -------------------------
// iterateExpCS : 
	
iterateExpCS
	: 	RARROW ITERATE
		LPAREN
			(variableDeclarationCS SEMI)? variableDeclarationCS PIPE oclExpressionCS
		RPAREN
	;
	
// -------------------------
// variableDeclarationCS : the type and init expression are optional.
	
variableDeclarationCS
	: 	simpleNameCS (COLON typeCS)? ( ASSIGN oclExpressionCS )?
	;
	
// -------------------------
// typeCS : either a Classifier, or a collection of some type.
	
typeCS
	: 	pathNameCS
	|	collectionTypeCS
	|	tupleTypeCS
	|	primitiveTypeCS
	|	oclTypeCS
	;
	
// -------------------------
// primitiveTypeCS : denotes a primitive type.
	
primitiveTypeCS
	: 	OCLBOOLEAN
	|	OCLINTEGER
	|	OCLREAL
	|	OCLSTRING
	|	OCLUNLIMITEDNAT
	;
	
// -------------------------
// oclTypeCS : denotes a built-in OCL type.
	
oclTypeCS
	: 	OCLANY
	|	OCLINVALID
	|	OCLMESSAGE
	|	OCLVOID
	;
	
// -------------------------
// collectionTypeCS : a Classifier, or a collection of some type.
	
collectionTypeCS
	: 	collectionTypeIdentifierCS LPAREN typeCS RPAREN
	;
	
// -------------------------
// tupleTypeCS : a tuple type declaration.
	
tupleTypeCS
//now changed equal to TupleLiteralExp
//	: 	TUPLE LPAREN variableDeclarationListCS? RPAREN
	:   TUPLE LPAREN (variableDeclarationCS (COMMA variableDeclarationCS)*)? RPAREN
	;
	
// -------------------------
// variableDeclarationListCS : represents the formal parameters of a tuple or attribute definition.
	
//variableDeclarationListCS
//	: 	variableDeclarationCS (COMMA variableDeclarationListCS )?
//	;

// -------------------------
// operationCallExpCS : has many different forms.
// A is used for infix, B for using an object as an implicit collection. C is a
// straightforward operation call, while D has an implicit source expression. 
// E, F and J are like C, D, and I, with the @pre addition. G covers the static operation call. 
// Rule H is for unary prefix expressions. I and J use pathNameCS to permit qualification of 
// operation names in access to redefined operations.

operationCallExpCS_A
//	: 	simpleNameCS oclExpressionCS						// A -> special OperatorExp in CustomVisitor
	:	RARROW simpleNameCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN   // B
	|	DOT simpleNameCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN			// C
	|	DOT simpleNameCS isMarkedPreCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN	// E
	|	DOT pathNameCS COLONCOLON simpleNameCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN	// I
	|	DOT pathNameCS COLONCOLON simpleNameCS isMarkedPreCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN	// J
	;
	
operationCallExpCS_B
	: 	simpleNameCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN								// D
	|	simpleNameCS isMarkedPreCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN	// F
	|	pathNameCS LPAREN (oclExpressionCS (COMMA oclExpressionCS)*)? RPAREN	// G
//	|	simpleNameCS oclExpressionCS	// H -> special OperatorExp/ prefixedExp in CustomVisitor
	;
	
// -------------------------
// propertyCallExpCS : This production rule results in a PropertyCallExp.
// In production [A] the source is explicit, while production [B] is used 
// for an implicit source. Alternative C covers the use of a static attribute. 
// Alternative D uses pathNameCS to permit qualification of attribute names in access to redefined attributes.
	
propertyCallExpCS_A
	: 	DOT simpleNameCS isMarkedPreCS?						// A
	|	DOT pathNameCS COLONCOLON simpleNameCS isMarkedPreCS?	// D
	;
	
propertyCallExpCS_B
	: 	simpleNameCS isMarkedPreCS?												// B														// C
	;
	
// -------------------------
// associationClassCallExpCS : represents a navigation to an association class.
	
associationClassCallExpCS_A
	//: 	DOT simpleNameCS (LBRACE argumentsCS RBRACE)? isMarkedPreCS?
	: 	DOT simpleNameCS (LBRACE oclExpressionCS (COMMA oclExpressionCS)* RBRACE)? isMarkedPreCS?
	;
	
associationClassCallExpCS_B
	//: 	simpleNameCS (LBRACE argumentsCS RBRACE)? isMarkedPreCS?
	:	simpleNameCS (LBRACE oclExpressionCS (COMMA oclExpressionCS)* RBRACE)? isMarkedPreCS?
	;
// -------------------------
// isMarkedPreCS : represents the marking @pre in an ocl expression.
	
isMarkedPreCS
	: 	AT PRE
	;
	
// -------------------------
// argumentsCS : represents a sequence of arguments.
	
//argumentsCS
//	: 	oclExpressionCS ( COMMA argumentsCS )?
//	;
	
// -------------------------
// letExpCS : represents a let expression.
	
letExpCS
	//: 	LET variableDeclarationCS 
	//	letExpSubCS
	: LET variableDeclarationCS (COMMA variableDeclarationCS)* IN oclExpressionCS
	;
	
// -------------------------
// letExpSubCS : let
	
//letExpSubCS
//	: 	COMMA variableDeclarationCS letExpSubCS
//	|	IN oclExpressionCS
//	;
	
// -------------------------
// oclMessageExpCS : must either be the name of a Signal, 

oclMessageExpCS
	: 	DHAT simpleNameCS LPAREN oclMessageArgumentsCS? RPAREN
	|	HAT simpleNameCS LPAREN oclMessageArgumentsCS? RPAREN
	;
	
// -------------------------
// oclMessageArgumentsCS : ocl message arguments.
	
oclMessageArgumentsCS
//	: 	oclMessageArgCS (COMMA oclMessageArgumentsCS)?
	:	( (QUESTION (COLON typeCS)?) | oclExpressionCS ) ( COMMA ( (QUESTION ( COLON typeCS )?) | oclExpressionCS ) )*
	;
	
// -------------------------
// oclMessageArgCS : ocl message argument.
	
//oclMessageArgCS
//	: 	QUESTION (COLON typeCS)?
//	|	oclExpressionCS
//	;
	
// -------------------------
// ifExpCS : if expression.
	
ifExpCS
	: 	IF 		oclExpressionCS
		THEN 	oclExpressionCS
		ELSE 	oclExpressionCS
		ENDIF
	;
	
// -------------------------
// nullLiteralExpCS : Null literal expression.
	
nullLiteralExpCS
	: 	NULLEXP
	;
	
// -------------------------
// invalidLiteralExpCS : Invalid literal expression.
	
invalidLiteralExpCS
	: 	INVALID
	;

// -------------------------
// unaryLiteralExpCS : unary operators.

unaryLiteralExpCS
  : MINUS
  | NOT
  ;
  
// -------------------------
// binaryLiteralExpCS : binary operators.

binaryLiteralExpCS
	:	LT	 	
	|	LTE		
	|	GTE	
	|	GT
	|	ASSIGN	
	|	INEQUAL	
	|	KEYAND	
	|	KEYOR
	|   KEYXOR
	|	IMPLIES
	;
	
// -------------------------
// packageDeclarationCS : This production rule represents a package declaration.
			
packageDeclarationCS
	:	PACKAGE pathNameCS contextDeclarationCS* ENDPACKAGE
	|	contextDeclarationCS*
	;
	
// -------------------------

// contextDeclarationCS : identifies a model element to be complemented.
			
contextDeclarationCS
	:	propertyContextDeclCS
	|	classifierContextDeclCS
	|	operationContextDeclCS
	;
	
// -------------------------
// classifierContextDeclCS : identifies a Classifier to be complemented.
			
classifierContextDeclCS
	:	CONTEXT pathNameCS invOrDefCS
	|	CONTEXT simpleNameCS COLON pathNameCS invOrDefCS
	;	

// -------------------------
// operationContextDeclCS : represents a context declaration for expressions that can be coupled to an operation.
			
operationContextDeclCS
	:	CONTEXT operationCS prePostOrBodyDeclCS
	;	
	
// -------------------------
// propertyContextDeclCS : identifies a Property to be complemented.
			
propertyContextDeclCS
	:	CONTEXT pathNameCS COLONCOLON simpleNameCS COLON typeCS initOrDerValueListCS
	;	
	
// -------------------------
// defExpressionCS : defines additional attributes or operations in OCL.
			
defExpressionCS
	:	variableDeclarationCS ASSIGN oclExpressionCS
	|	operationCS ASSIGN oclExpressionCS
	;
	
// -------------------------
// invOrDefCS : represents an invariant or definition.
			
invOrDefCS
	:	INV simpleNameCS? COLON oclExpressionCS
	|	STATIC? DEF simpleNameCS? COLON defExpressionCS
	;
	
// -------------------------

initOrDerValueListCS
	:	initOrDerValueCS*
	;

// initOrDerValueCS : represents an initial or derived value expression.
			
initOrDerValueCS
//	:	INIT COLON oclExpressionCS initOrDerValueCS?
//	|	DERIVE COLON oclExpressionCS initOrDerValueCS?
	:   (INIT | DERIVE) COLON oclExpressionCS
	;

// -------------------------
// prePostOrBodyDeclCS : represents a pre- or postcondition or body expression.
			
prePostOrBodyDeclCS
//	:	PRE simpleNameCS? COLON oclExpressionCS prePostOrBodyDeclCS?
//	|	POST simpleNameCS? COLON oclExpressionCS prePostOrBodyDeclCS?
//	|	BODY simpleNameCS? COLON oclExpressionCS prePostOrBodyDeclCS?
	: 	prePostBodyExpCS*
	;
	
// -------------------------

// -------------------------

prePostBodyExpCS
	: (PRE | POST | BODY) simpleNameCS? COLON oclExpressionCS
	;

//--------------------------

// operationCS : represents an operation in a context declaration or definition expression.
			
operationCS
	//:	pathNameCS COLONCOLON simpleNameCS LPAREN parametersCS? RPAREN COLON typeCS?
	//|	simpleNameCS LPAREN parametersCS? RPAREN COLON typeCS?
	:	pathNameCS COLONCOLON simpleNameCS LPAREN (variableDeclarationCS (COMMA variableDeclarationCS)*)? RPAREN COLON typeCS?
	|	simpleNameCS LPAREN (variableDeclarationCS (COMMA variableDeclarationCS)*)? RPAREN COLON typeCS?
	;
	
// -------------------------
// parametersCS : represents the formal parameters of an operation.
			
//parametersCS
	//:	variableDeclarationCS (COMMA parametersCS)?
//	:	variableDeclarationCS (COMMA variableDeclarationCS)*
//	;