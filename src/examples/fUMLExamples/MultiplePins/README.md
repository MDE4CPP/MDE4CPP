# Example model "MultiplePins"

This is an example for testing the functionality of pins. The stop condition is implemented in the body of function behaviour of `fUMLMultiplePins::TestClass::istEnde`

To generate the c++ project as well as gradle build files, execute:
```
Windows:
  gradlew generateModel -PModel=%MDE4CPP_HOME%/src/examples/fUMLExamples/MultiplePins/model/fUMLMultiplePins.uml

Unix:
  gradlew generateModel -PModel=$MDE4CPP_HOME/src/examples/fUMLExamples/MultiplePins/model/fUMLMultiplePins.uml
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
gradlew compileFUMLMultiplePins
```
 * To generate the model again, use:
```
gradlew generateFUMLMultiplePins
```
 * To generate and compile with single command, use:
```
gradlew buildFUMLMultiplePins
```

Resulting executables and libraries will be delivered to folder `%MDE4CPP_HOME%/application/bin` and can be executed there.


## Model figures

![Activity diagram with two actions to test the behavior of pins.](diagram.png)

![Class diagram of fork node example.](ClassDiagram.png)
