package ecore4CPP.generator.main.validation;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
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
 * 	<li>registering errors</li>
 *  <li>registering warnings</li>
 *  <li>Log errors and warnings</li>
 *  <li>exit java program with error code, if at least one error is registered and generator is running outside of eclipse</li>
 * </ul>
 * Functionality is triggered once at the beginning of the generation process.<br>
 * <br><br> 
 * 
 * @author Maximilian Hammer, Alexander Wichmann
 *
 */
public class ValidationService {
	
/**
 * Private member attributes
 */
		private List<String> errors;
		private List<String> warnings;
		private Boolean validationStatus = false;
		private Boolean warningsDisabled = false;
		private Logger logger;
		
/**
 * Private utility methods
 */
		/**
		 * Add {@code message} to internal error list
		 * @param message String representing error message
		 */
		private void registerError(String message)
		{
			errors.add(message);
		}
		
		/**
		 * Add {@code message} to internal warning list
		 * @param message String representing warning
		 */
		private void registerWarning(String message)
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
			errors = new ArrayList<String>();
			warnings = new ArrayList<String>();
			
			logger = Logger.getLogger("ecore4CPPLogger");
			logger.setLevel(Level.ALL);
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
		
		public void disableWarnings()
		{
			warningsDisabled = true;
		}
		
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
				for (String errorMessage : errors) {
					printError(errorMessage);
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
					printInfo("Warnings disabled!");
				}
				
