//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <sstream>

using namespace std;
#define pip pair<int, pair<int, int> >

vector<string> split(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

int getTimeDiffInMin(int h1,int m1,int h2,int m2){
    return h1 * 60 + m1 - h2 * 60 - m2;
}

vector<pip > gameHistory;

int main() {

    int N;
    cin >> N;
    int score = 0;

    int t1h = 0, t1m = 0, t2h = 0, t2m = 0;
    int ph = 0, pm = 0;

    for (int i = 0; i < N; ++i) {
        int team;
        string hourMinute;
        cin >> team >> hourMinute;

        vector<string> st = split(hourMinute, ':');
        int hour = stoi(st[0]);
        int minute = stoi(st[1]);

        if (score > 0) {
            t1m += getTimeDiffInMin(hour, minute, ph, pm);
        } else if (score < 0) {
            t2m += getTimeDiffInMin(hour, minute, ph, pm);
        }

        score = (team == 1) ? score + 1 : score - 1;

        ph = hour;
        pm = minute;
    }
    // last time
    int hour = 48;
    int minute = 0;

    if (score > 0) {
        t1m += getTimeDiffInMin(hour, minute, ph, pm);
    } else if (score < 0) {
        t2m += getTimeDiffInMin(hour, minute, ph, pm);
    }

    t1h = t1m / 60;
    t1m = t1m % 60;
    t2h = t2m / 60;
    t2m = t2m % 60;

    printf("%02d:%02d\n", t1h, t1m);
    printf("%02d:%02d\n", t2h, t2m);

    return 0;
}