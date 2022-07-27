#ifndef ABSTRACTDATATPYES_ANY_HPP
#define ABSTRACTDATATPYES_ANY_HPP

#include <memory>
#include <stdexcept>

class AnyObject
{
	public:
		template <typename T>
		AnyObject(T value, long typeID=0, bool isContainer=false):m_typeID(typeID), m_isContainer(isContainer)
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

		virtual ~AnyObject()
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

		long getTypeId()
		{
			return m_typeID;
		}

		bool isContainer()
		{
			return m_isContainer;
		}

	protected:
		const long m_typeID=0;
		const bool m_isContainer=false;
		AnyObject(){}
		class Object
		{
			public:
				virtual ~Object()
				{
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
			private:
				T m_value;

		};

		Object* m_object;
};

typedef std::shared_ptr<AnyObject> Any;

template <typename T> static Any eAny(T value,long typeID, bool isContainer)
{
	Any any(new AnyObject(value,typeID,isContainer));
	return any;
}

#endif
