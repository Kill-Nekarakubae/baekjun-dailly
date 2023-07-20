//
// Created by 김효림 on 2023/07/19.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, m;
    cin >> n >> s >> m;
    vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool dp[51][1001];
    dp[0][s] = true;

    for (int y = 1; y <= n; y++) {
        for (int x = 0; x <= m; x++) {
            if (dp[y - 1][x]) {
                if (x + v[y] <= m) {
                    dp[y][x + v[y]] = true;
                }
                if (x - v[y] >= 0) {
                    dp[y][x - v[y]] = true;
                }
            }
        }
    }

    int max_vol = -1;
    for (int x = m; x >= 0; x--) {
        if (dp[n][x] == 1) {
            max_vol = dp[n][x];
            break;
        }
    }

    cout << max_vol;
    return 0;
}
