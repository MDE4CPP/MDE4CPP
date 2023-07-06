#include "OclConversion.h"

#include <ocl/Expressions/ExpressionInOcl.hpp>
#include <ocl/Expressions/OclExpression.hpp>
#include <ocl/Expressions/BooleanLiteralExp.hpp>
#include <ocl/Expressions/IntegerLiteralExp.hpp>
#include <ocl/Expressions/UnlimitedNaturalExp.hpp>
#include <ocl/Expressions/EnumLiteralExp.hpp>
#include <ocl/Expressions/IfExp.hpp>
#include <ocl/Expressions/LetExp.hpp>
#include <ocl/Expressions/PropertyCallExp.hpp>
#include <ocl/Expressions/VariableExp.hpp>
#include <ocl/Expressions/TypeExp.hpp>
#include <ocl/Expressions/IteratorExp.hpp>
#include <ocl/Expressions/StringLiteralExp.hpp>
#include <ocl/Expressions/OperationCallExp.hpp>
#include <ocl/Expressions/RealLiteralExp.hpp>
#include <ocl/Expressions/IterateExp.hpp>
#include <ocl/Expressions/TupleLiteralExp.hpp>
#include <ocl/Expressions/CollectionLiteralExp.hpp>
#include <ocl/Expressions/NullLiteralExp.hpp>
#include <ocl/Expressions/InvalidLiteralExp.hpp>
#include <ocl/Expressions/AssociationClassCallExp.hpp>
#include <ocl/Expressions/StateExp.hpp>
#include <ocl/Expressions/UnspecifiedValueExp.hpp>
#include <ocl/Expressions/MessageExp.hpp>
#include <ocl/Expressions/InfixedExp.hpp>
#include <ocl/Expressions/PrefixedExp.hpp>
#include <ocl/Expressions/VarDeclarationExp.hpp>
#include <ocl/Expressions/OperatorExp.hpp>
#include <ocl/Expressions/ParentedExp.hpp>
#include <ocl/Expressions/PackageDeclarationExp.hpp>
#include <ocl/Expressions/PropertyContextDeclExp.hpp>
#include <ocl/Expressions/ClassifierContextDeclExp.hpp>
#include <ocl/Expressions/OperationContextDeclExp.hpp>
#include <ocl/Expressions/OperationContextExp.hpp>
#include <ocl/Expressions/PrePostBodyListExp.hpp>
#include <ocl/Expressions/InitOrDerValueListExp.hpp>
#include <ocl/Expressions/DefExp.hpp>

using namespace Utilities;

std::shared_ptr<ocl::Expressions::OclExpression> oclCV::exp2oclExp(std::any exp) {

    const std::type_info &type = exp.type();
    std::shared_ptr<ocl::Expressions::OclExpression> oclExp = nullptr;
    
    if (type == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {
        return nullptr;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::OclExpression>)) {
        oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OclExpression>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::BooleanLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::BooleanLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::BooleanLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::BooleanLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::BooleanLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::BooleanLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::IntegerLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::IntegerLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::IntegerLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp>)) {
        std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::UnlimitedNaturalExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::EnumLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::EnumLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::EnumLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::IfExp>)) {
        std::shared_ptr<ocl::Expressions::IfExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::IfExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::LetExp>)) {
        std::shared_ptr<ocl::Expressions::LetExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::LetExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::LetExp>)) {
        std::shared_ptr<ocl::Expressions::LetExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::LetExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::PropertyCallExp>)) {
        std::shared_ptr<ocl::Expressions::PropertyCallExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PropertyCallExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::VariableExp>)) {
        std::shared_ptr<ocl::Expressions::VariableExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::VariableExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::TypeExp>)) {
        std::shared_ptr<ocl::Expressions::TypeExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::TypeExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::IteratorExp>)) {
        std::shared_ptr<ocl::Expressions::IteratorExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::IteratorExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::StringLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::StringLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::StringLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::OperationCallExp>)) {
        std::shared_ptr<ocl::Expressions::OperationCallExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationCallExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::RealLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::RealLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::RealLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::IterateExp>)) {
        std::shared_ptr<ocl::Expressions::IterateExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::IterateExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::TupleLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::TupleLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::TupleLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::CollectionLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::CollectionLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::CollectionLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::NullLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::NullLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::NullLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::InvalidLiteralExp>)) {
        std::shared_ptr<ocl::Expressions::InvalidLiteralExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::InvalidLiteralExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::AssociationClassCallExp>)) {
        std::shared_ptr<ocl::Expressions::AssociationClassCallExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::AssociationClassCallExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::StateExp>)) {
        std::shared_ptr<ocl::Expressions::StateExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::StateExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::UnspecifiedValueExp>)) {
        std::shared_ptr<ocl::Expressions::UnspecifiedValueExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::UnspecifiedValueExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::MessageExp>)) {
        std::shared_ptr<ocl::Expressions::MessageExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::MessageExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::InfixedExp>)) {
        std::shared_ptr<ocl::Expressions::InfixedExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::InfixedExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::PrefixedExp>)) {
        std::shared_ptr<ocl::Expressions::PrefixedExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrefixedExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::VarDeclarationExp>)) {
        std::shared_ptr<ocl::Expressions::VarDeclarationExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::VarDeclarationExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::OperatorExp>)) {
        std::shared_ptr<ocl::Expressions::OperatorExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperatorExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::ParentedExp>)) {
        std::shared_ptr<ocl::Expressions::ParentedExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::ParentedExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::PackageDeclarationExp>)) {
        std::shared_ptr<ocl::Expressions::PackageDeclarationExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PackageDeclarationExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>)) {
        std::shared_ptr<ocl::Expressions::PropertyContextDeclExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PropertyContextDeclExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>)) {
        std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::ClassifierContextDeclExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::OperationContextDeclExp>)) {
        std::shared_ptr<ocl::Expressions::OperationContextDeclExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextDeclExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::OperationContextExp>)) {
        std::shared_ptr<ocl::Expressions::OperationContextExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::OperationContextExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::PrePostBodyListExp>)) {
        std::shared_ptr<ocl::Expressions::PrePostBodyListExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::PrePostBodyListExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>)) {
        std::shared_ptr<ocl::Expressions::InitOrDerValueListExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::InitOrDerValueListExp>>(exp);
        return oclExp;
    }

    if (type == typeid(std::shared_ptr<ocl::Expressions::DefExp>)) {
        std::shared_ptr<ocl::Expressions::DefExp> oclExp = std::any_cast<std::shared_ptr<ocl::Expressions::DefExp>>(exp);
        return oclExp;
    }

    return oclExp;

}

// extracts all path parts from a given string
std::shared_ptr<std::list<std::string>> oclCV::extractPath(const std::string& pathWithName) {

    std::string remaining = pathWithName;
    std::shared_ptr<std::list<std::string>> returnList = std::make_shared<std::list<std::string>>(std::list<std::string>());
    int colPos;
    std::string name;
    
    while (remaining.length() != 0) {

        if (remaining.find("::") != std::string::npos) {
        
            colPos = remaining.find("::");
            name = remaining.substr(0, colPos-1);
            remaining = remaining.substr(colPos+2);
            returnList->push_back(name);

        } else {
            returnList->push_back(remaining);
            remaining = "";
        }
    }

    return returnList;
}