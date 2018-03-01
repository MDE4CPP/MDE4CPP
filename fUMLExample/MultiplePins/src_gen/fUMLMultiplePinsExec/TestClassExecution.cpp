#include "fUMLMultiplePinsExec/TestClassExecution.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "fUMLMultiplePins/TestClass.hpp"

using namespace fUMLMultiplePins;

TestClassExecution::TestClassExecution(std::shared_ptr<TestClass> _element):
	m_umlValue(_element),
	m_umlValues(nullptr)
{
}

TestClassExecution::TestClassExecution(std::shared_ptr<Bag<TestClass>> _element):
	m_umlValue(nullptr),
	m_umlValues(_element)
{
}

TestClassExecution::TestClassExecution(TestClassExecution &obj):
	ObjectImpl(obj)
{
}

TestClassExecution::TestClassExecution()
{
}

TestClassExecution::~TestClassExecution()
{
}

std::shared_ptr<ecore::EObject> TestClassExecution::copy()
{
	std::shared_ptr<ecore::EObject> element(new TestClassExecution(*this));
	return element;
}

std::shared_ptr<TestClass> TestClassExecution::getUmlValue() const
{
	return m_umlValue;
}

std::shared_ptr<Bag<TestClass>> TestClassExecution::getUmlValues() const
{
	return m_umlValues;
}

void TestClassExecution::setUmlValue(std::shared_ptr<TestClass> _element)
{
	m_umlValue = _element;
}

void TestClassExecution::setUmlValues(std::shared_ptr<Bag<TestClass>> _element)
{
	m_umlValues = _element;
}
