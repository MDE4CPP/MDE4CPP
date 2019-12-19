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
#include "PSCS/impl/PSCSPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

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

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_appliedProfiles.reset(new Bag<uml::Package>());
	
	

	//Init references
	
	
}

CS_ExecutionFactoryImpl::~CS_ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus)
			:CS_ExecutionFactoryImpl()
			{
			    m_locus = par_locus;
			}






CS_ExecutionFactoryImpl::CS_ExecutionFactoryImpl(const CS_ExecutionFactoryImpl & obj):CS_ExecutionFactoryImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Package>> _appliedProfiles = obj.getAppliedProfiles();
	m_appliedProfiles.reset(new Bag<uml::Package>(*(obj.getAppliedProfiles().get())));

	std::shared_ptr<Bag<uml::PrimitiveType>> _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::Semantics::Loci::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  CS_ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<CS_ExecutionFactoryImpl> element(new CS_ExecutionFactoryImpl(*this));
	element->setThisCS_ExecutionFactoryPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ExecutionFactoryImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_ExecutionFactory_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_ExecutionFactoryImpl::getStereotypeApplication(std::shared_ptr<uml::Class>  stereotype,std::shared_ptr<uml::Element>  element)
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

std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> CS_ExecutionFactoryImpl::instantiateVisitor(std::shared_ptr<uml::Element>  element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Extends fUML semantics in the sense that newly introduced 
	// semantic visitors are instantiated instead of fUML visitors
	std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> visitor = nullptr;
	
	if(std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventBehavior>(element) != nullptr) {
		return PSCS::PSCSFactory::eInstance()->createCS_CallEventExecution();
	}
	
	switch(element->eClass()->getClassifierID())
	{
		case uml::UmlPackage::READEXTENTACTION_CLASS: 
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_ReadExtentActionActivation();
			break;
		}
		case uml::UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_AddStructuralFeatureValueActionActivation();
			break;
		}
		case uml::UmlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_ClearStructuralFeatureActionActivation();
			break;
		}
		case uml::UmlPackage::CREATELINKACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_CreateLinkActionActivation();
			break;
		}
		case uml::UmlPackage::CREATEOBJECTACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_CreateObjectActionActivation();
			break;
		}
		case uml::UmlPackage::READSELFACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_ReadSelfActionActivation();
			break;
		}
		case uml::UmlPackage::ACCEPTCALLACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_AcceptCallActionActivation();
			break;
		}
		case uml::UmlPackage::INSTANCEVALUE_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_InstanceValueEvaluation();
			break;
		}
		case uml::UmlPackage::ACCEPTEVENTACTION_CLASS: 
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_AcceptEventActionActivation();
			break;
		}
		case uml::UmlPackage::CALLOPERATIONACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_CallOperationActionActivation();
			break;
		}
		case uml::UmlPackage::SENDSIGNALACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_SendSignalActionActivation();
			break;
		}
		case uml::UmlPackage::OPAQUEEXPRESSION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_OpaqueExpressionEvaluation();
			break;
		}
		case uml::UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			visitor = PSCS::PSCSFactory::eInstance()->createCS_RemoveStructuralFeatureValueActionActivation();
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
// References
//*********************************
std::shared_ptr<Bag<uml::Package>> CS_ExecutionFactoryImpl::getAppliedProfiles() const
{

    return m_appliedProfiles;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_ExecutionFactory> CS_ExecutionFactoryImpl::getThisCS_ExecutionFactoryPtr() const
{
	return m_thisCS_ExecutionFactoryPtr.lock();
}
void CS_ExecutionFactoryImpl::setThisCS_ExecutionFactoryPtr(std::weak_ptr<CS_ExecutionFactory> thisCS_ExecutionFactoryPtr)
{
	m_thisCS_ExecutionFactoryPtr = thisCS_ExecutionFactoryPtr;
	setThisExecutionFactoryPtr(thisCS_ExecutionFactoryPtr);
}
std::shared_ptr<ecore::EObject> CS_ExecutionFactoryImpl::eContainer() const
{
	if(auto wp = m_locus.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_ExecutionFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Package>::iterator iter = m_appliedProfiles->begin();
			Bag<uml::Package>::iterator end = m_appliedProfiles->end();
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
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
			return getAppliedProfiles() != nullptr; //144
	}
	return fUML::Semantics::Loci::ExecutionFactoryImpl::internalEIsSet(featureID);
}
bool CS_ExecutionFactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
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
			
			Bag<uml::Package>::iterator iterAppliedProfiles = m_appliedProfiles->begin();
			Bag<uml::Package>::iterator endAppliedProfiles = m_appliedProfiles->end();
			while (iterAppliedProfiles != endAppliedProfiles)
			{
				if (appliedProfilesList->find(*iterAppliedProfiles) == -1)
				{
					m_appliedProfiles->erase(*iterAppliedProfiles);
				}
				iterAppliedProfiles++;
			}

			iterAppliedProfiles = appliedProfilesList->begin();
			endAppliedProfiles = appliedProfilesList->end();
			while (iterAppliedProfiles != endAppliedProfiles)
			{
				if (m_appliedProfiles->find(*iterAppliedProfiles) == -1)
				{
					m_appliedProfiles->add(*iterAppliedProfiles);
				}
				iterAppliedProfiles++;			
			}
			return true;
		}
	}

	return fUML::Semantics::Loci::ExecutionFactoryImpl::eSet(featureID, newValue);
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
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void CS_ExecutionFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	fUML::Semantics::Loci::ExecutionFactoryImpl::loadNode(nodeName, loadHandler, fUML::FUMLFactory::eInstance());
}

void CS_ExecutionFactoryImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_EXECUTIONFACTORY_ATTRIBUTE_APPLIEDPROFILES:
		{
			std::shared_ptr<Bag<uml::Package>> _appliedProfiles = getAppliedProfiles();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Package> _r = std::dynamic_pointer_cast<uml::Package>(ref);
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
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::Package>> appliedProfiles_list = this->getAppliedProfiles();
		for (std::shared_ptr<uml::Package > object : *appliedProfiles_list)
		{ 
			saveHandler->addReferences("appliedProfiles", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

