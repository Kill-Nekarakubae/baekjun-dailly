#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        int n;
        cin >> s;
        n = (int) s.length();
        vector<char> v;

        for (int i = 0; i < n; i++) {
            v.emplace_back(s[i]);
        }
        unique(v.begin(), v.end());

        bool isInfected = false;

        if (n < 3) cout << "Good\n";

        if (v[0] == 'A') {
            if (v[1] == 'F' && v[2] == 'C') {
                if (n == 3 || (n > 3 && v[3] >= 'A' && v[3] <= 'F'))
                    isInfected = true;
            }
        } else if (v[1] == 'A') {
            if (v[2] == 'F' && v[3] == 'C') {
                if (n == 4 || (n > 4 && v[4] >= 'A' && v[4] <= 'F'))
                    isInfected = true;
            }
        }

        cout << (isInfected ? "Infected!\n" : "Good\n");
    }


    return 0;
}