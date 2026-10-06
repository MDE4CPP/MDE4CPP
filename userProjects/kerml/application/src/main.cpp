
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "kerml/kermlFactory.hpp"
#include "kerml/kermlPackage.hpp"

#include "kerml/TextualRepresentation.hpp"
#include "kerml/AnnotatingElement.hpp"
#include "kerml/Element.hpp"
#include "kerml/OwningMembership.hpp"
#include "kerml/Membership.hpp"
#include "kerml/Relationship.hpp"
#include "kerml/Namespace.hpp"
#include "kerml/Import.hpp"
#include "kerml/Documentation.hpp"
#include "kerml/Comment.hpp"
#include "kerml/Annotation.hpp"
#include "kerml/MembershipImport.hpp"
#include "kerml/NamespaceImport.hpp"
#include "kerml/Dependency.hpp"
#include "kerml/CrossSubsetting.hpp"
#include "kerml/Subsetting.hpp"
#include "kerml/Specialization.hpp"
#include "kerml/Type.hpp"
#include "kerml/FeatureMembership.hpp"
#include "kerml/Feature.hpp"
#include "kerml/Redefinition.hpp"
#include "kerml/FeatureTyping.hpp"
#include "kerml/TypeFeaturing.hpp"
#include "kerml/FeatureInverting.hpp"
#include "kerml/FeatureChaining.hpp"
#include "kerml/ReferenceSubsetting.hpp"
#include "kerml/Conjugation.hpp"
#include "kerml/Multiplicity.hpp"
#include "kerml/Intersecting.hpp"
#include "kerml/Unioning.hpp"
#include "kerml/Disjoining.hpp"
#include "kerml/Differencing.hpp"
#include "kerml/EndFeatureMembership.hpp"
#include "kerml/Classifier.hpp"
#include "kerml/Subclassification.hpp"
#include "kerml/Succession.hpp"
#include "kerml/Connector.hpp"
#include "kerml/Association.hpp"
#include "kerml/BindingConnector.hpp"
#include "kerml/MultiplicityRange.hpp"
#include "kerml/Expression.hpp"
#include "kerml/Step.hpp"
#include "kerml/Behavior.hpp"
#include "kerml/Class.hpp"
#include "kerml/Function.hpp"
#include "kerml/Invariant.hpp"
#include "kerml/BooleanExpression.hpp"
#include "kerml/Predicate.hpp"
#include "kerml/ReturnParameterMembership.hpp"
#include "kerml/ParameterMembership.hpp"
#include "kerml/ResultExpressionMembership.hpp"
#include "kerml/FeatureValue.hpp"
#include "kerml/LibraryPackage.hpp"
#include "kerml/Package.hpp"
#include "kerml/ElementFilterMembership.hpp"
#include "kerml/NullExpression.hpp"
#include "kerml/LiteralInfinity.hpp"
#include "kerml/LiteralExpression.hpp"
#include "kerml/LiteralInteger.hpp"
#include "kerml/LiteralString.hpp"
#include "kerml/LiteralBoolean.hpp"
#include "kerml/SelectExpression.hpp"
#include "kerml/OperatorExpression.hpp"
#include "kerml/InvocationExpression.hpp"
#include "kerml/InstantiationExpression.hpp"
#include "kerml/CollectExpression.hpp"
#include "kerml/FeatureReferenceExpression.hpp"
#include "kerml/IndexExpression.hpp"
#include "kerml/MetadataAccessExpression.hpp"
#include "kerml/MetadataFeature.hpp"
#include "kerml/Metaclass.hpp"
#include "kerml/Structure.hpp"
#include "kerml/ConstructorExpression.hpp"
#include "kerml/LiteralRational.hpp"
#include "kerml/FeatureChainExpression.hpp"
#include "kerml/PayloadFeature.hpp"
#include "kerml/Interaction.hpp"
#include "kerml/FlowEnd.hpp"
#include "kerml/SuccessionFlow.hpp"
#include "kerml/Flow.hpp"
#include "kerml/AssociationStructure.hpp"
#include "kerml/DataType.hpp"
#include "kerml/VisibilityKind.hpp"
#include "kerml/FeatureDirectionKind.hpp"

#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"

#include "kermlTypes/kermlTypesPackage.hpp"
#include "ecore/EDataType.hpp"


#include "abstractDataTypes/Any.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
//#include "pluginFramework/PluginFramework.hpp" // can be used, if external (model independent) library can be specified inside the ecore model
#include "pluginFramework/MDE4CPPPlugin.hpp"



// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace kerml;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<kermlFactory> factory = kermlFactory::eInstance();

	kermlTypes::kermlTypesPackage::eInstance();
	
	//Create Type model factory
	std::shared_ptr<kermlTypes::kermlTypesPackage> typePackage =kermlTypes::kermlTypesPackage::eInstance();
	
	// Create Package
	std::shared_ptr<kerml::Package> addressBookPck = factory->createPackage();
	addressBookPck->setName("AddressBookModel2");
	std::cout << "Package name " << addressBookPck->getName() << std::endl;
	
	// ScalarValue Package
	std::shared_ptr<kerml::Package> scalarValuePackage = factory->createPackage();
	scalarValuePackage->setName("ScalarValuePackage");
	
			std::shared_ptr<kerml::DataType> stringType = factory->createDataType_as_ownedMember_in_Namespace(scalarValuePackage);
			stringType->setName("String");
			
			std::shared_ptr<kerml::DataType> integerType = factory->createDataType_as_ownedMember_in_Namespace(scalarValuePackage);
			integerType->setName("Integer");
	

		
		// Entry Class
			std::shared_ptr<kerml::Class> entryClass = factory->createClass_as_ownedMember_in_Namespace(addressBookPck);
			entryClass->setName("Entry");
			

		
			//Features and feature Type
				//--entryClassFeature
					std::shared_ptr<kerml::Feature> nameFeature = factory->createFeature_as_ownedFeature_in_Type(entryClass);
					nameFeature->setName("name");
					
					std::shared_ptr<kerml::FeatureTyping> nameFeatureType = factory->createFeatureTyping_as_ownedTyping_in_Feature(nameFeature);
					nameFeatureType->setType(stringType);
					
				
				// idFeature
					std::shared_ptr<kerml::Feature> idFeature = factory->createFeature_as_ownedFeature_in_Type(entryClass);
					idFeature->setName("id");
					
					
					std::shared_ptr<kerml::FeatureTyping> idFeatureTyping = factory->createFeatureTyping_as_ownedTyping_in_Feature(idFeature);
					idFeatureTyping->setType(integerType);
					
						
				//--addressFeature 
					std::shared_ptr<kerml::Feature> addressFeature = factory->createFeature_as_ownedFeature_in_Type(entryClass);
					addressFeature->setName("address");
					
					std::shared_ptr<kerml::FeatureTyping> addressFeatureTyping = factory->createFeatureTyping_as_ownedTyping_in_Feature(addressFeature);
					addressFeatureTyping->setType(stringType);
					
				
				
					
			
		// address book
			std::shared_ptr<kerml::Class> addressBookCls = factory->createClass_as_ownedMember_in_Namespace(addressBookPck);
			addressBookCls->setName("AddressBook");
			
			// Features and types
				std::shared_ptr<kerml::Feature> entriesFeature = factory->createFeature_as_ownedFeature_in_Type(addressBookCls);
				entriesFeature->setName("entries");
				
				
			// Create FeatureTyping for "entries"
					std::shared_ptr<kerml::FeatureTyping> entriesFeatureType =
						factory->createFeatureTyping_as_ownedTyping_in_Feature(entriesFeature);
				
					entriesFeatureType->setType(entryClass);
				
					// Creating multiplicity for "entries"
					std::shared_ptr<kerml::MultiplicityRange> entriesMultiplicity =
						factory->createMultiplicityRange_as_multiplicity_in_Type(entryClass);
				
					std::shared_ptr<kerml::LiteralInteger> lowerBound =
						factory->createLiteralInteger_as_lowerBound_in_MultiplicityRange(entriesMultiplicity);
					lowerBound->setValue(0);
				
					std::shared_ptr<kerml::LiteralInteger> upperBound =
						factory->createLiteralInteger_as_upperBound_in_MultiplicityRange(entriesMultiplicity);
					upperBound->setValue(-1);
				
				/*
					if (entryClass->getMultiplicity())
					{
						std::cout << "Multiplicity successfully assigned." << std::endl;
					}
					else
					{
						std::cout << "Multiplicity assignment failed." << std::endl;
					}
				
					if (entriesMultiplicity->getLowerBound())
					{
						std::cout << "Lower bound = "
								<< std::dynamic_pointer_cast<kerml::LiteralInteger>(
										entriesMultiplicity->getLowerBound())->getValue()
								<< std::endl;
					}
				
					if (entriesMultiplicity->getUpperBound())
					{
						std::cout << "Upper bound = "
								<< std::dynamic_pointer_cast<kerml::LiteralInteger>(
										entriesMultiplicity->getUpperBound())->getValue()
								<< std::endl;
					}
					
					*/
													
					
	
		std::cout << "Class Name: " << entryClass->getName() << std::endl;
			
			std::cout << "\n" << std::endl;
			
			std::cout << "Features: "
			<<"\n"
			<< nameFeature->getName()
			<< "-> "
			<< nameFeatureType->getType()->getName()
			<< "\n"
			<< idFeature->getName()
			<<"->" 
			<<idFeatureTyping->getType()->getName()
			<<"\n " 
			<<addressFeature->getName()
			<<"->"
			<<addressFeatureTyping->getType()->getName()
			<< std::endl;
			
			 
			
		std::cout << "\n\n" << std::endl;
		
		
		std::cout << "Class name: " << addressBookCls->getName()  << std::endl;
				
				std::cout<< "\n " << std::endl;
				
				std::cout << "AddressBookFeature: "
				<< entriesFeature->getName()
				<< " -> "
				<< entriesFeatureType->getType()->getName()
				<< "["
				<< (upperBound->getValue() == -1
						? "*"
						: std::to_string(upperBound->getValue()))
				<< "]"
				<< std::endl;

				//std::cout << "New generation!" << std::endl;
		
		
		
		
		

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}
