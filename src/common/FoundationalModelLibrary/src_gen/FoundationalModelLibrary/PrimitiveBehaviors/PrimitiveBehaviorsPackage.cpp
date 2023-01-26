#include "FoundationalModelLibrary/PrimitiveBehaviors/PrimitiveBehaviorsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/impl/PrimitiveBehaviorsPackageImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors;

//static initialisation
const std::string PrimitiveBehaviorsPackage::eNAME ="PrimitiveBehaviors";
const std::string PrimitiveBehaviorsPackage::eNS_URI ="";
const std::string PrimitiveBehaviorsPackage::eNS_PREFIX ="FoundationalModelLibrary";

//Singleton 
std::shared_ptr<PrimitiveBehaviorsPackage> PrimitiveBehaviorsPackage::instance;

std::shared_ptr<PrimitiveBehaviorsPackage> PrimitiveBehaviorsPackage::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(PrimitiveBehaviorsPackageImpl::create());
		std::dynamic_pointer_cast<PrimitiveBehaviorsPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
