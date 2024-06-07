#include "json2Model.hpp"
#include "helpersFunc.hpp"

//PluginFramework includes
#include "pluginFramework/MDE4CPPPlugin.hpp"

//Ecore includes
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"

std::shared_ptr<JSON2Model> JSON2Model::eInstance(std::shared_ptr<pluginHandler> pluginHandler){
    static std::shared_ptr<JSON2Model> instance = std::make_shared<JSON2Model>(JSON2Model(pluginHandler));
}

JSON2Model::JSON2Model(std::shared_ptr<pluginHandler> pluginHandler){
    m_pluginHandler = pluginHandler;
}

//creates an object encoded in a json
std::shared_ptr<ecore::EObject> JSON2Model::createModelWithoutCrossReferencesFromJson(const crow::json::rvalue& content, std::vector<std::tuple<std::shared_ptr<ecore::EReference>, crow::json::rvalue, long, bool>>& crossReferenceBuffer){

    auto ObjClass_KeyVal = content["ObjectClass"];
    if(ObjClass_KeyVal.t() != crow::json::type::String){ //if type of the key value is anything else except for a string (eg. null)
        throw std::runtime_error("ObjectClass key not set!");
    }
    auto [pluginName , eClass] = helperFunctions::splitObjectClassKey(std::string(ObjClass_KeyVal));

    auto plugin = m_pluginHandler->getPluginByName(pluginName);
    auto result = plugin->create(eClass); //TODO check for unexpected behavior (e.g unknown ClassName)

    //handeling of all member attibutes of the object
    std::shared_ptr<Bag<ecore::EAttribute>> attributes = result->eClass()->getEAllAttributes();
    for(const auto & attribute : *attributes){
        try {
            auto value = content[attribute->getName()];
            if(value.t() == crow::json::type::Null){
                CROW_LOG_INFO << attribute->getName()  << " not set in json for object";
                continue;
            }
        } catch (std::runtime_error& error){
            CROW_LOG_WARNING << "an error occured in createOjectFromJSON : "  << error.what() <<" !" ;
            continue;
        }

        auto attributeTypeId = result->eGet(attribute)->getTypeId(); //TODO make less complicated
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                result->eSet(attribute, readAttributeValue<bool>(result, attribute, content));
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                result->eSet(attribute, readAttributeValue<char>(result, attribute, content));
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                result->eSet(attribute, readAttributeValue<int>(result, attribute, content));
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                result->eSet(attribute, readAttributeValue<long>(result, attribute, content));
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                result->eSet(attribute, readAttributeValue<float>(result, attribute, content));
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                result->eSet(attribute, readAttributeValue<double>(result, attribute, content));
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
                result->eSet(attribute, readAttributeValue<std::string>(result, attribute, content));
                break;
            default :
                CROW_LOG_ERROR <<"encountered attribute of unknown type : " << attributeTypeId;
                break;
        }
    }
        
    //handeling of all member references of the object
    std::shared_ptr<Bag<ecore::EReference>> references = result->eClass()->getEAllReferences();
    for(auto reference : *references){

        if(reference == nullptr){
            CROW_LOG_ERROR << "shared_ptr to reference is nullptr!" ;
        }

        try {
            auto value = content[reference->getName()];
            if(value.t() == crow::json::type::Null){ //no matching key was found in the json 
                CROW_LOG_INFO << reference->getName()  << " not set in json for object";
                continue;
            }
        } catch (std::runtime_error& error){
            CROW_LOG_ERROR << "runtime error occured in createOjectFromJSON : "  << error.what() <<" !" ;
            continue;
        }

        if(reference->isContainment()){ //handles all containment references; container (back-)references will also automaticly be set
            auto referenceTypeID = result->eGet(reference)->getTypeId(); //Gets TypeID of the reference target //TODO make less complicated
            std::shared_ptr<Any> referenceContent;

            if(result->eGet(reference)->isContainer()){
                auto bag = std::make_shared<Bag<ecore::EObject>>();
                for(const auto & entry : content[reference->getName()]){
                    bag->add(createModelWithoutCrossReferencesFromJson(entry, crossReferenceBuffer)); //recursive call to creates each object that is being referenced 
                }
                referenceContent = eEcoreContainerAny(bag, referenceTypeID);
            }else{
                auto value = createModelWithoutCrossReferencesFromJson(content[reference->getName()], crossReferenceBuffer); //recursive call to creates the referenced object 
                referenceContent = eAny(value, referenceTypeID, false);
            }
            result->eSet(reference, referenceContent);
        }

        if(!reference->isContainer() && !reference->isContainment()){ //handles all references other than containment- and container-references
            auto referenceTypeID = result->eGet(reference)->getTypeId(); //Gets TypeID of the reference target //TODO make less complicated
            crossReferenceBuffer.push_back({reference,content[reference->getName()],referenceTypeID,result->eGet(reference)->isContainer()});
            //TODO: process referenceBuffer after recursion finished to set References
        }

    }
    return result;
}

template<typename T>
std::shared_ptr<Any> JSON2Model::readAttributeValue(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature, const crow::json::rvalue& content){
    auto attributeTypeId = object->eGet(feature)->getTypeId();
    auto isContainer = object->eGet(feature)->isContainer();

    if(isContainer){ //handling of Attributes with multiplicity of > 1
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        for(const auto & entry : content[feature->getName()]){
            auto value = std::make_shared<T>(convert_to<T>(entry));
            bag->add(value);
        }
        return eAny(bag, attributeTypeId, true);
    }

    return eAny(convert_to<T>(content[feature->getName()]), attributeTypeId, false);
}

//generic conversion methods for json
template<> bool JSON2Model::convert_to<bool>(const crow::json::rvalue& value){
    return value.b();
}

template <typename T> T JSON2Model::convert_to(const crow::json::rvalue& value){
    std::istringstream ss(value.operator std::string());
    T num;
    ss >> num;
    return num;
}