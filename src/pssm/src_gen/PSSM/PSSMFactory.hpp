//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSMFACTORY_HPP
#define PSSMFACTORY_HPP
// namespace macro header include
#include "PSSM/PSSM.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "PSSM/PSSMPackage.hpp"

namespace PSSM 
{
	class PSSMPackage;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace uml
{
	class DirectedRelationship;
}




namespace fUML::Semantics::CommonBehavior
{
	class ObjectActivation;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::MDE4CPP_Extensions
{
	class FUML_Object;
}


namespace fUML::Semantics::Loci
{
	class Locus;
}


namespace fUML::Semantics::CommonBehavior
{
	class ObjectActivation;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}











namespace PSSM 
{
	class PSSM_API PSSMFactory : virtual public ecore::EFactory 
	{
		private:    
			PSSMFactory(PSSMFactory const&) = delete;
			PSSMFactory& operator=(PSSMFactory const&) = delete;
		protected:
			PSSMFactory(){}
		
			//Singleton Getter
			public:
				static std::shared_ptr<PSSMFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: PSSMFACTORY_HPP */
