#include "ecore/impl/EClassImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EAttribute.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"

#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EClassImpl::EClassImpl()
{	
}

EClassImpl::~EClassImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EClass "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EClassImpl::EClassImpl(std::weak_ptr<ecore::EObject > par_eContainer)
:EClassImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EClassImpl::EClassImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
:EClassImpl()
{
	m_ePackage = par_ePackage;
}


EClassImpl::EClassImpl(const EClassImpl & obj):EClassImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EClass "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_abstract = obj.isAbstract();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_interface = obj.isInterface();
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<ecore::EAttribute>> _eAllAttributes = obj.getEAllAttributes();
	m_eAllAttributes.reset(new Bag<ecore::EAttribute>(*(obj.getEAllAttributes().get())));

	std::shared_ptr<Bag<ecore::EReference>> _eAllContainments = obj.getEAllContainments();
	m_eAllContainments.reset(new Bag<ecore::EReference>(*(obj.getEAllContainments().get())));

	std::shared_ptr<Bag<ecore::EGenericType>> _eAllGenericSuperTypes = obj.getEAllGenericSuperTypes();
	m_eAllGenericSuperTypes.reset(new Bag<ecore::EGenericType>(*(obj.getEAllGenericSuperTypes().get())));

	std::shared_ptr<Bag<ecore::EOperation>> _eAllOperations = obj.getEAllOperations();
	m_eAllOperations.reset(new Bag<ecore::EOperation>(*(obj.getEAllOperations().get())));

	std::shared_ptr<Bag<ecore::EReference>> _eAllReferences = obj.getEAllReferences();
	m_eAllReferences.reset(new Bag<ecore::EReference>(*(obj.getEAllReferences().get())));

	std::shared_ptr<Bag<ecore::EStructuralFeature>> _eAllStructuralFeatures = obj.getEAllStructuralFeatures();
	m_eAllStructuralFeatures.reset(new Bag<ecore::EStructuralFeature>(*(obj.getEAllStructuralFeatures().get())));

	std::shared_ptr<Bag<ecore::EClass>> _eAllSuperTypes = obj.getEAllSuperTypes();
	m_eAllSuperTypes.reset(new Bag<ecore::EClass>(*(obj.getEAllSuperTypes().get())));

	m_eContainer  = obj.getEContainer();

	m_eIDAttribute  = obj.getEIDAttribute();

	m_ePackage  = obj.getEPackage();

	std::shared_ptr<Bag<ecore::EClass>> _eSuperTypes = obj.getESuperTypes();
	m_eSuperTypes.reset(new Bag<ecore::EClass>(*(obj.getESuperTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAttribute>> _eAttributesList = obj.getEAttributes();
	for(std::shared_ptr<ecore::EAttribute> _eAttributes : *_eAttributesList)
	{
		this->getEAttributes()->add(std::shared_ptr<ecore::EAttribute>(std::dynamic_pointer_cast<ecore::EAttribute>(_eAttributes->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAttributes" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EGenericType>> _eGenericSuperTypesList = obj.getEGenericSuperTypes();
	for(std::shared_ptr<ecore::EGenericType> _eGenericSuperTypes : *_eGenericSuperTypesList)
	{
		this->getEGenericSuperTypes()->add(std::shared_ptr<ecore::EGenericType>(std::dynamic_pointer_cast<ecore::EGenericType>(_eGenericSuperTypes->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericSuperTypes" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EOperation>> _eOperationsList = obj.getEOperations();
	for(std::shared_ptr<ecore::EOperation> _eOperations : *_eOperationsList)
	{
		this->getEOperations()->add(std::shared_ptr<ecore::EOperation>(std::dynamic_pointer_cast<ecore::EOperation>(_eOperations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eOperations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EReference>> _eReferencesList = obj.getEReferences();
	for(std::shared_ptr<ecore::EReference> _eReferences : *_eReferencesList)
	{
		this->getEReferences()->add(std::shared_ptr<ecore::EReference>(std::dynamic_pointer_cast<ecore::EReference>(_eReferences->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eReferences" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(std::dynamic_pointer_cast<ecore::ETypeParameter>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif

	

	/*Subset*/
	m_eOperations->initSubset(getEContens());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eOperations - Subset<ecore::EOperation, ecore::EObject >(getEContens())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  EClassImpl::copy() const
{
	std::shared_ptr<EClassImpl> element(new EClassImpl(*this));
	element->setThisEClassPtr(element);
	return element;
}

std::shared_ptr<EClass> EClassImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEClass_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute abstract
*/
bool EClassImpl::isAbstract() const 
{
	return m_abstract;
}

void EClassImpl::setAbstract(bool _abstract)
{
	m_abstract = _abstract;
} 



/*
Getter & Setter for attribute interface
*/
bool EClassImpl::isInterface() const 
{
	return m_interface;
}

void EClassImpl::setInterface(bool _interface)
{
	m_interface = _interface;
} 



//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EOperation> EClassImpl::getEOperation(int operationID) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<ecore::EOperation> > eAllOps = getEAllOperations();
    return operationID >=0 && operationID < (int) eAllOps->size() ? eAllOps->at(operationID): nullptr;
	//end of body
}

std::shared_ptr<ecore::EStructuralFeature> EClassImpl::getEStructuralFeature(int featureID) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<ecore::EStructuralFeature> >  eAllFeat = getEAllStructuralFeatures();
    return featureID >=0 && featureID < (int) eAllFeat->size() ? eAllFeat->at(featureID): nullptr;
	//end of body
}

std::shared_ptr<ecore::EStructuralFeature> EClassImpl::getEStructuralFeature(std::string featureName) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<Bag<EStructuralFeature > > eAllFeat = getEAllStructuralFeatures();
    for(std::shared_ptr<EStructuralFeature> f: *eAllFeat)
    {
        if(f->getName()==featureName)
        {
            return f;
        }
    }

    return nullptr;
	//end of body
}

int EClassImpl::getFeatureCount() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return getEAllStructuralFeatures()->size();
	//end of body
}

int EClassImpl::getFeatureID(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<Bag<EStructuralFeature > > eAllFeat = getEAllStructuralFeatures();
    int index = feature->getFeatureID();
    
    if(index != -1)
    {
        index = 0;
        Bag<EStructuralFeature > ::iterator iter = eAllFeat->begin();
        while (iter != eAllFeat->end())
        {
           if (feature == *iter)
           {
               return index;
           }
           index++;
           iter++;
        }
    }
    return -1;
	//end of body
}

std::shared_ptr<ecore::EGenericType> EClassImpl::getFeatureType(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int EClassImpl::getOperationCount() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return getEAllOperations()->size();
	//end of body
}

int EClassImpl::getOperationID(std::shared_ptr<ecore::EOperation>  operation) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr< Bag<ecore::EOperation> > eAllOps = getEAllOperations();
    int index = operation->getOperationID();
    
    if(index != -1)
    {
        index = 0;
        Bag<ecore::EOperation >::iterator iter = eAllOps->begin();
        while (iter != eAllOps->end())
        {
           if (operation == *iter)
           {
               return index;
           }
           index++;
           iter++;
        }
    }
    return -1;
	//end of body
}

std::shared_ptr<ecore::EOperation> EClassImpl::getOverride(std::shared_ptr<ecore::EOperation>  operation) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EClassImpl::isSuperTypeOf(std::shared_ptr<ecore::EClass>  someClass) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr< Bag<ecore::EClass > > list = someClass->getEAllSuperTypes();

    Bag< ecore::EClass > ::iterator i=list->begin();
    Bag< ecore::EClass > ::iterator endIter=list->end();

    while (i!=endIter)
    {
	    if ((*i).get()==this) return true;
	    ++i;
    }

    return someClass.get() == this;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference eAllAttributes
*/
std::shared_ptr<Bag<ecore::EAttribute>> EClassImpl::getEAllAttributes() const
{
	//generated from getterbody annotation
    std::shared_ptr<Bag<ecore::EAttribute> > eAllAttributes(new Bag<ecore::EAttribute>());

    std::shared_ptr<Bag<ecore::EAttribute> > attributeList = this->getEAttributes();
    eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass> c : *classList)
    {
        std::shared_ptr<Bag<EAttribute> > attributeList = c->getEAllAttributes();
        eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    }
    return eAllAttributes;
	//end of body
}





/*
Getter & Setter for reference eAllContainments
*/
std::shared_ptr<Bag<ecore::EReference>> EClassImpl::getEAllContainments() const
{
	if(m_eAllContainments == nullptr)
	{
		m_eAllContainments.reset(new Bag<ecore::EReference>());
		
		
	}

    return m_eAllContainments;
}





/*
Getter & Setter for reference eAllGenericSuperTypes
*/
std::shared_ptr<Bag<ecore::EGenericType>> EClassImpl::getEAllGenericSuperTypes() const
{
	if(m_eAllGenericSuperTypes == nullptr)
	{
		m_eAllGenericSuperTypes.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eAllGenericSuperTypes;
}





/*
Getter & Setter for reference eAllOperations
*/
std::shared_ptr<Bag<ecore::EOperation>> EClassImpl::getEAllOperations() const
{
	//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EOperation> > eAllOperations(new Bag<ecore::EOperation> () );

    std::shared_ptr<Bag<ecore::EOperation> > operationList = this->getEOperations();
    eAllOperations->insert(eAllOperations->end(), operationList->begin(), operationList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr< Bag< EOperation> > operationList = c->getEAllOperations();
        eAllOperations->insert(eAllOperations->end(), operationList->begin(), operationList->end());
    }
    return eAllOperations;
	//end of body
}





/*
Getter & Setter for reference eAllReferences
*/
std::shared_ptr<Bag<ecore::EReference>> EClassImpl::getEAllReferences() const
{
	//generated from getterbody annotation
    std::shared_ptr<Bag<ecore::EReference> > eAllReferences(new Bag<ecore::EReference>());

    std::shared_ptr<Bag<ecore::EReference> > referenceList = this->getEReferences();
    eAllReferences->insert(eAllReferences->end(), referenceList->begin(), referenceList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass> c : *classList)
    {
        std::shared_ptr<Bag<EReference> > referenceList = c->getEAllReferences();
        eAllReferences->insert(eAllReferences->end(), referenceList->begin(), referenceList->end());
    }
    return eAllReferences;
	//end of body
}





/*
Getter & Setter for reference eAllStructuralFeatures
*/
std::shared_ptr<Bag<ecore::EStructuralFeature>> EClassImpl::getEAllStructuralFeatures() const
{
	//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EStructuralFeature> > eAllStructuralFeatures( new Bag<ecore::EStructuralFeature> ());

    std::shared_ptr< Bag< EStructuralFeature> > featureList = this->getEStructuralFeatures();
    eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<Bag<EStructuralFeature> > featureList = c->getEAllStructuralFeatures();
        eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    }
    return eAllStructuralFeatures;
	//end of body
}





/*
Getter & Setter for reference eAllSuperTypes
*/
std::shared_ptr<Bag<ecore::EClass>> EClassImpl::getEAllSuperTypes() const
{
	//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EClass> > eAllSuperTypes(new Bag<ecore::EClass>  ());

	std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<Bag<EClass> > classList = c->getEAllSuperTypes();
        eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    }
    return eAllSuperTypes;
	//end of body
}





/*
Getter & Setter for reference eAttributes
*/
std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> EClassImpl::getEAttributes() const
{
	if(m_eAttributes == nullptr)
	{
		/*Subset*/
		m_eAttributes.reset(new Subset<ecore::EAttribute, ecore::EStructuralFeature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAttributes - Subset<ecore::EAttribute, ecore::EStructuralFeature >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eAttributes->initSubset(getEStructuralFeatures());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAttributes - Subset<ecore::EAttribute, ecore::EStructuralFeature >(getEStructuralFeatures())" << std::endl;
		#endif
		
	}

    return m_eAttributes;
}





/*
Getter & Setter for reference eGenericSuperTypes
*/
std::shared_ptr<Bag<ecore::EGenericType>> EClassImpl::getEGenericSuperTypes() const
{
	if(m_eGenericSuperTypes == nullptr)
	{
		m_eGenericSuperTypes.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eGenericSuperTypes;
}





/*
Getter & Setter for reference eIDAttribute
*/
std::shared_ptr<ecore::EAttribute > EClassImpl::getEIDAttribute() const
{

    return m_eIDAttribute;
}

void EClassImpl::setEIDAttribute(std::shared_ptr<ecore::EAttribute> _eIDAttribute)
{
    m_eIDAttribute = _eIDAttribute;
}



/*
Getter & Setter for reference eOperations
*/
std::shared_ptr<Subset<ecore::EOperation, ecore::EObject>> EClassImpl::getEOperations() const
{
	if(m_eOperations == nullptr)
	{
		/*Subset*/
		m_eOperations.reset(new Subset<ecore::EOperation, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eOperations - Subset<ecore::EOperation, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eOperations->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eOperations - Subset<ecore::EOperation, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eOperations;
}





/*
Getter & Setter for reference eReferences
*/
std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> EClassImpl::getEReferences() const
{
	if(m_eReferences == nullptr)
	{
		/*Subset*/
		m_eReferences.reset(new Subset<ecore::EReference, ecore::EStructuralFeature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eReferences - Subset<ecore::EReference, ecore::EStructuralFeature >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eReferences->initSubset(getEStructuralFeatures());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eReferences - Subset<ecore::EReference, ecore::EStructuralFeature >(getEStructuralFeatures())" << std::endl;
		#endif
		
	}

    return m_eReferences;
}





/*
Getter & Setter for reference eStructuralFeatures
*/






/*
Getter & Setter for reference eSuperTypes
*/
std::shared_ptr<Bag<ecore::EClass>> EClassImpl::getESuperTypes() const
{
	if(m_eSuperTypes == nullptr)
	{
		m_eSuperTypes.reset(new Bag<ecore::EClass>());
		
		
	}

    return m_eSuperTypes;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EClassImpl::getEContens() const
{
	if(m_eContens == nullptr)
	{
		/*Union*/
		m_eContens.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContens - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContens;
}

std::shared_ptr<SubsetUnion<ecore::EStructuralFeature, ecore::EObject>> EClassImpl::getEStructuralFeatures() const
{
	if(m_eStructuralFeatures == nullptr)
	{
		/*SubsetUnion*/
		m_eStructuralFeatures.reset(new SubsetUnion<ecore::EStructuralFeature, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_eStructuralFeatures - SubsetUnion<ecore::EStructuralFeature, ecore::EObject >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_eStructuralFeatures->initSubsetUnion(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_eStructuralFeatures - SubsetUnion<ecore::EStructuralFeature, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}
	return m_eStructuralFeatures;
}




std::shared_ptr<EClass> EClassImpl::getThisEClassPtr() const
{
	return m_thisEClassPtr.lock();
}
void EClassImpl::setThisEClassPtr(std::weak_ptr<EClass> thisEClassPtr)
{
	m_thisEClassPtr = thisEClassPtr;
	setThisEClassifierPtr(thisEClassPtr);
}
std::shared_ptr<ecore::EObject> EClassImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EClassImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ABSTRACT:
			return eAny(isAbstract()); //1211
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLATTRIBUTES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EAttribute>::iterator iter = m_eAllAttributes->begin();
			Bag<ecore::EAttribute>::iterator end = m_eAllAttributes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1215
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLCONTAINMENTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EReference>::iterator iter = m_eAllContainments->begin();
			Bag<ecore::EReference>::iterator end = m_eAllContainments->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1219
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLGENERICSUPERTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EGenericType>::iterator iter = m_eAllGenericSuperTypes->begin();
			Bag<ecore::EGenericType>::iterator end = m_eAllGenericSuperTypes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1226
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLOPERATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EOperation>::iterator iter = m_eAllOperations->begin();
			Bag<ecore::EOperation>::iterator end = m_eAllOperations->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1220
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLREFERENCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EReference>::iterator iter = m_eAllReferences->begin();
			Bag<ecore::EReference>::iterator end = m_eAllReferences->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1216
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLSTRUCTURALFEATURES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EStructuralFeature>::iterator iter = m_eAllStructuralFeatures->begin();
			Bag<ecore::EStructuralFeature>::iterator end = m_eAllStructuralFeatures->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1221
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLSUPERTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EClass>::iterator iter = m_eAllSuperTypes->begin();
			Bag<ecore::EClass>::iterator end = m_eAllSuperTypes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1222
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EATTRIBUTES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EAttribute>::iterator iter = m_eAttributes->begin();
			Bag<ecore::EAttribute>::iterator end = m_eAttributes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1218
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EGENERICSUPERTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EGenericType>::iterator iter = m_eGenericSuperTypes->begin();
			Bag<ecore::EGenericType>::iterator end = m_eGenericSuperTypes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1225
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EIDATTRIBUTE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEIDAttribute())); //1223
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EOPERATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EOperation>::iterator iter = m_eOperations->begin();
			Bag<ecore::EOperation>::iterator end = m_eOperations->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1214
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EREFERENCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EReference>::iterator iter = m_eReferences->begin();
			Bag<ecore::EReference>::iterator end = m_eReferences->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1217
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EStructuralFeature>::iterator iter = m_eStructuralFeatures->begin();
			Bag<ecore::EStructuralFeature>::iterator end = m_eStructuralFeatures->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1224
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESUPERTYPES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EClass>::iterator iter = m_eSuperTypes->begin();
			Bag<ecore::EClass>::iterator end = m_eSuperTypes->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1213
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_INTERFACE:
			return eAny(isInterface()); //1212
	}
	return EClassifierImpl::eGet(featureID, resolve, coreType);
}
bool EClassImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ABSTRACT:
			return isAbstract() != false; //1211
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLATTRIBUTES:
			return getEAllAttributes() != nullptr; //1215
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLCONTAINMENTS:
			return getEAllContainments() != nullptr; //1219
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLGENERICSUPERTYPES:
			return getEAllGenericSuperTypes() != nullptr; //1226
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLOPERATIONS:
			return getEAllOperations() != nullptr; //1220
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLREFERENCES:
			return getEAllReferences() != nullptr; //1216
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLSTRUCTURALFEATURES:
			return getEAllStructuralFeatures() != nullptr; //1221
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EALLSUPERTYPES:
			return getEAllSuperTypes() != nullptr; //1222
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EATTRIBUTES:
			return getEAttributes() != nullptr; //1218
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EGENERICSUPERTYPES:
			return getEGenericSuperTypes() != nullptr; //1225
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EIDATTRIBUTE:
			return getEIDAttribute() != nullptr; //1223
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EOPERATIONS:
			return getEOperations() != nullptr; //1214
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EREFERENCES:
			return getEReferences() != nullptr; //1217
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:
			return getEStructuralFeatures() != nullptr; //1224
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESUPERTYPES:
			return getESuperTypes() != nullptr; //1213
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_INTERFACE:
			return isInterface() != false; //1212
	}
	return EClassifierImpl::internalEIsSet(featureID);
}
bool EClassImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ABSTRACT:
		{
			// BOOST CAST
			bool _abstract = newValue->get<bool>();
			setAbstract(_abstract); //1211
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EATTRIBUTES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EAttribute>> eAttributesList(new Bag<ecore::EAttribute>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eAttributesList->add(std::dynamic_pointer_cast<ecore::EAttribute>(*iter));
				iter++;
			}
			
			Bag<ecore::EAttribute>::iterator iterEAttributes = m_eAttributes->begin();
			Bag<ecore::EAttribute>::iterator endEAttributes = m_eAttributes->end();
			while (iterEAttributes != endEAttributes)
			{
				if (eAttributesList->find(*iterEAttributes) == -1)
				{
					m_eAttributes->erase(*iterEAttributes);
				}
				iterEAttributes++;
			}

			iterEAttributes = eAttributesList->begin();
			endEAttributes = eAttributesList->end();
			while (iterEAttributes != endEAttributes)
			{
				if (m_eAttributes->find(*iterEAttributes) == -1)
				{
					m_eAttributes->add(*iterEAttributes);
				}
				iterEAttributes++;			
			}
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EGENERICSUPERTYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EGenericType>> eGenericSuperTypesList(new Bag<ecore::EGenericType>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eGenericSuperTypesList->add(std::dynamic_pointer_cast<ecore::EGenericType>(*iter));
				iter++;
			}
			
			Bag<ecore::EGenericType>::iterator iterEGenericSuperTypes = m_eGenericSuperTypes->begin();
			Bag<ecore::EGenericType>::iterator endEGenericSuperTypes = m_eGenericSuperTypes->end();
			while (iterEGenericSuperTypes != endEGenericSuperTypes)
			{
				if (eGenericSuperTypesList->find(*iterEGenericSuperTypes) == -1)
				{
					m_eGenericSuperTypes->erase(*iterEGenericSuperTypes);
				}
				iterEGenericSuperTypes++;
			}

			iterEGenericSuperTypes = eGenericSuperTypesList->begin();
			endEGenericSuperTypes = eGenericSuperTypesList->end();
			while (iterEGenericSuperTypes != endEGenericSuperTypes)
			{
				if (m_eGenericSuperTypes->find(*iterEGenericSuperTypes) == -1)
				{
					m_eGenericSuperTypes->add(*iterEGenericSuperTypes);
				}
				iterEGenericSuperTypes++;			
			}
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EIDATTRIBUTE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EAttribute> _eIDAttribute = std::dynamic_pointer_cast<ecore::EAttribute>(_temp);
			setEIDAttribute(_eIDAttribute); //1223
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EOPERATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EOperation>> eOperationsList(new Bag<ecore::EOperation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eOperationsList->add(std::dynamic_pointer_cast<ecore::EOperation>(*iter));
				iter++;
			}
			
			Bag<ecore::EOperation>::iterator iterEOperations = m_eOperations->begin();
			Bag<ecore::EOperation>::iterator endEOperations = m_eOperations->end();
			while (iterEOperations != endEOperations)
			{
				if (eOperationsList->find(*iterEOperations) == -1)
				{
					m_eOperations->erase(*iterEOperations);
				}
				iterEOperations++;
			}

			iterEOperations = eOperationsList->begin();
			endEOperations = eOperationsList->end();
			while (iterEOperations != endEOperations)
			{
				if (m_eOperations->find(*iterEOperations) == -1)
				{
					m_eOperations->add(*iterEOperations);
				}
				iterEOperations++;			
			}
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EREFERENCES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EReference>> eReferencesList(new Bag<ecore::EReference>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eReferencesList->add(std::dynamic_pointer_cast<ecore::EReference>(*iter));
				iter++;
			}
			
			Bag<ecore::EReference>::iterator iterEReferences = m_eReferences->begin();
			Bag<ecore::EReference>::iterator endEReferences = m_eReferences->end();
			while (iterEReferences != endEReferences)
			{
				if (eReferencesList->find(*iterEReferences) == -1)
				{
					m_eReferences->erase(*iterEReferences);
				}
				iterEReferences++;
			}

			iterEReferences = eReferencesList->begin();
			endEReferences = eReferencesList->end();
			while (iterEReferences != endEReferences)
			{
				if (m_eReferences->find(*iterEReferences) == -1)
				{
					m_eReferences->add(*iterEReferences);
				}
				iterEReferences++;			
			}
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EStructuralFeature>> eStructuralFeaturesList(new Bag<ecore::EStructuralFeature>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eStructuralFeaturesList->add(std::dynamic_pointer_cast<ecore::EStructuralFeature>(*iter));
				iter++;
			}
			
			Bag<ecore::EStructuralFeature>::iterator iterEStructuralFeatures = m_eStructuralFeatures->begin();
			Bag<ecore::EStructuralFeature>::iterator endEStructuralFeatures = m_eStructuralFeatures->end();
			while (iterEStructuralFeatures != endEStructuralFeatures)
			{
				if (eStructuralFeaturesList->find(*iterEStructuralFeatures) == -1)
				{
					m_eStructuralFeatures->erase(*iterEStructuralFeatures);
				}
				iterEStructuralFeatures++;
			}

			iterEStructuralFeatures = eStructuralFeaturesList->begin();
			endEStructuralFeatures = eStructuralFeaturesList->end();
			while (iterEStructuralFeatures != endEStructuralFeatures)
			{
				if (m_eStructuralFeatures->find(*iterEStructuralFeatures) == -1)
				{
					m_eStructuralFeatures->add(*iterEStructuralFeatures);
				}
				iterEStructuralFeatures++;			
			}
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESUPERTYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EClass>> eSuperTypesList(new Bag<ecore::EClass>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eSuperTypesList->add(std::dynamic_pointer_cast<ecore::EClass>(*iter));
				iter++;
			}
			
			Bag<ecore::EClass>::iterator iterESuperTypes = m_eSuperTypes->begin();
			Bag<ecore::EClass>::iterator endESuperTypes = m_eSuperTypes->end();
			while (iterESuperTypes != endESuperTypes)
			{
				if (eSuperTypesList->find(*iterESuperTypes) == -1)
				{
					m_eSuperTypes->erase(*iterESuperTypes);
				}
				iterESuperTypes++;
			}

			iterESuperTypes = eSuperTypesList->begin();
			endESuperTypes = eSuperTypesList->end();
			while (iterESuperTypes != endESuperTypes)
			{
				if (m_eSuperTypes->find(*iterESuperTypes) == -1)
				{
					m_eSuperTypes->add(*iterESuperTypes);
				}
				iterESuperTypes++;			
			}
			return true;
		}
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_INTERFACE:
		{
			// BOOST CAST
			bool _interface = newValue->get<bool>();
			setInterface(_interface); //1212
			return true;
		}
	}

	return EClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EClassImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EClassImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("abstract");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setAbstract(value);
		}

		iter = attr_list.find("interface");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setInterface(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eAttributes");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eAttributes")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("eIDAttribute");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eIDAttribute")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("eReferences");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eReferences")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("eSuperTypes");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eSuperTypes")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	EClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void EClassImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::ecoreFactory> modelFactory=ecore::ecoreFactory::eInstance();

	try
	{
		if ( nodeName.compare("eGenericSuperTypes") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			std::shared_ptr<ecore::EGenericType> eGenericSuperTypes = std::dynamic_pointer_cast<ecore::EGenericType>(modelFactory->create(typeName));
			if (eGenericSuperTypes != nullptr)
			{
				std::shared_ptr<Bag<ecore::EGenericType>> list_eGenericSuperTypes = this->getEGenericSuperTypes();
				list_eGenericSuperTypes->push_back(eGenericSuperTypes);
				loadHandler->handleChild(eGenericSuperTypes);
			}
			return;
		}

		if ( nodeName.compare("eOperations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EOperation";
			}
			std::shared_ptr<ecore::EObject> eOperations = modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::ecorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS);
			if (eOperations != nullptr)
			{
				loadHandler->handleChild(eOperations);
			}
			return;
		}

		if ( nodeName.compare("eStructuralFeatures") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> eStructuralFeatures = modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS);
			if (eStructuralFeatures != nullptr)
			{
				loadHandler->handleChild(eStructuralFeatures);
			}
			return;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	EClassifierImpl::loadNode(nodeName, loadHandler);
}

void EClassImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EATTRIBUTES:
		{
			std::shared_ptr<Bag<ecore::EAttribute>> _eAttributes = getEAttributes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EAttribute> _r = std::dynamic_pointer_cast<ecore::EAttribute>(ref);
				if (_r != nullptr)
				{
					_eAttributes->push_back(_r);
				}				
			}
			return;
		}

		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EIDATTRIBUTE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EAttribute> _eIDAttribute = std::dynamic_pointer_cast<ecore::EAttribute>( references.front() );
				setEIDAttribute(_eIDAttribute);
			}
			
			return;
		}

		case ecore::ecorePackage::ECLASS_ATTRIBUTE_EREFERENCES:
		{
			std::shared_ptr<Bag<ecore::EReference>> _eReferences = getEReferences();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EReference> _r = std::dynamic_pointer_cast<ecore::EReference>(ref);
				if (_r != nullptr)
				{
					_eReferences->push_back(_r);
				}				
			}
			return;
		}

		case ecore::ecorePackage::ECLASS_ATTRIBUTE_ESUPERTYPES:
		{
			std::shared_ptr<Bag<ecore::EClass>> _eSuperTypes = getESuperTypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EClass> _r = std::dynamic_pointer_cast<ecore::EClass>(ref);
				if (_r != nullptr)
				{
					_eSuperTypes->push_back(_r);
				}				
			}
			return;
		}
	}
	EClassifierImpl::resolveReferences(featureID, references);
}

void EClassImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EClassifierImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EClassImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();

		// Save 'eOperations'
		for (std::shared_ptr<ecore::EOperation> eOperations : *this->getEOperations()) 
		{
			saveHandler->addReference(eOperations, "eOperations", eOperations->eClass() != package->getEOperation_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getEClass_Attribute_abstract()) )
		{
			saveHandler->addAttribute("abstract", this->isAbstract());
		}

		if ( this->eIsSet(package->getEClass_Attribute_interface()) )
		{
			saveHandler->addAttribute("interface", this->isInterface());
		}

		// Add references
		std::shared_ptr<Bag<ecore::EAttribute>> eAttributes_list = this->getEAttributes();
		for (std::shared_ptr<ecore::EAttribute > object : *eAttributes_list)
		{ 
			saveHandler->addReferences("eAttributes", object);
		}
		saveHandler->addReference("eIDAttribute", this->getEIDAttribute());
		std::shared_ptr<Bag<ecore::EReference>> eReferences_list = this->getEReferences();
		for (std::shared_ptr<ecore::EReference > object : *eReferences_list)
		{ 
			saveHandler->addReferences("eReferences", object);
		}
		std::shared_ptr<Bag<ecore::EClass>> eSuperTypes_list = this->getESuperTypes();
		for (std::shared_ptr<ecore::EClass > object : *eSuperTypes_list)
		{ 
			saveHandler->addReferences("eSuperTypes", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eGenericSuperTypes'
		std::shared_ptr<Bag<ecore::EGenericType>> list_eGenericSuperTypes = this->getEGenericSuperTypes();
		for (std::shared_ptr<ecore::EGenericType> eGenericSuperTypes : *list_eGenericSuperTypes) 
		{
			saveHandler->addReference(eGenericSuperTypes, "eGenericSuperTypes", eGenericSuperTypes->eClass() !=ecore::ecorePackage::eInstance()->getEGenericType_Class());
		}

		// Save 'eStructuralFeatures'
		std::shared_ptr<SubsetUnion<ecore::EStructuralFeature, ecore::EObject>> list_eStructuralFeatures = this->getEStructuralFeatures();
		for (std::shared_ptr<ecore::EStructuralFeature> eStructuralFeatures : *list_eStructuralFeatures) 
		{
			saveHandler->addReference(eStructuralFeatures, "eStructuralFeatures", eStructuralFeatures->eClass() !=ecore::ecorePackage::eInstance()->getEStructuralFeature_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

