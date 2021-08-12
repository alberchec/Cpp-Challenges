#ifndef DATE
#define DATE

#include <iostream>

class Date{
private:
	static const int start_year = 2020; //Leap year
	static const int start_weekday = 3; //Wednesday
	static constexpr int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int abs_date;
	int day;
	int month;
	int year;
	int weekday;
	int month_length;
	void set_abs_date();
	void set_date();
	void set_month_length();
	void set_weekday();
public:
	Date(int,int,int);
	Date(int);
	bool leap_year(); //Conditions to occur a leap year
	int get_abs_date();
	int get_day();
	int get_month();
	int get_weekday();
	int get_month_length();
	std::string get_date();
	void set_date(int);
};

Date& operator_overload(Date&,int);
Date& operator + (Date&,int);
Date& operator - (Date&,int);
Date& operator += (Date&,int);
Date& operator -= (Date&,int);
Date& operator ++ (Date&,int);
Date& operator -- (Date&,int);

#endif