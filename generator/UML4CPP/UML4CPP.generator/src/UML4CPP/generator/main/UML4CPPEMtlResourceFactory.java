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
		initializeComponentsEmtls(resourcePathPrefix);
		initializeConfigurationEmtls(resourcePathPrefix);
		initializeFactoryEmtls(resourcePathPrefix);
		initializeHelpersEmtls(resourcePathPrefix);
		initializeImplEmtls(resourcePathPrefix);
		initializePackageEmtls(resourcePathPrefix);
		initializePluginEmtls(resourcePathPrefix);
		initializeValidationEmtls(resourcePathPrefix);
	}
	
	private void initalizeGeneralEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generate", 
								"generateApplication", 
								"generateAttribute", 
								"generateClass",
								"generateEnumerationFile",
								"generateInterface",
								"generateMainExecution",
								"generateModel",
								"generateOperation",
								"generateSetGet",
								"generateSingleton",
								"generateStereotype",
								"generateType",
	   	 						"generateValueSpecification"
								};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);	   	 
	}
	
	private void initializeComponentsEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateActivity", 
								"generateActivityEdge",
								"generateActivityNode",
								"generateNamedElement",
								"generateConstraint",
								"generateEnumeration",
								"generateFunctionBehavior",
								"generateInstanceSpecification",
								"generateInterfaceRealization",
								"generateParameter",
								"generatePrimitivetype"
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
	
	private void initializeFactoryEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateFactory",
								"generateFactoryImplementationHeader",
								"generateFactoryImplementationSource",
								"generateFactoryInterface",
								"generateFactoryInterfaceSource"
								};
		generateFilePathMapData(moduleNames, "factory", resourcePathPrefix);
	}
	
	private void initializeHelpersEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"collectionHelper",
								"generalHelper",
								"keywords",
								"nameHelper"
								};
		generateFilePathMapData(moduleNames, "helpers", resourcePathPrefix);
	}

	private void initializeImplEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateImplModelSource",
								"generateImplementation",
								"generateImplementationHeader",
								"generateImplementationSource"
								};
		generateFilePathMapData(moduleNames, "impl", resourcePathPrefix);
	}
	
	private void initializePackageEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generatePackage",
								"generatePackageImplementationHeader",
								"generatePackageImplementationSource",
								"generatePackageInterface",
								"generatePackageInterfaceSource"
								};
		generateFilePathMapData(moduleNames, "package", resourcePathPrefix);
	}
	
	private void initializePluginEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateUMLPlugin",
								"generateUMLPluginImplementationHeader",
								"generateUMLPluginImplementationSource",
								"generateUMLPluginInterfaceHeader",
								"generateUMLPluginInterfaceSource"
								};
		generateFilePathMapData(moduleNames, "plugin", resourcePathPrefix);
	}
	
	private void initializeValidationEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"validateModel"};
		generateFilePathMapData(moduleNames, "validation", resourcePathPrefix);
	}

	protected void generateFilePathMapData(String[] fileNameList, String subfolderName, String resourcePathPrefix)
	{
		for (String fileName : fileNameList) 
		{
			String key = fileName + ".emtl";
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