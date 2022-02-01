package tui.sse.mde4cpp;

import java.io.File;
import java.util.LinkedList;
import java.util.List;

import org.gradle.api.DefaultTask;
import org.gradle.api.GradleException;
import org.gradle.api.file.FileCollection;
import org.gradle.api.tasks.InputFile;
import org.gradle.api.tasks.InputFiles;
import org.gradle.api.tasks.OutputDirectory;
import org.gradle.api.tasks.OutputFile;
import org.gradle.api.tasks.TaskAction;
import org.gradle.api.tasks.options.Option;

/**
 * Gradle task class for generating C++ projects of Ecore and UML models using MDE4CPP Code Generator<br>
 * Configuration options:<br>
 * 1. using parameter on task call<br>
 * - PModel={path} or --model={path} - model path<br>
 * - PStructureOnly=1 or -PSO=1 or --structureOnly - indicated to use UML4CPP on UML models, otherwise fUML4CPP is used for UML models, no effect on Ecore models<br>
 * <br>
 * 3. inside task declaration:<br>
 * - essential parameters:<br>
 * \t- File modelFile - model path<br>
 * \t- Boolean structureOnly - if set to 1, UML4CPP is used on UML models, otherwise fUML4CPP is used for UML models, no effect on Ecore models<br>
 * <br>
 * - optional parameters (will be calculated if not configured) 
 * \t- If generator is not configured, ecore4CPP generator is used for .ecore models and UML4CPP is used for .uml models
 * \t- String targetFolder - target folder for generated source code. Default folder is {model folder}/../src_gen.<br><br>
 * Further information:<br>
 * - Environment variable 'MDE4CPP_HOME' has to be set to calculate generator path ($MDE4CPP_HOME/application/generator/*.jar)<br>
 * - Working directory is the folder containing the model file.<br>
 * - Assumed folder structure:<br>
 * \troot project folder<br>
 * \t\tmodel folder<br>
 * \t\tgenerated source code folder<br><br>
 * More information can be found under https://github.com/MDE4CPP/gradlePlugins and http://sse.tu-ilmenau.de/mde4cpp
 *
 */
public class MDE4CPPGenerate extends DefaultTask
{
	private File modelFile = null;
	private boolean m_structureOnly = false;

	private String m_targetFolder = null;
	private String m_srcGenFolder = ".." + File.separator + "src_gen";

	private GENERATOR m_generator = GENERATOR.ECORE4CPP;
	private String m_workingDirectory = "";
	private String m_modelFileName = "";
	private List<String> m_relatedModels = null;
	
	/**
	 * @return generator file
	 */
	@InputFile
	public File getGenerator()
	{
		if (PropertyAnalyser.hasStructuredOnlyParameter(getProject()))
		{
			boolean structureOnly = PropertyAnalyser.isStructuredOnlyRequested(getProject());
			setStructureOnly(structureOnly);
		}
		
		return new File(m_generator.getPath());
	}
	
	/**
	 * @return gradle build file
	 */
	@OutputFile
	public File getGradleBuildFile()
	{
		return new File(m_workingDirectory + File.separator + ".." + File.separator + "build.gradle");
	}	
	
	/**
	 * @return model file
	 */
	@InputFile
	public File getModelFile()
	{
		if (modelFile == null)
		{
			String modelFilePath = PropertyAnalyser.getModelParameter(getProject());
			if (modelFilePath == null)
			{
				throw new GradleException("Property 'modelFilePath' is not set!\r\n" + "Configure the path to the model inside the gradle task or use parameter 'Model' (-PModel=<path>).");
			}
			
			File file = new File(modelFilePath);
			setModelFilePath(file);
		}
		
		return modelFile;
	}
	
	/**
	 * @return file list of related models
	 */
	@InputFiles
	public FileCollection getRelatedModels()
	{
		if (m_relatedModels == null)
		{
			return getProject().files();
		}
		else
		{
			return FileStructureAnalyser.getRelatedModels(getProject().getRootProject(), m_relatedModels);			
		}
	}
	
	/**
	 * @return target folder
	 */
	@OutputDirectory
	public File getTargetFolder()
	{
		if (m_targetFolder == null)
		{
			m_targetFolder = m_workingDirectory + File.separator + m_srcGenFolder;
		}
		return new File(m_targetFolder);
	}

	
	/**
	 * @param relatedModels - name list of related model
	 */
	public void setRelatedModels(List<String> relatedModels)
	{
		if (FileStructureAnalyser.isExperimentalMode(getProject()))
		{
			m_relatedModels = relatedModels;
		}
		else
		{
			m_relatedModels = null;
		}
	}
	
	/**
	 * Set target folder
	 * 
	 * @param generatorPath : String - specify target folder for generated code
	 */
	public void setGeneratorPath(String generatorPath)
	{
		if (generatorPath != null)
		{
			m_generator.setPath(generatorPath);
		}
	}

	/**
	 * @param modelFilePath - model path
	 */
	@Option(option = "model", description = "Configure the path to the model used by generator.")
	public void setModelFilePath(String modelFilePath)
	{
		File file = new File(modelFilePath);
		if (file.exists())
		{
			setModelFilePath(file);
		}
	}
	
