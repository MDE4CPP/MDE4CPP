#include "fUML/impl/FeatureValueImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/FUMLFactory.hpp"
#include "uml/StructuralFeature.hpp"


//Forward declaration includes
#include "fUML/FeatureValue.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FeatureValueImpl::FeatureValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_values.reset(new Bag<fUML::Value>());
	
	

	//Init references
	

	
	
}

FeatureValueImpl::~FeatureValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FeatureValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




FeatureValueImpl::FeatureValueImpl(const FeatureValueImpl & obj):FeatureValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FeatureValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_position = obj.getPosition();

	//copy references with no containment (soft copy)
	
	m_feature  = obj.getFeature();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Value>> _valuesList = obj.getValues();
	for(std::shared_ptr<fUML::Value> _values : *_valuesList)
	{
		this->getValues()->add(std::shared_ptr<fUML::Value>(std::dynamic_pointer_cast<fUML::Value>(_values->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_values" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  FeatureValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new FeatureValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> FeatureValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFeatureValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void FeatureValueImpl::setPosition(int _position)
{
	m_position = _position;
} 

int FeatureValueImpl::getPosition() const 
{
	return m_position;
}

//*********************************
// Operations
//*********************************
bool FeatureValueImpl::hasEqualValues(std::shared_ptr<fUML::FeatureValue>  other) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool equal = true;

    if(this->getValues()->size() != other->getValues()->size())
    {
        equal = false;

    }
    else
    {
    	std::shared_ptr<uml::StructuralFeature> feature = this->getFeature();
        if(feature->getIsOrdered())
        {
            unsigned int i = 0;
            while(equal && (i < this->getValues()->size()))
            {
                equal = this->getValues()->at(i)->equals(other->getValues()->at(i));
                i = i + 1;
            }

        }
        else
        {
        	std::shared_ptr<FeatureValue> otherFeatureValues(FUMLFactory::eInstance()->createFeatureValue());
        	std::shared_ptr<Bag<Value> > values = other->getValues();
            for(unsigned int i = 0; i < values->size(); i++)
            {
            	std::shared_ptr<Value> value = values->at(i);
                otherFeatureValues->getValues()->push_back(value);
            }

            unsigned int i = 0;
            while(equal && (i < this->getValues()->size()))
            {
                bool matched = false;
                unsigned int j = 0;
                while(!matched && (j < otherFeatureValues->getValues()->size()))
                {
                    if(this->getValues()->at(i)->equals(otherFeatureValues->getValues()->at(j)))
                    {
                        matched = true;
                        otherFeatureValues->getValues()->erase(otherFeatureValues->getValues()->begin() + j);
                    }
                    j = j + 1;
                }

                equal = matched;
                i = i + 1;
            }
        }
    }

    return equal;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::StructuralFeature > FeatureValueImpl::getFeature() const
{
//assert(m_feature);
    return m_feature;
}
void FeatureValueImpl::setFeature(std::shared_ptr<uml::StructuralFeature> _feature)
{
    m_feature = _feature;
}

std::shared_ptr<Bag<fUML::Value>> FeatureValueImpl::getValues() const
{

    return m_values;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<FeatureValue> FeatureValueImpl::getThisFeatureValuePtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<FeatureValue>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> FeatureValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FeatureValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::FEATUREVALUE_EREFERENCE_FEATURE:
			return getFeature(); //142
		case FUMLPackage::FEATUREVALUE_EATTRIBUTE_POSITION:
			return getPosition(); //141
		case FUMLPackage::FEATUREVALUE_EREFERENCE_VALUES:
			return getValues(); //140
	}
	return boost::any();
}

void FeatureValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::FEATUREVALUE_EREFERENCE_FEATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuralFeature> _feature = boost::any_cast<std::shared_ptr<uml::StructuralFeature>>(newValue);
			setFeature(_feature); //142
			break;
		}
		case FUMLPackage::FEATUREVALUE_EATTRIBUTE_POSITION:
		{
			// BOOST CAST
			int _position = boost::any_cast<int>(newValue);
			setPosition(_position); //141
			break;
		}
	}
}
