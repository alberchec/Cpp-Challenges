#include <iostream>
#include <vector>

using namespace std;

class Student {
private:
    vector<int> scores;
public:
    void input(){
        int n = 5;
        while(n--){
            int temp;
            cin >> temp;
            scores.push_back(temp);
        } 
    }
    int calculateTotalScore(){
        int total_score = 0;
        int n = 5;
        while(n--){
            total_score += scores[n];
        }

        return total_score;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    delete[] s;    
    
    return 0;
}
