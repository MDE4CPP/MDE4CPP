/*
 * Set.h
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef BAG_HPP_
#define BAG_HPP_

#include <memory>
#include <vector>

template<class T> class Bag
{
protected:
	std::vector<std::shared_ptr<T> > m_bag;
public:
	Bag()
	{
	}

	Bag(const Bag<T>& b)
	{
		m_bag(std::vector<std::shared_ptr<T> >(b));
	}

	virtual ~Bag()
	{
		clear();
	}

	void clear()
	{
		unsigned size = m_bag.size();
#pragma omp parallel for
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

	const std::shared_ptr<T> operator[](unsigned int n) const
	{
		return m_bag[n];
	}

	virtual void add(std::shared_ptr<T> el)
	{
		m_bag.push_back(el);
	}

	virtual void erase(std::shared_ptr<T> el)
	{
		int res = find(el);
		if (res < 0)
		{
			std::cout << "Element not found" << std::endl;
			return;
		}
		m_bag.erase(m_bag.begin() + res);
	}

	int find(std::shared_ptr<T> el)
	{
		int size = m_bag.size();
		volatile bool found = false;
		int first_index = -1;
		int iteration = 0;

#pragma omp parallel //if(size >=40)
		{
			int my_index = -1;
			int i;

			do
			{
#pragma omp critical(iteration)
				{
					i = iteration++;
				}

				if (i < size && m_bag[i] == el)
				{
					found = true;
					my_index = i;
				}
			} while (!found && i < size);

#pragma omp critical(reduction)
			if (my_index != -1)
			{
				if (first_index == -1 || my_index < first_index)
					first_index = my_index;
			}
		}
		return first_index;
	}

	template<class U> Bag(Bag<U> const & u)
	{
		this->m_bag = u.m_bag;
	}

	typedef typename std::vector<std::shared_ptr<T> >::const_iterator const_iterator;

	virtual const_iterator begin()
	{
		return m_bag.begin();
	}

	virtual const_iterator end()
	{
		return m_bag.end();
	}

protected:
	typedef typename std::vector<std::shared_ptr<T> >::iterator iterator;

};

#endif /* BAG_HPP_ */
