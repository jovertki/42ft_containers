#pragma once
namespace ft {
	template <class T>
	class VectorIterator {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t diff_type;
		typedef std::size_t	 size_type;
	private:
		value_type* _ptr;
	public:
		VectorIterator( value_type* ptr ) : _ptr( ptr ) {}
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

		VectorIterator operator+=( diff_type a ) {
			_ptr += a;
			return *this;
		}
		VectorIterator operator-=( diff_type a ) {
			_ptr -= a;
			return *this;
		}
		VectorIterator* operator->() const {
			return _ptr;
		}
		VectorIterator& operator[]( size_type index ) const {
			return *(_ptr + index);
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

}