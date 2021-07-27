#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string get_number(){
	static int number = 1;
	stringstream ss;
	ss << 'A' << setw(2) << setfill('0') << number;
	number++;
	return ss.str();
}

int main(){
	ifstream input("numbers.html");
	if(!input.is_open()) return 1;

	string s,data = "";
	while(getline(input,s) ){
		data += s;
	}

	string html1 =  "<div class='main'> \
					<div class='numbers'>";
	string html2 = "&#8681;</div> \
					<div class='numbers'>";
	string html3 = "&#8681;</div> \
					</div>";

	string html_add="";

	for(int i=0;i<45;i++){
		html_add += html1 + get_number();
		html_add += html2 + get_number() + html3;
	}

	int pos = data.find("Replace_numbers_here");

	data.replace(pos,20,html_add);

	ofstream output("numbers2.html");
	output << data;

	return 0;
}