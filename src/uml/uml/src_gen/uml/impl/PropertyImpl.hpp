//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROPERTYPROPERTYIMPL_HPP
#define UML_PROPERTYPROPERTYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Property.hpp"

#include "uml/impl/ConnectableElementImpl.hpp"
#include "uml/impl/DeploymentTargetImpl.hpp"
#include "uml/impl/StructuralFeatureImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API PropertyImpl : virtual public ConnectableElementImpl, virtual public DeploymentTargetImpl, virtual public StructuralFeatureImpl, virtual public Property 
	{
		public: 
			PropertyImpl(const PropertyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PropertyImpl& operator=(PropertyImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PropertyImpl();
			virtual std::shared_ptr<uml::Property> getThisPropertyPtr() const;
			virtual void setThisPropertyPtr(std::weak_ptr<uml::Property> thisPropertyPtr);

			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Property> par_associationEnd);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Class> par_class);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::DataType> par_datatype);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Interface> par_interface);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::Association> par_owningAssociation);
			//Additional constructors for the containments back reference
			PropertyImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~PropertyImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			/*!
			Retrieves the other end of the (binary) association in which this property is a member end.
			*/
			 
			virtual std::shared_ptr<uml::Property> getOtherEnd() ;
			/*!
			The query isAttribute() is true if the Property is defined as an attribute of some Classifier.
			result = (not classifier->isEmpty())
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isAttribute() ;
			/*!
			The value of isComposite is true only if aggregation is composite.
			result = (aggregation = AggregationKind::composite)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isComposite() ;
			/*!
			The query isNavigable() indicates whether it is possible to navigate across the property.
			result = (not classifier->isEmpty() or association.navigableOwnedEnd->includes(self))
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isNavigable() ;
			virtual bool isSetDefault() ;
			/*!
			Sets the default value for this property to the specified Boolean value.
			*/
			 
			virtual void setBooleanDefaultValue(bool value) ;
			/*!
			Sets the default value for this property to the specified integer value.
			*/
			 
			virtual void setIntegerDefaultValue(int value) ;
			/*!
			Sets the navigability of this property as indicated.
			*/
			 
			virtual void setIsNavigable(bool isNavigable) ;
			/*!
			Sets the default value for this property to the null value.
			*/
			 
			virtual void setNullDefaultValue() ;
			/*!
			Sets the default value for this property to the specified real value.
			*/
			 
			virtual void setRealDefaultValue(double value) ;
			/*!
			Sets the default value for this property to the specified string value.
			*/
			 
			virtual void setStringDefaultValue(std::string value) ;
			/*!
			Sets the default value for this property to the specified unlimited natural value.
			*/
			 
			virtual void setUnlimitedNaturalDefaultValue(int value) ;
			/*!
			The query subsettingContext() gives the context for subsetting a Property. It consists, in the case of an attribute, of the corresponding Classifier, and in the case of an association end, all of the Classifiers at the other ends.
			result = (if association <> null
			then association.memberEnd->excluding(self)->collect(type)->asSet()
			else 
			  if classifier<>null
			  then classifier->asSet()
			  else Set{} 
			  endif
			endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Type>> subsettingContext() ;
			virtual void unsetDefault() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the kind of aggregation that applies to the Property.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::AggregationKind getAggregation() const ;
			/*!
			Specifies the kind of aggregation that applies to the Property.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setAggregation (uml::AggregationKind _aggregation);
			virtual std::string getDefault() const ;
			virtual void setDefault (std::string _default);
			/*!
			If isComposite is true, the object containing the attribute is a container for the object or value contained in the attribute. This is a derived value, indicating whether the aggregation of the Property is composite or not.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsComposite() const ;
			/*!
			If isComposite is true, the object containing the attribute is a container for the object or value contained in the attribute. This is a derived value, indicating whether the aggregation of the Property is composite or not.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsComposite (bool _isComposite);
			/*!
			Specifies whether the Property is derived, i.e., whether its value or values can be computed from other information.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsDerived() const ;
			/*!
			Specifies whether the Property is derived, i.e., whether its value or values can be computed from other information.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsDerived (bool _isDerived);
			/*!
			Specifies whether the property is derived as the union of all of the Properties that are constrained to subset it.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsDerivedUnion() const ;
			/*!
			Specifies whether the property is derived as the union of all of the Properties that are constrained to subset it.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsDerivedUnion (bool _isDerivedUnion);
			/*!
			True indicates this property can be used to uniquely identify an instance of the containing Class.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsID() const ;
			/*!
			True indicates this property can be used to uniquely identify an instance of the containing Class.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsID (bool _isID);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Association of which this Property is a member, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::Association>& getAssociation() const ;
			/*!
			The Association of which this Property is a member, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setAssociation(const std::shared_ptr<uml::Association>&) ;
			/*!
			Designates the optional association end that owns a qualifier attribute.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Property> getAssociationEnd() const ;
			/*!
			Designates the optional association end that owns a qualifier attribute.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setAssociationEnd(std::weak_ptr<uml::Property>) ;
			/*!
			The Class that owns this Property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Class> getClass() const ;
			/*!
			The Class that owns this Property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setClass(std::weak_ptr<uml::Class>) ;
			/*!
			The DataType that owns this Property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::DataType> getDatatype() const ;
			/*!
			The DataType that owns this Property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDatatype(std::weak_ptr<uml::DataType>) ;
			/*!
			A ValueSpecification that is evaluated to give a default value for the Property when an instance of the owning Classifier is instantiated.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::ValueSpecification>& getDefaultValue() const ;
			/*!
			A ValueSpecification that is evaluated to give a default value for the Property when an instance of the owning Classifier is instantiated.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDefaultValue(const std::shared_ptr<uml::ValueSpecification>&) ;
			/*!
			The Interface that owns this Property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Interface> getInterface() const ;
			/*!
			The Interface that owns this Property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setInterface(std::weak_ptr<uml::Interface>) ;
			/*!
			In the case where the Property is one end of a binary association this gives the other end.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<uml::Property>& getOpposite() const ;
			/*!
			In the case where the Property is one end of a binary association this gives the other end.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setOpposite(const std::shared_ptr<uml::Property>&) ;
			/*!
			The owning association of this property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Association> getOwningAssociation() const ;
			/*!
			The owning association of this property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setOwningAssociation(std::weak_ptr<uml::Association>) ;
			/*!
			An optional list of ordered qualifier attributes for the end.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Property, uml::Element>>& getQualifier() const ;
			/*!
			The properties that are redefined by this property, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<SubsetUnion<uml::Property, uml::RedefinableElement>>& getRedefinedProperty() const ;
			/*!
			The properties of which this Property is constrained to be a subset, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Property>>& getSubsettedProperty() const ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<uml::Property> m_thisPropertyPtr;
	};
}
#endif /* end of include guard: UML_PROPERTYPROPERTYIMPL_HPP */
