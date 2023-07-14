//
// Created by 김효림 on 2023/07/14.
//
#include <iostream>
#include <vector>

#define ull unsigned long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull n, w, c = 0;
    vector<ull> v;

    cin >> n >> w;
    v.resize(n);
    for (ull i = 0; i < n; i++) {
        cin >> v[i];
    }


    // 10일 24개
    bool isBuy = true;
    for (ull i = 0; i < n - 1; i++) {
        ull today = v[i];
        ull tomorrow = v[i + 1];
        if (isBuy) { // 내일 보다 싸면
            if (today < tomorrow) {
                ull temp = w / today;
                w -= (today * temp);
                c += temp;
                isBuy = false;
                continue;
            }
        } else { // 팔아야됨
            if (today > tomorrow) {
                w += c * today;
                c = 0;
                isBuy = true;
                continue;
            }
        }
    }

    w += c * v[n - 1];

    cout << w;


    return 0;
}
