//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;

long long dp[1000000] = {0};

long long fibo(int n) {
    if (n < 2)
        return dp[n];

    if (dp[n - 1] == 0)
        dp[n - 1] = fibo(n - 1);
    if (dp[n - 2] == 0)
        dp[n - 2] = fibo(n - 2);


    return (dp[n - 1] + dp[n - 2]) % 1000000007;
}

//todo :
// https://www.acmicpc.net/problem/15624
int main() {
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;

    cout << fibo(N) << endl;
    return 0;
}