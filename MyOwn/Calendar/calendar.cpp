#include <iostream>
using namespace std;

class Calendar{
private:
	const int start_year = 2020; //Leap year
	const int start_weekday = 4; //Wednesday
	std::string weekdays[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int months_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	void set_month_length(int year){
		if(year % 4){
			months_length[1] = 28;
		}else{
			months_length[1] = 29;
		}
	}
public:
	string get_weekday(int day, int month, int year){
		set_month_length(year);
		int year_diff = year - start_year;
		int day_diff = year_diff / 4 + 365 * year_diff;
		cout << day_diff << endl;

		for(int i=0;i<month-1;i++){
			day_diff += months_length[i];
		}

		day_diff += day - 1;

		int weekday = (day_diff + start_weekday) % 7;
		cout << weekday << endl;
		return weekdays[weekday];
	}
};

int main(){
	Calendar cal;
	std::cout << cal.get_weekday(1,7,2021) << std::endl;
	return 0;
}