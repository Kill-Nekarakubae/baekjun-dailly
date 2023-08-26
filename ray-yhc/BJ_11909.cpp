//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int mmap[2223][2223];
int cost[2223][2223];
bool visited[2223][2223];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mmap[i][j];
        }
    }

    int dr[2] = {0, 1};
    int dc[2] = {1, 0};

    queue<pi > q;
    q.push(pi(0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        int coR = 1000000000;
        int coC = 1000000000;
        if (r != 0) {
            coR = mmap[r][c] - mmap[r-1][c] + 1;
            coR = coR < 0 ? 0 : coR;
            coR += cost[r - 1][c];
        }
        if (c != 0) {
            coC = mmap[r][c] - mmap[r][c - 1] + 1;
            coC = coC < 0 ? 0 : coC;
            coC += cost[r][c - 1];
        }

        if (r != 0 || c != 0)
            cost[r][c] = min(coR, coC);

        for (int i = 0; i < 2; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= N || nc >= N) continue;
            if (visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push(pi(nr, nc));
        }
    }

    cout << cost[N - 1][N - 1];
    return 0;
}