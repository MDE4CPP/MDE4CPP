#include "PSCS/Semantics/Actions/impl/CS_DefaultConstructStrategyImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"
#include <stdexcept>

#include "uml/Port.hpp"
#include "uml/TypedElement.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/umlFactory.hpp"
#include "uml/umlPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/Values/CS_OpaqueExpressionEvaluation.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Association.hpp"
#include "PSCS/Semantics/Actions/CS_ConstructStrategy.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "uml/Class.hpp"
#include "uml/Connector.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Interface.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
#include "uml/Property.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_DefaultConstructStrategyImpl::CS_DefaultConstructStrategyImpl()
{	
}

CS_DefaultConstructStrategyImpl::~CS_DefaultConstructStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_DefaultConstructStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_DefaultConstructStrategyImpl::CS_DefaultConstructStrategyImpl(const CS_DefaultConstructStrategyImpl & obj): CS_DefaultConstructStrategyImpl()
{
	*this = obj;
}

CS_DefaultConstructStrategyImpl& CS_DefaultConstructStrategyImpl::operator=(const CS_DefaultConstructStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	CS_ConstructStrategyImpl::operator=(obj);
	CS_DefaultConstructStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_DefaultConstructStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_locus  = obj.getLocus();

	//Clone references with containment (deep copy)
	if(obj.getDefaultAssociation()!=nullptr)
	{
		m_defaultAssociation = std::dynamic_pointer_cast<uml::Association>(obj.getDefaultAssociation()->copy());
	}
	std::shared_ptr<Bag<uml::Class>> generatedRealizingClassesContainer = getGeneratedRealizingClasses();
	for(auto _generatedRealizingClasses : *obj.getGeneratedRealizingClasses()) 
	{
		generatedRealizingClassesContainer->push_back(std::dynamic_pointer_cast<uml::Class>(_generatedRealizingClasses->copy()));
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> CS_DefaultConstructStrategyImpl::copy() const
{
	std::shared_ptr<CS_DefaultConstructStrategyImpl> element(new CS_DefaultConstructStrategyImpl());
	*element =(*this);
	element->setThisCS_DefaultConstructStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_DefaultConstructStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_DefaultConstructStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_DefaultConstructStrategyImpl::addStructuralFeatureValue(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<uml::Property> feature,std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = context->retrieveFeatureValue(feature);
	if(featureValue != nullptr) {
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values = featureValue->getValues();

		/*
		 * MDE4CPP-specific implementation: Since specialized references (i.e. CS_References vs. CS_InteractionPoints) are handled on a lower level,
		 * it is sufficient to just insert a CS_Reference at this point.
		 */
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
		reference->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value));
		reference->setReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value));
		values->add(reference);
		context->assignFeatureValue(feature, values, -1);

		/*ORIGINAL IMPLEMENTATION
		if(std::dynamic_pointer_cast<uml::Port>(feature) != nullptr)
		{
			// insert an interaction point
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_InteractionPoint();
			interactionPoint->setDefiningPort(std::dynamic_pointer_cast<uml::Port>(feature));
			interactionPoint->setReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value));
			interactionPoint->setOwner(context);
			values->add(interactionPoint);
		}
		else if (std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value) != nullptr)
		{
			// insert a reference
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			reference->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value));
			reference->setReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value));
			values->add(reference);
		}
		else
		{
			values->add(value);
		}
		*/
	}
	//end of body
}

