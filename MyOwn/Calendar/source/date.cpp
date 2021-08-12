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
	int year_ = start_year;
	while(year_ < year){
		if(leap_year(year_) ) abs_date += 366;
		else			abs_date += 365;
		year_++;
	}

	for(int i=0;i<month-1;i++){
		if(i == 1 && leap_year(year) ) abs_date++;
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
		if(!leap_year(year) ){
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
	bool leap = leap_year(year);

	if(month != 2){
		month_length = months_length[month - 1];
	}else if(leap){
		month_length = 29;
	}else{
		month_length = 28;
	}

}

bool Date::leap_year(int y){
	bool leap = false;

	if(y % 4) 		leap = false;
	else if(y % 100) leap = true;
	else if(y % 400) leap = false;
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

Date& operator_overload(Date& date, int val){
	int abs_date = date .get_abs_date();
	abs_date += val;
	date.set_date(abs_date);
	return date;
}

Date& operator + (Date& date, int add){
	return operator_overload(date,add);
}

Date& operator - (Date& date, int subtract){
	return operator_overload(date,-subtract);
}

Date& operator += (Date& date, int add){
	return operator_overload(date,add);
}

Date& operator -= (Date& date, int subtract){
	return operator_overload(date,-subtract);
}

Date& operator ++ (Date& date, int){
	return operator_overload(date,1);
}

Date& operator -- (Date& date, int){
	return operator_overload(date,-1);
}