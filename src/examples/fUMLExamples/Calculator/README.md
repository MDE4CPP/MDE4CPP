# Example model "Calculator"

This is an example for an executable model using fUML execution engine. It determines if a given number is a prime number. The number is set as default value of attribute `PrimeChecker::number`.

To generate the c++ project as well as gradle build files, execute:
```
Windows:
  gradlew generateModel -PModel=%MDE4CPP_HOME%/src/examples/fUMLExamples/Calculator/model/CalcModel.uml

Unix:
  gradlew generateModel -PModel=$MDE4CPP_HOME/src/examples/fUMLExamples/Calculator/model/CalcModel.uml
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
 * To compile the generated c++ project, use:
```
gradlew compileCalcModel
```
 * To generate the model again, use:
```
gradlew generateCalcModel
```
 * To generate and compile with single command, use:
```
gradlew buildCalcModel
```

Resulting executables and libraries will be delivered to folder `%MDE4CPP_HOME%/application/bin` and can be executed there.

##Model figures

![Activity diagramm of prime checker calc model to determine if a given number is prime.](diagram.png)
