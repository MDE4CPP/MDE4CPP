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
#include <iostream>
#include <stdexcept>
#include <omp.h>


template<class T>
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

Bag<T>*  copy() const {
        return new Bag<T>(*this);
}

void insert(const Bag<T> &b){
        m_bag.insert(m_bag.cend(), b.cbegin(), b.cend());
}

void insert(iterator a, iterator b, iterator c){
        m_bag.insert(a, b, c);
}

void insert(iterator a, std::shared_ptr<T> b){
        m_bag.insert(a, b);
}

bool empty(){
        return m_bag.empty();
}

std::shared_ptr<T> front ()
{
        return m_bag.front();
}

void clear()
{
        unsigned size = m_bag.size();
//#pragma omp parallel for (private i)
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

const std::shared_ptr<T> at(unsigned int n) const
{
        if(n < m_bag.size())
                return m_bag[n];
        throw std::invalid_argument( "Bag.hpp: index out of range" );
}


virtual void add(std::shared_ptr<T> el)
{
        m_bag.push_back(el);
}

virtual void push_back(std::shared_ptr<T> el)
{
        m_bag.push_back(el);
}

virtual void erase(iterator el)
{
        //TODO
        m_bag.erase(el);
        //m_bag.erase(m_bag.begin() + res);
}


virtual void erase(std::shared_ptr<T> el)
{
        int res = find(el);
        if(res < 0)
        {
                std::cout << "Element not found" << std::endl;
                return;
        }
        //TODO?
        //m_bag.erase(m_bag.begin() + res);
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

                        if(i < size && m_bag[i] == el)
                        {
                                found = true;
                                my_index = i;
                        }
                }
                while (!found && i < size);

#pragma omp critical(reduction)
                if(my_index != -1)
                {
                        if(first_index == -1 || my_index < first_index)
                                first_index = my_index;
                }
        }
        return first_index;
}

template<class U>
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

#endif /* BAG_HPP_ */
