class Calendar{
private:
	const int start_year = 2020; //Leap year
	const int start_weekday = 4; //Wednesday
	int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	void set_month_length(int year){
		if(year % 4){
			months_length[1] = 28;
		}else{
			months_length[1] = 29;
		}
	}
public:
	int get_weekday(int day, int month, int year){
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
};