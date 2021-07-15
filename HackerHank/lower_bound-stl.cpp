#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n,q;
    vector<int> v;

    cin >> n;
    while(n--){
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> q;
    while(q--){
        int y;
        cin >> y;
        vector<int>::iterator itr;
        itr = lower_bound(v.begin(),v.end(),y);

        if( *itr != y ){
            cout << "No" << ' ' << itr - v.begin() + 1 << endl;
        }else{
            cout << "Yes" << ' ' << itr - v.begin() + 1 << endl;
        }
    }
    return 0;
}