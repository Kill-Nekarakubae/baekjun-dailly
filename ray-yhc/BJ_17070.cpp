//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;
#define MAX_N 17

int N;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][3];
queue<pair<int, int> > que;


int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> map[i][j];
        }
    }

    int dx[4] = {1, 0, 1};
    int dy[4] = {0, 1, 1};

    que.push(pair<int, int>(1, 2));
    visited[1][1] = true;
    visited[1][2] = true;

    dp[1][2][0] = 1;

    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if (nr > N || nr < 1 || nc > N || nc < 1) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;
            que.push(pair<int, int>(nr, nc));
        }

        if (map[r][c] == 1) continue;
        if (map[r][c - 1] == 1 && map[r - 1][c] == 1) continue;

        if (r == 1 || (map[r - 1][c - 1] == 1 && map[r - 1][c] == 1)) {
            dp[r][c][0] += dp[r][c - 1][0];
        } else if (c == 1 || (map[r - 1][c - 1] == 1 && map[r][c - 1] == 1)) {
            dp[r][c][2] += dp[r - 1][c][2];
        } else if (map[r - 1][c - 1] == 1) {
            dp[r][c][0] += dp[r][c - 1][0];
            dp[r][c][2] += dp[r - 1][c][2];
        } else if (map[r - 1][c] == 1) {
            dp[r][c][0] += dp[r][c - 1][0] + dp[r][c - 1][1];
        } else if (map[r][c - 1] == 1) {
            dp[r][c][2] += dp[r - 1][c][1] + dp[r - 1][c][2];
        } else {
            dp[r][c][0] += dp[r][c - 1][0] + dp[r][c - 1][1];
            dp[r][c][1] += dp[r - 1][c - 1][0] + dp[r - 1][c - 1][1] + dp[r - 1][c - 1][2];
            dp[r][c][2] += dp[r - 1][c][1] + dp[r - 1][c][2];
        }
    }

//    cout << endl << endl;
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j <= N; ++j) {
//            cout << '{' << dp[i][j][0] << ' ' << dp[i][j][1] << ' ' << dp[i][j][2] << "} ";
//        }
//        cout << endl;
//    }


    cout << (dp[N][N][0] + dp[N][N][1] + dp[N][N][2]) <<
         endl;

    return 0;
}