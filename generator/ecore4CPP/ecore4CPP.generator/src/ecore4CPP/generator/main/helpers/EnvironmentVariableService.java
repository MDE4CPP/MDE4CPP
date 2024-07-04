package ecore4CPP.generator.main.helpers;

import java.util.Map;

public class EnvironmentVariableService {
	public String getEnvironmentVariableValue(String variable) 
	{
		String returnValue=System.getenv(variable);
		if(null==returnValue)
		{
			returnValue="";
		}
		return returnValue;
	}
}

