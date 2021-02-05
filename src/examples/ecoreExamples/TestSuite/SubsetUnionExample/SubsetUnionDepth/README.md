# Example model "SubsetUnionDepth"

The functionality of the subset union implementation including the of MDE4CPP will be demonstrated in this example. Additionally, this example demonstrate an example of inheritance of attributes. The main implementation is located in the annotation 'prepareApplication' using the key 'sourceCodeMain'. The algorithm create a container object of the type of 'Container_Level10' and objects for each 'Element_Level' class and put it only into the appropriate subset. The content of all subsets and the union will be printed out.

To generate the c++ project as well as gradle build files, execute:
```
Windows:
  gradlew generateModel -PModel=%MDE4CPP_HOME%/src/examples/commonExamples/SubsetUnionExample/SubsetUnionDepth/model/subsetUnionDepth.ecore

Unix:
  gradlew generateModel -PModel=$MDE4CPP_HOME/src/examples/commonExamples/SubsetUnionExample/SubsetUnionDepth/model/subsetUnionDepth.ecore
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
gradlew compileApplicationForSubsetUnionDepth
```
 * To compile the generated c++ library (without executable), use:
```
gradlew compileSubsetUnionDepth
```
 * To generate the model again, use:
```
gradlew generateSubsetUnionDepth
```
 * To generate and compile with single command, use:
```
gradlew buildSubsetUnionDepth
```

Resulting executables and libraries will be delivered to folder `%MDE4CPP_HOME%/application/bin` and can be executed there.

## Model figures

![Class diagramm of model *SubsetUnionDepth*](diagram.png)

## Execution result:

```
...

Printing out subset of level 1
Name: Element1 Type of: Element_Level1
Name: Element2 Type of: Element_Level2
Name: Element3 Type of: Element_Level3
Name: Element4 Type of: Element_Level4
Name: Element5 Type of: Element_Level5
Name: Element6 Type of: Element_Level6
Name: Element7 Type of: Element_Level7
Name: Element8 Type of: Element_Level8
Name: Element9 Type of: Element_Level9
Name: Element10 Type of: Element_Level10
-------------------
Printing out subset of level 2
Name: Element2 Type of: Element_Level2
Name: Element3 Type of: Element_Level3
Name: Element4 Type of: Element_Level4
Name: Element5 Type of: Element_Level5
Name: Element6 Type of: Element_Level6
Name: Element7 Type of: Element_Level7
Name: Element8 Type of: Element_Level8
Name: Element9 Type of: Element_Level9
Name: Element10 Type of: Element_Level10
-------------------

...

-------------------
Printing out subset of level 9
Name: Element9 Type of: Element_Level9
Name: Element10 Type of: Element_Level10
-------------------
Printing out subset of level 10
Name: Element10 Type of: Element_Level10
-------------------
Printing out the Union. Size: 11
Name: Element0
Name: Element1
Name: Element2
Name: Element3
Name: Element4
Name: Element5
Name: Element6
Name: Element7
Name: Element8
Name: Element9
Name: Element10
-------------------
```
