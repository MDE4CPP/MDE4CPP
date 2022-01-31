package tui.sse.mde4cpp;

import java.io.File;
import java.util.LinkedList;
import java.util.List;

import org.gradle.api.DefaultTask;
import org.gradle.api.GradleException;
import org.gradle.api.Project;
import org.gradle.api.tasks.Input;
import org.gradle.api.tasks.TaskAction;

/**
 * Gradle task for compiling C++ projects with the MDE4CPP framework using cmake and gnu compiler<br>
 * <br>
 * More information can be found under https://github.com/MDE4CPP/gradlePlugins and http://sse.tu-ilmenau.de/mde4cpp
 *
 */
public class MDE4CPPCompile extends DefaultTask
{
	@Input
	private String projectFolder = null;
	private String execProjectFolder = null;
	private boolean executionBuildActivated = false;
	private String warningForExecProjectExisting = null;

	/**
	 * @return all project properties as string, which affect the compiling result
	 */
	@Input
	public String getProjectProperties()
	{
		Project project = getProject();
		List<String> propertyList = new LinkedList<String>();
		List<String[]> propsList = GradlePropertyAnalyser.getPropertiesForCMake(project);
		for (String[] variable : propsList)
		{
			propertyList.add(variable[0] + "=" + variable[1]);
		}
		propertyList.add("DEBUG=" + String.valueOf(GradlePropertyAnalyser.isDebugBuildModeRequestet(project)));
		propertyList.add("RELEASE=" + String.valueOf(GradlePropertyAnalyser.isReleaseBuildModeRequested(project)));
		propertyList.add("STRUCTURE=" + String.valueOf(GradlePropertyAnalyser.isStructureBuildRequested(project)));
		propertyList.add("EXECUTION=" + String.valueOf(GradlePropertyAnalyser.isExecutionBuildRequested(project)));
		String listedProperties = String.join(",", propertyList);
		
		return listedProperties;
	}
	
	
	/**
	 * Returns the project folder path
	 * @return path
	 */
	public String getProjectFolder()
	{
		return projectFolder;
	}

	/**
	 * Set project folder path
	 * @param projectFolder path to project folder
	 */
	public void setProjectFolder(String projectFolder)
	{
		this.projectFolder = projectFolder;
	}

	/**
	 * Checks, if an execution project is existing near to the specified project<br>
	 * If exists a project with and {@code projectFolder}Exec containing file {@code CMakeLists.txt}, the compilation of execution project will be enabled
	 */
	private void checkExecutionProject()
	{
		execProjectFolder = projectFolder + "Exec";
		File execCmakeFile = new File(execProjectFolder + File.separator + "CMakeLists.txt");
		executionBuildActivated = execCmakeFile.isFile();
		if (!executionBuildActivated)
		{
			File execFolder = new File(execProjectFolder);
			if (execFolder.isDirectory())
			{
				warningForExecProjectExisting = "Folder '" + execProjectFolder
						+ "' exists, but does not contain a 'CMakeLists.txt'. Execution project will not be build.";
			}
		}
	}

	/**
	 * checks, if {@code projectFolder} is well defined
	 */
	private void checkInput()
	{
		if (projectFolder == null)
		{
			throw new GradleException(
					"Property 'projectFolder' is not set!\r\n" + "Configure the project folder containing 'CMakeLists.txt' with project build instructions.");
		}

		File folder = new File(projectFolder);
		if (!folder.isDirectory())
		{
			throw new GradleException("The folder '" + folder.getAbsolutePath() + "' does not exists!");
		}

		File cmakeFile = new File(projectFolder + File.separator + "CMakeLists.txt");
		if (!cmakeFile.isFile())
		{
			throw new GradleException("The folder '" + folder.getAbsolutePath() + "' does not contain a 'CMakeLists.txt' file!");
		}
	}

	/**
	 * checks, if project compilation is enabled and trigger the compilation 
	 * 
	 * @param buildMode build mode indicator
	 * @param project current project instance contains existing properties
	 */
	private void compileBuildMode(BUILD_MODE buildMode, Project project)
	{
		if (!executionBuildActivated || GradlePropertyAnalyser.isStructureBuildRequested(project))
		{
			compileProjectWithBuildMode(projectFolder, buildMode);
		}
		if (executionBuildActivated && GradlePropertyAnalyser.isExecutionBuildRequested(project))
		{
			compileProjectWithBuildMode(execProjectFolder, buildMode);
		}
	}

	/**
	 * compile specific C++ project with specific build mode
	 * @param projectPath C++ project to compile
	 * @param buildMode build mode indicator
	 */
	private void compileProjectWithBuildMode(String projectPath, BUILD_MODE buildMode)
	{
		String buildPath = projectPath + File.separator + ".cmake" + File.separator + buildMode.getName();
		File projectFolderFile = new File(projectPath);
		File folder = new File(buildPath);
		if (!folder.exists())
		{
			folder.mkdirs();
		}

		List<String> command = CommandBuilder.getCMakeCommand(buildMode, projectFolderFile);
		String startingMessage = "Compiling " + projectFolderFile.getName() + " with " + buildMode.getName() + " options";
		if (!executeCompileProcess(command, folder, startingMessage))
		{
			throw new GradleException("Compilation failed during cmake execution!");
		}

		command = CommandBuilder.getMakeCommand(getProject());
		if (!executeCompileProcess(command, folder, null))
		{
			throw new GradleException("Compilation failed during " + CommandBuilder.getMakeTool() + " execution!");
		}
	}

	/**
	 * execute compilation
	 * 
	 * @param commandList commands
	 * @param workingDir working directory
	 * @param startingMessage starting message
	 * @return true, if successfully compiled, otherwise false
	 */
	private boolean executeCompileProcess(List<String> commandList, File workingDir, String startingMessage)
	{
		try
		{
			ProcessBuilder processBuilder = new ProcessBuilder(commandList);
			processBuilder.directory(workingDir);
			List<String[]> additionEnvironment = GradlePropertyAnalyser.getPropertiesForCMake(getProject());
			for (String[] variable : additionEnvironment)
			{
				processBuilder.environment().put(variable[0], variable[1]);
			}

			Process process = processBuilder.start();
			ProcessInputStreamThread inputThread = new ProcessInputStreamThread(process.getInputStream(), false);
			inputThread.setStartingMessage(startingMessage);
			if (warningForExecProjectExisting != null)
			{
				inputThread.setWarningExecPluginExisting(warningForExecProjectExisting);
				warningForExecProjectExisting = null;
			}
			ProcessInputStreamThread errorThread = new ProcessInputStreamThread(process.getErrorStream(), true);
			inputThread.start();
			errorThread.start();

			int code = process.waitFor();

			return code == 0;
		}
		catch (Exception e)
		{
			e.printStackTrace();
			return false;
		}
	}

	/**
	 * entry point for this task
	 */
	@TaskAction
	void executeCompile()
	{
		checkInput();
		checkExecutionProject();

		Project project = getProject();
		if (GradlePropertyAnalyser.isDebugBuildModeRequestet(project))
		{
			compileBuildMode(BUILD_MODE.DEBUG, project);
		}
		if (GradlePropertyAnalyser.isReleaseBuildModeRequested(project))
		{
			compileBuildMode(BUILD_MODE.RELEASE, project);
		}
	}
}