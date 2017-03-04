#include "stereotypestorage.h"

#include "Stereotype.hpp"
#include "Property.hpp"
#include "Association.hpp"
#include "UmlPackage.hpp"
#include "EClass.hpp"
#include <iostream>

using namespace util;

StereotypeStorage*  StereotypeStorage::m_instance = nullptr;

StereotypeStorage * StereotypeStorage::eInstance()
{
    if(m_instance==nullptr)
    {
        m_instance = new StereotypeStorage();
    }
    return m_instance;
}

void StereotypeStorage::applyStereotype(uml::Element *_element, std::shared_ptr<uml::Stereotype> _stereotype)
{
	if(isStereotypeApplied(_element,_stereotype))
	{
		return;
	}
   
	std::shared_ptr<std::vector<std::shared_ptr<uml::Property>>> propList = _stereotype->getOwnedAttribute();
	
	//set the base property of the stereotype to this
	for(std::shared_ptr<uml::Property> prop : *propList)
	{
		if (prop != nullptr)
		{
			//check if it is an extension association
			if(prop->getAssociation()->eClass()==uml::UmlPackage::eInstance()->getExtension())
			{
				//check type of the property
				if(_element->eClass()->getName()==prop->getType()->getName())
				{
					std::cout <<"Set Base Property "<< prop->getQualifiedName() << std::endl;
					//set Base
					_stereotype->set(prop,this);
				}
			}
		}
	}

	m_stereotypeApplicationMap.insert(std::pair<uml::Element *,std::shared_ptr<uml::Stereotype>>(_element,_stereotype));
	std::cout<< "Stereotype applyed :"<<_stereotype->getMetaClass()->getQualifiedName() << std::endl;
}

std::shared_ptr<uml::Stereotype> StereotypeStorage::getAppliedStereotype(uml::Element * _element, std::string qualifiedName)
{
    for( std::shared_ptr<uml::Stereotype> s : *getAppliedStereotypes(_element) )
    {
        if(s->getMetaClass()->getQualifiedName()==qualifiedName)
        {
            return s;
        }
    }

    return nullptr;
}

std::shared_ptr<std::vector<std::shared_ptr<uml::Stereotype>>> StereotypeStorage::getAppliedStereotypes(uml::Element * _element)
{
    std::shared_ptr<std::vector<std::shared_ptr<uml::Stereotype>>> vector(new std::vector<std::shared_ptr<uml::Stereotype>>());
    std::map<uml::Element *, std::shared_ptr<uml::Stereotype>>::iterator it = m_stereotypeApplicationMap.find(_element);
    while (it != m_stereotypeApplicationMap.end())
    {
        vector->push_back(it->second);
    }
    return vector;
}

bool StereotypeStorage::isStereotypeApplied(uml::Element * _element, std::shared_ptr<uml::Stereotype> _stereotype)
{
    for(std::shared_ptr<uml::Stereotype> s : *getAppliedStereotypes(_element))
    {
        if(s->getMetaClass() == _stereotype)
        {
            //an stereotype instance exists for this element
            return true;
        }
    }

    return false;
}

void StereotypeStorage::unapplyStereotype(uml::Element *_element, std::shared_ptr<uml::Stereotype> _stereotype)
{
    if(isStereotypeApplied(_element,_stereotype))
    {
        std::cout << "Stereotype unapplyed :"<<_stereotype->getMetaClass()->getQualifiedName() << std::endl;
        m_stereotypeApplicationMap.erase(_element); // _element, _stereotype
    }

}

StereotypeStorage::StereotypeStorage()
{
}
