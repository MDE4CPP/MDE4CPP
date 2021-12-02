
#include "PSCS/Semantics/Loci/impl/CS_ExecutionFactoryImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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

#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/umlPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

#include "uml/ReadExtentAction.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/CreateLinkAction.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/AcceptCallAction.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/AcceptEventAction.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/SendSignalAction.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/CommonBehavior/CallEventBehavior.hpp"

#include "PSCS/Semantics/Actions/CS_ReadExtentActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_AddStructuralFeatureValueActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_ClearStructuralFeatureActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_CreateLinkActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_CreateObjectActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_ReadSelfActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_AcceptCallActionActivation.hpp"
#include "PSCS/Semantics/Classification/CS_InstanceValueEvaluation.hpp"
#include "PSCS/Semantics/Actions/CS_AcceptEventActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_CallOperationActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_SendSignalActionActivation.hpp"
#include "PSCS/Semantics/Actions/CS_RemoveStructuralFeatureValueActionActivation.hpp"
#include "PSCS/Semantics/Values/CS_OpaqueExpressionEvaluation.hpp"
#include "PSCS/Semantics/CommonBehavior/CS_CallEventExecution.hpp"
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSCS/Semantics/Actions/ActionsFactory.hpp"
#include "PSCS/Semantics/Classification/ClassificationFactory.hpp"
#include "PSCS/Semantics/Values/ValuesFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"

#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/CommonBehavior/OpaqueBehaviorExecution.hpp"
#include "uml/Package.hpp"
#include "uml/PrimitiveType.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

//Factories an Package includes
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSCS/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_ExecutionFactoryImpl::~CS_ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus)
:CS_ExecutionFactoryImpl()
{
	m_locus = par_locus;
}

CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl(const CS_ExecutionFactoryImpl & obj): CS_ExecutionFactoryImpl()
{
	*this = obj;
}

CS_ExecutionFactoryImpl& CS_ExecutionFactoryImpl::operator=(const CS_ExecutionFactoryImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::ExecutionFactoryImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_ExecutionFactory 
	 * which is generated by the compiler (as CS_ExecutionFactory is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_ExecutionFactory::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_appliedProfiles  = obj.getAppliedProfiles();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<CS_ExecutionFactoryImpl> element(new CS_ExecutionFactoryImpl());
	*element =(*this);
	element->setThisCS_ExecutionFactoryPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_ExecutionFactoryImpl::getStereotypeApplication(std::shared_ptr<uml::Class> stereotype,std::shared_ptr<uml::Element> element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent = this->getLocus().lock()->retrieveExtent(stereotype);
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> extensionObject = nullptr;
	unsigned int i = 1;
	while((i <= extent->size()) && (extensionObject == nullptr)) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> object = extent->at(i-1);
		
	//Aktuell nicht funktionfähig, unbekannte Variable "baseEnd"
		/*if(object->retrieveFeatureValue(baseEnd)->getValues()->at(0)->equals(element)) {
			extensionObject = dynamic_pointer_cast<fUML::Object>(object);
		}*/
		i++;
	}
	return extensionObject;
	//end of body
}

std::shared_ptr<uml::Classifier> CS_ExecutionFactoryImpl::getStereotypeClass(std::string profileName,std::string stereotypeName)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return nullptr;
	//end of body
}

std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> CS_ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element> element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Extends fUML semantics in the sense that newly introduced 
	// semantic visitors are instantiated instead of fUML visitors
	std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> visitor = nullptr;
	
	switch(element->eClass()->getClassifierID())
	{
		case uml::umlPackage::READEXTENTACTION_CLASS: 
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_ReadExtentActionActivation();
			break;
		}
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_AddStructuralFeatureValueActionActivation();
			break;
		}
		case uml::umlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_ClearStructuralFeatureActionActivation();
			break;
		}
		case uml::umlPackage::CREATELINKACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_CreateLinkActionActivation();
			break;
		}
		case uml::umlPackage::CREATEOBJECTACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_CreateObjectActionActivation();
			break;
		}
		case uml::umlPackage::READSELFACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_ReadSelfActionActivation();
			break;
		}
		case uml::umlPackage::ACCEPTCALLACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_AcceptCallActionActivation();
			break;
		}
		case uml::umlPackage::INSTANCEVALUE_CLASS:
		{
			visitor = PSCS::Semantics::Classification::ClassificationFactory::eInstance()->createCS_InstanceValueEvaluation();
			break;
		}
		case uml::umlPackage::ACCEPTEVENTACTION_CLASS: 
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_AcceptEventActionActivation();
			break;
		}
		case uml::umlPackage::CALLOPERATIONACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_CallOperationActionActivation();
			break;
		}
		case uml::umlPackage::SENDSIGNALACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_SendSignalActionActivation();
			break;
		}
		case uml::umlPackage::OPAQUEEXPRESSION_CLASS:
		{
			visitor = PSCS::Semantics::Values::ValuesFactory::eInstance()->createCS_OpaqueExpressionEvaluation();
			break;
		}
		case uml::umlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = PSCS::Semantics::Actions::ActionsFactory::eInstance()->createCS_RemoveStructuralFeatureValueActionActivation();
			break;
		}
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTBEHAVIOR_CLASS:
		{
			visitor = PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_CallEventExecution();
			break;
		}
		default:
		{
			visitor = fUML::Semantics::Loci::ExecutionFactoryImpl::instantiateVisitor(element);
		}
	}

	return visitor;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference appliedProfiles */
