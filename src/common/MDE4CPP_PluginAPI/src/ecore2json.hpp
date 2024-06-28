#ifndef ECORE2JSON_HPP
#define ECORE2JSON_HPP

#include "util/crow_all.h"

#include "ecore/EObject.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ecorePackage.hpp"

#include "pluginHandler.hpp"

class Ecore2Json {
    public:
        //methodes
        Ecore2Json();

        /**
         * parses an eObject and stores its attributes and refernces as a json
         *  -ignores backreferences since ecore should set them automatically
         *  -cross references are stored as the path to the object they reference in the modelInstance
         * @param object : ptr to the object being parsed
         * @param return_json : reference to the json::wvalue where the parsed attributes and refernces are to be stored
         */
        void createJsonOfEObject(const std::shared_ptr<ecore::EObject>& object, crow::json::wvalue& result_json);
        
    private:
        enum referenceType { //enum for reference types
            CONTAINMENT_REFERENCE,
            CROSS_REFERENCE,
            BACK_REFERENCE
        };

        //methodes
        /**
         * returns the full namespace + name of a given eObject
         * @param object : ptr to the object
         * //TODO document return
         */
        std::string getObjectClassName(const std::shared_ptr<ecore::EObject>& obj);

        /**
         * returns the type of a given eReference
         * @param eRef : ptr to an eReference; will throw runtime error if it is a nullptr
         * @return appropriate reference type
         */
        referenceType getRefType(const std::shared_ptr<ecore::EReference>& eRef);
        
        /**
         * writes the value of a passed structuralFeature into the passed json::wvalue; does insert a list if multiplicity of the structuralFeature is > 1
         * @param object : ptr to the object containing the structFeature being parsed
         * @param feature : ptr to the stuctFeature in the meta model, needed for calling eGet
         * @param return_json : reference to the json::wvalue where the parsed value is to be stored
         */
        template<typename T> void writeFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EAttribute>& feature, crow::json::wvalue& return_json);
};
#endif /*ECORE2JSON_HPP*/