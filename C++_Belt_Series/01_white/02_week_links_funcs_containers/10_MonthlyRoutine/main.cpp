#include <iostream>
#include "vector"
#include "string"
using namespace  std;


vector<int> month_dur = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add(vector<vector<string>>& jobs, int month, int day, string job){
    jobs[day - 1].push_back(job);
}


void dump(vector<vector<string>>& jobs, int month, int day){
    cout << jobs[day-1].size() << " ";
    for(auto j : jobs[day - 1]){
        cout << j << " ";
    }
    cout << endl;
}


void next(vector<vector<string>>& jobs, int& month){
    int len_prev_m = month_dur[month];
    month ++;
    month = month % 12;
    if (len_prev_m > month_dur[month]){
        for(int d = month_dur[month]; d < 31; d ++){
            for(auto j : jobs[d]){
                jobs[month_dur[month] - 1].push_back(j);
            }
            jobs[d].clear();
        }
    }
}


int main() {

    vector<vector<string>> jobs(31); // month -> day -> jobs
    vector<string> day_jobs;
    for(int d = 0; d < 31; d ++){
        jobs.push_back(day_jobs);
    }

    int n;
    int month = 0;
    cin >> n;
    int inp;
    string job;
    string command;
    for(int i = 0; i < n; i ++){
        cin >> command;
        if (command == "ADD"){
            cin >> inp >> job;
            add(jobs, month, inp, job);
        }
        if (command == "DUMP"){
            cin >> inp;
            dump(jobs, month, inp);
        }
        if (command == "NEXT"){
            next(jobs, month);
        }
    }
    return 0;
}
