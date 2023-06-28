//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTINPUTCHANNEL_TEXTINPUTCHANNELIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTINPUTCHANNEL_TEXTINPUTCHANNELIMPL_HPP

//Model includes
#include "../TextInputChannel.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/InputChannelImpl.hpp"

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
	class TextInputChannelImpl:virtual public InputChannelImpl, virtual public TextInputChannel
	{
		public: 
			TextInputChannelImpl(const TextInputChannelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			TextInputChannelImpl& operator=(TextInputChannelImpl const&);

		protected:
			friend class BasicInputOutputFactoryImpl;
			//constructor
			TextInputChannelImpl();
			virtual std::shared_ptr<TextInputChannel> getThisTextInputChannelPtr();
			virtual void setThisTextInputChannelPtr(std::weak_ptr<TextInputChannel> thisTextInputChannelPtr);


		public:

			//destructor
			virtual ~TextInputChannelImpl();

			//*********************************
			// Operations
			//*********************************
			//Methods defined by Operations
			virtual std::string peekCharacter(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual bool readBoolean(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual std::string readCharacter(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual int readInteger(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual std::string readLine(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual double readReal(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;
			virtual int readUnlimitedNatural(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) ;

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
			virtual void set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value) ;
			virtual void set(std::string _qualifiedName, const std::shared_ptr<Any>& value) ;
			virtual void set(unsigned long _uID, const std::shared_ptr<Any>& value) ;
			//Add
			virtual void add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual void add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			virtual void add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt = -1) ;
			//Unset
			virtual void unset(const std::shared_ptr<uml::Property>& _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
			//Remove
			virtual void remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value) ;
			virtual void remove(std::string _qualifiedName, const std::shared_ptr<Any>& value) ;
			virtual void remove(unsigned long _uID, const std::shared_ptr<Any>& value) ;
		
			//**************************************
			// Operation & OpaqueBehavior Invocation
			//**************************************
			//Operation invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			virtual std::shared_ptr<Any> invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;
			
			//OpaqueBehavior invocation
			virtual std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments) ;

		private:
			std::weak_ptr<TextInputChannel> m_thisTextInputChannelPtr;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTINPUTCHANNEL_TEXTINPUTCHANNELIMPL_HPP */
