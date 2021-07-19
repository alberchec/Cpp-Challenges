#include <iostream>
#include <vector>
using namespace std;

int bit_calc(vector<bool> v){
	int result;
	if(v.size() == 1){
		return v[0];
	}
	int value = v[v.size() - 1];
	v.pop_back();

	result = (bit_calc(v) << 1) + value;
	return result;
}

int main(){
	vector<bool> v = {0,0,0,0,0,0,1,1,0,0};

	cout << bit_calc(v) << endl;

	return 0;
}