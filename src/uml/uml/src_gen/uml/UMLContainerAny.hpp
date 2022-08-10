#ifndef UML_UMLCONTAINERANY_HPP
#define UML_UMLCONTAINERANY_HPP

#include <stdexcept>
#include "ecore/EcoreContainerAny.hpp"
#include "uml/Element.hpp"
#include "uml/umlPackage.hpp"

namespace uml
{
	class UMLContainerAny: virtual public ecore::EcoreContainerAny
	{
		public:
			virtual ~UMLContainerAny() = default;
			virtual std::shared_ptr<Bag<uml::Element>> getAsElementContainer() const = 0;

		protected:
			UMLContainerAny(){};
	};

	template <class T> class UMLContainerAnyTemplate: virtual public UMLContainerAny, virtual public ecore::EcoreContainerAnyTemplate<T>
	{
		public:
			UMLContainerAnyTemplate(T, unsigned long typeID = 0, bool isContainer = true);
			virtual std::shared_ptr<Bag<uml::Element>> getAsElementContainer() const final override;
	};
}

template <typename T>
uml::UMLContainerAnyTemplate<T>::UMLContainerAnyTemplate(T value, unsigned long typeID, bool isContainer) : Any(value, typeID, isContainer) /* Must directly call constructor of Any due to virtual inheritance construction order */
{
}

template <typename T>
std::shared_ptr<Bag<uml::Element>> uml::UMLContainerAnyTemplate<T>::getAsElementContainer() const
{
	std::shared_ptr<Bag<uml::Element>> returnContainer = nullptr;

	if(uml::umlPackage::ELEMENT_CLASS == this->getTypeId())
	{
		try
		{
			returnContainer = this->get<std::shared_ptr<Bag<uml::Element>>>();
		}
		catch(...){}
	}
	if(!returnContainer)
	{
		T anyValue=this->get<T>();
		
		returnContainer.reset();
		for(auto anyElement : *anyValue)
		{
			std::shared_ptr<uml::Element> element = std::dynamic_pointer_cast<uml::Element>(anyElement);
			if(anyElement)
			{
				returnContainer->add(anyElement);
			}
		}
	}
	if(!returnContainer)
	{
		throw std::runtime_error("UMLContainerAny::getAsElementContainer() : Bad cast");
	}
	return returnContainer;
}

template <typename T> static std::shared_ptr<Any> eUMLContainerAny(T value, unsigned long typeID)
{
	std::shared_ptr<Any> any(new UMLContainerAnyTemplate<T>(value, typeID, true));
	return any;
}
#endif
