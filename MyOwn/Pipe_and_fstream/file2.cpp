#include <iostream>
#include <fstream>

int main(int argc,char *argv[]){
	std::ofstream output(argv[1],std::ios::trunc);
	std::string s;
	while(getline(std::cin,s) ){
		output << s << std::endl;
	}
	
	return 0;
}