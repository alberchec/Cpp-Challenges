#ifndef CALENDAR
#define CALENDAR

class Calendar{
private:
	const int start_year = 2020; //Leap year
	const int start_weekday = 4; //Wednesday
	int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	void set_month_length(int);
public:
	bool leap_year(int); //Conditions to occur a leap year
	int get_weekday(int,int,int);
};

#endif