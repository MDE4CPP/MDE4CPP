#include "util/stereotypestorage.hpp"

#include <iostream>

#include "ecore/EClass.hpp"
#include "uml/Association.hpp"
#include "uml/Property.hpp"
#include "uml/Stereotype.hpp"
#include "uml/UmlPackage.hpp"

using namespace util;

StereotypeStorage* StereotypeStorage::m_instance = nullptr;

StereotypeStorage * StereotypeStorage::eInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new StereotypeStorage();
	}
	return m_instance;
}

void StereotypeStorage::applyStereotype(uml::Element *_element, std::shared_ptr<uml::Stereotype> _stereotype)
{
	if (isStereotypeApplied(_element, _stereotype))
	{
		return;
	}

	std::shared_ptr<Bag<uml::Property>> propList = _stereotype->getOwnedAttribute();

	//set the base property of the stereotype to this
	for (std::shared_ptr<uml::Property> prop : *propList)
	{
		if (prop != nullptr)
		{
			//check if it is an extension association
			if (prop->getAssociation()->eClass() == uml::UmlPackage::eInstance()->getEClass_Extension())
			{
				//check type of the property
				if (_element->eClass()->getName() == prop->getType()->getName())
				{
					DEBUG_MESSAGE(std::cout << "Set Base Property " << prop->getQualifiedName() << std::endl;)
					//set Base
					_stereotype->set(prop, this);
				}
			}
		}
	}

	std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(_element);
	if (nullptr)
	{
		list.reset(new Bag<uml::Stereotype>());
		list->push_back(_stereotype);
		m_stereotypeApplicationMap.insert(std::pair<uml::Element*, std::shared_ptr<Bag<uml::Stereotype>>>(_element, list));
	}
	else
	{
		list->push_back(_stereotype);
	}

	DEBUG_MESSAGE(std::cout << "Stereotype applied :" << _stereotype->getMetaClass()->getQualifiedName() << std::endl;)
}

std::shared_ptr<uml::Stereotype> StereotypeStorage::getAppliedStereotype(uml::Element * _element, std::string qualifiedName)
{
	std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(_element);
	for (std::shared_ptr<uml::Stereotype> s : *list)
	{
		if (s->getMetaClass()->getQualifiedName() == qualifiedName)
		{
			return s;
		}
	}
	return nullptr;
}

std::shared_ptr<Bag<uml::Stereotype>> StereotypeStorage::getAppliedStereotypes(uml::Element * _element)
{
	std::map<uml::Element*, std::shared_ptr<Bag<uml::Stereotype>>>::iterator it = m_stereotypeApplicationMap.begin();
	std::map<uml::Element*, std::shared_ptr<Bag<uml::Stereotype>>>::iterator endIter = m_stereotypeApplicationMap.end();
	while (it != endIter)
	{
		if (it->first == _element)
		{
			return it->second;
		}
		it++;
	}
	return nullptr;
}

bool StereotypeStorage::isStereotypeApplied(uml::Element* _element, std::shared_ptr<uml::Stereotype> _stereotype)
{
	std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(_element);
	if (list == nullptr)
	{
		return false;
	}

	for (std::shared_ptr<uml::Stereotype> s : *list)
	{
		if (s->getMetaClass() == _stereotype)
		{
			//an stereotype instance exists for this element
			return true;
		}
	}
	return false;
}

void StereotypeStorage::unapplyStereotype(uml::Element *_element, std::shared_ptr<uml::Stereotype> _stereotype)
{
	if (isStereotypeApplied(_element, _stereotype))
	{
		DEBUG_MESSAGE(std::cout << "Stereotype unapplyed :" << _stereotype->getMetaClass()->getQualifiedName() << std::endl;)
		std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(_element);
		for (std::shared_ptr<uml::Stereotype> s : *list)
		{
			if (s->getMetaClass() == _stereotype)
			{
				list->erase(_stereotype);
				break;
			}
		}
	}
}

StereotypeStorage::StereotypeStorage()
{
}
