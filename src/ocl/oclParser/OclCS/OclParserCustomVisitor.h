#ifndef OCLPARSERCUSTOMVISITOR_H
#define OCLPARSERCUSTOMVISITOR_H

#include "OclParserBaseVisitor.h"

#include <ocl/Expressions/AssociationClassCallExp.hpp>
#include <ocl/Expressions/PropertyCallExp.hpp>
#include <ocl/Expressions/OperationCallExp.hpp>
#include <ocl/Expressions/OperatorExp.hpp>
#include <ocl/Expressions/IfExp.hpp>
#include <ocl/Expressions/LetExp.hpp>
#include <ocl/Expressions/PrefixedExp.hpp>
#include <ocl/Expressions/VarDeclarationExp.hpp>
#include <ocl/Expressions/BooleanLiteralExp.hpp>

#include "../Utilities/OclConversion.h"

using namespace ocl::Expressions;
using namespace Utilities;

namespace OclCS {

class OclParserCustomVisitor : public OclParserBaseVisitor
{
public:

    // ##################
    // ### from antlr ###
    // ##################

    //added just for comparison
    //virtual std::any visitChildren(antlr4::tree::ParseTree *node) override;
    
    // override default implementation of antlr
    virtual std::any defaultResult() override;

    // override default implementation of antlr
    virtual std::any aggregateResult(std::any aggregate, std::any nextResult) override;

    // #######################
    // ### ExpressionInOcl ###
    // #######################
    
    //WIP
    virtual std::any visitExpressionInOclCS(OclParser::ExpressionInOclCSContext *ctx) override;

    // #####################
    // ### OclExpression ###
    // #####################  
    
    // WIP
    virtual std::any visitOclExpressionCS(OclParser::OclExpressionCSContext *ctx) override;
    
    // ##########################
    // ### LiteralExpressions ###
    // ##########################
    
    // BEGIN_LE implements abstract of
    //virtual std::any visitLiteralExpCS(OclParser::LiteralExpCSContext *ctx) override;
    
        virtual std::any visitEnumLiteralExpCS(OclParser::EnumLiteralExpCSContext *ctx) override;

        virtual std::any visitNullLiteralExpCS(OclParser::NullLiteralExpCSContext *ctx) override;

        virtual std::any visitInvalidLiteralExpCS(OclParser::InvalidLiteralExpCSContext *ctx) override; 
        
        // BEGIN_PLE implements abstract
        //virtual std::any visitPrimitiveLiteralExpCS(OclParser::PrimitiveLiteralExpCSContext *ctx) override;

            virtual std::any visitBooleanLiteralExpCS(OclParser::BooleanLiteralExpCSContext *ctx) override;

            virtual std::any visitStringLiteralExpCS(OclParser::StringLiteralExpCSContext *ctx) override;

            // BEGIN NLE implements abstract of 
            //visitNumericLiteralExpCS -> is abstract class

                virtual std::any visitRealLiteralExpCS(OclParser::RealLiteralExpCSContext *ctx) override;

                //WIP
                virtual std::any visitUnlimitedNaturalLiteralExpCS(OclParser::UnlimitedNaturalLiteralExpCSContext *ctx) override;

                virtual std::any visitIntegerLiteralExpCS(OclParser::IntegerLiteralExpCSContext *ctx) override;

            //END_NLE

        //END_PLE

        //CON
        virtual std::any visitCollectionLiteralExpCS(OclParser::CollectionLiteralExpCSContext *ctx) override;

            //CON
            virtual std::any visitCollectionLiteralPartsCS(OclParser::CollectionLiteralPartsCSContext *ctx) override;
            
            //CON
            virtual std::any visitCollectionRangeCS(OclParser::CollectionRangeCSContext *ctx) override;
        
        //CON
        virtual std::any visitTupleLiteralExpCS(OclParser::TupleLiteralExpCSContext *ctx) override;

    //END_LE
    
    // #######################
    // ### CallExpressions ###
    // #######################

    //Begin_CE implements abstract of
    //virtual std::any visitCallExpCS(OclParser::LiteralExpCSContext *ctx) override;
    
        //BEGIN_FCE implements abstract of
        //virtual std::any visitFeatureCallExpCS(OclParser::LiteralExpCSContext *ctx) override;

