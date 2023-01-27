//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_ACTIVECHANNEL_ACTIVECHANNELIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_ACTIVECHANNEL_ACTIVECHANNELIMPL_HPP

//Model includes
#include "../ActiveChannel.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/ChannelImpl.hpp"

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
	class ActiveChannelImpl:virtual public ChannelImpl, virtual public ActiveChannel
	{
		public: 
			ActiveChannelImpl(const ActiveChannelImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ActiveChannelImpl& operator=(ActiveChannelImpl const&);

		protected:
			friend class BasicInputOutputFactoryImpl;
			//constructor
			ActiveChannelImpl();
			virtual std::shared_ptr<ActiveChannel> getThisActiveChannelPtr();
			virtual void setThisActiveChannelPtr(std::weak_ptr<ActiveChannel> thisActiveChannelPtr);


		public:

			//destructor
			virtual ~ActiveChannelImpl();

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
			virtual std::shared_ptr<Any> get(std::shared_ptr<uml::Property> _property) const ;
			virtual std::shared_ptr<Any> get(std::string _qualifiedName) const ;
			virtual std::shared_ptr<Any> get(unsigned long _uID) const ;
			//Set
			virtual void set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value) ;
			virtual void set(std::string _qualifiedName, std::shared_ptr<Any> value) ;
			virtual void set(unsigned long _uID, std::shared_ptr<Any> value) ;
			//Add
			virtual void add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt = -1) ;
			virtual void add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt = -1) ;
			virtual void add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt = -1) ;
			//Unset
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
			//Remove
			virtual void remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value) ;
			virtual void remove(std::string _qualifiedName, std::shared_ptr<Any> value) ;
			virtual void remove(unsigned long _uID, std::shared_ptr<Any> value) ;
		
			//**************************************
			// Operation & OpaqueBehavior Invocation
			//**************************************
			//Operation invocation
			virtual std::shared_ptr<Any> invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments) ;
			virtual std::shared_ptr<Any> invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments) ;
			virtual std::shared_ptr<Any> invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments) ;
			
			//OpaqueBehavior invocation
			virtual std::shared_ptr<Any> invoke(std::shared_ptr<uml::OpaqueBehavior> _opaqueBehavior, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments) ;

		private:
			std::weak_ptr<ActiveChannel> m_thisActiveChannelPtr;
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_ACTIVECHANNEL_ACTIVECHANNELIMPL_HPP */
