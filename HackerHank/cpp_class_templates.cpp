#include <iostream>
using namespace std;

#define endl '\n';

struct Optimizer {
    Optimizer() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
};
Optimizer opt;

template <class T>
class AddElements {
private:
    T elem;
public:
    AddElements(const T& element) : elem(element){}
    T add(const T& element) const{
        return elem + element;
    }
};

template <>
class AddElements<string> { 
private:
    string elem;
public:
    AddElements(const string& element) : elem(element){}
    string concatenate(const string& element) const{
        return elem + element;
    }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}