#include <iostream>
#include "calendar.h"
using namespace std;

int main(){
	Calendar cal;
	cout << cal.get_weekday(1,7,2067) << endl;
}