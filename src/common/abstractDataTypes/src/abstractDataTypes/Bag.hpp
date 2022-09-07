/*
 * Set.h
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef ABSTRACTDATATPYES_BAG_HPP
#define ABSTRACTDATATPYES_BAG_HPP

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class Bag
{
	protected:
		std::vector<std::shared_ptr<T> > m_bag;

	public:
		typedef typename std::vector<std::shared_ptr<T> >::iterator iterator;

		Bag()
		{
		}

		Bag(const Bag<T> &b)
		{
			insert(b);
		}

		virtual ~Bag()
		{
			clear();
		}

		Bag<T> * copy() const
		{
			return new Bag<T>(*this);
		}

		void insert(const Bag<T> &b)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			for (auto i = b.cbegin(); i != b.cend(); i++)
			{
				if (find(*i) > -1)
				{
					//	DEBUG_WARNING("Element " << *i << " already present.")
				}
			}
#endif
			m_bag.insert(m_bag.cend(), b.cbegin(), b.cend());
		}

		void insert(iterator a, iterator b, iterator c)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			for (auto i = b; i != c; i++)
			{
				if (find(*i) > -1)
				{
					//	DEBUG_WARNING("Element " << *i << " already present.")
				}
			}
#endif
			m_bag.insert(a, b, c);
		}

		void insert(iterator a, std::shared_ptr<T> b)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			int i = find(b);

			if (i > -1)
			{
				//	DEBUG_WARNING("Element " << *i << " already present.")
			}
#endif
			m_bag.insert(a, b);
		}

		bool empty()
		{
			return m_bag.empty();
		}

		std::shared_ptr<T> front()
		{
			return m_bag.front();
		}

		void clear()
		{
			const unsigned int size = m_bag.size();
			for (unsigned int i = 0; i < size; i++)
			{
				m_bag[i].reset();
			}
			m_bag.clear();
		}

		unsigned int size() const
		{
			return m_bag.size();
		}

		unsigned int max_size() const
		{
			return m_bag.max_size();
		}

		const std::shared_ptr<T> operator [] (unsigned int n) const
		{
			return m_bag[n];
		}

		const std::shared_ptr<T> at(unsigned int n) const
		{
#ifndef NDEBUG
			if (n < m_bag.size())
			{
#endif
				return m_bag[n];
#ifndef NDEBUG
			}
			throw std::invalid_argument("Bag.hpp: index out of range");
#endif
		}

		virtual void add(std::shared_ptr<T> el)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			if (find(el) > -1)
			{
				//	DEBUG_WARNING("Element " << el << " already present.")
			}
#endif
			m_bag.push_back(el);
		}

		virtual void add(std::shared_ptr<T> el, int index)
		{
			if(index < 0)
			{
				add(el);
			}
			else
			{
				insert(begin() + index, el);
			}
		}

		virtual void push_back(std::shared_ptr<T> el)
		{
			add(el);
		}

		virtual void erase(iterator el)
		{
			m_bag.erase(el);
		}

		virtual void erase(std::shared_ptr<T> el)
		{
			int res = find(el);

			if (res < 0)
			{
				return;
			}
			m_bag.erase(m_bag.begin() + res);
		}

		int find(std::shared_ptr<T> el)
		{
			const int size = m_bag.size();

			if (size == 0)
			{
				return -1;
			}
			volatile bool found = false;
			int first_index     = -1;
			int iteration       = 0;
			int my_index = -1;
			int i;

			do
			{
				{
					i = iteration++;
				}

				if (i < size && m_bag[i] == el)
				{
					found    = true;
					my_index = i;
				}
			}
			while (!found && i < size);

			if (my_index != -1)
			{
				if (first_index == -1 || my_index < first_index)
				{
					first_index = my_index;
				}
			}
			return first_index;
		} // find

		template <class U>
		Bag(Bag<U> const &u)
		{
			this->m_bag = u.m_bag;
		}

		typedef typename std::vector<std::shared_ptr<T> >::const_iterator const_iterator;

		virtual const_iterator cbegin() const
		{
			return m_bag.cbegin();
		}

		virtual const_iterator cend() const
		{
			return m_bag.cend();
		}

		virtual iterator begin()
		{
			return m_bag.begin();
		}

		virtual iterator end()
		{
			return m_bag.end();
		}
};

#endif
