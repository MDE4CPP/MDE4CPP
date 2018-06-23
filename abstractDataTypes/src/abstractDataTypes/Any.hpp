#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>

class AnyObject
{
	public:
		template <typename T>
		AnyObject(T value)
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

	private:
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

			private:
				T m_value;
		};

		Object* m_object;
};

typedef std::shared_ptr<AnyObject> Any;

template <typename T>
static Any eAny(T value)
{
	Any any(new AnyObject(value));
	return any;
}

#endif