bool CS_DefaultConstructStrategyImpl::canInstantiate(std::shared_ptr<uml::Property> p)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Instantiate is possible if:
	// - p is composite
	// - p is typed
	// - This type is a Class and it is not abstract
	// - Or p is a Port and the type is an Interface

	if(p->isComposite()) {
		if(std::dynamic_pointer_cast<uml::TypedElement>(p) != nullptr) {
			if(p->getType() != nullptr) {
				if(std::dynamic_pointer_cast<uml::Class>(p->getType()) != nullptr) {
					return !((std::dynamic_pointer_cast<uml::Class>(p->getType()))->getIsAbstract());
				}
			}
			else if(std::dynamic_pointer_cast<uml::Interface>(p->getType()) != nullptr) {
					return ((std::dynamic_pointer_cast<uml::Port>(p)) != nullptr);
			}
		}
	}
	return false;
	//end of body
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_DefaultConstructStrategyImpl::construct(std::shared_ptr<uml::Operation> constructor,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> context)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		this->setLocus(context->getLocus());
	return this->constructObject(context, std::dynamic_pointer_cast<uml::Class>(constructor->getType()));
	//end of body
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_DefaultConstructStrategyImpl::constructObject(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> context,std::shared_ptr<uml::Class> type)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> referenceToContext = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
	referenceToContext->setReferent(context);
	referenceToContext->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(context));
	// FIXME detect infinite recursive instantiation
	std::shared_ptr<Bag<uml::Property>> allAttributes = type->getAttribute();
	unsigned int i = 1;
	// Instantiate ports and parts
	while(i <= allAttributes->size()) {
		std::shared_ptr<uml::Property> p = allAttributes->at(i-1);
		if(p->getDefaultValue() != nullptr) {
			std::shared_ptr<uml::ValueSpecification> defaultValueSpecification = p->getDefaultValue();
			std::shared_ptr<fUML::Semantics::Values::Evaluation> evaluation = std::dynamic_pointer_cast<fUML::Semantics::Values::Evaluation>(context->getLocus()->getFactory()->instantiateVisitor(defaultValueSpecification));
			evaluation->setSpecification(defaultValueSpecification);
			evaluation->setLocus(context->getLocus());
			if(std::dynamic_pointer_cast<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation>(evaluation) != nullptr) {
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> evaluations = (std::dynamic_pointer_cast<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation>(evaluation))->executeExpressionBehavior();
				for(unsigned int j = 0; j < evaluations->size(); j++) {
					this->addStructuralFeatureValue(referenceToContext, p, evaluations->at(j));
				}
			}
			else {
				std::shared_ptr<fUML::Semantics::Values::Value> defaultValue = evaluation->evaluate();
				this->addStructuralFeatureValue(referenceToContext, p, defaultValue);
			}
		}
		else if (this->canInstantiate(p)) {
			int j = 1;
			while(j <= p->getLower()){
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> value;
				// if p is a Port typed by an Interface
				// creates an Object without type, but with FeatureValues corresponding to
				// structural features of the interface.
				if((std::dynamic_pointer_cast<uml::Port>(p) != nullptr) && (std::dynamic_pointer_cast<uml::Interface>(p->getType()) != nullptr)) {
					value = this->instantiateInterface(std::dynamic_pointer_cast<uml::Interface>(p->getType()), this->getLocus());
					this->addStructuralFeatureValue(referenceToContext, p, value);
				}
				else {
					value = context->getLocus()->instantiate(std::dynamic_pointer_cast<uml::Class>(p->getType()));
					// TODO account for existing constructors
					value = this->constructObject(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value), std::dynamic_pointer_cast<uml::Class>(p->getType()));
					this->addStructuralFeatureValue(referenceToContext, p, std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(value));
					if((std::dynamic_pointer_cast<uml::Class>(p->getType()))->getIsActive()) {
						std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
						value->startBehavior(std::dynamic_pointer_cast<uml::Class>(p->getType()), parameterValues);
					}
				}
				j += 1;
			}
		}
		i += 1;
	}
	// Instantiate connectors

	/*
	 * MDE4CPP-specific implementation: We can directly access the types owned connectors rather than iterating over all members and
	 * searching for owned connectors.
	 */
	std::shared_ptr<Bag<uml::Connector>> allConnectors = type->getOwnedConnector();
	i = 1;
	unsigned int numberOfConnectors = allConnectors->size();
	while(i <= numberOfConnectors) {
		std::shared_ptr<uml::Connector> connector = allConnectors->at(i-1);
			if(this->isArrayPattern(connector)) {
				this->generateArrayPattern(referenceToContext, connector);
			}
			else if(this->isStarPattern(connector)) {
				this->generateStarPattern(referenceToContext, connector);
			}
		i += 1;
	}

	/*ORIGINAL IMPLEMENTATION
	std::shared_ptr<Bag<uml::NamedElement>> allMembers = type->getMember();
	i = 1;
	while(i <= allMembers->size()) {
		std::shared_ptr<uml::NamedElement> member = allMembers->at(i-1);
		if(std::dynamic_pointer_cast<uml::Connector>(member) != nullptr) {
			std::shared_ptr<uml::Connector> connector = std::dynamic_pointer_cast<uml::Connector>(member);
			if(this->isArrayPattern(connector)) {
				this->generateArrayPattern(referenceToContext, connector);
			}
			else if(this->isStarPattern(connector)) {
				this->generateStarPattern(referenceToContext, connector);
			}
		}
		i += 1;
	}
	 */
	return referenceToContext->getReferent();
	//end of body
}

