// #include <vector>
// #include <iterator>
// #include <iostream>
// #include "vector.hpp"
// #include <string>
// #include <vector>
// #include <list>



// //map
// #include "map.hpp"
// #include <map>




// #define GOOD std::cout << "\033[1;32mGOOD\033[0m\n";
// #define BAD std::cout << "\033[1;31mBAD\033[0m\n";





// // int main() {


// // 	std::cout << "my map test---------------------" << std::endl;
// // 	ft::map<int, int> mymap;
// // 	mymap.insert( ft::make_pair( 30, 30 ) );
// // 	mymap.insert( ft::make_pair( 20, 20 ) );
// // 	mymap.insert( ft::make_pair( 50, 50 ) );
// // 	mymap.insert( ft::make_pair( 15, 15 ) );
// // 	mymap.insert( ft::make_pair( 25, 25 ) );
// // 	mymap.insert( ft::make_pair( 40, 40 ) );
// // 	mymap.insert( ft::make_pair( 35, 35 ) );
// // 	mymap.insert( ft::make_pair( 45, 45 ) );
// // 	mymap.insert( ft::make_pair( 55, 55 ) );
// // 	mymap[17] = 17;


// // 	std::cout << "the tree is built" << std::endl;
// // 	// mymap[70] = 70;
// // 	// mymap[80] = 80;
// // 	//	std::cout << "value to erase = " << ((++(++(++(mymap.begin())))))->second << std::endl;
// // 	mymap.erase( --mymap.end() );

// // 	// ft::pair<ft::map<int, int>::iterator, bool> check = mymap.insert( ft::make_pair( 60, 60 ) );

// // 	std::cout << "full tree:" << std::endl;
// // 	for(ft::map<int, int>::iterator itt = mymap.begin(); itt != mymap.end(); itt++) {

// // 		std::cout << itt->second << std::endl;
// // 	}

// // 	std::cout << " equal range is" << std::endl;
// // 	//	std::cout << (*mymap.upper_bound( 50 )).second << " " << (*mymap.upper_bound( 50 )).second << std::endl;

// // 	std::cout << "----tree end---" << std::endl;


// // 	// std::cout << "60th element is " << check.first->second << " and " << check.second << std::endl;


// // 	std::cout << "std map test---------------------" << std::endl;

// // 	std::map<int, int> mapp;
// // 	mapp.insert( std::make_pair( 30, 30 ) );
// // 	mapp.insert( std::make_pair( 20, 20 ) );
// // 	mapp.insert( std::make_pair( 50, 50 ) );
// // 	mapp.insert( std::make_pair( 15, 15 ) );
// // 	mapp.insert( std::make_pair( 25, 25 ) );
// // 	mapp.insert( std::make_pair( 40, 40 ) );
// // 	mapp.insert( std::make_pair( 35, 35 ) );
// // 	mapp.insert( std::make_pair( 45, 45 ) );
// // 	mapp.insert( std::make_pair( 55, 55 ) );
// // 	mapp[17] = 17;
// // 	mapp.erase( 40 );

// // 	std::cout << "the tree is built" << std::endl;
// // 	std::cout << "full tree:" << std::endl;
// // 	for(std::map<int, int>::iterator itt = mapp.begin(); itt != mapp.end(); itt++) {

// // 		std::cout << itt->second << std::endl;
// // 	}

// // 	std::cout << " equal range is" << std::endl;
// // 	std::cout << (*mapp.upper_bound( 50 )).second << " " << (*mapp.upper_bound( 50 )).second << std::endl;







// // 	// 	ft::map<int, int> mymap1;
// // 	// 	mymap1.insert( ft::make_pair( 30, 30 ) );
// // 	// 	mymap1.insert( ft::make_pair( 20, 20 ) );
// // 	// 	mymap1.insert( ft::make_pair( 50, 50 ) );
// // 	// 	std::cout << "size1 is " << mymap1.size() << std::endl;
// // 	// 	ft::map<int, int> mymap2( mymap1 );
// // 	// 	for(ft::map<int, int>::iterator itt = mymap2.begin(); itt != mymap2.end(); itt++) {

// // 	// 		std::cout << itt->second << std::endl;
// // 	// 	}
// // 	// 	std::cout << "size2 is " << mymap2.size() << std::endl;
// // }



// #define T1 int
// #define T2 std::string

// typedef ft::pair<const T1, T2> T3;
// #define TESTED_NAMESPACE ft

