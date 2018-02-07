#include "fUML/impl/AcceptEventActionEventAccepterImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "fUML/AcceptEventActionActivation.hpp"

#include "fUML/EventAccepter.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

AcceptEventActionEventAccepterImpl::~AcceptEventActionEventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionEventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl(const AcceptEventActionEventAccepterImpl & obj):AcceptEventActionEventAccepterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionEventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_actionActivation  = obj.getActionActivation();


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  AcceptEventActionEventAccepterImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new AcceptEventActionEventAccepterImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> AcceptEventActionEventAccepterImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getAcceptEventActionEventAccepter();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<fUML::AcceptEventActionActivation > AcceptEventActionEventAccepterImpl::getActionActivation() const
{
//assert(m_actionActivation);
    return m_actionActivation;
}
void AcceptEventActionEventAccepterImpl::setActionActivation(std::shared_ptr<fUML::AcceptEventActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> AcceptEventActionEventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AcceptEventActionEventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ACTIONACTIVATION:
			return getActionActivation(); //1110
	}
	return boost::any();
}

void AcceptEventActionEventAccepterImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ACTIONACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::AcceptEventActionActivation> _actionActivation = boost::any_cast<std::shared_ptr<fUML::AcceptEventActionActivation>>(newValue);
			setActionActivation(_actionActivation); //1110
			break;
		}
	}
}
