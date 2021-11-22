#pragma once

#include <cstddef>

namespace ft
{
	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::iterator_category   iterator_category;
		typedef typename Iter::value_type          value_type;
		typedef typename Iter::difference_type     difference_type;
		typedef typename Iter::pointer             pointer;
		typedef typename Iter::reference           reference;
	};

	template<
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T&
	> struct iterator
	{
	public:
		typedef Category    iterator_category;
		typedef T           value_type;
		typedef Distance    difference_type;
		typedef Pointer     pointer;
		typedef Reference   reference;
	};
}