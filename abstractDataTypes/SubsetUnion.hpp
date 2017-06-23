/*
 * SubsetUnion.hpp
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef SUBSETUNION_HPP_
#define SUBSETUNION_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include "Union.hpp"
#include "Subset.hpp"

template<class T, class ...U>
class SubsetUnion : public Subset<T, U...>, public Union<T>
{

private:
  SubsetUnion()
  {
  }
public:

    SubsetUnion(std::shared_ptr<Union<U> > ...u) :
            Subset<T, U...>(u...), Union<T>()
    {
    }



    virtual ~SubsetUnion()
    {
        std::cout << "SubsetUnion: ~~~~~~~~~~~~~~~~~" << std::endl;
    }

    virtual void add(std::shared_ptr<T> el)
    {

        Subset<T, U...>::add(el);

    }

    virtual void erase(std::shared_ptr<T> el)
    {
        Subset<T, U...>::erase(el);
    }

};


#endif /* SUBSETUNION_HPP_ */
