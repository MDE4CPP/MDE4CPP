#include "fUMLMultiplePinsExec/TestClassObject.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "fUMLMultiplePins/TestClass.hpp"

using namespace fUMLMultiplePins;

TestClassObject::TestClassObject(std::shared_ptr<TestClass> _element):
	m_umlValue(_element),
	m_umlValues(nullptr)
{
}

TestClassObject::TestClassObject(std::shared_ptr<Bag<TestClass>> _element):
	m_umlValue(nullptr),
	m_umlValues(_element)
{
}

TestClassObject::TestClassObject(TestClassObject &obj):
	ObjectImpl(obj)
{
}

TestClassObject::TestClassObject()
{
}

TestClassObject::~TestClassObject()
{
}

std::shared_ptr<ecore::EObject> TestClassObject::copy()
{
	std::shared_ptr<TestClassObject> element(new TestClassObject(*this));
	element->setThisTestClassObjectPtr(element);
	return element;
}

std::shared_ptr<TestClass> TestClassObject::getUmlValue() const
{
	return m_umlValue;
}

std::shared_ptr<Bag<TestClass>> TestClassObject::getUmlValues() const
{
	return m_umlValues;
}

void TestClassObject::setUmlValue(std::shared_ptr<TestClass> _element)
{
	m_umlValue = _element;
}

void TestClassObject::setUmlValues(std::shared_ptr<Bag<TestClass>> _element)
{
	m_umlValues = _element;
}

void TestClassObject::setThisTestClassObjectPtr(std::weak_ptr<TestClassObject> thisObjectPtr)
{
	setThisObjectPtr(thisObjectPtr);
}
