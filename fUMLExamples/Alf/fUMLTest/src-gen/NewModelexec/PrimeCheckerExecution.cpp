
#include "PrimeCheckerExecution.hpp"

#include "QDebug"


 
using namespace NewModel;

PrimeCheckerExecution::PrimeCheckerExecution(PrimeChecker* _element):m_umlValue(_element)
{

}


PrimeCheckerExecution::PrimeCheckerExecution(PrimeCheckerExecution &obj)
:ObjectImpl(obj)
{
    
}

PrimeCheckerExecution::PrimeCheckerExecution()
{
    
}

PrimeCheckerExecution::~PrimeCheckerExecution()
{
    
}

ecore::EObject *  PrimeCheckerExecution::copy()
{
    return new PrimeCheckerExecution(*this);
}

PrimeChecker* PrimeCheckerExecution::getUmlValue()
{
	return m_umlValue;
}

void PrimeCheckerExecution::setUmlValue(PrimeChecker* _element)
{
	m_umlValue=_element;
}

