//
// Created by 김효림 on 2023/07/22
//
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int T = 0; T < t; T++) {
        int j, n;
        cin >> j >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            int r, c;
            cin >> r >> c;
            v[i] = r * c;
            // 12, 10, 8, 9, 10
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int answer = 0;
        while (j > 0) {
            j -= v[answer++];
        }

        cout << answer << endl;

    }


    return 0;
}
