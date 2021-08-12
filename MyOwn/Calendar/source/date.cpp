#include "date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y){
	set_abs_date();
	set_month_length();
	set_weekday();
}

Date::Date(int abs_date) : abs_date(abs_date) {
	set_date();
	set_weekday();
}

void Date::set_abs_date(){
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

void Date::set_date(){
	year = start_year;
	month = 1;
	day = 0;
	int absolute_date = abs_date;

	while(absolute_date > 365){
		if(!leap_year() ){
			year++;
			absolute_date -= 365; 
		}else if(absolute_date > 366){
			year++;
			absolute_date -= 366;
		}else{
			break;
		}
	}

	while(absolute_date >= 28){
		set_month_length();
		if(absolute_date > month_length){
			absolute_date -= month_length;
			month++;
		}else{
			break;
		}
	}

	day = absolute_date;
}

void Date::set_date(int abs){
	abs_date = abs;
	set_date();
}

void Date::set_month_length(){
	bool leap = leap_year();

	if(month != 2){
		month_length = months_length[month - 1];
	}else if(leap){
		month_length = 29;
	}else{
		month_length = 28;
	}

}

bool Date::leap_year(){
	bool leap = false;

	if(year % 4) 		leap = false;
	else if(year % 100) leap = true;
	else if(year % 400) leap = false;
	else				leap = true;

	return leap;	
}

void Date::set_weekday(){
	weekday = (abs_date - 1 + start_weekday) % 7;
}

int Date::get_weekday(){
	return weekday;
}

int Date::get_month_length(){
	return month_length;
}

int Date::get_abs_date(){
	return abs_date;
}

std::string Date::get_date(){
	std::string date;
	date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	return date;
}

int Date::get_day(){
	return day;
}

int Date::get_month(){
	return month;
}

Date& operator + (Date& date, int add){
	int abs_date = date.get_abs_date();
	abs_date += add;
	date.set_date(abs_date);
	return date;
}

Date& operator - (Date& date, int subtract){
	int abs_date = date.get_abs_date();
	abs_date -= subtract;
	date.set_date(abs_date);
	return date;
}

Date& operator += (Date& date, int add){
	int abs_date = date.get_abs_date();
	abs_date += add;
	date.set_date(abs_date);
	return date;
}

Date& operator -= (Date& date, int subtract){
	int abs_date = date.get_abs_date();
	abs_date -= subtract;
	date.set_date(abs_date);
	return date;
}

Date& operator ++ (Date& date, int){
	int abs_date = date.get_abs_date();
	abs_date++;
	date.set_date(abs_date);
	return date;
}

Date& operator -- (Date& date, int){
	int abs_date = date.get_abs_date();
	abs_date--;
	date.set_date(abs_date);
	return date;
}