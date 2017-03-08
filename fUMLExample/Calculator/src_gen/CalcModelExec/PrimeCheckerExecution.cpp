#include "PrimeCheckerExecution.hpp"
#include <iostream>

using namespace CalcModel;

PrimeCheckerExecution::PrimeCheckerExecution(std::shared_ptr<PrimeChecker> _element):
	m_umlValue(_element)
{
}

PrimeCheckerExecution::PrimeCheckerExecution(PrimeCheckerExecution &obj):
	ObjectImpl(obj)
{
}

PrimeCheckerExecution::PrimeCheckerExecution()
{
}

PrimeCheckerExecution::~PrimeCheckerExecution()
{
}

ecore::EObject* PrimeCheckerExecution::copy()
{
	return new PrimeCheckerExecution(*this);
}

std::shared_ptr<PrimeChecker> PrimeCheckerExecution::getUmlValue() const
{
	return m_umlValue;
}

void PrimeCheckerExecution::setUmlValue(std::shared_ptr<PrimeChecker> _element)
{
	m_umlValue = _element;
}