void CS_DefaultConstructStrategyImpl::generateArrayPattern(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<uml::Connector> connector)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::ConnectorEnd> end1 = connector->getEnd()->at(0);
	std::shared_ptr<uml::ConnectorEnd> end2 = connector->getEnd()->at(1);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> end1Values =
			this->getValuesFromConnectorEnd(context, end1);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> end2Values =
			this->getValuesFromConnectorEnd(context, end2);
	for (unsigned int i = 0; i < end1Values->size(); i++) {
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link =
				PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Link();
		if (connector->getType() == nullptr) {
			link->setType(this->getDefaultAssociation());
		} else {
			link->setType(connector->getType());
		}
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesForEnd1(
				new Bag<fUML::Semantics::Values::Value>());
		valuesForEnd1->add(end1Values->at(i));
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesForEnd2(
				new Bag<fUML::Semantics::Values::Value>());
		valuesForEnd2->add(end2Values->at(i));
		link->assignFeatureValue(link->getType()->getMemberEnd()->at(0),
				valuesForEnd1, -1);
		link->assignFeatureValue(link->getType()->getMemberEnd()->at(1),
				valuesForEnd2, -1);
		link->addTo(context->getReferent()->getLocus());
	}
	//end of body
}

std::shared_ptr<uml::Class> CS_DefaultConstructStrategyImpl::generateRealizingClass(std::shared_ptr<uml::Interface> interface_,std::string className)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<uml::Class> realizingClass = uml::umlFactory::eInstance()->createClass();
	realizingClass->setName(className);
	std::shared_ptr<uml::InterfaceRealization> realization = uml::umlFactory::eInstance()->createInterfaceRealization();
	realization->setContract(interface_);
	realization->setImplementingClassifier(realizingClass);
	realizingClass->getInterfaceRealization()->add(realization);
	// TODO Deal with structural features of the interface
	// TODO Make a test case for reading/writing structural features of an interface
	return realizingClass;
	//end of body
}

void CS_DefaultConstructStrategyImpl::generateStarPattern(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<uml::Connector> connector)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ConnectorEnd> end1 = connector->getEnd()->at(0);
	std::shared_ptr<uml::ConnectorEnd> end2 = connector->getEnd()->at(1);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> end1Values =
			this->getValuesFromConnectorEnd(context, end1);
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> end2Values =
			this->getValuesFromConnectorEnd(context, end2);
	for (unsigned int i = 0; i < end1Values->size(); i++) {
		for (unsigned int j = 0; j < end2Values->size(); j++) {
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link =
					PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Link();
			if (connector->getType() == nullptr) {
				link->setType(this->getDefaultAssociation());
			} else {
				link->setType(connector->getType());
			}
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesForEnd1(
					new Bag<fUML::Semantics::Values::Value>());
			valuesForEnd1->add(end1Values->at(i));
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesForEnd2(
					new Bag<fUML::Semantics::Values::Value>());
			valuesForEnd2->add(end2Values->at(j));
			link->assignFeatureValue(link->getType()->getMemberEnd()->at(0),
					valuesForEnd1, -1);
			link->assignFeatureValue(link->getType()->getMemberEnd()->at(1),
					valuesForEnd2, -1);
			link->addTo(context->getReferent()->getLocus());
		}
	}
	//end of body
}

int CS_DefaultConstructStrategyImpl::getCardinality(std::shared_ptr<uml::ConnectorEnd> end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			int lowerOfRole;
	if(std::dynamic_pointer_cast<uml::MultiplicityElement>(end->getRole()) != nullptr){
		lowerOfRole = (std::dynamic_pointer_cast<uml::MultiplicityElement>(end->getRole()))->getLower();
	}
	else {
		std::string errorMessage = "UnexpectedTypeException in PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl::getCardinality(): unexpected type '"
		+ end->getRole()->eClass()->getName() + "' is not an instance of uml::MultiplicityElement\n";
		
		throw std::runtime_error(errorMessage);
	}
	
	if(lowerOfRole == 0) {
		return 0;
	}
	else if (end->getPartWithPort() == nullptr) {
		return lowerOfRole;
	}
	else {
		int lowerOfPart = end->getPartWithPort()->getLower();
		return (lowerOfRole * lowerOfPart);
	}
	//end of body
}

