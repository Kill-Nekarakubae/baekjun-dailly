//
// Created by 조윤호 on 2023/07/12.
//
#include <unordered_map>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T = 3;
    int totalPoint[100001] = {0};
    int result[100001];

    cin >> N;

    for (int test = 0; test < T; ++test) {
        vector<pair<int, int> > v;
        for (int i = 0; i < N; ++i) {
            int t;
            cin >> t;
            v.push_back(pair<int, int>(t, i));
            totalPoint[i] += t;
        }

        sort(v.begin(), v.end(), greater<pair<int,int> >());

        for (int i = 0; i < v.size(); ++i) {
            if (i != 0 && v[i].first == v[i-1].first)
                result[v[i].second] = result[v[i - 1].second];
            else
                result[v[i].second] = i + 1;
        }

        for (int i = 0; i < N; ++i) {
            cout << result[i] << ' ';
        }
        cout << endl;
    }

    // 최종등수 출력
    vector<pair<int, int> > v;
    for (int i = 0; i < N; ++i) {
        v.push_back(pair<int, int>(totalPoint[i], i));
    }

    sort(v.begin(), v.end(), greater<pair<int,int> >());

    for (int i = 0; i < v.size(); ++i) {
        if (i != 0 && v[i].first == v[i-1].first)
            result[v[i].second] = result[v[i - 1].second];
        else
            result[v[i].second] = i + 1;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;


    return 0;
}