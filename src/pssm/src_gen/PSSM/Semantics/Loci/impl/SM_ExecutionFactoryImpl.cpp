
#include "PSSM/Semantics/Loci/impl/SM_ExecutionFactoryImpl.hpp"
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

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"
#include "uml/StateMachine.hpp"
#include "uml/Pseudostate.hpp"
#include "PSSM/Semantics/StateMachines/StateMachineExecution.hpp"
#include "uml/State.hpp"
#include "uml/FinalState.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/Transition.hpp"
#include "uml/Region.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/PrimitiveType.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSSM/Semantics/Loci/LociPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
SM_ExecutionFactoryImpl::SM_ExecutionFactoryImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SM_ExecutionFactoryImpl::~SM_ExecutionFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SM_ExecutionFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SM_ExecutionFactoryImpl::SM_ExecutionFactoryImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus)
:SM_ExecutionFactoryImpl()
{
	m_locus = par_locus;
}

SM_ExecutionFactoryImpl::SM_ExecutionFactoryImpl(const SM_ExecutionFactoryImpl & obj): SM_ExecutionFactoryImpl()
{
	*this = obj;
}

SM_ExecutionFactoryImpl& SM_ExecutionFactoryImpl::operator=(const SM_ExecutionFactoryImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::ExecutionFactoryImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SM_ExecutionFactory 
	 * which is generated by the compiler (as SM_ExecutionFactory is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SM_ExecutionFactory::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SM_ExecutionFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SM_ExecutionFactoryImpl::copy() const
{
	std::shared_ptr<SM_ExecutionFactoryImpl> element(new SM_ExecutionFactoryImpl());
	*element =(*this);
	element->setThisSM_ExecutionFactoryPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> SM_ExecutionFactoryImpl::instantiateVisitor(const std::shared_ptr<uml::Element>& element)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> visitor = nullptr;

	std::shared_ptr<uml::StateMachine> is_sm = std::dynamic_pointer_cast<uml::StateMachine>(element);
	std::shared_ptr<uml::Pseudostate> is_pseudoState = std::dynamic_pointer_cast<uml::Pseudostate>(element);
	std::shared_ptr<uml::State> is_state = std::dynamic_pointer_cast<uml::State>(element);
	std::shared_ptr<uml::FinalState> is_final_state = std::dynamic_pointer_cast<uml::FinalState>(element);
	std::shared_ptr<uml::Transition> is_transition = std::dynamic_pointer_cast<uml::Transition>(element);
	std::shared_ptr<uml::Region> is_region = std::dynamic_pointer_cast<uml::Region>(element);
	std::shared_ptr<uml::OpaqueExpression> is_opaque_expression = std::dynamic_pointer_cast<uml::OpaqueExpression>(element);
	std::shared_ptr<uml::ReadSelfAction> is_read_self_action = std::dynamic_pointer_cast <uml::ReadSelfAction>(element);

	if(is_sm != nullptr) {
		//visitor = new PSSM::Semantics::StateMachines::StateMachineExecution()
	}
	else if(is_pseudoState != nullptr) {
		std::shared_ptr<uml::Pseudostate> pseudostate = is_pseudoState;
//		switch(pseudostate->getKind()){
//			case uml::PseudostateKind::INITIAL: visitor = new PSSM::Semantics::StateMachines::InitialPseudostateActivation(); break;
//			case uml::PseudostateKind::ENTRYPOINT:
//			case uml::PseudostateKind::EXITPOINT:
//			case uml::PseudostateKind::CHOICE:
//			case uml::PseudostateKind::FORK:
//			case uml::PseudostateKind::JOIN:
//			case uml::PseudostateKind::TERMINATE:
//			case uml::PseudostateKind::DEEPHISTORY:
//			case uml::PseudostateKind::SHALLOWHISTORY:
//			case uml::PseudostateKind::JUNCTION:
//		}
	} else if(is_state != nullptr) {
//		if(is_final_state != nullptr){
//			visitor = new PSSM::Semantics::StateMachines::FinalStateActivation();
//		} else {
//			visitor = new PSSM::Semantics::StateMachines::StateActivation();
//		}
	} else if (is_transition != nullptr) {
		std::shared_ptr<uml::Transition> transition = is_transition;
//		switch(transition->getKind()){
//			case uml::TransitionKind::EXTERNAL:
//			case uml::TransitionKind::INTERNAL:
//			case uml::TransitionKind::LOCAL:
//		}
	} else if(is_region != nullptr) {
		//visitor = new PSSM::Semantics::StateMachines::RegionActivation();
	} else if(is_opaque_expression != nullptr) {
		//visitor = new PSSM::Semantics::Values::SM_OpaqueExpressionEvaluation();
	} else if(is_read_self_action) {
		//visitor = new PSSM::Semantics::Actions::SM_ReadSelfActionActivation();
	} else {
		visitor = this->instantiateVisitor(element);
	}

	return visitor;
//SemanticVisitor visitor = null ;
//if(element instanceof StateMachine){
//	visitor = new StateMachineExecution();
//}else if (element instanceof Pseudostate) {
//	Pseudostate pseudostate = (Pseudostate) element;
//	switch(pseudostate.getKind()){
//		case INITIAL_LITERAL: visitor = new InitialPseudostateActivation(); break;
//		case ENTRY_POINT_LITERAL: visitor = new EntryPointPseudostateActivation(); break;
//		case EXIT_POINT_LITERAL: visitor = new ExitPointPseudostateActivation(); break;
//		case CHOICE_LITERAL: visitor = new ChoicePseudostateActivation(); break;
//		case FORK_LITERAL: visitor = new ForkPseudostateActivation(); break;
//		case JOIN_LITERAL: visitor = new JoinPseudostateActivation(); break;
//		case TERMINATE_LITERAL: visitor = new TerminatePseudostateActivation(); break;
//		case DEEP_HISTORY_LITERAL: visitor = new DeepHistoryPseudostateActivation(); break;
//		case SHALLOW_HISTORY_LITERAL: visitor = new ShallowHistoryPseudostateActivation(); break;
//		case JUNCTION_LITERAL: visitor = new JunctionPseudostateActivation(); break;
//	}
//}else if (element instanceof State) {
//	if(element instanceof FinalState){
//		visitor = new FinalStateActivation();
//	}else{
//		visitor = new StateActivation() ;
//	}
//}else if (element instanceof Transition) {
//	Transition transition = (Transition) element;
//	switch(transition.getKind()){
//		case EXTERNAL_LITERAL: visitor = new ExternalTransitionActivation(); break;
//		case INTERNAL_LITERAL: visitor = new InternalTransitionActivation(); break;
//		case LOCAL_LITERAL: visitor = new LocalTransitionActivation(); break;
//	}
//}else if (element instanceof Region) {
//	visitor = new RegionActivation();
//}else if(element instanceof OpaqueExpression) {
//	visitor = new SM_OpaqueExpressionEvaluation();
//}else if(element instanceof ReadSelfAction){
//	visitor = new SM_ReadSelfActionActivation();
//}else {
//	visitor = super.instantiateVisitor(element);
//}
//return visitor;
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
std::shared_ptr<ecore::EObject> SM_ExecutionFactoryImpl::eContainer() const
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
void SM_ExecutionFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSSMFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void SM_ExecutionFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::ExecutionFactoryImpl::loadAttributes(loadHandler, attr_list);
}

void SM_ExecutionFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::ExecutionFactoryImpl::loadNode(nodeName, loadHandler);
}

void SM_ExecutionFactoryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	fUML::Semantics::Loci::ExecutionFactoryImpl::resolveReferences(featureID, references);
}

