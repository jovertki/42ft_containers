#pragma once

#include <memory>
#include <cstddef>
#include <iterator>
namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		typedef T				value_type;
		typedef Allocator		allocator_type;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer	pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename std::iterator < std::random_access_iterator_tag, value_type > iterator;
		typedef typename std::iterator < std::random_access_iterator_tag, const value_type > const_iterator; //is it though???
		typedef typename std::reverse_iterator<iterator> reverse_iterator;
		typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

		value_type* _data;
	public:
		//default constructor
		explicit vector( const allocator_type& alloc = allocator_type() ) {
			_data = alloc.allocate( 0 );
		}

		//fill constructor
		explicit vector( size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type() ) {
			_data = alloc.allocate( n );
			for(size_type i = 0; i < n; i++) {
				_data[i] = val;
			}
		}

		//range constructor
		template <class InputIterator>
		vector( InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type() ) {
			_data = alloc.allocate( static_cast<size_type> (last - first) );
			size_type j = 0;
			for(InputIterator i = first; i != last; i++) {
				*i = _data[j];
				j++;
			}
		}

		//copy constructor <--------NYI
		vector( const vector& x ) {
			if(this != &x) {

			}
		}
		virtual ~vector() {
			
		}
	};
}