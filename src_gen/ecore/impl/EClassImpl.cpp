#include "EClassImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "ecorePackageImpl.hpp"

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
	m_eAllAttributes.reset(new std::vector<std::shared_ptr<ecore::EAttribute>>());
	m_eAllContainments.reset(new std::vector<std::shared_ptr<ecore::EReference>>());
	m_eAllGenericSuperTypes.reset(new std::vector<std::shared_ptr<ecore::EGenericType>>());
	m_eAllOperations.reset(new std::vector<std::shared_ptr<ecore::EOperation>>());
	m_eAllReferences.reset(new std::vector<std::shared_ptr<ecore::EReference>>());
	m_eAllStructuralFeatures.reset(new std::vector<std::shared_ptr<ecore::EStructuralFeature>>());
	m_eAllSuperTypes.reset(new std::vector<std::shared_ptr<ecore::EClass>>());
	m_eAttributes.reset(new std::vector<std::shared_ptr<ecore::EAttribute>>());
	m_eGenericSuperTypes.reset(new std::vector<std::shared_ptr<ecore::EGenericType>>());
	
	m_eOperations.reset(new std::vector<std::shared_ptr<ecore::EOperation>>());
	m_eReferences.reset(new std::vector<std::shared_ptr<ecore::EReference>>());
	m_eStructuralFeatures.reset(new std::vector<std::shared_ptr<ecore::EStructuralFeature>>());
	m_eSuperTypes.reset(new std::vector<std::shared_ptr<ecore::EClass>>());
}

EClassImpl::~EClassImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EClass "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