void SM_ExecutionFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::ExecutionFactoryImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SM_ExecutionFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::Loci::LociPackage> package = PSSM::Semantics::Loci::LociPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SM_ExecutionFactoryImpl::eStaticClass() const
{
	return PSSM::Semantics::Loci::LociPackage::eInstance()->getSM_ExecutionFactory_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SM_ExecutionFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::ExecutionFactoryImpl::eGet(featureID, resolve, coreType);
}

bool SM_ExecutionFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::ExecutionFactoryImpl::internalEIsSet(featureID);
}

bool SM_ExecutionFactoryImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::ExecutionFactoryImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SM_ExecutionFactoryImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::Loci::SM_ExecutionFactory::instantiateVisitor(uml::Element) : fUML::Semantics::Loci::SemanticVisitor: 3011345813
		case LociPackage::SM_EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_element;
			Bag<Any>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_element_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_element = std::dynamic_pointer_cast<uml::Element>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'element'. Failed to invoke operation 'instantiateVisitor'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'element'. Failed to invoke operation 'instantiateVisitor'!")
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->instantiateVisitor(incoming_param_element), fUML::Semantics::Loci::LociPackage::SEMANTICVISITOR_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::ExecutionFactoryImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::Loci::SM_ExecutionFactory> SM_ExecutionFactoryImpl::getThisSM_ExecutionFactoryPtr() const
{
	return m_thisSM_ExecutionFactoryPtr.lock();
}
void SM_ExecutionFactoryImpl::setThisSM_ExecutionFactoryPtr(std::weak_ptr<PSSM::Semantics::Loci::SM_ExecutionFactory> thisSM_ExecutionFactoryPtr)
{
	m_thisSM_ExecutionFactoryPtr = thisSM_ExecutionFactoryPtr;
	setThisExecutionFactoryPtr(thisSM_ExecutionFactoryPtr);
}


