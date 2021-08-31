package ecore4CPP.generator.main.validation;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import org.eclipse.emf.common.EMFPlugin;
import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EClassifier;
import org.eclipse.emf.ecore.EDataType;
import org.eclipse.emf.ecore.EEnum;
import org.eclipse.emf.ecore.EEnumLiteral;
import org.eclipse.emf.ecore.ENamedElement;
import org.eclipse.emf.ecore.EOperation;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.EParameter;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.emf.ecore.EStructuralFeature;
import org.eclipse.emf.ecore.ETypedElement;

/**
 * Service class to report model errors found during C++ source code generation of given ecore model<br>
 * Provided functionality:<br>
 * <ul>
 *  <li>Model validation</li>
 * 	<li>Registering errors</li>
 *  <li>Registering warnings</li>
 *  <li>Log errors, warnings and info</li>
 *  <li>Exit java program with error code, if at least one error is registered and generator is running outside of eclipse</li>
 * </ul>
 * Functionality is triggered once at the beginning of the generation process.<br>
 * <br><br> 
 * 
 * @author Maximilian Hammer, Alexander Wichmann
 *
 */
public class ValidationService {
	
	/**
	 * Enumeration to represent different severity levels of Ecore4CPPMessage objects
	 *<ul>
     *	<li>INFO : message represents basic information for the user</li>
     * 	<li>WARNING : messages warns about a potential error. This does not necessarily abort the generation but it may result in erroneous generation</li>
     * 	<li>ERROR : messages containing errors during model validation. This should abort generation</li>
	 * </ul>
	 */
	private enum Ecore4CPPMessageServerityLevel
	{
		INFO,
		WARNING,
		ERROR
	}
	
	/**
	 * Class that holds constants for manipulating the color of text printed to the console via ANSI escape sequences
	 */
	private static class Ecore4CPPConsoleManipulator
	{
		public static final String ANSI_RESET = "\u001B[0m";
		public static final String ANSI_RED = "\u001B[31m";
		public static final String ANSI_GREEN = "\u001B[32m";
		public static final String ANSI_YELLOW = "\u001B[33m";
		
		public static final Map<Ecore4CPPMessageServerityLevel, String> ANSI_MAP = Map.of(
				Ecore4CPPMessageServerityLevel.INFO, ANSI_GREEN, 
				Ecore4CPPMessageServerityLevel.WARNING, ANSI_YELLOW,
				Ecore4CPPMessageServerityLevel.ERROR, ANSI_RED
				);
	}
	
	/**
	 * Class that represents a message. Contains info about the severity level of the message, the message itself and potentially the name of the function which created the message
	 */
	private class Ecore4CPPMessage
	{
		private String m_message, m_callingOperation;
		private Ecore4CPPMessageServerityLevel m_level;
		
		@SuppressWarnings("unused")
		public Ecore4CPPMessage() 
		{
			m_message = m_callingOperation = "";
			m_level = Ecore4CPPMessageServerityLevel.INFO;
		}
		
		public Ecore4CPPMessage(Ecore4CPPMessageServerityLevel level, String message, String callingOperation)
		{
			m_level = level;
			m_message = message;
			m_callingOperation = callingOperation;
		}
		
		public void print()
		{	
			String printedMessage = "[" + 
									Ecore4CPPConsoleManipulator.ANSI_MAP.get(m_level) +  m_level.name() + Ecore4CPPConsoleManipulator.ANSI_RESET + 
									"] :\t" + 
									m_message + 
									((m_callingOperation.isEmpty()) ? "" : ("\n\t\t(from " + m_callingOperation + ")"));
			System.out.println(printedMessage);
		}
	}

/**
 * Private member attributes
 */
		private List<Ecore4CPPMessage> errors;
		private List<Ecore4CPPMessage> warnings;
		private Boolean validationStatus = false;
		private Boolean warningsDisabled = false;
		
/**
 * Private utility methods
 */
		/**
		 * Add {@code message} to internal error list
		 * @param message String representing error message
		 */
		private void registerError(Ecore4CPPMessage message)
		{
			errors.add(message);
		}
		
		/**
		 * Add {@code message} to internal warning list
		 * @param message String representing warning
		 */
		private void registerWarning(Ecore4CPPMessage message)
		{
			warnings.add(message);
		}
		
