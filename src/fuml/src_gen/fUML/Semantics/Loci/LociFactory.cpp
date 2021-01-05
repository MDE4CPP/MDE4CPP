#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"

using namespace fUML::Semantics::Loci;
				 
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
