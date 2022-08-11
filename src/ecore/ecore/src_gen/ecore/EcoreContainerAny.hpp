#ifndef ECORE_ECORECONTAINERANY_HPP
#define ECORE_ECORECONTAINERANY_HPP

#include <stdexcept>
#include "abstractDataTypes/BaseContainerAny.hpp"
#include "ecore/EObject.hpp"
#include "ecore/ecorePackage.hpp"

namespace ecore
{
	class EcoreContainerAny: virtual public BaseContainerAny
	{
		public:
			virtual ~EcoreContainerAny() = default;
			virtual std::shared_ptr<Bag<ecore::EObject>> getAsEObjectContainer() const = 0;
	};

	template <class T> class EcoreContainerAnyTemplate: virtual public EcoreContainerAny, virtual public BaseContainerAnyTemplate<T>
	{
		public:
			EcoreContainerAnyTemplate(T, unsigned long typeID = 0, bool isContainer = true);
			virtual std::shared_ptr<Bag<ecore::EObject>> getAsEObjectContainer() const final override;

		protected:
			EcoreContainerAnyTemplate() = default;
	};
}

template <typename T>
inline ecore::EcoreContainerAnyTemplate<T>::EcoreContainerAnyTemplate(T value, unsigned long typeID, bool isContainer) : Any(value, typeID, isContainer) /* Must directly call constructor of Any due to virtual inheritance construction order */
{
}

template <typename T>
inline std::shared_ptr<Bag<ecore::EObject>> ecore::EcoreContainerAnyTemplate<T>::getAsEObjectContainer() const
{
	std::shared_ptr<Bag<ecore::EObject>> returnContainer = nullptr;

	if(ecore::ecorePackage::EOBJECT_CLASS == this->getTypeId())
	{
		try
		{
			returnContainer = this->get<std::shared_ptr<Bag<ecore::EObject>>>();
		}
		catch(...){}
	}
	if(!returnContainer)
	{
		T anyValue=this->get<T>();

		returnContainer.reset();
		for(auto anyElement : *anyValue)
		{
			std::shared_ptr<ecore::EObject> eObject = std::dynamic_pointer_cast<ecore::EObject>(anyElement);
			if(anyElement)
			{
				returnContainer->add(anyElement);
			}
		}
	}
	if(!returnContainer)
	{
		throw std::runtime_error("EcoreContainerAny::getAsEObjectContainer() : Bad cast");
	}
	return returnContainer;
}

template <typename T> static std::shared_ptr<Any> eEcoreContainerAny(T value, unsigned long typeID)
{
	std::shared_ptr<Any> any(new ecore::EcoreContainerAnyTemplate<T>(value, typeID, true));
	return any;
}
#endif
