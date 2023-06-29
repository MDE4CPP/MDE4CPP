/*
 * Subset.hpp
 *
 *  Created on: 12.05.2017
 *      Author: frbe5612
 */

#ifndef ABSTRACTDATATPYES_SUBSET_HPP
#define ABSTRACTDATATPYES_SUBSET_HPP

#include <memory>
#include <vector>
#include <utility>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Union.hpp"

template<class T, class ... U>
class Subset : virtual public Bag<T>
{
	protected:
		std::tuple<std::shared_ptr<Union<U>> ...> tuple_;

	public:

		typedef typename std::vector<std::shared_ptr<T>>::iterator iterator;

		Subset() : Bag<T>()
		{
		}

		Subset(const std::shared_ptr<Union<U>>& ... v) :
			Bag<T>()
		{
			this->initSubset(v ...);
		}

		void initSubset(const std::shared_ptr<Union<U>>& ... v)
		{
			tuple_ = std::tuple<std::shared_ptr<Union<U> > ...>(v ...);
		}

		virtual void push_back(const std::shared_ptr<T>& el)
		{
			this->add(el);
		}

		virtual void add(const std::shared_ptr<T>& el)
		{
			Bag<T>::add(el);
			this->call_addEl_with_tuple(el, tuple_, std::index_sequence_for<std::shared_ptr<Union<U>> ...>());
		}

		iterator insert(const Bag<T>& b)
		{
			return insert(this->m_bag.cend(), b.cbegin(), b.cend());
		}

		iterator insert(iterator a, iterator b, iterator c)
		{
			iterator it = Bag<T>::insert(a, b, c);
			this->call_insert3El_with_tuple(a, b, c, tuple_, std::index_sequence_for<std::shared_ptr<Union<U>> ...>());
			return it;
		}

		iterator insert(iterator a, std::shared_ptr<T> b)
		{
			iterator it = Bag<T>::insert(a, b);
			this->call_insertElPointer_with_tuple(a, b, tuple_, std::index_sequence_for<std::shared_ptr<Union<U>> ...>());
			return it;
		}

		virtual iterator erase(iterator el)
		{
			return erase(*el);
		}


		virtual iterator erase(const std::shared_ptr<T>& el)
		{
			iterator it = Bag<T>::erase(el);
			this->call_deleteEl_with_tuple(el, tuple_, std::index_sequence_for<std::shared_ptr<Union<U>> ...>());
			return it;
		}

		virtual ~Subset()
		{
			unsigned int i = 0;
			unsigned int size = this->m_bag.size();
			for (i = 0; i < size; i++)
			{
                this->erase(this->m_bag[i]);
			}
		}

	protected:

		/// ADD ///
		//The helper call add method.
		template<std::size_t ... Is>
		void call_addEl_with_tuple(const std::shared_ptr<T>& el, const std::tuple<std::shared_ptr<Union<U>> ...>& tuple, std::index_sequence<Is ...>)
		{
			this->addElRecursive(el, std::get<Is>(tuple) ...);
		}

		template<class FirstU, class ... RestU>
		void addElRecursive(const std::shared_ptr<T>& el, const std::shared_ptr<Union<FirstU>>& obj, const std::shared_ptr<Union<RestU>>& ... rest)
		{
			this->addElRecursive(el, rest ...);
			obj->add(el);
		}

		template<class FirstU, class ... RestU>
		void addElRecursive(const std::shared_ptr<T>& el, const std::shared_ptr<Union<FirstU>>& obj)
		{
			obj->add(el);
		}

		/// delete ///
		template<std::size_t ... Is>
		void call_deleteEl_with_tuple(const std::shared_ptr<T>& el, const std::tuple<std::shared_ptr<Union<U>> ...>& tuple, std::index_sequence<Is ...>)
		{
			this->deleteElRecursive(el, std::get<Is>(tuple) ...);
		}

		template<class FirstU, class ... RestU>
		void deleteElRecursive(const std::shared_ptr<T>& el, const std::shared_ptr<Union<FirstU>>& obj, const std::shared_ptr<Union<RestU>>& ... rest)
		{
			this->deleteElRecursive(el, rest ...);
			obj->erase(el);
		}

		template<class FirstU, class ... RestU>
		void deleteElRecursive(const std::shared_ptr<T>& el, const std::shared_ptr<Union<FirstU>>& obj)
		{
			if(nullptr == obj)
            {
				return;
            }
			obj->erase(el);
		}

		template<std::size_t ... Is>
		void call_insertElPointer_with_tuple(iterator it, const std::shared_ptr<T>& el, const std::tuple<std::shared_ptr<Union<U>> ...>& tuple, std::index_sequence<Is ...>)
		{
			this->insertElPointerRecursive(it, el, std::get<Is>(tuple) ...);
		}

		template<class FirstU, class ... RestU>
		void insertElPointerRecursive(iterator it, const std::shared_ptr<T>& el, const std::shared_ptr<Union<FirstU>>& obj, const std::shared_ptr<Union<RestU>>& ... rest)
		{
			this->insertElPointerRecursive(it, el, rest ...);
			obj->insert(it, el);
		}

		template<class FirstU, class ... RestU>
		void insertElPointerRecursive(iterator it, const std::shared_ptr<T>& el, const std::shared_ptr<Union<FirstU>>& obj)
		{
			obj->insert(it, el);
		}

		template<std::size_t ... Is>
		void call_insert3El_with_tuple(iterator position, iterator first, iterator last, const std::tuple<std::shared_ptr<Union<U>> ...>& tuple, std::index_sequence<Is ...>)
		{
			this->insert3ElRecursive(position, first, last, std::get<Is>(tuple) ...);
		}

		template<class FirstU, class ... RestU>
		void insert3ElRecursive(iterator position, iterator first, iterator last, const std::shared_ptr<Union<FirstU>>& obj, const std::shared_ptr<Union<RestU>>& ... rest)
		{
			insert3ElRecursive(position, first, last, rest ...);
			obj->insert(position, first, last);
		}

		template<class FirstU, class ... RestU>
		void insert3ElRecursive(iterator position, iterator first, iterator last, const std::shared_ptr<Union<FirstU>>& obj)
		{
			obj->insert(position, first, last);
		}
};

#endif
