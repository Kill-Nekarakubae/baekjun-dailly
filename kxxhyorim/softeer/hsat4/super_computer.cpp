#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define ull unsigned long long


using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ull b;
    cin >> n >> b; // 수와 예산

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ull start = v[0];
    ull end = v[n - 1] + sqrt(b);
    ull mid;
    ull possible_max;

    while (start <= end) {
        mid = (start + end) / 2;
        ull cost = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] < mid) {
                cost += (ull) pow((mid - v[i]), 2);
            } else break;
        }

        if (cost < b) {
            if (mid > possible_max)
                possible_max = mid;
            start = mid + 1;
        } else if (cost > b) {
            end = mid - 1;
        } else {
            cout << mid;
            return 0;
        }

    }

    if (end < possible_max) {
        cout << possible_max;
    } else {
        cout << end;
    }

    return 0;
}
