#include "TypesFactoryImpl.hpp"
#include "TypesPackage.hpp"

#include "EClass.hpp"

using namespace types;

//*********************************
// Constructor / Destructor
//*********************************

TypesFactoryImpl::TypesFactoryImpl()
{
}

TypesFactoryImpl::~TypesFactoryImpl()
{
}

TypesFactory* TypesFactoryImpl::create()
{
	return new TypesFactoryImpl();
}

//*********************************
// creators
//*********************************

ecore::EObject* TypesFactoryImpl::create(ecore::EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	switch (_class->getClassifierID())
	{
		default:
       		throw "Error create class '" + _class->getName();
	}
	return nullptr;
}


TypesPackage * TypesFactoryImpl::getTypesPackage() const
{
	return TypesPackage::eInstance();
}
