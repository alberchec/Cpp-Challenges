#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class Special_dates{
private:
	struct Special_dates_info{
		int day;
		int month;
		string text;
		bool operator < (const Special_dates_info& b) const {
			if(month > b.month) return false;
			if(month == b.month && day >= b.day) return false;
			return true;
		}
	};
	vector<Special_dates_info> v_sd;

	void get_data(std::ifstream& input){
		string data;
		
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

			Special_dates_info sd;
			sd.day = day;
			sd.month = month;
			sd.text = text;
			v_sd.push_back(sd);
		}
	}
public:
	Special_dates(){
		ifstream input("holidays.txt");
		if(!input.is_open() ){
			cout << "holidays.txt not found!\n";
			exit(EXIT_SUCCESS);
		}
		get_data(input);
		input.close();

		input.open("birthdays.txt");
		if(!input.is_open() ){
			cout << "birthdays.txt not found!\n";
			exit(EXIT_SUCCESS);
		}
		get_data(input);
		input.close();

		std::sort(v_sd.begin(),v_sd.end() );
	}
	void display_data(){
		for(int i=0;i<v_sd.size();i++){
			cout << v_sd[i].day << '/';
			cout << v_sd[i].month << " - ";
			cout << v_sd[i].text << endl;
		}
	}
};



int main(){
	Special_dates sd;

	sd.display_data();
}