#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int dp[41];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, fix, vip;
    cin >> n >> fix;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }


    int way = 1;
    int before = 0;
    for (int i = 0; i < fix; i++) {
        cin >> vip;
        int num = vip - before - 1;
        way *= dp[num];
        before = vip;
    }

    way *= dp[n - before];

    cout << way;


    return 0;
}
