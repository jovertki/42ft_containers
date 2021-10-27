#pragma once
#include "iterator_traits.hpp"

namespace ft {
	template<class Iter>
	typename ft::iterator_traits<Iter>::difference_type distance( Iter begin, Iter end ) {
		typename ft::iterator_traits<Iter>::difference_type i = 0;
		for(; begin != end; begin++) {
			i++;
		}
		return i;
	}
}