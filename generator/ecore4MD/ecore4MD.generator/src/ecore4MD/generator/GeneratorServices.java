package ecore4MD.generator;

import java.util.Collection;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.NullProgressMonitor;
import org.eclipse.core.runtime.Path;
import org.eclipse.emf.common.util.BasicMonitor;
import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.emf.ecore.resource.impl.ResourceSetImpl;
import org.eclipse.emf.transaction.TransactionalEditingDomain;
import org.eclipse.osgi.internal.serviceregistry.ServiceRegistry;
import org.eclipse.sirius.business.api.dialect.DialectManager;
import org.eclipse.sirius.business.api.query.DViewQuery;
import org.eclipse.sirius.business.api.session.Session;
       
import org.eclipse.sirius.business.api.session.SessionManager;
import org.eclipse.sirius.business.api.session.factory.SessionFactory;
import org.eclipse.sirius.business.internal.resource.AirDResourceFactory;
import org.eclipse.sirius.business.internal.session.LocalSessionEditingDomainFactory;
import org.eclipse.sirius.common.tools.api.editing.EditingDomainFactoryService;
import org.eclipse.sirius.common.tools.api.editing.IEditingDomainFactory;
import org.eclipse.sirius.common.tools.api.resource.ImageFileFormat;
import org.eclipse.sirius.common.tools.api.resource.ResourceSetFactory;
import org.eclipse.sirius.tools.api.command.ui.UICallBack;
import org.eclipse.sirius.viewpoint.DAnalysis;
import org.eclipse.sirius.viewpoint.DRepresentation;
import org.eclipse.sirius.viewpoint.DView;
import org.eclipse.sirius.viewpoint.provider.SiriusEditPlugin;
import org.eclipse.sirius.ui.business.api.dialect.DialectUIManager;
import org.eclipse.sirius.ui.business.api.dialect.ExportFormat;
import org.eclipse.sirius.ui.business.api.dialect.ExportFormat.ExportDocumentFormat;
import org.eclipse.sirius.ui.business.api.session.IEditingSession;
import org.eclipse.emf.workspace.WorkspaceEditingDomainFactory;

