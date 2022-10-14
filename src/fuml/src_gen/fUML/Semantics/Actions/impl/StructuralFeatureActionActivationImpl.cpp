
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
//#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
//#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
//Forward declaration includes
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Association.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/Property.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuralFeatureActionActivationImpl::~StructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:StructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}

StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl(const StructuralFeatureActionActivationImpl & obj): StructuralFeatureActionActivationImpl()
{
	*this = obj;
}

StructuralFeatureActionActivationImpl& StructuralFeatureActionActivationImpl::operator=(const StructuralFeatureActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StructuralFeatureActionActivation 
	 * which is generated by the compiler (as StructuralFeatureActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StructuralFeatureActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Association> StructuralFeatureActionActivationImpl::getAssociation(std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// If the structural feature for the action of this activation is an association end,
// then get the associated association.

std::shared_ptr<uml::Association> association = nullptr;
std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property>(feature);

if(property != nullptr)
{
	association = property->getAssociation();
}

return association;
	//end of body
}

std::shared_ptr<Bag<uml::Element>> StructuralFeatureActionActivationImpl::getMatchingLinks(std::shared_ptr<uml::Association> association, std::shared_ptr<uml::StructuralFeature> end, std::shared_ptr<Any> oppositeValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the links of the given binary association whose end opposite
// to the given end has the given value

return getMatchingLinksForEndValue(association, end, oppositeValue, nullptr);
	//end of body
}

std::shared_ptr<Bag<uml::Element>> StructuralFeatureActionActivationImpl::getMatchingLinksForEndValue(std::shared_ptr<uml::Association> association, std::shared_ptr<uml::StructuralFeature> end, std::shared_ptr<Any> oppositeValue, std::shared_ptr<Any> endValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the links of the given binary association whose end opposite
// to the given end has the given opposite value and, optionally, that
// has a given end value for the given end.

/* Currently not supported
std::shared_ptr<uml::Property> oppositeEnd = getOppositeEnd(association, end);

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent = this->getExecutionLocus()->retrieveExtent(association);

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links(new Bag<fUML::Semantics::StructuredClassifiers::Link>);
for(unsigned int i = 0; i < extent->size(); i++){
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> link = extent->at(i);
	if(link->retrieveFeatureValue(oppositeEnd)->getValues()->at(0) == oppositeValue) {
		bool matches = true;
		if(endValue != nullptr) {
			matches = (link->retrieveFeatureValue(end)->getValues()->at(0) == endValue);
		}
		
		if(matches){
			if(!(std::dynamic_pointer_cast<uml::MultiplicityElement>(end)->getIsOrdered()) || (links->size() == 0)){
				links->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
			}
			else {
				unsigned int n = link->retrieveFeatureValue(end)->getPosition();
				bool continueSearching = true;
				unsigned int j = 0;
				while(continueSearching && (j < links->size())){
					j += 1;
					continueSearching = (unsigned int)(links->at(j-1)->retrieveFeatureValue(end)->getPosition()) < n;
				}
				if(continueSearching){
					links->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
				}
				else {
					links->insert((links->begin() + (j-1)), std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
				}
			}
		}
	}
}

return links;
*/

throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
	//end of body
}

std::shared_ptr<uml::Property> StructuralFeatureActionActivationImpl::getOppositeEnd(std::shared_ptr<uml::Association> association, std::shared_ptr<uml::StructuralFeature> end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the end of a binary association opposite to the given end.

std::shared_ptr<uml::Property> oppositeEnd = association->getMemberEnd()->at(0);
if(oppositeEnd == end)
{
		oppositeEnd = association->getMemberEnd()->at(1);
}

return oppositeEnd;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StructuralFeatureActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<ecore::EClass> StructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuralFeatureActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool StructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool StructuralFeatureActionActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> StructuralFeatureActionActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getAssociation(uml::StructuralFeature) : uml::Association: 4112546735
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			Bag<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_feature_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_feature = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'getAssociation'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'feature'. Failed to invoke operation 'getAssociation'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getAssociation(incoming_param_feature), uml::umlPackage::ASSOCIATION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getMatchingLinks(uml::Association, uml::StructuralFeature, Any) : uml::Element[*]: 2765304632
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_EJAVAOBJECT:
		{
			//Retrieve input parameter 'association'
			//parameter 0
			std::shared_ptr<uml::Association> incoming_param_association;
			Bag<Any>::const_iterator incoming_param_association_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_association_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_association = std::dynamic_pointer_cast<uml::Association>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'association'. Failed to invoke operation 'getMatchingLinks'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'association'. Failed to invoke operation 'getMatchingLinks'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'end'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_end;
			Bag<Any>::const_iterator incoming_param_end_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_end_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_end = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'end'. Failed to invoke operation 'getMatchingLinks'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'end'. Failed to invoke operation 'getMatchingLinks'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'oppositeValue'
			//parameter 2
			std::shared_ptr<Any> incoming_param_oppositeValue;
			Bag<Any>::const_iterator incoming_param_oppositeValue_arguments_citer = std::next(arguments->begin(), 2);
			try
			{
				incoming_param_oppositeValue = (*incoming_param_oppositeValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'oppositeValue'. Failed to invoke operation 'getMatchingLinks'!")
				return nullptr;
			}
		
			std::shared_ptr<Bag<uml::Element>> resultList = this->getMatchingLinks(incoming_param_association,incoming_param_end,incoming_param_oppositeValue);
			return eEcoreContainerAny(resultList,uml::umlPackage::ELEMENT_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getMatchingLinksForEndValue(uml::Association, uml::StructuralFeature, Any, Any) : uml::Element[*]: 2298435547
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_EJAVAOBJECT:
		{
			//Retrieve input parameter 'association'
			//parameter 0
			std::shared_ptr<uml::Association> incoming_param_association;
			Bag<Any>::const_iterator incoming_param_association_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_association_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_association = std::dynamic_pointer_cast<uml::Association>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'association'. Failed to invoke operation 'getMatchingLinksForEndValue'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'association'. Failed to invoke operation 'getMatchingLinksForEndValue'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'end'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_end;
			Bag<Any>::const_iterator incoming_param_end_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_end_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_end = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'end'. Failed to invoke operation 'getMatchingLinksForEndValue'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'end'. Failed to invoke operation 'getMatchingLinksForEndValue'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'oppositeValue'
			//parameter 2
			std::shared_ptr<Any> incoming_param_oppositeValue;
			Bag<Any>::const_iterator incoming_param_oppositeValue_arguments_citer = std::next(arguments->begin(), 2);
			try
			{
				incoming_param_oppositeValue = (*incoming_param_oppositeValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'oppositeValue'. Failed to invoke operation 'getMatchingLinksForEndValue'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'endValue'
			//parameter 3
			std::shared_ptr<Any> incoming_param_endValue;
			Bag<Any>::const_iterator incoming_param_endValue_arguments_citer = std::next(arguments->begin(), 3);
			try
			{
				incoming_param_endValue = (*incoming_param_endValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'endValue'. Failed to invoke operation 'getMatchingLinksForEndValue'!")
				return nullptr;
			}
		
			std::shared_ptr<Bag<uml::Element>> resultList = this->getMatchingLinksForEndValue(incoming_param_association,incoming_param_end,incoming_param_oppositeValue,incoming_param_endValue);
			return eEcoreContainerAny(resultList,uml::umlPackage::ELEMENT_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getOppositeEnd(uml::Association, uml::StructuralFeature) : uml::Property: 1289289959
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE:
		{
			//Retrieve input parameter 'association'
			//parameter 0
			std::shared_ptr<uml::Association> incoming_param_association;
			Bag<Any>::const_iterator incoming_param_association_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_association_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_association = std::dynamic_pointer_cast<uml::Association>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'association'. Failed to invoke operation 'getOppositeEnd'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'association'. Failed to invoke operation 'getOppositeEnd'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'end'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_end;
			Bag<Any>::const_iterator incoming_param_end_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_end_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_end = std::dynamic_pointer_cast<uml::StructuralFeature>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'end'. Failed to invoke operation 'getOppositeEnd'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'end'. Failed to invoke operation 'getOppositeEnd'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->getOppositeEnd(incoming_param_association,incoming_param_end), uml::umlPackage::PROPERTY_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> StructuralFeatureActionActivationImpl::getThisStructuralFeatureActionActivationPtr() const
{
	return m_thisStructuralFeatureActionActivationPtr.lock();
}
void StructuralFeatureActionActivationImpl::setThisStructuralFeatureActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> thisStructuralFeatureActionActivationPtr)
{
	m_thisStructuralFeatureActionActivationPtr = thisStructuralFeatureActionActivationPtr;
	setThisActionActivationPtr(thisStructuralFeatureActionActivationPtr);
}


