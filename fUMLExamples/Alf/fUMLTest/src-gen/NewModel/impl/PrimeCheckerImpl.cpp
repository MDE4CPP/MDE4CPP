
#include "PrimeCheckerImpl.hpp"
#include <QDebug>

#include "NewModelPackageImpl.hpp"

#include "Class.hpp"
#include <iostream>




namespace NewModel {

//*********************************
// Constructor / Destructor
//*********************************

using boost::any_cast;



PrimeCheckerImpl::PrimeCheckerImpl()
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert("NewModel::PrimeChecker::divider",[this](){ return this->getDivider();});
	m_getterMap.insert("NewModel::PrimeChecker::number",[this](){ return this->getNumber();});
	
	
	m_setterMap.insert("NewModel::PrimeChecker::divider",[this](boost::any object){this->setDivider(any_cast<int>(object));});
	m_setterMap.insert("NewModel::PrimeChecker::number",[this](boost::any object){this->setNumber(any_cast<int>(object));});
	
	
	 

}

PrimeCheckerImpl::~PrimeCheckerImpl()
{
}


uml::Class * PrimeCheckerImpl::getMetaClass()
{

	return NewModelPackageImpl::eInstance()->get_NewModel_PrimeChecker();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PrimeCheckerImpl::setNumber (int _number)
{
	// qDebug() << __PRETTY_FUNCTION__ ;
	m_number = _number;
} 
int PrimeCheckerImpl::getNumber() const 
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	return m_number;
}

void PrimeCheckerImpl::setDivider (int _divider)
{
	// qDebug() << __PRETTY_FUNCTION__ ;
	m_divider = _divider;
} 
int PrimeCheckerImpl::getDivider() const 
{
	//qDebug() << __PRETTY_FUNCTION__ ;
	return m_divider;
}

//*********************************
// Operations
//*********************************
bool PrimeCheckerImpl::divides()
{

	bool isDivisible;

// Implemented as Function behaviour divides


isDivisible = this->getNumber() % this->getDivider() == 0;

return isDivisible;

}

void PrimeCheckerImpl::next()
{


// Implemented as Function behaviour next


this->setDivider (this->getDivider() + 2);
qCritical()<<"DIVIDER:" << this->getDivider();


}

void PrimeCheckerImpl::printIsPrime()
{


// Implemented as Function behaviour printIsPrime


std::cout<<"Number is prime";


}

void PrimeCheckerImpl::printNotPrime()
{


// Implemented as Function behaviour PrintNotPrime


std::cout<<"Number is not prime";


}

bool PrimeCheckerImpl::isOdd()
{

	bool isOdd;

// Implemented as Function behaviour isOdd


isOdd = this->getNumber() % 2 != 0;

return isOdd;

}

bool PrimeCheckerImpl::isNotFinished()
{

	bool isNotFinished;

// Implemented as Function behaviour isNotFinished


isNotFinished = this->getDivider() <= this->getNumber() / 2;

return isNotFinished;

}





//*********************************
// Structural Feature Getter/Setter
//*********************************

boost::any PrimeCheckerImpl::get(uml::Property * _property)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_getterMap.contains(qName))
    {
        //invoke the getter function
        return m_getterMap[qName]();
    }

	return boost::any();
}

void PrimeCheckerImpl::set(uml::Property *  _property,boost::any value)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_setterMap.contains(qName))
    {
        //invoke the getter function
        return m_setterMap[qName](value);
    }

}

void PrimeCheckerImpl::unset(uml::Property *  _property)
{
	//TODO: still two times run through map (contains and [])
	QString qName = _property->getQualifiedName();
    if(m_unsetterMap.contains(qName))
    {
        //invoke the getter function
        return m_unsetterMap[qName]();
    }

}


}

