package ecore4CPP.generator.main.validation;


import java.util.ArrayList;
import java.util.List;

import org.eclipse.emf.common.EMFPlugin;

/**
 * Service class to report model errors found during C++ source code generation of given UML model<br>
 * Provided functionality:<br>
 * <ul>
 * 	<li>register errors</li>
 *  <li>print errors</li>
 *  <li>check if errors registered</li>
 *  <li>exit java program with error code, if at least one error is registered and generator is running outside of eclipse</li>
 * </ul>
 * Functionality must be triggered by generator modules.<br> In particular, error printing and exiting with error is not done automatically to wait for complete generator executing and collecting all existing errors.
 * <br><br> 
 * 
 * @author wichmann
 *
 */
public class ValidationService {

	private List<String> errors;
	
	/**
	 * Constructor<br>
	 * initialize error list as ArrayList of type String
	 */
	public ValidationService() 
	{
		errors = new ArrayList<String>();
	}
	
	/**
	 * add {@code message} to internal error list
	 * @param message String representing error message
	 */
	public void registerError(String message)
	{
		errors.add(message);
	}
	
	/**
	 * checks, if at least one error is registered
	 * @return true for error existing, otherwise false
	 */
	public boolean errorExisting()
	{
		return errors.size() > 0;
	}
	
	/**
	 * prints all registered errors to syserr
	 */
	public void printErrors()
	{
		if (errorExisting())
		{
			System.err.println("Generation failed with following errors:");
			for (String errorMessage : errors) {
				System.err.println("- " + errorMessage);
			}
		}
	}
	
	/**
	 * if error is registered and generator is running outside of eclipse, application will be closed with given number
	 * @param number - exit code to be used during application exit, {@value 0} - close without error notification, otherwise close with error notification 
	 */
	public void closeWithErrorExit(int number)
	{
		if (!EMFPlugin.IS_ECLIPSE_RUNNING)
		{
			System.exit(number);
		}
	}
	
}
