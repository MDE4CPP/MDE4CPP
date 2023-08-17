package UML4CPP.generator.main;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import org.eclipse.acceleo.model.mtl.resource.EMtlResourceFactoryImpl;
import org.eclipse.acceleo.model.mtl.resource.EMtlResourceImpl;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.resource.Resource;

/**
 * factory to create resource path based on URI
 *
 */
public class UML4CPPEMtlResourceFactory extends EMtlResourceFactoryImpl {

	/**
	 * map storing pairs of {emtl file name, rsrc path}
	 */
	protected Map<String, String> m_emtlFilePathMap;
	private Map<URI, Resource> resourceMap = new HashMap<URI, Resource>();
		
	/**
	 * factory to create resource path based on URI
	 */
	public UML4CPPEMtlResourceFactory()
	{
		m_emtlFilePathMap = new HashMap<String, String>();
		initialize();
	}
	
	public Resource createResource(URI uri)
	{
		if (resourceMap.containsKey(uri))
		{
			return resourceMap.get(uri);
		}
		else
		{
			String uriString = uri.path();
			//System.out.print(uriString + "\t\t");
			boolean found = false;
			Set<String> keySet = m_emtlFilePathMap.keySet();
			for (String key : keySet)
			{
				if (uriString.endsWith(key))
				{
					uriString = m_emtlFilePathMap.get(key);
					found = true;
					break;
				}
			}
			if (!found)
			{
				System.err.println(uriString + " not found!");
			}

			//System.out.println(uriString);
			EMtlResourceImpl xmiResource = new EMtlResourceImpl(URI.createURI(uriString));
			resourceMap.put(uri, xmiResource);
			return xmiResource;
		}
	}
	
	/**
	 * fill {@code m_etmlFilePathMap} with UML specific emtl file/rsrc path pairs
	 */
	protected void initialize()
	{
		String resourcePathPrefix = "rsrc:UML4CPP/generator/main/";
		initalizeGeneralEmtls(resourcePathPrefix);
		initializeClassesEmtls(resourcePathPrefix);
		initializeComponentsEmtls(resourcePathPrefix);
		initializeConfigurationEmtls(resourcePathPrefix);
		initializeDataTypeEmtls(resourcePathPrefix);
		initializeEnumerationsEmtls(resourcePathPrefix);
		initializeHelpersEmtls(resourcePathPrefix);
		initializeInterfacesEmtls(resourcePathPrefix);
		initializeMainApplicationEmtls(resourcePathPrefix);
		initializeModelExecutionEmtls(resourcePathPrefix);
		initializeModelFactoryEmtls(resourcePathPrefix);
		initializeModelGlobalFunctionsEmtls(resourcePathPrefix);
		initializeModelPackageEmtls(resourcePathPrefix);
		initializeModelPluginEmtls(resourcePathPrefix);
		initializeProfilesEmtls(resourcePathPrefix);
		initializePscsEmtls(resourcePathPrefix);
		initializePssmEmtls(resourcePathPrefix);
		initializeSignalsEmtls(resourcePathPrefix);
		initializeValidationEmtls(resourcePathPrefix);
	}
	
