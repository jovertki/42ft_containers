#pragma once
#include "iterator_traits.hpp"

namespace ft {
	template <class T>
	class MapIterator : public iterator<bidirectional_iterator_tag, T> {
	public:
		typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category
			iterator_category;
		typedef typename iterator<bidirectional_iterator_tag, T>::value_type
			value_type;
		typedef typename iterator<bidirectional_iterator_tag, T>::difference_type
			diff_type;
		typedef typename iterator<bidirectional_iterator_tag, T>::pointer
			pointer;
		typedef typename iterator<bidirectional_iterator_tag, T>::reference
			reference;
		typedef std::size_t size_type;
	private:
		value_type* _ptr;
	public:
		MapIterator( value_type* ptr = 0 /*NULL*/ ) : _ptr( ptr ) {}
		MapIterator( MapIterator const& a ) : _ptr( a._ptr ) {}
		MapIterator& operator=( MapIterator const& a ) {
			if(this != &a) {
				_prev = a._prev;
				_ptr = a._ptr;
			}
			return (*this);
		}
		virtual ~MapIterator() {}

		value_type& operator*() const {
			return *_ptr;
		}

		//INCREMENTS DECREMENTS
		MapIterator& operator++() {
			_ptr++;
			return *this;
		}
		MapIterator operator++( int ) {
			MapIterator iterator = *this;
			_ptr++;
			return iterator;
		}
		MapIterator& operator--() {
			_ptr--;
			return *this;
		}
		MapIterator operator--( int ) {
			MapIterator iterator = *this;
			_ptr--;
			return iterator;
		}

		MapIterator operator+=( const diff_type& a ) {
			_ptr += a;
			return *this;
		}
		MapIterator operator-=( const diff_type& a ) {
			_ptr -= a;
			return *this;
		}
		pointer operator->() const {
			return _ptr;
		}
		reference operator[]( const diff_type& index ) const {
			return *(_ptr + index);
		}
		operator ft::MapIterator<const value_type>() const {
			return MapIterator<const value_type>( _ptr );
		}
	};


	//COMPARE
	//methods are doubled to handle iterator<int> == iterator<const int>

	//  ==
	template <class T1, class T2>
	bool operator==( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return (&(*a) == &(*b));
	}
	template <class T1>
	bool operator==( const MapIterator<T1>& a, const MapIterator<T1>& b ) {
		return (&(*a) == &(*b));
	}
	//  !=
	template <class T1, class T2>
	bool operator!=( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return (&(*a) != &(*b));
	}
	template <class T1>
	bool operator!=( const MapIterator<T1>& a, const MapIterator<T1>& b ) {
		return (&(*a) != &(*b));
	}

	//  <
	template <class T1, class T2>
	bool operator<( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return (&(*a) < &(*b));
	}
	template <class T1>
	bool operator<( const MapIterator<T1>& a, const MapIterator<T1>& b ) {
		return (&(*a) < &(*b));
	}

	//  >
	template <class T1, class T2>
	bool operator>( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return (&(*a) > &(*b));
	}
	template <class T1>
	bool operator>( const MapIterator<T1>& a, const MapIterator<T1>& b ) {
		return (&(*a) > &(*b));
	}

	//  <=
	template <class T1, class T2>
	bool operator<=( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return (&(*a) <= &(*b));
	}
	template <class T1>
	bool operator<=( const MapIterator<T1>& a, const MapIterator<T1>& b ) {
		return (&(*a) <= &(*b));
	}

	//  >=
	template <class T1, class T2>
	bool operator>=( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return (&(*a) >= &(*b));
	}
	template <class T1>
	bool operator>=( const MapIterator<T1>& a, const MapIterator<T1>& b ) {
		return (&(*a) >= &(*b));
	}

	template <class T>
	typename MapIterator<T>::diff_type
		operator-( const MapIterator<T>& a, const MapIterator<T>& b ) {
		return static_cast<typename MapIterator<T>::diff_type>(&(*a) - &(*b));
	}


	//Vector and an integer of type difference_type
	//vector + int
	template <class T>
	MapIterator<T> operator+( const typename MapIterator<T>::diff_type a, const MapIterator<T> b ) {
		return MapIterator<T>( const_cast<T*> (&(*b) + a) );
	}
	//int + vector
	template <class T>
	MapIterator<T> operator+( const MapIterator<T> b, const typename MapIterator<T>::diff_type a ) {
		return MapIterator<T>( const_cast<T*> (&(*b) + a) );
	}
	//vector - int
	template <class T>
	MapIterator<T> operator-( const MapIterator<T> b, const typename MapIterator<T>::diff_type a ) {
		return MapIterator<T>( const_cast<T*> (&(*b) - a) );
	}

	template <class T1, class T2>
	typename MapIterator<T1>::diff_type operator-( const MapIterator<T1>& a, const MapIterator<T2>& b ) {
		return &(*a) - &(*b);
	}
}