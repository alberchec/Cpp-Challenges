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
		bool holiday;
		string text;
		bool operator < (const Special_dates_info& b) const {
			if(month > b.month) return false;
			if(month == b.month && day >= b.day) return false;
			return true;
		}
	};
	vector<Special_dates_info> v_sd;

	void fetch_data(std::string file_name){
		ifstream input(file_name);
		if(!input.is_open() ){
			cout << file_name << " not found!\n";
			exit(EXIT_SUCCESS);
		}

		bool holiday = false;
		if(file_name == "holidays.txt"){
			holiday = true;
		}

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
			sd.holiday = holiday;
			v_sd.push_back(sd);
		}
		input.close();
	}
public:
	Special_dates(){
		fetch_data("holidays.txt");
		fetch_data("relevant_dates.txt");
		fetch_data("birthdays.txt");

		std::sort(v_sd.begin(),v_sd.end() );
	}
	void display_data(){
		for(int i=0;i<v_sd.size();i++){
			cout << v_sd[i].day << '/';
			cout << v_sd[i].month << " - ";
			cout << v_sd[i].text << " - ";
			cout << v_sd[i].holiday << endl;
		}
	}
};



int main(){
	Special_dates sd;

	sd.display_data();
}