//
// Created by 김효림 on 2023/07/13.
//
#include <iostream>
#include <vector>

#define ull unsigned long long

using namespace std;


ull n;
vector<ull> a;
vector<ull> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    a.resize(n);
    b.resize(n);

    for (ull i = 0; i < n; i++) { cin >> a[i]; }
    for (ull i = 0; i < n; i++) { cin >> b[i]; }

    // 마지막꺼는 무조건 0, 마지막에서 하나 앞까지 탐색
    for (ull i = 0; i < n - 1; i++) {
        ull target = a[i];
        ull start = i + 1;
        ull end = n - 1;
        ull mid;

        while (start <= end) {
            mid = (start + end) / 2;
            if (b[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (end == 0) cout << 0 << " ";
        else cout << end - i << " ";
    }
    cout << 0; // 마지막꺼

    return 0;
}
