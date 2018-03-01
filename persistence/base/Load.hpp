/*
 * Load.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef LOAD_HPP_
#define LOAD_HPP_

#ifdef NDEBUG
#define MSG_DEBUG(a) /**/
#else
#define MSG_DEBUG(a) std::cout<<"| DEBUG    | "<<a<<std::endl
#endif
#define MSG_WARNING(a) std::cout<<"| WARNING  | "<<a<<std::endl
#define MSG_ERROR(a) std::cout<<"| ERROR    | "<<a<<std::endl
#define MSG_FLF __FILE__<<":"<<__LINE__<<" "<<__FUNCTION__<<"() "

#include <exception>

//#include "ExtendedMetaData.hpp"
#include "persistence/base/LoadHandler.hpp"

#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"

#include <boost/any.hpp>

namespace persistence
{
namespace base
{
class Load
{
public:
	Load ();
	virtual ~Load ();

	std::shared_ptr<ecore::EObject> load ( const std::string &filename );

protected:
	std::shared_ptr<persistence::base::LoadHandler> m_handler;

	virtual bool read ( const std::string &filename ) = 0;
};

} /* namespace base */
} /* namespace persistence */

#endif /* LOAD_HPP_ */
