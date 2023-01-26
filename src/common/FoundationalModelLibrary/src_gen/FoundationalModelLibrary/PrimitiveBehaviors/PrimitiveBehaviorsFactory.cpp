
#include "FoundationalModelLibrary/PrimitiveBehaviors/PrimitiveBehaviorsFactory.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/impl/PrimitiveBehaviorsFactoryImpl.hpp"

using namespace FoundationalModelLibrary::PrimitiveBehaviors;

//static initialisation
std::shared_ptr<PrimitiveBehaviorsFactory> PrimitiveBehaviorsFactory::instance;

std::shared_ptr<PrimitiveBehaviorsFactory> PrimitiveBehaviorsFactory::eInstance()
{
	if(instance==nullptr)
	{
		//create a new Singelton Instance
		instance.reset(PrimitiveBehaviorsFactoryImpl::create());
	}	
	return instance;
}
