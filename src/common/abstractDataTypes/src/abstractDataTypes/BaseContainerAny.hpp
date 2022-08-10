#ifndef ABSTRACTDATATPYES_BASECONTAINERANY_HPP
#define ABSTRACTDATATPYES_BASECONTAINERANY_HPP

#include <stdexcept>
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/BaseElement.hpp"

class BaseContainerAny: virtual public Any
{
	public:
		virtual ~BaseContainerAny() = default;
		virtual std::shared_ptr<Bag<BaseElement>> getAsBaseElementContainer() const = 0;
};

template <class T> class BaseContainerAnyTemplate: virtual public BaseContainerAny
{
	public:
		BaseContainerAnyTemplate(T, unsigned long typeID = 0, bool isContainer = true);
		virtual std::shared_ptr<Bag<BaseElement>> getAsBaseElementContainer() const final override;

	protected:
		BaseContainerAnyTemplate() = default;
};

template <typename T>
BaseContainerAnyTemplate<T>::BaseContainerAnyTemplate(T value, unsigned long typeID, bool isContainer) : Any(value, typeID, isContainer) /* Must directly call constructor of Any due to virtual inheritance construction order */
{
}

template <typename T>
std::shared_ptr<Bag<BaseElement>> BaseContainerAnyTemplate<T>::getAsBaseElementContainer() const
{
	std::shared_ptr<Bag<BaseElement>> returnContainer = nullptr;

	/* TODO ID of BaseElement? */
	if(0 == this->getTypeId())
	{
		try
		{
			returnContainer = this->get<std::shared_ptr<Bag<BaseElement>>>();
		}
		catch(...){}
	}
	if(!returnContainer)
	{
		T anyValue=this->get<T>();
		
		returnContainer.reset();
		
		for(auto anyElement : *anyValue)
		{
			std::shared_ptr<BaseElement> baseElement = std::dynamic_pointer_cast<BaseElement>(anyElement);
			if(anyElement)
			{
				returnContainer->add(anyElement);
			}
		}
	}
	if(!returnContainer)
	{
		throw std::runtime_error("BaseContainerAny::getAsBaseElementContainer() : Bad cast");
	}
	return returnContainer;
}

template <typename T> static std::shared_ptr<Any> eBaseContainerAny(T value, unsigned long typeID)
{
	std::shared_ptr<Any> any(new BaseContainerAnyTemplate<T>(value, typeID, true));
	return any;
}
#endif
