#ifndef CALENDAR
#define CALENDAR

class Calendar{
private:
	static const int start_year = 2020; //Leap year
	static const int start_weekday = 3; //Wednesday
	static constexpr int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day;
	int month;
	int year;
	int absolute_date;
	int month_length;
	int prev_month_length;
	void abs_date();
	void set_month_length();
public:
	Calendar(int,int,int);
	bool leap_year(); //Conditions to occur a leap year
	int get_weekday();
	int get_month_length();
	int get_abs_date();
	int get_prev_m_len();
};

#endif