#include "CalcModelExec/PrimeCheckerObject.hpp"

#include "abstractDataTypes/Bag.hpp"
#include "CalcModel/PrimeChecker.hpp"

using namespace CalcModel;

PrimeCheckerObject::PrimeCheckerObject(std::shared_ptr<PrimeChecker> _element):
	m_umlValue(_element),
	m_umlValues(nullptr)
{
}

PrimeCheckerObject::PrimeCheckerObject(std::shared_ptr<Bag<PrimeChecker>> _element):
	m_umlValue(nullptr),
	m_umlValues(_element)
{
}

PrimeCheckerObject::PrimeCheckerObject(PrimeCheckerObject &obj):
	ObjectImpl(obj)
{
}

PrimeCheckerObject::PrimeCheckerObject()
{
}

PrimeCheckerObject::~PrimeCheckerObject()
{
}

std::shared_ptr<ecore::EObject> PrimeCheckerObject::copy()
{
	std::shared_ptr<PrimeCheckerObject> element(new PrimeCheckerObject(*this));
	element->setThisPrimeCheckerObjectPtr(element);
	return element;
}

std::shared_ptr<PrimeChecker> PrimeCheckerObject::getUmlValue() const
{
	return m_umlValue;
}

std::shared_ptr<Bag<PrimeChecker>> PrimeCheckerObject::getUmlValues() const
{
	return m_umlValues;
}

void PrimeCheckerObject::setUmlValue(std::shared_ptr<PrimeChecker> _element)
{
	m_umlValue = _element;
}

void PrimeCheckerObject::setUmlValues(std::shared_ptr<Bag<PrimeChecker>> _element)
{
	m_umlValues = _element;
}

void PrimeCheckerObject::setThisPrimeCheckerObjectPtr(std::weak_ptr<PrimeCheckerObject> thisObjectPtr)
{
	setThisObjectPtr(thisObjectPtr);
}
