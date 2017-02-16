#include "LinkImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "uml/Property.hpp"
#include "uml/Association.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LinkImpl::LinkImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

LinkImpl::~LinkImpl()
{
	
}

LinkImpl::LinkImpl(const LinkImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	m_type  = obj.getType();


	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
}

ecore::EObject *  LinkImpl::copy() const
{
	return new LinkImpl(*this);
}

ecore::EClass* LinkImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLink();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void LinkImpl::addTo(fUML::Locus *  locus) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<fUML::FeatureValue * > *  LinkImpl::getOtherFeatureValues(std::vector<fUML::ExtensionalValue * > *  extent,uml::Property *  end) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Classifier * > *  LinkImpl::getTypes() 
{
	//generated from body annotation
	std::vector< uml::Classifier * > * types = new std::vector< uml::Classifier * >();

if( this->getType() != nullptr){
	types->push_back(dynamic_cast<uml::Classifier * >(this->getType()));
}
    return types;
}

bool LinkImpl::isMatchingLink(fUML::ExtensionalValue *  link,uml::Property *  end) 
{
	//generated from body annotation
			std::vector<uml::Property * > * ends = this->getType()->getMemberEnd();

		bool matches = true;
		unsigned int i = 1;
		while (matches && i <= ends->size()) {
			uml::Property* otherEnd = ends->at(i - 1);
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
uml::Association *  LinkImpl::getType() const
{
	
	return m_type;
}
void LinkImpl::setType(uml::Association *  _type)
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
