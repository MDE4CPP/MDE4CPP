#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "types/TypesPackage.hpp"

using namespace libraryModel_ecore;

void LibraryModel_ecorePackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_author_EClass->getESuperTypes()->push_back(getNamedElement_EClass());
	m_book_EClass->getESuperTypes()->push_back(getNamedElement_EClass());
	m_picture_EClass->getESuperTypes()->push_back(getNamedElement_EClass());
	

 	// Initialize classes and features; add operations and parameters
	initializeAuthorContent();
	initializeBookContent();
	initializeLibraryModelContent();
	initializeNamedElementContent();
	initializePictureContent();

	initializePackageEDataTypes();
}

void LibraryModel_ecorePackageImpl::initializeAuthorContent()
{
	m_author_EClass->setName("Author");
	m_author_EClass->setAbstract(false);
	m_author_EClass->setInterface(false);
	
	
	
	
}

void LibraryModel_ecorePackageImpl::initializeBookContent()
{
	m_book_EClass->setName("Book");
	m_book_EClass->setAbstract(false);
	m_book_EClass->setInterface(false);
	
	
	m_book_EReference_authors->setName("authors");
	m_book_EReference_authors->setEType(getAuthor_EClass());
	m_book_EReference_authors->setLowerBound(0);
	m_book_EReference_authors->setUpperBound(-1);
	m_book_EReference_authors->setTransient(false);
	m_book_EReference_authors->setVolatile(false);
	m_book_EReference_authors->setChangeable(true);
	m_book_EReference_authors->setUnsettable(false);
	m_book_EReference_authors->setUnique(true);
	m_book_EReference_authors->setDerived(false);
	m_book_EReference_authors->setOrdered(true);
	m_book_EReference_authors->setContainment(false);
	m_book_EReference_authors->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_book_EReference_authors->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_book_EReference_authors->setEOpposite(otherEnd);
	    }
	}
	m_book_EReference_library->setName("library");
	m_book_EReference_library->setEType(getLibraryModel_EClass());
	m_book_EReference_library->setLowerBound(0);
	m_book_EReference_library->setUpperBound(1);
	m_book_EReference_library->setTransient(false);
	m_book_EReference_library->setVolatile(false);
	m_book_EReference_library->setChangeable(true);
	m_book_EReference_library->setUnsettable(false);
	m_book_EReference_library->setUnique(true);
	m_book_EReference_library->setDerived(false);
	m_book_EReference_library->setOrdered(true);
	m_book_EReference_library->setContainment(false);
	m_book_EReference_library->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_book_EReference_library->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getLibraryModel_EReference_book();
		if (otherEnd != nullptr)
	    {
	   		m_book_EReference_library->setEOpposite(otherEnd);
	    }
	}
	m_book_EReference_pictures->setName("pictures");
	m_book_EReference_pictures->setEType(getPicture_EClass());
	m_book_EReference_pictures->setLowerBound(0);
	m_book_EReference_pictures->setUpperBound(-1);
	m_book_EReference_pictures->setTransient(false);
	m_book_EReference_pictures->setVolatile(false);
	m_book_EReference_pictures->setChangeable(true);
	m_book_EReference_pictures->setUnsettable(false);
	m_book_EReference_pictures->setUnique(true);
	m_book_EReference_pictures->setDerived(false);
	m_book_EReference_pictures->setOrdered(true);
	m_book_EReference_pictures->setContainment(true);
	m_book_EReference_pictures->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_book_EReference_pictures->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getPicture_EReference_book();
		if (otherEnd != nullptr)
	    {
	   		m_book_EReference_pictures->setEOpposite(otherEnd);
	    }
	}
	
	
}

