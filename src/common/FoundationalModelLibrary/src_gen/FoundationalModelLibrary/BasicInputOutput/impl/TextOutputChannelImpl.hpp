//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTOUTPUTCHANNEL_TEXTOUTPUTCHANNELIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTOUTPUTCHANNEL_TEXTOUTPUTCHANNELIMPL_HPP

//Model includes
#include "../TextOutputChannel.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/OutputChannelImpl.hpp"

class Any;

namespace uml
{
	class Property;
	class Operation;
	class OpaqueBehavior;
}

//*********************************
namespace FoundationalModelLibrary::BasicInputOutput
{
	class TextOutputChannelImpl:virtual public OutputChannelImpl, virtual public TextOutputChannel
	{
		public: 
			TextOutputChannelImpl(const TextOutputChannelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			TextOutputChannelImpl& operator=(TextOutputChannelImpl const&);

		protected:
			friend class BasicInputOutputFactoryImpl;
			//constructor
			TextOutputChannelImpl();
			virtual std::shared_ptr<TextOutputChannel> getThisTextOutputChannelPtr();
			virtual void setThisTextOutputChannelPtr(std::weak_ptr<TextOutputChannel> thisTextOutputChannelPtr);


		public:

			//destructor
			virtual ~TextOutputChannelImpl();

			//*********************************
			// Operations
			//*********************************
			//Methods defined by Operations
			virtual void writeBoolean(bool value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual void writeInteger(int value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual void writeLine(std::string value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual void writeNewLine(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual void writeReal(double value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual void writeString(std::string value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual void writeUnlimitedNatural(int value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;

			// fUML-specific Operations
			const std::shared_ptr<Bag<uml::Classifier>>& getTypes() const;

			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual const std::shared_ptr<uml::Class>& getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();

		public:
			//**************************************
			// StructuralFeature Getter & Setter
			//**************************************
			//Get
			virtual std::shared_ptr<Any> get(const std::shared_ptr<uml::Property>& _property) const ;
			virtual std::shared_ptr<Any> get(std::string _qualifiedName) const ;
			virtual std::shared_ptr<Any> get(unsigned long _uID) const ;
			//Set
			virtual bool set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value) ;
			virtual bool set(std::string _qualifiedName, const std::shared_ptr<Any>& value) ;
			virtual bool set(unsigned long _uID, const std::shared_ptr<Any>& value) ;
			//Add
			virtual bool add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual bool add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual bool add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			//Unset
			virtual bool unset(const std::shared_ptr<uml::Property>& _property) ;
			virtual bool unset(std::string _qualifiedName) ;
			virtual bool unset(unsigned long _uID) ;
			//Remove
			virtual bool remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt = -1, bool isRemoveDuplicates = false) ;
			virtual bool remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt = -1, bool isRemoveDuplicates = false) ;
			virtual bool remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt = -1, bool isRemoveDuplicates = false) ;
		
			//**************************************
			// Operation & OpaqueBehavior Invocation
			//**************************************
			//Operation invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			
			//OpaqueBehavior invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;

		private:
			std::weak_ptr<TextOutputChannel> m_thisTextOutputChannelPtr;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTOUTPUTCHANNEL_TEXTOUTPUTCHANNELIMPL_HPP */
