#ifndef PLUGINFRAMEWORK_OPERATIONINVOKERPLUGIN_HPP
#define PLUGINFRAMEWORK_OPERATIONINVOKERPLUGIN_HPP

#include <memory>
#include <string>

namespace ecore
{
	class EObject;
	class EOperation;
}

class Any;

template <class T>
class Bag;

/**
 * Optional plugin interface for executing operations with real semantics.
 *
 * IMPORTANT:
 * - This is intentionally NOT added to MDE4CPPPlugin to avoid ABI breaks.
 * - PluginAPI should detect support via dynamic_pointer_cast.
 */
class OperationInvokerPlugin
{
	public:
		virtual ~OperationInvokerPlugin() {}

		struct InvokeRequest
		{
			// Operation name (simple name). Signature matching is plugin-specific.
			std::string operationName;
			// Optional: metamodel operation resolved by PluginAPI, may be null.
			std::shared_ptr<ecore::EOperation> operation;
			// Arguments already converted to Any values.
			std::shared_ptr<Bag<Any>> arguments;
		};

		struct InvokeResult
		{
			bool success = false;
			std::string error;
			std::shared_ptr<Any> result;
		};

		// Fast check for UI/metadata. Should be side-effect free.
		virtual bool canInvoke(const std::shared_ptr<ecore::EObject>& object, const std::string& operationName) const = 0;

		// Execute operation and return result as Any.
		virtual InvokeResult invoke(const std::shared_ptr<ecore::EObject>& object, const InvokeRequest& request) = 0;
};

#endif

