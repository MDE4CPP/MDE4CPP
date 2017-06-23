#include "PrimitiveValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "PrimitiveType.hpp"
#include "Classifier.hpp"

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
	
}

PrimitiveValueImpl::~PrimitiveValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrimitiveValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

PrimitiveValueImpl::PrimitiveValueImpl(const PrimitiveValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
}

ecore::EObject *  PrimitiveValueImpl::copy() const
{
	return new PrimitiveValueImpl(*this);
}

std::shared_ptr<ecore::EClass> PrimitiveValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getPrimitiveValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Classifier> >
 PrimitiveValueImpl::getTypes() 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
	std::shared_ptr<uml::PrimitiveType> type = this->getType();
	if (type != nullptr)
	{
		types->push_back(std::dynamic_pointer_cast<uml::Classifier>(type));
	}
    return types;
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PrimitiveValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::PRIMITIVEVALUE_TYPE:
			return getType(); //150
	}
	return boost::any();
}
