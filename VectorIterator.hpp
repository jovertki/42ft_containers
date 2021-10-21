#pragma once

template <class Cont>
class VectorIterator {
	typedef typename Cont::value_type value_type;
	typedef typename Cont::difference_type diff_type;
	typedef typename Cont::size_type size_type;
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

	//COMPARE
	bool operator==( const VectorIterator& a )const {
		if(this->_ptr == a._ptr)
			return true;
		return false;
	}
	bool operator!=( const VectorIterator& a ) const {
		if(this->_ptr != a._ptr)
			return true;
		return false;
	}
	bool operator<( const VectorIterator& a )const {
		if(this->_ptr < a._ptr)
			return true;
		return false;
	}
	bool operator>( const VectorIterator& a )const {
		if(this->_ptr > a._ptr)
			return true;
		return false;
	}
	bool operator<=( const VectorIterator& a )const {
		if(this->_ptr <= a._ptr)
			return true;
		return false;
	}
	bool operator>=( const VectorIterator& a )const {
		if(this->_ptr >= a._ptr)
			return true;
		return false;
	}
};
template <class Cont>
typename Cont::difference_type
operator-( const VectorIterator<Cont>& a, const VectorIterator<Cont>& b ) {
	return static_cast<typename Cont::difference_type>(&(*a) - &(*b));
}

//vector + int
template <class Cont>
VectorIterator<Cont> operator+( const typename Cont::difference_type a, const VectorIterator<Cont> b ) {
	return VectorIterator<Cont>( const_cast<typename Cont::value_type*> (&(*b) + a) );
}
//int + vector
template <class Cont>
VectorIterator<Cont> operator+( const VectorIterator<Cont> b, const typename Cont::difference_type a ) {
	return VectorIterator<Cont>( const_cast<typename Cont::value_type*> (&(*b) + a) );
}
//vector - int
template <class Cont>
VectorIterator<Cont> operator-( const VectorIterator<Cont> b, const typename Cont::difference_type a ) {
	return VectorIterator<Cont>( const_cast<typename Cont::value_type*> (&(*b) - a) );
}

/*NOT NEEDED*/
// //vector - int
// template <class Cont>
// VectorIterator<Cont> operator-( const typename Cont::difference_type a, const VectorIterator<Cont> b ) {
// 	return VectorIterator<Cont>( const_cast<typename Cont::value_type*> (&(*b) - a) );
// }



