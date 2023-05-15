//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_LOCUS_HPP
#define FOUNDATIONALMODELLIBRARY_LOCUS_HPP

//#include "PSCS/Semantics/Loci/CS_Locus.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

namespace FoundationalModelLibrary 
{
	class FoundationalModelLibraryLocus: virtual public /*PSCS::Semantics::Loci::CS_Locus*/ fUML::Semantics::Loci::Locus
	{
		public: 
			FoundationalModelLibraryLocus (){};
		public:
			//destructor
			virtual ~FoundationalModelLibraryLocus(){};
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<uml::Element> instantiate(const std::shared_ptr<uml::Class>&) = 0;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_LOCUS_HPP */
