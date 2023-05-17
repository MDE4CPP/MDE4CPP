#ifndef ECOREEVAL_H
#define ECOREEVAL_H

#include <abstractDataTypes/Any.hpp>
#include <abstractDataTypes/Bag.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EcoreAny.hpp>


#include <ocl/Expressions/ExpressionInOcl.hpp>
#include <ocl/Expressions/CallExp.hpp>

namespace Eval {

// TODO
// Ablaufalgo für Anfragebaum
// wie Ergebnisse weiterreichen
// Context einbinden
// EGet, EAllContents, EContents, Get(Meta)Class
// Name, Invoke
// Operationen ausführen
// Attribute, Operationen, select, reject, ...
// MDE4CPP Any, aus common includen

    class EcoreEnvironment;
    
    class EcoreEval{

        public:
        
            EcoreEval();
            EcoreEval(std::shared_ptr<EcoreEnvironment> env): m_env(env) {};
            ~EcoreEval();

            std::shared_ptr<Any> visitNode(std::shared_ptr<Any> node);

            void setContext(std::shared_ptr<EcoreEnvironment> env) {m_env = env;};
            
            // ######################
            // ### Eval Functions ###
            // ######################

            std::shared_ptr<Any> evalExpressionInOcl(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalCollectionLiteralExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalIfExp(std::shared_ptr<Any> exp);
            
            std::shared_ptr<Any> evalVariableExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalOperationCallExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalPropertyCallExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalBooleanLiteralExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalStringLiteralExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalUnlimitedNaturalLiteralExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalIntegerLiteralExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalRealLiteralExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalIteratorExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalIterateExp(std::shared_ptr<Any> exp);

            // not needed
            //std::shared_ptr<Any> evalTypeExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalPrefixedExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalOperatorExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalParentedExp(std::shared_ptr<Any> exp);

            std::shared_ptr<Any> evalVarDeclExp(std::shared_ptr<Any> exp);

            // ##########################
            // ### Handling Functions ###
            // ##########################        
            
            // in case in the OclExpression is 'appliedElement' set handle this here
            // updating the contextVariable here
            std::shared_ptr<Any> handleAppliedElement(std::shared_ptr<ocl::Expressions::CallExp> appliedElement, std::shared_ptr<Any> parentResult);

            // do the collection operation
            std::shared_ptr<Any> handleCollectionOperationsOverOpCall(std::string operName, std::shared_ptr<Any> collection, std::string collectionType, std::shared_ptr<Bag<ocl::Expressions::OclExpression>> bodyArgs);

        private:

            // ######################
            // ### Misc functions ###
            // ######################

            std::shared_ptr<EcoreEnvironment> m_env;

            // returns an empty any (nullptr)
            std::shared_ptr<Any> defaultResult();

            // try to find the oclExp and call the corresponding EvalFunction
            // returns nullptr if no case was found
            std::shared_ptr<Any> callEvalFunction(std::shared_ptr<Any> exp);

            //counts the parents in a expression
            int parentCounter(std::shared_ptr<ocl::Expressions::OclExpression> checkExp);

            //compare two floats
            bool floatCompare(double f1, double f2);

            // ############################
            // ### Collection functions ###
            // ############################

            std::shared_ptr<Any> oclIncluding(std::shared_ptr<Bag<ocl::Expressions::OclExpression>> bodyArgs, std::shared_ptr<Bag<Any>> oclCollection, std::shared_ptr<Bag<ecore::EObject>> eObjBag, std::string oclCollectionType);
            std::shared_ptr<Any> oclSelectReject(bool isSelect, std::shared_ptr<ocl::Expressions::OclExpression> bodyExp, std::shared_ptr<Bag<ocl::Expressions::VarDeclarationExp>> loopVars, std::shared_ptr<Any> resultCollection, std::string collectionType);

            // ##########################
            // ### Template functions ###
            // ##########################

            template <class L, class R>
            std::shared_ptr<Any> addition(L left, R right) {
                
                try
                {
                    auto result = left + right;
                    if (typeid(result) == typeid(int)) {
                        return eAny(result, ecore::ecorePackage::EINT_CLASS, false);
                    } else if (typeid(result) == typeid(double)) {
                        return eAny(result, ecore::ecorePackage::EDOUBLE_CLASS, false);
                    } else if (typeid(result) == typeid(std::string)) {
                        return eAny(result, ecore::ecorePackage::ESTRING_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //addition failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> subtraction(L left, R right) {
                
                try
                {
                    auto result = left - right;
                    if (typeid(result) == typeid(int)) {
                        return eAny(result, ecore::ecorePackage::EINT_CLASS, false);
                    } else if (typeid(result) == typeid(double)) {
                        return eAny(result, ecore::ecorePackage::EDOUBLE_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //subtraction failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> multiplication(L left, R right) {
                
                try
                {
                    auto result = left * right;
                    if (typeid(result) == typeid(int)) {
                        return eAny(result, ecore::ecorePackage::EINT_CLASS, false);
                    } else if (typeid(result) == typeid(double)) {
                        return eAny(result, ecore::ecorePackage::EDOUBLE_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //multiplication failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> division(L left, R right) {
                
                try
                {
                    auto result = double(left) / double(right);
                    if (typeid(result) == typeid(int)) {
                        return eAny(result, ecore::ecorePackage::EINT_CLASS, false);
                    } else if (typeid(result) == typeid(double)) {
                        return eAny(result, ecore::ecorePackage::EDOUBLE_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //division failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> primLT(L left, R right) {
                
                try
                {
                    auto result = left < right;
                    if (typeid(result) == typeid(bool)) {
                        return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //division failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> primLTE(L left, R right) {
                
                try
                {
                    auto result = left <= right;
                    if (typeid(result) == typeid(bool)) {
                        return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //division failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> primGT(L left, R right) {
                
                try
                {
                    auto result = left > right;
                    if (typeid(result) == typeid(bool)) {
                        return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //division failed
                return nullptr;
            }

            template <class L, class R>
            std::shared_ptr<Any> primGTE(L left, R right) {
                
                try
                {
                    auto result = left >= right;
                    if (typeid(result) == typeid(bool)) {
                        return eAny(result, ecore::ecorePackage::EBOOLEAN_CLASS, false);
                    } else {
                        //unhandled type
                        return nullptr;
                    }
                }
                catch(...){}
                
                //division failed
                return nullptr;
            }

    };

}

#endif