package tui.sse.mde4cpp;

import java.io.File;
import java.util.LinkedList;
import java.util.List;

import org.gradle.api.Project;

/**
 * Class for the creation of C++ compile command using cmake and gnu.<br>
 * <br>
 * This class provides operation to get cmake and make command for a C++ project
 * depending on the operation system.
 * 
 */
class CommandBuilder
{
	/**
	 * Returns cmake generator name depending on operation system
	 * 
	 * @return generator name
	 */
	private static String getCMakeGenerator()
	{
		if (isWindowsSystem())
		{
			return "MinGW Makefiles";
		}
		else
		{
			return "Unix Makefiles";
		}
	}

	/**
	 * Creates initial command list depending on operation system.
	 * 
	 * @return command list
	 */
	static private List<String> initialCommandList()
	{
		List<String> commandList = new LinkedList<>();
		if (isWindowsSystem())
		{
			commandList.add("cmd");
			commandList.add("/c");
		}
		else
		{
			commandList.add("/bin/sh");
			commandList.add("-c");
		}
		return commandList;
	}

	/**
	 * check, if operation system is a windows system
	 * 
	 * @return true, if current system is windows based, otherwise false
	 */
	private static boolean isWindowsSystem()
	{
		return System.getProperty("os.name").toLowerCase().contains("windows");
	}

	/**
	 * Creates specific cmake command including build mode and project folder
	 * depending in operation system
	 * 
	 * @param buildMode
	 *            build mode, which should be used for compiling
	 * @param projectFolder
	 *            the project folder containing CMakeLists.txt
	 * @return full specified cmake command
	 */
	static List<String> getCMakeCommand(BUILD_MODE buildMode, File projectFolder)
	{
		List<String> commandList = CommandBuilder.initialCommandList();
		commandList.add("cmake -G \"" + getCMakeGenerator() + "\" -D CMAKE_BUILD_TYPE=" + buildMode.getName() + " " + projectFolder.getAbsolutePath());
		return commandList;
	}

	/**
	 * Creates specific make command including parallel jobs option depending in
	 * operation system
	 * 
	 * @param project
	 *            current project instance contains existing properties
	 * @return full specified make command
	 */
	static List<String> getMakeCommand(Project project)
	{
		List<String> commandList = CommandBuilder.initialCommandList();
		commandList.add(getMakeTool() + " install" + GradlePropertyAnalyser.getParallelJobsFlag(project));
		return commandList;
	}

	/**
	 * returns the gnu make tool depending on operation system
	 * 
	 * @return gnu make tool
	 */
	static String getMakeTool()
	{
		if (isWindowsSystem())
		{
			return "mingw32-make";
		}
		else
		{
			return "make";
		}
	}
}
