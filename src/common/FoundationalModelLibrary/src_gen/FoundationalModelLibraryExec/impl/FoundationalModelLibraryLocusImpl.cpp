#include "FoundationalModelLibraryLocusImpl.hpp"
#include <iostream>

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Class.hpp"

#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputFactory.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputPackage.hpp"
#include "FoundationalModelLibrary/Common/CommonFactory.hpp"
#include "FoundationalModelLibrary/Common/CommonPackage.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/StandardInputChannel.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/StandardOutputChannel.hpp"
#include "FoundationalModelLibrary/Common/Status.hpp"

using namespace FoundationalModelLibrary;

//*********************************
// Constructor / Destructor
//*********************************
FoundationalModelLibraryLocusImpl::FoundationalModelLibraryLocusImpl()
{
}

FoundationalModelLibraryLocusImpl::~FoundationalModelLibraryLocusImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FoundationalModelLibraryLocus "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

std::shared_ptr<uml::Element> FoundationalModelLibraryLocusImpl::instantiate(std::shared_ptr<uml::Class>  type)
{
	std::shared_ptr<uml::Package> typePackage = type->getPackage().lock();

	//Model-internal types
	if(typePackage == FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance())
	{	
		switch(type->_getID())
		{
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::STANDARDINPUTCHANNEL_CLASS:
			{
				std::shared_ptr<FoundationalModelLibrary::BasicInputOutput::StandardInputChannel> instance = FoundationalModelLibrary::BasicInputOutput::BasicInputOutputFactory::eInstance()->createStandardInputChannel();
				return instance;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::STANDARDOUTPUTCHANNEL_CLASS:
			{
				std::shared_ptr<FoundationalModelLibrary::BasicInputOutput::StandardOutputChannel> instance = FoundationalModelLibrary::BasicInputOutput::BasicInputOutputFactory::eInstance()->createStandardOutputChannel();
				return instance;
			}
		}
	}
	else if(typePackage == FoundationalModelLibrary::Common::CommonPackage::eInstance())
	{	
		switch(type->_getID())
		{
			case FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE:
			{
				std::shared_ptr<FoundationalModelLibrary::Common::Status> instance = FoundationalModelLibrary::Common::CommonFactory::eInstance()->createStatus();
				return instance;
			}
		}
	}
	//Model-external types
	//No external types used in Activities of this model

	return fUML::Semantics::Loci::LocusImpl::instantiate(type);
	//return PSCS::Semantics::Loci::CS_LocusImpl::instantiate(type);
}

void FoundationalModelLibraryLocusImpl::setThisLocusPtr(std::weak_ptr</*PSCS::Semantics::Loci::CS_Locus*/fUML::Semantics::Loci::Locus> thisLocusPtr)
{
	/*PSCS::Semantics::Loci::CS_LocusImpl::setThisLocusPtr(thisLocusPtr)*/ fUML::Semantics::Loci::LocusImpl::setThisLocusPtr(thisLocusPtr);
}
