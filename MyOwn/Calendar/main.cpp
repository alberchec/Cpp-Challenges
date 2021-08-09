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

	output << calendar_html;
	
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//----------------------------------------------------------------//
	//ADD DAY BLOCKS TO HTML FILE

	
}