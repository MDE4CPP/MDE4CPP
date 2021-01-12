#include "PSCS/Semantics/Loci/LociFactory.hpp"
#include "PSCS/Semantics/Loci/impl/LociFactoryImpl.hpp"

using namespace PSCS::Semantics::Loci;
				 
//static initialisation
std::shared_ptr<LociFactory> LociFactory::instance;

std::shared_ptr<LociFactory> LociFactory::eInstance()
{
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(LociFactoryImpl::create());
	}	
	return instance;
}
