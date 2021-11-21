#pragma once
#include "iterator_traits.hpp"
#include <exception>
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


	//isConst
	template <typename T> bool isConst( T& )
	{
		return false;
	}

	template <typename T> bool isConst( T const&  )
	{
		return true;
	}


	//Pair
	template<
		class T1,
		class T2
	> struct pair {

	public:
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;
		pair() : first(T1()), second(T2()){//(1)

		}
		pair( const T1& x, const T2& y ) : first( x ), second( y ) {}//(2)

		template< class U1, class U2 >//(4)
		pair( const pair<U1, U2>& p ) : first( p.first ), second( p.second ) {}
		
		pair& operator=( const pair& other ) {
			if(this != &other) {
				if (!isConst(first))
					first = other.first;
				if(!isConst( second ))
					second = other.second;
			}
			return *this;
		}

	};
	
	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u ) {
		return ft::pair<T1, T2>( t, u );
	}

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if(lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if(lhs.first != rhs.first && lhs.second != rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if(lhs.first > rhs.first || lhs.second > rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if(lhs.first >= rhs.first && lhs.second >= rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if(lhs.first < rhs.first || lhs.second < rhs.second)
			return true;
		return false;
	}
	
	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ) {
		if(lhs.first <= rhs.first && lhs.second <= rhs.second)
			return true;
		return false;
	}


	// conditional
	template <bool B, typename U, typename V>
	struct conditional {
		typedef V type;
	};

	template <typename U, typename V>
	struct conditional<true, U, V> {
		typedef U type;
	};
	// --------------- end : conditional

	
}