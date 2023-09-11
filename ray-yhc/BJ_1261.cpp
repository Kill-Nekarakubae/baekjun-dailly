//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int map[101][101];
int dp[101][101];
int N, M;

struct compare {
    bool operator()(const pip a, const pip b) {
        return a.first > b.first;
    }
};

int main() {
    const int INF = 10001;
    cin >> M >> N;
    fill(dp[0], dp[101], INF);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >>c;
            map[i][j] = c - '0';
        }
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    priority_queue<pip, vector<pip >, compare> pq;
    pq.push(pip(0, pi(0, 0)));
    dp[0][0] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (dp[r][c] < d) continue;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            int cost = d + map[nr][nc];
            if (dp[nr][nc] > cost) {
                dp[nr][nc] = cost;
                pq.push(pip(cost, pi(nr, nc)));
            }
        }
    }

    cout << dp[N-1][M-1];

    return 0;
}