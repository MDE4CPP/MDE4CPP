#include "ecore/impl/EPackageImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EFactory.hpp"

#include "ecore/ENamedElement.hpp"

#include "ecore/EPackage.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EPackageImpl::EPackageImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eClassifiers.reset(new Bag<ecore::EClassifier>());
	
	

	

		m_eSubpackages.reset(new Bag<ecore::EPackage>());
	
	

	

	//Init references
	
	

	

	
	

	
}

EPackageImpl::~EPackageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EPackage "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EPackageImpl::EPackageImpl(std::weak_ptr<ecore::EPackage > par_eSuperPackage)
			:EPackageImpl()
			{
			    m_eSuperPackage = par_eSuperPackage;
			}






EPackageImpl::EPackageImpl(const EPackageImpl & obj):EPackageImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EPackage "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_nsPrefix = obj.getNsPrefix();
	m_nsURI = obj.getNsURI();

	//copy references with no containment (soft copy)
	
	m_eFactoryInstance  = obj.getEFactoryInstance();

	m_eSuperPackage  = obj.getESuperPackage();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EClassifier>> _eClassifiersList = obj.getEClassifiers();
	for(std::shared_ptr<ecore::EClassifier> _eClassifiers : *_eClassifiersList)
	{
		this->getEClassifiers()->add(std::shared_ptr<ecore::EClassifier>(std::dynamic_pointer_cast<ecore::EClassifier>(_eClassifiers->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eClassifiers" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EPackage>> _eSubpackagesList = obj.getESubpackages();
	for(std::shared_ptr<ecore::EPackage> _eSubpackages : *_eSubpackagesList)
	{
		this->getESubpackages()->add(std::shared_ptr<ecore::EPackage>(std::dynamic_pointer_cast<ecore::EPackage>(_eSubpackages->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eSubpackages" << std::endl;
	#endif

	
	

	
	
}

std::shared_ptr<ecore::EObject>  EPackageImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EPackageImpl(*this));
	return element;
}

std::shared_ptr<EClass> EPackageImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEPackage_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EPackageImpl::setNsPrefix(std::string _nsPrefix)
{
	m_nsPrefix = _nsPrefix;
} 

std::string EPackageImpl::getNsPrefix() const 
{
	return m_nsPrefix;
}

void EPackageImpl::setNsURI(std::string _nsURI)
{
	m_nsURI = _nsURI;
} 

std::string EPackageImpl::getNsURI() const 
{
	return m_nsURI;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EClassifier> EPackageImpl::getEClassifier(std::string name)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<EClassifier> > classifierList = getEClassifiers();
    for (std::shared_ptr<EClassifier> c : *classifierList)
    {
        if(c->getName()==name)
        {
            return c;
        }
    }
    return std::shared_ptr<ecore::EClassifier>();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EClassifier> > EPackageImpl::getEClassifiers() const
{

    return m_eClassifiers;
}


std::shared_ptr<ecore::EFactory > EPackageImpl::getEFactoryInstance() const
{
//assert(m_eFactoryInstance);
    return m_eFactoryInstance;
}
void EPackageImpl::setEFactoryInstance(std::shared_ptr<ecore::EFactory> _eFactoryInstance)
{
    m_eFactoryInstance = _eFactoryInstance;
}

std::shared_ptr< Bag<ecore::EPackage> > EPackageImpl::getESubpackages() const
{

    return m_eSubpackages;
}


std::weak_ptr<ecore::EPackage > EPackageImpl::getESuperPackage() const
{

    return m_eSuperPackage;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EPackageImpl::eContainer() const
{
	if(auto wp = m_eSuperPackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EPackageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //120
		case EcorePackage::EPACKAGE_EREFERENCE_ECLASSIFIERS:
			return getEClassifiers(); //125
		case EcorePackage::EPACKAGE_EREFERENCE_EFACTORYINSTANCE:
			return getEFactoryInstance(); //124
		case EcorePackage::EPACKAGE_EREFERENCE_ESUBPACKAGES:
			return getESubpackages(); //126
		case EcorePackage::EPACKAGE_EREFERENCE_ESUPERPACKAGE:
			return getESuperPackage(); //127
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //121
		case EcorePackage::EPACKAGE_EATTRIBUTE_NSPREFIX:
			return getNsPrefix(); //123
		case EcorePackage::EPACKAGE_EATTRIBUTE_NSURI:
			return getNsURI(); //122
	}
	return boost::any();
}

void EPackageImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EPACKAGE_EREFERENCE_EFACTORYINSTANCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EFactory> _eFactoryInstance = boost::any_cast<std::shared_ptr<ecore::EFactory>>(newValue);
			setEFactoryInstance(_eFactoryInstance); //124
			break;
		}
		case EcorePackage::ENAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //121
			break;
		}
		case EcorePackage::EPACKAGE_EATTRIBUTE_NSPREFIX:
		{
			// BOOST CAST
			std::string _nsPrefix = boost::any_cast<std::string>(newValue);
			setNsPrefix(_nsPrefix); //123
			break;
		}
		case EcorePackage::EPACKAGE_EATTRIBUTE_NSURI:
		{
			// BOOST CAST
			std::string _nsURI = boost::any_cast<std::string>(newValue);
			setNsURI(_nsURI); //122
			break;
		}
	}
}
