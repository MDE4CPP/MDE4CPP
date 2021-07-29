//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONSPACKAGE_HPP
#define OCL_EXPRESSIONSPACKAGE_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAttribute;
	class EClass;
	class EDataType;
	class EEnum;
	class EEnumLiteral;
	class EGenericType;
	class EReference;
}

namespace ocl::Expressions 
{
	class AssociationClassCallExp;
	class BooleanLiteralExp;
	class CallExp;
	class CollectionItem;
	class CollectionLiteralExp;
	class CollectionLiteralPart;
	class CollectionRange;
	class EnumLiteralExp;
	class ExpressionInOcl;
	class FeatureCallExp;
	class IfExp;
	class InfixedExp;
	class IntegerLiteralExp;
	class InvalidLiteralExp;
	class IterateExp;
	class IteratorExp;
	class LetExp;
	class LiteralExp;
	class LoopExp;
	class MessageExp;
	class NavigationCallExp;
	class NullLiteralExp;
	class NumericLiteralExp;
	class OclExpression;
	class OperationCallExp;
	class PrimitiveLiteralExp;
	class PropertyCallExp;
	class RealLiteralExp;
	class StateExp;
	class StringLiteralExp;
	class TupleLiteralExp;
	class TupleLiteralPart;
	class TypeExp;
	class UnlimitedNaturalExp;
	class UnspecifiedValueExp;
	class Variable;
	class VariableExp;
}
 
