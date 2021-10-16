


#include <iostream>

int main() {
	std::allocator<int> alloc;
	int* pointer = alloc.allocate( 5 );
	pointer[0] = 1;
	pointer[1] = 2;
	pointer[2] = 3;
	pointer[3] = 4;
	pointer[4] = 5;
	pointer[5] = 6;
	for(int i = 0; i < 6; i++) {
		std::cout << pointer[i] << std::endl;
	}
}