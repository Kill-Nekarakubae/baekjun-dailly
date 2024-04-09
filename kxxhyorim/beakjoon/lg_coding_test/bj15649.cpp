#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v;
    set<string> s;

    for (int i = 1; i <= n; i++) {
        v.emplace_back(i);
    }

    vector<bool> isSelected;
    isSelected.resize(n);

    for (int i = n - 1; i >= n - m; i--) {
        isSelected[i] = true;
    }

    do {
        vector<int> candidate;
        for (int i = 0; i < n; i++) {
            if (isSelected[i]) {
                candidate.emplace_back(v[i]);
            }
        }
        do {
            string temp;
            for (int i = 0; i < candidate.size(); i++) {
                temp += to_string(candidate[i]);
                temp += " ";
            }
            s.emplace(temp);
        } while (next_permutation(candidate.begin(), candidate.end()));
    } while (next_permutation(isSelected.begin(), isSelected.end()));


    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
