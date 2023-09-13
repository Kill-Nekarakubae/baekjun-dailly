//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
#define pip pair<int, pair<int,int> >


int N, T;
vector<pair<int, int> > judangs;

int main() {
    cin >> N >> T;
    int maxL = 0;
    int maxR = 0;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        maxL = max(l, maxL);
        maxR = max(r, maxR);
        judangs.push_back(pair<int, int>(l, r));
    }

    int begin = maxL;
    int end = maxR+1;
    int minResult = 1000001;
    while (begin < end) {
        int S = (begin + end) >> 1;

        int sum = 0;
        int revenue = 0;
        for (auto p: judangs) {
            int t = min(S, p.second);
            sum += t;
            revenue += t - p.first;
        }


        if (sum >= T) {
            if (sum - revenue <= T) minResult = min(minResult, S);
            end = S;
        } else {
            begin = S + 1;
        }
    }
    if (minResult == 1000001) minResult = -1;
    cout << minResult;

    return 0;
}