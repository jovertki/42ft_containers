#pragma once
#include "iterator_traits.hpp"
#include "VectorIterator.hpp"
namespace ft {
	template <class Iterator>
	class reverse_iterator {
		Iterator _it;
	public:
		typedef Iterator iterator_type;
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

		reverse_iterator( const Iterator& it = Iterator()) : _it( it - 1) {}
		reverse_iterator( reverse_iterator const& a ) : _it( a._it) {}
		reverse_iterator& operator=( reverse_iterator const& a ) {
			if(this != &a) {
				_it = a._it;
			}
			return* this;
		}
		virtual ~reverse_iterator() {}
		iterator_type base() const {
			return _it + 1;
		}
		reference operator*() const {
			return *(_it);
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
		pointer operator->() const {
			return &(*_it);
		}
		reference operator[]( const diff_type& index ) const {
			return base()[-index - 1];
		}

		operator ft::reverse_iterator<ft::VectorIterator< const value_type> >() const {
			return ft::reverse_iterator<ft::VectorIterator< const value_type> >( _it + 1);
		}
	};

	//COMPARE
	//methods are doubled to handle iterator<int> == iterator<const int>

	//  ==
	template <class T>
	bool operator==( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (a.base() == b.base());
	}
	template <class T1, class T2>
	bool operator==( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return (a.base() == b.base());
	}
	
	//  !=
	template <class T>
	bool operator!=( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (a.base() != b.base());
	}
	template <class T1, class T2>
	bool operator!=( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return (a.base() != b.base());
	}
	
	//  <
	template <class T>
	bool operator<( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (a.base() > b.base());
	}
	template <class T1, class T2>
	bool operator<( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return (a.base() > b.base());
	}
	
	//  >
	template <class T>
	bool operator>( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (a.base() < b.base());
	}
	template <class T1, class T2>
	bool operator>( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return (a.base() < b.base());
	}
	
	//  <=
	template <class T>
	bool operator<=( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (a.base() >= b.base());
	}
	template <class T1, class T2>
	bool operator<=( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return (a.base() >= b.base());
	}
	
	//  >=
	template <class T>
	bool operator>=( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return (a.base() <= b.base());
	}
	template <class T1, class T2>
	bool operator>=( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return (a.base() <= b.base());
	}

	
	template <class T>
	typename reverse_iterator<T>::diff_type
		operator-( const reverse_iterator<T>& a, const reverse_iterator<T>& b ) {
		return static_cast<typename reverse_iterator<T>::diff_type>(b.base() - a.base());
	}
	template <class T1, class T2>
	typename reverse_iterator<T1>::diff_type
		operator-( const reverse_iterator<T1>& a, const reverse_iterator<T2>& b ) {
		return static_cast<typename reverse_iterator<T1>::diff_type>(b.base() - a.base());
	}

	//Vector and an integer of type difference_type
	//int + vector
	template <class T>
	reverse_iterator<T> operator+( const typename reverse_iterator<T>::diff_type a, const reverse_iterator<T> b ) {
		return reverse_iterator<T>( b.base() - a );
	}
	//vector + int
	template <class T>
	reverse_iterator<T> operator+( const reverse_iterator<T> b, const typename reverse_iterator<T>::diff_type a ) {
		return reverse_iterator<T>( b.base() - a);
	}
	//vector - int
	template <class T>
	reverse_iterator<T> operator-( const reverse_iterator<T> b, const typename reverse_iterator<T>::diff_type a ) {
		return reverse_iterator<T>( b.base() + a  );
	}

}