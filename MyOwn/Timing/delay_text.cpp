#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

#define delay(x) this_thread::sleep_for(chrono::milliseconds(x));

void print_slow(string s){
	for(int i=0;i<s.size();i++){
		cout << s[i] << flush;
		delay(100);
	}
	delay(1000);
}

void erase_slow(string s){
	for(int i=0;i<s.size();i++){
		cout << "\b \b" << flush;
		delay(100);
	}
	delay(500);
}

void cursor(){
	bool state = false;
	while(true){
		if(state){
			cout << ' ' << flush;
			delay(400);
		}
		else{
			cout << '_' << flush;
			delay(600);
		}
		cout << "\b \b" << flush;
		state = !state;
	}
}

int main(){
	//cursor();
	string s = "Dynamic text";
	print_slow(s);
	erase_slow(s);
	s = "Another text";
	print_slow(s);
	erase_slow(s);
	return 0;
}