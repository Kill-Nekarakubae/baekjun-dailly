//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;
#define MAX_K 10001

int N, M;
int dp[MAX_K];
int coin[100];


int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> coin[i];
    }


    fill(dp, dp + MAX_K, MAX_K);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = coin[i]; j <= M; ++j) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    int res = (dp[M] == MAX_K) ? -1 : dp[M];

    cout <<res << endl;

    return 0;
}