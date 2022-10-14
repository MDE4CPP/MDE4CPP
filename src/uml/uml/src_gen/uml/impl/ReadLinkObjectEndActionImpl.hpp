//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READLINKOBJECTENDACTIONREADLINKOBJECTENDACTIONIMPL_HPP
#define UML_READLINKOBJECTENDACTIONREADLINKOBJECTENDACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReadLinkObjectEndAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReadLinkObjectEndActionImpl : virtual public ActionImpl, virtual public ReadLinkObjectEndAction 
	{
		public: 
			ReadLinkObjectEndActionImpl(const ReadLinkObjectEndActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadLinkObjectEndActionImpl& operator=(ReadLinkObjectEndActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReadLinkObjectEndActionImpl();
			virtual std::shared_ptr<uml::ReadLinkObjectEndAction> getThisReadLinkObjectEndActionPtr() const;
			virtual void setThisReadLinkObjectEndActionPtr(std::weak_ptr<uml::ReadLinkObjectEndAction> thisReadLinkObjectEndActionPtr);

			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReadLinkObjectEndActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The association of the end must be an AssociationClass.
			end.association.oclIsKindOf(AssociationClass)
			*/
			 
			virtual bool association_of_association(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The ends of the association must not be static.
			end.association.memberEnd->forAll(e | not e.isStatic)
			*/
			 
			virtual bool ends_of_association(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The multiplicity of the object InputPin is 1..1.
			object.is(1,1)
			*/
			 
			virtual bool multiplicity_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The multiplicity of the result OutputPin is 1..1.
			result.is(1,1)
			*/
			 
			virtual bool multiplicity_of_result(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The end Property must be an Association memberEnd.
			end.association <> null
			*/
			 
			virtual bool property(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the object InputPin is the AssociationClass that owns the end Property.
			object.type = end.association
			*/
			 
			virtual bool type_of_object(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the result OutputPin is the same as the type of the end Property.
			result.type = end.type
			*/
			 
			virtual bool type_of_result(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Association end to be read.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getEnd() const ;
			/*!
			The Association end to be read.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setEnd(std::shared_ptr<uml::Property>) ;
			/*!
			The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const ;
			/*!
			The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) ;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const ;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::ReadLinkObjectEndAction> m_thisReadLinkObjectEndActionPtr;
	};
}
#endif /* end of include guard: UML_READLINKOBJECTENDACTIONREADLINKOBJECTENDACTIONIMPL_HPP */
