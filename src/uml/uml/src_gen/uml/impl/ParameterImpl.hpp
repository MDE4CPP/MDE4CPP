//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARAMETERPARAMETERIMPL_HPP
#define UML_PARAMETERPARAMETERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Parameter.hpp"

#include "uml/impl/ConnectableElementImpl.hpp"
#include "uml/impl/MultiplicityElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ParameterImpl : virtual public ConnectableElementImpl, virtual public MultiplicityElementImpl, virtual public Parameter 
	{
		public: 
			ParameterImpl(const ParameterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ParameterImpl& operator=(ParameterImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ParameterImpl();
			virtual std::shared_ptr<uml::Parameter> getThisParameterPtr() const;
			virtual void setThisParameterPtr(std::weak_ptr<uml::Parameter> thisParameterPtr);

			//Additional constructors for the containments back reference
			ParameterImpl(std::weak_ptr<uml::Behavior> par_behavior);
			//Additional constructors for the containments back reference
			ParameterImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ParameterImpl(std::weak_ptr<uml::Operation> par_operation);
			//Additional constructors for the containments back reference
			ParameterImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ParameterImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ParameterImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A Parameter may only be associated with a Connector end within the context of a Collaboration.
			end->notEmpty() implies collaboration->notEmpty()
			*/
			 
			virtual bool connector_end(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Only in and inout Parameters may have a delete effect. Only out, inout, and return Parameters may have a create effect.
			(effect = ParameterEffectKind::delete implies (direction = ParameterDirectionKind::_'in' or direction = ParameterDirectionKind::inout))
			and
			(effect = ParameterEffectKind::create implies (direction = ParameterDirectionKind::out or direction = ParameterDirectionKind::inout or direction = ParameterDirectionKind::return))
			*/
			 
			virtual bool in_and_out(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			virtual bool isSetDefault() ;
			/*!
			An input Parameter cannot be an exception.
			isException implies (direction <> ParameterDirectionKind::_'in' and direction <> ParameterDirectionKind::inout)
			*/
			 
			virtual bool not_exception(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Parameters typed by DataTypes cannot have an effect.
			(type.oclIsKindOf(DataType)) implies (effect = null)
			*/
			 
			virtual bool object_effect(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Reentrant behaviors cannot have stream Parameters.
			(isStream and behavior <> null) implies not behavior.isReentrant
			*/
			 
			virtual bool reentrant_behaviors(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Sets the default value for this parameter to the specified Boolean value.
			*/
			 
			virtual void setBooleanDefaultValue(bool value) ;
			/*!
			Sets the default value for this parameter to the specified integer value.
			*/
			 
			virtual void setIntegerDefaultValue(int value) ;
			/*!
			Sets the default value for this parameter to the null value.
			*/
			 
			virtual void setNullDefaultValue() ;
			/*!
			Sets the default value for this parameter to the specified real value.
			*/
			 
			virtual void setRealDefaultValue(double value) ;
			/*!
			Sets the default value for this parameter to the specified string value.
			*/
			 
			virtual void setStringDefaultValue(std::string value) ;
			/*!
			Sets the default value for this parameter to the specified unlimited natural value.
			*/
			 
			virtual void setUnlimitedNaturalDefaultValue(int value) ;
			/*!
			A Parameter cannot be a stream and exception at the same time.
			not (isException and isStream)
			*/
			 
			virtual bool stream_and_exception(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			virtual void unsetDefault() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			A String that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::string getDefault() const ;
			/*!
			A String that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setDefault (std::string _default);
			/*!
			Indicates whether a parameter is being sent into or out of a behavioral element.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::ParameterDirectionKind getDirection() const ;
			/*!
			Indicates whether a parameter is being sent into or out of a behavioral element.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setDirection (uml::ParameterDirectionKind _direction);
			/*!
			Specifies the effect that executions of the owner of the Parameter have on objects passed in or out of the parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::ParameterEffectKind getEffect() const ;
			/*!
			Specifies the effect that executions of the owner of the Parameter have on objects passed in or out of the parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setEffect (uml::ParameterEffectKind _effect);
			/*!
			Tells whether an output parameter may emit a value to the exclusion of the other outputs.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsException() const ;
			/*!
			Tells whether an output parameter may emit a value to the exclusion of the other outputs.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsException (bool _isException);
			/*!
			Tells whether an input parameter may accept values while its behavior is executing, or whether an output parameter may post values while the behavior is executing.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsStream() const ;
			/*!
			Tells whether an input parameter may accept values while its behavior is executing, or whether an output parameter may post values while the behavior is executing.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsStream (bool _isStream);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<uml::Behavior> getBehavior() const ;
			virtual void setBehavior(std::weak_ptr<uml::Behavior>) ;
			/*!
			Specifies a ValueSpecification that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getDefaultValue() const ;
			/*!
			Specifies a ValueSpecification that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDefaultValue(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			The Operation owning this parameter.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Operation> getOperation() const ;
			/*!
			The ParameterSets containing the parameter. See ParameterSet.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ParameterSet>> getParameterSet() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Parameter> m_thisParameterPtr;
	};
}
#endif /* end of include guard: UML_PARAMETERPARAMETERIMPL_HPP */