//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_CHANNEL_CHANNELIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_CHANNEL_CHANNELIMPL_HPP

//Model includes
#include "../Channel.hpp"
#include "fUML/MDE4CPP_Extensions/impl/FUML_ObjectImpl.hpp"

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
	class ChannelImpl : virtual public fUML::MDE4CPP_Extensions::FUML_ObjectImpl, virtual public Channel
	{
		public: 
			ChannelImpl(const ChannelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ChannelImpl& operator=(ChannelImpl const&);

		protected:
			friend class BasicInputOutputFactoryImpl;
			//constructor
			ChannelImpl();
			virtual std::shared_ptr<Channel> getThisChannelPtr();
			virtual void setThisChannelPtr(std::weak_ptr<Channel> thisChannelPtr);


		public:

			//destructor
			virtual ~ChannelImpl();

			//*********************************
			// Operations
			//*********************************
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass() const;
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
			std::weak_ptr<Channel> m_thisChannelPtr;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_CHANNEL_CHANNELIMPL_HPP */
