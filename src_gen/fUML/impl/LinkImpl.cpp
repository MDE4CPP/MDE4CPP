#include "fUML/impl/LinkImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Property.hpp"
#include "uml/Association.hpp"

//Forward declaration includes
#include "uml/Association.hpp"

#include "uml/Classifier.hpp"

#include "fUML/ExtensionalValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "uml/Property.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LinkImpl::LinkImpl()
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

LinkImpl::~LinkImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Link "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LinkImpl::LinkImpl(const LinkImpl & obj):LinkImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Link "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  LinkImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LinkImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LinkImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLink_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void LinkImpl::addTo(std::shared_ptr<fUML::Locus>  locus) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::FeatureValue> > LinkImpl::getOtherFeatureValues(std::shared_ptr<Bag<fUML::ExtensionalValue> >  extent,std::shared_ptr<uml::Property>  end) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > LinkImpl::getTypes() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());

	if( this->getType() != nullptr)
	{
		types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
	}
    return types;
	//end of body
}

bool LinkImpl::isMatchingLink(std::shared_ptr<fUML::ExtensionalValue>  link,std::shared_ptr<uml::Property>  end) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Property> > ends = this->getType()->getMemberEnd();

	bool matches = true;
	unsigned int i = 0;
	while (matches && i < ends->size()) 
	{
		std::shared_ptr<uml::Property> otherEnd = ends->at(i);
		if (otherEnd != end
				&& !this->retrieveFeatureValue(otherEnd)->getValues()->at(0)
						->equals(
								link->retrieveFeatureValue(otherEnd)->getValues()->at(0))) {
			matches = false;
		}
		i = i + 1;
	}

	return matches;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Association > LinkImpl::getType() const
{

    return m_type;
}
void LinkImpl::setType(std::shared_ptr<uml::Association> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Link> LinkImpl::getThisLinkPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<Link>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> LinkImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LinkImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_EREFERENCE_FEATUREVALUES:
			return getFeatureValues(); //320
		case FUMLPackage::EXTENSIONALVALUE_EREFERENCE_LOCUS:
			return getLocus(); //321
		case FUMLPackage::LINK_EREFERENCE_TYPE:
			return getType(); //322
	}
	return boost::any();
}

void LinkImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXTENSIONALVALUE_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //321
			break;
		}
		case FUMLPackage::LINK_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _type = boost::any_cast<std::shared_ptr<uml::Association>>(newValue);
			setType(_type); //322
			break;
		}
	}
}
