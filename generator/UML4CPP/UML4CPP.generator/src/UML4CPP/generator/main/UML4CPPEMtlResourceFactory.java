package UML4CPP.generator.main;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import org.eclipse.acceleo.model.mtl.resource.EMtlResourceFactoryImpl;
import org.eclipse.acceleo.model.mtl.resource.EMtlResourceImpl;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.resource.Resource;

public class UML4CPPEMtlResourceFactory extends EMtlResourceFactoryImpl {

	protected Map<String, String> m_emtlFilePathMap;
	private Map<URI, Resource> resourceMap = new HashMap<URI, Resource>();
		
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
			 Set<String> keySet = m_emtlFilePathMap.keySet();
			 for (String key : keySet)
			 {
				 if (uriString.endsWith(key))
				 {
					 uriString = m_emtlFilePathMap.get(key);
					 break;
				 }
			 }
		
			 //System.out.println(uriString);
			 EMtlResourceImpl xmiResource = new EMtlResourceImpl(URI.createURI(uriString));
			 resourceMap.put(uri, xmiResource);
			 return xmiResource;
		 }
	 }
	
	protected void initialize()
	{
		initalizeGeneralEmtls();
		initializeConfigurationEmtls();
		initializeFactoryEmtls();
	}
	
	private void initalizeGeneralEmtls()
	{
	  	 m_emtlFilePathMap.put("configurationHelper.emtl", "rsrc:UML4CPP/generator/main/helpers/configurationHelper.emtl");
	   	 m_emtlFilePathMap.put("generate.emtl", "rsrc:UML4CPP/generator/main/generate.emtl");
	   	 m_emtlFilePathMap.put("generateActivity.emtl", "rsrc:UML4CPP/generator/main/generateActivity.emtl");
	   	 m_emtlFilePathMap.put("generateActivityEdge.emtl", "rsrc:UML4CPP/generator/main/generateActivityEdge.emtl");
	   	 m_emtlFilePathMap.put("generateActivityNode.emtl", "rsrc:UML4CPP/generator/main/generateActivityNode.emtl");
	   	 m_emtlFilePathMap.put("generateApplication.emtl", "rsrc:UML4CPP/generator/main/generateApplication.emtl");
	   	 m_emtlFilePathMap.put("generateAttribute.emtl", "rsrc:UML4CPP/generator/main/generateAttribute.emtl");
	  	 m_emtlFilePathMap.put("generateClass.emtl", "rsrc:UML4CPP/generator/main/generateClass.emtl");
	 	 m_emtlFilePathMap.put("generateConstraint.emtl", "rsrc:UML4CPP/generator/main/generateConstraint.emtl");
	   	 m_emtlFilePathMap.put("generateEnum.emtl", "rsrc:UML4CPP/generator/main/generateEnum.emtl");
	   	 m_emtlFilePathMap.put("generateExecutionBuildFile.emtl", "rsrc:fUML4CPP/generator/main/generateExecutionBuildFile.emtl");
	   	 m_emtlFilePathMap.put("generateExecutionPlugin.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPlugin.emtl");
	   	 m_emtlFilePathMap.put("generateExecutionPluginImplementationHeader.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPluginImplementationHeader.emtl");
	   	 m_emtlFilePathMap.put("generateExecutionPluginImplementationSource.emtl", "rsrc:fUML4CPP/generator/main/plugin/generateExecutionPluginImplementationSource.emtl");
	   	 m_emtlFilePathMap.put("generateFunctionBehavior.emtl", "rsrc:UML4CPP/generator/main/generateFunctionBehavior.emtl");
	   	 m_emtlFilePathMap.put("generateImplModelSource.emtl", "rsrc:UML4CPP/generator/main/impl/generateImplModelSource.emtl");
	   	 m_emtlFilePathMap.put("generateImplementation.emtl", "rsrc:UML4CPP/generator/main/impl/generateImplementation.emtl");
	   	 m_emtlFilePathMap.put("generateImplementationHeader.emtl", "rsrc:UML4CPP/generator/main/impl/generateImplementationHeader.emtl");
	   	 m_emtlFilePathMap.put("generateImplementationSource.emtl", "rsrc:UML4CPP/generator/main/impl/generateImplementationSource.emtl");
	   	 m_emtlFilePathMap.put("generateInstanceSpecification.emtl", "rsrc:UML4CPP/generator/main/generateInstanceSpecification.emtl");
	   	 m_emtlFilePathMap.put("generateInterface.emtl", "rsrc:UML4CPP/generator/main/generateInterface.emtl");
	   	 m_emtlFilePathMap.put("generateInterfaceRealization.emtl", "rsrc:UML4CPP/generator/main/generateInterfaceRealization.emtl");
	   	 m_emtlFilePathMap.put("generateMainExecution.emtl", "rsrc:fUML4CPP/generator/main/generateMainExecution.emtl");
	   	 m_emtlFilePathMap.put("generateMetamodelPackage.emtl", "rsrc:UML4CPP/generator/main/package/generateMetamodelPackage.emtl");
	   	 m_emtlFilePathMap.put("generateModel.emtl", "rsrc:UML4CPP/generator/main/generateModel.emtl");
	   	 m_emtlFilePathMap.put("generateOperation.emtl", "rsrc:UML4CPP/generator/main/generateOperation.emtl");
	   	 m_emtlFilePathMap.put("generatePackageImplementationHeader.emtl", "rsrc:UML4CPP/generator/main/package/generatePackageImplementationHeader.emtl");
	   	 m_emtlFilePathMap.put("generatePackageImplementationSource.emtl", "rsrc:UML4CPP/generator/main/package/generatePackageImplementationSource.emtl");
	   	 m_emtlFilePathMap.put("generatePackageInterface.emtl", "rsrc:UML4CPP/generator/main/package/generatePackageInterface.emtl");
	   	 m_emtlFilePathMap.put("generatePackageInterfaceSource.emtl", "rsrc:UML4CPP/generator/main/package/generatePackageInterfaceSource.emtl");
	   	 m_emtlFilePathMap.put("generateParameter.emtl", "rsrc:UML4CPP/generator/main/generateParameter.emtl");
	   	 m_emtlFilePathMap.put("generatePrimitivetype.emtl", "rsrc:UML4CPP/generator/main/generatePrimitivetype.emtl");
	   	 m_emtlFilePathMap.put("generateSetGet.emtl", "rsrc:UML4CPP/generator/main/generateSetGet.emtl");
	   	 m_emtlFilePathMap.put("generateSingleton.emtl", "rsrc:UML4CPP/generator/main/generateSingleton.emtl");
	   	 m_emtlFilePathMap.put("generateStereotype.emtl", "rsrc:UML4CPP/generator/main/generateStereotype.emtl");
	   	 m_emtlFilePathMap.put("generateType.emtl", "rsrc:UML4CPP/generator/main/generateType.emtl");
	   	 m_emtlFilePathMap.put("generateUMLPlugin.emtl", "rsrc:UML4CPP/generator/main/plugin/generateUMLPlugin.emtl");
	   	 m_emtlFilePathMap.put("generateUMLPluginImplementationHeader.emtl", "rsrc:UML4CPP/generator/main/plugin/generateUMLPluginImplementationHeader.emtl");
	   	 m_emtlFilePathMap.put("generateUMLPluginImplementationSource.emtl", "rsrc:UML4CPP/generator/main/plugin/generateUMLPluginImplementationSource.emtl");
	   	 m_emtlFilePathMap.put("generateUMLPluginInterfaceHeader.emtl", "rsrc:UML4CPP/generator/main/plugin/generateUMLPluginInterfaceHeader.emtl");
	   	 m_emtlFilePathMap.put("generateUMLPluginInterfaceSource.emtl", "rsrc:UML4CPP/generator/main/plugin/generateUMLPluginInterfaceSource.emtl");
	   	 m_emtlFilePathMap.put("generateValueSpecification.emtl", "rsrc:UML4CPP/generator/main/generateValueSpecification.emtl");
	   	 m_emtlFilePathMap.put("helper.emtl", "rsrc:UML4CPP/generator/main/helper.emtl");
	   	 m_emtlFilePathMap.put("keywords.emtl", "rsrc:UML4CPP/generator/main/helpers/keywords.emtl");
	   	 m_emtlFilePathMap.put("validateModel.emtl", "rsrc:UML4CPP/generator/main/validation/validateModel.emtl");
	}
	
	private void initializeConfigurationEmtls()
	{
		m_emtlFilePathMap.put("generateCMakeFiles.emtl", "rsrc:UML4CPP/generator/main/configuration/generateCMakeFiles.emtl");
		m_emtlFilePathMap.put("generateConfigurationFiles.emtl", "rsrc:UML4CPP/generator/main/configuration/generateConfigurationFiles.emtl");
		m_emtlFilePathMap.put("generateGradleFiles.emtl", "rsrc:UML4CPP/generator/main/configuration/generateGradleFiles.emtl");
		m_emtlFilePathMap.put("generateEclipseFiles.emtl", "rsrc:UML4CPP/generator/main/configuration/generateEclipseFiles.emtl");
	}
	
	private void initializeFactoryEmtls()
	{
		m_emtlFilePathMap.put("generateFactory.emtl", "rsrc:UML4CPP/generator/main/factory/generateFactory.emtl");
		m_emtlFilePathMap.put("generateFactoryImplementationHeader.emtl", "rsrc:UML4CPP/generator/main/factory/generateFactoryImplementationHeader.emtl");
		m_emtlFilePathMap.put("generateFactoryImplementationSource.emtl", "rsrc:UML4CPP/generator/main/factory/generateFactoryImplementationSource.emtl");
		m_emtlFilePathMap.put("generateFactoryInterface.emtl", "rsrc:UML4CPP/generator/main/factory/generateFactoryInterface.emtl");
		m_emtlFilePathMap.put("generateFactoryInterfaceSource.emtl", "rsrc:UML4CPP/generator/main/factory/generateFactoryInterfaceSource.emtl");
	   	 	
	}
}
