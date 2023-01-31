package ecore4CPP.generator.main;

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
public class Ecore4CPPEMtlResourceFactory extends EMtlResourceFactoryImpl {

	/**
	 * map storing pairs of {emtl file name, rsrc path}
	 */
	protected Map<String, String> m_emtlFilePathMap;
	private Map<URI, Resource> resourceMap = new HashMap<URI, Resource>();
		
	/**
	 * factory to create resource path based on URI
	 */
	public Ecore4CPPEMtlResourceFactory()
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
		String resourcePathPrefix = "rsrc:ecore4CPP/generator/main/";
		initalizeGeneralEmtls(resourcePathPrefix);
		initializeComponentsEmtls(resourcePathPrefix);
		initializeConfigurationEmtls(resourcePathPrefix);
		initializeFactoryEmtls(resourcePathPrefix);
		initializeHelpersEmtls(resourcePathPrefix);
		initializeClassesEmtls(resourcePathPrefix);
		initializePackageEmtls(resourcePathPrefix);
		initializePluginEmtls(resourcePathPrefix);
		initializeValidationEmtls(resourcePathPrefix);
	}
	
	private void initalizeGeneralEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generate", 
								"generateApplication",
								"generateAttribute",
								"generateBehavioralFeatureInvoke",
								"generateBuildFile",
								"generateEClass",
								"generateDatatype",
								"generateEnum",
								"generateOperation",
								"generatePackageHeaderFile",
								"generatePersistence",
								"generateProjectFiles",
								"generateReference",
								"generateSingleton",
								"generateStructuralFeatureSetGet",
								"generateType",
								"generateUnion",
								"helper"
								};
		generateFilePathMapData(moduleNames, "", resourcePathPrefix);	   	 
	}
	
	private void initializeComponentsEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {};
		generateFilePathMapData(moduleNames, "components", resourcePathPrefix);
	}
	
	private void initializeConfigurationEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {};
		generateFilePathMapData(moduleNames, "configuration", resourcePathPrefix);
	}
	
	private void initializeFactoryEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateMetamodelFactory",
								"generateFactoryImplementationHeader",
								"generateFactoryImplementationSource",
								"generateFactoryInterface"
								};
		generateFilePathMapData(moduleNames, "model_factory", resourcePathPrefix);
	}
	
	private void initializeHelpersEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"keywords",
								"IDHelper"
								};
		generateFilePathMapData(moduleNames, "helpers", resourcePathPrefix);
	}

	private void initializeClassesEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateClass",
								"generateClassInterfaceHeader",
								"generateClassImplementationHeader",
								"generateClassImplementationSource"
								};
		generateFilePathMapData(moduleNames, "classes", resourcePathPrefix);
	}
	
	private void initializePackageEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateMetamodelPackage",
								"generatePackageHelper",
								"generatePackageImplementationHeader",
								"generatePackageImplementationSource",
								"generatePackageInterface"
								};
		generateFilePathMapData(moduleNames, "model_package", resourcePathPrefix);
	}
	
	private void initializePluginEmtls(String resourcePathPrefix)
	{
		String[] moduleNames = {"generateEcorePlugin",
								"generateEcorePluginImplementationHeader",
								"generateEcorePluginImplementationSource",
								"generateEcorePluginInterfaceHeader"
								};
		generateFilePathMapData(moduleNames, "model_plugin", resourcePathPrefix);
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