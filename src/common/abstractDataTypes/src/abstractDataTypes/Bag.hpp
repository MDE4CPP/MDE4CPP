/*
 * Bag.h
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

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template <class T>
class Bag
{
	protected:
		std::vector<std::shared_ptr<T>> m_bag;

	public:
		typedef typename std::vector<std::shared_ptr<T>>::iterator iterator;

		Bag()
		{
		}

		Bag(const Bag<T>& b)
		{
			insert(b);
		}

		virtual ~Bag()
		{
			this->clear();
		}

		Bag<T> * copy() const
		{
			return new Bag<T>(*this);
		}

		iterator insert(const Bag<T>& b)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			for (auto i = b.cbegin(); i != b.cend(); i++)
			{
				if (this->includes(*i))
				{
					//	DEBUG_WARNING("Element " << *i << " already present.")
				}
			}
#endif
			return m_bag.insert(m_bag.cend(), b.cbegin(), b.cend());
		}

		iterator insert(iterator a, iterator b, iterator c)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			for (auto i = b; i != c; i++)
			{
				if (this->includes(*i))
				{
					//	DEBUG_WARNING("Element " << *i << " already present.")
				}
			}
#endif
			return m_bag.insert(a, b, c);
		}

		iterator insert(iterator a, const std::shared_ptr<T>& b)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.

			if (this->includes(b))
			{
				//	DEBUG_WARNING("Element " << b << " already present.")
			}
#endif
			return m_bag.insert(a, b);
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

		const std::shared_ptr<T>& operator [] (unsigned int n) const
		{
			return m_bag[n];
		}

		const std::shared_ptr<T>& at(unsigned int n) const
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

		virtual void add(const std::shared_ptr<T>& el)
		{
#ifndef NDEBUG
			// The debug version check if an inserted element is already present in the collection.
			if (this->includes(el))
			{
				//	DEBUG_WARNING("Element " << el << " already present.")
			}
#endif
			m_bag.push_back(el);
		}

		virtual void add(const std::shared_ptr<T>& el, int index)
		{
			if(index < 0)
			{
				this->add(el);
			}
			else
			{
				this->insert(begin() + index, el);
			}
		}

		virtual void push_back(const std::shared_ptr<T>& el)
		{
			m_bag.push_back(el);
		}

		iterator erase(iterator el)
		{
			// Calling erase on an empty std::vector results in segmentation fault
			if(!m_bag.empty())
			{
				return m_bag.erase(el);
			}
			
			return m_bag.end();
		}

		virtual iterator erase(const std::shared_ptr<T>& el)
		{
			iterator it = std::find(m_bag.begin(), m_bag.end(), el);
			
			// Calling erase on an empty std::vector results in segmentation fault
			if(!m_bag.empty())
			{
				return m_bag.erase(it);
			}

			return it;
		}

		iterator find(const std::shared_ptr<T>& el)
		{
			return std::find(m_bag.begin(), m_bag.end(), el);
		} // find

		bool includes(const std::shared_ptr<T>& el)
		{
			return (find(el) != m_bag.end());
		}

		int index_of(const std::shared_ptr<T>& el)
		{
			return index_of(find(el));
		}

		int index_of(iterator it)
		{
			if(it != m_bag.end())
			{
				return (it - m_bag.begin());
			}

			return -1;
		}

		template <class U>
		Bag(Bag<U> const &u)
		{
			m_bag = u.m_bag;
		}

		typedef typename std::vector<std::shared_ptr<T>>::const_iterator const_iterator;

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