std::shared_ptr<Bag<uml::Package>> CS_ExecutionFactoryImpl::getAppliedProfiles() const
{
	if(m_appliedProfiles == nullptr)
	{
		m_appliedProfiles.reset(new Bag<uml::Package>());
		
		
	}
    return m_appliedProfiles;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CS_ExecutionFactoryImpl::eContainer() const
{
	if(auto wp = m_locus.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_ExecutionFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_ExecutionFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("appliedProfiles");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("appliedProfiles")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	fUML::Semantics::Loci::ExecutionFactoryImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ExecutionFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::ExecutionFactoryImpl::loadNode(nodeName, loadHandler);
}

void CS_ExecutionFactoryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::Loci::LociPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			std::shared_ptr<Bag<uml::Package>> _appliedProfiles = getAppliedProfiles();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Package>  _r = std::dynamic_pointer_cast<uml::Package>(ref);
				if (_r != nullptr)
				{
					_appliedProfiles->push_back(_r);
				}
			}
			return;
		}
	}
	fUML::Semantics::Loci::ExecutionFactoryImpl::resolveReferences(featureID, references);
}

void CS_ExecutionFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_ExecutionFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Loci::LociPackage> package = PSCS::Semantics::Loci::LociPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Package>("appliedProfiles", this->getAppliedProfiles());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> CS_ExecutionFactoryImpl::eStaticClass() const
{
	return PSCS::Semantics::Loci::LociPackage::eInstance()->getCS_ExecutionFactory_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_ExecutionFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::Loci::LociPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Package>::iterator iter = getAppliedProfiles()->begin();
			Bag<uml::Package>::iterator end = getAppliedProfiles()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //144			
		}
	}
	return fUML::Semantics::Loci::ExecutionFactoryImpl::eGet(featureID, resolve, coreType);
}

bool CS_ExecutionFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::Loci::LociPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
			return getAppliedProfiles() != nullptr; //144
	}
	return fUML::Semantics::Loci::ExecutionFactoryImpl::internalEIsSet(featureID);
}

bool CS_ExecutionFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::Loci::LociPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Package>> appliedProfilesList(new Bag<uml::Package>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				appliedProfilesList->add(std::dynamic_pointer_cast<uml::Package>(*iter));
				iter++;
			}
			
			Bag<uml::Package>::iterator iterAppliedProfiles = getAppliedProfiles()->begin();
			Bag<uml::Package>::iterator endAppliedProfiles = getAppliedProfiles()->end();
			while (iterAppliedProfiles != endAppliedProfiles)
			{
				if (appliedProfilesList->find(*iterAppliedProfiles) == -1)
				{
					getAppliedProfiles()->erase(*iterAppliedProfiles);
				}
				iterAppliedProfiles++;
			}
 
			iterAppliedProfiles = appliedProfilesList->begin();
			endAppliedProfiles = appliedProfilesList->end();
			while (iterAppliedProfiles != endAppliedProfiles)
			{
				if (getAppliedProfiles()->find(*iterAppliedProfiles) == -1)
				{
					getAppliedProfiles()->add(*iterAppliedProfiles);
				}
				iterAppliedProfiles++;			
			}
			return true;
		}
	}

	return fUML::Semantics::Loci::ExecutionFactoryImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_ExecutionFactoryImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 305337573
		case LociPackage::CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPEAPPLICATION_CLASS_ELEMENT:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Class> >();
			//Retrieve input parameter 'element'
			//parameter 1
			std::shared_ptr<uml::Element> incoming_param_element;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get()->get<std::shared_ptr<uml::Element> >();
			result = eAny(this->getStereotypeApplication(incoming_param_stereotype,incoming_param_element));
			break;
		}
		
		// 1716538227
		case LociPackage::CS_EXECUTIONFACTORY_OPERATION_GETSTEREOTYPECLASS_ESTRING_ESTRING:
		{
			//Retrieve input parameter 'profileName'
			//parameter 0
			std::string incoming_param_profileName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_profileName_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_profileName = (*incoming_param_profileName_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'stereotypeName'
			//parameter 1
			std::string incoming_param_stereotypeName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotypeName_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_stereotypeName = (*incoming_param_stereotypeName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getStereotypeClass(incoming_param_profileName,incoming_param_stereotypeName));
			break;
		}
		
		// 689017765
		case LociPackage::CS_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_element;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get()->get<std::shared_ptr<uml::Element> >();
			result = eAny(this->instantiateVisitor(incoming_param_element));
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::ExecutionFactoryImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> CS_ExecutionFactoryImpl::getThisCS_ExecutionFactoryPtr() const
{
	return m_thisCS_ExecutionFactoryPtr.lock();
}
void CS_ExecutionFactoryImpl::setThisCS_ExecutionFactoryPtr(std::weak_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> thisCS_ExecutionFactoryPtr)
{
	m_thisCS_ExecutionFactoryPtr = thisCS_ExecutionFactoryPtr;
	setThisExecutionFactoryPtr(thisCS_ExecutionFactoryPtr);
}
