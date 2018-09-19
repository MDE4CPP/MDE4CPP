# Example model "Calculator"

This is an example for an executable model using fUML execution engine. It determines if a given number is a prime number. The number is set as default value of attribute 'PrimeChecker::number'.

To create the gradle project use:

> gradle generateModel -PModel=%MDE4CPP_HOME%/src/examples/fUMLExamples/Calculator/model/CalcModel.uml

or

> generate

in the model folder.

To compile the example use:

> gradle buildCalcModel


![Activity diagramm of behavior to determine if a given number is prime.](diagram.png)
###### Figure1: Example library model using UML as metamodel