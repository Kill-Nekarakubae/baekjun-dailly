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
#define pip pair<int, pair<int,int> >

int N, M;
int maxSteps = 150;
unordered_set<int> us;

int dp[10001][2];

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        us.insert(t);
    }

    if (us.find(2) != us.end()) {
        cout << -1;
        return 0;
    }

    fill(&dp[0][0], &dp[N][2], -1);
    dp[1][0] = 0;
    dp[1][1] = 0;
    for (int cp = 1; cp <= N; ++cp) {
        int step = dp[cp][1];
        for (int d = -1; d <= 1; ++d) {
            int np = cp + step + d;
            if (np<=1 || np > N) continue;
            if (us.find(np)!=us.end())continue;

            if (dp[np][0] == -1 ||
                    dp[np][0] > dp[cp][0] + 1) {
                dp[np][0] = dp[cp][0] + 1;
                dp[np][1] = step + d;
            } else if (dp[np][0] == dp[cp][0] + 1) {
                dp[np][1] = max(dp[np][1], step + d);
            }
        }
    }
    cout << dp[N][0];

    return 0;
}