	/**
	 * Set model file path
	 * 
	 * @param modelFilePath : File - specify model file
	 */
	public void setModelFilePath(File modelFilePath)
	{
		this.modelFile = modelFilePath;
		if (this.modelFile == null)
		{
			throw new GradleException("The property 'modelFile' is not configured!");
		}
		if (!modelFile.isFile())
		{
			throw new GradleException("The file '" + modelFile.getAbsolutePath() + "' is not an existing file!");
		}
			
		m_workingDirectory = modelFile.getParent();
		m_modelFileName = modelFile.getName();
		
		configureGenerator();
	}
	

	/**
	 * @param structureOnly - indicates, that the generator UML4COO should be used for a UML model
	 */
	@Option(option = "structureOnly", description = "Indicates, that the generator UML4CPP should be used for a UML model.")
	public void setStructureOnlyAsOption(boolean structureOnly)
	{
		if (structureOnly)
		{
			setStructureOnly(structureOnly);
		}
	}
	
	
	
	/**
	 * indicates, that UML4CPP should be used to generate only the structure of the model, not the activity execution part
	 * 
	 * @param structureOnly : Boolean - true to generate structure only, false to generate structure + execution part 
	 */
	public void setStructureOnly(boolean structureOnly)
	{
		if (structureOnly != m_structureOnly)
		{
			m_structureOnly = structureOnly;
			configureGenerator();
		}
	}
	
	/**
	 * Set target folder
	 * 
	 * @param targetFolder : String - specify target folder for generated code
	 */
	public void setTargetFolder(String targetFolder)
	{
		m_targetFolder = targetFolder;
	}

	private void configureGenerator()
	{
		if (m_modelFileName.isEmpty())
		{
			return;
		}
		int index = m_modelFileName.lastIndexOf('.');
		if (index == -1) 
		{
			throw new GradleException("The file '" + m_modelFileName + "' is not supported! Only '.ecore' and '.uml' files are supported!");
		}
		String extension = m_modelFileName.substring(index+1);
		
		if (extension.compareTo("ecore") == 0)
		{
			m_generator = GENERATOR.ECORE4CPP;
		}
		else if (extension.compareTo("uml") == 0 && !m_structureOnly)
		{
			m_generator = GENERATOR.FUML4CPP;
		}
		else if (extension.compareTo("uml") == 0 && m_structureOnly)
		{
			m_generator = GENERATOR.UML4CPP;
		}
		else
		{
			throw new GradleException("The file extension '" + extension + "' is not supported! Only '.ecore' and '.uml' models are supported!");			
		}

		setDependsOn(getProject().getRootProject().getTasksByName(m_generator.getCreateTaskName(), true));
	}
	
	/**
	 * check and complete configuration
	 * 
	 */
	private void configure()
	{
		if (FileStructureAnalyser.checkFileStructure(modelFile))
		{
			if (!m_workingDirectory.endsWith("model"))
			{
				m_workingDirectory += File.separator + "model";
			}
		}
		
		// check generator
		File file = new File(m_generator.getPath());
		if (!file.isFile())
		{
			throw new GradleException("Generator '" + m_generator.getName() + "' can not be found!" + 
											System.lineSeparator() + "Expected path: '" + m_generator.getPath() +"'." +
											System.lineSeparator() + "Please set 'MDE4CPP_HOME' correctly or use property 'generatorPath' for manual configuration.");			
		}
		
		file = new File(m_targetFolder);
		if (!file.isDirectory())
		{
			file.mkdirs();
			if (!file.exists())
			{
				throw new GradleException("Could not create target folder '" + file.getAbsolutePath() + "'");
			}
		}
	}

	/**
	 * generate C++ code for configured model model
	 */
	private void generateModel()
	{		
		List<String> command = new LinkedList<String>();
		command.add("java");
		command.add("-jar");
		command.add(m_generator.getPath());
		command.add(m_modelFileName);
		command.add(m_targetFolder);
		String startingMessage = "Generating model " + m_modelFileName + " using generator " + m_generator.getName();
		
		executeGenerateProcess(command, m_workingDirectory, startingMessage);		
	}

	/**
	 * execute generation
	 * 
	 * @param List command list
	 * @param String working directory
	 * @param String starting message
	 */
	private void executeGenerateProcess(List<String> commandList, String workingDir, String startingMessage)
	{
		try
		{
			ProcessBuilder processBuilder = new ProcessBuilder(commandList);
			processBuilder.directory(new File(workingDir));

			Process process = processBuilder.start();
			InputStreamThread inputThread = new InputStreamThread(process.getInputStream(), false);
			inputThread.setStartingMessage(startingMessage);
			InputStreamThread errorThread = new InputStreamThread(process.getErrorStream(), true);
			inputThread.start();
			errorThread.start();

			int code = process.waitFor();
			if (code != 0)
			{
				throw new GradleException("Generator execution failed!");	
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
			throw new GradleException("Generator execution failed!" + e.getMessage());
		}
	}

	/**
	 * entry point for this task
	 */
	@TaskAction
	void executeGenerate()
	{
		configure();
		generateModel();
	}
}