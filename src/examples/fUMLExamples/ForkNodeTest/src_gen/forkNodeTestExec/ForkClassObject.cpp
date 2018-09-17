#include "forkNodeTestExec/ForkClassObject.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "forkNodeTest/ForkClass.hpp"

using namespace forkNodeTest;

ForkClassObject::ForkClassObject(std::shared_ptr<ForkClass> _element):
	m_umlValue(_element),
	m_umlValues(nullptr)
{
}

ForkClassObject::ForkClassObject(std::shared_ptr<Bag<ForkClass>> _element):
	m_umlValue(nullptr),
	m_umlValues(_element)
{
}

ForkClassObject::ForkClassObject(ForkClassObject &obj):
	ObjectImpl(obj)
{
}

ForkClassObject::ForkClassObject()
{
}

ForkClassObject::~ForkClassObject()
{
}

std::shared_ptr<ecore::EObject> ForkClassObject::copy()
{
	std::shared_ptr<ForkClassObject> element(new ForkClassObject(*this));
	element->setThisForkClassObjectPtr(element);
	return element;
}

std::shared_ptr<ForkClass> ForkClassObject::getUmlValue() const
{
	return m_umlValue;
}

std::shared_ptr<Bag<ForkClass>> ForkClassObject::getUmlValues() const
{
	return m_umlValues;
}

void ForkClassObject::setUmlValue(std::shared_ptr<ForkClass> _element)
{
	m_umlValue = _element;
}

void ForkClassObject::setUmlValues(std::shared_ptr<Bag<ForkClass>> _element)
{
	m_umlValues = _element;
}

void ForkClassObject::setThisForkClassObjectPtr(std::weak_ptr<ForkClassObject> thisObjectPtr)
{
	setThisObjectPtr(thisObjectPtr);
}
