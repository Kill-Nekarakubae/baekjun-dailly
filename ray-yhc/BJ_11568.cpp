//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int N;
int card[1001];
int dp [1001];


int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> card[i];
    }

    int maxLis = 1;
    for (int i = 0; i < N; ++i) {
        int maximum = -1;
        for (int j = 0; j < i; ++j) {
            if (card[j] < card[i]) maximum = max(maximum, dp[j]);
        }
        if (maximum == -1)
            dp[i] = 1;
        else {
            dp[i] = maximum + 1;
            maxLis = max(maxLis, dp[i]);
        }
    }

    cout << maxLis;


    return 0;
}