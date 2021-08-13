#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

struct Special_dates{
	int day;
	int month;
	string text;
};

int main(){
	string data;
	vector<Special_dates> v_sd;

	ifstream input("birthdays.txt");
	
	while(getline(input,data) ){
		int day,month;
		string text;
		stringstream ss;
		
		ss << data;
		ss >> day;
		ss.ignore(256,'/');
		ss >> month;
		ss.ignore(256,'-');

		while(ss >> data){
			if(text == ""){
				text = data;
			}else{
				text += " " + data;
			}
		}

		Special_dates sd;
		sd.day = day;
		sd.month = month;
		sd.text = text;
		v_sd.push_back(sd);
	}

	for(int i=0;i<v_sd.size();i++){
		cout << v_sd[i].day << '/';
		cout << v_sd[i].month << " - ";
		cout << v_sd[i].text << endl;
	}
}