std::shared_ptr<uml::Association> CS_DefaultConstructStrategyImpl::getDefaultAssociation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// Computes an returns an Association with two untyped owned ends,
	// with multiplicity [*].
	// This association can be used to type links instantiated from untyped connec
	
	if(m_defaultAssociation == nullptr) {
		m_defaultAssociation = uml::umlFactory::eInstance()->createAssociation();
		m_defaultAssociation->setName("DefaultGeneratedAssociation");
		std::shared_ptr<uml::Property> end1 = uml::umlFactory::eInstance()->createProperty();
		end1->setName("x");
		end1->setLower(0);
		end1->setUpper(-1);
		end1->setIsOrdered(true);
		end1->setIsUnique(true);
		m_defaultAssociation->getOwnedEnd()->add(end1);
		std::shared_ptr<uml::Property> end2 = uml::umlFactory::eInstance()->createProperty();
		end2->setName("y");
		end2->setLower(0);
		end2->setUpper(-1);
		end2->setIsOrdered(true);
		end2->setIsUnique(true);
		m_defaultAssociation->getOwnedEnd()->add(end2);
	}
	return m_defaultAssociation;
	//end of body
}

std::shared_ptr<uml::Class> CS_DefaultConstructStrategyImpl::getRealizingClass(std::shared_ptr<uml::Interface> interface_)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<uml::Class> realizingClass = nullptr;
	// TODO For cached RealizingClasses, search based on InterfaceRealizations rather than name
	std::string realizingClassName = interface_->getQualifiedName() + "GeneratedRealizingClass";
	unsigned int i = 0;
	while((i <= m_generatedRealizingClasses->size()) && (realizingClass == nullptr)) {
		std::shared_ptr<uml::Class> cddRealizingClass = m_generatedRealizingClasses->at(i-1);
		if(cddRealizingClass->getName() == realizingClassName) {
			realizingClass = cddRealizingClass;
		}
		i += 1;
	}
	if(realizingClass == nullptr) {
		realizingClass = this->generateRealizingClass(interface_, realizingClassName);
		m_generatedRealizingClasses->add(realizingClass);
	}
	return realizingClass;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::Values::Value> > CS_DefaultConstructStrategyImpl::getValuesFromConnectorEnd(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<uml::ConnectorEnd> end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
				std::shared_ptr<Bag<fUML::Semantics::Values::Value>> endValues(new Bag<fUML::Semantics::Values::Value>());
	if(end->getPartWithPort() != nullptr) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> valueForPart = context->retrieveFeatureValue(end->getPartWithPort());
		if(valueForPart != nullptr) {
			for(unsigned int i = 0; i < valueForPart->getValues()->size(); i++) {
				std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Reference>(valueForPart->getValues()->at(i));
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> valueForPort = reference->retrieveFeatureValue(std::dynamic_pointer_cast<uml::Port>(end->getRole()));
				if(valueForPort != nullptr) {
					for(unsigned int j = 0; j < valueForPort->getValues()->size(); j++) {
						endValues->add(valueForPort->getValues()->at(j));
					}
				}
			}
		}
	}
	else {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> valueForRole = context->retrieveFeatureValue(std::dynamic_pointer_cast<uml::Property>(end->getRole()));
		if(valueForRole != nullptr) {
			for (unsigned int i = 0; i < valueForRole->getValues()->size(); i++) {
				endValues->add(valueForRole->getValues()->at(i));
			}
		}
	}
	return endValues;
	//end of body
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> CS_DefaultConstructStrategyImpl::instantiateInterface(std::shared_ptr<uml::Interface> interface,std::shared_ptr<fUML::Semantics::Loci::Locus> locus)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<uml::Class> realizingClass = this->getRealizingClass(interface);
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object = locus->instantiate(realizingClass);
	return object;
	//end of body
}

