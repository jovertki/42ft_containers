
#include <vector>
#include <iterator>
#include <iostream>
//how does this not segfault????
int main() {
	std::allocator<int> alloc;
	std::vector<int> pointer;


	
	pointer.push_back(1);
	pointer.push_back( 2 );
	pointer.push_back( 3 );
	for(int i = 0; i < 100; i++) {
		std::cout << pointer[i] << std::endl;
	}


	
}
