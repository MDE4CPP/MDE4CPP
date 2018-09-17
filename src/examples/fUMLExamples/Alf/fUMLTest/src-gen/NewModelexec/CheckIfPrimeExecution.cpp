
#include "CheckIfPrimeExecution.hpp"

#include "QDebug"


 
using namespace NewModel;

CheckIfPrimeExecution::CheckIfPrimeExecution(CheckIfPrime* _element):m_umlValue(_element)
{

}


CheckIfPrimeExecution::CheckIfPrimeExecution(CheckIfPrimeExecution &obj)
:ObjectImpl(obj)
{
    
}

CheckIfPrimeExecution::CheckIfPrimeExecution()
{
    
}

CheckIfPrimeExecution::~CheckIfPrimeExecution()
{
    
}

ecore::EObject *  CheckIfPrimeExecution::copy()
{
    return new CheckIfPrimeExecution(*this);
}

CheckIfPrime* CheckIfPrimeExecution::getUmlValue()
{
	return m_umlValue;
}

void CheckIfPrimeExecution::setUmlValue(CheckIfPrime* _element)
{
	m_umlValue=_element;
}

