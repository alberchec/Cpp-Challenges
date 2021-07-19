#include <iostream>
#include <bitset>

int main(){
	int a = 24;

	std::cout << std::bitset<8>(a) << std::endl;
	
	a = a >> 2;

	std::cout << std::bitset<8>(a) << std::endl;

}