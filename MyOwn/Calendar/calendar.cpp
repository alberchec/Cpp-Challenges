#include "calendar.h"

void Calendar::set_month_length(){
	if(leap_year(year) ){
		months_length[1] = 29;
	}else{
		months_length[1] = 28;
	}
}

bool Calendar::leap_year(){
	bool leap = false;

	if(year % 4) 		leap = false;
	else if(year % 100) leap = true;
	else if(year % 400) leap = false;
	else				leap = true;

	return leap;	
}

int Calendar::get_weekday(){
	set_month_length(year);
	int year_diff = year - start_year;
	int day_diff = 0;
	if(year_diff) day_diff = 1;
	day_diff = (year_diff - 1) / 4 + 365 * year_diff;

	for(int i=0;i<month-1;i++){
		day_diff += months_length[i];
	}
	day_diff += day - 1;

	int weekday = (day_diff + start_weekday) % 7;
	return weekday;
}