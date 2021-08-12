#ifndef CALENDAR
#define CALENDAR

#include <iostream>

class Calendar{
private:
	static const int start_year = 2020; //Leap year
	static const int start_weekday = 3; //Wednesday
	static constexpr int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day;
	int month;
	int year;
	int abs_date;
	int month_length;
	int weekday;
	void set_abs_date();
	void set_month_length();
	void set_weekday();
public:
	Calendar(int,int,int);
	Calendar(int);
	bool leap_year(); //Conditions to occur a leap year
	int get_weekday();
	int get_month_length();
	int get_abs_date();
	std::string get_date();
};

#endif