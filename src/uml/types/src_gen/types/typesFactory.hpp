//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef TYPESFACTORY_HPP
#define TYPESFACTORY_HPP
// namespace macro header include
#include "types/types.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "types/typesPackage.hpp"

namespace types 
{
	class typesPackage;
}



namespace types 
{
	class TYPES_API typesFactory : virtual public ecore::EFactory 
	{
		private:    
			typesFactory(typesFactory const&) = delete;
			typesFactory& operator=(typesFactory const&) = delete;
		protected:
			typesFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<typesFactory> instance;
			public:
				static std::shared_ptr<typesFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: TYPESFACTORY_HPP */