// template <typename T>
// std::string	printPair( const T& iterator, bool nl = true, std::ostream& o = std::cout )
// {
// 	o << "key: " << iterator->first << " | value: " << iterator->second;
// 	if(nl)
// 		o << std::endl;
// 	return ("");
// }


// template <typename T_MAP>
// void	printSize( T_MAP const& mp, bool print_content = 1 )
// {
// 	std::cout << "size: " << mp.size() << std::endl;
// 	std::cout << "max_size: " << mp.max_size() << std::endl;
// 	if(print_content)
// 	{
// 		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for(; it != ite; ++it)
// 			std::cout << "- " << printPair( it, false ) << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

// static int iter = 0;

// template <typename MAP>
// void	ft_erase( MAP& mp, const T1 param )
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.erase( param );
// 	printSize( mp );
// }

// int		main( void )
// {
// 	TESTED_NAMESPACE::map<T1, T2> mp;

// 	mp[42] = "lol";

// 	mp[50] = "mdr";
// 	mp[25] = "funny";

// 	mp[46] = "bunny";
// 	mp[21] = "fizz";
// 	mp[30] = "buzz";
// 	mp[55] = "fuzzy";

// 	mp[18] = "bee";
// 	mp[23] = "coconut";
// 	mp[28] = "diary";
// 	mp[35] = "fiesta";
// 	mp[44] = "hello";
// 	mp[48] = "world";
// 	mp[53] = "this is a test";
// 	mp[80] = "hey";

// 	mp[12] = "no";
// 	mp[20] = "idea";
// 	mp[22] = "123";
// 	mp[24] = "345";
// 	mp[27] = "27";
// 	mp[29] = "29";
// 	mp[33] = "33";
// 	mp[38] = "38";

// 	mp[43] = "1";
// 	mp[45] = "2";
// 	mp[47] = "3";
// 	mp[49] = "4";
// 	mp[51] = "5";
// 	mp[54] = "6";
// 	mp[60] = "7";
// 	mp[90] = "8";

// 	printSize( mp );

// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    25                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       55
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
// 	 *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
// 	 *
// 	 * */

// 	std::cout << "HERE1" << std::endl;
// 	ft_erase( mp, 25 ); // right != NULL; left != NULL

// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       55
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \    /    \         \     /   \        /   \       /   \     /    \         /     \
// 	 *  12   20  22    24        29  33    38     43    45    47    49   51    54       60      90
// 	 *
// 	 * */

	
// 	std::cout << "HERE2" << std::endl;
// 	ft_erase( mp, 55 ); // right != NULL; left != NULL


	
// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       60
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \    /    \         \     /   \        /   \       /   \     /    \               \
// 	 *  12   20  22    24        29  33    38     43    45    47    49   51    54               90
// 	 *
// 	 * */


// 	std::cout << "HERE3" << std::endl;
// 	ft_erase( mp, 24 ); // right != NULL; left != NULL
// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       60
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \    /              \     /   \        /   \       /   \     /    \               \
// 	 *  12   20  22              29  33    38     43    45    47    49   51    54               90
// 	 *
// 	 * */

	
// 	std::cout << "HERE4" << std::endl;
// 	ft_erase( mp, 54 ); // right != NULL; left != NULL

// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       60
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \    /              \     /   \        /   \       /   \     /                   \
// 	 *  12   20  22              29  33    38     43    45    47    49   51                   90
// 	 *
// 	 * */




	
// 	std::cout << "HERE5" << std::endl;
// 	ft_erase( mp, 22 ); // right == NULL; left == NULL
// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       60
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \                   \     /   \        /   \       /   \     /                   \
// 	 *  12   20                  29  33    38     43    45    47    49   51                   90
// 	 *
// 	 * */

	
// 	std::cout << "HERE6" << std::endl;
// 	ft_erase( mp, 51 ); // right == NULL; left == NULL


// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          21                 30                       46                       60
// 	 *      /       \           /      \                /       \             /           \
// 	 *     18       23        28        35            44         48         53             80
// 	 *   /   \                   \     /   \        /   \       /   \                        \
// 	 *  12   20                  29  33    38     43    45    47    49                        90
// 	 *
// 	 * */



	

// 	std::cout << "HERE7" << std::endl;
// 	ft_erase( mp, 21 ); // right == NULL; left != NULL


