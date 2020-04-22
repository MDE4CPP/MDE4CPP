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
	}
	
	private void initalizeGeneralEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {
								"generateClassifierObjectHeader",
								"generateClassifierObjectSource",
								"generateExpansionRegionActiviationHeader",
								"generateExpansionRegionActiviationSource",
								"generateExecutionBuildFile",
								"generateExecutionProjectFiles",
								"generateModelExecutionFactoryHeader",
								"generateModelExecutionFactorySource",
								"generateModelLocusHeader",
								"generateModelLocusSource",
								"generateFUML",
								"generateMainExecution",
								"generateOpaqueBehaviorExecution",
								"generateOpaqueBehaviorExecutionHeader",
								"generateOpaqueBehaviorExecutionSource",
								"generateOperationExecution",
								"generateOperationExecutionHeader",
								"generateOperationExecutionSource",
								"parameterHelper"
		};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);
	}
	
	private void initalizePluginEmtls(String resourcePathPrefix)
	{
		String[] ModuleNames = {"generateExecutionPlugin",
								"generateExecutionPluginImplementationHeader",
								"generateExecutionPluginImplementationSource",
								"generateExecutionPluginInterfaceHeader",
								"generateExecutionPluginInterfaceSource"
								};
		generateFilePathMapData(ModuleNames, "plugin", resourcePathPrefix);
	}
}

