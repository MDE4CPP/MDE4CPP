#include "CheckIfPrimeExecution.hpp"
#include <iostream>
#include <memory>

using namespace CalcModel;

CheckIfPrimeExecution::CheckIfPrimeExecution(std::shared_ptr<CheckIfPrime> _element):
	m_umlValue(_element)
{
}

CheckIfPrimeExecution::CheckIfPrimeExecution(CheckIfPrimeExecution &obj):
	ObjectImpl(obj)
{
}

CheckIfPrimeExecution::CheckIfPrimeExecution()
{
}

CheckIfPrimeExecution::~CheckIfPrimeExecution()
{
}

ecore::EObject* CheckIfPrimeExecution::copy()
{
	return new CheckIfPrimeExecution(*this);
}

std::shared_ptr<CheckIfPrime> CheckIfPrimeExecution::getUmlValue() const
{
	return m_umlValue;
}

void CheckIfPrimeExecution::setUmlValue(std::shared_ptr<CheckIfPrime> _element)
{
	m_umlValue = _element;
}
