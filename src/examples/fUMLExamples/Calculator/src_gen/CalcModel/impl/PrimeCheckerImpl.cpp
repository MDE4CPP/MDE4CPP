#include "CalcModel/impl/PrimeCheckerImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "CalcModel/impl/CalcModelPackageImpl.hpp"
#include "uml/Class.hpp"


//Included from operation "printIsPrime"
#include <iostream>
//Included from operation "printNotPrime"
#include <iostream>


using namespace CalcModel;

//*********************************
// Constructor / Destructor
//*********************************
PrimeCheckerImpl::PrimeCheckerImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("CalcModel::PrimeChecker::divider",[this](){ return eAny(this->getDivider());}));
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("CalcModel::PrimeChecker::number",[this](){ return eAny(this->getNumber());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("CalcModel::PrimeChecker::divider",[this](Any object){this->setDivider(object->get<int>());}));
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("CalcModel::PrimeChecker::number",[this](Any object){this->setNumber(object->get<int>());}));
	
	 

	// init properties without default
	
	

	
}




PrimeCheckerImpl::~PrimeCheckerImpl()
{
}

std::shared_ptr<uml::Class> PrimeCheckerImpl::getMetaClass()
{
	return CalcModelPackageImpl::eInstance()->get_CalcModel_PrimeChecker();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PrimeCheckerImpl::setDivider(int _divider)
{
	m_divider = _divider;
}
int PrimeCheckerImpl::getDivider() const 
{
	return m_divider;
}

void PrimeCheckerImpl::setNumber(int _number)
{
	m_number = _number;
}
int PrimeCheckerImpl::getNumber() const 
{
	return m_number;
}

//*********************************
// Operations
//*********************************
bool PrimeCheckerImpl::divides()
{
	bool isDivisible;

	// Implemented as Function behaviour fbDivides

isDivisible = this->getNumber() % this->getDivider() == 0;

	return isDivisible;
}

bool PrimeCheckerImpl::isNotFinished()
{
	bool isNotFinished;

	// Implemented as Function behaviour fbIsNotFinished

isNotFinished = this->getDivider() <= this->getNumber() / 2;

	return isNotFinished;
}

bool PrimeCheckerImpl::isOdd()
{
	bool isOdd;

	// Implemented as Function behaviour fbIsOdd

isOdd = this->getNumber() % 2 != 0;

	return isOdd;
}

void PrimeCheckerImpl::next()
{

	// Implemented as Function behaviour fbNext

this->setDivider (this->getDivider() + 2);

}

void PrimeCheckerImpl::printIsPrime()
{

	// Implemented as Function behaviour fbPrintIsPrime

std::cout<<"Number is prime"<<std::endl;

}

void PrimeCheckerImpl::printNotPrime()
{

	// Implemented as Function behaviour fbPrintNotPrime

std::cout<<"Number is not prime";

}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any PrimeCheckerImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<Any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return eAny(nullptr);
}

void PrimeCheckerImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<void(Any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void PrimeCheckerImpl::unset(std::shared_ptr<uml::Property> _property)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void()>>::iterator iter = m_unsetterMap.find(qName);
    if(iter != m_unsetterMap.end())
    {
        //invoke the getter function
        iter->second();
    }
}


std::shared_ptr<PrimeChecker> PrimeCheckerImpl::getThisPrimeCheckerPtr()
{
	return m_thisPrimeCheckerPtr.lock();
}
void PrimeCheckerImpl::setThisPrimeCheckerPtr(std::weak_ptr<PrimeChecker> thisPrimeCheckerPtr)
{
	m_thisPrimeCheckerPtr = thisPrimeCheckerPtr;
	setThisClassPtr(thisPrimeCheckerPtr);
}
