#include "PSCS/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSCS::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_cS_EventOccurrence_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCS_EventOccurrenceContent();

	initializePackageEDataTypes();

}

void CommonBehaviorPackageImpl::initializeCS_EventOccurrenceContent()
{
	m_cS_EventOccurrence_Class->setName("CS_EventOccurrence");
	m_cS_EventOccurrence_Class->setAbstract(false);
	m_cS_EventOccurrence_Class->setInterface(false);
	
	m_cS_EventOccurrence_Class->_setID(CS_EVENTOCCURRENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_cS_EventOccurrence_Attribute_propagationInward = getCS_EventOccurrence_Attribute_propagationInward();
	m_cS_EventOccurrence_Attribute_propagationInward->setName("propagationInward");
	m_cS_EventOccurrence_Attribute_propagationInward->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_cS_EventOccurrence_Attribute_propagationInward->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_propagationInward->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_propagationInward->setTransient(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setVolatile(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setChangeable(true);
	m_cS_EventOccurrence_Attribute_propagationInward->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setUnique(true);
	m_cS_EventOccurrence_Attribute_propagationInward->setDerived(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setOrdered(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setID(false);
	m_cS_EventOccurrence_Attribute_propagationInward->setDefaultValueLiteral("");
	
	m_cS_EventOccurrence_Attribute_propagationInward->_setID(CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD);
	
	/*
	 * EReferences
	 */
	m_cS_EventOccurrence_Attribute_onPort->setName("onPort");
	m_cS_EventOccurrence_Attribute_onPort->setEType(uml::umlPackage::eInstance()->getPort_Class());
	m_cS_EventOccurrence_Attribute_onPort->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_onPort->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_onPort->setTransient(false);
	m_cS_EventOccurrence_Attribute_onPort->setVolatile(false);
	m_cS_EventOccurrence_Attribute_onPort->setChangeable(true);
	m_cS_EventOccurrence_Attribute_onPort->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_onPort->setUnique(true);
	m_cS_EventOccurrence_Attribute_onPort->setDerived(false);
	m_cS_EventOccurrence_Attribute_onPort->setOrdered(false);
	m_cS_EventOccurrence_Attribute_onPort->setContainment(false);
	m_cS_EventOccurrence_Attribute_onPort->setResolveProxies(true);
	m_cS_EventOccurrence_Attribute_onPort->setDefaultValueLiteral("");	
	
	m_cS_EventOccurrence_Attribute_onPort->_setID(CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setName("wrappedEventOccurrence");
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setLowerBound(0);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUpperBound(1);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setTransient(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setVolatile(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setChangeable(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUnsettable(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setUnique(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setDerived(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setOrdered(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setContainment(false);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setResolveProxies(true);
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->setDefaultValueLiteral("");	
	
	m_cS_EventOccurrence_Attribute_wrappedEventOccurrence->_setID(CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE);
	
	/*
	 * EOperations
	 */
	
}

void CommonBehaviorPackageImpl::initializePackageEDataTypes()
{
	
}

