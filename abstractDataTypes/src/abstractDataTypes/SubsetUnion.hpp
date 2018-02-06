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

		SubsetUnion(std::shared_ptr<Union<U> > ... u) :
			Subset<T, U ...>(u ...), Union<T>()
		{
		}

		void initSubsetUnion(std::shared_ptr<Union<U> > ... u)
		{
			Subset<T,U ... >::initSubset(u ...);
		}

		typedef typename std::vector<std::shared_ptr<T> >::iterator iterator;

		virtual ~SubsetUnion()
		{
		}

		virtual void push_back(std::shared_ptr<T> el)
		{
			add(el);
		}

		virtual void add(std::shared_ptr<T> el)
		{
			Subset<T, U ...>::add(el);
		}

		void insert(const Bag<T> &b)
		{
			Subset<T, U ...>::insert(b);
		}

		void insert(iterator a, iterator b, iterator c)
		{
			Subset<T, U ...>::insert(a, b, c);
		}

		void insert(iterator a, std::shared_ptr<T> b)
		{
			Subset<T, U ...>::insert(a, b);
		}

		virtual void erase(std::shared_ptr<T> el)
		{
			Subset<T, U ...>::erase(el);
		}
};

#endif
