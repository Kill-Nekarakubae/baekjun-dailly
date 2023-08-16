#include <iostream>

#define ull unsigned long long
// 팩토리얼 결과값이 ull을 초과함

using namespace std;

// ull factorial[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    factorial[1] = 1;
//    factorial[0] = 1;
//    for (int i = 2; i < 30; i++) {
//        factorial[i] = factorial[i - 1] * i;
//    }

    int t;
    cin >> t;

    for (int T = 0; T < t; T++) {
        int n, m;
        cin >> n >> m;

        int res = 1, temp = 1;
        for (int i = m; i > m - n; i--) {
            res = res * i;
            res = res / temp++;
        }

//        ull top = factorial[m];
//        ull bottom = factorial[n];
//        ull temp = top / bottom;
//        if (m - n != 0) temp /= factorial[m - n];

        cout << res << endl;
    }

    return 0;
}
