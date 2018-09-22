# UML Model Example
This example defines a library DSL, which is shown in the following figure. The application create a library with one book with a picture. All books of the library will be printed out.

To generate the c++ project as well as gradle build files, execute:
```
Windows:
  gradlew generateModel -PModel=%MDE4CPP_HOME%/src/examples/UMLExamples/UMLModelExample/model/LibraryModel_uml.uml

Unix:
  gradlew generateModel -PModel=$MDE4CPP_HOME/src/examples/UMLExamples/UMLModelExample/model/LibraryModel_uml.uml
```
in MDE4CPP home folder or call script file:
```
Windows:
  generate

Unix:
  ./generate
```
in model folder.

Following tasks are available after first code generation (build.gradle files are generated):
 * To compile the generated c++ project (executable and library), use:
```
gradlew compileApplicationForLibraryModel_uml
```
 * To compile the generated c++ library (without executable), use:
```
gradlew compileLibraryModel_uml
```
 * To generate the model again, use:
```
gradlew generateLibraryModel_uml
```
 * To generate and compile with single command, use:
```
gradlew buildLibraryModel_uml
```

Resulting executables and libraries will be delivered to folder `%MDE4CPP_HOME%/application/bin` and can be executed there.

##Model figures

![Class diagramm of model *umlModelExample*](diagram.png)