	private void initalizeGeneralEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generate"};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);	   	 
	}
	
	private void initializeClassesEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateClassFiles",
								"generateClassImplementationHeader",
								"generateClassImplementationSource",
								"generateClassInterfaceHeader",
								"generateClassInterfaceSource"
								};
		generateFilePathMapData(moduleNames, "classes", resourcePathPrefix);
	}
	
	private void initializeComponentsEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateActivity", 
								"generateActivityEdge",
								"generateActivityNode",
								"generateAssociation",
								"generateClass",
								"generateConnector",
								"generateDataType",
								"generateDependency",
								"generateNamedElement",
								"generateConstraint",
								"generateEnumeration",
								"generateFunctionBehavior",
								"generateInstanceSpecification",
								"generateInterface",
								"generateInterfaceRealization",
								"generateOpaqueBehavior",
								"generateOperation",
								"generateParameter",
								"generatePrimitivetype", 
								"generateProperty",
								"generateSignal",
								"generateStereotype",
								"generateStructuralFeature",
								"generateType",
	   	 						"generateValueSpecification"
								};
		generateFilePathMapData(moduleNames, "components", resourcePathPrefix);
	}
	
	private void initializeConfigurationEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateCMakeFiles",
								"generateConfigurationFiles",
								"generateGradleFiles",
								"generateEclipseFiles"
								};
		generateFilePathMapData(moduleNames, "configuration", resourcePathPrefix);
	}
	
	private void initializeDataTypeEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateDataTypeFiles",
								"generateDataTypeImplementationHeader",
								"generateDataTypeImplementationSource",
								"generateDataTypeInterfaceHeader"
								};
		generateFilePathMapData(moduleNames, "datatypes", resourcePathPrefix);
	}
	
	private void initializeEnumerationsEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateEnumerationFiles",
								"generateEnumerationHeader"
								};
		generateFilePathMapData(moduleNames, "enumerations", resourcePathPrefix);
	}
	
	private void initializeHelpersEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"collectionHelper",
								"generalHelper",
								"keywords",
								"nameHelper",
								"setGetHelper",
								"singletonHelper",
								"IDHelper",
								"isGeneratableHelper"
								};
		generateFilePathMapData(moduleNames, "helpers", resourcePathPrefix);
	}
	
	private void initializeInterfacesEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateInterfaceFiles",
								"generateInterfaceHeader"
								};
		generateFilePathMapData(moduleNames, "interfaces", resourcePathPrefix);
	}
	
	private void initializeMainApplicationEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateMainApplicationFiles",
								"generateMainApplicationCMakeFile",
								"generateMainApplicationGradleFile",
								"generateMainApplicationSource"
								};
		generateFilePathMapData(moduleNames, "main_application", resourcePathPrefix);
	}
	
	private void initializeModelExecutionEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"model_execution"};
		generateFilePathMapData(moduleNames, "model_execution", resourcePathPrefix);
	}
	
	private void initializeModelFactoryEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateFactoryFiles",
								"generateFactoryImplementationHeader",
								"generateFactoryImplementationSource",
								"generateFactoryInterface"
								};
		generateFilePathMapData(moduleNames, "model_factory", resourcePathPrefix);
	}
	
	private void initializeModelGlobalFunctionsEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generatePackageGlobalFunctionsFiles",
								"generatePackageGlobalFunctionsHeader",
								"generatePackageGlobalFunctionsSource"
								};
		generateFilePathMapData(moduleNames, "model_global_functions", resourcePathPrefix);
	}
	
	private void initializeModelPackageEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generatePackageFiles",
								"generatePackageImplementationHeader",
								"generatePackageImplementationSource",
								"generatePackageInterface"
								};
		generateFilePathMapData(moduleNames, "model_package", resourcePathPrefix);
	}
	
	private void initializeModelPluginEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generatePluginFiles",
								"generatePluginImplementationHeader",
								"generatePluginImplementationSource",
								"generatePluginInterfaceHeader"
								};
		generateFilePathMapData(moduleNames, "model_plugin", resourcePathPrefix);
	}
	
	private void initializeProfilesEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"fUMLStrategiesProfileKeywords",
								"PSCSStrategiesProfileKeywords",
								"profileHelper",
								"strategyHelper",
								"uml4CPPProfileHelper"
								};
		generateFilePathMapData(moduleNames, "profiles", resourcePathPrefix);
	}
	
    private void initializePscsEmtls(String resourcePathPrefix)
    {
        String[] moduleNames = {"generatePropertyInstantiation",
        						"generateConnectorPatternsInstantiation",
        						"generateDestruction"
        						};
        generateFilePathMapData(moduleNames, "pscs", resourcePathPrefix);
    }
    
    private void initializePssmEmtls(String resourcePathPrefix)
    {
    	String[] moduleNames = {"generateStateMachine"
    							};
    	generateFilePathMapData(moduleNames, "pssm", resourcePathPrefix);
    }

	private void initializeSignalsEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateSignalFiles",
								"generateSignalImplementationHeader",
								"generateSignalImplementationSource",
								"generateSignalInterfaceHeader"
								};
		generateFilePathMapData(moduleNames, "signals", resourcePathPrefix);
	}
	
	private void initializeValidationEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"validation"};
		generateFilePathMapData(moduleNames, "validation", resourcePathPrefix);
	}

	/**
	 * generate pair of {emtl file name, rsrc file path} 
	 * 
	 * @param moduleNameList - list of module names
	 * @param subfolderName - subfolder name
	 * @param resourcePathPrefix - rsrc prefix until base folder of module files
	 */
	protected void generateFilePathMapData(String[] moduleNameList, String subfolderName, String resourcePathPrefix)
	{
		for (String moduleName : moduleNameList) 
		{
			String key = moduleName + ".emtl";
			String value = resourcePathPrefix;
			if (!subfolderName.isEmpty())
			{
				value += subfolderName + "/";
			}
			value += key;
			m_emtlFilePathMap.put(key, value);
		}
	}
}