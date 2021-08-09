#ifndef CALENDAR
#define CALENDAR

class Calendar{
private:
	int day;
	int month;
	int year;
	const int start_year = 2020; //Leap year
	const int start_weekday = 4; //Wednesday
	int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	void set_month_length();
public:
	Calendar(int d,int m,int y) : day(d), month(m), year(y){}
	bool leap_year(); //Conditions to occur a leap year
	int get_weekday();
	//int get_month_length(int,int);
};

#endif