public class GeneratorServices 
{
	public String myString(EPackage aPackage) 
	{
		try {
			String PROJECT_NAME="Test";
			String IMAGE_FILE_NAME="Test";	
/*
			System.out.println("2" );
			
//	        URI airdURI = URI.createFileURI("platform:/resource/libraryModel_ecore_src_gen/model/representations.aird");
			URI airdURI = URI.createFileURI("C:\\src\\MDE4CPP\\MDE4CPP_develop\\MDE4CPP\\src\\examples\\ecoreExamples\\ecoreModelExample\\model\\representations.aird");
			
			
			
			org.eclipse.sirius.business.internal.resource.AirDResourceFactory f= new org.eclipse.sirius.business.internal.resource.AirDResourceFactory();   // (it brings the automatic migration of Sirius resources).
			
			UICallBack call=SiriusEditPlugin.getPlugin().getUiCallback(); 
			
			org.eclipse.sirius.business.api.session.factory.SessionFactory.INSTANCE.createSession(airdURI, new NullProgressMonitor());

//			org.eclipse.sirius.business.api.session.factory.SessionFactory.INSTANCE.openSession(airdURI, new NullProgressMonitor(), new org.eclipse.sirius.tools.api.command.ui.NoUICallback() );
			
			//.Session asession= org.eclipse.sirius.business.api.session...INSTANCE.getSession(airdURI, new NullProgressMonitor());
			//org.eclipse.sirius.business.api.session.INSTANCE.openSession(airdURI, new NullProgressMonitor(), new org.eclipse.sirius.tools.api.command.ui.NoUICallback() ); 
			//(with SiriusEditPlugin.getPlugin().getUiCallback() or a new 
			//org.eclipse.sirius.tools.api.command.ui.NoUICallback regarding your context) instead of the use of the session factory.
			//new org.eclipse.sirius.tools.api.command.ui.NoUICallback 
			
			//Resource.Factory.Registry.INSTANCE.getResourceFactoryRegistry().getExtensionToFactoryMap().put("aird",  new XMIResourceFactoryImpl());
			
			
			DialectManager myManager=org.eclipse.sirius.business.api.dialect.DialectManager.INSTANCE;
	
			
			URI diagramURI = URI.createURI("C:\\src\\MDE4CPP\\MDE4CPP_develop\\MDE4CPP\\src\\examples\\ecoreExamples\\ecoreModelExample\\model\\representations.aird");
			ResourceSet rs = new ResourceSetImpl(); 
			Resource rsc = rs.createResource(diagramURI);
//			try {
//				load(null);
			//} catch
			//(IOException e1) {
				// TODO Auto-generated catch block
//				e1.printStackTrace();
	//		}

			DAnalysis root = (DAnalysis) rsc.getContents().get(0);
			DView dView = root.getOwnedViews().get(0);
//			DRepresentation rep = dView.getOwnedRepresentationDescriptors().get(0).getDescription(); 
//			DialectUIManager.INSTANCE.openEditor(SessionManager.INSTANCE.getSession(diagramURI, new NullProgressMonitor()), rep, new NullProgressMonitor());
			
			
	/*		
			org.eclipse.sirius.ui.business.api.session.SessionEditorInput sEditor = 
					new SessionEditorInput(diagramURI, "New Diagram", null);
					IEditorPart openEditor = IDE.openEditor(page, sEditor,"org.eclipse.sirius.diagram.part.SiriusDiagramEditorID", true);
			
			org.eclipse.sirius.ui.business.api.session.SessionEditorInput sEditor =
					new SessionEditorInput(diagramURI, "New Diagram", null);
					IEditorPart openEditor = IDE.openEditor(page, sEditor,"org.eclipse.sirius.diagram.part.SiriusDiagramEditorID", true);
					
			 Collection<IEditingSession>  sessionss=org.eclipse.sirius.ui.business.api.session.SessionUIManager.INSTANCE;
			 System.out.println(sessionss.size());
		/	
			SessionFactory sessionFactory = SessionFactory.INSTANCE;
			System.out.println("3" );
			
			
			Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("aird", new AirDResourceFactory());
			//log.info("Exporting image of " + getAirdFile() + " file to " + getImageFileName());
			IProgressMonitor progressMonitor = new NullProgressMonitor();
						// Get session from an absolute path (not in a workspace)
						//URI sessionResourceURI = URI.createFileURI(getAirdFile());
						Session session = SessionFactory.INSTANCE.createSession(airdURI, progressMonitor);
						//Session session = SessionManager.INSTANCE.openSession(sessionResourceURI, progressMonitor, noUICallback, false);
						session.open(progressMonitor);
						
						
						// Get the expected representation (here the first of the first DView)
						DViewQuery query = new DViewQuery(session.getOwnedViews().iterator().next());
						DRepresentation representation = query.getLoadedRepresentations().get(0);
									
			
/*			
			Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("aird", new AirDResourceFactory());
			ResourceSet set = ResourceSetFactory.createFactory().createResourceSet(airdURI);
			IEditingDomainFactory factory= EditingDomainFactoryService.INSTANCE.getEditingDomainFactory();

			TransactionalEditingDomain domain=factory.createEditingDomain(set);
			//LocalSessionEditingDomainFactory transactionalEditingDomain = EditingDomainFactoryService.INSTANCE.getEditingDomainFactory();
			System.out.println("b" );			
			SessionManager manager=SessionManager.INSTANCE;
			System.out.println("4" );
			Session session=sessionFactory.createSession(airdURI, new NullProgressMonitor());
			System.out.println("5" );
/


			 session = SessionManager.INSTANCE.getSession(airdURI, new NullProgressMonitor());
	        IFile airdFile = ResourcesPlugin.getWorkspace().getRoot().getFile(new Path("C:\\src\\MDE4CPP\\MDE4CPP_develop\\MDE4CPP\\src\\examples\\ecoreExamples\\ecoreModelExample\\model\\representations.aird"));
	        //assertTrue("The file " + "/" + TEMPORARY_PROJECT_NAME + "/" + SESSION_MODEL_FILENAME + " should exist in the workspace.", airdFile.exists());
	        // Load the resource in a new TransactionalEditingDomain

	        /*newSession = SessionManager.INSTANCE.getSession(sessionResourceURI, new NullProgressMonitor());
	        if (!newSession.isOpen()) {
	            newSession.open(new NullProgressMonitor());
	        }
			
			DialectUIManager.INSTANCE.export(null, null)
				/	
			
			
			//Session session=SessionFactory.INSTANCE.createSession(airdURI, new NullProgressMonitor());
			System.out.println("2" );       
			
			 sessionFactory = SessionFactory.INSTANCE; 
			/* 
			 Session session = sessionFactory..acquireSession(); 
			 List results = (List) session.executeQuery("query-name", MyClass.class, args); 
			 session.release(); return results; 
			 
			 
			
			  Session session = sessionFactory.getCurrentSession();
			  
			Session session=SessionFactory.INSTANCE.createDefaultSession(airdURI);
			/
//			org.eclipse.sirius.business.api.session.SessionManager.INSTANCE.openSession(airdURI, new NullProgressMonitor(), SiriusEditPlugin.getPlugin().getUiCallback());
			
//			Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("aird", new AirDResourceFactory());
			
//			  set = ResourceSetFactory.createFactory().createResourceSet(airdURI);
			 
//			  factory= EditingDomainFactoryService.INSTANCE.getEditingDomainFactory();

//				NullProgressMonitor progressMonitor = new NullProgressMonitor();
		        Session session2 = SessionManager.INSTANCE.openSession(airdURI, progressMonitor, null, false);
				session2.open(progressMonitor);
				
		        
				Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("aird", new AirDResourceFactory());
				System.out.println("Exporting image of " + airdURI.toFileString() + " ..." );
			 
			 
			 IEditingDomainFactory ffactory= EditingDomainFactoryService.INSTANCE.getEditingDomainFactory();
//			 LocalSessionEditingDomainFactory transactionalEditingDomain = EditingDomainFactoryService.INSTANCE.getEditingDomainFactory();
//					 get.getEditingDomainFactory().createEditingDomain(set);

				System.out.println("2" );    		 
	       // org.eclipse.sirius.business.api.session.INSTANCE.openSession(URI, IProgressMonitor, new org.eclipse.sirius.tools.api.command.ui.NoUICallback); 
	        
	       // and then open the session or org.eclipse.sirius.business.api.session.INSTANCE.openSession(URI, IProgressMonitor, UICallBack) (with SiriusEditPlugin.getPlugin().getUiCallback() or a new org.eclipse.sirius.tools.api.command.ui.NoUICallback regarding your context) instead of the use of the session factory.
	        
	     // Since version 4.x, service registry is being used
//	        ServiceRegistry serviceRegistry = new StandardServiceRegistryBuilder().

	        // Create session factory instance
	        //SessionFactory factory = configuration.buildSessionFactory(serviceRegistry);

	        // Get current session
	        //Session session = factory.getCurrentSession();
	        
	        Session sessionA = SessionFactory.INSTANCE.createSession(airdURI, new NullProgressMonitor());
	        System.out.println("3" );

	        sessionA.open(new NullProgressMonitor());

	        System.out.println("3" );
			
			Collection<DRepresentation> allRepresentations = DialectManager.INSTANCE.getAllRepresentations(sessionA);
			//		DRepresentation representation = (DRepresentation)
			//		allRepresentations.toArray()[0];
			
	/*        
	        Collection<DRepresentation> allRepresentations =
	        		DialectManager.INSTANCE.getAllRepresentations(session);
	        		DRepresentation representation = (DRepresentation)
	        		allRepresentations.toArray()[0];
/
	        		
			 progressMonitor = new NullProgressMonitor();
	         session2 = SessionManager.INSTANCE.openSession(airdURI, progressMonitor, null, false);
			session2.open(progressMonitor);
			
	        
			Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("aird", new AirDResourceFactory());
			System.out.println("Exporting image of " + airdURI.toFileString() + " ..." );

			System.out.println("2" );

			// Get session from an absolute path (not in a workspace)
						URI sessionResourceURI =airdURI;
						 session = SessionFactory.INSTANCE.createSession(sessionResourceURI, progressMonitor);
System.out.println("3");

						 //Session session = SessionManager.INSTANCE.openSession(sessionResourceURI, progressMonitor, noUICallback, false);
						session.open(progressMonitor);
			
	        // Get session from an absolute path (not in a workspace)
//	        URI airdURI = URI.createFileURI("D:/folder/representations.aird");
	        
	        IWorkspace workspace = ResourcesPlugin.getWorkspace();
	        System.out.println(workspace.getRoot().toString());
	        		
	        //System.out.println(ResourcesPlugin.getWorkspace().getRoot().getName());
	        //System.out.println(ResourcesPlugin.getWorkspace().getRoot().toString());

	        //IPath absoluteImagePath = ResourcesPlugin.getWorkspace().getRoot().getProject(PROJECT_NAME).getLocation().append(IMAGE_FILE_NAME);
	        //System.out.println(absoluteImagePath.toString());
	
	        

	        
	        // Get the expected representation (here the first of the first DView)
	        /*
	        DViewQuery query = new DViewQuery(session.getOwnedViews().iterator().next());
	        DRepresentation representation = query.getLoadedRepresentations().get(0);
	        // Export it as SVG image
	        
	        
	        Collection<DRepresentation> allRepresentations = DialectManager.INSTANCE.getAllRepresentations(session);
	        DRepresentation representations = (DRepresentation) allRepresentations.toArray()[0];
	
	        System.out.println(representations.getName());
	        */
			// Export the image
/*	        DialectUIManager.INSTANCE.export(representation, session, absoluteImagePath, new ExportFormat(ExportDocumentFormat.NONE,  ImageFileFormat.PNG), new NullProgressMonitor());
	        
	       // obeo Kommentar: DialectManager.INSTANCE.getRepresentations(EObject semantic, Session	session);
	        
	        ExportFormat exportFormat = new ExportFormat(ExportDocumentFormat.NONE, ImageFileFormat.SVG);
	        DialectUIManager.INSTANCE.export(representation, session, new Path("D:/folder/image.svg"), exportFormat, new NullProgressMonitor());
	        
	//        Resource.Factory.Registry.INSTANCE.getResourceFactoryRegistry().getExtensionToFactoryMap().put("aird",  new XMIResourceFactoryImpl());
		
	        
	        DialectUIManager.INSTANCE.export(representation, session,
	        		absoluteImagePath, new ExportFormat(ExportDocumentFormat.NONE,
	        		ImageFileFormat.PNG), new NullProgressMonitor());
	        		*/
	        
	        //__________
	
	/*
	
        org.eclipse.sirius.business.api.session.SessionManager.INSTANCE.openSession(airdURI, new NullProgressMonitor(), SiriusEditPlugin.getPlugin().getUiCallback());
	
	
	
        Session session = SessionFactory.INSTANCE.createSession(airdURI, new NullProgressMonitor());
        session.open(new NullProgressMonitor()); 	
        
        org.eclipse.sirius.business.api.session.INSTANCE.getSession(uri, progressmonitor); 
        org.eclipse.sirius.business.api.session.INSTANCE.openSession(URI, IProgressMonitor, UICallBack); 
        SiriusEditPlugin.getPlugin().getUiCallback(); 
         new org.eclipse.sirius.tools.api.command.ui.NoUICallback();
*/
		} 
		catch (Exception e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		return "GeneratorServices []"+aPackage.getName();

	}

	
	
	
	
	
}
