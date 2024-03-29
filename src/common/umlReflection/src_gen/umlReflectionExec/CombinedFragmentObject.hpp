//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML_COMBINEDFRAGMENT_EXECUTION_HPP
#define UML_COMBINEDFRAGMENT_EXECUTION_HPP

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "umlReflectionExec/InteractionFragmentObject.hpp"

template <class T> 
class Bag;

namespace uml
{
	class CombinedFragment;
}

namespace uml
{
	class Element;
	class ConnectorEnd;
}

namespace UML 
{
	class CombinedFragmentObject : virtual public UML::InteractionFragmentObject
	{
		public:
		    //constructors
		    CombinedFragmentObject(CombinedFragmentObject &obj);
		    CombinedFragmentObject(std::shared_ptr<uml::CombinedFragment>);
		 	CombinedFragmentObject();
		    //destructor
		    virtual ~CombinedFragmentObject();
		
		    virtual std::shared_ptr<ecore::EObject> copy();
			CombinedFragmentObject& operator=(CombinedFragmentObject const&);

			virtual void destroy();
			
			virtual std::shared_ptr<uml::CombinedFragment> getCombinedFragmentValue() const;
			virtual std::shared_ptr<uml::Element> getUmlValue() const;
			virtual void setUmlValue(std::shared_ptr<uml::Element>);
			virtual void setCombinedFragmentValue(std::shared_ptr<uml::CombinedFragment>);
			virtual void setThisCombinedFragmentObjectPtr(std::weak_ptr<CombinedFragmentObject> thisObjectPtr);
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue);
			virtual std::string toString();
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> getDirectContainers();
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> values);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues);
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature);
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> retrieveFeatureValues();

			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end);

		protected:
			std::shared_ptr<uml::CombinedFragment> m_CombinedFragmentValue = nullptr;
	};
}
#endif /* end of include guard: UML_COMBINEDFRAGMENT_OBJECT_HPP */
