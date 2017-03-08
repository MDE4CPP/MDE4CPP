#include "CalculatorExecution.hpp"
#include <iostream>

using namespace CalcModel;

CalculatorExecution::CalculatorExecution(std::shared_ptr<Calculator* _element>):
	m_umlValue(_element)
{
}

CalculatorExecution::CalculatorExecution(CalculatorExecution &obj):
	ObjectImpl(obj)
{
}

CalculatorExecution::CalculatorExecution()
{
}

CalculatorExecution::~CalculatorExecution()
{
}

ecore::EObject* CalculatorExecution::copy()
{
	return new CalculatorExecution(*this);
}

std::shared_ptr<Calculator> CalculatorExecution::getUmlValue() const
{
	return m_umlValue;
}

void CalculatorExecution::setUmlValue(std::shared_ptr<Calculator> _element)
{
	m_umlValue = _element;
}
