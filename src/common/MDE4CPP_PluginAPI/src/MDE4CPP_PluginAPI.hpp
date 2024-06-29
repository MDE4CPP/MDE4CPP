#ifndef MDE4CPP_PLUGINAPI_HPP
#define MDE4CPP_PLUGINAPI_HPP

#include "util/crow_all.h"

#include "ModelInstance.hpp"
#include "pluginHandler.hpp"
#include "json2ecore.hpp"
#include "ecore2json.hpp"

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"

#include "ecore/EObject.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "ecore/ecorePackage.hpp"

#include "pluginFramework/PluginFramework.hpp"

#include <deque>

using namespace ecore;

/** 
 * JSON Formate for Model Instances: 
 * {
 *  ObjectClass : "pluginName::ClassNamespaces::ClassName"                                             //REQUIRED; used to specify the class of an object ??ONLY NEEDED FOR ROOT OBJECT?? -> what is the correct way for derived Classes? 
 *  ObjectID : Number                                                                                  //OPTIONAL; unique identifier used for resolving the target-EObject of a reference
 *  StructuralFeature_Name_0 : Value,                                                                  //for Attributes with primitive type 
 *  StructuralFeature_Name_1 : [Value_0, Value_1, ...],                                                //for Attributes that are containers
 *  StructuralFeature_Name_2 : { EObject_JSON },                                                       //for Containment-References with multiplicity of "1"
 *  StructuralFeature_Name_3 : [{EObject_0_JSON}, {EObject_1_JSON}, ...],                              //for Containment-References with multiplicity of greater than "1"
 *  StructuralFeature_Name_4 : Reference_Target,                                                       //for Non-Containment Reference with multiplicity of "1"
 *  StructuralFeature_Name_5 : [Reference_Target_0, Reference_Target_1, ...]                           //for Non-Containment Reference with multiplicity of greater than "1"
 *  ...
 *      } 
 *  Reference_Targets can be either :   -the ObjectID of the target-EObject as a number;
 *                                      -the path to the EObject in the Model from the rootObject
 *                                          -> must be in the form: "first_reference_name[@index_0](::next_reference_name[@index_1])"
 *                                          -> index must only be used if the multipicity of the reference is > 1
 *                                          -> first_reference_name must be contained in the root object of the model instance
 */

class GenericApi{
public:
    /**
     * Singleton-Getter
     * retrieves a pointer to the existing instance or creates a new one should none exist yet
     * 
     * needed since only one application can bound to a port at the same time 
     */
    static std::shared_ptr<GenericApi> getInstance();

private:
    /**
     * creates a REST-API and binds it to http://127.0.0.1:8080
     * for Enpoint documentation refer to Implemention
     */
    explicit GenericApi();
    
    std::shared_ptr<pluginHandler> m_pluginHandler;

    std::shared_ptr<Ecore2Json> m_Ecore2Json_handler;

    std::map<std::string,std::shared_ptr<ModelInstance>> m_modelInsts{}; //map of all modelinstances
	

};
#endif /*MDE4CPP_PLUGINAPI_HPP*/