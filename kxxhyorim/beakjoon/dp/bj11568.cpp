//
// Created by 김효림 on 2023/07/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    int dp[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int t = 1; t < n; t++) { // target
        for (int b = 0; b <= t - 1; b++) { // before
            if (v[t] > v[b]) {
                dp[t] = max(dp[t], dp[b] + 1);
            }
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max)
            max = dp[i];
    }

    cout << max;


    return 0;
}
