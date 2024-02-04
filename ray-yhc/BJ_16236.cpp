//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

#define pip pair<int, pair<int, int> >

using namespace std;
int mapp[21][21];
int N;
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

pair<int, int> current;
int level = 2;
int ex = 0;

int bfs() {
    bool visited[21][21];
    fill(visited[0], visited[N], false);
    queue<pip > q;
    q.push(pip(0, current));
    visited[current.first][current.second] = true;

    int minDist = 500;
    int minR, minC;

    while (!q.empty()) {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int d = q.front().first;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int dist = d+1;

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (visited[nr][nc]) continue;
            visited[nr][nc] = true;

            int size = mapp[nr][nc];
            if (size > level) continue;
            if (size == 0 || size == level) {
                q.push(pip(dist, pair<int, int>(nr, nc)));
                continue;
            }

            if (dist > minDist) continue;
            if (dist < minDist ||
                (nr < minR) ||
                (nr == minR && nc < minC)
                    ) {
                minR = nr;
                minC = nc;
                minDist = dist;
            }

        }
    }

    if (minDist == 500) return 0;

    mapp[minR][minC] = 0;
    ex++;
    if (ex >= level) ex -= (level++);
    current.first = minR;
    current.second = minC;

    return minDist;
}


void printmap() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mapp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mapp[i][j];
            if (mapp[i][j] == 9) {
                mapp[i][j] = 0;
                current = pair<int, int>(i, j);
            }
        }
    }

    int move = 0;
    while (true) {
        int m = bfs();
        if (m == 0)break;
        move += m;
//        printmap();
    }
    cout << move;
    return 0;
}