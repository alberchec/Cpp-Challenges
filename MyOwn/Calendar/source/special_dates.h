#ifndef SPECIAL_DATES
#define SPECIAL_DATES

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

struct Special_dates_info{
	int day;
	int month;
	bool holiday;
	std::string text;
	bool operator < (const Special_dates_info& b) const {
		if(month > b.month) return false;
		if(month != b.month){}
		else if(day > b.day) return false;
		else if(day == b.day && text.compare(b.text) >= 0) return false;
		return true;
	}
};

class Special_dates{
private:
	std::vector<Special_dates_info> v_sd;

	void fetch_data(std::string file_name){
		std::ifstream input(file_name);
		if(!input.is_open() ){
			std::cout << file_name << " not found!\n";
			exit(EXIT_SUCCESS);
		}

		bool holiday = false;
		if(file_name == "holidays.txt"){
			holiday = true;
		}

		std::string data;
		
		while(getline(input,data) ){
			if(data == "") continue;

			int day,month;
			std::string text;
			std::stringstream ss;
			
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
			std::cout << v_sd[i].day << '/';
			std::cout << v_sd[i].month << " - ";
			std::cout << v_sd[i].text << " - ";
			std::cout << v_sd[i].holiday << std::endl;
		}
	}
	int match(int day,int month){ //0 for not special date, 1 for birthdays or relevant_dates, 2 for holidays and 3 for holidays with birthdates
		bool holiday = false;
		bool other_dates = false;
		for(int i=0;i<v_sd.size();i++){
			if(v_sd[i].month != month) continue;
			if(v_sd[i].day != day) continue;
			if(v_sd[i].holiday) holiday = true;
			else other_dates = true;
		}
		
		if(holiday && other_dates) return 3;
		if(holiday) return 2;
		if(other_dates) return 1;
		return 0;
	}
	std::vector<Special_dates_info> match_info(int day,int month){
		std::vector<Special_dates_info> v;
		for(int i=0;i<v_sd.size();i++){
			if(v_sd[i].month != month) continue;
			if(v_sd[i].day == day) {
				v.push_back(v_sd[i]);
			}
		}
		return v;
	}
};

#endif