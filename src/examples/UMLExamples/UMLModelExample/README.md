# UML Model Example
This example defines a library DSL, which is shown in the following figure. The Application create a library with one book with a picture. All books of the library will be printed out.
To create the gradle project:

> gradle generateModel -PModel=%MDE4CPP_HOME%/src/examples/UMLExamples/UMLModelExample/model/LibraryModel_uml.uml

or

> generate

in the model folder.

To compile the example:

> gradle buildLibraryModel_uml

![Class diagramm of model *umlModelExample*](diagram.png)
###### Figure1: Example library model using UML as metamodel