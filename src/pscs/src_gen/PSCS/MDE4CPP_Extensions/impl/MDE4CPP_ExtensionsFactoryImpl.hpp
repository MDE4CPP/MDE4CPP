//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_MDE4CPP_EXTENSIONSFACTORYIMPL_HPP
#define PSCS_MDE4CPP_EXTENSIONSFACTORYIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"

namespace MDE4CPP_Extensions 
{	class PSCS_Object;
}

namespace PSCS::MDE4CPP_Extensions 
{
	class PSCS_API MDE4CPP_ExtensionsFactoryImpl : virtual public ecore::EFactoryImpl , virtual public MDE4CPP_ExtensionsFactory 
	{
		private:    
			MDE4CPP_ExtensionsFactoryImpl(MDE4CPP_ExtensionsFactoryImpl const&) = delete;
			MDE4CPP_ExtensionsFactoryImpl& operator=(MDE4CPP_ExtensionsFactoryImpl const&) = delete;

		protected:
			friend class MDE4CPP_ExtensionsFactory;
			// Constructor
			MDE4CPP_ExtensionsFactoryImpl();

		public:
			virtual ~MDE4CPP_ExtensionsFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> createPSCS_Object(const int metaElementID = MDE4CPP_ExtensionsPackage::PSCS_OBJECT_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> createPSCS_Object_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID = MDE4CPP_ExtensionsPackage::PSCS_OBJECT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> createPSCS_Object_as_source_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID = MDE4CPP_ExtensionsPackage::PSCS_OBJECT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> createPSCS_Object_as_target_in_DirectedRelationship(std::shared_ptr<uml::DirectedRelationship> par_DirectedRelationship, const int metaElementID = MDE4CPP_ExtensionsPackage::PSCS_OBJECT_CLASS) const ;
			 

		private:
			static MDE4CPP_ExtensionsFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCS_MDE4CPP_EXTENSIONSFACTORYIMPL_HPP */
