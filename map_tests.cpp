#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"
#include <string>
#include <vector>
#include <list>



//map
#include "map.hpp"
#include <map>




#define GOOD std::cout << "\033[1;32mGOOD\033[0m\n";
#define BAD std::cout << "\033[1;31mBAD\033[0m\n";





// int main() {


// 	std::cout << "my map test---------------------" << std::endl;
// 	ft::map<int, int> mymap;
// 	mymap.insert( ft::make_pair( 30, 30 ) );
// 	mymap.insert( ft::make_pair( 20, 20 ) );
// 	mymap.insert( ft::make_pair( 50, 50 ) );
// 	mymap.insert( ft::make_pair( 15, 15 ) );
// 	mymap.insert( ft::make_pair( 25, 25 ) );
// 	mymap.insert( ft::make_pair( 40, 40 ) );
// 	mymap.insert( ft::make_pair( 35, 35 ) );
// 	mymap.insert( ft::make_pair( 45, 45 ) );
// 	mymap.insert( ft::make_pair( 55, 55 ) );
// 	mymap[17] = 17;


// 	std::cout << "the tree is built" << std::endl;
// 	// mymap[70] = 70;
// 	// mymap[80] = 80;
// 	//	std::cout << "value to erase = " << ((++(++(++(mymap.begin())))))->second << std::endl;
// 	mymap.erase( --mymap.end() );

// 	// ft::pair<ft::map<int, int>::iterator, bool> check = mymap.insert( ft::make_pair( 60, 60 ) );

// 	std::cout << "full tree:" << std::endl;
// 	for(ft::map<int, int>::iterator itt = mymap.begin(); itt != mymap.end(); itt++) {

// 		std::cout << itt->second << std::endl;
// 	}

// 	std::cout << " equal range is" << std::endl;
// 	//	std::cout << (*mymap.upper_bound( 50 )).second << " " << (*mymap.upper_bound( 50 )).second << std::endl;

// 	std::cout << "----tree end---" << std::endl;


// 	// std::cout << "60th element is " << check.first->second << " and " << check.second << std::endl;


// 	std::cout << "std map test---------------------" << std::endl;

// 	std::map<int, int> mapp;
// 	mapp.insert( std::make_pair( 30, 30 ) );
// 	mapp.insert( std::make_pair( 20, 20 ) );
// 	mapp.insert( std::make_pair( 50, 50 ) );
// 	mapp.insert( std::make_pair( 15, 15 ) );
// 	mapp.insert( std::make_pair( 25, 25 ) );
// 	mapp.insert( std::make_pair( 40, 40 ) );
// 	mapp.insert( std::make_pair( 35, 35 ) );
// 	mapp.insert( std::make_pair( 45, 45 ) );
// 	mapp.insert( std::make_pair( 55, 55 ) );
// 	mapp[17] = 17;
// 	mapp.erase( 40 );

// 	std::cout << "the tree is built" << std::endl;
// 	std::cout << "full tree:" << std::endl;
// 	for(std::map<int, int>::iterator itt = mapp.begin(); itt != mapp.end(); itt++) {

// 		std::cout << itt->second << std::endl;
// 	}

// 	std::cout << " equal range is" << std::endl;
// 	std::cout << (*mapp.upper_bound( 50 )).second << " " << (*mapp.upper_bound( 50 )).second << std::endl;







// 	// 	ft::map<int, int> mymap1;
// 	// 	mymap1.insert( ft::make_pair( 30, 30 ) );
// 	// 	mymap1.insert( ft::make_pair( 20, 20 ) );
// 	// 	mymap1.insert( ft::make_pair( 50, 50 ) );
// 	// 	std::cout << "size1 is " << mymap1.size() << std::endl;
// 	// 	ft::map<int, int> mymap2( mymap1 );
// 	// 	for(ft::map<int, int>::iterator itt = mymap2.begin(); itt != mymap2.end(); itt++) {

// 	// 		std::cout << itt->second << std::endl;
// 	// 	}
// 	// 	std::cout << "size2 is " << mymap2.size() << std::endl;
// }

#define T1 char
#define T2 int
#define TESTED_NAMESPACE ft
template <class MAP>
void	cmp( const MAP& lhs, const MAP& rhs )
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############" << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs < rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs > rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main( void )
{
	TESTED_NAMESPACE::map<T1, T2> mp1;
	TESTED_NAMESPACE::map<T1, T2> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	// cmp( mp1, mp1 ); // 0
	// cmp( mp1, mp2 ); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	// cmp( mp1, mp2 ); // 2
	// cmp( mp2, mp1 ); // 3

	(++(++mp1.begin()))->second = 42;

	cmp( mp1, mp2 ); // 4
	cmp( mp2, mp1 ); // 5

	swap( mp1, mp2 );

	cmp( mp1, mp2 ); // 6
	cmp( mp2, mp1 ); // 7

	return (0);
}