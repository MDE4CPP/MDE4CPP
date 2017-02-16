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
package ecore4CPP.generator.ui.common;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.emf.common.util.BasicMonitor;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.emf.common.util.URI;

/**
 * Main entry point of the 'ecore4CPP Generator' generation module.
 */
public class GenerateAll {

	/**
	 * The model URI.
	 */
	private URI modelURI;

	/**
	 * The output folder.
	 */
	private File targetFolder;

	/**
	 * The other arguments.
	 */
	List<? extends Object> arguments;

	/**
	 * Constructor.
	 * 
	 * @param modelURI
	 *            is the URI of the model.
	 * @param targetFolder
	 *            is the output folder
	 * @param arguments
	 *            are the other arguments
	 * @throws IOException
	 *             Thrown when the output cannot be saved.
	 * @generated NOT
	 */
	public GenerateAll(URI modelURI, File targetFolder, List<? extends Object> arguments) {
		this.modelURI = modelURI;
		this.targetFolder = targetFolder;
		this.arguments = arguments;
	}

	/**
	 * Launches the generation.
	 *
	 * @param monitor
	 *            This will be used to display progress information to the user.
	 * @throws IOException
	 *             Thrown when the output cannot be saved.
	 * @generated NOT
	 */
	public void doGenerate(IProgressMonitor monitor) throws IOException {
		if (!targetFolder.exists()) {
			targetFolder.mkdirs();
		}
		monitor.subTask("Loading...");
		ecore4CPP.generator.main.Generate gen0 = new ecore4CPP.generator.main.Generate(modelURI, targetFolder, arguments);
		monitor.worked(1);
		String generationID = org.eclipse.acceleo.engine.utils.AcceleoLaunchingUtil.computeUIProjectID("ecore4CPP.generator", "ecore4CPP.generator.main.Generate", modelURI.toString(), targetFolder.toString(), new ArrayList<String>());
		gen0.setGenerationID(generationID);
		gen0.doGenerate(BasicMonitor.toMonitor(monitor));
	}
}
