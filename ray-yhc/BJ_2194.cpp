//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>

using namespace std;
bool gameMap[501][501] = {false};
bool visited[501][501] = {false};
int dp[501][501] = {0};

bool checkMap(int r, int c, int A, int B) {
    for (int rr = 0; rr < A; ++rr) {
        for (int cc = 0; cc < B; ++cc) {
            if (gameMap[r + rr][c + cc])
                return false;
        }
    }
    return true;
}

int main() {
    int N, M, A, B, K;
    cin >> N >> M >> A >> B >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        gameMap[r][c] = true;
    }

    int ir, ic, fr, fc;
    int dc[4] = {1, 0, -1, 0};
    int dr[4] = {0, 1, 0, -1};
    cin >> ir >> ic >> fr >> fc;

    if (ir==fr && ic==fc) {
        cout << 0;
        return 0;
    }

    // bfs
    queue<pair<int, int> > que;
    que.push(pair<int, int>(ir, ic));
    dp[ir][ic] = 0;
    visited[ir][ic] = true;

    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 1 || nc < 1 || nr + A - 1 > N || nc + B - 1 > M) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;

            if (!checkMap(nr, nc, A, B)) continue;

            // dp memo
            dp[nr][nc] = dp[r][c] + 1;
            que.push(pair<int, int>(nr, nc));
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int res = (dp[fr][fc] != 0) ? dp[fr][fc] : -1;
    cout << res;

    return 0;
}
