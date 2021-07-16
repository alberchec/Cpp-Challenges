#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
        virtual void getdata(){}
        virtual void putdata(){}
};

class Professor : public Person{
    static int counter;
    int publications, cur_id;
    public:
        void getdata(){
            string name;
            int age, publ;
            cin >> name >> age >> publ;
            this->name=name;
            this->age=age;
            publications=publ;
            cur_id=counter;
        }
        void putdata(){
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
        Professor(){
            counter++;
        }
        ~Professor(){
            counter--;
        }
};

class Student : public Person{
    static int counter;
    int marks[6], cur_id;
    public:
        void getdata(){
            string name;
            int age;
            cin >> name >> age;
            for(int i=0;i<6;i++){
                cin >> marks[i];
            }
            this->name=name;
            this->age=age;
            cur_id=counter;
        }
        void putdata(){
            int grades=0;
            for(int i=0;i<6;i++){
                grades+=marks[i];
            }
            cout << name << ' ' << age << ' ' << grades << ' ' << cur_id << endl;
        }
        Student(){
            counter++;
        }
        ~Student(){
            counter--;
        }
};
int Professor::counter=0;
int Student::counter=0;



int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
