/*
 * Subset.hpp
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef SUBSET_HPP_
#define SUBSET_HPP_

#include <memory>
#include <vector>
#include <utility>
#include "Bag.hpp"

template<class T, class ... U>
class Subset : virtual public Bag<T> {

protected:
std::tuple<std::shared_ptr<Union<U> > ...> tuple_;

public:

typedef typename std::vector<std::shared_ptr<T> >::iterator iterator;

Subset() : Bag<T>(){

}

Subset(std::shared_ptr<Union<U> > ... v) :
        Bag<T>() {
        initSubset(v ...);
}

void initSubset(std::shared_ptr<Union<U> > ... v){
        tuple_ = std::tuple<std::shared_ptr<Union<U> > ...>(v ...);
}

virtual void push_back(std::shared_ptr<T> el) {
        add(el);
}

virtual void add(std::shared_ptr<T> el) {
        Bag<T>::add(el);
        call_addEl_with_tuple(el, tuple_, std::index_sequence_for<std::shared_ptr<Union<U> > ...>());

}

void insert(const Bag<T> &b){
        insert(this->m_bag.cend(), b.cbegin(), b.cend());
}

void insert(iterator a, iterator b, iterator c){
        Bag<T>::insert(a, b, c);
        call_insert3El_with_tuple(a,b,c,tuple_, std::index_sequence_for<std::shared_ptr<Union<U> > ...>());
}

void insert(iterator a, std::shared_ptr<T> b){
        Bag<T>::insert(a, b);
        call_insertElPointer_with_tuple(a,b,tuple_, std::index_sequence_for<std::shared_ptr<Union<U> > ...>());
}

virtual void erase(iterator el)
{
        erase(*el);
}


virtual void erase(std::shared_ptr<T> el) {
        Bag<T>::erase(el);
        call_deleteEl_with_tuple(el, tuple_, std::index_sequence_for<std::shared_ptr<Union<U> > ...>());
}

virtual ~Subset() {
        unsigned int i = 0;
        unsigned int size = this->m_bag.size();
        for (i = 0; i < size; i++) {
                erase(this->m_bag[i]);
        }
}

protected:

/// ADD ///
//The helper call add method.
template<std::size_t ... Is>
void call_addEl_with_tuple(std::shared_ptr<T> el, const std::tuple<std::shared_ptr<Union<U> > ...> &tuple,
                           std::index_sequence<Is ...>) {
        addElRecursive(el, std::get<Is>(tuple) ...);
}

template<class FirstU, class ... RestU>
void addElRecursive(std::shared_ptr<T> el, std::shared_ptr<Union<FirstU> > obj, std::shared_ptr<Union<RestU> > ... rest) {
        addElRecursive(el, rest ...);
        obj->add(el);
}

template<class FirstU, class ... RestU>
void addElRecursive(std::shared_ptr<T> el, std::shared_ptr<Union<FirstU> > obj) {
        obj->add(el);
}

/// delete ///

template<std::size_t ... Is>
void call_deleteEl_with_tuple(std::shared_ptr<T> el, const std::tuple<std::shared_ptr<Union<U> > ...> &tuple,
                              std::index_sequence<Is ...>) {
        deleteElRecursive(el, std::get<Is>(tuple) ...);
}

template<class FirstU, class ... RestU>
void deleteElRecursive(std::shared_ptr<T> el, std::shared_ptr<Union<FirstU> > obj, std::shared_ptr<Union<RestU> > ... rest) {
        deleteElRecursive(el, rest ...);
        obj->erase(el);
}

template<class FirstU, class ... RestU>
void deleteElRecursive(std::shared_ptr<T> el, std::shared_ptr<Union<FirstU> > obj) {
        if(nullptr == obj)
                return;
        obj->erase(el);
}

/// insert iterator and pointer  ///

// void insert(iterator a, std::shared_ptr<T> b){
//         m_bag.insert(a, b);
// }

template<std::size_t ... Is>
void call_insertElPointer_with_tuple(iterator it, std::shared_ptr<T> el, const std::tuple<std::shared_ptr<Union<U> > ...> &tuple,
                                     std::index_sequence<Is ...>) {
        insertElPointerRecursive(it, el, std::get<Is>(tuple) ...);
}

template<class FirstU, class ... RestU>
void insertElPointerRecursive(iterator it, std::shared_ptr<T> el, std::shared_ptr<Union<FirstU> > obj, std::shared_ptr<Union<RestU> > ... rest) {
        insertElPointerRecursive(it, el, rest ...);
        obj->insert(it, el);
}

template<class FirstU, class ... RestU>
void insertElPointerRecursive(iterator it, std::shared_ptr<T> el, std::shared_ptr<Union<FirstU> > obj) {
        obj->insert(it, el);
}

/// insert 3 iterators  ///

// void insert(iterator a, iterator b, iterator c){
//         m_bag.insert(a, b, c);
// }

template<std::size_t ... Is>
void call_insert3El_with_tuple(iterator position, iterator first, iterator last, const std::tuple<std::shared_ptr<Union<U> > ...> &tuple,
                               std::index_sequence<Is ...>) {
        insert3ElRecursive(position, first, last, std::get<Is>(tuple) ...);
}

template<class FirstU, class ... RestU>
void insert3ElRecursive(iterator position, iterator first, iterator last, std::shared_ptr<Union<FirstU> > obj, std::shared_ptr<Union<RestU> > ... rest) {
        insert3ElRecursive(position, first, last, rest ...);
        obj->insert(position, first, last);
}

template<class FirstU, class ... RestU>
void insert3ElRecursive(iterator position, iterator first, iterator last, std::shared_ptr<Union<FirstU> > obj) {
        obj->insert(position, first, last);
}



};

#endif /* SUBSET_HPP_ */
