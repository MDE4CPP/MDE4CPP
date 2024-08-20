#ifndef TESTHELPERS_H
#define TESTHELPERS_H

#include "ecore/EObject.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"

#include "util/crow_all.h"

namespace testHelpers{

	/**
	 * Set up the LibraryModel_ecore expected from the json:
	 
	{
		"ObjectClass" : "libraryModel_ecore::LibraryModel",
		"authors" : [
			{
				"ObjectClass" : "libraryModel_ecore::Author",
				"Name" : "David Sylvester"
			},
		],
		"book" : [
			{
				"ObjectClass" : "libraryModel_ecore::Book",
				"Name" : "Magritte",
				"authors" : ["#authors@0"],
				"publisher": "publisher@0",
				"pages" : "448",
				"genres" : ["Art","Architecture"],
				"pictures" : [
					{
						"ObjectClass" : "libraryModel_ecore::Picture",
						"Name" : "Der Verrat der Binder (La trahison des images), 1929: l, 60x82 cm",
						"pageNumber" : "212"
					}
				]
			}
		],
		"publishers": [
			{
			"ObjectClass": "libraryModel_ecore::Publisher"
			"adress": {
				"ObjectClass": "libraryModel_ecore::Adress"
				"street": "Schanzenstr",
				"county": "Germany",
				"house_number": 13,
				"city": "Köln",
			},
			"Name": "Avus Buch & Medien",
			}
		]
	}
	*/
	std::shared_ptr<ecore::EObject> getExampleModelInstance_1();

	/**
	 * returns a model json of the form:
	  	{
			"ObjectClass" : "libraryModel_ecore::LibraryModel",
			"authors" : [
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "Andrzej Sapkowski"
				},
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "Dimity Glukhovsky"
				},
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "Frank Herbert"
				},
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "Andy Weir"
				},
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "J.R.R. Tolkin"
				}
			],
			"book" : [
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Metro 2033",
					"authors" : ["$Glukhovsky"],
					"pictures" : []
				},
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Metro 2034",
					"authors" : ["#authors@1"],
					"pictures" : []
				},
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Artemis",
					"authors" : ["#authors@3"],
					"pictures" : []
				},
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Der Hobbit",
					"authors" : ["$Tolkin"],
					"pictures" : []
				},
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Der letzte Wunsch",
					"authors" : ["#authors@0"],
					"pictures" : []
				},
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Dune, der Wüstenplanet",
					"authors" : ["#authors@2"],
					"pictures" : [
						{
							"ObjectClass" : "libraryModel_ecore::Picture",
							"Name" : "Albtraum der Wüste",
							"pageNumber" : "385"
						},
						{
							"ObjectClass" : "libraryModel_ecore::Picture",
							"Name" : "Flug über den Schildwall",
							"pageNumber" : "417"
						},
					]
				}
			]
		}  
	*/
	std::string getTestJSON_Large();

	/* returns a model json of the form:
		{
			"ObjectClass" : "libraryModel_ecore::LibraryModel",
			"authors" : [
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "Andrzej Sapkowski"
				}
			],
			"books" : [
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Der letzte Wunsch",
					"authors" : ["authors@0"],
					"pictures" : []
				}
			]
		}
	*/
	std::string getTestJSON_Small();

	/* returns a model json of the form:
		{
			"ObjectClass" : "libraryModel_ecore::LibraryModel",
			"authors" : [
				{
					"ObjectClass" : "libraryModel_ecore::Author",
					"Name" : "David Sylvester"
				}],
			"books" : [
				{
					"ObjectClass" : "libraryModel_ecore::Book",
					"Name" : "Magritte",
					"authors" : ["authors@0"],
					"pages" : 448,
					"genres" : ["Art","Architecture"],
					"publisher" : "publishers@0",
					"pictures" : [
						{
							"ObjectClass" : "libraryModel_ecore::Picture",
							"Name" : "Der Verrat der Binder",
							"pageNumber" : 212
						}]
				}],
			"publishers" : [
				{
				"ObjectClass" : "libraryModel_ecore::Publisher",
				"Name" : "Avus Buch & Medien",
				"adress" : {
					"ObjectClass" : "libraryModel_ecore::Adress",
					"county" : "Germany",
					"city" : "Köln",
					"street" : "Schanzenstr",
					"house_number" : 13
					}
				}
			] 
		}
	*/
	std::string getTestJSON_Medium();
}



#endif /*TESTHELPERS_H*/