#include <iostream>
#include <climits>
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

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int solution = INT_MAX;
    int idx1 = -1;
    int idx2 = -1;

    for (int i = 0; i < n; i++) {
        int target = v[i];
        int start = i + 1;
        int end = n - 1;
        int mid;

        while (start <= end) {
            mid = (start + end) >> 1;
            int sum = target + v[mid];
            if (sum == 0) {
                cout << v[i] << " " << v[mid];
                return 0;
            }

            if (abs(sum) < abs(solution)) {
                solution = target + v[mid];
                idx1 = i;
                idx2 = mid;
            }

            if (sum < 0)
                start = mid + 1;
            else end = mid - 1;
        }
    }
    cout << v[idx1] << " " << v[idx2];
    return 0;
}
