#include <iostream>

int main(){
	std::string number_names[] = {"one","two","three","four","five",
								  "six","seven","eight","nine"};
	int init, final;
	std::cin >> init >> final;

	for(int i=init;i<=final;i++){
		if(i <= 9){
			std::cout << number_names[i - 1] << std::endl;
		}else{
			if(i % 2)
				std::cout << "odd" << std::endl;
			else
				std::cout << "even" << std::endl;
		}
	}

	return 0;
}