	/**
	 * Public utility methods
	 */
		/**
		 * Constructor<br>
		 */
		public ValidationService() 
		{
			errors = new ArrayList<Ecore4CPPMessage>();
			warnings = new ArrayList<Ecore4CPPMessage>();
		}
		
		/**
		 * Checks, if at least one error is registered
		 * @return true if error exist, otherwise false
		 */
		public boolean errorsExist()
		{
			return errors.size() > 0;
		}
		
		/**
		 * Checks, if at least one warning is registered
		 * @return true if warnings exist, otherwise false
		 */
		public boolean warningsExist()
		{
			return warnings.size() > 0;
		}
		
		/**
		 * Indicates, if the model has already been validated
		 * @return true if validation process already passed, otherwise false
		 */
		public boolean getValidationStatus()
		{
			return validationStatus;
		}

		/**
		 * Sets the status of the validation (true - performed, false - not yet performed)
		 * @param status - the validation status
		 */
		public void setValidationStatus(Boolean status)
		{
			validationStatus = status;
		}
		
		/**
		 * Disables the print of warning messages
		 */
		public void disableWarnings()
		{
			warningsDisabled = true;
		}
		
		/**
		 * Enables the print of warning messages
		 */
		public void enableWarnings()
		{
			warningsDisabled = false;
		}
		
		/**
		 * Logs all registered errors
		 */
		public void printErrors()
		{
			if (errorsExist())
			{
				System.err.println("Validation failed with the following errors:");
				System.out.println("--------------------------------------------\n");
				for (Ecore4CPPMessage errorMessage : errors) {
					errorMessage.print();
				}
			}
		}
		
		/**
		 * Logs all registered warnings
		 */
		public void printWarnings()
		{
			if (warningsExist())
			{
				if(warningsDisabled)
				{
					printInfo("Warnings disabled!", "");
				}
				
				else {
				System.out.println("Warnings during validation (NOTE: generation might not work correctly):");
				System.out.println("-----------------------------------------------------------------------\n");

					for (Ecore4CPPMessage warningMessage : warnings) {
						warningMessage.print();
					}
				}
			}
		}
		
		/**
		 * Creates and prints a new Info message
		 */
		public void printInfo(String message, String callingOperation)
		{
			Ecore4CPPMessage infoMessage = new Ecore4CPPMessage(Ecore4CPPMessageServerityLevel.INFO, message, callingOperation);
			infoMessage.print();
		}
		
		/**
		 * Creates and prints a new Warning message (if warnings are enabled)
		 */
		public void printWarning(String message, String callingOperation)
		{
			if(!warningsDisabled)
			{
				Ecore4CPPMessage warningMessage = new Ecore4CPPMessage(Ecore4CPPMessageServerityLevel.WARNING, message, callingOperation);
				warningMessage.print();
			}
		}
		
		/**
		 * Creates and prints a new Error message
		 */
		public void printError(String message,  String callingOperation)
		{
			
			Ecore4CPPMessage errorMessage = new Ecore4CPPMessage(Ecore4CPPMessageServerityLevel.ERROR, message, callingOperation);
			errorMessage.print();
		}
		
		/**
		 * if error is registered and generator is running outside of eclipse, application will be closed with given number
		 * @param number - exit code to be used during application exit, {@value 0} - close without error notification, otherwise close with error notification 
		 */
		public void closeWithErrorExit(Integer number)
		{
			if (!EMFPlugin.IS_ECLIPSE_RUNNING)
			{
				System.exit(number);
			}
		}

	/**
	 * Private validation methods
	 */

