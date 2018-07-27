#ifndef UTIL_STEREOTYPESTORAGE_HPP
#define UTIL_STEREOTYPESTORAGE_HPP

#include <map>
#include <memory>
#include <string>

template<class T> class Bag;

namespace uml
{
	class Element;
	class Stereotype;
}

namespace util
{
	class StereotypeStorage
	{
		public:
			static std::shared_ptr<StereotypeStorage> eInstance();

			void applyStereotype(std::shared_ptr<uml::Element> element, std::shared_ptr<uml::Stereotype> stereotype);
			std::shared_ptr<uml::Stereotype> getAppliedStereotype(std::shared_ptr<uml::Element> element, std::string qualifiedName) const;
			std::shared_ptr<Bag<uml::Stereotype>> getAppliedStereotypes(std::shared_ptr<uml::Element> element) const;
			bool isStereotypeApplied(std::shared_ptr<uml::Element> element, std::shared_ptr<uml::Stereotype> stereotype) const;
			void unapplyStereotype(std::shared_ptr<uml::Element> element, std::shared_ptr<uml::Stereotype> stereotype);

		private:
			StereotypeStorage();

			static std::shared_ptr<StereotypeStorage> m_instance;
			std::map<std::shared_ptr<uml::Element>, std::shared_ptr<Bag<uml::Stereotype>>> m_stereotypeApplicationMap;
	};
}
#endif
