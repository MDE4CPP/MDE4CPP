#include "ImageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ImageImpl::ImageImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ImageImpl::~ImageImpl()
{
	
}

ImageImpl::ImageImpl(const ImageImpl & obj)
{
	//create copy of all Attributes
	m_content = obj.getContent();
	m_format = obj.getFormat();
	m_location = obj.getLocation();

	//copy references with now containment
	
	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  ImageImpl::copy() const
{
	return new ImageImpl(*this);
}

ecore::EClass* ImageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getImage();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ImageImpl::setContent (std::string _content)
{
	m_content = _content;
} 

std::string ImageImpl::getContent() const 
{
	return m_content;
}

void ImageImpl::setFormat (std::string _format)
{
	m_format = _format;
} 

std::string ImageImpl::getFormat() const 
{
	return m_format;
}

void ImageImpl::setLocation (std::string _location)
{
	m_location = _location;
} 

std::string ImageImpl::getLocation() const 
{
	return m_location;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ImageImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ImageImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::IMAGE_CONTENT:
			return getContent(); //114
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //110
		case UmlPackage::IMAGE_FORMAT:
			return getFormat(); //115
		case UmlPackage::IMAGE_LOCATION:
			return getLocation(); //116
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //111
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //112
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //113
	}
	return boost::any();
}
