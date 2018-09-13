#include "libraryModel_ecore/impl/LibraryModel_ecorePackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

//depending model packages
#include "types/TypesPackage.hpp"

using namespace libraryModel_ecore;

void LibraryModel_ecorePackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createAuthorContent(package, factory);
	createBookContent(package, factory);
	createLibraryModelContent(package, factory);
	createNamedElementContent(package, factory);
	createPictureContent(package, factory);

	createPackageEDataTypes(package, factory);
}

void LibraryModel_ecorePackageImpl::createAuthorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_author_EClass = factory->createEClass_in_EPackage(package, AUTHOR_ECLASS);
	
	
	
}

void LibraryModel_ecorePackageImpl::createBookContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_book_EClass = factory->createEClass_in_EPackage(package, BOOK_ECLASS);
	
	m_book_EReference_authors = factory->createEReference_in_EContainingClass(m_book_EClass, BOOK_EREFERENCE_AUTHORS);
	m_book_EReference_library = factory->createEReference_in_EContainingClass(m_book_EClass, BOOK_EREFERENCE_LIBRARY);
	m_book_EReference_pictures = factory->createEReference_in_EContainingClass(m_book_EClass, BOOK_EREFERENCE_PICTURES);
	
	
}

void LibraryModel_ecorePackageImpl::createLibraryModelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_libraryModel_EClass = factory->createEClass_in_EPackage(package, LIBRARYMODEL_ECLASS);
	
	m_libraryModel_EReference_authors = factory->createEReference_in_EContainingClass(m_libraryModel_EClass, LIBRARYMODEL_EREFERENCE_AUTHORS);
	m_libraryModel_EReference_book = factory->createEReference_in_EContainingClass(m_libraryModel_EClass, LIBRARYMODEL_EREFERENCE_BOOK);
	
	
}

void LibraryModel_ecorePackageImpl::createNamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_namedElement_EClass = factory->createEClass_in_EPackage(package, NAMEDELEMENT_ECLASS);
	m_namedElement_EAttribute_name = factory->createEAttribute_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EATTRIBUTE_NAME);
	
	
	
}

void LibraryModel_ecorePackageImpl::createPictureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_picture_EClass = factory->createEClass_in_EPackage(package, PICTURE_ECLASS);
	m_picture_EAttribute_pageNumber = factory->createEAttribute_in_EContainingClass(m_picture_EClass, PICTURE_EATTRIBUTE_PAGENUMBER);
	
	m_picture_EReference_book = factory->createEReference_in_EContainingClass(m_picture_EClass, PICTURE_EREFERENCE_BOOK);
	
	
}

void LibraryModel_ecorePackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	
}
