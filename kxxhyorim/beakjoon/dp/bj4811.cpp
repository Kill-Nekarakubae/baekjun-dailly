#include <iostream>
#include <set>
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull dp[31][62];
// 16퍼에서 틀림

ull getCases(int x, int y) { // 한알 개수, 반알 개수
    if (dp[x][y] != 0) return dp[x][y];
    else if (x == 0 && y == 0)
        return dp[x][y] = 1;
    else if (y == 0)
        return dp[x][y] = getCases(x - 1, y + 1);
    else if (x == 0)
        return dp[x][y] = getCases(x, y - 1);
    else
        return dp[x][y] = getCases(x - 1, y + 1) + getCases(x, y - 1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    do {
        cin >> n;
        if (n == 0) break;
        cout << getCases(n, 0) << "\n";
    } while (n != 0);
    return 0;
}