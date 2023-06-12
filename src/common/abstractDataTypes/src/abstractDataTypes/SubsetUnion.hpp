/*
 * SubsetUnion.hpp
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef ABSTRACTDATATPYES_SUBSETUNION_HPP
#define ABSTRACTDATATPYES_SUBSETUNION_HPP

#include <memory>
#include <vector>
#include <iostream>

#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"

template<class T, class ... U>
class SubsetUnion : public Subset<T, U ...>, public Union<T>
{
	public:
		SubsetUnion() : Subset<T, U ...>(), Union<T>()
		{
		}

		SubsetUnion(const std::shared_ptr<Union<U>>& ... u) :
			Subset<T, U ...>(u ...), Union<T>()
		{
		}

		void initSubsetUnion(const std::shared_ptr<Union<U>>& ... u)
		{
			Subset<T,U ... >::initSubset(u ...);
		}

		typedef typename std::vector<std::shared_ptr<T>>::iterator iterator;

		virtual ~SubsetUnion()
		{
		}

		virtual void push_back(const std::shared_ptr<T>& el)
		{
			this->add(el);
		}

		virtual void add(const std::shared_ptr<T>& el)
		{
			Subset<T, U ...>::add(el);
		}

		iterator insert(const Bag<T>& b)
		{
			return Subset<T, U ...>::insert(b);
		}

		iterator insert(iterator a, iterator b, iterator c)
		{
			return Subset<T, U ...>::insert(a, b, c);
		}

		iterator insert(iterator a, const std::shared_ptr<T>& b)
		{
			return Subset<T, U ...>::insert(a, b);
		}

		virtual iterator erase(const std::shared_ptr<T>& el)
		{
			return Subset<T, U ...>::erase(el);
		}
};

#endif
