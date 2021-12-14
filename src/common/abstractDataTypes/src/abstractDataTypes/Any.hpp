#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>

class AnyObject
{
	public:
		template <typename T>
		AnyObject(T value,long long typeID=0, bool isContainer=false):m_typeID(typeID), m_isContainer(isContainer)
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
			throw "Any::get - cast failed";
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

		long long getTypeId()
		{
			return m_typeID;
		}

		bool isContainer()
		{
			return m_isContainer;
		}

	protected:
		const long long m_typeID=0;
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

template <typename T> static Any eAny(T value,long long typeID, bool isContainer)
{
	Any any(new AnyObject(value,typeID,isContainer));
	return any;
}

#endif
