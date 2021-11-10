
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




// #define GOOD std::cout << "\033[1;32mGOOD\033[0m\n";
// #define BAD std::cout << "\033[1;31mBAD\033[0m\n";



// // ft::vector<std::string> create_vector() {
// // 	ft::vector<std::string>
// // }


// template< class T, class Alloc >
// bool operator==( const ft::vector<T, Alloc>& lhs,
// 	const std::vector<T, Alloc>& rhs ) {
// 	return ft::equal( lhs.begin(), lhs.end(), rhs.begin() );
// }



// int main() {
// 	// std::cout << " -----------VECTOR check----------------" << std::endl;
// 	// std::cout << " -----------Constructor check----------------" << std::endl;
// 	// {
// 	// 	std::cout << " -----Default-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	std::vector<std::string> vector2;
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
// 	// {
// 	// 	std::cout << "\n -----Fill-------" << std::endl;
// 	// 	ft::vector<std::string> vector( 3, "LOL" );
// 	// 	std::vector<std::string> vector2( 3, "LOL" );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
// 	// {
// 	// 	std::cout << "\n -----Range-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector( list.begin(), list.end() );
// 	// 	std::vector<std::string> vector2( list.begin(), list.end() );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
// 	// {
// 	// 	std::cout << "\n -----Copy-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector2( vector );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }


// 	// {
// 	// 	std::cout << "\n -----Operator==-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector2;
// 	// 	vector2 = vector;
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Assign (1)-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.assign( 3, "LOL" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.assign( 3, "LOL" );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Assign (2)-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
		
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.assign( list.begin(), list.end() );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.assign( list.begin(), list.end() );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// //get allocator???

// 	// {
// 	// 	std::cout << " -----------Element access check----------------" << std::endl;
// 	// 	std::cout << " -----at-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector.at(2) == vector2.at(2)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
	
// 	// {
// 	// 	std::cout << "\n -----Operator[]-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector[2] == vector2[2]) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Front-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector.front() == vector2.front()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Back-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector.back() == vector2.back()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
	
// 	// {
// 	// 	std::cout << "\n -----Data-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(*(vector.data()) == *(vector2.data())) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << " -----------Capacity check----------------" << std::endl;
// 	// 	std::cout << " -----Empty-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	std::vector<std::string> vector2;
// 	// 	if(vector.empty() && vector2.empty()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Size-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector.size() == vector2.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Max size-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector.max_size() == vector2.max_size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Capacity-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	if(vector.capacity() == vector2.capacity()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
	
// 	// {
// 	// 	std::cout << "\n -----Reserve-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.reserve( 5 );
		
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.reserve( 5 );
// 	// 	if(vector.capacity() == vector2.capacity()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << " -----------Modifiers check----------------" << std::endl;
// 	// 	std::cout << " -----Clear-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.clear();
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.clear();
// 	// 	if(vector.empty() && vector2.empty() && vector.size() == vector2.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
	
// 	// {
// 	// 	std::cout << "\n -----Insert (1)-------" << std::endl;
// 	// 	//insert in begin
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.insert( vector.begin(), "LOLKEKW" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.insert( vector2.begin(), "LOLKEKW" );
// 	// 	if(vector == vector2 && vector.size() == vector2.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
		
// 	// 	//insert in end
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	vector3.insert( vector3.end(), "LOLKEKW" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );
// 	// 	vector4.insert( vector4.end(), "LOLKEKW" );
// 	// 	if(vector3 == vector4 && vector3.size() == vector4.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//insert in random
// 	// 	ft::vector<std::string> vector5;
// 	// 	vector5.push_back( "A" );
// 	// 	vector5.push_back( "BB" );
// 	// 	vector5.push_back( "CCC" );
// 	// 	vector5.insert( vector5.begin() + 2, "LOLKEKW" );
// 	// 	std::vector<std::string> vector6;
// 	// 	vector6.push_back( "A" );
// 	// 	vector6.push_back( "BB" );
// 	// 	vector6.push_back( "CCC" );
// 	// 	vector6.insert( vector6.begin() + 2, "LOLKEKW" );
// 	// 	if(vector5 == vector6 && vector5.size() == vector6.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << "\n -----Insert (3)-------" << std::endl;
// 	// 	//insert in begin
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.insert( vector.begin(), 4, "LOLKEKW" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.insert( vector2.begin(), 4, "LOLKEKW" );
// 	// 	if(vector == vector2 && vector.size() == vector2.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//insert in end
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	vector3.insert( vector3.end(), 4, "LOLKEKW" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );
// 	// 	vector4.insert( vector4.end(), 4, "LOLKEKW" );
// 	// 	if(vector3 == vector4 && vector3.size() == vector4.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//insert in random
// 	// 	ft::vector<std::string> vector5;
// 	// 	vector5.push_back( "A" );
// 	// 	vector5.push_back( "BB" );
// 	// 	vector5.push_back( "CCC" );
// 	// 	vector5.insert( vector5.begin() + 2, 4, "LOLKEKW" );
// 	// 	std::vector<std::string> vector6;
// 	// 	vector6.push_back( "A" );
// 	// 	vector6.push_back( "BB" );
// 	// 	vector6.push_back( "CCC" );
// 	// 	vector6.insert( vector6.begin() + 2, 4, "LOLKEKW" );
// 	// 	if(vector5 == vector6 && vector5.size() == vector6.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
	
// 	// {
// 	// 	std::cout << "\n -----Insert (4)-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
// 	// 	//insert in begin
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "first" );
// 	// 	vector.push_back( "second" );
// 	// 	vector.push_back( "third" );
// 	// 	vector.push_back( "fourth" );
// 	// 	vector.insert( vector.begin(), list.begin(), list.end() );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "first" );
// 	// 	vector2.push_back( "second" );
// 	// 	vector2.push_back( "third" );
// 	// 	vector2.push_back( "fourth" );
// 	// 	vector2.insert( vector2.begin(), list.begin(), list.end() );
// 	// 	if(vector == vector2 && vector.size() == vector2.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//insert in end
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	vector3.insert( vector3.end(), list.begin(), list.end() );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );
// 	// 	vector4.insert( vector4.end(), list.begin(), list.end() );
// 	// 	if(vector3 == vector4) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//insert in random
// 	// 	ft::vector<std::string> vector5;
// 	// 	vector5.push_back( "A" );
// 	// 	vector5.push_back( "BB" );
// 	// 	vector5.push_back( "CCC" );
// 	// 	vector5.insert( vector5.begin() + 2, list.begin(), list.end() );
// 	// 	std::vector<std::string> vector6;
// 	// 	vector6.push_back( "A" );
// 	// 	vector6.push_back( "BB" );
// 	// 	vector6.push_back( "CCC" );
// 	// 	vector6.insert( vector6.begin() + 2, list.begin(), list.end() );
// 	// 	if(vector5 == vector6 && vector5.size() == vector6.size()) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }



// 	// {
// 	// 	std::cout << "\n -----Erase (1)-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
// 	// 	//erase in begin
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.erase( vector.begin());
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.erase( vector2.begin());
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//erase in end
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	vector3.erase( vector3.end() - 1);
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );
// 	// 	vector4.erase( vector4.end() - 1);
// 	// 	if(vector3 == vector4) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//erase in random
// 	// 	ft::vector<std::string> vector5;
// 	// 	vector5.push_back( "A" );
// 	// 	vector5.push_back( "BB" );
// 	// 	vector5.push_back( "CCC" );
// 	// 	vector5.erase( vector5.begin() + 2);
// 	// 	std::vector<std::string> vector6;
// 	// 	vector6.push_back( "A" );
// 	// 	vector6.push_back( "BB" );
// 	// 	vector6.push_back( "CCC" );
// 	// 	vector6.erase( vector6.begin() + 2);
// 	// 	if(vector5 == vector6) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }


	
// 	// {
// 	// 	std::cout << "\n -----Erase (2)-------" << std::endl;
// 	// 	//erase all
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.erase( vector.begin(), vector.end() );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.erase( vector2.begin() , vector2.end());
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// 	//erase in middle
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	vector3.erase( vector3.begin() + 1, vector3.end() - 1 );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );
// 	// 	vector4.erase( vector4.begin() + 1, vector4.end() - 1 );
// 	// 	if(vector3 == vector4) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }


// 	// {
// 	// 	std::cout << " -----Pop back-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.pop_back();
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.pop_back();
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << " -----Resize-------" << std::endl;
// 	// 	// resize to smaller
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.resize( 1 );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.resize( 1 );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	// resize to bigger 1 arg
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.resize( 5 );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.resize( 5 );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
// 	// {
// 	// 	// resize to bigger 2 arg
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	vector.resize( 5 , "LOLKEKW");
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	vector2.resize( 5, "LOLKEKW" );
// 	// 	if(vector == vector2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }

// 	// {
// 	// 	std::cout << " -----Swap-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector.push_back( "AAA" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "C" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector2.push_back( "AAA" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "C" );

