#pragma once

#include <memory>
#include <cstddef>
#include "VectorIterator.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <sstream>
#include "meta_functions.hpp"
#include "utils.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef value_type& 						reference;
		typedef const value_type& 					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer 	const_pointer;
		typedef ft::VectorIterator<value_type> iterator;
		typedef ft::VectorIterator< const value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	private:
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
		value_type* _data;

		value_type* realloc( size_type newCapacity, bool replace_data = true ) {
			value_type* new_data = 0;//NULL
			try {
				new_data = _alloc.allocate( newCapacity );
			}
			catch(std::exception& e) {
				_alloc.deallocate( new_data, newCapacity );
				return NULL;
			}
			size_type new_size = _size;
			if(newCapacity < _size)
				new_size = newCapacity;
			for(size_type i = 0; i < new_size; i++) {
				_alloc.construct( &new_data[i], _data[i] );
			}
			//switch for insert exception
			if(replace_data)
			{
				for(size_type i = 0; i < new_size; i++) {
					_alloc.destroy( &_data[i] );
				}
				_alloc.deallocate( _data, _capacity );
				_data = new_data;
				_capacity = newCapacity;
				_size = new_size;
				return NULL;
			}
			else {
				//in case of exception
				return new_data;
			}
		}
	public:
		//BASE MEMBERS
		
		//default constructor
		explicit vector( const allocator_type& alloc = allocator_type() ) :
			_alloc( alloc ), _size( 0 ), _capacity( 0 ), _data( _alloc.allocate( 0 )) {
		}

		//fill constructor
		explicit vector( size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type() ) : _alloc( alloc ), _size( n ), _capacity( n ), _data( _alloc.allocate( n ) ) {
			for(size_type i = 0; i < n; i++) {
				_alloc.construct( &_data[i], val );
			}
			_size = n;
			_capacity = n;
		}

		//range constructor
		template <class InputIterator>
		vector( InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, char>::type* = 0/*NULL*/ ) : _alloc( alloc ), _size( std::distance( first, last ) ), _capacity( _size ), _data( _alloc.allocate( _size ) ) {
			size_type i = 0;
			for(; first != last; first++) {
				_alloc.construct( &_data[i], *first);
				i++;
			}
		}

		//copy constructor
		vector( const vector& x ) :
			_alloc( x._alloc ), _size( x._size ), _capacity( x._capacity ),
			_data( _alloc.allocate( x._capacity ) ) {
			for(size_type i = 0; i < x.size(); i++) {
				_alloc.construct( &_data[i], x._data[i] );
			}
		}

		//destructor
		virtual ~vector() {
			clear();
			_alloc.deallocate( _data, _capacity );
		}

		//operator=
		vector& operator=( const vector& other ) {
			if(this != &other) {
				clear();
				_alloc.deallocate( _data, _capacity );
				_size = other._size;
				_capacity = other._capacity;
				_data = _alloc.allocate( other._capacity );
				for(size_type i = 0; i < other.size(); i++) {
					_alloc.construct( &_data[i], other._data[i] );
				}
			}
			return *this;
		}


		//assign
		//(1)
		void assign( size_type count, const value_type& value ) {
			clear();
			if(capacity() < count) {
				reserve( count );
				for(size_type i = 0; i < count; i++) {
					push_back(value);
				}	
			}
			else {
				for(size_type i = 0; i < count; i++) {
					push_back( value );
				}
			}
		}
		// //(2)
		template< class InputIt >
		void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, char>::type* = 0/*NULL*/ ) {
			clear();
			size_type dist = std::distance( first, last );
			if(capacity() < dist)
				realloc( dist );
			while(first != last) {
				push_back( *first );
				first++;
			}
		}


		//get_allocator
		allocator_type get_allocator() const {
			return _alloc;
		}

		
		//ELEMENT ACCESS
		//at
		reference at( size_type pos ) {
			if(!(pos < size())) {
				std::stringstream ss;
				ss << "pos (which is " << pos << ") >= this->size() (which is " << size() << ")" << std::endl;
				throw (std::out_of_range( ss.str() ));
			}
			return _data[pos];
		}
		const_reference at( size_type pos ) const {
			if(!(pos < size())) {
				std::stringstream ss;
				ss << "pos (which is " << pos << ") >= this->size() (which is " << size() << ")" << std::endl;
				throw (std::out_of_range( ss.str() ));
			}
			return _data[pos];
		}
		
		//operator[]
		reference operator[]( size_type pos ) {//exceptions
			return _data[pos];
		}
		const_reference operator[]( size_type pos ) const{
			return _data[pos];
		}
		
		//front
		reference front() {
			return _data[0];
		}
		const_reference front() const {
			return _data[0];
		}

		//back
		reference back() {
			return _data[size() - 1];
		}
		const_reference back() const {
			return _data[size() - 1];
		}

		//data
		value_type* data() {
			return _data;
		}
		const value_type* data() const {
			return _data;
		}


		//ITERATORS
		//begin
		iterator begin() {
			return iterator( _data );
		}
		const_iterator begin() const {
			return const_iterator( _data );
		}

		//end
		iterator end() {
			return iterator( _data + _size);
		}
		const_iterator end() const{
			return const_iterator( _data + _size );
		}

		
		//rbegin
		reverse_iterator rbegin() {
			return reverse_iterator( end() );
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator( end());
		}

		//rend
		reverse_iterator rend() {
			return reverse_iterator( begin());
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator( begin());
		}

		//CAPACITY
		//empty
		bool empty() const {
			return begin() == end();
		}

		//size
		size_type size() const {
			return _size;
		}

		//max_size
		size_type max_size() const {
			return _alloc.max_size();
		}

		//reserve
		void reserve( size_type new_cap ) {
			if(new_cap > capacity()) {
				if(capacity() == 0)
					realloc( new_cap );
				else {
					size_type new_cap_mod = capacity();
					while(new_cap_mod < new_cap) {
						new_cap_mod = new_cap_mod * 2;
					}
					realloc( new_cap_mod );
				}
			}
		}
		
		//capacity
		size_type capacity() const {
			return _capacity;
		}

		//MODIFIERS
		//clear
		void clear() {
			for(size_type i = 0; i < _size; i++) {
				_alloc.destroy( &_data[i] );
			}
			_size = 0;
		}

		//insert
		//(1)
		iterator insert( iterator pos, const value_type& value ) {
			bool garantee = (pos == end());
			ft::vector<T, Allocator> temp;
			if(garantee)
				temp = *this ;
			try {
				if(pos > end())
					return pos;
				if(size() == capacity()) {
					difference_type temp = pos - begin();
					realloc( _capacity * 2 );
					pos = begin();
					for(difference_type i = 0; i < temp; i++) {
						pos++;
					}
				}
				for(iterator it = end(); &(*it) != &(*pos) && it != begin(); it--) {
					_alloc.destroy( &(*it) );
					_alloc.construct( &(*it), *(it - 1) );
				}
				_alloc.construct( &(*pos), value );
				_size++;
				return pos;
			}
			catch(...) {
				//need to free mem here lol
				if(garantee)
					*this = temp;
				throw;
			}
		}
		//(3)
		void insert( iterator pos, size_type count, const value_type& value ) {
			if(count == 0)
				return;
			if(size() + count > capacity()) {
				difference_type temp = pos - begin();
				realloc( (size() + count) * 1.5 );
				pos = begin();
				for(difference_type i = 0; i < temp; i++) {
					pos++;
				}
			}

			for(iterator it = pos; it != end();it++) {
				_alloc.construct( &(*(it + count)), *it );
			}
			_size += count;
			for(size_type i = 0; i < count;i++) {
				_alloc.construct( &(*(pos + i)), value );
			}
			
		}
		// //(4)
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, char>::type* = 0/*NULL*/ ) {
			difference_type count = std::distance( first, last );
			if(count == 0)
				return;
			if(size() + count > capacity()) {
				difference_type temp = pos - begin();

				if(_capacity == 0)
					_capacity = (size() + count);
				else {
					while(_capacity < (size() + count))
						_capacity *= 2;
				}
				realloc( _capacity );
				pos = begin();
				for(difference_type i = 0; i < temp; i++) {
					pos++;
				}
			}

			for(iterator it = end() - 1; it != pos - 1;it--) {
				_alloc.construct( &(*(it + count)), *it );
			}
			_size += count;
			for(difference_type i = 0; i < count;i++) {
				_alloc.construct( &(*(pos + i)), *first );
				first++;
			}
		}
		//erase
		//(1)
		iterator erase( iterator pos ) {
			_alloc.destroy( &(*pos) );
			for(iterator it = pos; it != end() - 1; it++) {
				_alloc.construct( &(*it), *(it + 1) );
			}
			_size--;
			return pos;
		}
		//(2)
		iterator erase( iterator first, iterator last ) {
			difference_type temp = std::distance(first, last);
			iterator out = first;
			for(iterator it = first; it != last; it++) {
				_alloc.destroy( &(*it) );
			}
			
			for(iterator it = last; it != end(); it++) {
				_alloc.construct( &(*first), *it );
				first++;
			}
			_size -= temp;
			return out;
		}

		//push_back
		void push_back( const value_type& value ) {
			if(_size == _capacity) {
				if(_capacity == 0)
					_capacity = 1;
				else
					_capacity = _capacity * 2;
				try {
					realloc( _capacity );
				}
				catch(std::exception& e) {
					return;
				}
			}
			_alloc.construct( &_data[_size], value );
			_size++;
		}

		//pop_back
		void pop_back() {
			erase( end() - 1 );
		}

		//resize
		//(2)
		void resize( size_type count, value_type value = value_type() ) {
			if(size() < count) {
				reserve( count );
				for(size_type i = size(); i < count; i++) {
					_alloc.construct( &_data[i], value );
					_size = count;
				}
			}
			else {
				_size = count;
			}
		}

		//swap
		void swap( vector& other ) {
			allocator_type _alloc_buf = _alloc;
			size_type _size_buf = _size;
			size_type _capacity_buf = _capacity;
			value_type* _data_buf = _data;

			_alloc = other._alloc;
			_size = other._size;
			_capacity = other._capacity;
			_data = other._data;
			
			other._alloc = _alloc_buf;
			other._size = _size_buf;
			other._capacity = _capacity_buf;
			other._data = _data_buf;
		}

	};

	//compare
	//==
	template< class T, class Alloc >
	bool operator==( const ft::vector<T, Alloc>& lhs,
		const ft::vector<T, Alloc>& rhs ) {
		return lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) && ft::equal( rhs.begin(), rhs.end(), lhs.begin() );
	}
	//!=
	template< class T, class Alloc >
	bool operator!=( const ft::vector<T, Alloc>& lhs,
		const ft::vector<T, Alloc>& rhs ){
		return !(lhs == rhs);
	}
	//<
	template< class T, class Alloc >
	bool operator<( const ft::vector<T, Alloc>& lhs,
		const ft::vector<T, Alloc>& rhs ){
		return ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) && ft::operator!=(lhs, rhs);
	}
	//<=
	template< class T, class Alloc >
	bool operator<=( const ft::vector<T, Alloc>& lhs,
		const ft::vector<T, Alloc>& rhs ){
		return ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) || lhs == rhs;
	}
	//>
	template< class T, class Alloc >
	bool operator>( const ft::vector<T, Alloc>& lhs,
		const ft::vector<T, Alloc>& rhs ){
		return !ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) && lhs != rhs;
		}
	//>=
	template< class T, class Alloc >
	bool operator>=( const ft::vector<T, Alloc>& lhs,
		const ft::vector<T, Alloc>& rhs ){
		return !ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) || lhs == rhs;
		}

	
	//ft::swap
	template <class T, class Alloc>
	void swap( ft::vector<T, Alloc>& a, ft::vector<T, Alloc>& b ) {
		a.swap( b );
	}
}

