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

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(ecore::EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className);
}

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(std::string _className) const
{
	//TODO: still two times run through map
	std::map<std::string,std::function<ecore::EObject*()>>::const_iterator iter = m_creatorMap.find(_className);
	
	std::shared_ptr<ecore::EObject> _createdObject;
	if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return std::shared_ptr<ecore::EObject>(iter->second());
    }

    return nullptr;
}


std::shared_ptr<TypesPackage> TypesFactoryImpl::getTypesPackage() const
{
	return TypesPackage::eInstance();
}
