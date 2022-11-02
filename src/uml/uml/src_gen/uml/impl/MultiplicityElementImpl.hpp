//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MULTIPLICITYELEMENTMULTIPLICITYELEMENTIMPL_HPP
#define UML_MULTIPLICITYELEMENTMULTIPLICITYELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../MultiplicityElement.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API MultiplicityElementImpl : virtual public ElementImpl, virtual public MultiplicityElement 
	{
		public: 
			MultiplicityElementImpl(const MultiplicityElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			MultiplicityElementImpl& operator=(MultiplicityElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			MultiplicityElementImpl();
			virtual std::shared_ptr<uml::MultiplicityElement> getThisMultiplicityElementPtr() const;
			virtual void setThisMultiplicityElementPtr(std::weak_ptr<uml::MultiplicityElement> thisMultiplicityElementPtr);

			//Additional constructors for the containments back reference
			MultiplicityElementImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~MultiplicityElementImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The operation compatibleWith takes another multiplicity as input. It returns true if the other multiplicity is wider than, or the same as, self.
			result = ((other.lowerBound() <= self.lowerBound()) and ((other.upperBound() = *) or (self.upperBound() <= other.upperBound())))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool compatibleWith(std::shared_ptr<uml::MultiplicityElement> other) ;
			/*!
			The query includesMultiplicity() checks whether this multiplicity includes all the cardinalities allowed by the specified multiplicity.
			self.upperBound()->notEmpty() and self.lowerBound()->notEmpty() and M.upperBound()->notEmpty() and M.lowerBound()->notEmpty()
			result = ((self.lowerBound() <= M.lowerBound()) and (self.upperBound() >= M.upperBound()))
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool includesMultiplicity(std::shared_ptr<uml::MultiplicityElement> M) ;
			/*!
			The operation is determines if the upper and lower bound of the ranges are the ones given.
			result = (lowerbound = self.lowerBound() and upperbound = self.upperBound())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool is(int lowerbound, int upperbound) ;
			/*!
			The query isMultivalued() checks whether this multiplicity has an upper bound greater than one.
			upperBound()->notEmpty()
			result = (upperBound() > 1)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isMultivalued() ;
			/*!
			The query lowerBound() returns the lower bound of the multiplicity as an integer, which is the integerValue of lowerValue, if this is given, and 1 otherwise.
			result = (if (lowerValue=null or lowerValue.integerValue()=null) then 1 else lowerValue.integerValue() endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int lowerBound() ;
			/*!
			The query upperBound() returns the upper bound of the multiplicity for a bounded multiplicity as an unlimited natural, which is the unlimitedNaturalValue of upperValue, if given, and 1, otherwise.
			result = (if (upperValue=null or upperValue.unlimitedValue()=null) then 1 else upperValue.unlimitedValue() endif)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int upperBound() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this MultiplicityElement are sequentially ordered.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool getIsOrdered() const ;
			/*!
			For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this MultiplicityElement are sequentially ordered.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setIsOrdered (bool _isOrdered);
			/*!
			For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this MultiplicityElement are unique.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool getIsUnique() const ;
			/*!
			For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this MultiplicityElement are unique.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setIsUnique (bool _isUnique);
			/*!
			The lower bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int getLower() const ;
			/*!
			The lower bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setLower (int _lower);
			/*!
			The upper bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual int getUpper() const ;
			/*!
			The upper bound of the multiplicity interval.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setUpper (int _upper);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The specification of the lower bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getLowerValue() const ;
			/*!
			The specification of the lower bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setLowerValue(std::shared_ptr<uml::ValueSpecification>) ;
			/*!
			The specification of the upper bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getUpperValue() const ;
			/*!
			The specification of the upper bound for this multiplicity.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setUpperValue(std::shared_ptr<uml::ValueSpecification>) ;
			
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
			std::weak_ptr<uml::MultiplicityElement> m_thisMultiplicityElementPtr;
	};
}
#endif /* end of include guard: UML_MULTIPLICITYELEMENTMULTIPLICITYELEMENTIMPL_HPP */
