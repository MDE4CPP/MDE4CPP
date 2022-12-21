package UML4CPP.generator.main.validation;


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;

import org.eclipse.emf.common.EMFPlugin;

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
	//TODO
}
