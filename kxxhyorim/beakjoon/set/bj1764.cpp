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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    set < string > s;
    vector<string> v;

    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.emplace(name);
    }

    for (int i = 0; i < m; i++) {
        cin >> name;
        if (s.find(name) != s.end()) {
            v.push_back(name);
        }
    }

    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }


    return 0;
}