namespace ocl::Expressions 
{
	/*!
	The Metamodel Package for the Expressions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class OCL_API ExpressionsPackage : virtual public ecore::EPackage 
	{
		private:    
			ExpressionsPackage(ExpressionsPackage const&) = delete;
			ExpressionsPackage& operator=(ExpressionsPackage const&) = delete;

		protected:
			ExpressionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class AssociationClassCallExp
			//Class and Feature IDs 
			static const long long ASSOCIATIONCLASSCALLEXP_CLASS = 870318929;
			static const unsigned int ASSOCIATIONCLASSCALLEXP_CLASS_FEATURE_COUNT = 27;
			static const unsigned int ASSOCIATIONCLASSCALLEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long ASSOCIATIONCLASSCALLEXP_ATTRIBUTE_REFERREDASSOCIATIONCLASS = 904729146;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAssociationClassCallExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getAssociationClassCallExp_Attribute_referredAssociationClass() const = 0;
			
			
			// End Class AssociationClassCallExp


			// Begin Class BooleanLiteralExp
			//Class and Feature IDs 
			static const long long BOOLEANLITERALEXP_CLASS = 225873423;
			static const unsigned int BOOLEANLITERALEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int BOOLEANLITERALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long BOOLEANLITERALEXP_ATTRIBUTE_BOOLEANSYMBOL = 163266681;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getBooleanLiteralExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getBooleanLiteralExp_Attribute_booleanSymbol() const = 0;
			
			
			
			// End Class BooleanLiteralExp


			// Begin Class CallExp
			//Class and Feature IDs 
			static const long long CALLEXP_CLASS = 1741533399;
			static const unsigned int CALLEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int CALLEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long CALLEXP_ATTRIBUTE_SOURCE = 1085763551;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCallExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCallExp_Attribute_source() const = 0;
			
			
			// End Class CallExp


			// Begin Class CollectionItem
			//Class and Feature IDs 
			static const long long COLLECTIONITEM_CLASS = 2033004063;
			static const unsigned int COLLECTIONITEM_CLASS_FEATURE_COUNT = 11;
			static const unsigned int COLLECTIONITEM_CLASS_OPERATION_COUNT = 1;
			
			static const long long COLLECTIONITEM_ATTRIBUTE_ITEM = 2137854234;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionItem_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionItem_Attribute_item() const = 0;
			
			
			// End Class CollectionItem


			// Begin Class CollectionLiteralExp
			//Class and Feature IDs 
			static const long long COLLECTIONLITERALEXP_CLASS = 658019569;
			static const unsigned int COLLECTIONLITERALEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int COLLECTIONLITERALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long COLLECTIONLITERALEXP_ATTRIBUTE_KIND = 1089781924;
			
			static const long long COLLECTIONLITERALEXP_ATTRIBUTE_PART = 2072692088;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionLiteralExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getCollectionLiteralExp_Attribute_kind() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getCollectionLiteralExp_Attribute_part() const = 0;
			
			
			// End Class CollectionLiteralExp


			// Begin Class CollectionLiteralPart
			//Class and Feature IDs 
			static const long long COLLECTIONLITERALPART_CLASS = 525693555;
			static const unsigned int COLLECTIONLITERALPART_CLASS_FEATURE_COUNT = 10;
			static const unsigned int COLLECTIONLITERALPART_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionLiteralPart_Class() const = 0;
			
			
			
			
			// End Class CollectionLiteralPart


			// Begin Class CollectionRange
			//Class and Feature IDs 
			static const long long COLLECTIONRANGE_CLASS = 1706418751;
			static const unsigned int COLLECTIONRANGE_CLASS_FEATURE_COUNT = 12;
			static const unsigned int COLLECTIONRANGE_CLASS_OPERATION_COUNT = 1;
			
			static const long long COLLECTIONRANGE_ATTRIBUTE_FIRST = 914360917;
			static const long long COLLECTIONRANGE_ATTRIBUTE_LAST = 30378830;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionRange_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionRange_Attribute_first() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCollectionRange_Attribute_last() const = 0;
			
			
			// End Class CollectionRange


			// Begin Class EnumLiteralExp
			//Class and Feature IDs 
			static const long long ENUMLITERALEXP_CLASS = 1896746244;
			static const unsigned int ENUMLITERALEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int ENUMLITERALEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long ENUMLITERALEXP_ATTRIBUTE_REFERREDENUMLITERAL = 1742161624;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEnumLiteralExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEnumLiteralExp_Attribute_referredEnumLiteral() const = 0;
			
			
			// End Class EnumLiteralExp


			// Begin Class ExpressionInOcl
			//Class and Feature IDs 
			static const long long EXPRESSIONINOCL_CLASS = 988393756;
			static const unsigned int EXPRESSIONINOCL_CLASS_FEATURE_COUNT = 14;
			static const unsigned int EXPRESSIONINOCL_CLASS_OPERATION_COUNT = 1;
			
			static const long long EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION = 712388958;
			static const long long EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE = 848264500;
			static const long long EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE = 324600278;
			static const long long EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE = 362564962;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExpressionInOcl_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExpressionInOcl_Attribute_bodyExpression() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpressionInOcl_Attribute_contextVariable() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpressionInOcl_Attribute_parameterVariable() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExpressionInOcl_Attribute_resultVariable() const = 0;
			
			
			// End Class ExpressionInOcl


			// Begin Class FeatureCallExp
			//Class and Feature IDs 
			static const long long FEATURECALLEXP_CLASS = 108542242;
			static const unsigned int FEATURECALLEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int FEATURECALLEXP_CLASS_OPERATION_COUNT = 1;
			static const long long FEATURECALLEXP_ATTRIBUTE_ISPRE = 1578651514;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFeatureCallExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getFeatureCallExp_Attribute_isPre() const = 0;
			
			
			
			// End Class FeatureCallExp


			// Begin Class IfExp
			//Class and Feature IDs 
			static const long long IFEXP_CLASS = 327095557;
			static const unsigned int IFEXP_CLASS_FEATURE_COUNT = 25;
			static const unsigned int IFEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long IFEXP_ATTRIBUTE_CONDITION = 541352280;
			static const long long IFEXP_ATTRIBUTE_ELSEEXPRESSION = 403461435;
			static const long long IFEXP_ATTRIBUTE_THENEXPRESSION = 842935867;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIfExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getIfExp_Attribute_condition() const = 0;
			virtual std::shared_ptr<ecore::EReference> getIfExp_Attribute_elseExpression() const = 0;
			virtual std::shared_ptr<ecore::EReference> getIfExp_Attribute_thenExpression() const = 0;
			
			
			// End Class IfExp


			// Begin Class InfixedExp
			//Class and Feature IDs 
			static const long long INFIXEDEXP_CLASS = 938428434;
			static const unsigned int INFIXEDEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int INFIXEDEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long INFIXEDEXP_ATTRIBUTE_SOURCE = 1085763551;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInfixedExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getInfixedExp_Attribute_source() const = 0;
			
			
			// End Class InfixedExp


			// Begin Class IntegerLiteralExp
			//Class and Feature IDs 
			static const long long INTEGERLITERALEXP_CLASS = 274113150;
			static const unsigned int INTEGERLITERALEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int INTEGERLITERALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long INTEGERLITERALEXP_ATTRIBUTE_INTEGERSYMBOL = 211506408;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIntegerLiteralExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getIntegerLiteralExp_Attribute_integerSymbol() const = 0;
			
			
			
			// End Class IntegerLiteralExp


			// Begin Class InvalidLiteralExp
			//Class and Feature IDs 
			static const long long INVALIDLITERALEXP_CLASS = 1953131443;
			static const unsigned int INVALIDLITERALEXP_CLASS_FEATURE_COUNT = 22;
			static const unsigned int INVALIDLITERALEXP_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInvalidLiteralExp_Class() const = 0;
			
			
			
			
			// End Class InvalidLiteralExp


			// Begin Class IterateExp
			//Class and Feature IDs 
			static const long long ITERATEEXP_CLASS = 1451014857;
			static const unsigned int ITERATEEXP_CLASS_FEATURE_COUNT = 26;
			static const unsigned int ITERATEEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long ITERATEEXP_ATTRIBUTE_RESULT = 1501738861;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIterateExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getIterateExp_Attribute_result() const = 0;
			
			
			// End Class IterateExp


			// Begin Class IteratorExp
			//Class and Feature IDs 
			static const long long ITERATOREXP_CLASS = 1427874836;
			static const unsigned int ITERATOREXP_CLASS_FEATURE_COUNT = 25;
			static const unsigned int ITERATOREXP_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getIteratorExp_Class() const = 0;
			
			
			
			
			// End Class IteratorExp


			// Begin Class LetExp
			//Class and Feature IDs 
			static const long long LETEXP_CLASS = 514305968;
			static const unsigned int LETEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int LETEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long LETEXP_ATTRIBUTE_IN = 2006612969;
			static const long long LETEXP_ATTRIBUTE_VARIABLE = 681800373;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLetExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getLetExp_Attribute_in() const = 0;
			virtual std::shared_ptr<ecore::EReference> getLetExp_Attribute_variable() const = 0;
			
			
			// End Class LetExp


			// Begin Class LiteralExp
			//Class and Feature IDs 
			static const long long LITERALEXP_CLASS = 509208412;
			static const unsigned int LITERALEXP_CLASS_FEATURE_COUNT = 22;
			static const unsigned int LITERALEXP_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralExp_Class() const = 0;
			
			
			
			
			// End Class LiteralExp


			// Begin Class LoopExp
			//Class and Feature IDs 
			static const long long LOOPEXP_CLASS = 1471094680;
			static const unsigned int LOOPEXP_CLASS_FEATURE_COUNT = 25;
			static const unsigned int LOOPEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long LOOPEXP_ATTRIBUTE_BODY = 775823562;
			static const long long LOOPEXP_ATTRIBUTE_ITERATOR = 1271624111;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLoopExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getLoopExp_Attribute_body() const = 0;
			virtual std::shared_ptr<ecore::EReference> getLoopExp_Attribute_iterator() const = 0;
			
			
			// End Class LoopExp


			// Begin Class MessageExp
			//Class and Feature IDs 
			static const long long MESSAGEEXP_CLASS = 1834681541;
			static const unsigned int MESSAGEEXP_CLASS_FEATURE_COUNT = 26;
			static const unsigned int MESSAGEEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long MESSAGEEXP_ATTRIBUTE_ARGUMENT = 1876730217;
			static const long long MESSAGEEXP_ATTRIBUTE_CALLEDOPERATION = 670800091;
			static const long long MESSAGEEXP_ATTRIBUTE_SENTSIGNAL = 224941433;
			static const long long MESSAGEEXP_ATTRIBUTE_TARGET = 1707287415;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getMessageExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getMessageExp_Attribute_argument() const = 0;
			virtual std::shared_ptr<ecore::EReference> getMessageExp_Attribute_calledOperation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getMessageExp_Attribute_sentSignal() const = 0;
			virtual std::shared_ptr<ecore::EReference> getMessageExp_Attribute_target() const = 0;
			
			
			// End Class MessageExp


			// Begin Class NavigationCallExp
			//Class and Feature IDs 
			static const long long NAVIGATIONCALLEXP_CLASS = 833199948;
			static const unsigned int NAVIGATIONCALLEXP_CLASS_FEATURE_COUNT = 26;
			static const unsigned int NAVIGATIONCALLEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long NAVIGATIONCALLEXP_ATTRIBUTE_NAVIGATIONSOURCE = 1264477946;
			static const long long NAVIGATIONCALLEXP_ATTRIBUTE_QUALIFIER = 1554459054;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getNavigationCallExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getNavigationCallExp_Attribute_navigationSource() const = 0;
			virtual std::shared_ptr<ecore::EReference> getNavigationCallExp_Attribute_qualifier() const = 0;
			
			
			// End Class NavigationCallExp


			// Begin Class NullLiteralExp
			//Class and Feature IDs 
			static const long long NULLLITERALEXP_CLASS = 863530749;
			static const unsigned int NULLLITERALEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int NULLLITERALEXP_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getNullLiteralExp_Class() const = 0;
			
			
			
			
			// End Class NullLiteralExp


			// Begin Class NumericLiteralExp
			//Class and Feature IDs 
			static const long long NUMERICLITERALEXP_CLASS = 1020270764;
			static const unsigned int NUMERICLITERALEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int NUMERICLITERALEXP_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getNumericLiteralExp_Class() const = 0;
			
			
			
			
			// End Class NumericLiteralExp


			// Begin Class OclExpression
			//Class and Feature IDs 
			static const long long OCLEXPRESSION_CLASS = 925307628;
			static const unsigned int OCLEXPRESSION_CLASS_FEATURE_COUNT = 22;
			static const unsigned int OCLEXPRESSION_CLASS_OPERATION_COUNT = 1;
			
			static const long long OCLEXPRESSION_ATTRIBUTE_APPLIEDELEMENT = 1349393706;
			static const long long OCLEXPRESSION_ATTRIBUTE_ELSEOWNER = 1886831920;
			static const long long OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER = 1009034965;
			static const long long OCLEXPRESSION_ATTRIBUTE_IFOWNER = 327030755;
			static const long long OCLEXPRESSION_ATTRIBUTE_INITIALIZEDELEMENT = 977252805;
			static const long long OCLEXPRESSION_ATTRIBUTE_INSTANCE = 125355111;
			static const long long OCLEXPRESSION_ATTRIBUTE_LASTOWNER = 1450314711;
			static const long long OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER = 1645262158;
			static const long long OCLEXPRESSION_ATTRIBUTE_PARENTCALL = 1138285494;
			static const long long OCLEXPRESSION_ATTRIBUTE_PARENTNAV = 1557485548;
			static const long long OCLEXPRESSION_ATTRIBUTE_THENOWNER = 178822705;
			static const long long OCLEXPRESSION_ATTRIBUTE_TOPEXPRESSION = 688149434;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOclExpression_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_appliedElement() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_elseOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_firstOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_ifOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_initializedElement() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_instance() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_lastOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_loopBodyOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_parentCall() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_parentNav() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_thenOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOclExpression_Attribute_topExpression() const = 0;
			
			
			// End Class OclExpression


			// Begin Class OperationCallExp
			//Class and Feature IDs 
			static const long long OPERATIONCALLEXP_CLASS = 1030298851;
			static const unsigned int OPERATIONCALLEXP_CLASS_FEATURE_COUNT = 26;
			static const unsigned int OPERATIONCALLEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long OPERATIONCALLEXP_ATTRIBUTE_ARGUMENT = 1876730217;
			static const long long OPERATIONCALLEXP_ATTRIBUTE_REFERREDOPERATION = 1699464259;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOperationCallExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getOperationCallExp_Attribute_argument() const = 0;
			virtual std::shared_ptr<ecore::EReference> getOperationCallExp_Attribute_referredOperation() const = 0;
			
			
			// End Class OperationCallExp


			// Begin Class PrimitiveLiteralExp
			//Class and Feature IDs 
			static const long long PRIMITIVELITERALEXP_CLASS = 95355624;
			static const unsigned int PRIMITIVELITERALEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int PRIMITIVELITERALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long PRIMITIVELITERALEXP_ATTRIBUTE_SYMBOL = 17917190;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPrimitiveLiteralExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getPrimitiveLiteralExp_Attribute_symbol() const = 0;
			
			
			
			// End Class PrimitiveLiteralExp


			// Begin Class PropertyCallExp
			//Class and Feature IDs 
			static const long long PROPERTYCALLEXP_CLASS = 133065828;
			static const unsigned int PROPERTYCALLEXP_CLASS_FEATURE_COUNT = 27;
			static const unsigned int PROPERTYCALLEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long PROPERTYCALLEXP_ATTRIBUTE_REFERREDPROPERTY = 743796371;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getPropertyCallExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getPropertyCallExp_Attribute_referredProperty() const = 0;
			
			
			// End Class PropertyCallExp


			// Begin Class RealLiteralExp
			//Class and Feature IDs 
			static const long long REALLITERALEXP_CLASS = 470342449;
			static const unsigned int REALLITERALEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int REALLITERALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long REALLITERALEXP_ATTRIBUTE_REALSYMBOL = 105959647;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getRealLiteralExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getRealLiteralExp_Attribute_realSymbol() const = 0;
			
			
			
			// End Class RealLiteralExp


			// Begin Class StateExp
			//Class and Feature IDs 
			static const long long STATEEXP_CLASS = 2001706267;
			static const unsigned int STATEEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int STATEEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long STATEEXP_ATTRIBUTE_REFERREDSTATE = 536707064;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStateExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getStateExp_Attribute_referredState() const = 0;
			
			
			// End Class StateExp


			// Begin Class StringLiteralExp
			//Class and Feature IDs 
			static const long long STRINGLITERALEXP_CLASS = 88304816;
			static const unsigned int STRINGLITERALEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int STRINGLITERALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long STRINGLITERALEXP_ATTRIBUTE_STRINGSYMBOL = 1144267828;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getStringLiteralExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getStringLiteralExp_Attribute_stringSymbol() const = 0;
			
			
			
			// End Class StringLiteralExp


			// Begin Class TupleLiteralExp
			//Class and Feature IDs 
			static const long long TUPLELITERALEXP_CLASS = 421328739;
			static const unsigned int TUPLELITERALEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int TUPLELITERALEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long TUPLELITERALEXP_ATTRIBUTE_PART = 2072692088;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTupleLiteralExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getTupleLiteralExp_Attribute_part() const = 0;
			
			
			// End Class TupleLiteralExp


			// Begin Class TupleLiteralPart
			//Class and Feature IDs 
			static const long long TUPLELITERALPART_CLASS = 2008604788;
			static const unsigned int TUPLELITERALPART_CLASS_FEATURE_COUNT = 11;
			static const unsigned int TUPLELITERALPART_CLASS_OPERATION_COUNT = 1;
			
			static const long long TUPLELITERALPART_ATTRIBUTE_ATTRIBUTE = 551242599;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTupleLiteralPart_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getTupleLiteralPart_Attribute_attribute() const = 0;
			
			
			// End Class TupleLiteralPart


			// Begin Class TypeExp
			//Class and Feature IDs 
			static const long long TYPEEXP_CLASS = 523410060;
			static const unsigned int TYPEEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int TYPEEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long TYPEEXP_ATTRIBUTE_REFERREDTYPE = 659682022;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTypeExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getTypeExp_Attribute_referredType() const = 0;
			
			
			// End Class TypeExp


			// Begin Class UnlimitedNaturalExp
			//Class and Feature IDs 
			static const long long UNLIMITEDNATURALEXP_CLASS = 521207252;
			static const unsigned int UNLIMITEDNATURALEXP_CLASS_FEATURE_COUNT = 24;
			static const unsigned int UNLIMITEDNATURALEXP_CLASS_OPERATION_COUNT = 1;
			static const long long UNLIMITEDNATURALEXP_ATTRIBUTE_UNLIMITEDNATURALSYMBOL = 1628816833;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getUnlimitedNaturalExp_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getUnlimitedNaturalExp_Attribute_unlimitedNaturalSymbol() const = 0;
			
			
			
			// End Class UnlimitedNaturalExp


			// Begin Class UnspecifiedValueExp
			//Class and Feature IDs 
			static const long long UNSPECIFIEDVALUEEXP_CLASS = 233840348;
			static const unsigned int UNSPECIFIEDVALUEEXP_CLASS_FEATURE_COUNT = 22;
			static const unsigned int UNSPECIFIEDVALUEEXP_CLASS_OPERATION_COUNT = 1;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getUnspecifiedValueExp_Class() const = 0;
			
			
			
			
			// End Class UnspecifiedValueExp


			// Begin Class Variable
			//Class and Feature IDs 
			static const long long VARIABLE_CLASS = 1173641377;
			static const unsigned int VARIABLE_CLASS_FEATURE_COUNT = 19;
			static const unsigned int VARIABLE_CLASS_OPERATION_COUNT = 1;
			
			static const long long VARIABLE_ATTRIBUTE_BASEEXP = 1199498409;
			static const long long VARIABLE_ATTRIBUTE_INITEXPRESSION = 1334231038;
			static const long long VARIABLE_ATTRIBUTE_LOOPEXP = 979253676;
			static const long long VARIABLE_ATTRIBUTE_REFERRINGEXP = 215524417;
			static const long long VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER = 294243133;
			static const long long VARIABLE_ATTRIBUTE_RESULTOWNER = 77012464;
			static const long long VARIABLE_ATTRIBUTE_SELFOWNER = 525315198;
			static const long long VARIABLE_ATTRIBUTE_VALUE = 1394916563;
			static const long long VARIABLE_ATTRIBUTE_VAROWNER = 649811158;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getVariable_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_baseExp() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_initExpression() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_loopExp() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_referringExp() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_representedParameter() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_resultOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_selfOwner() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_value() const = 0;
			virtual std::shared_ptr<ecore::EReference> getVariable_Attribute_varOwner() const = 0;
			
			
			// End Class Variable


			// Begin Class VariableExp
			//Class and Feature IDs 
			static const long long VARIABLEEXP_CLASS = 838051098;
			static const unsigned int VARIABLEEXP_CLASS_FEATURE_COUNT = 23;
			static const unsigned int VARIABLEEXP_CLASS_OPERATION_COUNT = 1;
			
			static const long long VARIABLEEXP_ATTRIBUTE_REFERREDVARIABLE = 841820569;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getVariableExp_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getVariableExp_Attribute_referredVariable() const = 0;
			
			
			// End Class VariableExp

			static const int COLLECTIONKIND_CLASS = 13;
			
			virtual std::shared_ptr<ecore::EEnum> getCollectionKind_Class() const = 0;
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ExpressionsPackage> instance;
			public:
				static std::shared_ptr<ExpressionsPackage> eInstance();
	};
}
#endif /* end of include guard: OCL_EXPRESSIONSPACKAGE_HPP */
