#include "Loci/LociPackage.hpp"
#include "Loci/impl/LociPackageImpl.hpp"

using namespace Loci;

//static initialisation
const std::string LociPackage::eNAME ="Loci";
const std::string LociPackage::eNS_URI ="http:///PSCS_Semantics/Semantics/Loci.ecore";
const std::string LociPackage::eNS_PREFIX ="PSCS_Semantics.Semantics.Loci";

//Singleton 
std::shared_ptr<LociPackage> LociPackage::instance;

std::shared_ptr<LociPackage>LociPackage::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LociPackageImpl::create());
		std::dynamic_pointer_cast<LociPackageImpl>(instance)->init(instance);
	}	
	return instance;
}
