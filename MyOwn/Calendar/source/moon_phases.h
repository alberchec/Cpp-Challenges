#ifndef MOON_PHASES
#define MOON_PHASES

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

struct Moon_phase_info{
	int day;
	int month;
	int moon_phase;

	bool operator < (const Moon_phase_info& b) const {
		if(month > b.month) return false;
		if(month != b.month){}
		else if(day > b.day) return false;
		return true;
	}
};

class Moon_dates{
private:
	std::vector<Moon_phase_info> moon_phase_dates;

	void fetch_data(std::string file_name){
		std::ifstream input(file_name);
		if(!input.is_open() ){
			std::cout << file_name << " not found!\n";
			exit(EXIT_SUCCESS);
		}

		std::string data;
		
		while(getline(input,data) ){
			if(data == "") continue;

			int day,month;
			std::stringstream ss;
			
			ss << data;
			ss >> day;
			ss.ignore(256,'/');
			ss >> month;
			ss.ignore(256,' ');

			ss >> data;

			int moon_phase = 0;

			if(data == "Nova") moon_phase = 1;
			else if(data == "Crescente") moon_phase = 2;
			else if(data == "Cheia") moon_phase = 3;
			else if(data == "Minguante") moon_phase = 4;

			Moon_phase_info mpi;
			mpi.day = day;
			mpi.month = month;
			mpi.moon_phase = moon_phase;
			moon_phase_dates.push_back(mpi);
		}
		input.close();
	}
public:
	Moon_dates(){
		fetch_data("moon_dates.txt");

		std::sort(moon_phase_dates.begin(),moon_phase_dates.end() );
	}
	int match(int day,int month){ //0 for non moon change, 1 for nova, 2 for crescente, 3 for cheia and 4 for minguante
		int moon_phase = 0;
		for(int i=0;i<moon_phase_dates.size();i++){
			if(moon_phase_dates[i].month != month) continue;
			if(moon_phase_dates[i].day != day) continue;
			else moon_phase = moon_phase_dates[i].moon_phase;
		}
		return moon_phase;
	}
};

#endif