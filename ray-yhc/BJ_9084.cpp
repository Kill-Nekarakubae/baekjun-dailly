//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >

unsigned int dp[20][100001];

int main() {
    int T, N, M;
    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cin >> N;
        vector<int> coins;
        for (int i = 0; i < N; ++i) {
            int t;
            cin >> t;
            coins.push_back(t);
        }
        cin >> M;

        for (int i = 0; i < N; ++i) {
            if (i == 0 && coins[i]==1) {
                fill(dp[0] + 1, dp[0] + M + 1, 1);
                continue;
            }

            int c = coins[i];
            for (int j = 1; j <= M; ++j) {
                if (i==0) {
                    if (j%c == 0) dp[i][j] = 1;
                    else dp[i][j] = 0;
                    continue;
                }

                if (j<c) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                int count = dp[i - 1][j];

                if (j==c) {
                    if (j%c == 0) count++;
                } else {
                    count+= dp[i][j - c];
                }
                dp[i][j] = count;
            }
        }

        cout << dp[N - 1][M] << endl;
    }
    return 0;
}