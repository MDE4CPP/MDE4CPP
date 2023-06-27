//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDDATALINKENDDATAIMPL_HPP
#define UML_LINKENDDATALINKENDDATAIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LinkEndData.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LinkEndDataImpl : virtual public ElementImpl, virtual public LinkEndData 
	{
		public: 
			LinkEndDataImpl(const LinkEndDataImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LinkEndDataImpl& operator=(LinkEndDataImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LinkEndDataImpl();
			virtual std::shared_ptr<uml::LinkEndData> getThisLinkEndDataPtr() const;
			virtual void setThisLinkEndDataPtr(std::weak_ptr<uml::LinkEndData> thisLinkEndDataPtr);

			//Additional constructors for the containments back reference
			LinkEndDataImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~LinkEndDataImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Returns all the InputPins referenced by this LinkEndData. By default this includes the value and qualifier InputPins, but subclasses may override the operation to add other InputPins.
			result = (value->asBag()->union(qualifier.value))
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::InputPin>> allPins() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::Property>& getEnd() const ;
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setEnd(const std::shared_ptr<uml::Property>&) ;
			/*!
			A set of QualifierValues used to provide values for the qualifiers of the end.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::QualifierValue, uml::Element>>& getQualifier() const ;
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getValue() const ;
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(const std::shared_ptr<uml::InputPin>&) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::LinkEndData> m_thisLinkEndDataPtr;
	};
}
#endif /* end of include guard: UML_LINKENDDATALINKENDDATAIMPL_HPP */
