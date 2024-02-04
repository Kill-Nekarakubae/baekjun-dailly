#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> tops) {
    vector<vector<int>> dp(n, vector<int>(2, 0));
    int residue = 10007;

    if (tops[0]) {
        dp[0][0] = 3;
        dp[0][1] = 1;
    } else {
        dp[0][0] = 2;
        dp[0][1] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (tops[i]) {
            dp[i][0] = dp[i - 1][0] * 3 + dp[i - 1][1] * 2;
            dp[i][1] = dp[i - 1][0] * 1 + dp[i - 1][1] * 1;
        } else {
            dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1] * 1;
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }

        dp[i][0] %= residue;
        dp[i][1] %= residue;
    }

    return (dp[n - 1][0] + dp[n - 1][1]) % residue;
}


int main() {

    cout << solution(4, {1, 1, 0, 1}) << endl << endl;
    cout << solution(2, {0, 1}) << endl << endl;
    cout << solution(10, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) << endl << endl;

    return 0;
}
