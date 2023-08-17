package UML4CPP.generator.main.validation;


import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import org.eclipse.emf.common.EMFPlugin;
import org.eclipse.uml2.uml.Element;
import org.eclipse.uml2.uml.FunctionBehavior;
import org.eclipse.uml2.uml.Generalization;
import org.eclipse.uml2.uml.InterfaceRealization;
import org.eclipse.uml2.uml.Model;
import org.eclipse.uml2.uml.MultiplicityElement;
import org.eclipse.uml2.uml.NamedElement;
import org.eclipse.uml2.uml.OpaqueBehavior;
import org.eclipse.uml2.uml.Operation;
import org.eclipse.uml2.uml.Package;
import org.eclipse.uml2.uml.PackageableElement;
import org.eclipse.uml2.uml.Parameter;
import org.eclipse.uml2.uml.ParameterDirectionKind;
import org.eclipse.uml2.uml.Port;
import org.eclipse.uml2.uml.Property;
import org.eclipse.uml2.uml.TypedElement;
import org.eclipse.uml2.uml.Activity;
import org.eclipse.uml2.uml.AggregationKind;
import org.eclipse.uml2.uml.Behavior;
import org.eclipse.uml2.uml.Class;
import org.eclipse.uml2.uml.Connector;
import org.eclipse.uml2.uml.UMLPackage;

/**
 * Service class to report model errors found during C++ source code generation of given UML model<br>
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
public class ValidationService
{
	
	/**
	 * Enumeration to represent different severity levels of UML4CPPMessage objects
	 *<ul>
     *	<li>INFO : message represents basic information for the user</li>
     * 	<li>WARNING : messages warns about a potential error. This does not necessarily abort the generation but it may result in erroneous generation</li>
     * 	<li>ERROR : messages containing errors during model validation. This should abort generation</li>
	 * </ul>
	 */
	private enum UML4CPPMessageServerityLevel
	{
		INFO,
		WARNING,
		ERROR
	}
	
	/**
	 * Class that holds constants for manipulating the color of text printed to the console via ANSI escape sequences
	 */
	private static class UML4CPPConsoleManipulator
	{
		public static final String ANSI_RESET = "\u001B[0m";
		public static final String ANSI_RED = "\u001B[31m";
		public static final String ANSI_GREEN = "\u001B[32m";
		public static final String ANSI_YELLOW = "\u001B[33m";
		
		public static final Map<UML4CPPMessageServerityLevel, String> ANSI_MAP = Map.of(
				UML4CPPMessageServerityLevel.INFO, ANSI_GREEN, 
				UML4CPPMessageServerityLevel.WARNING, ANSI_YELLOW,
				UML4CPPMessageServerityLevel.ERROR, ANSI_RED
				);
	}
	
	/**
	 * Class that represents a message. Contains info about the severity level of the message, the message itself and potentially the name of the function which created the message
	 */
	private class UML4CPPMessage
	{
		private String m_message, m_callingOperation;
		private UML4CPPMessageServerityLevel m_level;
		private static final String INDENT = "    ";
		
		@SuppressWarnings("unused")
		public UML4CPPMessage() 
		{
			m_message = m_callingOperation = "";
			m_level = UML4CPPMessageServerityLevel.INFO;
		}
		
		public UML4CPPMessage(UML4CPPMessageServerityLevel level, String message, String callingOperation)
		{
			m_level = level;
			m_message = message;
			m_callingOperation = callingOperation;
		}
		
		public void print(Integer level)
		{	
			String printedMessage = "[" + 
									UML4CPPConsoleManipulator.ANSI_MAP.get(m_level) +  m_level.name() + UML4CPPConsoleManipulator.ANSI_RESET + 
									"] :\t" + 
									String.join("",  Collections.nCopies(level, INDENT)) +
									m_message + 
									((m_callingOperation.isEmpty()) ? 
											"" : (
													"\n\t\t" + 
													String.join("",  Collections.nCopies(level, INDENT)) +
													"(from " + m_callingOperation + ")"));
			System.out.println(printedMessage);
		}
	}

/**
 * Private member attributes
 */
		private List<UML4CPPMessage> errors;
		private List<UML4CPPMessage> warnings;
		private Boolean validationStatus = false;
		private Boolean infosDisabled = false, warningsDisabled = false;
		private Integer disabledLevelInfo = 0, disabledLevelWarning = 0;
		
