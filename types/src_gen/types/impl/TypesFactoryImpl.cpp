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

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(std::string _className) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id);
    }

    return nullptr;
}

std::shared_ptr<ecore::EObject> TypesFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}



std::shared_ptr<TypesPackage> TypesFactoryImpl::getTypesPackage() const
{
	return TypesPackage::eInstance();
}
