#ifndef ABSTRACTDATATPYES_ANY_EOBJECT_BAG_HPP
#define ABSTRACTDATATPYES_ANY_EOBJECT_BAG_HPP

#include <stdexcept>
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Union.hpp"

class AnyEObjectBag: public AnyObject
{
public:
	template <typename T> AnyEObjectBag(T value,long long typeID, bool isContainer=true) : AnyObject(value, typeID, isContainer)
	{
	}

	virtual ~AnyEObjectBag()
	{
	}

	virtual std::shared_ptr<Bag<ecore::EObject>> getBag()
	{
		if(2051543432==this->getTypeId())  /*ecore::ecorePackage::EOBJECT_CLASS*/
		{
			try // can be: Bag, Subset, SubsetUnion or Union // for Subset complete template signature are needed
			{
				return this->get<std::shared_ptr<Bag<ecore::EObject>>>();
			} catch(...){}
			try // can be: Bag, Subset, SubsetUnion or Union
			{
				return this->get<std::shared_ptr<Union<ecore::EObject>>>();
			} catch(...){}
		}
		return nullptr; // return emptyList
	}
};

template <class T> class AnyGenericBag: public AnyEObjectBag
{
public:
	AnyGenericBag(T value,long long typeID=0, bool isContainer=true) : AnyEObjectBag(value, typeID, isContainer)
	{
	}

	void resetBag(T value)
	{
		TypedObject<T>* obj = dynamic_cast<TypedObject<T>*>(m_object);
		if (obj)
		{
			return obj->set(value);
		}
		throw std::runtime_error("AnyGenericBag::resetBag() : Bad cast");
	}

	virtual std::shared_ptr<Bag<ecore::EObject>> getBag()
	{
		std::shared_ptr<Bag<ecore::EObject>> returnList=nullptr;
		if(2051543432==this->getTypeId()) /*ecore::ecorePackage::EOBJECT_CLASS*/
		{
			returnList=AnyEObjectBag::getBag();
		}
		if(nullptr==returnList)
		{
			T anyBag=this->get<T>();
			if(anyBag->size()>0)
			{
				returnList=std::make_shared<Bag<ecore::EObject>>();
				for (auto i : *anyBag)
				{
					std::shared_ptr<ecore::EObject> object= std::dynamic_pointer_cast<ecore::EObject>(i);
					if(object)
					{
						returnList->push_back(object);
					}
	/*Further Any enhancement:
	#include "ecore/ecoreFactory.hpp"
	#include "ecore/EObjectAny.hpp"
					else // could be an Any
					{
						std::shared_ptr<AnyObject> anyObject= std::dynamic_pointer_cast<AnyObject>(i);
						if(object)
						{
							std::shared_ptr<ecore::EObjectAny> anyObject= ecore::ecoreFactory::eInstance()->createEObjectAny();
							returnList->push_back(anyObject);
						}
					}
	*/
				}
			}
			else
			{
				throw std::runtime_error("AnyGenericBag::getBag() : Bad cast");
			}
		}
		return returnList;
	}

};

template <typename T> static Any eAnyBag(T value,long long typeID)
{
	Any any(new AnyGenericBag<T>(value,typeID,true));
	return any;
}
#endif