bool CS_DefaultConstructStrategyImpl::isArrayPattern(std::shared_ptr<uml::Connector> c)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// This is an array pattern if:
	// - c is binary
	// - lower bound of the two connector ends is 1
	// - Cardinality of ends are equals

	if (c->getEnd()->size() == 2) {
		if (std::dynamic_pointer_cast<uml::MultiplicityElement>(
				c->getEnd()->at(0)->getRole()) != nullptr) {
			if (c->getEnd()->at(0)->getLower() == 1) {
				if (std::dynamic_pointer_cast<uml::MultiplicityElement>(
						c->getEnd()->at(1)->getRole()) != nullptr) {
					if (c->getEnd()->at(1)->getLower() == 1) {
						if ((this->canInstantiate(
								std::dynamic_pointer_cast<uml::Property>(
										c->getEnd()->at(0)->getRole())))
								&& (this->canInstantiate(
										std::dynamic_pointer_cast<uml::Property>(
												c->getEnd()->at(1)->getRole())))) {
							int cardinality1 = this->getCardinality(
									c->getEnd()->at(0));
							int cardinality2 = this->getCardinality(
									c->getEnd()->at(1));
							return (cardinality1 == cardinality2);
						}
					}
				} else {
					std::string errorMessage =
							"UnexpectedTypeException in PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl::isArrayPattern(): unexpected type '"
									+ c->getEnd()->at(1)->getRole()->eClass()->getName()
									+ "' is not an instance of uml::MultiplicityElement\n";

					throw std::runtime_error(errorMessage);
				}
			}
		} else {
			std::string errorMessage =
					"UnexpectedTypeException in PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl::isArrayPattern(): unexpected type '"
							+ c->getEnd()->at(0)->getRole()->eClass()->getName()
							+ "' is not an instance of uml::MultiplicityElement\n";

			throw std::runtime_error(errorMessage);
		}
	}
	return false;
	//end of body
}

bool CS_DefaultConstructStrategyImpl::isStarPattern(std::shared_ptr<uml::Connector> c)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// This is a star pattern if:
	// - c is binary
	// - lower bound of end1 equals cardinality of end1
	// - lower bound of end2 equals cardinality of end2	

	 if(c->getEnd()->size() == 2) {
		if(std::dynamic_pointer_cast<uml::MultiplicityElement>(c->getEnd()->at(0)->getRole())) {
			if(std::dynamic_pointer_cast<uml::MultiplicityElement>(c->getEnd()->at(1)->getRole())) {
				if((this->canInstantiate(std::dynamic_pointer_cast<uml::Property>(c->getEnd()->at(0)->getRole()))) && (this->canInstantiate(std::dynamic_pointer_cast<uml::Property>(c->getEnd()->at(1)->getRole())))) {
					int cardinalityOfEnd1 = this->getCardinality(c->getEnd()->at(0));
					int lowerBoundofEnd1 = std::dynamic_pointer_cast<uml::MultiplicityElement>(c->getEnd()->at(0)->getRole())->getLower();
					if (cardinalityOfEnd1 == lowerBoundofEnd1) {
						int cardinalityOfEnd2 = this->getCardinality(c->getEnd()->at(1));
						int lowerBoundofEnd2 = std::dynamic_pointer_cast<uml::MultiplicityElement>(c->getEnd()->at(1)->getRole())->getLower();
						return (cardinalityOfEnd2 == lowerBoundofEnd2);
						}
					}
				}
			else {
				std::string errorMessage = "UnexpectedTypeException in PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl::isStarPattern(): unexpected type '"
				+ c->getEnd()->at(1)->getRole()->eClass()->getName() + "' is not an instance of uml::MultiplicityElement\n";
		
				throw std::runtime_error(errorMessage);
				}
			}
		else {
			std::string errorMessage = "UnexpectedTypeException in PSCS::Semantics::Actions::CS_DefaultConstructStrategyImpl::isStarPattern(): unexpected type '"
			+ c->getEnd()->at(0)->getRole()->eClass()->getName() + "' is not an instance of uml::MultiplicityElement\n";
		
			throw std::runtime_error(errorMessage);
			}
		}
	return false;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference defaultAssociation
*/
std::shared_ptr<uml::Association> CS_DefaultConstructStrategyImpl::getDefaultAssociation() const
{
//assert(m_defaultAssociation);
    return m_defaultAssociation;
}
void CS_DefaultConstructStrategyImpl::setDefaultAssociation(std::shared_ptr<uml::Association> _defaultAssociation)
{
    m_defaultAssociation = _defaultAssociation;
}


/*
Getter & Setter for reference generatedRealizingClasses
*/
std::shared_ptr<Bag<uml::Class>> CS_DefaultConstructStrategyImpl::getGeneratedRealizingClasses() const
{
	if(m_generatedRealizingClasses == nullptr)
	{
		m_generatedRealizingClasses.reset(new Bag<uml::Class>());
		
		
	}

    return m_generatedRealizingClasses;
}



