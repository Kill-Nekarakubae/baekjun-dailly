#include <iostream>
#include <algorithm>

#define ull unsigned long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull n;
    cin >> n;
    ull sum = 0;

    for (int i = 1; i < n; i++) {
        ull num = i * n + i;
        sum += num;
    }

    cout << sum;

    return 0;
}
