#include <climits>
#define toStr(value) #value
#define io(v) cin >> v
#define FUNCTION(x, y) void x(int& m, const int v) { if(v y m) m = v; }
#define INF INT_MAX
#define foreach(v,i) for(int i=0;i<v.size();i++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}