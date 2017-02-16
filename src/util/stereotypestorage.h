#ifndef STEREOTYPESTORAGE_H
#define STEREOTYPESTORAGE_H

#include <map>
#include <string>
#include <vector>


#include "uml/Stereotype.hpp"

namespace util
{

class StereotypeStorage
{
public:



    static StereotypeStorage * eInstance();


    void applyStereotype(uml::Element * _element, uml::Stereotype * _stereotype);
    uml::Stereotype * getAppliedStereotype(uml::Element * _element,std::string qualifiedName);
    std::vector<uml::Stereotype * > getAppliedStereotypes(uml::Element * _element);
    bool isStereotypeApplied(uml::Element * _element,uml::Stereotype * _stereotype);
    void unapplyStereotype(uml::Element * _element, uml::Stereotype * _stereotype);

private:
    StereotypeStorage();

    static StereotypeStorage * m_instance ;
    std::map<uml::Element *,uml::Stereotype *> m_stereotypeApplicationMap;





};


}
#endif // STEREOTYPESTORAGE_H
