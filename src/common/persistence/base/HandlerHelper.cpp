/*
 * HandlerHelper.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/HandlerHelper.hpp"

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout << "| DEBUG    | " << a << std::endl
#endif
#define MSG_WARNING(a) std::cout << "| WARNING  | "<< a << std::endl
#define MSG_ERROR(a) std::cout << "| ERROR    | " << a << std::endl
#define MSG_FLF __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() "

#include <sstream> // used for extractType()

#include "abstractDataTypes/SubsetUnion.hpp"

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "abstractDataTypes/Union.hpp"
#include "uml/NamedElement.hpp"

using namespace persistence::base;

HandlerHelper::HandlerHelper()
{
}

HandlerHelper::~HandlerHelper()
{
}

/*
 * This API is adapted to API in Project emf4cpp.
 *
 * LINK to source: https://github.com/catedrasaes-umu/emf4cpp/tree/master/emf4cpp/ecorecpp/serializer/serializer-xerces.cpp
 * ::ecorecpp::mapping::type_traits::string_t serializer::get_type(EObject_ptr obj) const
 *
 */
std::string HandlerHelper::extractType(const std::shared_ptr<ecore::EObject> obj, std::string prefix)
{
	std::stringstream ss;
	std::shared_ptr<ecore::EClass> metaClass = obj->eClass();

	if (!prefix.empty())
	{
		ss << prefix << ":" << metaClass->getName();
	}
	else
	{
		ss << metaClass->getName();
	}
	return ss.str();
}

std::string HandlerHelper::extractReference(const std::shared_ptr<ecore::EObject> toObject, const std::shared_ptr<ecore::EObject> rootObject,
	std::string prefix, const std::string& uri)
{
	std::list<std::shared_ptr<ecore::EObject>> list;
	std::shared_ptr<ecore::EObject> antecessor = toObject; //pre-init antecessor
	while (antecessor)
	{
		list.push_front(antecessor);
		antecessor = list.front()->eContainer();
	}
	return extractReference(toObject, rootObject, prefix, list, uri);
}

/*
 * This API is adapted to API in Project emf4cpp.
 *
 * LINK to source: https://github.com/catedrasaes-umu/emf4cpp/tree/master/emf4cpp/ecorecpp/serializer/serializer-xerces.cpp
 * ::ecorecpp::mapping::type_traits::string_t serializer::get_reference(EObject_ptr from, EObject_ptr to) const
 *
 */
