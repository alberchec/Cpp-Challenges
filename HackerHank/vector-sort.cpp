#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n;
    vector<int> v;
    cin >> n;

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
