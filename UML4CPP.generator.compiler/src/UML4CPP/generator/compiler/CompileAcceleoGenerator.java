package UML4CPP.generator.compiler;

import java.io.File;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.security.CodeSource;
import java.util.StringTokenizer;

import org.eclipse.acceleo.common.IAcceleoConstants;
import org.eclipse.acceleo.model.mtl.MtlPackage;
import org.eclipse.acceleo.model.mtl.resource.EMtlResourceFactoryImpl;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.URIConverter;
import org.eclipse.emf.ecore.xmi.impl.EcoreResourceFactoryImpl;
import org.eclipse.uml2.uml.UMLPackage;
import org.eclipse.uml2.uml.resource.UMLResource;
import org.eclipse.acceleo.parser.compiler.AcceleoCompilerHelper;

public class CompileAcceleoGenerator 
{

	/**
	 * The packages to register.
	 */
	private String packagesToRegister;

	/**
	 * The compiler helper.
	 */
	private final AcceleoCompilerHelper helper = new AcceleoCompilerHelper();

	/**
	 * Sets the source folder to compile.
	 * 
	 * @param theSourceFolder
	 *            are the source folder to compile
	 */
	public void setSourceFolder(String theSourceFolder) {
		helper.setSourceFolder(theSourceFolder);
	}

	/**
	 * Sets the output folder.
	 * 
	 * @param theOutputFolder
	 *            The output folder.
	 */
	public void setOutputFolder(String theOutputFolder) {
		helper.setOutputFolder(theOutputFolder);
	}

	/**
	 * Sets the dependencies to load before to compile. They are separated by ';'.
	 * 
	 * @param allDependencies
	 *            are the dependencies identifiers
	 */
	public void setDependencies(String allDependencies) {
		helper.setDependencies(allDependencies);
	}

	/**
	 * Sets the binary resource attribute.
	 * 
	 * @param binaryResource
	 *            Indicates if we should use a binary resource.
	 */
	public void setBinaryResource(boolean binaryResource) {
		helper.setBinaryResource(binaryResource);
	}

	/**
	 * Sets the packages to register.
	 * 
	 * @param packages
	 *            the semicolon separated packages.
	 */
	public void setPackagesToRegister(String packages) {
		this.packagesToRegister = packages;
	}
	
	
	public void execute() throws Exception 
	{
		registerResourceFactories();
		registerPackages();
		registerLibraries();
		
		executeCompiler();
	}
	 
	private void registerResourceFactories() 
	{
		Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("ecore", new EcoreResourceFactoryImpl());
		Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put(IAcceleoConstants.EMTL_FILE_EXTENSION, new EMtlResourceFactoryImpl());
		Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put(UMLResource.FILE_EXTENSION, UMLResource.Factory.INSTANCE);
	}
	 
	private void registerPackages() 
	{
		EPackage.Registry.INSTANCE.put(UMLPackage.eNS_URI, UMLPackage.eINSTANCE);
		// Uncomment if you need to use UML models saved with on old version of MDT/UML (you might need to change the URI's version number)
		// EPackage.Registry.INSTANCE.put("http://www.eclipse.org/uml2/2.1.0/UML", UMLPackage.eINSTANCE);
	}
	 
	private void registerLibraries() 
	{
		CodeSource acceleoModel = MtlPackage.class.getProtectionDomain().getCodeSource();
		if (acceleoModel != null) 
		{
			String libraryLocation = acceleoModel.getLocation().toString();
			if (libraryLocation.endsWith(".jar")) 
			{
				libraryLocation = "jar:" + libraryLocation + '!';
			}
			URIConverter.URI_MAP.put(URI.createURI("http://www.eclipse.org/acceleo/mtl/3.0/mtlstdlib.ecore"), URI.createURI(libraryLocation + "/model/mtlstdlib.ecore"));
			URIConverter.URI_MAP.put(URI.createURI("http://www.eclipse.org/acceleo/mtl/3.0/mtlnonstdlib.ecore"), URI.createURI(libraryLocation + "/model/mtlnonstdlib.ecore"));
		}
		else 
		{
			System.err.println("Coudln't retrieve location of plugin 'org.eclipse.acceleo.model'.");
		}
	}
	
	private void executeCompiler() throws Exception
	{
		try 
		{
			if (packagesToRegister != null) 
			{
				StringTokenizer tokenizer = new StringTokenizer(packagesToRegister, ";"); //$NON-NLS-1$
				while (tokenizer.hasMoreElements()) 
				{
					String nextPackage = tokenizer.nextToken();
					Class<?> packageClass = Class.forName(nextPackage);
					Field field = packageClass.getField("eINSTANCE"); //$NON-NLS-1$
					if (field != null) 
					{
						Object packageInstance = field.get(packageClass);
						Method method = packageInstance.getClass().getMethod("getNsURI"); //$NON-NLS-1$
						Object packageNsUri = method.invoke(packageInstance);
						if (packageInstance instanceof EPackage && packageNsUri instanceof String) 
						{
							EPackage ePackage = (EPackage)packageInstance;
							String uri = (String)packageNsUri;
							EPackage.Registry.INSTANCE.put(uri, ePackage);
						}
					}
				}
			}
			helper.execute();
		} 
		catch (Throwable e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
			throw new Exception(e.getMessage());
		}
	}
	
	 public static void main(String[] args) {
        try 
        {
            if (args.length != 2) 
            {
                System.out.println("Arguments not valid : {source folder, target folder}.");
            } 
            else 
            {
            	String srcFolder = args[0];
            	File file = new File(srcFolder);
            	if (!file.exists())
            	{
            		System.err.println("Source folder does not exists! (" + file.getAbsolutePath() + ")");
            		return;
            	}
            	String targetFolder = args[1];
            	file = new File(targetFolder);
            	if (file.isFile())
            	{
            		System.err.println("Target path is a file!");
            		return;
            	}
            	
		        CompileAcceleoGenerator compiler = new CompileAcceleoGenerator();
            	if (file.isDirectory())
            	{
            		compiler.deleteExistingEmtlFiles(file);
            	}
		        compiler.setSourceFolder(srcFolder);
		        compiler.setOutputFolder(targetFolder);
		        compiler.setBinaryResource(false);
		        compiler.execute();
            }
        }
        catch (Exception e)
        {
        	e.printStackTrace();
        }
	}
	 
	private void deleteExistingEmtlFiles(File parentFile)
	{
		File[] fileList = parentFile.listFiles();
		for (File file : fileList) {
			if (file.isDirectory())
			{
				deleteExistingEmtlFiles(file);
			}
			else if (file.getName().endsWith(".emtl"))
			{
				file.delete();
			}
		}
	}
}