#ifndef ABSTRACTDATATPYES_BASEANY_HPP
#define ABSTRACTDATATPYES_BASEANY_HPP

#include <stdexcept>
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/BaseElement.hpp"

class BaseAny: virtual public Any
{
	public:
		virtual ~BaseAny() = default;
		virtual std::shared_ptr<BaseElement> getAsBaseElement() const = 0;
};

template <class T> class BaseAnyTemplate: virtual public BaseAny
{
	public:
		BaseAnyTemplate(T, unsigned long typeID = 0, bool isContainer = false);
		virtual std::shared_ptr<BaseElement> getAsBaseElement() const final override;

	protected:
		BaseAnyTemplate() = default;
};


template <typename T>
inline BaseAnyTemplate<T>::BaseAnyTemplate(T value, unsigned long typeID, bool isContainer) : Any(value, typeID, isContainer) /* Must directly call constructor of Any due to virtual inheritance construction order */
{
}

template <typename T>
inline std::shared_ptr<BaseElement> BaseAnyTemplate<T>::getAsBaseElement() const
{
	std::shared_ptr<BaseElement> returnValue = nullptr;

	/* TODO ID of BaseElement? */
	if(0 == this->getTypeId())
	{
		try
		{
			returnValue = this->get<std::shared_ptr<BaseElement>>();
		}
		catch(...){}
	}
	if(!returnValue)
	{
		T anyValue=this->get<T>();
		returnValue = std::dynamic_pointer_cast<BaseElement>(anyValue);
	}
	if(!returnValue)
	{
		throw std::runtime_error("BaseAny::getAsBaseElement() : Bad cast");
	}
	return returnValue;
}

template <typename T> static std::shared_ptr<Any> eBaseAny(T value, unsigned long typeID)
{
	std::shared_ptr<Any> any(new BaseAnyTemplate<T>(value, typeID, false));
	return any;
}
#endif
