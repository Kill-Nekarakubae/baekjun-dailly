//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
#define pip pair<int, pair<int,int> >

bool cmp(pip a, pip b) {
    // pip {mdmId, heart, registered index}
    if (a.second.first == b.second.first)
        return a.second.second > b.second.second;
    return a.second.first > b.second.first;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pip > v; // pq{mdmId, heart, registered index}

    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;

        // 이미 등록되었다면 ++
        bool isRegistered = false;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].first == t) {
                v[i].second.first++;
                isRegistered = true;
                break;
            }
        }
        if(isRegistered) continue;

        // 들어갈 위치를 찾는다
        if (v.size() >= N) {
            sort(v.begin(), v.end(), cmp);
            v.pop_back();
        }

        // 들어간다
        v.push_back(pip(t, pair<int, int>(0, i)));
    }

    vector<int> vv;
    for (auto m: v) {
        vv.push_back(m.first);
    }
    sort(vv.begin(), vv.end());

    for (auto i: vv) {
        cout << i << " ";
    }
    return 0;
}