//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONSPACKAGE_HPP
#define FUML_MDE4CPP_EXTENSIONSPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EDataType;
	class EAttribute;
	class EParameter;
	class EClass;
	class EReference;
	class EOperation;
	class EAnnotation;
	class EGenericType;
}

namespace fUML::MDE4CPP_Extensions 
{
	class FUML_Link;
	class FUML_LinkEnd;
	class FUML_Object;
	class FUML_SignalInstance;
}
 
namespace fUML::MDE4CPP_Extensions 
{
	/*!
	The Metamodel Package for the MDE4CPP_Extensions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API MDE4CPP_ExtensionsPackage : virtual public ecore::EPackage 
	{
		private:    
			MDE4CPP_ExtensionsPackage(MDE4CPP_ExtensionsPackage const&) = delete;
			MDE4CPP_ExtensionsPackage& operator=(MDE4CPP_ExtensionsPackage const&) = delete;

		protected:
			MDE4CPP_ExtensionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class FUML_Link
			//Class and Feature IDs 
			static const unsigned long FUML_LINK_CLASS = 1317507267;
			static const unsigned int FUML_LINK_CLASS_FEATURE_COUNT = 2;
			static const unsigned int FUML_LINK_CLASS_OPERATION_COUNT = 5;
			
			static const unsigned long FUML_LINK_ATTRIBUTE_LINKENDS = 487915139;
			static const unsigned long FUML_LINK_ATTRIBUTE_TYPE = 894190498;
			
			static const unsigned long FUML_LINK_OPERATION_ADD_FUML_OBJECT_PROPERTY = 2782434456;
			static const unsigned long FUML_LINK_OPERATION_ADD_FUML_OBJECT_EINT = 1930469695;
			static const unsigned long FUML_LINK_OPERATION_DESTROY = 1266427544;
			static const unsigned long FUML_LINK_OPERATION_RETRIEVELINKEND_PROPERTY = 2164603078;
			static const unsigned long FUML_LINK_OPERATION_RETRIEVELINKENDVALUE_PROPERTY = 2560483969;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getFUML_Link_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getFUML_Link_Attribute_linkEnds() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getFUML_Link_Attribute_type() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Link_Operation_add_FUML_Object_Property() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Link_Operation_add_FUML_Object_EInt() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Link_Operation_destroy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Link_Operation_retrieveLinkEnd_Property() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Link_Operation_retrieveLinkEndValue_Property() const = 0;
			
			// End Class FUML_Link


			// Begin Class FUML_LinkEnd
			//Class and Feature IDs 
			static const unsigned long FUML_LINKEND_CLASS = 1635365763;
			static const unsigned int FUML_LINKEND_CLASS_FEATURE_COUNT = 3;
			static const unsigned int FUML_LINKEND_CLASS_OPERATION_COUNT = 0;
			static const unsigned long FUML_LINKEND_ATTRIBUTE_POSITION = 746119650;
			
			static const unsigned long FUML_LINKEND_ATTRIBUTE_END = 1861057324;
			static const unsigned long FUML_LINKEND_ATTRIBUTE_ENDVALUE = 1305940166;
			
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getFUML_LinkEnd_Class() const = 0;
			
			virtual const std::shared_ptr<ecore::EAttribute>& getFUML_LinkEnd_Attribute_position() const = 0;
			
			virtual const std::shared_ptr<ecore::EReference>& getFUML_LinkEnd_Attribute_end() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getFUML_LinkEnd_Attribute_endValue() const = 0;
			
			
			// End Class FUML_LinkEnd


			// Begin Class FUML_Object
			//Class and Feature IDs 
			static const unsigned long FUML_OBJECT_CLASS = 1012292556;
			static const unsigned int FUML_OBJECT_CLASS_FEATURE_COUNT = 7;
			static const unsigned int FUML_OBJECT_CLASS_OPERATION_COUNT = 48;
			
			static const unsigned long FUML_OBJECT_ATTRIBUTE_LINKS = 376392934;
			static const unsigned long FUML_OBJECT_ATTRIBUTE_LOCUS = 121078438;
			static const unsigned long FUML_OBJECT_ATTRIBUTE_OBJECTACTIVATION = 1242096493;
			
			static const unsigned long FUML_OBJECT_OPERATION__REGISTER_EVENTACCEPTER = 2307607380;
			static const unsigned long FUML_OBJECT_OPERATION_ADDTO_FUML_LINK_PROPERTY = 3737882179;
			static const unsigned long FUML_OBJECT_OPERATION_DESTROY = 4089641697;
			static const unsigned long FUML_OBJECT_OPERATION_GETTYPES = 1742598842;
			static const unsigned long FUML_OBJECT_OPERATION_INVOKEOPAQUEBEHAVIOR_ESTRING_EJAVAOBJECT = 738288422;
			static const unsigned long FUML_OBJECT_OPERATION_INVOKEOPAQUEBEHAVIOR_EINT_EJAVAOBJECT = 960883863;
			static const unsigned long FUML_OBJECT_OPERATION_INVOKEOPERATION_ESTRING_EJAVAOBJECT = 3231998528;
			static const unsigned long FUML_OBJECT_OPERATION_INVOKEOPERATION_EINT_EJAVAOBJECT = 3453044381;
			static const unsigned long FUML_OBJECT_OPERATION_SEND_EVENTOCCURRENCE = 1595242616;
			static const unsigned long FUML_OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE = 692191281;
			static const unsigned long FUML_OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER = 1214480524;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getFUML_Object_Class() const = 0;
			
			
			virtual const std::shared_ptr<ecore::EReference>& getFUML_Object_Attribute_links() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getFUML_Object_Attribute_locus() const = 0;
			virtual const std::shared_ptr<ecore::EReference>& getFUML_Object_Attribute_objectActivation() const = 0;
			
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation__register_EventAccepter() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_addTo_FUML_Link_Property() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_destroy() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_getTypes() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_invokeOpaqueBehavior_EString_EJavaObject() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_invokeOpaqueBehavior_EInt_EJavaObject() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_invokeOperation_EString_EJavaObject() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_invokeOperation_EInt_EJavaObject() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_send_EventOccurrence() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_startBehavior_Class_ParameterValue() const = 0;
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_Object_Operation_unregister_EventAccepter() const = 0;
			
			// End Class FUML_Object


			// Begin Class FUML_SignalInstance
			//Class and Feature IDs 
			static const unsigned long FUML_SIGNALINSTANCE_CLASS = 1484913340;
			static const unsigned int FUML_SIGNALINSTANCE_CLASS_FEATURE_COUNT = 4;
			static const unsigned int FUML_SIGNALINSTANCE_CLASS_OPERATION_COUNT = 38;
			
			
			static const unsigned long FUML_SIGNALINSTANCE_OPERATION_GETTYPE = 486596182;
			
			//Class and Feature Getter
			virtual const std::shared_ptr<ecore::EClass>& getFUML_SignalInstance_Class() const = 0;
			
			
			
			virtual const std::shared_ptr<ecore::EOperation>& getFUML_SignalInstance_Operation_getType() const = 0;
			
			// End Class FUML_SignalInstance

			
			

			

			//Singleton Getter
			public:
				static std::shared_ptr<MDE4CPP_ExtensionsPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONSPACKAGE_HPP */
