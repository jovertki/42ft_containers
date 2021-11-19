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

class B {
public:
	char* l;
	int i;
	B() :l( nullptr ), i( 1 ) {};
	B( const int& ex ) {
		this->i = ex;
		this->l = new char( 'a' );
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A() :B() {};
	A( const B* ex ) {
		this->l = new char( *(ex->l) );
		this->i = ex->i;
		if(ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

int main() {
	// {
	// 	std::vector<int> vector;
		
	// 	std::vector<int> v;
	// 	vector.assign( 26000000, 1 );
	// 	v.push_back( *(vector.insert( vector.end() - 8000000, 44 )) );
	// 	v.push_back( vector.size() );
	// 	v.push_back( vector.capacity() );
	// 	std::unique_ptr<B> k2( new B( 3 ) );
	// 	std::unique_ptr<B> k3( new B( 4 ) );
	// 	std::unique_ptr<B> k4( new B( -1 ) );
	// 	std::vector<A> vv;
	// 	std::vector<B*> v1;

	// 	v1.push_back( &(*k2) );
	// 	v1.push_back( &(*k3) );
	// 	v1.push_back( &(*k4) );
	// 	try { vv.insert( vv.begin(), v1.begin(), v1.end() ); }
	// 	catch(const char* e) {
	// 			std::cout << e << std::endl;
	// 		v.push_back( vv.size() );
	// 		v.push_back( vv.capacity() );
	// 	}


	// 	std::cout << "OG vector" << std::endl;
	// 	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	// 		std::cout << *it << std::endl;
	// 	}
	// }
	
	{
		ft::vector<int> vector;

		std::vector<int> v;
		vector.assign( 26000000, 1 );
		v.push_back( *(vector.insert( vector.end() - 8000000, 44 )) );
		v.push_back( vector.size() );
		v.push_back( vector.capacity() );
		std::unique_ptr<B> k2( new B( 3 ) );
		std::unique_ptr<B> k3( new B( 4 ) );
		std::unique_ptr<B> k4( new B( -1 ) );
		ft::vector<A> vv;
		ft::vector<B*> v1;

		v1.push_back( &(*k2) );
		v1.push_back( &(*k3) );
		v1.push_back( &(*k4) );
		try { vv.insert( vv.begin(), v1.begin(), v1.end() ); }
		catch(const char* e) {
			std::string err = e;
			std::cout << err << std::endl;
			v.push_back( vv.size() );
			v.push_back( vv.capacity() );
		}

		std::cout << "MY vector" << std::endl;
		for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			std::cout << *it << std::endl;
		}
	}


	
}