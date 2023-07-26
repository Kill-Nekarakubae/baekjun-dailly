//
// Created by 김효림 on 2023/07/24.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int fibo[1000001];

int fib(int idx) {

    if (idx == 0)return fibo[0];
    if (idx == 1)return fibo[1];

    if (fibo[idx] == 0) {
        fibo[idx] = ((fib(idx - 1) % 1000000007) + (fib(idx - 2) % 1000000007)) % 1000000007;
    }
    return fibo[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;

    cout << fib(n);

    return 0;
}
