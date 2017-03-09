
#include "NewModel activityExecution.hpp"

#include "QDebug"


 
using namespace NewModel;

NewModel activityExecution::NewModel activityExecution(NewModel activity* _element):m_umlValue(_element)
{

}


NewModel activityExecution::NewModel activityExecution(NewModel activityExecution &obj)
:ObjectImpl(obj)
{
    
}

NewModel activityExecution::NewModel activityExecution()
{
    
}

NewModel activityExecution::~NewModel activityExecution()
{
    
}

ecore::EObject *  NewModel activityExecution::copy()
{
    return new NewModel activityExecution(*this);
}

NewModel activity* NewModel activityExecution::getUmlValue()
{
	return m_umlValue;
}

void NewModel activityExecution::setUmlValue(NewModel activity* _element)
{
	m_umlValue=_element;
}

