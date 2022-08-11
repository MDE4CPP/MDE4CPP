#ifndef UML_UMLANY_HPP
#define UML_UMLANY_HPP

#include <stdexcept>
#include "ecore/EcoreAny.hpp"
#include "uml/Element.hpp"

namespace uml
{
	class UMLAny: virtual public ecore::EcoreAny
	{
		public:
			virtual ~UMLAny() = default;
			virtual std::shared_ptr<uml::Element> getAsElement() const = 0;

		protected:
			UMLAny(){};
	};


	template <class T> class UMLAnyTemplate: virtual public UMLAny, virtual public ecore::EcoreAnyTemplate<T>
	{
		public:
			UMLAnyTemplate(T, unsigned long typeID = 0, bool isContainer = false);
			virtual std::shared_ptr<uml::Element> getAsElement() const final override;
	};
}

template <typename T>
inline uml::UMLAnyTemplate<T>::UMLAnyTemplate(T value, unsigned long typeID, bool isContainer) : Any(value, typeID, isContainer) /* Must directly call constructor of Any due to virtual inheritance construction order */
{
}

template <typename T>
inline std::shared_ptr<uml::Element> uml::UMLAnyTemplate<T>::getAsElement() const
{
	std::shared_ptr<uml::Element> returnValue=nullptr;

	if(uml::umlPackage::ELEMENT_CLASS == this->getTypeId())
	{
		try
		{
			returnValue = this->get<std::shared_ptr<uml::Element>>();
		}
		catch(...){}
	}
	if(!returnValue)
	{
		T anyValue=this->get<T>();

		returnValue = std::dynamic_pointer_cast<uml::Element>(anyValue);
	}
	if(!returnValue)
	{
		throw std::runtime_error("UMLAny::getAsElement() : Bad cast");
	}
	return returnValue;
}


template <typename T> static std::shared_ptr<Any> eUMLAny(T value, unsigned long typeID)
{
	std::shared_ptr<Any> any(new UMLAnyTemplate<T>(value, typeID, false));
	return any;
}
#endif
