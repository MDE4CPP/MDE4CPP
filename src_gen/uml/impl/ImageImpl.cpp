#include "uml/impl/ImageImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ImageImpl::ImageImpl()
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

ImageImpl::~ImageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Image "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ImageImpl::ImageImpl(std::weak_ptr<uml::Element > par_owner)
			:ImageImpl()
			{
			    m_owner = par_owner;
			}






ImageImpl::ImageImpl(const ImageImpl & obj):ImageImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Image "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_content = obj.getContent();
	m_format = obj.getFormat();
	m_location = obj.getLocation();

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ImageImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ImageImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ImageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getImage();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ImageImpl::setContent(std::string _content)
{
	m_content = _content;
} 

std::string ImageImpl::getContent() const 
{
	return m_content;
}

void ImageImpl::setFormat(std::string _format)
{
	m_format = _format;
} 

std::string ImageImpl::getFormat() const 
{
	return m_format;
}

void ImageImpl::setLocation(std::string _location)
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
std::shared_ptr<Union<uml::Element> > ImageImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<ecore::EObject> ImageImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ImageImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void ImageImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::IMAGE_CONTENT:
		{
			// BOOST CAST
			std::string _content = boost::any_cast<std::string>(newValue);
			setContent(_content); //114
			break;
		}
		case UmlPackage::IMAGE_FORMAT:
		{
			// BOOST CAST
			std::string _format = boost::any_cast<std::string>(newValue);
			setFormat(_format); //115
			break;
		}
		case UmlPackage::IMAGE_LOCATION:
		{
			// BOOST CAST
			std::string _location = boost::any_cast<std::string>(newValue);
			setLocation(_location); //116
			break;
		}
	}
}
