package fUML4CPP.generator.main;

import UML4CPP.generator.main.UML4CPPEMtlResourceFactory;

/**
 * factory to create resource path based on URI
 *
 */
public class FUML4CPPEMtlResourceFactory extends UML4CPPEMtlResourceFactory {
		
	/**
	 * factory to create resource path based on URI
	 */
	public FUML4CPPEMtlResourceFactory()
	{
		initialize();
	}
		
	protected void initialize()
	{
		super.initialize();
		String resourcePathPrefix = "rsrc:fUML4CPP/generator/main/";
		initializeGeneralEmtls(resourcePathPrefix);
		initializeBuildFilesEmtls(resourcePathPrefix);
		initializeHelpersEmtls(resourcePathPrefix);
		initializeModelExecutionFactoryEmtls(resourcePathPrefix);
		initializeModelExecutionPluginEmtls(resourcePathPrefix);
		initializeModelExecutorEmtls(resourcePathPrefix);
		initializeModelLocusEmtls(resourcePathPrefix);
		initializeStrategyEmtls(resourcePathPrefix);
		initializePssmEmtls(resourcePathPrefix);
	}
	
	private void initializeGeneralEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {"generateFUML"};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);
	}
	
	private void initializeBuildFilesEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"build_files_helper",
								"generateExecutionBuildFiles",
								"generateExecutionCMakeFile",
								"generateExecutionGradleFiles"
								};
		generateFilePathMapData(ModuleNames, "build_files", resourcePathPrefix);
	}
	
	private void initializeHelpersEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"fUMLCollectionHelper",
								"fUMLKeywords",
								"parameterHelper"
								};
		generateFilePathMapData(ModuleNames, "helpers", resourcePathPrefix);
	}
	
	private void initializeModelExecutionFactoryEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateModelExecutionFactoryFiles",
								"generateModelExecutionFactoryImplementationHeader",
								"generateModelExecutionFactoryImplementationSource",
								"generateModelExecutionFactoryInterfaceHeader"
								};
		generateFilePathMapData(ModuleNames, "model_execution_factory", resourcePathPrefix);
	}
	
	private void initializeModelExecutionPluginEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateExecutionPluginFiles",
								"generateExecutionPluginImplementationHeader",
								"generateExecutionPluginImplementationSource",
								"generateExecutionPluginInterfaceHeader"
								};
		generateFilePathMapData(ModuleNames, "model_execution_plugin", resourcePathPrefix);
	}
	
	private void initializeModelExecutorEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateModelExecutorFiles",
								"generateModelExecutorImplementationHeader",
								"generateModelExecutorImplementationSource",
								"generateModelExecutorInterfaceHeader"
								};
		generateFilePathMapData(ModuleNames, "model_executor", resourcePathPrefix);
	}
	
	private void initializeModelLocusEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateModelLocusFiles",
								"generateModelLocusImplementationHeader",
								"generateModelLocusImplementationSource",
								"generateModelLocusInterfaceHeader"
								};
		generateFilePathMapData(ModuleNames, "model_locus", resourcePathPrefix);
	}
	
	private void initializeStrategyEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateStrategyHeader",
								"generateStrategySource"
								};
		generateFilePathMapData(ModuleNames, "strategies", resourcePathPrefix);
	}
	
	private void initializePssmEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generatePssmExecutionPrototypes"
								};
		generateFilePathMapData(ModuleNames, "pssm", resourcePathPrefix);
	}
}

