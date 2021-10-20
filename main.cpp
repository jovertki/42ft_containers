
#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"
#include <string>
#include <vector>

int main() {
	{
		ft::vector<std::string> vector;
		vector.push_back( "First" );
		vector.push_back( "Second" );
		vector.push_back( "Third" );
		vector.push_back( "fourth" );
		vector.push_back( "Fith" );
		for(int i = 0; i < vector.size(); i++) {
			std::cout << vector[i] << std::endl;
		}
		vector.assign( 10, "LOLKEK" );
		for(int i = 0; i < vector.size(); i++) {
		std::cout << vector[i] << std::endl;
		}
		std::cout << "_____--------______" << std::endl;
		ft::vector<std::string> vector2( vector );
		
		for(int i = 0; i < vector2.size(); i++) {
			std::cout << vector2[i] << std::endl;
		}
		std::cout << "_____--------______" << std::endl;

		
		ft::vector<std::string> vector3;
		vector3 = vector;
		for(int i = 0; i < vector3.size(); i++) {
			std::cout << vector3[i] << std::endl;
		}
		vector3.assign( 5, "LULW" );
		for(int i = 0; i < vector3.size(); i++) {
			std::cout << vector3[i] << std::endl;
		}
		std::cout << "_____--------______" << std::endl;

		// vector3.resize( 7 );
		// for(int i = 0; i < vector3.size(); i++) {
		// 	std::cout << vector3[i] << std::endl;
		// }
		// std::cout << "_____--------______" << std::endl;


		ft::vector<std::string> vector4;
		vector4.push_back( "First to deref" );
		vector4.push_back( "Second to deref" );
		vector4.push_back( "THirrd to deref" );
		vector4.push_back( "Fourth to deref" );
		std::cout << *vector4.begin() << std::endl;
		ft::vector<std::string>::iterator it = vector4.begin();
		it++;
		it = it + 1;
		std::cout << *it << std::endl;
	}
	system( "leaks containers" );
}
