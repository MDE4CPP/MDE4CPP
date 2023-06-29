/*
 * Union.hpp
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef ABSTRACTDATATPYES_UNION_HPP
#define ABSTRACTDATATPYES_UNION_HPP

#include <memory>
#include <vector>
#include "abstractDataTypes/Bag.hpp"

template<class T>
class Union : virtual public Bag<T>
{
	public:
		Union()
		{
		}

		template<class U>
		Union(const Union<U>& u)
		{
			this->m_bag = std::dynamic_pointer_cast<std::vector<std::shared_ptr<T>>>(u.m_bag);
		}

		virtual ~Union()
		{
		}
};

#endif
