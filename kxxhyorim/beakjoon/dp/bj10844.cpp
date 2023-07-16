//
// Created by 김효림 on 2023/07/14.
//
#include <iostream>

using namespace std;

int dp[101][10];

int sumOfDpValue(int n) {
    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += (dp[n][i] % 1000000000);
    }
    return sum % 1000000000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    if (n == 1) {
        cout << sumOfDpValue(1);
        return 0;
    }

    for (int i = 2; i <= n; i++) { // 날짜
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000);
        }
        dp[i][9] = dp[i - 1][8];
    }

    cout << sumOfDpValue(n);

    return 0;
}
