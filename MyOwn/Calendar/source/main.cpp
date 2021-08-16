#include <iostream>
#include <fstream>
#include <vector>
#include "date.h"
#include "special_dates.h"
#include "format_html_chars.h"
#include "/Users/alberto/Desktop/Cpp-Challenges/MyOwn/Format_string/format_string.h"

using namespace std;

int main(){
	cout << "\nThis program creates a month calendar!\n\n";

	cout << "Enter the desired month number: ";
	int month;
	std::string month_name[12] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
	cin >> month;

	cout << "Enter the desired year: ";
	int year;
	cin >> year;

	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//FETCH HTML TEMPLATE FROM CALENDAR.HTML

	ifstream input("source/calendar.html");
	if(!input.is_open()){
		cout << "Calendar.html not found!\n";
		return 1;
	}

	string calendar_html = "",temp;
	while(getline(input,temp) ){
		calendar_html += temp;
	}

	input.close();

	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//CREATE MONTH HTML FILE

	temp = month_name[month-1] + "-" + to_string(year) + ".html";
	ofstream output(temp,ios::trunc);


	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//ADD MONTH NAME AND YEAR TO HTML FILE

	int pos = calendar_html.find("/--Replace_with_month--/");
	calendar_html.replace(pos,24,month_name[month-1]);

	pos = calendar_html.find("/--Replace_with_year--/");
	calendar_html.replace(pos,23,to_string(year) );
	
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//ADD DAY BLOCKS TO HTML FILE

	Date date(1,month,year);
	string days_div = "";
	string div_template = "<div class=\"{}\">{}</div>";
	Special_dates sd;

	int weekday = date.get_weekday();
	int month_length = date.get_month_length();
	date -= weekday;
	
	int n = 0;
	while(n < 7){
		int day_ = date.get_day();
		int month_ = date.get_month();
		int day_type = sd.match(day_,month_);
		string class_content = "day";
		
		if(!n) class_content += " special_day";
		else if(day_type > 1) class_content += " special_day";
		if(month_ != month) class_content += " day_other_month";

		string content = "";
		if(day_type == 1 || day_type == 3) content = "*";
		content += to_string(day_);

		string temp = div_template;
		format_string(temp,class_content,content);
		days_div += temp;

		n++;
		if(n != 7){}
		else if(month_ != month){}
		else if(day_ != month_length ) n = 0;
		date++;
	}

	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//ADD SPECIAL DATES BLOCKS TO HTML FILE

	string special_dates_div = "";
	div_template = "<p class=\"{}\"><b>{}</b> - {}</p>";

	for(int i=1;i<=month_length;i++){
		vector<Special_dates_info> v = sd.match_info(i,month);
		for(int j=0;j<v.size();j++){
			string temp = div_template;
			string holiday = "";
			if(v[j].holiday) holiday = "special_day";
			string day_ = to_string(v[j].day);
			format_string(temp,holiday,day_,v[j].text);
			special_dates_div += temp;
		}
	}


	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//OUTPUT HTML FILE

	pos = calendar_html.find("/--Replace_with_days--/");
	calendar_html.replace(pos,23,days_div);

	pos = calendar_html.find("/--Replace_with_commented_days--/");
	calendar_html.replace(pos,33,special_dates_div);

	//Format html chars
	format_html_chars(calendar_html);

	output << calendar_html;
	output.close();

}