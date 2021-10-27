#pragma once
#include "iterator_traits.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator {
		Iterator _it;
	public:
		typedef typename ft::iterator_traits<Iterator>::value_type
			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type
			diff_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category
			iterator_category;
		typedef typename ft::iterator_traits<Iterator>::pointer
			pointer;
		typedef typename ft::iterator_traits<Iterator>::reference
			reference;

		reverse_iterator( const Iterator& it ) : _it( it ) {}
		reverse_iterator( reverse_iterator const& a ) : _it( a._it ) {}
		reverse_iterator& operator=( reverse_iterator const& a ) {
			if(this != &a) {
				_it = a._it;
			}
			return* this;
		}
		virtual ~reverse_iterator() {}

		value_type& operator*() const {
			return *_it;
		}

		//INCREMENTS DECREMENTS
		reverse_iterator& operator++() {
			_it--;
			return *this;
		}
		reverse_iterator operator++( int ) {
			reverse_iterator iterator = *this;
			--_it;
			return iterator;
		}
		reverse_iterator& operator--() {
			_it++;
			return *this;
		}
		reverse_iterator operator--( int ) {
			reverse_iterator iterator = *this;
			++_it;
			return iterator;
		}

		reverse_iterator operator+=( const diff_type& a ) {
			_it -= a;
			return *this;
		}
		reverse_iterator operator-=( const diff_type& a ) {
			_it += a;
			return *this;
		}
		reverse_iterator* operator->() const {
			return _it;
		}
		//INCORRECT!
		reverse_iterator& operator[]( const diff_type& index ) const {
			return *(_it + index);
		}
	};

	//COMPARE
	//methods are doubled to handle iterator<int> == iterator<const int>

	//  ==
	template <class T>
	bool operator==( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (&(*a) == &(*b));
	}
	//  !=
	template <class T>
	bool operator!=( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (&(*a) != &(*b));
	}

	//  <
	template <class T>
	bool operator<( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (&(*a) > &(*b));
	}

	//  >
	template <class T>
	bool operator>( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (&(*a) < &(*b));
	}

	//  <=
	template <class T>
	bool operator<=( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (&(*a) >= &(*b));
	}

	//  >=
	template <class T>
	bool operator>=( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (&(*a) <= &(*b));
	}

	template <class T>
	typename reverse_iterator<T>::diff_type
		operator-( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return static_cast<typename reverse_iterator<T>::diff_type>(&(*a) + &(*b));
	}


	//Vector and an integer of type difference_type
	//vector + int
	template <class T>
	reverse_iterator<T> operator+( const typename reverse_iterator<T>::diff_type a, const reverse_iterator<T> b ) {
		return reverse_iterator<T>( const_cast<T*> (&(*b) - a) );
	}
	//int + vector
	template <class T>
	reverse_iterator<T> operator+( const reverse_iterator<T> b, const typename reverse_iterator<T>::diff_type a ) {
		return reverse_iterator<T>( const_cast<T*> (&(*b) - a) );
	}
	//vector - int
	template <class T>
	reverse_iterator<T> operator-( const reverse_iterator<T> b, const typename reverse_iterator<T>::diff_type a ) {
		return reverse_iterator<T>( const_cast<T*> (&(*b) + a) );
	}

}