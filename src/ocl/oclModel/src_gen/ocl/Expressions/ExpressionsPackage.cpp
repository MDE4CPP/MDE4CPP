#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ocl/Expressions/impl/ExpressionsPackageImpl.hpp"

using namespace ocl::Expressions;

//static initialisation
const std::string ExpressionsPackage::eNAME ="Expressions";
const std::string ExpressionsPackage::eNS_URI ="http://ocl4cpp/ocl/expressions.ecore";
const std::string ExpressionsPackage::eNS_PREFIX ="ocl.expressions";

//Singleton 
std::shared_ptr<ExpressionsPackage> ExpressionsPackage::instance;

std::shared_ptr<ExpressionsPackage> ExpressionsPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(ExpressionsPackageImpl::create());
		std::dynamic_pointer_cast<ExpressionsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
