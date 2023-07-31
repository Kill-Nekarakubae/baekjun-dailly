//
// Created by 김효림 on 2023/07/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, cnt = 0;
    cin >> n >> s;
    vector<int> cow(n);

    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());

    for (int i = 0; i < n - 1; i++) {
        int idx = n - 1;
        for (int j = i + 1; j < n; j++) {
            if (cow[i] + cow[j] <= s) {
                cnt++;
            } else {
                idx = j;
                break;
            }
        }
        if (idx == i + 1) break;
    }

    cout << cnt;
    return 0;
}
