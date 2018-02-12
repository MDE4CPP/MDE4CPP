#include "fUML/impl/PrimitiveValueImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/PrimitiveType.hpp"

#include "fUML/Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
PrimitiveValueImpl::PrimitiveValueImpl()
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

PrimitiveValueImpl::~PrimitiveValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrimitiveValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




PrimitiveValueImpl::PrimitiveValueImpl(const PrimitiveValueImpl & obj):PrimitiveValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrimitiveValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  PrimitiveValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new PrimitiveValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> PrimitiveValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getPrimitiveValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Classifier> > PrimitiveValueImpl::getTypes() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
	std::shared_ptr<uml::PrimitiveType> type = this->getType();
	if (type != nullptr)
	{
		types->push_back(std::dynamic_pointer_cast<uml::Classifier>(type));
	}
    return types;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::PrimitiveType > PrimitiveValueImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void PrimitiveValueImpl::setType(std::shared_ptr<uml::PrimitiveType> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> PrimitiveValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PrimitiveValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_EREFERENCE_TYPE:
			return getType(); //150
	}
	return boost::any();
}

void PrimitiveValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::PrimitiveType> _type = boost::any_cast<std::shared_ptr<uml::PrimitiveType>>(newValue);
			setType(_type); //150
			break;
		}
	}
}
