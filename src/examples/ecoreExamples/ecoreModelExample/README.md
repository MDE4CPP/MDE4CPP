# Ecore Model Example
This example includes a library DSL, which is shown in the following figure. The application create a library with one book with a picture. All books of the library will be printed out.

To create the gradle project use:

> gradle generateModel -PModel=%MDE4CPP_HOME%/src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore

or

> generate

in the model folder.

To compile the example use:

> gradle buildLibraryModel_ecore


![Class diagramm example library model *ecoreModelExample*](diagram.png)