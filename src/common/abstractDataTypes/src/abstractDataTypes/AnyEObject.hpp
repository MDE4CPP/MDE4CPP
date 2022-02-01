#ifndef ABSTRACTDATATPYES_ANY_EOBJECT_HPP
#define ABSTRACTDATATPYES_ANY_EOBJECT_HPP

#include <stdexcept>
#include "abstractDataTypes/Any.hpp"

class AnyEObject: public AnyObject
{     
public:
	template <typename T> AnyEObject(T value,long long typeID, bool isContainer=true) : AnyObject(value, typeID, isContainer)
	{
	}

	virtual ~AnyEObject()
	{
	}

	virtual std::shared_ptr<ecore::EObject> getObject()
	{
		if(2051543432==this->getTypeId())  /*ecore::ecorePackage::EOBJECT_CLASS*/
		{
			try // can be: Bag, Subset, SubsetUnion or Union // for Subset complete template signature are needed
			{
				return this->get<std::shared_ptr<ecore::EObject>>();
			} catch(...){}
		}
		return nullptr; // return emptyList
	}
};

template <class T> class AnyGenericEObject: public AnyEObject
{
public:
	AnyGenericEObject(T value,long long typeID=0, bool isContainer=true) : AnyEObject(value, typeID, isContainer)
	{
	}

	void resetBag(T value)
	{
		TypedObject<T>* obj = dynamic_cast<TypedObject<T>*>(m_object);
		if (obj)
		{
			return obj->set(value);
		}
		throw std::runtime_error("AnyEObject::resetBag() : Bad cast");
	}

	virtual std::shared_ptr<ecore::EObject> getObject()
	{
		std::shared_ptr<ecore::EObject> returnVal=nullptr;
		if(2051543432==this->getTypeId()) /*ecore::ecorePackage::EOBJECT_CLASS*/
		{
			returnVal=AnyEObject::getObject();
		}
		if(nullptr==returnVal)
		{
			T anyObj=this->get<T>();
			returnVal= std::dynamic_pointer_cast<ecore::EObject>(anyObj);
		}
		if(nullptr==returnVal)
		{
			throw std::runtime_error("AnyEObject::getObject() : Bad cast");
		}
		return returnVal;
	}

};

template <typename T> static Any eAnyObject(T value,long long typeID)
{
	Any any(new AnyGenericEObject<T>(value,typeID,false));
	return any;
}
#endif