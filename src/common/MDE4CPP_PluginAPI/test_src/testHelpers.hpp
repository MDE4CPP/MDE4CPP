#ifndef TESTHELPERS_H
#define TESTHELPERS_H

#include "ecore/EObject.hpp"
#include "pluginFramework/MDE4CPPPlugin.hpp"

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
		]
	}
	*/
	std::shared_ptr<ecore::EObject> getExampleModelInstance_1();

	/**
	 * Set up the LibraryModel_ecore expected from the json:
	 
	{
		"ObjectClass" : "libraryModel_ecore::LibraryModel",
		"authors" : [
			{
				"ObjectClass" : "libraryModel_ecore::Author",
				"Name" : "Andrzej Sapkowski"
			},
			{
				"ObjectClass" : "libraryModel_ecore::Author",
				"Name" : "Frank Herbert"
			},
		],
		"book" : [
			{
				"ObjectClass" : "libraryModel_ecore::Book",
				"Name" : "Der letzte Wunsch",
				"authors" : ["#authors@0"],
				"pictures" : []
			},
			{
				"ObjectClass" : "libraryModel_ecore::Book",
				"Name" : "Dune, der Wüstenplanet",
				"authors" : ["#authors@1"],
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
}




#endif /*TESTHELPERS_H*/