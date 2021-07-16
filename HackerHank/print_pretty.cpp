#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;

	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << nouppercase << setw(0) << hex << showbase;
		cout << (long)A << endl;

		cout << dec << setw(0xf) << right << showpos << setfill('_') << fixed << setprecision(2);
		cout << B << endl;
		
		cout << noshowpos << setprecision(9) << uppercase << scientific;
		cout << C << endl;
	}

	return 0;
}