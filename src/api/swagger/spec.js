var spec = 
{
  "openapi": "3.0.3",
  "info": {
    "title": "MDE4CPP-API",
    "description": "A dashboard for the MDE4CPP-API",
    "contact": {
      "email": "martin.noebel@tu-ilmenau.de"
    },
    "version": "1.0"
  },
  "servers": [
    {
      "url": "http://localhost:8080"
    }
  ],
  "tags": [
    {
      "name": "crud",
      "description": "Create, Read, Delete or Update objects"
    },
    {
      "name": "instance-specification",
      "description": "Save or Load multiple objects"
    }
  ],
  "paths": {
    "/objects/{className}/{objectName}": {
      "get": {
        "tags": [
          "crud"
        ],
        "summary": "Read an existing object",
        "operationId": "readObject",
        "parameters": [
          {
            "name": "className",
            "in": "path",
            "description": "Classname for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          },
          {
            "name": "objectName",
            "in": "path",
            "description": "Name for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          }
        ],
        "responses": {
          "200": {
            "description": "Returns the object as a json"
          },
          "404": {
            "description": "Object not found"
          },
          "500": {
            "description": "An exception occurred"
          }
        }
      },
      "post": {
        "tags": [
          "crud"
        ],
        "summary": "Create a new object",
        "operationId": "createObject",
        "parameters": [
          {
            "name": "className",
            "in": "path",
            "description": "Classname for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          },
          {
            "name": "objectName",
            "in": "path",
            "description": "Name for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          }
        ],
        "requestBody": {
          "description": "The object in serialized form",
          "required": true,
          "content": {
            "application/json": {
              "schema": {
                "type": "object"
              }
            }
          }
        },
        "responses": {
          "201": {
            "description": "Object is created successfully"
          },
          "400": {
            "description": "Object already exists"
          },
          "500": {
            "description": "An exception occurred"
          }
        }
      },
      "put": {
        "tags": [
          "crud"
        ],
        "summary": "Update an existing object",
        "operationId": "updateObject",
        "parameters": [
          {
            "name": "className",
            "in": "path",
            "description": "Classname for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          },
          {
            "name": "objectName",
            "in": "path",
            "description": "Name for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          }
        ],
        "requestBody": {
          "description": "The object in serialized form",
          "required": true,
          "content": {
            "application/json": {
              "schema": {
                "type": "object"
              }
            }
          }
        },
        "responses": {
          "200": {
            "description": "Object is updated successfully"
          },
          "404": {
            "description": "Object not found"
          },
          "500": {
            "description": "An exception occurred"
          }
        }
      },
      "delete": {
        "tags": [
          "crud"
        ],
        "summary": "Delete an existing object",
        "operationId": "deleteObject",
        "parameters": [
          {
            "name": "className",
            "in": "path",
            "description": "Classname for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          },
          {
            "name": "objectName",
            "in": "path",
            "description": "Name for the object",
            "required": true,
            "schema": {
              "type": "string"
            }
          }
        ],
        "responses": {
          "204": {
            "description": "Object deleted successfully"
          },
          "404": {
            "description": "Object not found"
          },
          "500": {
            "description": "An exception occurred"
          }
        }
      }
    },
    "/objects": {
      "get": {
        "tags": [
          "instance-specification"
        ],
        "summary": "Save a list of objects",
        "operationId": "saveObjects",
        "responses": {
          "200": {
            "description": "Returns all objects as a json"
          },
          "500": {
            "description": "An exception occurred"
          }
        }
      },
      "post": {
        "tags": [
          "instance-specification"
        ],
        "summary": "Load a list of objects",
        "operationId": "loadObjects",
        "requestBody": {
          "description": "The objects in serialized form",
          "required": true,
          "content": {
            "application/json": {
              "schema": {
                "type": "array",
                "items": {
                  "type": "object"
                }
              }
            }
          }
        },
        "responses": {
          "201": {
            "description": "All objects created successfully"
          },
          "500": {
            "description": "An exception occurred"
          }
        }
      }
    }
  }
}