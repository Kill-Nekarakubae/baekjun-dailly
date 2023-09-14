#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        if (dp[i] > ans) ans = dp[i];
    }

    cout << ans;

    return 0;
}