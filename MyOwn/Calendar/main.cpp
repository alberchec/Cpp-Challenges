#include <iostream>
#include <fstream>
#include "calendar.h"

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

	ifstream input("calendar.html");
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
	ofstream output(temp,ios::app);


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

	Calendar cal(1,month,year);
	string days_div = "";
	const string div_template = "<div class=\"{}\">{}</div>";

	int weekday = cal.get_weekday();

	int prev_len = cal.get_prev_m_len();

	for(int i=0;i<weekday;i++){
		string class_content = "day day_other_month";
		if(!i) class_content += " special_day";

		string content = to_string(prev_len - weekday + 1 + i);

		string temp = div_template;
		pos = temp.find("{}");
		temp.replace(pos,2,class_content);
		pos = temp.find("{}");
		temp.replace(pos,2,content);

		days_div += temp;
	}

	int m_len = cal.get_month_length();

	for(int i=1;i<=m_len;i++){
		string class_content = "day";
		if()
	}




	pos = calendar_html.find("/--Replace_with_days--/");
	calendar_html.replace(pos,23,days_div);





	output << calendar_html;
	output.close();





















	
}