            //BEGIN_NCE implements abstract of
            //virtual std::any visitNavigationCallExpCS(OclParser::LiteralExpCSContext *ctx) override;

                //CON
                virtual std::any visitAssociationClassCallExpCS_A(OclParser::AssociationClassCallExpCS_AContext *ctx) override;

                //CON
                virtual std::any visitAssociationClassCallExpCS_B(OclParser::AssociationClassCallExpCS_BContext *ctx) override;

                //CON
                virtual std::any visitPropertyCallExpCS_A(OclParser::PropertyCallExpCS_AContext *ctx) override;

                //CON
                virtual std::any visitPropertyCallExpCS_B(OclParser::PropertyCallExpCS_BContext *ctx) override;

            //END_NCE

            //CON
            virtual std::any visitOperationCallExpCS_A(OclParser::OperationCallExpCS_AContext *ctx) override;

            //CON
            virtual std::any visitOperationCallExpCS_B(OclParser::OperationCallExpCS_BContext *ctx) override;

        //END_FCE

        //BEGIN_LE implements abstract of
        //LoopExpressions

            // CON
            virtual std::any visitIteratorExpCS(OclParser::IteratorExpCSContext *ctx) override;

            // CON
            virtual std::any visitIterateExpCS(OclParser::IterateExpCSContext *ctx) override;


        //END_LE

    //END_CE

    // ####################
    // ### IfExpression ###
    // ####################

        // CON
        virtual std::any visitIfExpCS(OclParser::IfExpCSContext *ctx) override;


    // ###########################
    // ### VariableExpressions ###
    // ###########################

        // CON
        virtual std::any visitVariableExpCS(OclParser::VariableExpCSContext *ctx) override;

    // #####################
    // ### LetExpression ###
    // #####################

    // CON
    virtual std::any visitLetExpCS(OclParser::LetExpCSContext *ctx) override;

    // #######################
    // ### TypeExpressions ###
    // #######################

    //BEGIN_TE
    // CON
    virtual std::any visitTypeCS(OclParser::TypeCSContext *ctx) override;
    
        // CON
        virtual std::any visitTupleTypeCS(OclParser::TupleTypeCSContext *ctx) override;

        // CON
        virtual std::any visitCollectionTypeCS(OclParser::CollectionTypeCSContext *ctx) override;

    //END_TE

    // ##########################
    // ### MessageExpressions ###
    // ##########################

    // CON
    virtual std::any visitOclMessageExpCS(OclParser::OclMessageExpCSContext *ctx) override;

    // CON
    virtual std::any visitOclMessageArgumentsCS(OclParser::OclMessageArgumentsCSContext *ctx) override;

    // #########################
    // ### State Expressions ###
    // #########################

    // no further rules exist

    // ########################
    // ### Misc Expressions ###
    // ########################

    // CON
    virtual std::any visitPrefixedExp(OclParser::PrefixedExpContext *ctx) override;

    // CON
    virtual std::any visitVariableDeclarationCS(OclParser::VariableDeclarationCSContext *ctx) override;

    // CON
    virtual std::any visitParentedExpCS(OclParser::ParentedExpCSContext *ctx) override;

    // ###########################
    // ### Context Expressions ###
    // ###########################

    // CON
    virtual std::any visitPackageDeclarationCS(OclParser::PackageDeclarationCSContext *ctx) override;
    
    // CON
    virtual std::any visitClassifierContextDeclCS(OclParser::ClassifierContextDeclCSContext *ctx) override;

    // CON
    virtual std::any visitPropertyContextDeclCS(OclParser::PropertyContextDeclCSContext *ctx) override;
    
    // CON
    virtual std::any visitOperationContextDeclCS(OclParser::OperationContextDeclCSContext *ctx) override;

    // CON
    virtual std::any visitOperationCS(OclParser::OperationCSContext *ctx) override;
    
    // CON
    virtual std::any visitPrePostOrBodyDeclCS(OclParser::PrePostOrBodyDeclCSContext *ctx) override;
    
    // CON
    virtual std::any visitPrePostBodyExpCS(OclParser::PrePostBodyExpCSContext *ctx) override;

