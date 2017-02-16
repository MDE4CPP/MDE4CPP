//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ECLASSECLASSIMPL_HPP
#define ECORE_ECLASSECLASSIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../EClass.hpp"

#include "impl/EClassifierImpl.hpp"


//*********************************
namespace ecore 
{
	class EClassImpl :virtual public EClassifierImpl, virtual public EClass
	{
		public: 
			EClassImpl(const EClassImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			EClassImpl& operator=(EClassImpl const&) = delete;

		protected:
			friend class EcoreFactoryImpl;
			EClassImpl();

		public:
			//destructor
			virtual ~EClassImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool isSuperTypeOf(ecore::EClass *  someClass)  const  ;
			
			/*!
			 */ 
			virtual int getFeatureCount()  const  ;
			
			/*!
			 */ 
			virtual ecore::EStructuralFeature *  getEStructuralFeature(int featureID)  const  ;
			
			/*!
			 */ 
			virtual int getFeatureID(ecore::EStructuralFeature *  feature)  const  ;
			
			/*!
			 */ 
			virtual ecore::EStructuralFeature *  getEStructuralFeature(std::string featureName)  const  ;
			
			/*!
			 */ 
			virtual int getOperationCount()  const  ;
			
			/*!
			 */ 
			virtual ecore::EOperation *  getEOperation(int operationID)  const  ;
			
			/*!
			 */ 
			virtual int getOperationID(ecore::EOperation *  operation)  const  ;
			
			/*!
			 */ 
			virtual ecore::EOperation *  getOverride(ecore::EOperation *  operation)  const  ;
			
			/*!
			 */ 
			virtual ecore::EGenericType *  getFeatureType(ecore::EStructuralFeature *  feature)  const  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isAbstract() const ;
			
			/*!
			 */ 
			virtual void setAbstract (bool _abstract); 
			
			/*!
			 */ 
			virtual bool isInterface() const ;
			
			/*!
			 */ 
			virtual void setInterface (bool _interface); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::vector<ecore::EClass * > *  getESuperTypes() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EOperation * > *  getEOperations() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EAttribute * > *  getEAllAttributes() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EReference * > *  getEAllReferences() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EReference * > *  getEReferences() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EAttribute * > *  getEAttributes() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EReference * > *  getEAllContainments() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EOperation * > *  getEAllOperations() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EStructuralFeature * > *  getEAllStructuralFeatures() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EClass * > *  getEAllSuperTypes() const ;
			
			/*!
			 */
			virtual ecore::EAttribute *  getEIDAttribute() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EStructuralFeature * > *  getEStructuralFeatures() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EGenericType * > *  getEGenericSuperTypes() const ;
			
			/*!
			 */
			virtual std::vector<ecore::EGenericType * > *  getEAllGenericSuperTypes() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual EClass* eStaticClass() const;
	};
}
#endif /* end of include guard: ECORE_ECLASSECLASSIMPL_HPP */