		/**
		 * Validates properties constrained by metaclass ENamedElement
		 * This includes:
		 * 	- check if the 'name' property is set
		 */
		private void validateENamedElement(ENamedElement eNamedElement)
		{
			if(eNamedElement.getName().isEmpty())
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined 'name' for instance of ENamedElement : " + getPrintableName(eNamedElement),
						this.getClass().getName() + ":validateENamedElement"));
			}
		}
		
		/**
		 * Creates a printable String-representation of a NamedElement
		 * Returns the qualified name of the element if present, or else calls "toString()".
		 */
		private String getPrintableName(ENamedElement eNamedElement)
		{
			if(eNamedElement.getName().isEmpty())
			{
				return eNamedElement.toString();
			}
			else
			{
				String qualifiedName = "";
				while(eNamedElement != null)
				{
					qualifiedName = eNamedElement.getName() + (qualifiedName.isEmpty() ? "" : "::") + qualifiedName;
					if(eNamedElement instanceof EClassifier)
					{
						eNamedElement = ((EClassifier)eNamedElement).getEPackage();
					}
					else if(eNamedElement instanceof EStructuralFeature)
					{
						eNamedElement = ((EStructuralFeature)eNamedElement).getEContainingClass();
					}
					else if(eNamedElement instanceof EOperation)
					{
						eNamedElement = ((EOperation)eNamedElement).getEContainingClass();
					}
					else if(eNamedElement instanceof EParameter)
					{
						eNamedElement = ((EParameter)eNamedElement).getEOperation();
					}
					else if(eNamedElement instanceof EEnumLiteral)
					{
						eNamedElement = ((EEnumLiteral)eNamedElement).getEEnum();
					}
					else {
						eNamedElement = null;
					}
				}
				
				return qualifiedName;
			}
		}
		
		/**
		 * Validates properties constrained by metaclass EPackage
		 * This includes:
		 * 	- check if the EPackage is null
		 */
		public void validateEPackage(EPackage ePackage)
		{
			if(ePackage == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EPackage",
						this.getClass().getName() + ":validateEPackage"));
				
				return;
			}
			
			validateENamedElement(ePackage);
			
			String messageInstanceSuffix = " for instance of EPackage : " + getPrintableName(ePackage);
			
			{
				List<String> eSubPackagesNames = ePackage.getESubpackages().stream().map(EPackage::getName).collect(Collectors.toList());
				Set<String> duplicateESubPackagesNames = findDuplicates(eSubPackagesNames);
				
				if(!duplicateESubPackagesNames.isEmpty())
				{
					for(String duplicateESubPackagesName : duplicateESubPackagesNames)
					{
						registerWarning(new Ecore4CPPMessage(
								Ecore4CPPMessageServerityLevel.WARNING,
								"Multiple sub packages with name '" + duplicateESubPackagesName + "'" + messageInstanceSuffix
								+ "\n- Generated files might be overridden",
								this.getClass().getName() + ":validateEPackage"));
					}
				}
			}
			
			{
				List<String> eClassifiersNames = ePackage.getEClassifiers().stream().map(EClassifier::getName).collect(Collectors.toList());
				Set<String> duplicateEClassifiersNames = findDuplicates(eClassifiersNames);
				
				if(!duplicateEClassifiersNames.isEmpty())
				{
					for(String duplicateEClassifiersName : duplicateEClassifiersNames)
					{
						registerWarning(new Ecore4CPPMessage(
								Ecore4CPPMessageServerityLevel.WARNING,
								"Multiple contained classifiers with name '" + duplicateEClassifiersName + "'" + messageInstanceSuffix 
								+ "\n- Possible naming conflicts\n- Generated files might be overridden",
								this.getClass().getName() + ":validateEPackage"));
					}
				}
			}
		}
		
		/**
		 * Validates properties constrained by metaclass EEnumLiteral
		 * This includes:
		 * 	- check if the EEnumLiteral is null
		 *  - check if the containing EEnum is null
		 */
		public void validateEEnumLiteral(EEnumLiteral eEnumLiteral)
		{
			if(eEnumLiteral == null)
			{			
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EEnumLiteral",
						this.getClass().getName() + ":validateEEnumLiteral"));
				
				return;
			}
			
			validateENamedElement(eEnumLiteral);
			
			if(eEnumLiteral.getEEnum() == null)
			{		
				registerWarning(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.WARNING,
						"Undefined 'eEnum' for instance of EEnumerationLiteral : " + getPrintableName(eEnumLiteral),
						this.getClass().getName() + ":validateEEnumLiteral"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass ETypedElement
		 * This includes:
		 * 	- check if the 'lowerBound' property is greater or equal to 0
		 *  - check if the 'upperBound' property is valid (not =0 and not <-1)
		 *  - check if the 'lowerBound' property is smaller than the "upperBound" property (except if upperBound == -1)
		 */
		private void validateETypedElement(ETypedElement eTypedElement)
		{
			validateENamedElement(eTypedElement);
			
			String messageInstanceSuffix = " for instance of ETypedElement : " + getPrintableName(eTypedElement);
			
			if(eTypedElement.getLowerBound() < 0)
			{		
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Invalid 'lowerBound' of " + eTypedElement.getLowerBound() + messageInstanceSuffix,
						this.getClass().getName() + ":validateETypedElement"));
			}
			
			if(eTypedElement.getUpperBound() == 0 || eTypedElement.getUpperBound() < -1)
			{			
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Invalid 'upperBound' of " + eTypedElement.getUpperBound() + messageInstanceSuffix,
						this.getClass().getName() + ":validateETypedElement"));
			}
			
			if((eTypedElement.getUpperBound() > 0) && (eTypedElement.getLowerBound() > eTypedElement.getUpperBound()))
			{				
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"'lowerBound' of " + eTypedElement.getLowerBound() + " is greater than 'upperBound' of " + eTypedElement.getUpperBound() + messageInstanceSuffix,
						this.getClass().getName() + ":validateETypedElement"));
			}
			
			if((eTypedElement.getUpperBound() > 1 || eTypedElement.getUpperBound() == -1) && (eTypedElement.getLowerBound() > 0))
			{				
				registerWarning(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.WARNING,
						"[n..*] or [n..m] multiplicity will be generated as [0..*] multiplicity" + messageInstanceSuffix,
						this.getClass().getName() + ":validateETypedElement"));
			}
			
			/*
			 * NOTE: 'eType' of ETypedElement will be checked in validation methods for subclasses,
			 * as EOperations are allowed to be of undefined type (which will be interpreted as 'void' during generation)
			 */
		}
		
		/**
		 * Validates properties constrained by metaclass EOperation
		 * This includes:
		 * 	- check if the the EOperation is null
		 *  - check if the containing class is null
		 */
		public void validateEOperation(EOperation eOperation)
		{
			if(eOperation == null)
			{			
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EOperation",
						this.getClass().getName() + ":validateEOperation"));
				
				return;
			}
			
			validateETypedElement(eOperation);
			
			String messageInstanceSuffix = " for instance of EOperation : " + getPrintableName(eOperation);
			
			if(eOperation.getEContainingClass() == null) 
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined 'eContainingClass'" + messageInstanceSuffix,
						this.getClass().getName() + ":validateEOperation"));
			}
			
			{
				List<String> eParameterNames = eOperation.getEParameters().stream().map(EParameter::getName).collect(Collectors.toList());
				Set<String> duplicateEParameterNames = findDuplicates(eParameterNames);
				
				if(!duplicateEParameterNames.isEmpty())
				{
					for(String duplicateEParameterName : duplicateEParameterNames)
					{
						registerWarning(new Ecore4CPPMessage(
								Ecore4CPPMessageServerityLevel.WARNING,
								"Multiple parameters with name '" + duplicateEParameterName + "'" + messageInstanceSuffix
								+ "\n- Possible naming conflicts",
								this.getClass().getName() + ":validateEOperation"));
					}
				}
			}
		}
		
		/**
		 * Validates properties constrained by metaclass EParameter
		 * This includes:
		 * 	- check if the the EParameter is null
		 *  - check if the containing operation is null
		 *  - check if the 'eType' property is valid
		 */
		public void validateEParameter(EParameter eParameter)
		{
			if(eParameter == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EParameter",
						this.getClass().getName() + ":validateEParameter"));

				return;
			}
			
			validateETypedElement(eParameter);
			
			String messageInstanceSuffix = " for instance of EParameter : " + getPrintableName(eParameter);
			
			if(eParameter.getEOperation() == null) 
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined 'eOperation'" + messageInstanceSuffix,
						this.getClass().getName() + ":validateEParameter"));
			}
			
			if(eParameter.getEType() == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined 'eType'" + messageInstanceSuffix,
						this.getClass().getName() + ":validateEParameter"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass EStructuralFeature
		 * This includes:
		 * 	- check if the the EStructuralFeature is null
		 *  - check if the containing class is null
		 *  - check if the 'eType' property is valid
		 */
		private void validateEStructuralFeature(EStructuralFeature eStructuralFeature)
		{
			if(eStructuralFeature == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EStructuralFeature",
						this.getClass().getName() + ":validateEStructuralFeature"));
				
				return;
			}
			
			validateETypedElement(eStructuralFeature);
			
			String messageInstanceSuffix = " for instance of EStructuralFeature : " + getPrintableName(eStructuralFeature);
			
			if(eStructuralFeature.getEContainingClass() == null) 
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined 'eContainingClass'" + messageInstanceSuffix,
						this.getClass().getName() + ":validateEStructuralFeature"));
			}
			
			if(eStructuralFeature.getEType() == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined 'eType'" + messageInstanceSuffix,
						this.getClass().getName()+ ":validateEStructuralFeature"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass EReference
		 * This includes:
		 * 	- check if the the EReference is null
		 */
		public void validateEReference(EReference eReference)
		{
			if(eReference == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EReference",
						this.getClass().getName() + ":validateEReference"));
				
				return;
			}
			
			validateEStructuralFeature(eReference);
		}
		
		/**
		 * Validates properties constrained by metaclass EAttribute
		 * This includes:
		 * 	- check if the the EAttribute is null
		 */
		public void validateEAttribute(EAttribute eAttribute)
		{
			if(eAttribute == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EAttribute",
						this.getClass().getName() + ":validateEAttribute"));
				
				return;
			}
			
			validateEStructuralFeature(eAttribute);
		}
		
		/**
		 * Validates properties constrained by metaclass EClassifier
		 */
		private void validateEClassifier(EClassifier eClassifier)
		{
			validateENamedElement(eClassifier);
		}
		
		/**
		 * Validates properties constrained by metaclass EDataType
		 * This includes:
		 * 	- check if the the EDataType is null
		 */
		public void validateEDataType(EDataType eDataType)
		{
			if(eDataType == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EDataType",
						this.getClass().getName() + ":validateEDataType"));
				
				return;
			}
			
			validateEClassifier(eDataType);
		}
		
		/**
		 * Validates properties constrained by metaclass EEnum
		 * This includes:
		 * 	- check if the EEnum is null
		 *  - check if the EEnum contains multiple literals with the same names
		 */
		public void validateEEnum(EEnum eEnum)
		{
			if(eEnum == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EEnum",
						this.getClass().getName() + ":validateEEnum"));
				
				return;
			}
			
			validateEClassifier(eEnum);
			
			String messageInstanceSuffix = " for instance of EEnum : " + getPrintableName(eEnum);
			
			{
				List<String> eEnumLiteralNames = eEnum.getELiterals().stream().map(EEnumLiteral::getName).collect(Collectors.toList());
				Set<String> duplicateEEnumLiteralNames = findDuplicates(eEnumLiteralNames);
				
				if(!duplicateEEnumLiteralNames.isEmpty())
				{
					for(String duplicateEEnumLiteralName : duplicateEEnumLiteralNames)
					{
						registerWarning(new Ecore4CPPMessage(
								Ecore4CPPMessageServerityLevel.WARNING,
								"Multiple literals with name '" + duplicateEEnumLiteralName + "'" + messageInstanceSuffix
								+ "\n- Possible naming conflicts",
								this.getClass().getName() + ":validateEEnum"));
					}
				}
			}
		}
		
		private <T> Set<T> findDuplicates(Collection<T> collection)
		{
			Set<T> uniques = new HashSet<>();
			return collection.stream().filter(element -> !uniques.add(element)).collect(Collectors.toSet());
		}
		
		/**
		 * Validates properties constrained by metaclass EClass
		 * This includes:
		 * 	- check if the EClass is null
		 *  - check if the EClass contains multiple structural features with the same names
		 *  TODO: Check for "equivalent" operations
		 */
		public void validateEClass(EClass eClass)
		{
			if(eClass == null)
			{
				registerError(new Ecore4CPPMessage(
						Ecore4CPPMessageServerityLevel.ERROR,
						"Undefined instance of EClass",
						this.getClass().getName() + ":validateEClass"));
				
				return;
			}
			
			validateEClassifier(eClass);
			
			String messageInstanceSuffix = " for instance of EClass : " + getPrintableName(eClass);
			
			List<String> eStructuralFeatureNames = eClass.getEStructuralFeatures().stream().map(EStructuralFeature::getName).collect(Collectors.toList());
			Set<String> duplicateEStructuralFeatureNames = findDuplicates(eStructuralFeatureNames);
			
			if(!duplicateEStructuralFeatureNames.isEmpty())
			{
				for(String duplicateEStructuralFeatureName : duplicateEStructuralFeatureNames)
				{
					registerWarning(new Ecore4CPPMessage(
							Ecore4CPPMessageServerityLevel.WARNING,
							"Multiple structural features with name '" + duplicateEStructuralFeatureName + "'" + messageInstanceSuffix
							+ "\n- Possible naming conflicts",
							this.getClass().getName() + ":validateEClass"));
				}
			}
		}
	
}
