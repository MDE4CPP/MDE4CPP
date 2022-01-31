package tui.sse.mde4cpp;

import org.gradle.api.Project;

/**
 * Class for analyzing Gradle properties assigned to this task<br>
 * The following aspects are investigated: <br>
 * <br>
 * 
 * Configure generator
 * <ul>
 * <li>{@code Model} path to model</li>
 * <li>{@code StructureOnly} or {@code SO} UML4CPP is used for UML models (except value {@code 0} is assigned.</li>
 * </ul>
 */
class PropertyAnalyser
{
	/**
	 * return property 'model' from project
	 * 
	 * @param project
	 *            current project instance contains existing properties
	 * @return model path, if property is configured, otherwise null
	 */
	static String getModelParameter(Project project)
	{
		if (project.hasProperty("Model"))
		{
			return project.property("Model").toString();
		}
		
		return null;
	}

	/**
	 * Checks, if project should be generated with UML4CPP (structure only mode)
	 * 
	 * @param project
	 *            current project instance contains existing properties
	 * @return {@code true} if {@core StructureOnly} is requested, otherwise {@code false}
	 */
	static boolean isStructuredOnlyRequested(Project project)
	{
		if (project.hasProperty("StructureOnly"))
		{
			return !project.property("StructureOnly").equals("0");
		}
		else if (project.hasProperty("SO"))
		{
			return !project.property("SO").equals("0");
		}
		else
		{
			return false;
		}
	}
	
	/**
	 * @param project Gradle project
	 * @return true if parameter 'structureOnly' is configured, otherwise false
	 */
	static boolean hasStructuredOnlyParameter(Project project)
	{
		return (project.hasProperty("StructureOnly") || project.hasProperty("SO"));
	}
}
