package UML4CPP_test.generator.main;

import UML4CPP.generator.main.UML4CPPEMtlResourceFactory;

/**
 * factory to create resource path based on URI
 *
 */
public class UML4CPP_testEMtlResourceFactory extends UML4CPPEMtlResourceFactory {
		
	/**
	 * factory to create resource path based on URI
	 */
	public UML4CPP_testEMtlResourceFactory()
	{
		initialize();
	}
		
	protected void initialize()
	{
		super.initialize();
		String resourcePathPrefix = "rsrc:UML4CPP_test/generator/main/";
		initalizeMainEmtls(resourcePathPrefix);
		initalizeGenerateHelpersEmtls(resourcePathPrefix);
		initalizeProjectFilesEmtls(resourcePathPrefix);
		initalizeTestSuiteEmtls(resourcePathPrefix);
	}
	
	private void initalizeMainEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {
			"generate"
		};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);
	}
	
	private void initalizeGenerateHelpersEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {
			"generateCountHelper",
			"generateHelpers",
			"generateMainHelper",
			"generateMemoryHelper",
			"generateTimeHelper"
		};
		generateFilePathMapData(moduleNames, "generate_helpers", resourcePathPrefix);
	}
	
	private void initalizeProjectFilesEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {
			"generateApplication",
			"generateCMake",
			"generateEclipseFiles",
			"generateGradleFiles",
			"generateProjectFiles"
		};
		generateFilePathMapData(moduleNames, "project_files", resourcePathPrefix);
	}
	
	private void initalizeTestSuiteEmtls(String resourcePathPrefix)
	{		
		String[] moduleNames = {"generateImplementation",
								"generateImplementationHeader",
								"generateImplementationSource",
								"generateOperation"
		};
		generateFilePathMapData(moduleNames, "test_suite", resourcePathPrefix);
	}
}

