//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >

int dp[15001];

int main() {
    double rate = 1.2;
    int N;
    cin >> N;
    for (int i = 2; i <= rate * N; ++i) {
        dp[i] = i;
    }

    for (int i = 2; i <= N; ++i) {
        int imsii[15001];
        fill(imsii, imsii + (int) (rate * N) + 1, 0);
        imsii[i * 2] = dp[i] + 2;

        for (int j = i * 3; j < rate * N; j += i) {
            imsii[j] = imsii[j - i] + 1;
        }

        // refresh();
        for (int j = 2; j < rate * N; ++j) {
            int m = imsii[j];
            int n = dp[j + 1];
            if (n==0&&m==0) continue;
            if (n==0) {
                dp[j] = min(dp[j], m);
            } else if (m == 0) {
                dp[j] = min(dp[j], n+1);
            } else {
                dp[j] = min(dp[j], min(m, n+ 1));
            }
        }
    }

    cout << dp[N];

    return 0;
}