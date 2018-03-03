/*
 * HandlerHelper.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef HandlerHelper_HPP_
#define HandlerHelper_HPP_

#include <list>
#include <string>
#include <set>
#include <tuple>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

namespace persistence
{
namespace base
{
class HandlerHelper
{
public:
	HandlerHelper ();
	virtual ~HandlerHelper ();

	static std::string extractType ( const std::shared_ptr<ecore::EObject> obj, std::string prefix );
	static std::string extractReference ( const std::shared_ptr<ecore::EObject> toObject, const std::shared_ptr<ecore::EObject> rootObject,
			std::string prefix );
};

} /* namespace base */
} /* namespace persistence */

#endif /* HandlerHelper_HPP_ */
