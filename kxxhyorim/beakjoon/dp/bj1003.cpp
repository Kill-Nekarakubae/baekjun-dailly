//
// Created by 김효림 on 2/4/24.
//

#include <iostream>

using namespace std;

int dp[41][2] = {{1, 0},
                 {0, 1}};

void printAnswer(int num) {
    cout << dp[num][0] << " " << dp[num][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n; // 40 이하

        if (n == 0 || n == 1) {
            printAnswer(n);
            continue;
        }

        if (dp[n][0] != 0) {
            printAnswer(n);
            continue;
        }

        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
        }

        printAnswer(n);
    }
    return 0;
}