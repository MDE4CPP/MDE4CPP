/*******************************************************************************
 * Copyright (c) 2008, 2012 Obeo.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Obeo - initial API and implementation
 *******************************************************************************/
package fUML4CPP.generator.main;
 
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;
import java.util.Map;

import org.eclipse.acceleo.engine.event.IAcceleoTextGenerationListener;
import org.eclipse.acceleo.engine.generation.strategy.IAcceleoGenerationStrategy;
import org.eclipse.acceleo.engine.service.AbstractAcceleoGenerator;
import org.eclipse.emf.common.EMFPlugin;
import org.eclipse.emf.common.util.BasicMonitor;
import org.eclipse.emf.common.util.Monitor;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EcorePackage;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.uml2.types.TypesPackage;
import org.eclipse.uml2.uml.UMLPackage;
import org.eclipse.uml2.uml.resource.UMLResource;

/**
 * Entry point of the 'Generate' generation module.
 *
 * @generated NOT
 */
public class GenerateFUML extends AbstractAcceleoGenerator {
    /**
     * The name of the module.
     *
     * @generated
     */
    public static final String MODULE_FILE_NAME = "/fUML4CPP/generator/main/generateFUML";

    /**
     * The name of the templates that are to be generated.
     *
     * @generated
     */
    public static final String[] TEMPLATE_NAMES = { "generateFUML" };

    /**
     * The list of properties files from the launch parameters (Launch configuration).
     *
     * @generated
     */
    private List<String> propertiesFiles = new ArrayList<String>();

    /**
     * path to org.eclipse.uml2.uml.resources_<version>.jar
     */
    private String umlJarPath = null;
    
    /**
     * Allows the public constructor to be used. Note that a generator created
     * this way cannot be used to launch generations before one of
     * {@link #initialize(EObject, File, List)} or
     * {@link #initialize(URI, File, List)} is called.
     * <p>
     * The main reason for this constructor is to allow clients of this
     * generation to call it from another Java file, as it allows for the
     * retrieval of {@link #getProperties()} and
     * {@link #getGenerationListeners()}.
     * </p>
     *
     * @generated
     */
    public GenerateFUML() {
        // Empty implementation
    }

    /**
     * This allows clients to instantiates a generator with all required information.
     *
     * @param modelURI
     *            URI where the model on which this generator will be used is located.
     * @param targetFolder
     *            This will be used as the output folder for this generation : it will be the base path
     *            against which all file block URLs will be resolved.
     * @param arguments
     *            If the template which will be called requires more than one argument taken from the model,
     *            pass them here.
     * @throws IOException
     *             This can be thrown in three scenarios : the module cannot be found, it cannot be loaded, or
     *             the model cannot be loaded.
     * @generated NOT
     */
    public GenerateFUML(URI modelURI, File targetFolder,
            List<? extends Object> arguments) throws IOException {
    	if (arguments.size() > 0)
    	{
    		umlJarPath = arguments.get(0).toString();
    		arguments.remove(0);
    	}
    	
        initialize(modelURI, targetFolder, arguments);
    }

    /**
     * This allows clients to instantiates a generator with all required information.
     *
     * @param model
     *            We'll iterate over the content of this element to find Objects matching the first parameter
     *            of the template we need to call.
     * @param targetFolder
     *            This will be used as the output folder for this generation : it will be the base path
     *            against which all file block URLs will be resolved.
     * @param arguments
     *            If the template which will be called requires more than one argument taken from the model,
     *            pass them here.
     * @throws IOException
     *             This can be thrown in two scenarios : the module cannot be found, or it cannot be loaded.
     * @generated
     */
    public GenerateFUML(EObject model, File targetFolder,
            List<? extends Object> arguments) throws IOException {
        initialize(model, targetFolder, arguments);
    }

