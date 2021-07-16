#include<bits/stdc++.h>
//#include <iostream>

using namespace std;
#include <vector>

struct Workshop {
    int start_time;
    int duration;
    int end_time;

    bool operator < (const Workshop& ws) const{
        return end_time < ws.end_time;
    }
};

struct Available_Workshops {
    int n;
    vector<Workshop> ws;
};

Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    //aw->ws = new Workshop[n];

    for(int i=0;i<n;i++){
        Workshop wks;
        wks.start_time = start_time[i];
        wks.duration = duration[i];
        wks.end_time = start_time[i] + duration[i];
        aw->ws.push_back(wks);
    }
    sort(aw->ws.begin(),aw->ws.end());
    return aw;
}

int CalculateMaxWorkshops (Available_Workshops* ptr){
    int max_ws=0;
    int attending_end=0;

    for(int i=0; i < (ptr->n) ;i++){
        if(ptr->ws[i].start_time >= attending_end ){
            max_ws++;
            attending_end = ptr->ws[i].end_time;
        }
    }
    return max_ws;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}