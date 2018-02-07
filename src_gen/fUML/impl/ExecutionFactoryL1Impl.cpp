#include "fUML/impl/ExecutionFactoryL1Impl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/LiteralBoolean.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/LiteralString.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/LiteralReal.hpp"
#include "uml/LiteralNull.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/LiteralUnlimitedNatural.hpp"

//Forward declaration includes
#include "uml/Element.hpp"

#include "fUML/ExecutionFactory.hpp"

#include "fUML/Locus.hpp"

#include "fUML/OpaqueBehaviorExecution.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/SemanticStrategy.hpp"

#include "fUML/SemanticVisitor.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionFactoryL1Impl::ExecutionFactoryL1Impl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ExecutionFactoryL1Impl::~ExecutionFactoryL1Impl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionFactoryL1 "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExecutionFactoryL1Impl::ExecutionFactoryL1Impl(std::weak_ptr<fUML::Locus > par_locus)
			:ExecutionFactoryL1Impl()
			{
			    m_locus = par_locus;
			}






ExecutionFactoryL1Impl::ExecutionFactoryL1Impl(const ExecutionFactoryL1Impl & obj):ExecutionFactoryL1Impl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionFactoryL1 "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::PrimitiveType> > _builtInTypes = obj.getBuiltInTypes();
	m_builtInTypes.reset(new Bag<uml::PrimitiveType>(*(obj.getBuiltInTypes().get())));

	m_locus  = obj.getLocus();

	std::shared_ptr< Bag<fUML::OpaqueBehaviorExecution> > _primitiveBehaviorPrototypes = obj.getPrimitiveBehaviorPrototypes();
	m_primitiveBehaviorPrototypes.reset(new Bag<fUML::OpaqueBehaviorExecution>(*(obj.getPrimitiveBehaviorPrototypes().get())));

	std::shared_ptr< Bag<fUML::SemanticStrategy> > _strategies = obj.getStrategies();
	m_strategies.reset(new Bag<fUML::SemanticStrategy>(*(obj.getStrategies().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ExecutionFactoryL1Impl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExecutionFactoryL1Impl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionFactoryL1Impl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExecutionFactoryL1();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::SemanticVisitor> ExecutionFactoryL1Impl::instantiateVisitor(std::shared_ptr<uml::Element>  element) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<fUML::SemanticVisitor> visitor = nullptr;

    switch (element->eClass()->getClassifierID()) {
		case uml::UmlPackage::LITERALBOOLEAN:
		{
				visitor = FUMLFactory::eInstance()->createLiteralBooleanEvaluation();
				break;
		}

		case uml::UmlPackage::LITERALSTRING:
		{
			visitor = FUMLFactory::eInstance()->createLiteralStringEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALNULL:
		{
			visitor =  FUMLFactory::eInstance()->createLiteralNullEvaluation();
			break;
		}
		case uml::UmlPackage::INSTANCEVALUE:
		{
			visitor = FUMLFactory::eInstance()->createInstanceValueEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALUNLIMITEDNATURAL:
		{
			visitor = FUMLFactory::eInstance()->createLiteralUnlimitedNaturalEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALINTEGER:
		{
			visitor = FUMLFactory::eInstance()->createLiteralIntegerEvaluation();
			break;
		}
		case uml::UmlPackage::LITERALREAL:
		{
			visitor = FUMLFactory::eInstance()->createLiteralRealEvaluation();
			break;
		}
		default:{
            //L3 provides an error message
        }
	}

    return visitor;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> ExecutionFactoryL1Impl::eContainer() const
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
boost::any ExecutionFactoryL1Impl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_BUILTINTYPES:
			return getBuiltInTypes(); //73
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
			return getLocus(); //70
		case FUMLPackage::EXECUTIONFACTORY_PRIMITIVEBEHAVIORPROTOTYPES:
			return getPrimitiveBehaviorPrototypes(); //72
		case FUMLPackage::EXECUTIONFACTORY_STRATEGIES:
			return getStrategies(); //71
	}
	return boost::any();
}

void ExecutionFactoryL1Impl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTIONFACTORY_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //70
			break;
		}
	}
}
