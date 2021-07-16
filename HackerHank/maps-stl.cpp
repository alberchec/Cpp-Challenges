#include <iostream>
#include <map>
using namespace std;


int main() {
    int q;
    cin >> q;
    map<string,int> m;

    while(q--){
        int x;
        string name;
        cin >> x >> name;

        switch(x){
            case 1:
                int grade;
                cin >> grade;
                if( m.find(name) == m.end() ){
                    m.insert( make_pair(name,grade) );    
                }else{
                    m[name] += grade;
                }
                break;
            case 2:
                m.erase(name);
                break;
            case 3:
                if( m.find(name) != m.end() ){
                    cout << m[name] << endl;
                }else{
                    cout << 0 << endl;
                }
                break;
        }
    }

    return 0;
}