				else {
				System.out.println("Warnings during validation (NOTE: generation might not work correctly):");
				System.out.println("-----------------------------------------------------------------------\n");

					for (String warning : warnings) {
						printWarning(warning);
					}
				}
			}
		}
		
		public void printInfo(String message)
		{
			logger.info(message + "\n");
		}
		
		public void printWarning(String message)
		{
			if(!warningsDisabled)
			{
				logger.warning(message + "\n");
			}
		}
		
		public void printError(String message)
		{
			
			logger.severe(message + "\n");
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

		private void validateENamedElement(ENamedElement eNamedElement)
		{
			if(eNamedElement.getName().isEmpty())
			{
				registerError("Undefined 'name' for instance of ENamedElement :\n" + eNamedElement);
			}
		}
		
		public void validateEPackage(EPackage ePackage)
		{
			if(ePackage == null)
			{
				registerError("Undefined instance of EPackage");
				return;
			}
			
			validateENamedElement(ePackage);
		}
		
		public void validateEEnumLiteral(EEnumLiteral eEnumLiteral)
		{
			if(eEnumLiteral == null)
			{
				registerError("Undefined instance of EEnumLiteral");
				return;
			}
			
			validateENamedElement(eEnumLiteral);
			
			if(eEnumLiteral.getEEnum() == null)
			{
				registerWarning("Undefined 'eEnum' for instance of EEnumerationLiteral :\n" + eEnumLiteral);
			}
		}
		
		private void validateETypedElement(ETypedElement eTypedElement)
		{
			validateENamedElement(eTypedElement);
			
			String messageInstanceSuffix = " for instance of ETypedElement :\n" + eTypedElement;
			
			if(eTypedElement.getLowerBound() < 0)
			{
				registerError("Invalid 'lowerBound' of " + eTypedElement.getLowerBound() + messageInstanceSuffix);
			}
			
			if(eTypedElement.getUpperBound() == 0 || eTypedElement.getUpperBound() < -1)
			{
				registerError("Invalid 'upperBound' of " + eTypedElement.getUpperBound() + messageInstanceSuffix);
			}
			
			if((eTypedElement.getUpperBound() > 0) && (eTypedElement.getLowerBound() > eTypedElement.getUpperBound()))
			{
				registerError("'lowerBound' of " + eTypedElement.getLowerBound() + " is greater than 'upperBound' of " + eTypedElement.getUpperBound() + messageInstanceSuffix);
			}
			
			if((eTypedElement.getUpperBound() > 1 || eTypedElement.getUpperBound() == -1) && (eTypedElement.getLowerBound() > 0))
			{
				registerWarning("[n..*] or [n..m] multiplicity will be generated as [0..*] multiplicity" + messageInstanceSuffix);
			}
			
			/*
			 * NOTE: 'eType' of ETypedElement will be checked in validation methods for subclasses,
			 * as EOperations are allowed to be of undefined type (which will be interpreted as 'void' during generation)
			 */
		}

		public void validateEOperation(EOperation eOperation)
		{
			if(eOperation == null)
			{
				registerError("Undefined instance of EOperation");
				return;
			}
			
			validateETypedElement(eOperation);
			
			if(eOperation.getEContainingClass() == null) 
			{
				registerError("Undefined 'eContainingClass' for instance of EOperation :\n" + eOperation);
			}
		}
		
		public void validateEParameter(EParameter eParameter)
		{
			if(eParameter == null)
			{
				registerError("Undefined instance of EParameter");
				return;
			}
			
			validateETypedElement(eParameter);
			
			String messageInstanceSuffix = " for instance of EParameter :\n" + eParameter;
			
			if(eParameter.getEOperation() == null) 
			{
				registerError("Undefined 'eOperation'" + messageInstanceSuffix);
			}
			
			if(eParameter.getEType() == null)
			{
				registerError("Undefined 'eType'" + messageInstanceSuffix);
			}
		}
		
		private void validateEStructuralFeature(EStructuralFeature eStructuralFeature)
		{
			if(eStructuralFeature == null)
			{
				registerError("Undefined instance of EStructuralFeature");
				return;
			}
			
			validateETypedElement(eStructuralFeature);
			
			String messageInstanceSuffix = " for instance of EStructuralFeature :\n" + eStructuralFeature;
			
			if(eStructuralFeature.getEContainingClass() == null) 
			{
				registerError("Undefined 'eContainingClass'" + messageInstanceSuffix);
			}
			
			if(eStructuralFeature.getEType() == null)
			{
				registerError("Undefined 'eType'" + messageInstanceSuffix);
			}
		}
		
		public void validateEReference(EReference eReference)
		{
			if(eReference == null)
			{
				registerError("Undefined instance of EReference");
				return;
			}
			
			validateEStructuralFeature(eReference);
		}
		
		public void validateEAttribute(EAttribute eAttribute)
		{
			if(eAttribute == null)
			{
				registerError("Undefined instance of EAttribute");
				return;
			}
			
			validateEStructuralFeature(eAttribute);
		}
		
		private void validateEClassifier(EClassifier eClassifier)
		{
			validateENamedElement(eClassifier);
		}
		
		public void validateEDataType(EDataType eDataType)
		{
			if(eDataType == null)
			{
				registerError("Undefined instance of EDataType");
				return;
			}
			
			validateEClassifier(eDataType);
		}
		
		public void validateEEnum(EEnum eEnum)
		{
			if(eEnum == null)
			{
				registerError("Undefined instance of EEnum");
				return;
			}
			
			validateEClassifier(eEnum);
			
			String messageInstanceSuffix = " for instance of EEnum :\n" + eEnum;
			
			List<String> eEnumLiteralNames = eEnum.getELiterals().stream().map(EEnumLiteral::getName).collect(Collectors.toList());
			Set<String> duplicateEEnumLiteralNames = findDuplicates(eEnumLiteralNames);
			
			if(!duplicateEEnumLiteralNames.isEmpty())
			{
				for(String duplicateEEnumLiteralName : duplicateEEnumLiteralNames)
				{
					registerError("Multiple literals with name '" + duplicateEEnumLiteralName + "'" + messageInstanceSuffix);
				}
			}
			
			List<Integer> eEnumLiteralValues = eEnum.getELiterals().stream().map(EEnumLiteral::getValue).collect(Collectors.toList());
			Set<Integer> duplicateEEnumLiteralValues = findDuplicates(eEnumLiteralValues);
			
			if(!duplicateEEnumLiteralValues.isEmpty())
			{
				for(int duplicateEEnumLiteralValue : duplicateEEnumLiteralValues)
				{
					registerError("Multiple literals with value '" + duplicateEEnumLiteralValue + "'" + messageInstanceSuffix);
				}
			}
		}
		
		private <T> Set<T> findDuplicates(Collection<T> collection)
		{
			Set<T> uniques = new HashSet<>();
			return collection.stream().filter(element -> !uniques.add(element)).collect(Collectors.toSet());
		}
		
		public void validateEClass(EClass eClass)
		{
			if(eClass == null)
			{
				registerError("Undefined instance of EClass");
				return;
			}
			
			validateEClassifier(eClass);
			
			String messageInstanceSuffix = " for instance of EClass :\n" + eClass;
			
			List<String> eStructuralFeatureNames = eClass.getEStructuralFeatures().stream().map(EStructuralFeature::getName).collect(Collectors.toList());
			Set<String> duplicateEStructuralFeatureNames = findDuplicates(eStructuralFeatureNames);
			
			if(!duplicateEStructuralFeatureNames.isEmpty())
			{
				for(String duplicateEStructuralFeatureName : duplicateEStructuralFeatureNames)
				{
					registerWarning("Multiple structural features with name '" + duplicateEStructuralFeatureName + "'" + messageInstanceSuffix);
				}
			}
			
			/**
			 * TODO Check operations
			 */
		}
	
}
