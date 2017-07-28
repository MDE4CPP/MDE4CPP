#include "LinkImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "uml/Property.hpp"
#include "uml/Association.hpp"

//Forward declaration includes
#include "Association.hpp";

#include "Classifier.hpp";

#include "ExtensionalValue.hpp";

#include "FeatureValue.hpp";

#include "Locus.hpp";

#include "Property.hpp";


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
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif


}

ecore::EObject *  LinkImpl::copy() const
{
	return new LinkImpl(*this);
}

std::shared_ptr<ecore::EClass> LinkImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLink();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 LinkImpl::addTo(std::shared_ptr<fUML::Locus>  locus) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::FeatureValue> >
 LinkImpl::getOtherFeatureValues(std::shared_ptr<Bag<fUML::ExtensionalValue> >  extent,std::shared_ptr<uml::Property>  end) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> >
 LinkImpl::getTypes() 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());

	if( this->getType() != nullptr)
	{
		types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
	}
    return types;
}

bool
 LinkImpl::isMatchingLink(std::shared_ptr<fUML::ExtensionalValue>  link,std::shared_ptr<uml::Property>  end) 
{
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LinkImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //320
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //321
		case FUMLPackage::LINK_TYPE:
			return getType(); //322
	}
	return boost::any();
}