EClassImpl::EClassImpl(const EClassImpl & obj)
{
	//create copy of all Attributes
	m_abstract = obj.isAbstract();
	m_classifierID = obj.getClassifierID();
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_interface = obj.isInterface();
	m_name = obj.getName();

	//copy references with now containment
	
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAttribute>>> _eAllAttributes = obj.getEAllAttributes();
	this->getEAllAttributes()->insert(this->getEAllAttributes()->end(), _eAllAttributes->begin(), _eAllAttributes->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EReference>>> _eAllContainments = obj.getEAllContainments();
	this->getEAllContainments()->insert(this->getEAllContainments()->end(), _eAllContainments->begin(), _eAllContainments->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EGenericType>>> _eAllGenericSuperTypes = obj.getEAllGenericSuperTypes();
	this->getEAllGenericSuperTypes()->insert(this->getEAllGenericSuperTypes()->end(), _eAllGenericSuperTypes->begin(), _eAllGenericSuperTypes->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EOperation>>> _eAllOperations = obj.getEAllOperations();
	this->getEAllOperations()->insert(this->getEAllOperations()->end(), _eAllOperations->begin(), _eAllOperations->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EReference>>> _eAllReferences = obj.getEAllReferences();
	this->getEAllReferences()->insert(this->getEAllReferences()->end(), _eAllReferences->begin(), _eAllReferences->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EStructuralFeature>>> _eAllStructuralFeatures = obj.getEAllStructuralFeatures();
	this->getEAllStructuralFeatures()->insert(this->getEAllStructuralFeatures()->end(), _eAllStructuralFeatures->begin(), _eAllStructuralFeatures->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EClass>>> _eAllSuperTypes = obj.getEAllSuperTypes();
	this->getEAllSuperTypes()->insert(this->getEAllSuperTypes()->end(), _eAllSuperTypes->begin(), _eAllSuperTypes->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAttribute>>> _eAttributes = obj.getEAttributes();
	this->getEAttributes()->insert(this->getEAttributes()->end(), _eAttributes->begin(), _eAttributes->end());

	m_eIDAttribute  = obj.getEIDAttribute();

	m_ePackage  = obj.getEPackage();

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EReference>>> _eReferences = obj.getEReferences();
	this->getEReferences()->insert(this->getEReferences()->end(), _eReferences->begin(), _eReferences->end());

	std::shared_ptr<std::vector<std::shared_ptr<ecore::EClass>>> _eSuperTypes = obj.getESuperTypes();
	this->getESuperTypes()->insert(this->getESuperTypes()->end(), _eSuperTypes->begin(), _eSuperTypes->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EAnnotation>>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->push_back(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EGenericType>>> _eGenericSuperTypesList = obj.getEGenericSuperTypes();
	for(std::shared_ptr<ecore::EGenericType> _eGenericSuperTypes : *_eGenericSuperTypesList)
	{
		this->getEGenericSuperTypes()->push_back(std::shared_ptr<ecore::EGenericType>(dynamic_cast<ecore::EGenericType*>(_eGenericSuperTypes->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EOperation>>> _eOperationsList = obj.getEOperations();
	for(std::shared_ptr<ecore::EOperation> _eOperations : *_eOperationsList)
	{
		this->getEOperations()->push_back(std::shared_ptr<ecore::EOperation>(dynamic_cast<ecore::EOperation*>(_eOperations->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::EStructuralFeature>>> _eStructuralFeaturesList = obj.getEStructuralFeatures();
	for(std::shared_ptr<ecore::EStructuralFeature> _eStructuralFeatures : *_eStructuralFeaturesList)
	{
		this->getEStructuralFeatures()->push_back(std::shared_ptr<ecore::EStructuralFeature>(dynamic_cast<ecore::EStructuralFeature*>(_eStructuralFeatures->copy())));
	}
	std::shared_ptr<std::vector<std::shared_ptr<ecore::ETypeParameter>>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->push_back(std::shared_ptr<ecore::ETypeParameter>(dynamic_cast<ecore::ETypeParameter*>(_eTypeParameters->copy())));
	}
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
std::shared_ptr<ecore::EOperation>  EClassImpl::getEOperation(int operationID)  const 
{
	//generated from body annotation
	std::shared_ptr< std::vector<std::shared_ptr<EOperation > > > eAllOps = getEAllOperations();
    return operationID >=0 && operationID < (int) eAllOps->size() ? eAllOps->at(operationID): nullptr;
}

std::shared_ptr<ecore::EStructuralFeature>  EClassImpl::getEStructuralFeature(int featureID)  const 
{
	//generated from body annotation
	std::shared_ptr< std::vector<std::shared_ptr<ecore::EStructuralFeature> > > eAllFeat = getEAllStructuralFeatures();
    return featureID >=0 && featureID < (int) eAllFeat->size() ? eAllFeat->at(featureID): nullptr;
}

std::shared_ptr<ecore::EStructuralFeature>  EClassImpl::getEStructuralFeature(std::string featureName)  const 
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

int EClassImpl::getFeatureCount()  const 
{
	//generated from body annotation
	return getEAllStructuralFeatures()->size();
}

int EClassImpl::getFeatureID(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	//generated from body annotation
	    std::shared_ptr<std::vector<std::shared_ptr<EStructuralFeature > > > eAllFeat = getEAllStructuralFeatures();
    int index = feature->getFeatureID();
    
    if(index != -1)
    {
        index = 0;
        std::vector<std::shared_ptr<EStructuralFeature > >::iterator iter = eAllFeat->begin();
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

std::shared_ptr<ecore::EGenericType>  EClassImpl::getFeatureType(std::shared_ptr<ecore::EStructuralFeature>  feature)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int EClassImpl::getOperationCount()  const 
{
	//generated from body annotation
	return getEAllOperations()->size();
}

int EClassImpl::getOperationID(std::shared_ptr<ecore::EOperation>  operation)  const 
{
	//generated from body annotation
	    std::shared_ptr< std::vector<std::shared_ptr<ecore::EOperation> > > eAllOps = getEAllOperations();
    int index = operation->getOperationID();
    
    if(index != -1)
    {
        index = 0;
        std::vector<std::shared_ptr<ecore::EOperation > >::iterator iter = eAllOps->begin();
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

std::shared_ptr<ecore::EOperation>  EClassImpl::getOverride(std::shared_ptr<ecore::EOperation>  operation)  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EClassImpl::isSuperTypeOf(std::shared_ptr<ecore::EClass>  someClass)  const 
{
	//generated from body annotation
		std::shared_ptr< std::vector<std::shared_ptr< ecore::EClass > > > list = someClass->getEAllSuperTypes();

    std::vector<std::shared_ptr< ecore::EClass > >::iterator i=list->begin();
    std::vector<std::shared_ptr< ecore::EClass > >::iterator endIter=list->end();

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
std::shared_ptr<std::vector<std::shared_ptr<ecore::EAttribute>>> EClassImpl::getEAllAttributes() const
{

    return m_eAllAttributes;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EReference>>> EClassImpl::getEAllContainments() const
{

    return m_eAllContainments;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EGenericType>>> EClassImpl::getEAllGenericSuperTypes() const
{

    return m_eAllGenericSuperTypes;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EOperation>>> EClassImpl::getEAllOperations() const
{
//generated from getterbody annotation
std::shared_ptr< std::vector<std::shared_ptr<ecore::EOperation> > > eAllOperations(new std::vector<std::shared_ptr<ecore::EOperation> > () );

    std::shared_ptr< std::vector< std::shared_ptr<ecore::EOperation> > > operationList = this->getEOperations();
    eAllOperations->insert(eAllOperations->end(), operationList->begin(), operationList->end());
    std::shared_ptr<std::vector<std::shared_ptr<EClass>>> classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr< std::vector<std::shared_ptr< EOperation> > > operationList = c->getEAllOperations();
        eAllOperations->insert(eAllOperations->end(), operationList->begin(), operationList->end());
    }
    return eAllOperations;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EReference>>> EClassImpl::getEAllReferences() const
{

    return m_eAllReferences;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EStructuralFeature>>> EClassImpl::getEAllStructuralFeatures() const
{
//generated from getterbody annotation
std::shared_ptr< std::vector<std::shared_ptr<ecore::EStructuralFeature> > > eAllStructuralFeatures( new std::vector<std::shared_ptr<ecore::EStructuralFeature> >());

    std::shared_ptr< std::vector<std::shared_ptr< EStructuralFeature> > > featureList = this->getEStructuralFeatures();
    eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    std::shared_ptr<std::vector<std::shared_ptr<EClass>>> classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<std::vector<std::shared_ptr<EStructuralFeature> > > featureList = c->getEStructuralFeatures();
        eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    }
    return eAllStructuralFeatures;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EClass>>> EClassImpl::getEAllSuperTypes() const
{
//generated from getterbody annotation
std::shared_ptr< std::vector<std::shared_ptr<ecore::EClass> > > eAllSuperTypes(new std::vector<std::shared_ptr<ecore::EClass> > ());

	std::shared_ptr<std::vector<std::shared_ptr<EClass>>> classList = this->getESuperTypes();
    eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<std::vector<std::shared_ptr<EClass> > > classList = c->getESuperTypes();
        eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    }
    return eAllSuperTypes;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EAttribute>>> EClassImpl::getEAttributes() const
{

    return m_eAttributes;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EGenericType>>> EClassImpl::getEGenericSuperTypes() const
{

    return m_eGenericSuperTypes;
}


std::shared_ptr<ecore::EAttribute> EClassImpl::getEIDAttribute() const
{

    return m_eIDAttribute;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EOperation>>> EClassImpl::getEOperations() const
{

    return m_eOperations;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EReference>>> EClassImpl::getEReferences() const
{

    return m_eReferences;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EStructuralFeature>>> EClassImpl::getEStructuralFeatures() const
{

    return m_eStructuralFeatures;
}


std::shared_ptr<std::vector<std::shared_ptr<ecore::EClass>>> EClassImpl::getESuperTypes() const
{

    return m_eSuperTypes;
}


//*********************************
// Union Getter
//*********************************


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
