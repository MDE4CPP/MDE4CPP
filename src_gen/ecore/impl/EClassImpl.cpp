#include "EClassImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp";

#include "EAttribute.hpp";

#include "EClass.hpp";

#include "EClassifier.hpp";

#include "EGenericType.hpp";

#include "EOperation.hpp";

#include "EPackage.hpp";

#include "EReference.hpp";

#include "EStructuralFeature.hpp";

#include "ETypeParameter.hpp";


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EClassImpl::EClassImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eAllAttributes.reset(new Bag<ecore::EAttribute>());
	
	

		m_eAllContainments.reset(new Bag<ecore::EReference>());
	
	

		m_eAllGenericSuperTypes.reset(new Bag<ecore::EGenericType>());
	
	

		m_eAllOperations.reset(new Bag<ecore::EOperation>());
	
	

		m_eAllReferences.reset(new Bag<ecore::EReference>());
	
	

		m_eAllStructuralFeatures.reset(new Bag<ecore::EStructuralFeature>());
	
	

		m_eAllSuperTypes.reset(new Bag<ecore::EClass>());
	
	

		/*Subset*/
		m_eAttributes.reset(new Subset<ecore::EAttribute, ecore::EStructuralFeature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAttributes - Subset<ecore::EAttribute, ecore::EStructuralFeature >()" << std::endl;
		#endif
	
	

		m_eGenericSuperTypes.reset(new Bag<ecore::EGenericType>());
	
	

	

		m_eOperations.reset(new Bag<ecore::EOperation>());
	
	

		/*Subset*/
		m_eReferences.reset(new Subset<ecore::EReference, ecore::EStructuralFeature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eReferences - Subset<ecore::EReference, ecore::EStructuralFeature >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_eStructuralFeatures.reset(new Union<ecore::EStructuralFeature>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eStructuralFeatures - Union<ecore::EStructuralFeature>()" << std::endl;
		#endif
	
	

		m_eSuperTypes.reset(new Bag<ecore::EClass>());
	
	

	//Init references
	
	

	
	

	
	

	
	

	
	

	
	

	
	

		/*Subset*/
		m_eAttributes->initSubset(m_eStructuralFeatures);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAttributes - Subset<ecore::EAttribute, ecore::EStructuralFeature >(m_eStructuralFeatures)" << std::endl;
		#endif
	
	

	
	

	

	
	

		/*Subset*/
		m_eReferences->initSubset(m_eStructuralFeatures);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eReferences - Subset<ecore::EReference, ecore::EStructuralFeature >(m_eStructuralFeatures)" << std::endl;
		#endif
	
	

	
	

	
	
}

EClassImpl::~EClassImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EClass "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EClassImpl::EClassImpl(const EClassImpl & obj):EClassImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EClass "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_abstract = obj.isAbstract();
	m_classifierID = obj.getClassifierID();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_interface = obj.isInterface();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<ecore::EAttribute> >
	 _eAllAttributes = obj.getEAllAttributes();
	m_eAllAttributes.reset(new 	 Bag<ecore::EAttribute> 
	(*(obj.getEAllAttributes().get())));

		std::shared_ptr< Bag<ecore::EReference> >
	 _eAllContainments = obj.getEAllContainments();
	m_eAllContainments.reset(new 	 Bag<ecore::EReference> 
	(*(obj.getEAllContainments().get())));

		std::shared_ptr< Bag<ecore::EGenericType> >
	 _eAllGenericSuperTypes = obj.getEAllGenericSuperTypes();
	m_eAllGenericSuperTypes.reset(new 	 Bag<ecore::EGenericType> 
	(*(obj.getEAllGenericSuperTypes().get())));

		std::shared_ptr< Bag<ecore::EOperation> >
	 _eAllOperations = obj.getEAllOperations();
	m_eAllOperations.reset(new 	 Bag<ecore::EOperation> 
	(*(obj.getEAllOperations().get())));

		std::shared_ptr< Bag<ecore::EReference> >
	 _eAllReferences = obj.getEAllReferences();
	m_eAllReferences.reset(new 	 Bag<ecore::EReference> 
	(*(obj.getEAllReferences().get())));

		std::shared_ptr< Bag<ecore::EStructuralFeature> >
	 _eAllStructuralFeatures = obj.getEAllStructuralFeatures();
	m_eAllStructuralFeatures.reset(new 	 Bag<ecore::EStructuralFeature> 
	(*(obj.getEAllStructuralFeatures().get())));

		std::shared_ptr< Bag<ecore::EClass> >
	 _eAllSuperTypes = obj.getEAllSuperTypes();
	m_eAllSuperTypes.reset(new 	 Bag<ecore::EClass> 
	(*(obj.getEAllSuperTypes().get())));

	m_eIDAttribute  = obj.getEIDAttribute();

	m_ePackage  = obj.getEPackage();

		std::shared_ptr< Bag<ecore::EClass> >
	 _eSuperTypes = obj.getESuperTypes();
	m_eSuperTypes.reset(new 	 Bag<ecore::EClass> 
	(*(obj.getESuperTypes().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAttribute>> _eAttributesList = obj.getEAttributes();
	for(std::shared_ptr<ecore::EAttribute> _eAttributes : *_eAttributesList)
	{
		this->getEAttributes()->add(std::shared_ptr<ecore::EAttribute>(dynamic_cast<ecore::EAttribute*>(_eAttributes->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAttributes" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EGenericType>> _eGenericSuperTypesList = obj.getEGenericSuperTypes();
	for(std::shared_ptr<ecore::EGenericType> _eGenericSuperTypes : *_eGenericSuperTypesList)
	{
		this->getEGenericSuperTypes()->add(std::shared_ptr<ecore::EGenericType>(dynamic_cast<ecore::EGenericType*>(_eGenericSuperTypes->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericSuperTypes" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EOperation>> _eOperationsList = obj.getEOperations();
	for(std::shared_ptr<ecore::EOperation> _eOperations : *_eOperationsList)
	{
		this->getEOperations()->add(std::shared_ptr<ecore::EOperation>(dynamic_cast<ecore::EOperation*>(_eOperations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eOperations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EReference>> _eReferencesList = obj.getEReferences();
	for(std::shared_ptr<ecore::EReference> _eReferences : *_eReferencesList)
	{
		this->getEReferences()->add(std::shared_ptr<ecore::EReference>(dynamic_cast<ecore::EReference*>(_eReferences->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eReferences" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(dynamic_cast<ecore::ETypeParameter*>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif

	
	

	
	

}

ecore::EObject *  EClassImpl::copy() const
{
	return new EClassImpl(*this);
}

std::shared_ptr<EClass> EClassImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEClass();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void EClassImpl::setAbstract (bool _abstract)
{
	m_abstract = _abstract;
} 

bool EClassImpl::isAbstract() const 
{
	return m_abstract;
}

void EClassImpl::setInterface (bool _interface)
{
	m_interface = _interface;
} 

bool EClassImpl::isInterface() const 
{
	return m_interface;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EOperation> 
 EClassImpl::getEOperation(int operationID)  const 
{
	//generated from body annotation
	std::shared_ptr< Bag<ecore::EOperation> > eAllOps = getEAllOperations();
    return operationID >=0 && operationID < (int) eAllOps->size() ? eAllOps->at(operationID): nullptr;
}

std::shared_ptr<ecore::EStructuralFeature> 
 EClassImpl::getEStructuralFeature(int featureID)  const 
{
	//generated from body annotation
	std::shared_ptr< Bag<ecore::EStructuralFeature> >  eAllFeat = getEAllStructuralFeatures();
    return featureID >=0 && featureID < (int) eAllFeat->size() ? eAllFeat->at(featureID): nullptr;
}

std::shared_ptr<ecore::EStructuralFeature> 
 EClassImpl::getEStructuralFeature(std::string featureName)  const 
{
	//generated from body annotation
	    for(std::shared_ptr<EStructuralFeature> f: *getEAllStructuralFeatures())
    {
        if(f->getName()==featureName)
        {
            return f;
        }
    }

    return nullptr;
}

int
 EClassImpl::getFeatureCount()  const 
{
	//generated from body annotation
	return getEAllStructuralFeatures()->size();
}

int
 EClassImpl::getFeatureID(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
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
}

std::shared_ptr<ecore::EGenericType> 
 EClassImpl::getFeatureType(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int
 EClassImpl::getOperationCount()  const 
{
	//generated from body annotation
	return getEAllOperations()->size();
}

int
 EClassImpl::getOperationID(std::shared_ptr<ecore::EOperation>  operation)  const 
{
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
}

std::shared_ptr<ecore::EOperation> 
 EClassImpl::getOverride(std::shared_ptr<ecore::EOperation>  operation)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 EClassImpl::isSuperTypeOf(std::shared_ptr<ecore::EClass>  someClass)  const 
{
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
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<ecore::EAttribute> >
 EClassImpl::getEAllAttributes() const
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
}


	std::shared_ptr< Bag<ecore::EReference> >
 EClassImpl::getEAllContainments() const
{

    return m_eAllContainments;
}


	std::shared_ptr< Bag<ecore::EGenericType> >
 EClassImpl::getEAllGenericSuperTypes() const
{

    return m_eAllGenericSuperTypes;
}


	std::shared_ptr< Bag<ecore::EOperation> >
 EClassImpl::getEAllOperations() const
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
}


	std::shared_ptr< Bag<ecore::EReference> >
 EClassImpl::getEAllReferences() const
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
}


	std::shared_ptr< Bag<ecore::EStructuralFeature> >
 EClassImpl::getEAllStructuralFeatures() const
{
//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EStructuralFeature> > eAllStructuralFeatures( new Bag<ecore::EStructuralFeature> ());

    std::shared_ptr< Bag< EStructuralFeature> > featureList = this->getEStructuralFeatures();
    eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<Bag<EStructuralFeature> > featureList = c->getEStructuralFeatures();
        eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    }
    return eAllStructuralFeatures;
}


	std::shared_ptr< Bag<ecore::EClass> >
 EClassImpl::getEAllSuperTypes() const
{
//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EClass> > eAllSuperTypes(new Bag<ecore::EClass>  ());

	std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<Bag<EClass> > classList = c->getESuperTypes();
        eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    }
    return eAllSuperTypes;
}


		std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature > >
 EClassImpl::getEAttributes() const
{

    return m_eAttributes;
}


	std::shared_ptr< Bag<ecore::EGenericType> >
 EClassImpl::getEGenericSuperTypes() const
{

    return m_eGenericSuperTypes;
}


std::shared_ptr<ecore::EAttribute > EClassImpl::getEIDAttribute() const
{

    return m_eIDAttribute;
}


	std::shared_ptr< Bag<ecore::EOperation> >
 EClassImpl::getEOperations() const
{

    return m_eOperations;
}


		std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature > >
 EClassImpl::getEReferences() const
{

    return m_eReferences;
}





	std::shared_ptr< Bag<ecore::EClass> >
 EClassImpl::getESuperTypes() const
{

    return m_eSuperTypes;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<ecore::EStructuralFeature> > EClassImpl::getEStructuralFeatures() const
{
	return m_eStructuralFeatures;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EClassImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASS_ABSTRACT:
			return isAbstract(); //29
		case EcorePackage::ECLASSIFIER_CLASSIFIERID:
			return getClassifierID(); //25
		case EcorePackage::ECLASSIFIER_DEFAULTVALUE:
			return getDefaultValue(); //24
		case EcorePackage::ECLASS_EALLATTRIBUTES:
			return getEAllAttributes(); //213
		case EcorePackage::ECLASS_EALLCONTAINMENTS:
			return getEAllContainments(); //217
		case EcorePackage::ECLASS_EALLGENERICSUPERTYPES:
			return getEAllGenericSuperTypes(); //224
		case EcorePackage::ECLASS_EALLOPERATIONS:
			return getEAllOperations(); //218
		case EcorePackage::ECLASS_EALLREFERENCES:
			return getEAllReferences(); //214
		case EcorePackage::ECLASS_EALLSTRUCTURALFEATURES:
			return getEAllStructuralFeatures(); //219
		case EcorePackage::ECLASS_EALLSUPERTYPES:
			return getEAllSuperTypes(); //220
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //20
		case EcorePackage::ECLASS_EATTRIBUTES:
			return getEAttributes(); //216
		case EcorePackage::ECLASS_EGENERICSUPERTYPES:
			return getEGenericSuperTypes(); //223
		case EcorePackage::ECLASS_EIDATTRIBUTE:
			return getEIDAttribute(); //221
		case EcorePackage::ECLASS_EOPERATIONS:
			return getEOperations(); //212
		case EcorePackage::ECLASSIFIER_EPACKAGE:
			return getEPackage(); //27
		case EcorePackage::ECLASS_EREFERENCES:
			return getEReferences(); //215
		case EcorePackage::ECLASS_ESTRUCTURALFEATURES:
			return getEStructuralFeatures(); //222
		case EcorePackage::ECLASS_ESUPERTYPES:
			return getESuperTypes(); //211
		case EcorePackage::ECLASSIFIER_ETYPEPARAMETERS:
			return getETypeParameters(); //28
		case EcorePackage::ECLASSIFIER_INSTANCECLASS:
			return getInstanceClass(); //23
		case EcorePackage::ECLASSIFIER_INSTANCECLASSNAME:
			return getInstanceClassName(); //22
		case EcorePackage::ECLASSIFIER_INSTANCETYPENAME:
			return getInstanceTypeName(); //26
		case EcorePackage::ECLASS_INTERFACE:
			return isInterface(); //210
		case EcorePackage::ENAMEDELEMENT_NAME:
			return getName(); //21
	}
	return boost::any();
}
