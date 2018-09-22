# Ecore Model Example
This example includes a library DSL, which is shown in the following figure. The application create a library with one book with a picture. All books of the library will be printed out.

To generate the c++ project as well as gradle build files, execute:
```
Windows:
  gradlew generateModel -PModel=%MDE4CPP_HOME%/src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore

Unix:
  gradlew generateModel -PModel=$MDE4CPP_HOME/src/examples/ecoreExamples/ecoreModelExample/model/libraryModel_ecore.ecore
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
gradlew compileApplicationForLibraryModel_ecore
```
 * To compile the generated c++ library (without executable), use:
```
gradlew compileLibraryModel_ecore
```
 * To generate the model again, use:
```
gradlew generateLibraryModel_ecore
```
 * To generate and compile with single command, use:
```
gradlew buildLibraryModel_ecore
```

Resulting executables and libraries will be delivered to folder `%MDE4CPP_HOME%/application/bin` and can be executed there.

##Model figures

![Class diagramm example library model *ecoreModelExample*](diagram.png)
