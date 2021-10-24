#pragma once

#include <memory>
#include <cstddef>
#include <iterator>
#include "VectorIterator.hpp"
#include "ReverseIterator.hpp"
#include <iostream>
#include <vector>

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
		typedef VectorIterator<value_type> iterator;
		typedef VectorIterator< const value_type> const_iterator; //is it though???
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	private:
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
		value_type* _data;

		void realloc( size_type newCapacity ) {
			value_type* new_data = _alloc.allocate( newCapacity );

			if(newCapacity < _size)
				_size = newCapacity;
			for(size_type i = 0; i < _size; i++) {
				_alloc.construct( &new_data[i], _data[i] );
				_alloc.destroy( &_data[i] );
			}
			_alloc.deallocate( _data, _capacity );
			_data = new_data;
			_capacity = newCapacity;
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

		// //range constructor
		// template <class InputIterator>
		// vector( InputIterator first, InputIterator last,
		// 	const allocator_type& alloc = allocator_type() ) : _alloc( alloc ), _size( last - first ), _capacity( last - first ), _data( _alloc.allocate( last - first ) ) {
		// 	size_type i = 0;
		// 	for(; first < last; first++) {
		// 		alloc.construct( &_data[i], *first );
		// 		i++;
		// 	}
		// }

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
			for(size_type i = 0; i < count; i++) {
				push_back(value);
			}
		}
		// //(2)
		template< class InputIt >
		void assign( InputIt first, InputIt last ) {
			clear();
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
			return _data[pos];
		}
		const_reference at( size_type pos ) const{
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
			return reverse_iterator( _data + _size - 1 );
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator( _data + _size - 1 );
		}

		//end
		reverse_iterator rend() {
			return reverse_iterator( _data - 1 );
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator( _data - 1 );
		}

		//CAPACITY
		//empty
		bool empty() const {
			begin() == end();
		}

		//size
		size_type size() const {
			return _size;
		}

		//reserve
		void reserve( size_type new_cap ) {
			if(new_cap > capacity()) {
				realloc( new_cap );
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
			if(size() == capacity()) {
				difference_type temp = pos - begin();
				realloc(_capacity * 2);
				pos = begin();
				for(difference_type i = 0; i < temp; i++) {
					pos++;
				}
			}		
			for(iterator it = end(); &(*it) != &(*pos) && it != begin() + 1; it--) {
				*it = *(it - 1);
			}
			_alloc.construct( &(*pos), value );
			_size++;
			return pos;
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
			for(difference_type i = 0; i < count;i++) {
				_alloc.construct( &(*(pos + i)), value );
			}
			
		}
		// //(4)
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last ) {
			size_type count = 0;
			for(InputIt i = first; i != last;i++) {
				count++;
			}
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
			difference_type temp = last - first;
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
		void push_back( const value_type& value ) {//NYI
			if(_size == _capacity) {
				if(_capacity == 0)
					_capacity = 1;
				else
					_capacity = _capacity * 2;
				realloc( _capacity );
			}
			_alloc.construct(&_data[_size], value);
			_size++;
		}

		//pop_back
		void pop_back() {
			erase( end() - 1 );
		}

		//resize
		//(1)
		void resize( size_type count ) {
			if(size() < count) {
				realloc( count );
				for(size_type i = size(); i < count; i++) {
					_alloc.construct( &_data[i], value_type() );
					_size = count;
				}
			}
			else {
				realloc( count );
			}
		}
		//(2)
		void resize( size_type count, value_type value = value_type() ) {
			if(size() < count) {
				realloc( count );
				for(size_type i = size(); i < count; i++) {
					_alloc.construct( &_data[i], value );
					_size = count;
				}
			}
			else {
				realloc( count );
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

	template <class T, class Alloc>
	void swap( ft::vector<T, Alloc> &a, ft::vector<T, Alloc> &b ) {
		a.swap( b );
	}
}

