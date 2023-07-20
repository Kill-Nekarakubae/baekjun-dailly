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

    set<pair<int, int>> vol_set;
    vol_set.emplace(s, 0);

    int max_vol = -1;

    while (!vol_set.empty()) {
        int curr_vol = vol_set.begin()->first;
        int idx = vol_set.begin()->second;
        vol_set.erase(vol_set.begin());


        if (idx == n) {
            if (curr_vol > max_vol)
                max_vol = curr_vol;
            continue;
        }

        int next_vol1 = curr_vol + v[idx];
        int next_vol2 = curr_vol - v[idx];
        if (next_vol1 >= 0 && next_vol1 <= m) {
            vol_set.emplace(next_vol1, idx + 1);
        }
        if (next_vol2 >= 0 && next_vol2 <= m) {
            vol_set.emplace(next_vol2, idx + 1);
        }
    }

    cout << max_vol;

    return 0;
}
