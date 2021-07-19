#include <iostream>

unsigned int factorial(unsigned int num){
	if(!num){
		return 1;
	}
	return num * factorial(num - 1);
}

int main(){
	int n;

	std::cout << "Enter a number to calculate factorial: ";
	std::cin >> n;

	if(n < 0){
		std::cout << "Error, number must be a positive integer!\n";
		return 1;
	}

	std::cout << "The result of " << n << "! is: " << factorial(n) << std::endl;

	return 0;
}