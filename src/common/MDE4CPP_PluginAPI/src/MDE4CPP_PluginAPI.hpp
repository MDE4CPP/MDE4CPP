#include "util/crow_all.h"
#include "Model.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "pluginFramework/PluginFramework.hpp"
#include "ecore/ecorePackage.hpp"
#include <deque>

using namespace ecore;

/** 
 * Json Formate for EObjects and Models: 
 * {
 *  Alias : "User_defined_Alias_for_EObject"                                                           //OPTIONAL; for easier use of the Objects in the API and for easier setting of References
 *  ObjectClass : "pluginName::ClassNamespaces::ClassName"                                             // used to specify the class of an object ??ONLY NEEDED FOR ROOT OBJECT?? -> what is the correct way for derived Classes? 
 *  StructuralFeature_Name_0 : Value,                                                                  //for Attributes with primitive type 
 *  StructuralFeature_Name_1 : [Value_0, Value_1, ...],                                                //for Attributes that are containers
 *  StructuralFeature_Name_2 : { EObject_json },                                                       //for Containment-References with multiplicity of "1"
 *  StructuralFeature_Name_3 : [{EObject_0_json}, {EObject_1_json}, ...],                              //for Containment-References with multiplicity of greater than "1"
 *  StructuralFeature_Name_4 : Path_to_Referenced_EObject,                                             //for Non-Containment Reference with multiplicity of "1"
 *  StructuralFeature_Name_5 : [Path_to_Referenced_EObject_0, Path_to_Referenced_EObject_1, ...]       //for Non-Containment Reference with multiplicity of greater than "1"
 *  StructuralFeature_Name_4 : $Alias_of_Referenced_EObject,                                           //for Non-Containment Reference with multiplicity of "1"
 *  StructuralFeature_Name_5 : [$Alias_of_Referenced_EObject_0, Path_to_Referenced_EObject_1, ...]     //for Non-Containment Reference with multiplicity of greater than "1"
 *  ...
 *      } 
 *  
 *  Clarification concering Alias of EObject: 
 *  -> Can be used to set References instead of using the path to the EObject 
 *  -> Just internal in the API; not present in the resulting model 
 */

class GenericApi{
public:
    static std::shared_ptr<GenericApi> eInstance(std::shared_ptr<PluginFramework>& pluginFramework);

    /**
     * pares an object of the model and returns a json of it
     * @param object : pointer to the EObject that should be parsed
     * @return json in the form specified above
     */
    crow::json::wvalue writeValue(const std::shared_ptr<ecore::EObject>& object);


    /**
     * creates an EObject of the EClass and sets the StructuralFeatures of it according to the values specified in the json
     * @param content : json with StructuralFeatures and their Values; has to follow the form outlined above
     * @param eClass : pointer to the eClass of the Object that should be created
     * @return shared_ptr to created EObject
     */
    std::shared_ptr<ecore::EObject> readValue(const crow::json::rvalue& content, const std::string& eClass, const std::shared_ptr<MDE4CPPPlugin>& plugin);

private:
    explicit GenericApi(std::shared_ptr<PluginFramework>& pluginFramework);

    /**
     * helper function to write the value of a StructuralFeature into a json
     * @param object : the EObject where the StructuralFeature is a part of
     * @param feature : the Feature whos value shall be written into the json
     * @return : a json representation of the StructuralFeature 
     */
    template<typename T> crow::json::wvalue writeFeature(const std::shared_ptr<EObject>& object, const std::shared_ptr<EStructuralFeature>& feature);


    template <typename T> T convert_to(const crow::json::rvalue& value);
    
    /**
     * helper function to parse a json and create an Any-Object with the correct Value for an StructuralFeature of an Object
     * @param object : the EObject where the StructuralFeature is a part of
     * @param feature : the Feature whos value shall be written to
     * @param content : the json holding a Key/Value Pair with the Name of the StructuralFeature and its intended value
     * @return : pointer to an Any containing the value(s) specified in the json
     */
    template<typename T> std::shared_ptr<Any> readFeature(const std::shared_ptr<EObject>& object, const std::shared_ptr<EStructuralFeature>& feature, const crow::json::rvalue& content);
    
    /**
     * Allows getting a plugin by its name 
     * @param name : name of the plugin as a string
     * @return : pointer to the plugin; nullptr if plugin could not found 
    */
    std::shared_ptr<MDE4CPPPlugin> getPlugin(std::string name);

    /**
     * populates the m_plugins variable with pointers to all plugins found in the current directory 
    */
	void mapPlugins();

    /**
     * navigate to a StructuralFeature and return a shared_ptr to it
     * @param start_object = shared_ptr to object from which to start 
     * @param path = sting of StructualFeature; MUST NOT be empty; e.g: books@9/authors@1/Name would first navigate to the 9th object of the "books" StrukturalFeature which must be a container. Then to the 1st object of the "authors" container that is in the previously selected book. And finaly navigate to the name of the auhor
     */
    const std::shared_ptr<EStructuralFeature>& navigateToStructuralFeature(const std::shared_ptr<EObject>& start_object, std::string path); 

    /**
     * splits the string s at every occurence of split_char and writes every segment into the buffer
     * does not ever insert an empty string into buffer
     * @param buffer : pointer to the vector where the string segments are supposed to be stored (empty segments are not inserted)
     * @param s : string that is supposed to be split
     * @param split_char : char denoting the boundery between to segments 
    */
    void split_string(const std::shared_ptr<std::deque<std::string>>& buffer, std::string s, char split_char);
    
    std::shared_ptr<PluginFramework> m_pluginFramework;

    std::map<std::string,std::shared_ptr<Model>> m_models{}; //map of all root-artifacts 
	std::map<std::string,std::shared_ptr<MDE4CPPPlugin>> m_plugins{}; //map of all plugins currently detected
    
};
