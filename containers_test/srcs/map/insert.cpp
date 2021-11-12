#include "common.hpp"

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp, mp2;

	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 42, "lol" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}

	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 42, "mdr" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}
	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 50, "mdr" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}
	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 35, "funny" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}
	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 45, "bunny" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}
	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 21, "fizz" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}
	{
		_pair<iterator, bool> tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( T3( 38, "buzz" ) );
		std::cout << "insert return: " << printPair( tmp.first );
		std::cout << "Created new node: " << tmp.second << std::endl;
		printSize( mp );
	}
	{
		iterator tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( mp.begin(), T3( 55, "fuzzy" ) );
		std::cout << "insert return: " << printPair( tmp );
		printSize( mp );
	}

	{
		iterator tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp.insert( mp.begin(), T3( 55, "fuzzy" ) );
		std::cout << "insert return: " << printPair( tmp );
		printSize( mp );
	}
	
	{
		iterator tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp2.insert( mp2.begin(), T3( 1337, "beauty" ) );
		std::cout << "insert return: " << printPair( tmp );
		printSize( mp2 );
	}
	{
		iterator tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp2.insert( mp2.end(), T3(1000, "Hello") );
		std::cout << "insert return: " << printPair( tmp );
		printSize( mp2 );
	}
	{
		iterator tmp;

		std::cout << "\t-- [" << iter++ << "] --" << std::endl;
		tmp = mp2.insert( mp2.end(), T3( 1500, "World" ) );
		std::cout << "insert return: " << printPair( tmp );
		printSize( mp2 );
	}

	return (0);
}
