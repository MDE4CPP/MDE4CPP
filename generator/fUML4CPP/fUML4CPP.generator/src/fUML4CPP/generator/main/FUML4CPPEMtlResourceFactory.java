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
		initalizeGeneralEmtls();
	}
	
	private void initalizeGeneralEmtls()
	{
		m_emtlFilePathMap.put("generateBehaviorExecutionHeader.emtl", "rsrc:fUML4CPP/generator/main/generateBehaviorExecutionHeader.emtl");
		m_emtlFilePathMap.put("generateBehaviorExecutionSource.emtl", "rsrc:fUML4CPP/generator/main/generateBehaviorExecutionSource.emtl");
     	m_emtlFilePathMap.put("generateCallOperationActionExecutionHeader.emtl", "rsrc:fUML4CPP/generator/main/generateCallOperationActionExecutionHeader.emtl");
    	m_emtlFilePathMap.put("generateCallOperationActionExecutionSource.emtl", "rsrc:fUML4CPP/generator/main/generateCallOperationActionExecutionSource.emtl");
       	m_emtlFilePathMap.put("generateClassifierObjectHeader.emtl", "rsrc:fUML4CPP/generator/main/generateClassifierObjectHeader.emtl");
    	m_emtlFilePathMap.put("generateClassifierObjectSource.emtl", "rsrc:fUML4CPP/generator/main/generateClassifierObjectSource.emtl");
    	m_emtlFilePathMap.put("generateExecutionBuildFile.emtl", "rsrc:fUML4CPP/generator/main/generateExecutionBuildFile.emtl");
    	m_emtlFilePathMap.put("generateExecutionPlugin.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPlugin.emtl");
    	m_emtlFilePathMap.put("generateExecutionPluginImplementationHeader.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPluginImplementationHeader.emtl");
    	m_emtlFilePathMap.put("generateExecutionPluginImplementationSource.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPluginImplementationSource.emtl");
    	m_emtlFilePathMap.put("generateExecutionPluginInterfaceHeader.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPluginInterfaceHeader.emtl");
    	m_emtlFilePathMap.put("generateExecutionPluginInterfaceSource.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPluginInterfaceSource.emtl");
       	m_emtlFilePathMap.put("generateExecutionProjectFiles.emtl", "rsrc:fUML4CPP/generator/main/generateExecutionProjectFiles.emtl");
       	m_emtlFilePathMap.put("generateFUML.emtl", "rsrc:fUML4CPP/generator/main/generateFUML.emtl");
      	m_emtlFilePathMap.put("generateMainExecution.emtl", "rsrc:fUML4CPP/generator/main/generateMainExecution.emtl");
      	m_emtlFilePathMap.put("generateOpaqueBehaviorExecution.emtl", "rsrc:fUML4CPP/generator/main/generateOpaqueBehaviorExecution.emtl");
     	m_emtlFilePathMap.put("parameterHelper.emtl", "rsrc:fUML4CPP/generator/main/parameterHelper.emtl");
	}
}

