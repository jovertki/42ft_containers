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



#define TESTED_NAMESPACE ft
#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase( MAP& mp, U param )
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase( param );
	for (TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << (*it).first << "  " << (*it).second << std::endl;
}

template <typename MAP, typename U, typename V>
void	ft_erase( MAP& mp, U param, V param2 )
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase( param, param2 );
	for(TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << (*it).first << "  " << (*it).second << std::endl;
}

int		main( void )
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for(unsigned int i = 0; i < lst_size; ++i)
		lst.push_back( T3( i, std::string( (lst_size - i), i + 65 ) ) );
	TESTED_NAMESPACE::map<T1, T2> mp( lst.begin(), lst.end() );

	std::cout << "original" << std::endl;
	for(TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << (*it).first << "  " << (*it).second << std::endl;

	ft_erase( mp, ++mp.begin() );

	ft_erase( mp, mp.begin() );

	std::cout << (*(--mp.end())).second << std::endl;
	ft_erase( mp, --mp.end() ); // <- here is the evidence

	ft_erase( mp, mp.begin(), ++(++(++mp.begin())) );
	ft_erase( mp, --(--(--mp.end())), --mp.end() );//<-incorrect size

	mp[10] = "Hello";
	mp[11] = "Hi there";
	std::cout << "with new elements" << std::endl;
	for(TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << (*it).first << "  " << (*it).second << std::endl;
	ft_erase( mp, --(--(--mp.end())), mp.end() );


	ft::vector<int> vec;
	vec.push_back( 234 );
	ft::vector<int>::iterator it = vec.begin();
	std::cout << *it << std::endl;

	vec.insert( it, 2, 3 );
	
}