//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pr pair<int, int>

int map[65][65];
bool visited[65][65];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int> > q;
    q.push(pr(0, 0));
    visited[0][0] = true;
    int dr[2] = {0, 1};
    int dc[2] = {1, 0};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int dist = map[r][c];
        if (dist==-1) break;

        for (int i = 0; i < 2; ++i) {
            int nr, nc;
            if (i == 0) {
                nr = r + dist;
                nc = c;
            } else {
                nr = r;
                nc = c + dist;
            }

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)continue;
            if (visited[nr][nc])continue;
            visited[nr][nc] = true;
            q.push(pr(nr, nc));
        }
    }

    if (visited[N-1][N-1])
        cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}