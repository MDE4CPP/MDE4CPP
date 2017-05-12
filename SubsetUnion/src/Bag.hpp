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
		std::cout << "Union ~~~~~~~~~~" << std::endl;
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
		unsigned size = m_bag.size();

		//TODO: better parallelization without for (break all loops after erase), or remove parallel
		volatile bool continueLoop=true;
		unsigned int i =0;
#pragma omp parallel for private(i)
		for (i=0; i < size; i++)
		{
			if(continueLoop){
				continue;
			}
			if (m_bag[i] == el)
			{
#pragma omp critical
			{
				std::cout << "Bag: ERASE position" << i << std::endl;
				m_bag.erase(m_bag.begin() + i);
				continueLoop=false;
			}
			}
		}
	}
	template<class U> Bag(Bag<U> const & u)
	{
		this->m_bag = std::dynamic_pointer_cast<std::vector<std::shared_ptr<T> > >(u.m_bag);
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
