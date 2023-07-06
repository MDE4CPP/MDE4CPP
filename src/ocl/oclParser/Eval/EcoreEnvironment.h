#ifndef ECOREENVIRONMENT_H
#define ECOREENVIRONMENT_H

#include <unordered_map>
#include <memory>

//#include "EcoreNamedElement.h"

#include <ecore/EObject.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/EcoreAny.hpp>


namespace Eval {

    class EcoreEval;

    class EcoreEnvironment{

        public:
            EcoreEnvironment(std::shared_ptr<EcoreEnvironment> parent, std::shared_ptr<Any> self) : m_parent(parent), m_self(self), m_context(self) {};
            virtual ~EcoreEnvironment();

            /*!
            * \brief Find a Object in the current environment, not in its parents, based on a single name.
            * \param name
            * \return nullptr if the element is not found.
            */
            std::shared_ptr<Any> lookupLocal(const std::string& name);

            /*!
            * \brief Find a named element in the current environment or recursively in its parent environment, based on a single name.
            * \param name
            * \return nullptr if the element is not found.
            */
           std::shared_ptr<Any> lookup(const std::string& name);

            /*!
            * \brief Find a Object in the current environment or recursively in its parent environment, based on a single name and the implicitly.
            * \param name
            * \return nullptr if the element is not found.
            */
            std::shared_ptr<Any> lookupImplicit(const std::string& name);

            /*!
            * \brief This operation results in a new environment that has the current one as its parent.
            * \return a new environment.
            */
            std::shared_ptr<EcoreEnvironment> nestedEnvironment();

            /*!
            * \brief Add a new object to the environment. The type can be set to "" if unknown.
            * \return true if the element is added, false if the element is already contained
            */
            bool addElement(const std::string& name, std::shared_ptr<Any> elem, bool isImplicit, std::string type);

            /*!
            * \brief Allowing changing namedElements.
            * \return true if successful false if not
            */
            bool changeNamedElement(const std::string& name, std::shared_ptr<Any> newElem);

            /*!
            * \brief Generates a new, unique name for an implicit iterator variable.
            * \return the new name.
            */
            std::string generateName();

            /* SETTERS */
            void setSelfVariable(std::shared_ptr<Any> self) { m_self = self; }
            void setContextVariable(std::shared_ptr<Any> context) { m_context = context; }

            /* GETTERS */
            
            /*! 
            *  \brief returns the first Environment with no parent (including this)
            *  \return the first Environment with no parent (including this)
            */
            std::shared_ptr<EcoreEnvironment> getRootEnv();
            
            std::shared_ptr<Eval::EcoreEval> getEvalEnv() { return m_evalEnv; }
            std::shared_ptr<Any> getSelfVariable() { return m_self; }
            std::shared_ptr<Any> getContextVariable() { return m_context; }

            static const std::string SELF_VARIABLE_NAME;

            // ### non OCL spec functions ###

            // only 'self' will be requested here, all other properties will be requested in PropertyCallExp
            std::shared_ptr<Any> lookupVariableName(const std::string& name);

            //looks for the given (property) name in the given (EClass) context
            //returns nullptr if property with name is not found
            std::shared_ptr<Any> lookupPropertyName(const std::string& name, std::shared_ptr<Any> context);

            //looks for the given (operation) name in the given (EClass) context
            //returns nullptr if operation with name is not found
            std::shared_ptr<Any> lookupOperationName(const std::string& name, std::shared_ptr<Any> context);

            // look for a Type in the given Any
            //return nullptr if no type is found
            std::string getTypeName(const std::shared_ptr<Any>& argument);

            //searches in all namedElements for the given variable name
            std::shared_ptr<Any> lookupNamedElement(const std::string& name);

        private:
            /*!
            * \brief Parent environment
            */
            std::shared_ptr<Eval::EcoreEnvironment> m_parent;
            /*!
            * \brief Evaluation environment
            */
            std::shared_ptr<Eval::EcoreEval> m_evalEnv;
            /*!
            * \brief self variable
            */
            std::shared_ptr<Any> m_self;

            /*!
            * \brief the current context of the query, default is m_self, can change during to nested calls
            */
            std::shared_ptr<Any> m_context;
            /*!
            * \brief List of declared variables and implicit variables, including "self".
            * Implicit variables are generated when there is an iterator without any
            * iteration variable specified. -> this task now manages the m_context var
            * the variables are stored in a tuple
            * first entry is the type as string, second is the value as any
            */
            std::unordered_map<std::string, std::tuple<std::string, std::shared_ptr<Any>>> m_namedElements;
            /*!
            * \brief Used to generate implicit iterator variables
            */
            int m_generatorInt = 0;
            // returns an empty any (nullptr)
            std::shared_ptr<Any> emptyResult();
            //get 'this' as parameter
            std::shared_ptr<EcoreEnvironment> getThisEnv();

    };

    template <class T>
    // T without std::shared_ptr
    // casts if the given type is valid
    // return nullptr if not, else return the casted object
    std::shared_ptr<T> castEcoreArgument(std::shared_ptr<Any> argument) {

        std::shared_ptr<T> emptyResult;

        std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(argument);
        if (ecoreAny == nullptr) {

            //TODO error
            // input have to be of type ecoreAny
            return emptyResult;

        } else {

            // check if an Expression is present
            std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
            std::shared_ptr<T> checkExp = std::dynamic_pointer_cast<T>(eObject);

            if (checkExp == nullptr) {

                //TODO add error
                // the expression could not be casted
                return emptyResult;

            }

            return checkExp;
        }
    };

}


#endif