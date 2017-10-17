
#include "PictureImpl.hpp"
#include "LibraryModel_umlPackageImpl.hpp"
#include "Class.hpp"

using namespace LibraryModel_uml;
using boost::any_cast;

//*********************************
// Constructor / Destructor
//*********************************
PictureImpl::PictureImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::NamedModelElement::name",[this](){ return this->getName();}));
	m_getterMap.insert(std::pair<std::string,std::function<boost::any()>>("LibraryModel_uml::Picture::pageNumber",[this](){ return this->getPageNumber();}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(boost::any)>>("LibraryModel_uml::NamedModelElement::name",[this](boost::any object){this->setName(any_cast<std::string>(object));}));
	m_setterMap.insert(std::pair<std::string,std::function<void(boost::any)>>("LibraryModel_uml::Picture::pageNumber",[this](boost::any object){this->setPageNumber(any_cast<int>(object));}));
	
	 

	// init properties without default
	
}




PictureImpl::~PictureImpl()
{
}

std::shared_ptr<uml::Class> PictureImpl::getMetaClass()
{
	return LibraryModel_umlPackageImpl::eInstance()->get_LibraryModel_uml_Picture();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PictureImpl::setPageNumber(int _pageNumber)
{
	m_pageNumber = _pageNumber;
}
int PictureImpl::getPageNumber() const 
{
	return m_pageNumber;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PictureImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<boost::any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return boost::any();
}

void PictureImpl::set(std::shared_ptr<uml::Property> _property,boost::any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void(boost::any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void PictureImpl::unset(std::shared_ptr<uml::Property> _property)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void()>>::iterator iter = m_unsetterMap.find(qName);
    if(iter != m_unsetterMap.end())
    {
        //invoke the getter function
        iter->second();
    }
}
