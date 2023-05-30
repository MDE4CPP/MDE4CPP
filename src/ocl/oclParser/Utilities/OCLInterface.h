#ifndef OCLINTERFACE_H
#define OCLINTERFACE_H

#include <string>

#include <abstractDataTypes/Any.hpp>

namespace Utilities {

    class OCLInterface {

    public:
        virtual std::shared_ptr<Any> query(const std::string& qryStr, std::shared_ptr<Any> context) = 0;
        virtual std::shared_ptr<Any> debugQuery(const std::string& qryStr, std::shared_ptr<Any> context) = 0;

        //Getter & Setter
        void setContext(std::shared_ptr<Any> context) {m_context = context;};
        std::shared_ptr<Any> getContext() {return m_context;};

    private:
        std::shared_ptr<Any> m_context;
    };

}


#endif