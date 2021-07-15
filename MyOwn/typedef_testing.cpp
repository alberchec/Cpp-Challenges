#include <iostream>

class Car{
public:
	int a;
};

class Factory{
public:
	int b;
	typedef Car Bmw;
};

int main(){
	Factory::Bmw p;
	p.a=10;
	std::cout << p.a << std::endl;
}