void LibraryModel_ecorePackageImpl::initializeLibraryModelContent()
{
	m_libraryModel_EClass->setName("LibraryModel");
	m_libraryModel_EClass->setAbstract(false);
	m_libraryModel_EClass->setInterface(false);
	
	
	m_libraryModel_EReference_authors->setName("authors");
	m_libraryModel_EReference_authors->setEType(getAuthor_EClass());
	m_libraryModel_EReference_authors->setLowerBound(0);
	m_libraryModel_EReference_authors->setUpperBound(-1);
	m_libraryModel_EReference_authors->setTransient(false);
	m_libraryModel_EReference_authors->setVolatile(false);
	m_libraryModel_EReference_authors->setChangeable(true);
	m_libraryModel_EReference_authors->setUnsettable(false);
	m_libraryModel_EReference_authors->setUnique(true);
	m_libraryModel_EReference_authors->setDerived(false);
	m_libraryModel_EReference_authors->setOrdered(true);
	m_libraryModel_EReference_authors->setContainment(true);
	m_libraryModel_EReference_authors->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_libraryModel_EReference_authors->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_libraryModel_EReference_authors->setEOpposite(otherEnd);
	    }
	}
	m_libraryModel_EReference_book->setName("book");
	m_libraryModel_EReference_book->setEType(getBook_EClass());
	m_libraryModel_EReference_book->setLowerBound(0);
	m_libraryModel_EReference_book->setUpperBound(-1);
	m_libraryModel_EReference_book->setTransient(false);
	m_libraryModel_EReference_book->setVolatile(false);
	m_libraryModel_EReference_book->setChangeable(true);
	m_libraryModel_EReference_book->setUnsettable(false);
	m_libraryModel_EReference_book->setUnique(true);
	m_libraryModel_EReference_book->setDerived(false);
	m_libraryModel_EReference_book->setOrdered(true);
	m_libraryModel_EReference_book->setContainment(true);
	m_libraryModel_EReference_book->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_libraryModel_EReference_book->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getBook_EReference_library();
		if (otherEnd != nullptr)
	    {
	   		m_libraryModel_EReference_book->setEOpposite(otherEnd);
	    }
	}
	
	m_libraryModel_EOperation_printLibrary->setEType(nullptr);
	m_libraryModel_EOperation_printLibrary->setName("printLibrary");
	m_libraryModel_EOperation_printLibrary->setLowerBound(0);
	m_libraryModel_EOperation_printLibrary->setUpperBound(1);
	m_libraryModel_EOperation_printLibrary->setUnique(true);
	m_libraryModel_EOperation_printLibrary->setOrdered(true);
	
	
	
}

void LibraryModel_ecorePackageImpl::initializeNamedElementContent()
{
	m_namedElement_EClass->setName("NamedElement");
	m_namedElement_EClass->setAbstract(false);
	m_namedElement_EClass->setInterface(false);
	
	m_namedElement_EAttribute_name = getNamedElement_EAttribute_name();
	m_namedElement_EAttribute_name->setName("Name");
	m_namedElement_EAttribute_name->setEType(types::TypesPackage::eInstance()->getString_EDataType());
	m_namedElement_EAttribute_name->setLowerBound(0);
	m_namedElement_EAttribute_name->setUpperBound(1);
	m_namedElement_EAttribute_name->setTransient(false);
	m_namedElement_EAttribute_name->setVolatile(false);
	m_namedElement_EAttribute_name->setChangeable(true);
	m_namedElement_EAttribute_name->setUnsettable(false);
	m_namedElement_EAttribute_name->setUnique(true);
	m_namedElement_EAttribute_name->setDerived(false);
	m_namedElement_EAttribute_name->setOrdered(true);
	m_namedElement_EAttribute_name->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_namedElement_EAttribute_name->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	
}

void LibraryModel_ecorePackageImpl::initializePictureContent()
{
	m_picture_EClass->setName("Picture");
	m_picture_EClass->setAbstract(false);
	m_picture_EClass->setInterface(false);
	
	m_picture_EAttribute_pageNumber = getPicture_EAttribute_pageNumber();
	m_picture_EAttribute_pageNumber->setName("pageNumber");
	m_picture_EAttribute_pageNumber->setEType(types::TypesPackage::eInstance()->getInteger_EDataType());
	m_picture_EAttribute_pageNumber->setLowerBound(0);
	m_picture_EAttribute_pageNumber->setUpperBound(1);
	m_picture_EAttribute_pageNumber->setTransient(false);
	m_picture_EAttribute_pageNumber->setVolatile(false);
	m_picture_EAttribute_pageNumber->setChangeable(true);
	m_picture_EAttribute_pageNumber->setUnsettable(false);
	m_picture_EAttribute_pageNumber->setUnique(true);
	m_picture_EAttribute_pageNumber->setDerived(false);
	m_picture_EAttribute_pageNumber->setOrdered(true);
	m_picture_EAttribute_pageNumber->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_picture_EAttribute_pageNumber->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_picture_EReference_book->setName("book");
	m_picture_EReference_book->setEType(getBook_EClass());
	m_picture_EReference_book->setLowerBound(0);
	m_picture_EReference_book->setUpperBound(1);
	m_picture_EReference_book->setTransient(false);
	m_picture_EReference_book->setVolatile(false);
	m_picture_EReference_book->setChangeable(true);
	m_picture_EReference_book->setUnsettable(false);
	m_picture_EReference_book->setUnique(true);
	m_picture_EReference_book->setDerived(false);
	m_picture_EReference_book->setOrdered(true);
	m_picture_EReference_book->setContainment(false);
	m_picture_EReference_book->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_picture_EReference_book->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getBook_EReference_pictures();
		if (otherEnd != nullptr)
	    {
	   		m_picture_EReference_book->setEOpposite(otherEnd);
	    }
	}
	
	
}

void LibraryModel_ecorePackageImpl::initializePackageEDataTypes()
{
	
}
