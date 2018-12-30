package UML4CPP.generator.main.validation;


import java.util.ArrayList;
import java.util.List;

import org.eclipse.emf.common.EMFPlugin;
import org.eclipse.uml2.uml.Package;

public class ValidationService {

	private List<String> errors;
	
	public ValidationService() 
	{
		errors = new ArrayList<String>();
	}
	
	public void registerError(String message)
	{
		errors.add(message);
	}
	
	public boolean errorExisting(Package pac)
	{
		return errors.size() > 0;
	}
	
	public void printErrors(Package pac)
	{
		if (errorExisting(pac))
		{
			System.err.println("Validation of package " + pac.getName() + " failed with following errors:");
			for (String errorMessage : errors) {
				System.err.println("- " + errorMessage);
			}
			System.err.println("Generation failed");
		}
	}
	
	public void closeWithErrorExit(Package pac, int number)
	{
		if (!EMFPlugin.IS_ECLIPSE_RUNNING)
		{
			System.exit(number);
		}
	}
	
}
