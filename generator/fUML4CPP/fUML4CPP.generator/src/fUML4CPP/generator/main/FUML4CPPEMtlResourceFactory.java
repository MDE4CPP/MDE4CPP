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
		initalizeGeneralEmtls(resourcePathPrefix);
		initalizePluginEmtls(resourcePathPrefix);
		initalizeStrategyEmtls(resourcePathPrefix);
	}
	
	private void initalizeGeneralEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {
								"generateExecutionBuildFile",
								"generateModelExecutorHeader",
								"generateModelExecutorSource",
								"generateModelLocusHeader",
								"generateModelLocusSource",
								"generateModelExecutionFactoryHeader",
								"generateModelExecutionFactorySource",
								"generateFUML",
								"fUMLCollectionHelper",
								"fUMLKeywords",
								"parameterHelper"
		};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);
	}
	
	private void initalizePluginEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateExecutionPlugin",
								"generateExecutionPluginImplementationHeader",
								"generateExecutionPluginImplementationSource",
								"generateExecutionPluginInterfaceHeader"
								};
		generateFilePathMapData(ModuleNames, "plugin", resourcePathPrefix);
	}
	
	private void initalizeStrategyEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateStrategyHeader",
								"generateStrategySource"
								};
		generateFilePathMapData(ModuleNames, "strategies", resourcePathPrefix);
	}
}

