#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t, space;

    while (cin >> s >> t) {


        int idx = 0;

        for (int i = 0; i < t.length(); i++) {
            if (t[i] == s[idx]) {
                idx++;
            }
        }
        if (idx == s.length()) {
            cout << "Yes\n";
        } else cout << "No\n";


    }

    return 0;
}
