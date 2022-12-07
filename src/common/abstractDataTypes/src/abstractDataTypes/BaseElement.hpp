#ifndef ABSTRACTDATATPYES_BASEELEMENT_HPP
#define ABSTRACTDATATPYES_BASEELEMENT_HPP

#include <string>

class BaseElement
{
	public:
		virtual ~BaseElement() = 0;
		
		
		unsigned long _getID() const noexcept;
		void _setID(unsigned long) noexcept;
		
	private:
		unsigned long m_id = -1;
};

inline BaseElement::~BaseElement(){}

inline unsigned long BaseElement::_getID() const noexcept
{
	return m_id;
}

inline void BaseElement::_setID(unsigned long _id) noexcept
{
	m_id = _id;
}

#endif
