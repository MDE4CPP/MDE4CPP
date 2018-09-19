# Example model "MultiplePins"

This is an example for testing the functionality of pins. The stop condition is implemented in the body of function behaviour of 'fUMLMultiplePins::TestClass::istEnde'

To create the gradle project use:

> gradle generateModel -PModel=%MDE4CPP_HOME%/src/examples/fUMLExamples/MultiplePins/model/fUMLMultiplePins.uml

or

> generate

in the model folder.

To compile the example use:

> gradle buildFUMLMultiplePins

![Activity diagram with two actions to test the behavior of pins.](diagram.png)

![Class diagram of fork node example.](ClassDiagram.png)