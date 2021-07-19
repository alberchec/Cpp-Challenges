#include <iostream>

//template<typename = void>
int sum(){return 0;}

template<class...T>
int sum(int a, int...args){
	int temp = a + sum(args...);
	return temp;
}

int main(){
	
	std::cout << sum(1,2,3,4,5,6,7) << std::endl;
	return 0;
}