// 	/* A classic btree should give this:
// 	 *                                      42
// 	 *                     /                                            \
// 	 *                    27                                            50
// 	 *           /                 \                         /                       \
// 	 *          20                 30                       46                       60
// 	 *      /        \         /      \                /       \             /           \
// 	 *     18        23       28        35            44         48         53             80
// 	 *   /                       \     /   \        /   \       /   \                        \
// 	 *  12                       29  33    38     43    45    47    49                        90
// 	 *
// 	 * */





	
// 	// std::cout << "HERE8" << std::endl;
// 	// ft_erase( mp, 53 ); // right != NULL; left == NULL

// 	// /* After deleting 22, 51 and then 21, 53, I would get:
// 	//  *                                      42
// 	//  *                     /                                            \
// 	//  *                    23                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          20                 30                       46                      80
// 	//  *      /                   /      \                /       \                /        \
// 	//  *     18                 28        35            44         48             60         90
// 	//  *   /                  /    \     /   \        /   \       /   \
// 	//  *  12                 27    29  33    38     43    45    47    49
// 	//  *
// 	//  * */
// 	// std::cout << "HERE9" << std::endl;
// 	// ft_erase( mp, 20 ); // right == NULL; left != NULL

// 	// /* After deleting 20, I would get:
// 	//  *                                      42
// 	//  *                     /                                            \
// 	//  *                    23                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          18                 30                       46                      80
// 	//  *      /                   /      \                /       \                /        \
// 	//  *     12                 28        35            44         48             60         90
// 	//  *                      /    \     /   \        /   \       /   \
// 	//  *                     27    29  33    38     43    45    47    49
// 	//  *
// 	//  * */
// 	// std::cout << "HERE10" << std::endl;
// 	// ft_erase( mp, 23 ); // right != NULL; left != NULL

// 	// /* After deleting 23, I would get:
// 	//  *                                      42
// 	//  *                     /                                            \
// 	//  *                    18                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          12                 30                       46                      80
// 	//  *                          /      \                /       \                /        \
// 	//  *                        28        35            44         48             60         90
// 	//  *                      /    \     /   \        /   \       /   \
// 	//  *                     27    29  33    38     43    45    47    49
// 	//  *
// 	//  * */
// 	// std::cout << "HERE11" << std::endl;
// 	// ft_erase( mp, 42 ); // right != NULL; left != NULL; parent == NULL

// 	// /* After deleting 42, I would get:
// 	//  *                                      38
// 	//  *                     /                                            \
// 	//  *                    18                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          12                 30                       46                      80
// 	//  *                          /      \                /       \                /        \
// 	//  *                        28        35            44         48             60         90
// 	//  *                      /    \     /            /   \       /   \
// 	//  *                     27    29  33           43    45    47    49
// 	//  *
// 	//  * */
// 	// std::cout << "HERE12" << std::endl;
// 	// ft_erase( mp, 38 ); // right != NULL; left != NULL; parent == NULL

// 	// /* After deleting 38, I would get:
// 	//  *                                      35
// 	//  *                     /                                            \
// 	//  *                    18                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          12                 30                       46                      80
// 	//  *                          /      \                /       \                /        \
// 	//  *                        28        33            44         48             60         90
// 	//  *                      /    \                  /   \       /   \
// 	//  *                     27    29               43    45    47    49
// 	//  *
// 	//  * */
// 	// std::cout << "HERE13" << std::endl;
// 	// ft_erase( mp, 35 ); // right != NULL; left != NULL; parent == NULL

// 	// /* After deleting 35, I would get:
// 	//  *                                      33
// 	//  *                     /                                            \
// 	//  *                    18                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          12                 30                       46                      80
// 	//  *                          /                       /       \                /        \
// 	//  *                        28                      44         48             60         90
// 	//  *                      /    \                  /   \       /   \
// 	//  *                     27    29               43    45    47    49
// 	//  *
// 	//  * */
// 	// std::cout << "HERE14" << std::endl;
// 	// ft_erase( mp, 33 ); // right != NULL; left != NULL; parent == NULL

// 	// /* After deleting 33, I would get:
// 	//  *                                      30
// 	//  *                     /                                            \
// 	//  *                    18                                            50
// 	//  *           /                 \                         /                      \
// 	//  *          12                 28                       46                      80
// 	//  *                          /      \                /       \                /        \
// 	//  *                        27       29             44         48             60         90
// 	//  *                                              /   \       /   \
// 	//  *                                            43    45    47    49
// 	//  *
// 	//  * */

// 	// return (0);
// }
