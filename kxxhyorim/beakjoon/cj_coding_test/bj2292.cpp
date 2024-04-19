#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n == 1) cout << 1;
    vector<int> v;
    v.emplace_back(1);

    for (int i = 1;; i++) {
        v.emplace_back(v[i - 1] + (6 * i));
        if (n > v[i - 1] && n <= v[i])
            cout << i + 1;
        if (v[i] >= n) break;
    }

    return 0;
}
