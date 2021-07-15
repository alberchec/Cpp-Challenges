#include <iostream>
#include <set>

using namespace std;

int main(){
	int q;
	set<int> s;
	cin >> q;

	while(q--){
		int y,x;
		cin >> y >> x;

		if(y == 1){
			s.insert(x);
		}else if(y == 2){
			s.erase(x);
		}else if(y == 3){
			set<int>::iterator itr;
			itr = s.find(x);
			if(itr == s.end()){
				cout << "No" << endl;
			}else{
				cout << "Yes" << endl;
			}
		}
	}
	return 0;
}