    // CON
    virtual std::any visitInitOrDerValueListCS(OclParser::InitOrDerValueListCSContext *ctx) override;
    
    // CON
    virtual std::any visitInitOrDerValueCS(OclParser::InitOrDerValueCSContext *ctx) override;

    // CON
    virtual std::any visitInvOrDefCS(OclParser::InvOrDefCSContext *ctx) override;

    // CON
    virtual std::any visitDefExpressionCS(OclParser::DefExpressionCSContext *ctx) override;

    protected:

    virtual std::any customVisitChildren(std::any node, antlr4::tree::ParseTree *antlrTree);

    // ##########################
    // ### Handling Functions ###
    // ##########################
    
    // handling tasks for aggregateResult
    // because they work on shared_ptr they do not need to return anything
    // BEGIN_HM

        virtual void handleExpressionInOcl(std::any aggregate, std::any nextResult); 
        
        virtual void handleCollectionLiteralExpression(std::any aggregate, std::any nextResult);

        virtual void handleCollectionLiteralParts(std::any aggregate, std::any nextResult);
        
        virtual void handleCollectionRange(std::any aggregate, std::any nextResult);

        virtual void handleTupleLiteralExpression(std::any aggregate, std::any nextResult);

        virtual void handleAssociationClassExp(std::any aggregate, std::any nextResult);

        //virtual void handlePropertyCallExp(std::any aggregate, std::any nextResult);

        virtual void handleOperationCallExp(std::any aggregate, std::any nextResult);

        virtual void handleIteratorExp(std::any aggregate, std::any nextResult);

        virtual void handleIterateExp(std::any aggregate, std::any nextResult);

        virtual void handleIfExp(std::any aggregate, std::any nextResult);

        virtual void handleLetExp(std::any aggregate, std::any nextResult);

        //virtual void handleTypeExp(std::any aggregate, std::any nextResult);

        virtual void handleTupleTypeExp(std::any aggregate, std::any nextResult);

        virtual void handleCollectionTypeExp(std::any aggregate, std::any nextResult);

        virtual void handleMessageExp(std::any aggregate, std::any nextResult);
        
        virtual void handleMessageArguments(std::any aggregate, std::any nextResult);

        virtual void handleVarDeclarationExp(std::any aggregate, std::any nextResult);

        virtual void handlePrefixedExp(std::any aggregate, std::any nextResult);

        virtual void handleParentedExp(std::any aggregate, std::any nextResult);

        virtual void handleOperatorExp(std::any aggregate, std::any nextResult);

        virtual void handlePackageContextDeclExp(std::any aggregate, std::any nextResult);

        virtual void handleClassifierContextDeclExp(std::any aggregate, std::any nextResult);

        virtual void handlePropertyContextDeclExp(std::any aggregate, std::any nextResult);

        virtual void handleOperationContextDecl(std::any aggregate, std::any nextResult);

        virtual void handleOperationContextExp(std::any aggregate, std::any nextResult);

        virtual void handlePrePostBodyListExp(std::any aggregate, std::any nextResult);
        
        virtual void handlePrePostBodyExp(std::any aggregate, std::any nextResult);

        virtual void handleInitOrDerValueListExp(std::any aggregate, std::any nextResult);

        virtual void handleInitOrDerValueExp(std::any aggregate, std::any nextResult);

        virtual void handleInvOrDefExp(std::any aggregate, std::any nextResult);

        virtual void handleDefExp(std::any aggregate, std::any nextResult);

    // END_HM

    // ####################################
    // ### nextResultHandling Functions ###
    // ####################################

    //BEGIN_NRHM

        // CON
        virtual void nR_HandlingAssociationCallExp(std::any aggregate, std::any nextResult);

        // CON
        virtual void nR_HandlingPropertyCallExp(std::any aggregate, std::any nextResult);

        // CON
        virtual void nR_HandlingOperationCallExp(std::any aggregate, std::any nextResult);

        // CON
        virtual void nR_HandlingIteratorExp(std::any aggregate, std::any nextResult);

        // CON
        virtual void nR_HandlingIterateExp(std::any aggregate, std::any nextResult);

        // CON
        virtual void nR_HandlingMessageExp(std::any aggregate, std::any nextResult);