    /**
     * This can be used to launch the generation from a standalone application.
     *
     * @param args
     *            Arguments of the generation.
     * @generated NOT
     */
    public static void main(String[] args) {
        try {
            if (args.length < 2) 
            {
                System.err.println("Arguments not valid : {model path, target folder}.");
            } 
            else 
            {
                URI modelURI = URI.createFileURI(args[0]);
                File folder = new File(args[1]);

                System.out.println("Generate c++ code for: " + modelURI.devicePath());
                System.out.println("          into folder: " + folder.getAbsolutePath());
                
                /*
                 * If you want to change the content of this method, do NOT forget to change the "@generated"
                 * tag in the Javadoc of this method to "@generated NOT". Without this new tag, any compilation
                 * of the Acceleo module with the main template that has caused the creation of this class will
                 * revert your modifications.
                 */

                /*
                 * Add in this list all the arguments used by the starting point of the generation
                 * If your main template is called on an element of your model and a String, you can
                 * add in "arguments" this "String" attribute.
                 */
                int index = 2;
                List<String> arguments = new ArrayList<String>();
                if (args.length > 2)
				{
                	String jarPath = args[2];
                	if (jarPath.startsWith("-L"))
                	{
                		index = 3;
                		arguments.add(jarPath.replace("-L", ""));	
                	}
				}

                GenerateFUML generator = new GenerateFUML(modelURI, folder, arguments);

                /*
                 * Add the properties from the launch arguments.
                 * If you want to programmatically add new properties, add them in "propertiesFiles"
                 * You can add the absolute path of a properties files, or even a project relative path.
                 * If you want to add another "protocol" for your properties files, please override
                 * "getPropertiesLoaderService(AcceleoService)" in order to return a new property loader.
                 * The behavior of the properties loader service is explained in the Acceleo documentation
                 * (Help -> Help Contents).
                 */

                for (int i = index; i < args.length; i++) {
                    generator.addPropertiesFile(args[i]);
                }

                generator.doGenerate(new BasicMonitor());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Launches the generation described by this instance.
     *
     * @param monitor
     *            This will be used to display progress information to the user.
     * @throws IOException
     *             This will be thrown if any of the output files cannot be saved to disk.
     * @generated NOT
     */
    @Override
    public void doGenerate(Monitor monitor) throws IOException {
        /*
         * TODO if you wish to change the generation as a whole, override this. The default behavior should
         * be sufficient in most cases. If you want to change the content of this method, do NOT forget to
         * change the "@generated" tag in the Javadoc of this method to "@generated NOT". Without this new tag,
         * any compilation of the Acceleo module with the main template that has caused the creation of this
         * class will revert your modifications. If you encounter a problem with an unresolved proxy during the
         * generation, you can remove the comments in the following instructions to check for problems. Please
         * note that those instructions may have a significant impact on the performances.
         */

        org.eclipse.emf.ecore.util.EcoreUtil.resolveAll(model);

        /*
         * If you want to check for potential errors in your models before the launch of the generation, you
         * use the code below.
         */

        if (model != null && model.eResource() != null) {
            List<org.eclipse.emf.ecore.resource.Resource.Diagnostic> errors = model.eResource().getErrors();
            for (org.eclipse.emf.ecore.resource.Resource.Diagnostic diagnostic : errors) {
                System.err.println(diagnostic.toString());
            }
        }

        super.doGenerate(monitor);
    }

    /**
     * If this generator needs to listen to text generation events, listeners can be returned from here.
     *
     * @return List of listeners that are to be notified when text is generated through this launch.
     * @generated
     */
    @Override
    public List<IAcceleoTextGenerationListener> getGenerationListeners() {
        List<IAcceleoTextGenerationListener> listeners = super.getGenerationListeners();
        /*
         * TODO if you need to listen to generation event, add listeners to the list here. If you want to change
         * the content of this method, do NOT forget to change the "@generated" tag in the Javadoc of this method
         * to "@generated NOT". Without this new tag, any compilation of the Acceleo module with the main template
         * that has caused the creation of this class will revert your modifications.
         */
        return listeners;
    }

    /**
     * If you need to change the way files are generated, this is your entry point.
     * <p>
     * The default is {@link org.eclipse.acceleo.engine.generation.strategy.DefaultStrategy}; it generates
     * files on the fly. If you only need to preview the results, return a new
     * {@link org.eclipse.acceleo.engine.generation.strategy.PreviewStrategy}. Both of these aren't aware of
     * the running Eclipse and can be used standalone.
     * </p>
     * <p>
     * If you need the file generation to be aware of the workspace (A typical example is when you wanna
     * override files that are under clear case or any other VCS that could forbid the overriding), then
     * return a new {@link org.eclipse.acceleo.engine.generation.strategy.WorkspaceAwareStrategy}.
     * <b>Note</b>, however, that this <b>cannot</b> be used standalone.
     * </p>
     * <p>
     * All three of these default strategies support merging through JMerge.
     * </p>
     *
     * @return The generation strategy that is to be used for generations launched through this launcher.
     * @generated
     */
    @Override
    public IAcceleoGenerationStrategy getGenerationStrategy() {
        return super.getGenerationStrategy();
    }

    /**
     * This will be called in order to find and load the module that will be launched through this launcher.
     * We expect this name not to contain file extension, and the module to be located beside the launcher.
     *
     * @return The name of the module that is to be launched.
     * @generated
     */
    @Override
    public String getModuleName() {
        return MODULE_FILE_NAME;
    }

    /**
     * If the module(s) called by this launcher require properties files, return their qualified path from
     * here.Take note that the first added properties files will take precedence over subsequent ones if they
     * contain conflicting keys.
     *
     * @return The list of properties file we need to add to the generation context.
     * @see java.util.ResourceBundle#getBundle(String)
     * @generated
     */
    @Override
    public List<String> getProperties() {
        /*
         * If you want to change the content of this method, do NOT forget to change the "@generated"
         * tag in the Javadoc of this method to "@generated NOT". Without this new tag, any compilation
         * of the Acceleo module with the main template that has caused the creation of this class will
         * revert your modifications.
         */

        /*
         * TODO if your generation module requires access to properties files, add their qualified path to the list here.
         *
         * Properties files can be located in an Eclipse plug-in or in the file system (all Acceleo projects are Eclipse
         * plug-in). In order to use properties files located in an Eclipse plugin, you need to add the path of the properties
         * files to the "propertiesFiles" list:
         *
         * final String prefix = "platform:/plugin/";
         * final String pluginName = "org.eclipse.acceleo.module.sample";
         * final String packagePath = "/org/eclipse/acceleo/module/sample/properties/";
         * final String fileName = "default.properties";
         * propertiesFiles.add(prefix + pluginName + packagePath + fileName);
         *
         * With this mechanism, you can load properties files from your plugin or from another plugin.
         *
         * You may want to load properties files from the file system, for that you need to add the absolute path of the file:
         *
         * propertiesFiles.add("C:\Users\MyName\MyFile.properties");
         *
         * If you want to let your users add properties files located in the same folder as the model:
         *
         * if (EMFPlugin.IS_ECLIPSE_RUNNING && model != null && model.eResource() != null) {
         *     propertiesFiles.addAll(AcceleoEngineUtils.getPropertiesFilesNearModel(model.eResource()));
         * }
         *
         * To learn more about Properties Files, have a look at the Acceleo documentation (Help -> Help Contents).
         */
        return propertiesFiles;
    }

    /**
     * Adds a properties file in the list of properties files.
     *
     * @param propertiesFile
     *            The properties file to add.
     * @generated
     * @since 3.1
     */
    @Override
    public void addPropertiesFile(String propertiesFile) {
        this.propertiesFiles.add(propertiesFile);
    }

    /**
     * This will be used to get the list of templates that are to be launched by this launcher.
     *
     * @return The list of templates to call on the module {@link #getModuleName()}.
     * @generated
     */
    @Override
    public String[] getTemplateNames() {
        return TEMPLATE_NAMES;
    }

    /**
     * This can be used to update the resource set's package registry with all needed EPackages.
     *
     * @param resourceSet
     *            The resource set which registry has to be updated.
     * @generated NOT
     */
    @Override
    public void registerPackages(ResourceSet resourceSet) {
        super.registerPackages(resourceSet);

        if (!EMFPlugin.IS_ECLIPSE_RUNNING)
        {
        	String path = null;
        	if (umlJarPath == null)
        	{
				try {
					// getResource() requires full qualified name in java > 8 (?)
					ClassLoader t_classloader = Thread.currentThread().getContextClassLoader();
					Enumeration<URL> t_ressources = t_classloader.getResources("plugin.xml");
				
					for (Enumeration<URL> e = t_ressources; e.hasMoreElements();) {
					    URL url = e.nextElement();
						//System.out.println("URL: " + url.toString());
						
						if (url.getFile().startsWith("rsrc:org.eclipse.uml2.uml.resources_"))
	    				{
	    					path = url.toString().replace("plugin.xml", "");
	    					//System.out.println();
	    	    			//System.out.println("INFO: Using internal org.eclipse.uml2.uml.resources.*.jar (" + path.replace("!/", "") + ")");
	    				}
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
			
    			if (path == null)
    			{
    				System.err.println("ERROR: Could not find org.eclipse.uml2.uml.resources.*.jar in JARs of generator!");
    				System.exit(1);
    			}
        	}
        	else
        	{
	        	File f = new File(umlJarPath);
		        if(!f.exists())
		        {
		        	System.err.println("Please check the path to org.eclipse.uml2.uml.resources.*.jar or remove argument to use included jar files!");
		        	System.exit(1);
		        }
		        else
		        {
		            //System.out.println(" *uml.resources_*.jar: " + path);
		        	path = "jar:file:" + umlJarPath + "!/";
		        }
        	}

	        URI uri = URI.createURI(path);
        	
	        /*
	         * If you want to change the content of this method, do NOT forget to change the "@generated"
	         * tag in the Javadoc of this method to "@generated NOT". Without this new tag, any compilation
	         * of the Acceleo module with the main template that has caused the creation of this class will
	         * revert your modifications.
	         */
	        Map<URI,URI> uriMap = resourceSet.getURIConverter().getURIMap();
	        uriMap.put(URI.createURI(UMLResource.LIBRARIES_PATHMAP), uri.appendSegment("libraries").appendSegment(""));
	        uriMap.put(URI.createURI(UMLResource.METAMODELS_PATHMAP), uri.appendSegment("metamodels").appendSegment(""));
	        uriMap.put(URI.createURI(UMLResource.PROFILES_PATHMAP), uri.appendSegment("profiles").appendSegment(""));
	
	        /*System.out.println();
	        System.out.println("registered libraries/metamodels/profiles:");
	        for (URI nsuri : uriMap.keySet()) {
				System.out.println("    " + nsuri.toString());
			}*/
	
	        /*
	         * If you need additional package registrations, you can register them here. The following line
	         * (in comment) is an example of the package registration for UML.
	         *
	         * You can use the method  "isInWorkspace(Class c)" to check if the package that you are about to
	         * register is in the workspace.
	         *
	         * To register a package properly, please follow the following conventions:
	         *
	         * If the package is located in another plug-in, already installed in Eclipse. The following content should
	         * have been generated at the beginning of this method. Do not register the package using this mechanism if
	         * the metamodel is located in the workspace.
	         *
	         * if (!isInWorkspace(UMLPackage.class)) {
	         *     // The normal package registration if your metamodel is in a plugin.
	         *     resourceSet.getPackageRegistry().put(UMLPackage.eNS_URI, UMLPackage.eINSTANCE);
	         * }
	         *
	         * If the package is located in another project in your workspace, the plugin containing the package has not
	         * been register by EMF and Acceleo should register it automatically. If you want to use the generator in
	         * stand alone, the regular registration (seen a couple lines before) is needed.
	         *
	         * To learn more about Package Registration, have a look at the Acceleo documentation (Help -> Help Contents).
	         */
	
	        if (!isInWorkspace(UMLPackage.class)) {
	             // The normal package registration if your metamodel is in a plugin.
	             resourceSet.getPackageRegistry().put(UMLPackage.eNS_URI, UMLPackage.eINSTANCE);
	          }
	
	        resourceSet.getPackageRegistry().put("http://www.eclipse.org/emf/2002/Ecore",EcorePackage.eINSTANCE);
	
	        resourceSet.getPackageRegistry().put("http://www.eclipse.org/uml2/5.0.0/Types", TypesPackage.eINSTANCE);
        }
         
        /*System.out.println();
        System.out.println("registered packages:");
        for (String nsuri : resourceSet.getPackageRegistry().keySet()) {
			System.out.println("   " + nsuri);
		}*/
    }

    /**
     * This can be used to update the resource set's resource factory registry with all needed factories.
     *
     * @param resourceSet
     *            The resource set which registry has to be updated.
     * @generated NOT
     */
    @Override
    public void registerResourceFactories(ResourceSet resourceSet) {
        super.registerResourceFactories(resourceSet);
        /*
         * If you want to change the content of this method, do NOT forget to change the "@generated"
         * tag in the Javadoc of this method to "@generated NOT". Without this new tag, any compilation
         * of the Acceleo module with the main template that has caused the creation of this class will
         * revert your modifications.
         */

        /*
         * TODO If you need additional resource factories registrations, you can register them here. the following line
         * (in comment) is an example of the resource factory registration for UML.
         *
         * If you want to use the generator in stand alone, the resource factory registration will be required.
         *
         * To learn more about the registration of Resource Factories, have a look at the Acceleo documentation (Help -> Help Contents).
         */

         resourceSet.getResourceFactoryRegistry().getExtensionToFactoryMap().put(UMLResource.FILE_EXTENSION, UMLResource.Factory.INSTANCE);
         
         if (!EMFPlugin.IS_ECLIPSE_RUNNING)
         {        	 
	 		 resourceSet.getResourceFactoryRegistry().getExtensionToFactoryMap( ).put("emtl", new FUML4CPPEMtlResourceFactory());
         }
    }
}
