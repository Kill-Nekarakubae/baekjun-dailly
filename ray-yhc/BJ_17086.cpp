//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int smap[51][51];
vector<pi > shark;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> smap[i][j];
            if (smap[i][j] == 1) shark.push_back(pi(i, j));
        }
    }

    int maxDist = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (smap[i][j] == 1) continue;

            int dist = 100;
            for (pi s: shark) {
                dist = min(dist, max(abs(s.first - i), abs(s.second - j)));
            }
            if (dist != 100)
                maxDist = max(dist, maxDist);
        }
    }

    cout << maxDist;

    return 0;
}