//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int fac[10];
int factorial(int i){
    if (fac[i] == 0) fac[i] = i * factorial(i - 1);
    return fac[i];
}

int nCr(int M, int m){
    return factorial(M) / factorial(m) / factorial(M - m);
}

int main() {
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
    }

    fac[0] = fac[1] = 1;

    int result = pow(10, N);
    int sign = 1;
    for (int m = 1; m <= M; ++m) {
        sign = -1 * sign;
        result += sign * nCr(M, m) * pow((10 - m), N);
    }
    cout << result;

    return 0;
}