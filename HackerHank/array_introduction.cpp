#include <iostream>

int main(){
	int n;
	std::cin >> n;

	int array[n];

	for(int i=0;i<n;i++){
		std::cin >> array[i];
	}

	for(int i=n-1;i>=0;i--){
		std::cout << array[i] << ' ';
	}
	
	std::cout << std::endl;

	return 0;
}