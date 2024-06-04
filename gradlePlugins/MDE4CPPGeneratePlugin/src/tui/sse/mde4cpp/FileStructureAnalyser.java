package tui.sse.mde4cpp;

import java.io.File;
import java.io.FileFilter;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JOptionPane;

import org.gradle.api.GradleException;
import org.gradle.api.Project;
import org.gradle.api.file.ConfigurableFileCollection;
import org.gradle.api.file.FileCollection;


/**
 * This class analyzed the file structure around the model file.<br>
 * Following file structure is necessary to use the MDE4CPP generators without additional manual changes:<br>
 * 
 * Project root folder<br>
 * <ul>
 * 	<li>model
 * 	<ul>
 * 	<li>model.uml / model.ecore</li>
 * 	<li>...</li>
 * 	</ul></li>
 * 	<li>src_gen
 *  <ul>
 * 		<li>generated source code</li>
 *  </ul></li>
 * </ul>
 *
 */
public class FileStructureAnalyser 
{
	/**
	 * check, if the model file is 
	 * 
	 * @param modelFile - the model file
	 * @return true, if file structure is fine, otherwise false
	 */
	static public boolean checkFileStructure(File modelFile)
	{
		if (isParentFolderCalledModel(modelFile))
		{
			return true;
		}
		
		if (!requestFileStructureAdaption(modelFile))
		{
			return false;
		}
		
		return moveModelIntoSubfolder(modelFile);
	}
	
	
	/**
	 * checks, if model folder is called 'model'
	 */
	static private boolean isParentFolderCalledModel(File file)
	{
		File parentFile = file.getParentFile();
		return parentFile.isDirectory() && (parentFile.getName().compareTo("model") == 0);
	}
	
	/**
	 * inform the user, that the file structure is not well defined and ask, if the file structure should be changed
	 * @param modelFile - the model file
	 * @return true for change model structure, otherwise false
	 */
	static private boolean requestFileStructureAdaption(File modelFile)
	{
		String whiteSpace = "    ";
		String message = "To use the MDE4CPP generators without additional manual modification, the following file structure is necessary:" + System.lineSeparator()
				+ whiteSpace + modelFile.getParent() + System.lineSeparator()
				+ whiteSpace + whiteSpace + "model" + System.lineSeparator()
				+ whiteSpace + whiteSpace + whiteSpace + modelFile.getName() + System.lineSeparator();
		
		for (File file : modelFile.getParentFile().listFiles()) 
		{
			if (file.getName().compareTo(".project") == 0)
			{
				message += whiteSpace + whiteSpace + whiteSpace + file.getName() + System.lineSeparator();
			}
			else if (file.getName().endsWith(".aird"))
			{
				message += whiteSpace + whiteSpace + whiteSpace + file.getName() + System.lineSeparator();			
			}
		}
		
		message	+= whiteSpace + whiteSpace + "src_gen" + System.lineSeparator()
				+ System.lineSeparator()
				+ "Do you want to move the model file to the subfolder 'model'?";
			
		int result = JOptionPane.showConfirmDialog(null, message, "File structure issue", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE);
		if (result == JOptionPane.YES_OPTION)
		{
			return true;
		}
		else if (result == JOptionPane.NO_OPTION)
		{
			return false;
		}
		else
		{
			throw new GradleException("Generation canceld by user.");
		}
	}
	
	static private boolean moveModelIntoSubfolder(File modelFile)
	{
		File parentFolder = modelFile.getParentFile();

		String modelFolderPath = parentFolder.getAbsolutePath() + File.separator + "model"; 
		File modelFolder = new File(modelFolderPath);
		if (!modelFolder.exists())
		{
			modelFolder.mkdir();
		}
		moveFile(modelFile, modelFolderPath);
		
		for (File file : parentFolder.listFiles()) 
		{
			if (file.getName().compareTo(".project") == 0)
			{
				moveFile(file, modelFolderPath);
			}
			else if (file.getName().endsWith(".aird"))
			{
				moveFile(file, modelFolderPath);				
			}
		}	
				
		return true;
	}
	
	static private void moveFile(File file, String targetPath)
	{

		file.renameTo(new File(targetPath + File.separator + file.getName()));
	}
	
	/**
	 * @param project Gradle project
	 * @param modelNames list of related model names
	 * @return file set of related models
	 */
	public static FileCollection getRelatedModels(Project project, List<String> modelNames)
	{
		List<File> modelFiles = collectModels(project.getRootDir());
		
		FileCollection collection = project.files();
		ConfigurableFileCollection col = project.files(); 
		for (File modelFile : modelFiles)
		{
			for (String modelName : modelNames)
			{
				if (modelFile.getName().compareToIgnoreCase(modelName + ".uml") == 0)
				{
					collection = collection.plus(col.from(modelFile));
				}
				else if (modelFile.getName().compareToIgnoreCase(modelName + ".ecore") == 0)
				{
					collection = collection.plus(col.from(modelFile));
				}
			}
		}

		return collection;
	}
	
	private static List<File> collectModels(File file)
	{	
		final FileFilter filter = new FileFilter() 
		{
			@Override
			public boolean accept(File pathname) 
			{
				if (pathname.isDirectory())
				{
					return true;
				}
				String name = pathname.getName();
				int index = name.lastIndexOf('.');
				if (index == -1)
				{
					return false;
				}
				String extension = name.substring(index+1);
				return extension.compareToIgnoreCase("uml") == 0 || extension.compareToIgnoreCase("ecore") == 0 ;
			}
		};
		
		List<File> fileList = new LinkedList<>();
		for (File childFile : file.listFiles(filter)) 
		{
			if (childFile.isDirectory())
			{
				fileList.addAll(collectModels(childFile));
			}
			else
			{
				fileList.add(childFile);
			}
		}
		return fileList;
	}
	
	/**
	 * @param project Gradle project
	 * @return true for experimental mode activation, otherwise false
	 */
	static boolean isExperimentalMode(Project project)
	{
		if (project.hasProperty("experimentalMode"))
		{
			return Boolean.valueOf(project.property("experimentalMode").toString());
		}
		else
		{
			return false;
		}
	}
}
