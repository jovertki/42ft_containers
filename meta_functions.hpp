#pragma once
#include "utils.hpp"

namespace ft {

	/* Enable_if    metafunction

	Signature:
		template< _condition, _Type >

	Behaviour:
		If condition is true, ::type field sets to _Type
		Otherwise, template does not match
*/
	
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };



	template<typename T>
	struct is_integral { static const bool  value = false; };

	template<>  struct is_integral<bool> { static const bool value = true; };
	template<>  struct is_integral<char> { static const bool value = true; };
	template<>  struct is_integral<signed char> { static const bool value = true; };
	template<>  struct is_integral<unsigned char> { static const bool value = true; };
	template<>  struct is_integral<wchar_t> { static const bool value = true; };
	template<>  struct is_integral<short> { static const bool value = true; };
	template<>  struct is_integral<unsigned short> { static const bool value = true; };
	template<>  struct is_integral<int> { static const bool value = true; };
	template<>  struct is_integral<unsigned int> { static const bool value = true; };
	template<>  struct is_integral<long> { static const bool value = true; };
	template<>  struct is_integral<unsigned long> { static const bool value = true; };

	template<typename T, typename U, typename X>
	struct is_pair { static const bool  value = false; };
	
	template<typename U, typename X>  struct is_pair< ft::pair<U, X>, U, X> { static const bool value = true; };
}