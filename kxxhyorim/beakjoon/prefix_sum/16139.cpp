//
// Created by 김효림 on 2023/07/25.
//
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int arr[26][200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    char a;
    cin >> s;
    int q, l, r;

    for (int i = (int) 'a'; i <= 'z'; i++) {
        int idx = i - 'a';

        arr[idx][0] = (s[0] == (char) i);

        for (int j = 1; j < s.length(); j++) {
            if (s[j] == (char) i)
                arr[idx][j] = arr[idx][j - 1] + 1;
            else arr[idx][j] = arr[idx][j - 1];
        }
    }


    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;
        if (r == 0)
            cout << arr[a - 'a'][r] << "\n";
        else cout << arr[a - 'a'][r] - arr[a - 'a'][l - 1] << "\n";
    }

    return 0;
}
