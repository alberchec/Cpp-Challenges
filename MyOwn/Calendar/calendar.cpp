#include "calendar.h"

Calendar::Calendar(int d, int m, int y) : day(d), month(m), year(y){
	absolute_date();
	set_month_length();
}

void Calendar::absolute_date(){
	absolute_date = 0;
	int year_diff = year - start_year;
	if(year_diff) absolute_date = 1;
	absolute_date = (year_diff - 1) / 4 + 365 * year_diff;

	for(int i=0;i<month-1;i++){
		if(i == 1 && leap_year() ) absolute_date++;
		absolute_date += months_length[i];
	}
	absolute_date += day;
}

void Calendar::set_month_length(){
	if(month != 2){
		month_length = months_length[month - 1];
	}else if(leap_year() ){
		month_length = 29;
	}else{
		month_length = 28;
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
	int year_diff = year - start_year;
	int day_diff = 0;
	if(year_diff) day_diff = 1;
	day_diff = (year_diff - 1) / 4 + 365 * year_diff;

	for(int i=0;i<month-1;i++){
		day_diff += month_length;
	}
	day_diff += day - 1;

	int weekday = (day_diff + start_weekday) % 7;
	return weekday;
}

int Calendar::get_month_length(){
	return month_length;
}