/**
 * Private utility methods
 */
		/**
		 * Add {@code message} to internal error list
		 * @param message String representing error message
		 */
		private void registerError(UML4CPPMessage message)
		{
			errors.add(message);
		}
		
		/**
		 * Add {@code message} to internal warning list
		 * @param message String representing warning
		 */
		private void registerWarning(UML4CPPMessage message)
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
			errors = new ArrayList<UML4CPPMessage>();
			warnings = new ArrayList<UML4CPPMessage>();
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
		 * Disables the print of info messages
		 */
		public void disableInfos()
		{
			disableInfos(0);
		}
		
		/**
		 * Disables the print of info messages from a specific level of depth
		 */
		public void disableInfos(Integer disableLevel)
		{
			disabledLevelInfo = disableLevel;
			infosDisabled = true;
		}
		
		/**
		 * Enables the print of info messages
		 */
		public void enableInfos()
		{
			infosDisabled = false;
		}
		
		/**
		 * Disables the print of warning messages
		 */
		public void disableWarnings()
		{
			disableWarnings(0);
		}
		
		/**
		 * Disables the print of warning messages from a specific level of depth
		 */
		public void disableWarnings(Integer disableLevel)
		{
			disabledLevelWarning = disableLevel;
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
				for (UML4CPPMessage errorMessage : errors) {
					errorMessage.print(0);
				}
				System.out.println("\n--------------------------------------------");
			}
		}
		
		/**
		 * Logs all registered warnings
		 */
		public void printWarnings()
		{
			if (warningsExist())
			{
				if(warningsDisabled && disabledLevelWarning < 1)
				{
					printInfo("Warnings disabled!", "", 0);
				}
				
				else 
				{
				System.out.println("Warnings during validation (NOTE: generation might not work correctly):");
				System.out.println("-----------------------------------------------------------------------\n");
					for (UML4CPPMessage warningMessage : warnings) {
						warningMessage.print(0);
					}
				System.out.println("\n-----------------------------------------------------------------------");
				}
			}
		}
		
		/**
		 * Creates and prints a new Info message
		 */
		public void printInfo(String message, String callingOperation, Integer level)
		{
			/* Print infos only if:
			 * - infos are enabled
			 * - or (if infos are disabled) if the disabledLevel for infos is less than the level of the provided info
			 */
			if(!infosDisabled || level < disabledLevelInfo) {
				UML4CPPMessage infoMessage = new UML4CPPMessage(UML4CPPMessageServerityLevel.INFO, message, callingOperation);
				infoMessage.print(level);
			}
		}
		
		/**
		 * Creates and prints a new Warning message (if warnings are enabled)
		 */
		public void printWarning(String message, String callingOperation, Integer level)
		{
			/* Print warnings only if:
			 * - warnings are enabled
			 * - or (if warnings are disabled) if the disabledLevel for warnings is less than the level of the provided warning
			 */
			if(!warningsDisabled || disabledLevelWarning < level)
			{
				UML4CPPMessage warningMessage = new UML4CPPMessage(UML4CPPMessageServerityLevel.WARNING, message, callingOperation);
				warningMessage.print(level);
			}
		}
		
		/**
		 * Creates and prints a new Error message
		 */
		public void printError(String message,  String callingOperation, Integer level)
		{
			
			UML4CPPMessage errorMessage = new UML4CPPMessage(UML4CPPMessageServerityLevel.ERROR, message, callingOperation);
			errorMessage.print(level);
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
		 * Creates a printable String-representation of an Element
		 * Returns "toString()".
		 */
		private String getPrintableName(Element element)
		{
			return element.toString();
		}
		
		/**
		 * Creates a printable String-representation of a NamedElement
		 * Returns the qualified name of the element if present, or else calls "toString()".
		 */
		private String getPrintableName(NamedElement namedElement)
		{
			String qualifiedName = namedElement.getQualifiedName();
			
			if(qualifiedName == null || qualifiedName.isEmpty())
			{
				return namedElement.toString();
			}
			else
			{
				return qualifiedName;
			}
		}
		
		private String getMessageInstanceSuffix(Element element)
		{
			return (" for instance of " + element.eClass().getName() + " : " + getPrintableName(element));
		}
		private String getMessageInstanceSuffix(NamedElement namedElement)
		{
			return (" for instance of " + namedElement.eClass().getName() + " : " + getPrintableName(namedElement));
		}
		
		/**
		 * Finds duplicates within a Collection
		 */
		private <T> Set<T> findDuplicates(Collection<T> collection)
		{
			Set<T> uniques = new HashSet<>();
			return collection.stream().filter(element -> !uniques.add(element)).collect(Collectors.toSet());
		}
		
		
		/**
		 * Validates properties constrained by metaclass Behavior
		 * This includes:
		 *  - validation of specific behavior sub-type
		 *  - validation of Class
		 *  - check if there are multiple 'ownedParameters' with the same name
		 *  - check if there are multiple 'ownedParameters' with direction ParameterDirectionKind::RETURN
		 *  - validate ownedParameters
		 */
		private void validateBehavior(Behavior behavior)
		{
			switch(behavior.eClass().getClassifierID())
			{
				case UMLPackage.FUNCTION_BEHAVIOR:
				case UMLPackage.OPAQUE_BEHAVIOR: 
				{
					//TODO implement
					break;
				} 
				case UMLPackage.ACTIVITY: 
				{
					//TODO implement
					break;
				}
				//PSSM
				case UMLPackage.STATE_MACHINE:
				{
					//TODO implement
					break;
				}
				
				default:
					throw new IllegalArgumentException("Unexpected value: " + behavior.eClass().getClassifierID());
			}
			
			//validation of Class
			validateClass(behavior);
			
			//check if there are multiple 'ownedParameters' with the same name
			List<String> ownedParametersNames = behavior.getOwnedParameters().stream().map(Parameter::getName).collect(Collectors.toList());
			Set<String> duplicateOwnedParametersNames = findDuplicates(ownedParametersNames);
			
			if(!duplicateOwnedParametersNames.isEmpty())
			{
				for(String duplicateOwnedParametersName : duplicateOwnedParametersNames)
				{
					registerError(new UML4CPPMessage(
							UML4CPPMessageServerityLevel.ERROR,
							"Multiple 'ownedParameters' with name '" + duplicateOwnedParametersName + "'" + getMessageInstanceSuffix(behavior),
							this.getClass().getName() + ":validateBehavior"));
				}
			}
			
			//check if there are multiple 'ownedParameters' with direction ParameterDirectionKind::RETURN
			List<Parameter> returnParameters = behavior.getOwnedParameters().stream().filter(p -> p.getDirection() == ParameterDirectionKind.RETURN_LITERAL).collect(Collectors.toList());
			if(returnParameters.size() > 1)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"Multiple return parameters '" + getMessageInstanceSuffix(behavior),
						this.getClass().getName() + ":validateBehavior"));
			}
			
			//validate ownedParameters
			for(Parameter parameter : behavior.getOwnedParameters()) 
			{
				validateParameter(parameter);
			}
		}
		
		/**
		 * Validates properties constrained by metaclass Class
		 * This includes:
		 *  - validation of NamedElement
		 *  - check if there are multiple ownedMember with the same name (warning only)
		 *  - validate generalization
		 *  - validate interfaceRealization
		 *  - validate ownedAttribute
		 *  - validate ownedBehavior
		 *  - validate ownedConnector
		 *  - validate ownedOperation
		 *  - validate ownedPort
		 */
		public void validateClass(Class _class)
		{
			//validation of NamedElement
			validateNamedElement(_class);
			
			//check if there are multiple ownedMember with the same name (warning only)
			List<String> ownedMembersNames = _class.getOwnedMembers().stream().map(NamedElement::getName).collect(Collectors.toList());
			Set<String> duplicateOwnedMembersNames = findDuplicates(ownedMembersNames);
			
			if(!duplicateOwnedMembersNames.isEmpty())
			{
				for(String duplicateOwnedMembersName : duplicateOwnedMembersNames)
				{
					registerWarning(new UML4CPPMessage(
							UML4CPPMessageServerityLevel.WARNING,
							"Multiple 'ownedMembers' with name '" + duplicateOwnedMembersName + "'" + getMessageInstanceSuffix(_class)
							+ "\n Possible naming conflicts",
							this.getClass().getName() + ":validateClass"));
				}
			}
	
			//validate generalization
			for(Generalization generalization : _class.getGeneralizations())
			{
				validateGeneralization(generalization);
			}
			
			//validate interfaceRealization
			for(InterfaceRealization interfaceRealization : _class.getInterfaceRealizations())
			{
				validateInterfaceRealization(interfaceRealization);
			}
			
			//validate ownedAttribute
			for(Property property : _class.getOwnedAttributes())
			{
				validateProperty(property);
			}
			
			//validate ownedBehavior
			for(Behavior behavior : _class.getOwnedBehaviors())
			{
				validateBehavior(behavior);
			}
			
			//validate ownedConnector
			for(Connector connector : _class.getOwnedConnectors())
			{
				validateConnector(connector);
			}
			
			//validate ownedOperation
			for(Operation operation : _class.getOwnedOperations())
			{
				validateOperation(operation);
			}
			
			//validate ownedPort
			for(Port port : _class.getOwnedPorts())
			{
				validatePort(port);
			}
		}
		
		/**
		 * Validates properties constrained by metaclass InterfaceRealization
		 * This includes:
		 *  - validation of NamedElement
		 *  - check if type is null
		 *  - check if there are at least 2 ends
		 */
		private void validateConnector(Connector connector)
		{
			//validation of NamedElement
			validateNamedElement(connector);
			
			//check if type is null
			if(connector.getType() == null) 
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'type' not set" + getMessageInstanceSuffix(connector),
						this.getClass().getName() + ":validateConnector"));
			}
			
			//check if there are at least 2 ends
			if(connector.getEnds().size() < 2)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'end' must contain at least 2 ConnectorEnds" + getMessageInstanceSuffix(connector),
						this.getClass().getName() + ":validateConnector"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass Generalization
		 * This includes:
		 *  - check if general is null
		 *  - check if specific is null
		 *  - check if general equals specific
		 */
		private void validateGeneralization(Generalization generalization)
		{
			//check if general is null
			if(generalization.getGeneral() == null) 
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'general' not set" + getMessageInstanceSuffix(generalization),
						this.getClass().getName() + ":validateGeneralization"));
			}
			
			//check if specific is null
			if(generalization.getSpecific() == null)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'specific' not set" + getMessageInstanceSuffix(generalization),
						this.getClass().getName() + ":validateGeneralization"));
			}
			
			//check if general equals specific
			if(generalization.getGeneral() != null && (generalization.getGeneral() == generalization.getSpecific()))
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'general' must not equal 'specific'" + getMessageInstanceSuffix(generalization),
						this.getClass().getName() + ":validateGeneralization"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass InterfaceRealization
		 * This includes:
		 *  - validation of NamedElement
		 *  - check if contract is null
		 *  - check if implementingClassifier is null
		 */
		private void validateInterfaceRealization(InterfaceRealization interfaceRealization)
		{
			//validation of NamedElement
			validateNamedElement(interfaceRealization);
			
			//check if contract is null
			if(interfaceRealization.getContract() == null) 
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'contract' not set" + getMessageInstanceSuffix(interfaceRealization),
						this.getClass().getName() + ":validateInterfaceRealization"));
			}
			
			//check if implementingClassifier is null
			if(interfaceRealization.getImplementingClassifier() == null)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'implementingClassifier' not set" + getMessageInstanceSuffix(interfaceRealization),
						this.getClass().getName() + ":validateInterfaceRealization"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass MultiplicityElement
		 * This includes:
		 * 	- check if the lower is greater or equal to 0
		 *  - check if the upper is valid (not =0 and not <-1)
		 *  - check if the lower is smaller than upper property (except if upper == -1)
		 */
		public void validateMultiplicityElement(MultiplicityElement multiplicityElement)
		{
			//check if the lower is greater or equal to 0 
			if(multiplicityElement.getLower() < 0)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'lower' must be greater or equal to 0" + getMessageInstanceSuffix(multiplicityElement),
						this.getClass().getName() + ":validateMultiplicityElement"));
			}
			
			//check if the upper is valid (not =0 and not <-1)
			if(multiplicityElement.getUpper() == 0 || multiplicityElement.getUpper() < -1)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'upper' must either be greater than 0 or equal to -1" + getMessageInstanceSuffix(multiplicityElement),
						this.getClass().getName() + ":validateMultiplicityElement"));
			}
			
			//check if the lower is smaller than upper property (except if upper == -1) 
			if((multiplicityElement.getUpper() > 0) && (multiplicityElement.getLower() > multiplicityElement.getUpper()))
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'upper' must be greater or equal to 'lower'" + getMessageInstanceSuffix(multiplicityElement),
						this.getClass().getName() + ":validateMultiplicityElement"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass NamedElement
		 * This includes:
		 *  - check if name is set (warning only)
		 */
		public void validateNamedElement(NamedElement namedElement)
		{
			//check if name is set (warning only) 
			
			String name = namedElement.getName();
			
			if(name == null || name.isEmpty())
			{
				registerWarning(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.WARNING,
						"Undefined 'name'" + getMessageInstanceSuffix(namedElement),
						this.getClass().getName() + ":validateNamedElement"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass Operation
		 * This includes:
		 * 	- validation of NamedElement
		 *  - check if there are multiple 'ownedParameters' with the same name
		 *  - check if there are multiple 'ownedParameters' with direction ParameterDirectionKind::RETURN
		 *  - validate ownedParameters
		 */
		private void validateOperation(Operation operation)
		{
			//validation of NamedElement
			validateNamedElement(operation);
			
			//check if there are multiple 'ownedParameters' with the same name
			List<String> ownedParametersNames = operation.getOwnedParameters().stream().map(Parameter::getName).collect(Collectors.toList());
			Set<String> duplicateOwnedParametersNames = findDuplicates(ownedParametersNames);
			
			if(!duplicateOwnedParametersNames.isEmpty())
			{
				for(String duplicateOwnedParametersName : duplicateOwnedParametersNames)
				{
					registerError(new UML4CPPMessage(
							UML4CPPMessageServerityLevel.ERROR,
							"Multiple 'ownedParameters' with name '" + duplicateOwnedParametersName + "'" + getMessageInstanceSuffix(operation),
							this.getClass().getName() + ":validateOperation"));
				}
			}
			
			//check if there are multiple 'ownedParameters' with direction ParameterDirectionKind::RETURN
			List<Parameter> returnParameters = operation.getOwnedParameters().stream().filter(p -> p.getDirection() == ParameterDirectionKind.RETURN_LITERAL).collect(Collectors.toList());
			if(returnParameters.size() > 1)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"Multiple return parameters '" + getMessageInstanceSuffix(operation),
						this.getClass().getName() + ":validateOperation"));
			}
			
			//validate ownedParameters
			for(Parameter parameter : operation.getOwnedParameters()) 
			{
				validateParameter(parameter);
			}
		}
		
		/**
		 * Validates properties constrained by metaclass Package
		 * This includes:
		 * 	- validation of NamedElement
		 *  - check if there are multiple 'packagedElements' with the same name (warning only)
		 *  - validate packgedElements
		 */
		public void validatePackage(Package _package)
		{
			//validation of NamedElement
			validateNamedElement(_package);
			
			//check if there are multiple 'packagedElements' with the same name (warning only)
			List<String> packagedElementsNames = _package.getPackagedElements().stream().map(PackageableElement::getName).collect(Collectors.toList());
			Set<String> duplicatePackagedElementsNames = findDuplicates(packagedElementsNames);
			
			if(!duplicatePackagedElementsNames.isEmpty())
			{
				for(String duplicatePackagedElementsName : duplicatePackagedElementsNames)
				{
					registerWarning(new UML4CPPMessage(
							UML4CPPMessageServerityLevel.WARNING,
							"Multiple 'packagedElements' with name '" + duplicatePackagedElementsName + "'" + getMessageInstanceSuffix(_package)
							+ "\n Possible naming conflicts or overriding of generated files",
							this.getClass().getName() + ":validatePackage"));
				}
			}
			
			//validate packgedElements
			for(PackageableElement packageableElement : _package.getPackagedElements()) 
			{
				validatePackageableElement(packageableElement);
			}
		}
		
		public void validatePackageableElement(PackageableElement packageableElement)
		{
			int metaClassID = packageableElement.eClass().getClassifierID();
			
			switch (metaClassID) 
			{
				case UMLPackage.ABSTRACTION: 
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ACTIVITY:
				{
					validateBehavior((Activity)packageableElement);
					break;
				}
				case UMLPackage.ACTOR:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ANY_RECEIVE_EVENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ARTIFACT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ASSOCIATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ASSOCIATION_CLASS:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.CALL_EVENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.CLASS:
				{
					validateClass((Class) packageableElement);
					break;
				}
				case UMLPackage.COLLABORATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.COMMUNICATION_PATH:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.COMPONENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.COMPONENT_REALIZATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.CONSTRAINT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DATA_TYPE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DEPENDENCY:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DEPLOYMENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DEPLOYMENT_SPECIFICATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DEVICE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DURATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DURATION_CONSTRAINT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DURATION_INTERVAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.DURATION_OBSERVATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ENUMERATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.ENUMERATION_LITERAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.EXECUTION_ENVIRONMENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.EXPRESSION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.EXTENSION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.FUNCTION_BEHAVIOR:
				{
					validateBehavior((FunctionBehavior)packageableElement);
					break;
				}
				case UMLPackage.GENERALIZATION_SET:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INFORMATION_FLOW:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INFORMATION_ITEM:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INSTANCE_SPECIFICATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INSTANCE_VALUE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INTERACTION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INTERACTION_CONSTRAINT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INTERFACE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INTERFACE_REALIZATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INTERVAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.INTERVAL_CONSTRAINT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.LITERAL_BOOLEAN:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.LITERAL_INTEGER:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.LITERAL_NULL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.LITERAL_REAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.LITERAL_STRING:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.LITERAL_UNLIMITED_NATURAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.MANIFESTATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.MODEL:
				{
					validatePackage((Model)packageableElement);
					break;
				}
				case UMLPackage.NODE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.OPAQUE_BEHAVIOR:
				{
					validateBehavior((OpaqueBehavior)packageableElement);
					break;
				}
				case UMLPackage.OPAQUE_EXPRESSION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.PACKAGE:
				{
					validatePackage((Package)packageableElement);
					break;
				}
				case UMLPackage.PRIMITIVE_TYPE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.PROFILE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.PROTOCOL_STATE_MACHINE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.REALIZATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.SIGNAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.SIGNAL_EVENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.STATE_MACHINE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.STEREOTYPE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.STRING_EXPRESSION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.SUBSTITUTION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.TIME_CONSTRAINT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.TIME_EVENT:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.TIME_EXPRESSION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.TIME_INTERVAL:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.TIME_OBSERVATION:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.USAGE:
				{
					//TODO Implement
					break;
				}
				case UMLPackage.USE_CASE:
				{
					//TODO Implement
					break;
				}
				
			default:
				break;
			}
		}
		
		/**
		 * Validates properties constrained by metaclass Parameter
		 * This includes:
		 *  - validation of MultiplicityElement
		 *  - validation of TypedElement
		 */
		public void validateParameter(Parameter parameter)
		{
			//validation of MultiplicityElement
			validateMultiplicityElement(parameter);
			//validation of TypedElement
			validateTypedElement(parameter);
		}
		
		/**
		 * Validates properties constrained by metaclass Port
		 * This includes:
		 * 	- check if aggregation is AggregationKind::COMPOSITE
		 */
		public void validatePort(Port port)
		{
			//check if aggregation is AggregationKind::COMPOSITE
			if(port.getAggregation() != AggregationKind.COMPOSITE_LITERAL)
			{
				registerError(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.ERROR,
						"'aggregation' must be composite" + getMessageInstanceSuffix(port),
						this.getClass().getName() + ":validatePort"));
			}
		}
		
		/**
		 * Validates properties constrained by metaclass Property
		 * This includes:
		 *  - validation of MultiplicityElement
		 *  - validation of TypedElement
		 */
		public void validateProperty(Property property)
		{
			//validation of MultiplicityElement
			validateMultiplicityElement(property);
			//validation of TypedElement
			validateTypedElement(property);
		}
		
		/**
		 * Validates properties constrained by metaclass TypedElement
		 * This includes:
		 *  - validation of NamedElement
		 * 	- check if type is null
		 */
		public void validateTypedElement(TypedElement typedElement)
		{
			//validation of NamedElement
			validateNamedElement(typedElement);
			//check if type is null
			if(typedElement.getType() == null)
			{
				registerWarning(new UML4CPPMessage(
						UML4CPPMessageServerityLevel.WARNING,
						"'type' is not set" + getMessageInstanceSuffix(typedElement) + 
						"\nWill be generated as 'Any' type.",
						this.getClass().getName() + ":validateTypedElement"));
			}
		}
}