// 	// 	vector.swap( vector3 );
// 	// 	vector2.swap( vector4 );
// 	// 	if(vector == vector2 && vector3 == vector4) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// 	std::cout << " -----------Modifiers check----------------" << std::endl;
// 	// {
// 	// 	std::cout << " -----Iterator-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	std::vector<std::string> out1;
// 	// 	std::vector<std::string> out2;
// 	// 	for(ft::vector<std::string>::iterator it = vector.begin(); it != vector.end(); it++) {
// 	// 		out1.push_back( *it );
// 	// 	}
// 	// 	for(std::vector<std::string>::iterator it = vector2.begin(); it != vector2.end(); it++) {
// 	// 		out2.push_back( *it );
// 	// 	}
// 	// 	if(out1 == out2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
// 	// {
// 	// 	std::cout << " -----Const iterator-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
// 	// 	const ft::vector<std::string> vector(list.begin(), list.end());
// 	// 	const std::vector<std::string> vector2( list.begin(), list.end() );
// 	// 	std::vector<std::string> out1;
// 	// 	std::vector<std::string> out2;
// 	// 	for(ft::vector<std::string>::const_iterator it = vector.begin(); it != vector.end(); it++) {
// 	// 		out1.push_back( *it );
// 	// 	}
// 	// 	for(std::vector<std::string>::const_iterator it = vector2.begin(); it != vector2.end(); it++) {
// 	// 		out2.push_back( *it );
// 	// 	}
// 	// 	if(out1 == out2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	std::cout << " -----Reverse iterator-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector( list.begin(), list.end() );
// 	// 	std::vector<std::string> vector2( list.begin(), list.end() );
// 	// 	std::vector<std::string> out1;
// 	// 	std::vector<std::string> out2;
// 	// 	for(ft::vector<std::string>::reverse_iterator it = vector.rbegin(); it != vector.rend(); it++) {
// 	// 		out1.push_back( *it );
// 	// 	}
// 	// 	for(std::vector<std::string>::reverse_iterator it = vector2.rbegin(); it != vector2.rend(); it++) {
// 	// 		out2.push_back( *it );
// 	// 	}
// 	// 	if(out1 == out2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }

// 	// {
// 	// 	std::cout << " -----Const Reverse iterator-------" << std::endl;
// 	// 	std::list<std::string> list;
// 	// 	list.push_back( "A" );
// 	// 	list.push_back( "BB" );
// 	// 	list.push_back( "CCC" );
// 	// 	const ft::vector<std::string> vector( list.begin(), list.end() );
// 	// 	const std::vector<std::string> vector2( list.begin(), list.end() );
// 	// 	std::vector<std::string> out1;
// 	// 	std::vector<std::string> out2;
// 	// 	for(ft::vector<std::string>::const_reverse_iterator it = vector.rbegin(); it != vector.rend(); it++) {
// 	// 		out1.push_back( *it );
// 	// 	}
// 	// 	for(std::vector<std::string>::const_reverse_iterator it = vector2.rbegin(); it != vector2.rend(); it++) {
// 	// 		out2.push_back( *it );
// 	// 	}
// 	// 	if(out1 == out2) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }

// 	// {
// 	// 	std::cout << " -----std::Swap-------" << std::endl;
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector.push_back( "AAA" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "C" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector2.push_back( "AAA" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "C" );
// 	// 	swap( vector, vector3 );
// 	// 	swap( vector2, vector4 );
// 	// 	if(vector == vector2 && vector3 == vector4) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// std::cout << " -----------Compare check----------------" << std::endl;
// 	// {
// 	// 	std::cout << " ----- == -------" << std::endl;
// 	// 	//equal
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );

// 	// 	if(vector == vector3 && vector2 == vector4) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	//non equal
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCCc" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCCc" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );

// 	// 	if(!(vector == vector3) && !(vector2 == vector4)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}
// 	// }
// 	// {
// 	// 	std::cout << " ----- < -------" << std::endl;
// 	// 	//yes
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCCc" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCCc" );

// 	// 	if((vector < vector3) && (vector2 < vector4)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	std::cout << " ----- <= -------" << std::endl;
// 	// 	//yes
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCC" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCC" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCCc" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCCc" );

// 	// 	if((vector <= vector3) && (vector2 <= vector4)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	std::cout << " ----- > -------" << std::endl;
// 	// 	//yes
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCCc" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCCc" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );

// 	// 	if((vector > vector3) && (vector2 > vector4)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	std::cout << " ----- >= -------" << std::endl;
// 	// 	//yes
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCCc" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCCc" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );

// 	// 	if((vector >= vector3) && (vector2 >= vector4)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }
// 	// {
// 	// 	std::cout << " ----- != -------" << std::endl;
// 	// 	//yes
// 	// 	ft::vector<std::string> vector;
// 	// 	vector.push_back( "A" );
// 	// 	vector.push_back( "BB" );
// 	// 	vector.push_back( "CCCc" );
// 	// 	std::vector<std::string> vector2;
// 	// 	vector2.push_back( "A" );
// 	// 	vector2.push_back( "BB" );
// 	// 	vector2.push_back( "CCCc" );
// 	// 	ft::vector<std::string> vector3;
// 	// 	vector3.push_back( "A" );
// 	// 	vector3.push_back( "BB" );
// 	// 	vector3.push_back( "CCC" );
// 	// 	std::vector<std::string> vector4;
// 	// 	vector4.push_back( "A" );
// 	// 	vector4.push_back( "BB" );
// 	// 	vector4.push_back( "CCC" );

// 	// 	if((vector != vector3) && (vector2 != vector4)) {
// 	// 		GOOD;
// 	// 	}
// 	// 	else {
// 	// 		BAD;
// 	// 	}

// 	// }

// 	// {
// 	// 	const int size = 10;
// 	// 	ft::vector<int> vct( size );
// 	// 	ft::vector<int>::iterator it_ = vct.begin();
// 	// 	ft::vector<int>::reverse_iterator it( it_ );
		
// 	// 	for(int i = 0; i < size; ++i) {
// 	// 		vct[i] = (i + 1) * 5;
// 	// 		std::cout << vct[i] << std::endl;
// 	// 	}

// 	// 	std::cout << "the stuff = " << *(it) << std::endl;
// 	// }
// 	// {
// 	// 	const int size = 10;
// 	// 	std::vector<int> vct( size );
// 	// 	std::vector<int>::iterator it_ = vct.begin();
// 	// 	std::vector<int>::reverse_iterator it( it_ );

// 	// 	for(int i = 0; i < size; ++i) {
// 	// 		vct[i] = (i + 1) * 5;
// 	// 		std::cout << vct[i] << std::endl;
// 	// 	}

// 	// 	std::cout << "the stuff = " << *(it) << std::endl;
// 	// }






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
// // 	mymap[60] = 60;


// // 	std::cout << "the tree is built" << std::endl;
// // 	// mymap[70] = 70;
// // 	// mymap[80] = 80;
// // 	std::cout << "value to erase = " << ((++(++(++(mymap.begin())))))->second << std::endl;
// // 	mymap.erase(10);
	
// // 	// ft::pair<ft::map<int, int>::iterator, bool> check = mymap.insert( ft::make_pair( 60, 60 ) );
	
// // 	std::cout << "full tree:" << std::endl;
// // 	for(ft::map<int, int>::iterator itt = mymap.begin(); itt != mymap.end(); itt++) {

// // 		std::cout << itt->second << std::endl;
// // 	}

// // 	std::cout << " equal range is" << std::endl;
// // 	std::cout << (*mymap.upper_bound( 50 )).second << " " << (*mymap.upper_bound( 50 )).second << std::endl;

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
// // 	mapp[60] = 60;


// // 	std::cout << "the tree is built" << std::endl;
// // 	std::cout << "full tree:" << std::endl;
// // 	for(std::map<int, int>::iterator itt = mapp.begin(); itt != mapp.end(); itt++) {

// // 		std::cout << itt->second << std::endl;
// // 	}
	
// // 	std::cout << " equal range is" << std::endl;
// // 	std::cout << (*mapp.upper_bound( 50 )).second << " " << (*mapp.upper_bound( 50 )).second << std::endl;







// // 	ft::map<int, int> mymap1;
// // 	mymap1.insert( ft::make_pair( 30, 30 ) );
// // 	mymap1.insert( ft::make_pair( 20, 20 ) );
// // 	mymap1.insert( ft::make_pair( 50, 50 ) );
// // 	std::cout << "size1 is " << mymap1.size() << std::endl;
// // 	ft::map<int, int> mymap2( mymap1 );
// // 	for(ft::map<int, int>::iterator itt = mymap2.begin(); itt != mymap2.end(); itt++) {

// // 		std::cout << itt->second << std::endl;
// // 	}
// // 	std::cout << "size2 is " << mymap2.size() << std::endl;
// // }


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
}

template <typename MAP, typename U, typename V>
void	ft_erase( MAP& mp, U param, V param2 )
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase( param, param2 );
}

int		main( void )
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for(unsigned int i = 0; i < lst_size; ++i)
		lst.push_back( T3( i, std::string( (lst_size - i), i + 65 ) ) );
	TESTED_NAMESPACE::map<T1, T2> mp( lst.begin(), lst.end() );

	ft_erase( mp, ++mp.begin() );

	ft_erase( mp, mp.begin() );
	ft_erase( mp, --mp.end() ); // <- here is the evidence
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin();
	for(; it != mp.end(); it++) {
		std::cout << (*it).first << "  " << (*it).second << std::endl;
	}

}