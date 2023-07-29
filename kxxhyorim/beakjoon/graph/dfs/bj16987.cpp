//
// Created by 김효림 on 2023/07/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int n, max_egg;
int egg[8][2]; // (내구도, 무게)

void dfs(int idx) {

    if (idx == n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (egg[i][0] <= 0) sum++;
        }
        if (sum > max_egg) max_egg = sum;
        return;
    }

    if (egg[idx][0] <= 0) {
        dfs(idx + 1);
        return;
    }
    bool canHit = false;
    for (int i = 0; i < n; i++) {
        if (i == idx || egg[i][0] <= 0) continue;
        canHit = true;
        egg[idx][0] -= egg[i][1];
        egg[i][0] -= egg[idx][1];
        dfs(idx + 1);
        egg[idx][0] += egg[i][1];
        egg[i][0] += egg[idx][1];
    }
    if (!canHit) dfs(idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 내구도 7, 무게 5 -> 3
    // 내구도 3, 무게 4 -> -3
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> egg[i][0] >> egg[i][1];
    }

    dfs(0);
    cout << max_egg;

    return 0;
}