        //helper function for CallExp
        //append correctly AppliedElement
        template <class T>
        void setAppliedElement(std::any parent, std::any child) {

            //recast the expressions
            std::shared_ptr<ocl::Expressions::CallExp> callExp = std::any_cast<T>(child);
            std::shared_ptr<ocl::Expressions::OclExpression> oclExp = Utilities::oclCV::exp2oclExp(parent);

            //check if the parent is an operatorExp -> the appliedExp can't be a Operand
            std::shared_ptr<ocl::Expressions::OperatorExp> operaExp = std::dynamic_pointer_cast<ocl::Expressions::OperatorExp>(oclExp);
            bool isNotOperand = true;
            if (operaExp != nullptr) {
                if (operaExp->getLeftHandOperand() == callExp || operaExp->getRightHandOperand() == callExp) {
                    isNotOperand = false;
                }
            }

            //check if it is an ifExpr
            std::shared_ptr<ocl::Expressions::IfExp> ifExp = std::dynamic_pointer_cast<ocl::Expressions::IfExp>(oclExp);
            bool isNotInIfExp = true;
            if (ifExp != nullptr) {
                //check condition
                if (ifExp->getCondition() == callExp) {
                    isNotInIfExp = false;
                } else if (ifExp->getThenExpression() == callExp) {
                    isNotInIfExp = false;
                } else if (ifExp->getElseExpression() == callExp) {
                    isNotInIfExp = false;
                }
            }

            //check if it is an letExp
            std::shared_ptr<ocl::Expressions::LetExp> letExp = std::dynamic_pointer_cast<ocl::Expressions::LetExp>(oclExp);
            bool isNotInPart = true;
            if (letExp != nullptr) {
                if (letExp->getIn() == callExp) {
                    isNotInPart = false;
                }
            }

            //check if it is an prefixedExp
            std::shared_ptr<ocl::Expressions::PrefixedExp> prefExp = std::dynamic_pointer_cast<ocl::Expressions::PrefixedExp>(oclExp);
            bool isNotReferredPart = true;
            if (prefExp != nullptr) {
                if (prefExp->getReferredExpression() == callExp) {
                    isNotReferredPart = false;
                }
            }

            //check if it is an varDeclExp
            std::shared_ptr<ocl::Expressions::VarDeclarationExp> varDeclExp = std::dynamic_pointer_cast<ocl::Expressions::VarDeclarationExp>(oclExp);
            bool isNotAssignedPart = true;
            if (varDeclExp != nullptr) {
                if (varDeclExp->getAssignedOclExp() == callExp) {
                    isNotAssignedPart = false;
                }
            }

            // continued from underneath
            //third check (isNotOperand): (x.y=z), without check interpreted as (x.y=z).x.y
            //fourth check (isNotInIfExp): if x.y then z.t else z.w , e.g. without check interpreted as (if x.y then z.t else z.w).x.y
            //fifth check (isNotInPart): let ... in x, without check interpreted as (let ... in x).x (would return value of y instead of body x)
            //sixth check (isNotReferredPart): somewhere above is y declared: x = not y, without check interpreted as x = (not y).y (would return value of y instead of x)
            //seventh part (isNotAssignedPart): x = y, without check interpreted as (x = y).y (would return value of y instead of x)
            bool valid = isNotOperand && isNotInIfExp && isNotInPart && isNotReferredPart && isNotAssignedPart;


            //first check avoid: real qry: operation(elem), without check interpreted as -> operation(elem).elem
            //second check avoid: real qry: ...->iterate(sth-with-acc-and-elem), without check interpreted as ...->iterate(sth-with-acc-and-elem).acc
            // following see valid
            if (oclExp != callExp->getParentCall().lock() && oclExp != callExp->getLoopBodyOwner().lock() && valid) {

                // if there is already an 'applied_element' at the oclExp this element have to be the source of this propExp
                while(oclExp->getAppliedElement() != nullptr) {
                    oclExp = oclExp->getAppliedElement();
                }

                callExp->setSource(oclExp);
                oclExp->setAppliedElement(callExp);

            }

        }

    //END_NRHM
};
}
#endif // OCLPARSERCUSTOMVISITOR_H
