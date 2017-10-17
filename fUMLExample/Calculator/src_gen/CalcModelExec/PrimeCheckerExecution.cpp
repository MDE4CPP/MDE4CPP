#include "PrimeCheckerExecution.hpp"
#include <iostream>
#include <memory>

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

std::shared_ptr<ecore::EObject> PrimeCheckerExecution::copy()
{
	std::shared_ptr<ecore::EObject> element(new PrimeCheckerExecution(*this));
	return element;
}

std::shared_ptr<PrimeChecker> PrimeCheckerExecution::getUmlValue() const
{
	return m_umlValue;
}

void PrimeCheckerExecution::setUmlValue(std::shared_ptr<PrimeChecker> _element)
{
	m_umlValue = _element;
}
