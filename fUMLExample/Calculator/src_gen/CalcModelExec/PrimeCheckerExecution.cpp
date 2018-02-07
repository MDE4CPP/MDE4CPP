#include "CalcModelExec/PrimeCheckerExecution.hpp"
#include <iostream>
#include <memory>

using namespace CalcModel;

PrimeCheckerExecution::PrimeCheckerExecution(std::shared_ptr<PrimeChecker> _element):
	m_umlValue(_element),
	m_umlValues(nullptr)
{
}

PrimeCheckerExecution::PrimeCheckerExecution(std::shared_ptr<Bag<PrimeChecker>> _element):
	m_umlValue(nullptr),
	m_umlValues(_element)
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

std::shared_ptr<Bag<PrimeChecker>> PrimeCheckerExecution::getUmlValues() const
{
	return m_umlValues;
}

void PrimeCheckerExecution::setUmlValue(std::shared_ptr<PrimeChecker> _element)
{
	m_umlValue = _element;
}

void PrimeCheckerExecution::setUmlValues(std::shared_ptr<Bag<PrimeChecker>> _element)
{
	m_umlValues = _element;
}
