#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream output("result.txt");
	output.close();

	ofstream output2("result.txt", ios::app);

	string s;
	while(getline(cin,s)){
		output2 << s << endl;
	}
	return 0;
}