#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 20% 틀림

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int l, input, n;
    vector<int> s;
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> input;
        s.emplace_back(input);
    }
    cin >> n;

    sort(s.begin(), s.end());

    if (n < s[0]) {
        int left = n - 1;
        int right = (s[0] - 1) - n + 1;
        int rtn = right * left;
        rtn += (s[0] - 1) - n;
        cout << rtn;
        return 0;
    }

    if (l == 1) {
        if (n == s[0]) cout << 0;
    }

    for (int i = 0; i < l - 1; i++) {
        int n1 = s[i];
        int n2 = s[i + 1];
        if (n1 == n || n2 == n) {
            cout << 0;
            return 0;
        }
        if (n > n1 && n < n2) {
            n1++;
            n2--;
            int left = n - n1;
            int right = n2 - n + 1;
            int rtn = left * right;
            rtn += right - 1;
            cout << rtn;
            return 0;
        }
    }
    return 0;
}