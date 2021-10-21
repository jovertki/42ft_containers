#pragma once

#include <memory>
#include <cstddef>
#include <iterator>
#include "VectorIterator.hpp"

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
		typedef VectorIterator< vector<T, Allocator> > iterator;
		typedef VectorIterator< const vector<const T, Allocator> > const_iterator; //is it though???
		typedef typename std::reverse_iterator<iterator> reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;
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
		// 	const allocator_type& alloc = allocator_type() ) {
		// 	_data = alloc.allocate( static_cast<size_type> (last - first) );
		// 	size_type j = 0;
		// 	for(InputIterator i = first; i != last; i++) {
		// 		*i = _data[j];
		// 		j++;
		// 	}
		// 	_size = j;
		// 	_capacity = j;
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
			return allocator_type();
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

		// //insert
		// //(1)
		// iterator insert( iterator pos, const value_type& value );
		// //(3)
		// void insert( iterator pos, size_type count, const value_type& value );
		// //(4)
		// template< class InputIt >
		// void insert( iterator pos, InputIt first, InputIt last );

		// //erase
		// //(1)
		// iterator erase( iterator pos );
		// //(2)
		// iterator erase( iterator first, iterator last );

		//push_back
		void push_back( const value_type& value ) {//NYI
			if(_size <= _capacity) {
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
			//call erase
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
		void swap( vector& other );

	};
}
