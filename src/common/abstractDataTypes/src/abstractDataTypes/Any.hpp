#ifndef ABSTRACTDATATPYES_ANY_HPP
#define ABSTRACTDATATPYES_ANY_HPP

#include <memory>
#include <stdexcept>
#include <typeinfo>

class Any
{
	public:
		template <typename T>
		Any(T, unsigned long typeID = 0, bool isContainer = false);
		virtual ~Any();

		template <typename T>
		T get() const;
		bool isEmpty() const;
		unsigned long getTypeId() const;
		bool isContainer() const;
		std::string toString() const;

	protected:
		Any() = default;
		
		class Object
		{
			public:
				virtual ~Object() = default;
				
				virtual std::string getTypeIDName() const;
		};

		template <typename T>
		class TypedObject: public Object
		{
			public:
				TypedObject(T);
				virtual ~TypedObject() = default;

				T get() const;
				void set(T);
				std::string getTypeIDName() const final override;
				
			private:
				T m_value;

		};

		Object* m_object;
		const unsigned long m_typeID = 0;
		const bool m_isContainer = false;
};


template <typename T>
inline Any::Any(T value, unsigned long typeID, bool isContainer) : m_typeID(typeID), m_isContainer(isContainer)
{
	m_object = new TypedObject<T>(value);
}

inline Any::~Any()
{
	if (m_object != nullptr)
	{
		delete(m_object);
	}
}

template <typename T>
inline T Any::get() const
{
	TypedObject<T>* obj = dynamic_cast<TypedObject<T>*>(m_object);
	if (obj)
	{
		return obj->get();
	}
	throw std::runtime_error("Any::get() : Bad cast");
}

inline bool Any::isEmpty() const
{
	return (m_object == nullptr);
}

inline unsigned long Any::getTypeId() const
{
	return m_typeID;
}

inline bool Any::isContainer() const
{
	return m_isContainer;
}

inline std::string Any::toString() const
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

inline std::string Any::Object::getTypeIDName() const
{
	return "NULL";
}

template <typename T>
inline Any::TypedObject<T>::TypedObject(T value)
{
	m_value = value;
}

template <typename T>
inline T Any::TypedObject<T>::get() const
{
	return m_value;
}

template <typename T>
inline void Any::TypedObject<T>::set(T value)
{
	m_value=value;
}

template <typename T>
inline std::string Any::TypedObject<T>::getTypeIDName() const
{
	return typeid(T).name();
}


template <typename T> static std::shared_ptr<Any> eAny(T value, unsigned long typeID, bool isContainer)
{
	std::shared_ptr<Any> any(new Any(value, typeID, isContainer));
	return any;
}

#endif
