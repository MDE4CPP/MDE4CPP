#include "MainActivityExecution.hpp"
#include <iostream>

using namespace CalcModel;

MainActivityExecution::MainActivityExecution(std::shared_ptr<MainActivity* _element>):
	m_umlValue(_element)
{
}

MainActivityExecution::MainActivityExecution(MainActivityExecution &obj):
	ObjectImpl(obj)
{
}

MainActivityExecution::MainActivityExecution()
{
}

MainActivityExecution::~MainActivityExecution()
{
}

ecore::EObject* MainActivityExecution::copy()
{
	return new MainActivityExecution(*this);
}

std::shared_ptr<MainActivity> MainActivityExecution::getUmlValue() const
{
	return m_umlValue;
}

void MainActivityExecution::setUmlValue(std::shared_ptr<MainActivity> _element)
{
	m_umlValue = _element;
}
