/*
 * LoadHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef LoadHandler_HPP_
#define LoadHandler_HPP_

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout<<"| DEBUG    | "<<a<<std::endl
#endif
#define MSG_WARNING(a) std::cout<<"| WARNING  | "<<a<<std::endl
#define MSG_ERROR(a) std::cout<<"| ERROR    | "<<a<<std::endl
#define MSG_FLF __FILE__<<":"<<__LINE__<<" "<<__FUNCTION__<<"() "

#include "XLoadHandler.hpp"
#include "HandlerHelper.hpp"

#include <map>
#include <list>
#include <string>
#include <set>
#include <exception>

#include "boost/exception/to_string.hpp"

#include "EObject.hpp"
#include "EStructuralFeature.hpp"

namespace persistence
{
namespace base
{
struct UnresolvedReference
{
	inline UnresolvedReference ( std::string refName, std::shared_ptr<ecore::EObject> eObject, std::shared_ptr<ecore::EStructuralFeature> eStructuralFeature ) :
					refName( refName ),
					eObject( eObject ),
					eStructuralFeature( eStructuralFeature )
	{
	}

	std::string refName;
	std::shared_ptr<ecore::EObject> eObject;
	std::shared_ptr<ecore::EStructuralFeature> eStructuralFeature;
};

/**
 * Class LoadHandler
 */
class LoadHandler : public persistence::interface::XLoadHandler
{
public:
	LoadHandler ();
	virtual ~LoadHandler ();

	std::shared_ptr<ecore::EObject> getObjectByRef ( std::string ref );

	std::string getLevel ();
	std::string getPrefix ();

	std::string extractType ( std::shared_ptr<ecore::EObject> obj ) const;

	void addToMap ( std::shared_ptr<ecore::EObject> object );

	void setCurrentObject ( std::shared_ptr<ecore::EObject> object );
	std::shared_ptr<ecore::EObject> getCurrentObject ();

	void release ();

	virtual unsigned int getNumOfChildNodes () = 0;
	virtual std::string getNextNodeName () = 0;
	virtual std::map<std::string, std::string> getAttributeList () = 0;

	void addUnresolvedReference ( const std::string &name, std::shared_ptr<ecore::EObject> object, std::shared_ptr<ecore::EStructuralFeature> esf );

	void resolveReferences ();

protected:
	int m_level;

	std::shared_ptr<ecore::EObject> m_rootObject;
	std::list<std::shared_ptr<ecore::EObject> > m_currentObjects;

	std::string m_rootPrefix;

	std::map<std::string, std::shared_ptr<ecore::EObject>> m_refToObject_map;
	std::list<persistence::base::UnresolvedReference> m_unresolvedReferences;
};
} /* namespace base */
} /* namespace persistence */

#endif /* LoadHandler_HPP_ */