std::string HandlerHelper::extractReference(const std::shared_ptr<ecore::EObject> toObject, const std::shared_ptr<ecore::EObject> rootObject,
	std::string prefix, std::list<std::shared_ptr<ecore::EObject>> currentObjects, const std::string& uri)
{
	std::stringstream ref;

	if (!toObject)
	{
		MSG_ERROR(MSG_FLF << " Given Parameter 'toObject' is nullptr.");
		return ref.str();
	}

	if (currentObjects.size() == 0)
	{
		std::cerr << "no current object" << std::endl;
		throw "no current object";
	}

	std::shared_ptr<ecore::EPackage> rootPkg = std::dynamic_pointer_cast<ecore::EPackage>(currentObjects.front());

	if (rootPkg)
	{
		// This case is used for ecore-models

		// If meta package of clsObj is different then rootObject of model, so extract type and Namespace-Uri of meta package
		if (rootObject != rootPkg) // TODO check if works correct (not tested yet)
		{
			if (uri.empty())
			{
				ref << extractType(toObject, prefix) << " " << rootPkg->getNsURI();
			}
			else
			{
				ref << extractType(toObject, prefix) << " " << uri;
			}
		}

		ref << "#/";

		// Add Package name(s) and Class/Enum/EDataType name to 'value'
		std::list<std::shared_ptr<ecore::EObject>>::iterator iter = currentObjects.begin();
		std::list<std::shared_ptr<ecore::EObject>>::iterator endIter = currentObjects.end();
		iter++; // Remove root Package from 'to_antecessors' because it is not used in reference name
		while (iter != endIter)
		{
			std::shared_ptr<ecore::EObject> obj = *iter;
			std::shared_ptr<ecore::ENamedElement> to_antecessors_back = std::dynamic_pointer_cast<ecore::ENamedElement>(obj);
			std::shared_ptr<ecore::EAnnotation> to_antecessors_back_annotation = std::dynamic_pointer_cast<ecore::EAnnotation>(obj);

			if (to_antecessors_back != nullptr)
			{
				ref << "/" << to_antecessors_back->getName();
			}
			else if (to_antecessors_back_annotation != nullptr)
			{
				ref << "/" << "%" << to_antecessors_back_annotation->getSource() << "%";
			}
			else
			{
				MSG_ERROR(MSG_FLF << "During casting Object of type '" << obj->eClass()->getName() << "' to 'ENamedElement'.");
			}
			iter++;
		}

		std::shared_ptr<ecore::EClass> classObj = std::dynamic_pointer_cast<ecore::EClass>(currentObjects.back()->eContainer());
		std::shared_ptr<ecore::ENamedElement> targetObj = std::dynamic_pointer_cast<ecore::ENamedElement>(toObject);
		if (classObj && targetObj)
		{
			if (targetObj->getName().compare("behavioredClassifier") == 0)
			{

				int count = 0;
				int meetingIndex = 0;

				std::shared_ptr<SubsetUnion<ecore::EStructuralFeature, ecore::EObject>> structFeastureList = classObj->getEStructuralFeatures();
				for (std::shared_ptr<ecore::EStructuralFeature> structFeat : *structFeastureList)
				{
					if (structFeat->getName() == targetObj->getName())
					{
						count++;
					}

					if (structFeat == toObject)
					{
						meetingIndex = count;
					}
				}

				std::shared_ptr<Bag<ecore::EOperation>> operationList = classObj->getEOperations();
				for (std::shared_ptr<ecore::EOperation> operatation : *operationList)
				{
					if (operatation->getName() == targetObj->getName())
					{
						count++;
					}

					if (operatation == toObject)
					{
						meetingIndex = count;
					}
				}
				if (count > 1 && meetingIndex != 0)
				{
					ref << "." << meetingIndex;
				}
			}
		}
	}
#if 0
	//else if ( (to_antecessors.back() == m_rootObject) || (m_rootObject == nullptr) )
	else if ( to_antecessors.back() == rootObject )
	{
		// This case is used for Non-Ecore-Models to extract reference
		// TODO implement and test this case

		MSG_ERROR(MSG_FLF << "else-if-case (Non-Ecore-Models) is not tested yet.");

		ref << "/";
		std::shared_ptr<ecore::EObject> prev = to_antecessors.back();
		to_antecessors.pop_back();

		while ( to_antecessors.size() > 0 )
		{
			std::shared_ptr<ecore::EStructuralFeature> esf = to_antecessors.back()->eContainingFeature();

			if ( esf->getUpperBound() == 1 )
			ref << "/" << esf->getName();

			else
			{
				Any _any = prev->eGet( esf );

				std::shared_ptr<Bag<ecore::EObject>> ef = _any.get<std::shared_ptr<Bag<ecore::EObject>>>();

				// calculate the index of back at father's collection
				size_t index_of = 0;
				for (; index_of < ef->size() && (*ef)[index_of] != to_antecessors.back(); index_of++ );

				ref << "/@" << esf->getName() << "." << index_of;
			}

			prev = to_antecessors.back();
			to_antecessors.pop_back();
		}
	}
#endif
	else
	{
		std::shared_ptr<ecore::EClassifier> clsObj = std::dynamic_pointer_cast<ecore::EClassifier>(toObject);
		if (clsObj)
		{
			// This case is used for Class/Enum/EDataType that are not contained within a Package
			std::weak_ptr<ecore::EPackage> dPck = clsObj->getEPackage();

			if (auto ePck = dPck.lock())
			{
				// If meta package of clsObj is different then rootObject of model, so extract type and Namespace-Uri of meta package
				if (rootObject != ePck) // TODO check if works correct (not tested yet)
				{
					ref << extractType(toObject, prefix) << " " << ePck->getNsURI();
				}
			}
			ref << "#/";
			ref << "/" << clsObj->getName();
		}
		else
		{
			std::shared_ptr<uml::NamedElement> obj = std::dynamic_pointer_cast<uml::NamedElement>(toObject);
			if (obj)
			{
				ref << "#/";
				ref << "/" << obj->getName();
			}
			else
			{
				MSG_WARNING(MSG_FLF << "Given Object's type '" << toObject->eClass()->getName() << "' is not 'EClassifier'.");
			}
		}
	}

	return ref.str();
}
