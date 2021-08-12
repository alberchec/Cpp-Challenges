#include <iostream>
#include <fstream>
#include "date.h"
#include "/Users/alberto/Desktop/Cpp-Challenges/MyOwn/Format_string/format_string.h"

using namespace std;

int main(){
	cout << "\nThis program creates a month calendar!\n\n";

	cout << "Enter the desired month number: ";
	int month;
	std::string month_name[12] = {"Janeiro","Fevereiro","Marco","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
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
	const string div_template = "<div class=\"{}\">{}</div>";

	int weekday = date.get_weekday();
	date -= weekday;
	
	int n = 0;
	while(n < 7){
		string class_content = "day";
		if(!n) class_content += " special_day";
		if(date.get_month() != month) class_content += " day_other_month";

		string content = to_string(date.get_day() );

		string temp = div_template;
		format_string(temp,class_content,content);
		days_div += temp;

		n++;
		if(n != 7){}
		else if(date.get_month() != month){}
		else if(date.get_day() != date.get_month_length() ) n = 0;
		date++;
	}

	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//OUTPUT HTML FILE

	pos = calendar_html.find("/--Replace_with_days--/");
	calendar_html.replace(pos,23,days_div);

	output << calendar_html;
	output.close();

}