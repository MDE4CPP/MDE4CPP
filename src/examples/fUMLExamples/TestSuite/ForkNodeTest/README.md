# Example model "ForkNode"

This is an example for an executable model using fork nodes.

To generate the c++ project as well as gradle build files, execute:
```
Windows:
  gradlew generateModel -PModel=%MDE4CPP_HOME%/src/examples/fUMLExamples/ForkNodeTest/model/forkNodeTest.uml

Unix:
  gradlew generateModel -PModel=$MDE4CPP_HOME/src/examples/fUMLExamples/ForkNodeTest/model/forkNodeTest.uml
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
gradlew compileForkNodeTest
```
 * To generate the model again, use:
```
gradlew generateForkNodeTest
```
 * To generate and compile with single command, use:
```
gradlew buildForkNodeTest
```

Resulting executables and libraries will be delivered to folder `%MDE4CPP_HOME%/application/bin` and can be executed there.


## Model figures

![Activity diagram demonstrating the functionality of fork node.](diagram.png)