/*
Getter & Setter for reference locus
*/
std::shared_ptr<fUML::Semantics::Loci::Locus> CS_DefaultConstructStrategyImpl::getLocus() const
{
//assert(m_locus);
    return m_locus;
}
void CS_DefaultConstructStrategyImpl::setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_DefaultConstructStrategy> CS_DefaultConstructStrategyImpl::getThisCS_DefaultConstructStrategyPtr() const
{
	return m_thisCS_DefaultConstructStrategyPtr.lock();
}
void CS_DefaultConstructStrategyImpl::setThisCS_DefaultConstructStrategyPtr(std::weak_ptr<CS_DefaultConstructStrategy> thisCS_DefaultConstructStrategyPtr)
{
	m_thisCS_DefaultConstructStrategyPtr = thisCS_DefaultConstructStrategyPtr;
	setThisCS_ConstructStrategyPtr(thisCS_DefaultConstructStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_DefaultConstructStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_DefaultConstructStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION:
			return eAny(getDefaultAssociation()); //101
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES:
		{
			return eAny(getGeneratedRealizingClasses()); //102			
		}
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
			return eAny(getLocus()); //100
	}
	return CS_ConstructStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_DefaultConstructStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION:
			return getDefaultAssociation() != nullptr; //101
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES:
			return getGeneratedRealizingClasses() != nullptr; //102
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //100
	}
	return CS_ConstructStrategyImpl::internalEIsSet(featureID);
}
bool CS_DefaultConstructStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _defaultAssociation = std::dynamic_pointer_cast<uml::Association>(_temp);
			setDefaultAssociation(_defaultAssociation); //101
			return true;
		}
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Class>> generatedRealizingClassesList(new Bag<uml::Class>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generatedRealizingClassesList->add(std::dynamic_pointer_cast<uml::Class>(*iter));
				iter++;
			}
			
			Bag<uml::Class>::iterator iterGeneratedRealizingClasses = m_generatedRealizingClasses->begin();
			Bag<uml::Class>::iterator endGeneratedRealizingClasses = m_generatedRealizingClasses->end();
			while (iterGeneratedRealizingClasses != endGeneratedRealizingClasses)
			{
				if (generatedRealizingClassesList->find(*iterGeneratedRealizingClasses) == -1)
				{
					m_generatedRealizingClasses->erase(*iterGeneratedRealizingClasses);
				}
				iterGeneratedRealizingClasses++;
			}
 
			iterGeneratedRealizingClasses = generatedRealizingClassesList->begin();
			endGeneratedRealizingClasses = generatedRealizingClassesList->end();
			while (iterGeneratedRealizingClasses != endGeneratedRealizingClasses)
			{
				if (m_generatedRealizingClasses->find(*iterGeneratedRealizingClasses) == -1)
				{
					m_generatedRealizingClasses->add(*iterGeneratedRealizingClasses);
				}
				iterGeneratedRealizingClasses++;			
			}
			return true;
		}
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(_temp);
			setLocus(_locus); //100
			return true;
		}
	}

	return CS_ConstructStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_DefaultConstructStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_DefaultConstructStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("locus");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("locus")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CS_ConstructStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_DefaultConstructStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("defaultAssociation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Association";
			}
			loadHandler->handleChild(this->getDefaultAssociation()); 

			return; 
		}

		if ( nodeName.compare("generatedRealizingClasses") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Class";
			}
			loadHandler->handleChildContainer<uml::Class>(this->getGeneratedRealizingClasses());  

			return; 
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
	//load BasePackage Nodes
	CS_ConstructStrategyImpl::loadNode(nodeName, loadHandler);
}

void CS_DefaultConstructStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::Actions::ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}
	}
	CS_ConstructStrategyImpl::resolveReferences(featureID, references);
}

void CS_DefaultConstructStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CS_ConstructStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void CS_DefaultConstructStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> package = PSCS::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getLocus(), "locus", getLocus()->eClass() != fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'defaultAssociation'

		saveHandler->addReference(this->getDefaultAssociation(), "defaultAssociation", getDefaultAssociation()->eClass() != uml::umlPackage::eInstance()->getAssociation_Class());

		// Save 'generatedRealizingClasses'

		saveHandler->addReferences<uml::Class>("generatedRealizingClasses", this->getGeneratedRealizingClasses());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

