#include "util/stereotypestorage.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#include <iostream>

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "uml/Association.hpp"
#include "uml/Property.hpp"
#include "uml/Stereotype.hpp"
#include "uml/UmlPackage.hpp"

using namespace util;

std::shared_ptr<StereotypeStorage> StereotypeStorage::m_instance = nullptr;

std::shared_ptr<StereotypeStorage> StereotypeStorage::eInstance()
{
	if (m_instance == nullptr)
	{
		m_instance.reset(new StereotypeStorage());
	}
	return m_instance;
}

void StereotypeStorage::applyStereotype(std::shared_ptr<uml::Element> element, std::shared_ptr<uml::Stereotype> stereotype)
{
	removeInvalidEntries();

	if (isStereotypeApplied(element, stereotype))
	{
		return;
	}

	std::shared_ptr<Bag<uml::Property>> propList = stereotype->getOwnedAttribute();

	//set the base property of the stereotype to this
	for (std::shared_ptr<uml::Property> prop : *propList)
	{
		if (prop != nullptr)
		{
			//check if it is an extension association
			if (prop->getAssociation()->eClass() == uml::UmlPackage::eInstance()->getExtension_Class())
			{
				//check type of the property
				if (element->eClass()->getName() == prop->getType()->getName())
				{
					DEBUG_MESSAGE(std::cout << "Set Base Property " << prop->getQualifiedName() << std::endl;)
					//set Base
					stereotype->set(prop, eAny(this));
				}
			}
		}
	}

	std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(element);
	if (list == nullptr)
	{
		list.reset(new Bag<uml::Stereotype>());
		list->push_back(stereotype);
		m_stereotypeApplicationMap.insert(std::pair<std::weak_ptr<uml::Element>, std::shared_ptr<Bag<uml::Stereotype>>>(element, list));
	}
	else
	{
		list->push_back(stereotype);
	}

	DEBUG_MESSAGE(std::cout << "Stereotype applied :" << stereotype->getMetaClass()->getQualifiedName() << std::endl;)
}

std::shared_ptr<uml::Stereotype> StereotypeStorage::getAppliedStereotype(std::shared_ptr<uml::Element> element, std::string qualifiedName) const
{
	std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(element);
	if (list == nullptr)
	{
		return nullptr;
	}
	for (std::shared_ptr<uml::Stereotype> s : *list)
	{
		if (s->getMetaClass()->getQualifiedName() == qualifiedName)
		{
			return s;
		}
	}
	return nullptr;
}

std::shared_ptr<Bag<uml::Stereotype>> StereotypeStorage::getAppliedStereotypes(std::shared_ptr<uml::Element> element) const
{
	std::map<std::weak_ptr<uml::Element>, std::shared_ptr<Bag<uml::Stereotype>>>::const_iterator it = m_stereotypeApplicationMap.cbegin();
	std::map<std::weak_ptr<uml::Element>, std::shared_ptr<Bag<uml::Stereotype>>>::const_iterator endIter = m_stereotypeApplicationMap.cend();
	while (it != endIter)
	{
		std::shared_ptr<uml::Element> storedElement = it->first.lock();
		if (storedElement == element)
		{
			return it->second;
		}
		it++;
	}
	return nullptr;
}

bool StereotypeStorage::isStereotypeApplied(std::shared_ptr<uml::Element> element, std::shared_ptr<uml::Stereotype> stereotype) const
{
	std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(element);
	if (list == nullptr)
	{
		return false;
	}

	for (std::shared_ptr<uml::Stereotype> s : *list)
	{
		if (s == stereotype)
		{
			//an stereotype instance exists for this element
			return true;
		}
	}
	return false;
}

void StereotypeStorage::removeInvalidEntries()
{
	std::map<std::weak_ptr<uml::Element>, std::shared_ptr<Bag<uml::Stereotype>>>::iterator it = m_stereotypeApplicationMap.begin();
	std::map<std::weak_ptr<uml::Element>, std::shared_ptr<Bag<uml::Stereotype>>>::iterator endIter = m_stereotypeApplicationMap.end();
	while (it != endIter)
	{
		std::shared_ptr<uml::Element> storedElement = it->first.lock();
		if (storedElement == nullptr)
		{
			it = m_stereotypeApplicationMap.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void StereotypeStorage::unapplyStereotype(std::shared_ptr<uml::Element> element, std::shared_ptr<uml::Stereotype> stereotype)
{
	removeInvalidEntries();

	if (isStereotypeApplied(element, stereotype))
	{
		DEBUG_MESSAGE(std::cout << "Stereotype unapplyed :" << stereotype->getMetaClass()->getQualifiedName() << std::endl;)
		std::shared_ptr<Bag<uml::Stereotype>> list = getAppliedStereotypes(element);
		for (std::shared_ptr<uml::Stereotype> s : *list)
		{
			if (s->getMetaClass() == stereotype)
			{
				list->erase(stereotype);
				break;
			}
		}
	}
}

StereotypeStorage::StereotypeStorage()
{
}
