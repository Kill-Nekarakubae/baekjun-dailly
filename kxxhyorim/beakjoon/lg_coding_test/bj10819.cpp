#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int max = 0;

    do {
        int sum = 0;

        for (int i = 0; i < n - 1; i++) {
            int n1 = v[i];
            int n2 = v[i + 1];
            int sub = abs(n1 - n2);
            sum += sub;
        }
        if (sum > max) max = sum;

    } while (next_permutation(v.begin(), v.end()));

    cout << max;

    return 0;
}
