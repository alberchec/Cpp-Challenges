#include <iostream>

int main(){
	std::string a,b;
	std::cin >> a >> b;

	int size_a,size_b;

	size_a = a.size();
	size_b = b.size();

	std::cout << size_a << ' ' << size_b << std::endl;

	std::string response;
	response = a + b;

	std::cout << response << std::endl;

	char temp;
	temp = a[0];
	a[0] = b[0];
	b[0] = temp;

	std::cout << a << ' ' << b << std::endl;
	return 0;
}