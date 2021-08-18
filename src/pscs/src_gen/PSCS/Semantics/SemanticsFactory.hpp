//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICSFACTORY_HPP
#define PSCS_SEMANTICSFACTORY_HPP
// namespace macro header include
#include "PSCS/PSCS.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ActivityNodeActivationGroup;
}




namespace fUML::Semantics::Actions
{
	class CallActionActivation;
}
namespace fUML::Semantics::Activities
{
	class DecisionNodeActivation;
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}


namespace fUML::Semantics::Loci
{
	class Locus;
}


namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}







namespace PSCS::Semantics 
{
	class PSCS_API SemanticsFactory : virtual public ecore::EFactory 
	{
		private:    
			SemanticsFactory(SemanticsFactory const&) = delete;
			SemanticsFactory& operator=(SemanticsFactory const&) = delete;
		protected:
			SemanticsFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<SemanticsFactory> instance;
			public:
				static std::shared_ptr<SemanticsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: PSCS_SEMANTICSFACTORY_HPP */
