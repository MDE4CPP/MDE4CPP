
#include "ocl/Expressions/impl/VariableImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/ETypedElement.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IterateExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/VariableExp.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
VariableImpl::VariableImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

VariableImpl::~VariableImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Variable "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


VariableImpl::VariableImpl(const VariableImpl & obj): VariableImpl()
{
	*this = obj;
}

VariableImpl& VariableImpl::operator=(const VariableImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Variable 
	 * which is generated by the compiler (as Variable is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Variable::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Variable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_baseExp  = obj.getBaseExp();
	m_loopExp  = obj.getLoopExp();
	m_referringExp  = obj.getReferringExp();
	m_representedParameter  = obj.getRepresentedParameter();
	m_resultOwner  = obj.getResultOwner();
	m_selfOwner  = obj.getSelfOwner();
	m_value  = obj.getValue();
	m_varOwner  = obj.getVarOwner();
	//Clone references with containment (deep copy)
	//clone reference 'initExpression'
	if(obj.getInitExpression()!=nullptr)
	{
		m_initExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getInitExpression()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> VariableImpl::copy() const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl());
	*element =(*this);
	element->setThisVariablePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference baseExp */
std::shared_ptr<ocl::Expressions::IterateExp> VariableImpl::getBaseExp() const
{
    return m_baseExp;
}
void VariableImpl::setBaseExp(const std::shared_ptr<ocl::Expressions::IterateExp>& _baseExp)
{
    m_baseExp = _baseExp;
	
}

/* Getter & Setter for reference initExpression */
std::shared_ptr<ocl::Expressions::OclExpression> VariableImpl::getInitExpression() const
{
    return m_initExpression;
}
void VariableImpl::setInitExpression(const std::shared_ptr<ocl::Expressions::OclExpression>& _initExpression)
{
    m_initExpression = _initExpression;
	
}

/* Getter & Setter for reference loopExp */
std::shared_ptr<ocl::Expressions::LoopExp> VariableImpl::getLoopExp() const
{
    return m_loopExp;
}
void VariableImpl::setLoopExp(const std::shared_ptr<ocl::Expressions::LoopExp>& _loopExp)
{
    m_loopExp = _loopExp;
	
}

/* Getter & Setter for reference referringExp */
std::shared_ptr<ocl::Expressions::VariableExp> VariableImpl::getReferringExp() const
{
    return m_referringExp;
}
void VariableImpl::setReferringExp(const std::shared_ptr<ocl::Expressions::VariableExp>& _referringExp)
{
    m_referringExp = _referringExp;
	
}

/* Getter & Setter for reference representedParameter */
std::shared_ptr<ecore::EParameter> VariableImpl::getRepresentedParameter() const
{
    return m_representedParameter;
}
void VariableImpl::setRepresentedParameter(const std::shared_ptr<ecore::EParameter>& _representedParameter)
{
    m_representedParameter = _representedParameter;
	
}

/* Getter & Setter for reference resultOwner */
std::shared_ptr<ocl::Expressions::ExpressionInOcl> VariableImpl::getResultOwner() const
{
    return m_resultOwner;
}
void VariableImpl::setResultOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& _resultOwner)
{
    m_resultOwner = _resultOwner;
	
}

/* Getter & Setter for reference selfOwner */
std::shared_ptr<ocl::Expressions::ExpressionInOcl> VariableImpl::getSelfOwner() const
{
    return m_selfOwner;
}
void VariableImpl::setSelfOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& _selfOwner)
{
    m_selfOwner = _selfOwner;
	
}

/* Getter & Setter for reference value */
std::shared_ptr<ecore::ETypedElement> VariableImpl::getValue() const
{
    return m_value;
}
void VariableImpl::setValue(const std::shared_ptr<ecore::ETypedElement>& _value)
{
    m_value = _value;
	
}

