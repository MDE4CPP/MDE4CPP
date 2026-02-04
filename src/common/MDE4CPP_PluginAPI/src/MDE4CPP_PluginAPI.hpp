#include "util/crow_all.h"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EFactory.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "pluginFramework/PluginFramework.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "pluginFramework/EcoreModelPlugin.hpp"
#include "pluginFramework/UMLModelPlugin.hpp"
#include "ecore/ecorePackage.hpp"
#include <mutex>

using namespace ecore;

struct StoredObject
{
	std::string pluginName;
	std::string className;
	std::shared_ptr<ecore::EObject> object;
	std::string parentName;  // empty = root; non-empty = child of this object name
};

class GenericApi{
public:
    static std::shared_ptr<GenericApi> eInstance(std::shared_ptr<PluginFramework>& pluginFramework);
    crow::json::wvalue writeValue(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<MDE4CPPPlugin>& plugin);
    std::shared_ptr<ecore::EObject> readValue(const crow::json::rvalue& content, const std::string& eClass, const std::shared_ptr<MDE4CPPPlugin>& plugin);
    void applyPropertiesToObject(const std::shared_ptr<ecore::EObject>& object, const crow::json::rvalue& content, const std::shared_ptr<MDE4CPPPlugin>& plugin);

private:
    explicit GenericApi(std::shared_ptr<PluginFramework>& pluginFramework);
    template<typename T> crow::json::wvalue writeFeature(const std::shared_ptr<EObject>& object, const std::shared_ptr<EStructuralFeature>& feature);
    template <typename T> T convert_to(const crow::json::rvalue& value);
    template<typename T> std::shared_ptr<Any> readFeature(const std::shared_ptr<EObject>& object, const std::shared_ptr<EStructuralFeature>& feature, const crow::json::rvalue& content);
    std::shared_ptr<MDE4CPPPlugin> getPlugin(std::string name);
	void mapPlugins();
    std::shared_ptr<PluginFramework> m_pluginFramework;
    mutable std::mutex m_objectsMutex;
    std::map<std::string, StoredObject> m_objects{};
	std::map<std::string,std::shared_ptr<MDE4CPPPlugin>> m_plugins{};
};
