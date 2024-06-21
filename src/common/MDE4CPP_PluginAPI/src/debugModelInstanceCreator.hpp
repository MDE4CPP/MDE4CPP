#ifndef DEBUG_MODEL_INSTANCE_CREATOR_HPP
#define DEBUG_MODEL_INSTANCE_CREATOR_HPP

#include "ecore/EObject.hpp"

#include "ecore/EObject.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"

namespace debugModelInstanceCreator{
    std::shared_ptr<ecore::EObject> getExampleModelInstance();
}
#endif /*DEBUG_MODEL_INSTANCE_CREATOR_HPP*/