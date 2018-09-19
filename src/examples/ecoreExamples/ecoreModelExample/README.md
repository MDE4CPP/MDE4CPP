#Ecore Model Example
This example includes a library DSL, which is shown in the following figure. The Application create a Library with one Book with a Picture. All books of the library will be printed out.
To create the gradle project:
`gradle generateModel -PModel=%MDE4CPP_HOME%/src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore`
or
`generate` in the model folder.
To compile the example:
`gradle buildLibraryModel_ecore`

###### Example model using ecore as metamodel
![Class diagramm of model *ecoreModelExample*](diagram.png)
