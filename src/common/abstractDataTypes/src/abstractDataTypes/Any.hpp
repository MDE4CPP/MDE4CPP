#ifndef ABSTRACTDATATPYES_ANY_HPP
#define ABSTRACTDATATPYES_ANY_HPP

#include <memory>
#include <stdexcept>
#include <typeinfo>

class Any
{
	public:
		template <typename T>
		Any(T value,long long typeID=0, bool isContainer=false):m_typeID(typeID), m_isContainer(isContainer)
		{
			m_object = new TypedObject<T>(value);
		}

		template <typename T>
		T get()
		{
			TypedObject<T>* obj = dynamic_cast<TypedObject<T>*>(m_object);
			if (obj)
			{
				return obj->get();
			}
			throw std::runtime_error("Any::get() : Bad cast");
		}

		virtual ~Any()
		{
			if (m_object != nullptr)
			{
				delete(m_object);
			}
		}

		virtual bool isEmpty()
		{
			return m_object == nullptr;
		}

		long long getTypeId()
		{
			return m_typeID;
		}

		bool isContainer()
		{
			return m_isContainer;
		}
		
		std::string toString()
		{
			if(this->isEmpty())
			{
				return "nullptr";
			}
			
			std::string retString = "typeName: "
									+ m_object->getTypeIDName()
									+ " ; "
									+ "typeID: "
									+ std::to_string(m_typeID)
									+ " ; "
									+ "isContainer: "
									+ ((m_isContainer) ? "true" : "false");
									
			return retString;
		}

	protected:
		const long long m_typeID=0;
		const bool m_isContainer=false;
		Any(){}
		class Object
		{
			public:
				virtual ~Object()
				{
				}
				
				virtual std::string getTypeIDName()
				{
					return "NULL";
				}
		};

		template <class T>
		class TypedObject: public Object
		{
			public:
				TypedObject(T value)
				{
					m_value = value;
				}

				virtual ~TypedObject()
				{
				}

				T get()
				{
					return m_value;
				}

				void set(T value)
				{
					m_value=value;
				}
				
				std::string getTypeIDName()
				{
					return typeid(T).name();
				}
				
			private:
				T m_value;

		};

		Object* m_object;
};

template <typename T> static std::shared_ptr<Any> eAny(T value,long long typeID, bool isContainer)
{
	std::shared_ptr<Any> any(new Any(value,typeID,isContainer));
	return any;
}

#endif
