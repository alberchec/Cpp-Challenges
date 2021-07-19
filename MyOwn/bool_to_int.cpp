#include <iostream>
#include <deque>
using namespace std;

int main(){
	bool a[10] = {0,0,0,0,0,0,1,1,0,0};
	int result;

	for(int i = 0;i<10;i++){
		result = (result << 1) + a[i];
	}

	cout << result << endl;

	return 0;
}