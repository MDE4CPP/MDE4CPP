# Documentation for MDE4CPP-API

This is a small overview for the different endpoints and how to use them. The api is reachable under ```localhost:8080```.
An example for this specific model api can be found in the postman json.

## READ-Endpoint: ```GET /objects/<className>/<objectName>```

This endpoint is used for reading out a specific object which was created over the POST-Endpoint.

Inputs:
* className = specifies the class of the object from the model
* objectName = specifies the name of the object itself

Outputs:
* 200 = the request was successful and the body contains the serialized form of the requested object
* 404 = the requested object doesn't exist under the given objectName
* 500 = an exception occurred while serializing the object

## CREATE-Endpoint: ```POST /objects/<className>/<objectName> + Object```

This endpoint is used for creating an object of the specified class.

Inputs:
* className = specifies the class of the object from the model; note: the className is only the name of a class and does not include packages (/namespaces). Packages are not supported since they are not yet fully implemented in ecore4CPP 
* objectName = specifies the name of the object itself; note: the objectName is just an identifier for accessing an object via the API and and does not correspond to any attribute of the object itself
* Object = a serialized form of an object from the model inside the request body as json

Outputs:
* 201 = the request was successful and the object was created
* 400 = the requested object already exists under the given objectName
* 404 = className does not exist in the Model
* 500 = an exception occurred while deserializing the object

## UPDATE-Endpoint: ```PUT /objects/<className>/<objectName> + Object```

This endpoint is used for updating a specific object with the given input.

Inputs:
* className = specifies the class of the object from the model
* objectName = specifies the name of the object itself
* Object = a serialized form of an object from the model inside the request body as json

Outputs:
* 200 = the request was successful and the object was updated
* 404 = the requested object doesn't exist under the given objectName
* 500 = an exception occurred while updating the object

## DELETE-Endpoint: ```DELETE /objects/<className>/<objectName>```

This endpoint is used for deleting a specific object which was created over the POST-Endpoint.

Inputs:
* className = specifies the class of the object from the model
* objectName = specifies the name of the object itself

Outputs:
* 204 = the request was successful and the object was deleted
* 404 = the requested object doesn't exist under the given objectName
* 500 = an exception occurred while deleting the object

## Instance-Specification ```GET /objects/``` or ```POST /objects/ + ObjectList```

This is an additional feature to save and load the current instance model by writing or reading all objects and attach 
some more features like the class or the name. 

* ```GET /objects/``` = returns all objects in serialized form as a list and some additional information like className and objectName
* ```POST /objects/ + ObjectList``` = creates all objects from the request body (needs the json from the get endpoint above)