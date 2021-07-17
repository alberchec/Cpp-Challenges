#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;

	if(n < 50) cout << "Less than 50\n";
	if(n >= 50) cout << "Greater or equal to 50\n";

	while(n--){
		int x;
		cin >> x;
		cout << "The number is: " << x << endl;
	}

	return 0;
}