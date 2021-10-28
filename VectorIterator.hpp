#pragma once
#include "iterator_traits.hpp"

namespace ft {
	template <class T>
	class VectorIterator : public iterator<random_access_iterator_tag, T>{
	public:
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category
			iterator_category;
		typedef typename iterator<random_access_iterator_tag, T>::value_type
			value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type
			diff_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer
			pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference
			reference;
		typedef std::size_t size_type;
	private:
		value_type* _ptr;
	public:
		VectorIterator( value_type* ptr = 0 /*NULL*/) : _ptr( ptr ) {}
		VectorIterator( VectorIterator const& a ) : _ptr( a._ptr ) {}
		VectorIterator& operator=( VectorIterator const& a ) {
			if(this != &a) {
				_ptr = a._ptr;
			}
			return (*this);
		}
		virtual ~VectorIterator() {}

		value_type& operator*() const {
			return *_ptr;
		}

		//INCREMENTS DECREMENTS
		VectorIterator& operator++() {
			_ptr++;
			return *this;
		}
		VectorIterator operator++( int ) {
			VectorIterator iterator = *this;
			_ptr++;
			return iterator;
		}
		VectorIterator& operator--() {
			_ptr--;
			return *this;
		}
		VectorIterator operator--( int ) {
			VectorIterator iterator = *this;
			_ptr--;
			return iterator;
		}

		VectorIterator operator+=( const diff_type &a ) {
			_ptr += a;
			return *this;
		}
		VectorIterator operator-=( const diff_type& a ) {
			_ptr -= a;
			return *this;
		}
		pointer operator->() const {
			return _ptr;
		}
		reference operator[]( const diff_type& index ) const {
			return *(_ptr + index);
		}
		operator ft::VectorIterator<const value_type>() const {
			return VectorIterator<const value_type>(_ptr);
		}
	};


	//COMPARE
	//methods are doubled to handle iterator<int> == iterator<const int>

	//  ==
	template <class T1, class T2>
	bool operator==( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return (&(*a) == &(*b));
	}
	template <class T1>
	bool operator==( const VectorIterator<T1>& a, const VectorIterator<T1>& b ) {
		return (&(*a) == &(*b));
	}
	//  !=
	template <class T1, class T2>
	bool operator!=( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return (&(*a) != &(*b));
	}
	template <class T1>
	bool operator!=( const VectorIterator<T1>& a, const VectorIterator<T1>& b ) {
		return (&(*a) != &(*b));
	}

	//  <
	template <class T1, class T2>
	bool operator<( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return (&(*a) < &(*b));
	}
	template <class T1>
	bool operator<( const VectorIterator<T1>& a, const VectorIterator<T1>& b ) {
		return (&(*a) < &(*b));
	}

	//  >
	template <class T1, class T2>
	bool operator>( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return (&(*a) > &(*b));
	}
	template <class T1>
	bool operator>( const VectorIterator<T1>& a, const VectorIterator<T1>& b ) {
		return (&(*a) > &(*b));
	}

	//  <=
	template <class T1, class T2>
	bool operator<=( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return (&(*a) <= &(*b));
	}
	template <class T1>
	bool operator<=( const VectorIterator<T1>& a, const VectorIterator<T1>& b ) {
		return (&(*a) <= &(*b));
	}

	//  >=
	template <class T1, class T2>
	bool operator>=( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return (&(*a) >= &(*b));
	}
	template <class T1>
	bool operator>=( const VectorIterator<T1>& a, const VectorIterator<T1>& b ) {
		return (&(*a) >= &(*b));
	}

	template <class T>
	typename VectorIterator<T>::diff_type
		operator-( const VectorIterator<T>& a, const VectorIterator<T>& b ) {
		return static_cast<typename VectorIterator<T>::diff_type>(&(*a) - &(*b));
	}


	//Vector and an integer of type difference_type
	//vector + int
	template <class T>
	VectorIterator<T> operator+( const typename VectorIterator<T>::diff_type a, const VectorIterator<T> b ) {
		return VectorIterator<T>( const_cast<T*> (&(*b) + a) );
	}
	//int + vector
	template <class T>
	VectorIterator<T> operator+( const VectorIterator<T> b, const typename VectorIterator<T>::diff_type a ) {
		return VectorIterator<T>( const_cast<T*> (&(*b) + a) );
	}
	//vector - int
	template <class T>
	VectorIterator<T> operator-( const VectorIterator<T> b, const typename VectorIterator<T>::diff_type a ) {
		return VectorIterator<T>( const_cast<T*> (&(*b) - a) );
	}

	template <class T1, class T2>
	typename VectorIterator<T1>::diff_type operator-( const VectorIterator<T1>& a, const VectorIterator<T2>& b ) {
		return &(*a) - &(*b);
	}
}