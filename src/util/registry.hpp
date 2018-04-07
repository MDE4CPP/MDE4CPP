#ifndef UTIL_REGISTRY_HPP
#define UTIL_REGISTRY_HPP

#include <map>
#include <memory>
#include <string>

namespace ecore
{
	class EFactory;
	class EPackage;
}

namespace util
{
	class Registry
	{
		public:
			Registry();

			static Registry * eInstance();

			std::shared_ptr<ecore::EPackage> getEPackage(std::string nsURI);
			std::shared_ptr<ecore::EFactory> getEFactory(std::string nsURI);
			void put(std::string nsURI, std::shared_ptr<ecore::EPackage> package);

		private:
			static Registry * m_instance;
			std::map<const std::string, std::shared_ptr<ecore::EPackage> > m_packageMap;
	};
}
#endif