/* Getter & Setter for reference varOwner */
std::shared_ptr<ocl::Expressions::ExpressionInOcl> VariableImpl::getVarOwner() const
{
    return m_varOwner;
}
void VariableImpl::setVarOwner(const std::shared_ptr<ocl::Expressions::ExpressionInOcl>& _varOwner)
{
    m_varOwner = _varOwner;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> VariableImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void VariableImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void VariableImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("baseExp");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("baseExp")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("loopExp");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("loopExp")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("referringExp");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referringExp")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("representedParameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("representedParameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("resultOwner");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("resultOwner")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("selfOwner");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("selfOwner")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("value")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("varOwner");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("varOwner")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void VariableImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("initExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getInitExpression()); 

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
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void VariableImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_BASEEXP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::IterateExp> _baseExp = std::dynamic_pointer_cast<ocl::Expressions::IterateExp>( references.front() );
				setBaseExp(_baseExp);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_LOOPEXP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::LoopExp> _loopExp = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>( references.front() );
				setLoopExp(_loopExp);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REFERRINGEXP:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::VariableExp> _referringExp = std::dynamic_pointer_cast<ocl::Expressions::VariableExp>( references.front() );
				setReferringExp(_referringExp);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EParameter> _representedParameter = std::dynamic_pointer_cast<ecore::EParameter>( references.front() );
				setRepresentedParameter(_representedParameter);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_RESULTOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::ExpressionInOcl> _resultOwner = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>( references.front() );
				setResultOwner(_resultOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_SELFOWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::ExpressionInOcl> _selfOwner = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>( references.front() );
				setSelfOwner(_selfOwner);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::ETypedElement> _value = std::dynamic_pointer_cast<ecore::ETypedElement>( references.front() );
				setValue(_value);
			}
			
			return;
		}

		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VAROWNER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::ExpressionInOcl> _varOwner = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>( references.front() );
				setVarOwner(_varOwner);
			}
			
			return;
		}
	}
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void VariableImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void VariableImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getBaseExp(), "baseExp", getBaseExp()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getIterateExp_Class()); 
		saveHandler->addReference(this->getLoopExp(), "loopExp", getLoopExp()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getLoopExp_Class()); 
		saveHandler->addReference(this->getReferringExp(), "referringExp", getReferringExp()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getVariableExp_Class()); 
		saveHandler->addReference(this->getRepresentedParameter(),"representedParameter", getRepresentedParameter()->eClass() != ecore::ecorePackage::eInstance()->getEParameter_Class());
		saveHandler->addReference(this->getResultOwner(), "resultOwner", getResultOwner()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Class()); 
		saveHandler->addReference(this->getSelfOwner(), "selfOwner", getSelfOwner()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Class()); 
		saveHandler->addReference(this->getValue(),"value", getValue()->eClass() != ecore::ecorePackage::eInstance()->getETypedElement_Class());
		saveHandler->addReference(this->getVarOwner(), "varOwner", getVarOwner()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Class()); 
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'initExpression'

		saveHandler->addReference(this->getInitExpression(), "initExpression", getInitExpression()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> VariableImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> VariableImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_BASEEXP:
			return eAny(getBaseExp(),ocl::Expressions::ExpressionsPackage::ITERATEEXP_CLASS,false); //9413
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:
			return eAny(getInitExpression(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //9410
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_LOOPEXP:
			return eAny(getLoopExp(),ocl::Expressions::ExpressionsPackage::LOOPEXP_CLASS,false); //9412
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REFERRINGEXP:
			return eAny(getReferringExp(),ocl::Expressions::ExpressionsPackage::VARIABLEEXP_CLASS,false); //9414
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER:
			return eAny(getRepresentedParameter(),ecore::ecorePackage::EPARAMETER_CLASS,false); //9411
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_RESULTOWNER:
			return eAny(getResultOwner(),ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_CLASS,false); //9416
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_SELFOWNER:
			return eAny(getSelfOwner(),ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_CLASS,false); //9415
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VALUE:
			return eAny(getValue(),ecore::ecorePackage::ETYPEDELEMENT_CLASS,false); //9418
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VAROWNER:
			return eAny(getVarOwner(),ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_CLASS,false); //9417
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool VariableImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_BASEEXP:
			return getBaseExp() != nullptr; //9413
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:
			return getInitExpression() != nullptr; //9410
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_LOOPEXP:
			return getLoopExp() != nullptr; //9412
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REFERRINGEXP:
			return getReferringExp() != nullptr; //9414
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER:
			return getRepresentedParameter() != nullptr; //9411
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_RESULTOWNER:
			return getResultOwner() != nullptr; //9416
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_SELFOWNER:
			return getSelfOwner() != nullptr; //9415
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //9418
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VAROWNER:
			return getVarOwner() != nullptr; //9417
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool VariableImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_BASEEXP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::IterateExp> _baseExp = std::dynamic_pointer_cast<ocl::Expressions::IterateExp>(eObject);
					if(_baseExp)
					{
						setBaseExp(_baseExp); //9413
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'baseExp'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'baseExp'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_INITEXPRESSION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _initExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_initExpression)
					{
						setInitExpression(_initExpression); //9410
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'initExpression'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'initExpression'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_LOOPEXP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::LoopExp> _loopExp = std::dynamic_pointer_cast<ocl::Expressions::LoopExp>(eObject);
					if(_loopExp)
					{
						setLoopExp(_loopExp); //9412
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'loopExp'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'loopExp'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REFERRINGEXP:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::VariableExp> _referringExp = std::dynamic_pointer_cast<ocl::Expressions::VariableExp>(eObject);
					if(_referringExp)
					{
						setReferringExp(_referringExp); //9414
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'referringExp'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'referringExp'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_REPRESENTEDPARAMETER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EParameter> _representedParameter = std::dynamic_pointer_cast<ecore::EParameter>(eObject);
					if(_representedParameter)
					{
						setRepresentedParameter(_representedParameter); //9411
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'representedParameter'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'representedParameter'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_RESULTOWNER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::ExpressionInOcl> _resultOwner = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(eObject);
					if(_resultOwner)
					{
						setResultOwner(_resultOwner); //9416
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'resultOwner'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'resultOwner'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_SELFOWNER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::ExpressionInOcl> _selfOwner = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(eObject);
					if(_selfOwner)
					{
						setSelfOwner(_selfOwner); //9415
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'selfOwner'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'selfOwner'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VALUE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::ETypedElement> _value = std::dynamic_pointer_cast<ecore::ETypedElement>(eObject);
					if(_value)
					{
						setValue(_value); //9418
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'value'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'value'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::VARIABLE_ATTRIBUTE_VAROWNER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::ExpressionInOcl> _varOwner = std::dynamic_pointer_cast<ocl::Expressions::ExpressionInOcl>(eObject);
					if(_varOwner)
					{
						setVarOwner(_varOwner); //9417
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'varOwner'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'varOwner'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> VariableImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::Variable> VariableImpl::getThisVariablePtr() const
{
	return m_thisVariablePtr.lock();
}
void VariableImpl::setThisVariablePtr(std::weak_ptr<ocl::Expressions::Variable> thisVariablePtr)
{
	m_thisVariablePtr = thisVariablePtr;
	setThisETypedElementPtr(thisVariablePtr);
}


