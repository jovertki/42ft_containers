#pragma once

namespace ft {
	template <class Iterator>
	class ReverseIterator {
		Iterator _it;
	public:
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::diff_type diff_type;
		typedef typename Iterator::size_type size_type;

		ReverseIterator( const Iterator& it ) : _it( it ) {}
		ReverseIterator( ReverseIterator const& a ) : _it( a._it ) {}
		ReverseIterator& operator=( ReverseIterator const& a ) {
			if(this != &a) {
				_it = a._it;
			}
			return* this;
		}
		virtual ~ReverseIterator() {}

		value_type& operator*() const {
			return *_it;
		}

		//INCREMENTS DECREMENTS
		ReverseIterator& operator++() {
			_it--;
			return *this;
		}
		ReverseIterator operator++( int ) {
			ReverseIterator iterator = *this;
			--_it;
			return iterator;
		}
		ReverseIterator& operator--() {
			_it++;
			return *this;
		}
		ReverseIterator operator--( int ) {
			ReverseIterator iterator = *this;
			++_it;
			return iterator;
		}

		ReverseIterator operator+=( diff_type a ) {
			_it -= a;
			return *this;
		}
		ReverseIterator operator-=( diff_type a ) {
			_it += a;
			return *this;
		}
		ReverseIterator* operator->() const {
			return _it;
		}
		//INCORRECT!
		ReverseIterator& operator[]( size_type index ) const {
			return *(_it + index);
		}
	};

	//COMPARE
	//methods are doubled to handle iterator<int> == iterator<const int>

	//  ==
	template <class T>
	bool operator==( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return (&(*a) == &(*b));
	}
	//  !=
	template <class T>
	bool operator!=( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return (&(*a) != &(*b));
	}

	//  <
	template <class T>
	bool operator<( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return (&(*a) > &(*b));
	}

	//  >
	template <class T>
	bool operator>( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return (&(*a) < &(*b));
	}

	//  <=
	template <class T>
	bool operator<=( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return (&(*a) >= &(*b));
	}

	//  >=
	template <class T>
	bool operator>=( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return (&(*a) <= &(*b));
	}

	template <class T>
	typename ReverseIterator<T>::diff_type
		operator-( const ReverseIterator<T>& a, const ReverseIterator<T>& b ) {
		return static_cast<typename ReverseIterator<T>::diff_type>(&(*a) + &(*b));
	}


	//Vector and an integer of type difference_type
	//vector + int
	template <class T>
	ReverseIterator<T> operator+( const typename ReverseIterator<T>::diff_type a, const ReverseIterator<T> b ) {
		return ReverseIterator<T>( const_cast<T*> (&(*b) - a) );
	}
	//int + vector
	template <class T>
	ReverseIterator<T> operator+( const ReverseIterator<T> b, const typename ReverseIterator<T>::diff_type a ) {
		return ReverseIterator<T>( const_cast<T*> (&(*b) - a) );
	}
	//vector - int
	template <class T>
	ReverseIterator<T> operator-( const ReverseIterator<T> b, const typename ReverseIterator<T>::diff_type a ) {
		return ReverseIterator<T>( const_cast<T*> (&(*b) + a) );
	}

}