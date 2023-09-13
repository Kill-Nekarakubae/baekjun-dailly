//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;
int N, M;


struct hashFunction {
    size_t operator()(const pair<int, int> &x) const {
        return x.first ^ x.second;
    }
};

unordered_set<pair<int, int>, hashFunction> chess, visited;
int answer[500];

int main() {
    int x, y;
    int dx[8] = {2, 1, -1, -2, -2, -2, 1, 2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    cin >> N >> M;
    cin >> x >> y;
    for (int i = 0; i < M; ++i) {
        int xx, yy;
        cin >> xx >> yy;
        chess.insert(pair<int, int>(xx, yy));
    }

    queue<pair<int, int> > q;
    q.push(pair<int, int>(x, y));
    visited.insert(pair<int, int>(x, y));

    int count = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (chess.find(pair<int, int>(cx, cy)) != chess.end()) answer[];

        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited.find(pair<int, int>(nx, ny)) == visited.end()) continue;


            q.push(pair<int, int>(nx, ny));
            visited.insert(pair<int, int>(nx, ny));
        }
    }


    return 0;
}

// 15
// BJBOJOJOOJOBOJO