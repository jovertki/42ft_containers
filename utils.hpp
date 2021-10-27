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


	//equal
	//(1) Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise
	template<class InputIt1, class InputIt2>
	bool equal( InputIt1 first1, InputIt1 last1,
		InputIt2 first2 )
	{
		for(; first1 != last1; ++first1, ++first2) {
			if(!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	//(3) Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise
	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal( InputIt1 first1, InputIt1 last1,
		InputIt2 first2, BinaryPredicate p )
	{
		for(; first1 != last1; ++first1, ++first2) {
			if(!p( *first1, *first2 )) {
				return false;
			}
		}
		return true;
	}


	//lexicographical_compare
	//(1)Elements are compared using operator<
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
		InputIt2 first2, InputIt2 last2 )
	{
		for(; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if(*first1 < *first2) return true;
			if(*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	//(3)Elements are compared using the given binary comparison function comp
	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
		InputIt2 first2, InputIt2 last2,
		Compare comp )
	{
		for(; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if(comp( *first1, *first2 )) return true;
			if(comp( *first2, *first1 )) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}



	
}