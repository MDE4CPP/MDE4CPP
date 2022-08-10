#ifndef ECORE_ECOREANY_HPP
#define ECORE_ECOREANY_HPP

#include <stdexcept>
#include "abstractDataTypes/BaseAny.hpp"
#include "ecore/EObject.hpp"
#include "ecore/ecorePackage.hpp"

namespace ecore
{
	class EcoreAny: virtual public BaseAny
	{
		public:
			virtual ~EcoreAny() = default;
			virtual std::shared_ptr<ecore::EObject> getAsEObject() const = 0;
	};

	template <class T> class EcoreAnyTemplate: virtual public EcoreAny, virtual public BaseAnyTemplate<T>
	{
		public:
			EcoreAnyTemplate(T, unsigned long typeID = 0, bool isContainer = false);
			virtual std::shared_ptr<ecore::EObject> getAsEObject() const final override;

		protected:
			EcoreAnyTemplate() = default;
	};
}

template <typename T>
ecore::EcoreAnyTemplate<T>::EcoreAnyTemplate(T value, unsigned long typeID, bool isContainer) : Any(value, typeID, isContainer) /* Must directly call constructor of Any due to virtual inheritance construction order */
{
}

template <typename T>
std::shared_ptr<ecore::EObject> ecore::EcoreAnyTemplate<T>::getAsEObject() const
{
	std::shared_ptr<ecore::EObject> returnValue=nullptr;

	if(ecore::ecorePackage::EOBJECT_CLASS == this->getTypeId())
	{
		try
		{
			returnValue = this->get<std::shared_ptr<ecore::EObject>>();
		}
		catch(...){}
	}
	if(!returnValue)
	{
		T anyValue=this->get<T>();

		returnValue = std::dynamic_pointer_cast<ecore::EObject>(anyValue);
	}
	if(!returnValue)
	{
		throw std::runtime_error("EcoreAny::getAsEObject() : Bad cast");
	}
	return returnValue;
}


template <typename T> static std::shared_ptr<Any> eEcoreAny(T value, unsigned long typeID)
{
	std::shared_ptr<Any> any(new ecore::EcoreAnyTemplate<T>(value, typeID, false));
	return any;
}
#endif
