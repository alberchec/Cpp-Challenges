#include "calendar.h"

Calendar::Calendar(int d, int m, int y) : day(d), month(m), year(y){
	set_abs_date();
	set_month_length();
}

Calendar::Calendar(int abs_date) : abs_date(abs_date) {
	year = start_year;
	month = 1;
	day = 0;

	while(abs_date > 365){
		if(!leap_year() ){
			year++;
			abs_date -= 365; 
		}else if(abs_date > 366){
			year++;
			abs_date -= 366;
		}else{
			break;
		}
	}

	while(abs_date >= 28){
		set_month_length();
		if(abs_date > month_length){
			abs_date -= month_length;
			month++;
		}else{
			break;
		}
	}

	day = abs_date;

}

void Calendar::set_abs_date(){
	abs_date = 0;
	int year_diff = year - start_year;
	if(year_diff) abs_date = 1;
	abs_date += (year_diff - 1) / 4 + 365 * year_diff;

	for(int i=0;i<month-1;i++){
		if(i == 1 && leap_year() ) abs_date++;
		abs_date += months_length[i];
	}
	abs_date += day;
}

void Calendar::set_month_length(){
	bool leap = leap_year();

	if(month != 2){
		month_length = months_length[month - 1];
	}else if(leap){
		month_length = 29;
	}else{
		month_length = 28;
	}

	if(month == 1)    prev_month_length = 31;
	else if(month == 3){
		if(leap) prev_month_length = 29;
		else		  prev_month_length = 28;
	}else		      prev_month_length = months_length[month-2];

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
	int weekday = (abs_date - 1 + start_weekday) % 7;
	return weekday;
}

int Calendar::get_month_length(){
	return month_length;
}

int Calendar::get_abs_date(){
	return abs_date;
}

int Calendar::get_prev_m_len(){
	return prev_month_length;
}

std::string Calendar::get_date(){
	std::string date;
	date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	return date;
}