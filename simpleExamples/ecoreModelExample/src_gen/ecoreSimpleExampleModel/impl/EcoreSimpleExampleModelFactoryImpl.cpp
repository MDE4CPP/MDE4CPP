#include "EcoreSimpleExampleModelFactoryImpl.hpp"
#include "EcoreSimpleExampleModelPackage.hpp"

#include "EClass.hpp"

using namespace ecoreSimpleExampleModel;

//*********************************
// Constructor / Destructor
//*********************************

EcoreSimpleExampleModelFactoryImpl::EcoreSimpleExampleModelFactoryImpl()
{
	m_idMap.insert(std::pair<std::string,unsigned int>("Author", EcoreSimpleExampleModelPackage::AUTHOR));
	m_idMap.insert(std::pair<std::string,unsigned int>("Book", EcoreSimpleExampleModelPackage::BOOK));
	m_idMap.insert(std::pair<std::string,unsigned int>("LibraryModel", EcoreSimpleExampleModelPackage::LIBRARYMODEL));
	m_idMap.insert(std::pair<std::string,unsigned int>("NamedElement", EcoreSimpleExampleModelPackage::NAMEDELEMENT));
}

EcoreSimpleExampleModelFactoryImpl::~EcoreSimpleExampleModelFactoryImpl()
{
}

EcoreSimpleExampleModelFactory* EcoreSimpleExampleModelFactoryImpl::create()
{
	return new EcoreSimpleExampleModelFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> EcoreSimpleExampleModelFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case EcoreSimpleExampleModelPackage::AUTHOR:
		{
				return std::shared_ptr<Author>(this->createAuthor());
			
		}
		case EcoreSimpleExampleModelPackage::BOOK:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Book>(this->createBook());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<ecoreSimpleExampleModel::LibraryModel>(container);
				assert(castedContainer);
				return std::shared_ptr<Book>(this->createBook_in_Library(castedContainer));
			}
		}
		case EcoreSimpleExampleModelPackage::LIBRARYMODEL:
		{
				return std::shared_ptr<LibraryModel>(this->createLibraryModel());
			
		}
		case EcoreSimpleExampleModelPackage::NAMEDELEMENT:
		{
				return std::shared_ptr<NamedElement>(this->createNamedElement());
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> EcoreSimpleExampleModelFactoryImpl::create(ecore::EClass* _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}

std::shared_ptr<ecore::EObject> EcoreSimpleExampleModelFactoryImpl::create(std::string _className) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id);
    }

    return nullptr;
}

std::shared_ptr<ecore::EObject> EcoreSimpleExampleModelFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}


std::shared_ptr<Author> EcoreSimpleExampleModelFactoryImpl::createAuthor() const
{
	std::shared_ptr<Author> element(new AuthorImpl());
	return element;
}
std::shared_ptr<Book> EcoreSimpleExampleModelFactoryImpl::createBook() const
{
	std::shared_ptr<Book> element(new BookImpl());
	return element;
}
std::shared_ptr<Book> EcoreSimpleExampleModelFactoryImpl::createBook_in_Library(std::weak_ptr<ecoreSimpleExampleModel::LibraryModel > par_library) const
{
	std::shared_ptr<Book> element(new BookImpl(par_library));
	if(auto wp = par_library.lock())
	{
    		wp->getBook()->push_back(element);
	}
	return element;
}

std::shared_ptr<LibraryModel> EcoreSimpleExampleModelFactoryImpl::createLibraryModel() const
{
	std::shared_ptr<LibraryModel> element(new LibraryModelImpl());
	return element;
}
std::shared_ptr<NamedElement> EcoreSimpleExampleModelFactoryImpl::createNamedElement() const
{
	std::shared_ptr<NamedElement> element(new NamedElementImpl());
	return element;
}

std::shared_ptr<EcoreSimpleExampleModelPackage> EcoreSimpleExampleModelFactoryImpl::getEcoreSimpleExampleModelPackage() const
{
	return EcoreSimpleExampleModelPackage::eInstance();
}
