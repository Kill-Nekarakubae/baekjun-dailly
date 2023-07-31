//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

bool isExist[10];

int getInvResult(int N, int d) {
    if (d == N) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (isExist[i]) continue;
        sum += getInvResult(N, d + 1);
    }
    return sum;
}

int main() {
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        isExist[t] = true;
    }

    cout << pow(10, N) - getInvResult(N, 0);

    return 0;
}