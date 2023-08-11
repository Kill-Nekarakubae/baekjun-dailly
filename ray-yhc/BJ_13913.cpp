//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
#define pip pair<int, pair<int,int> >

int dp[200000];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    if (M <= N) {
        for (int i = N; i >=M; --i) {
            printf("%d ", i);
        }
        return 0;
    }

    for (int i = 0; i < 200000 && i < 2 * M; ++i) {
        dp[i] = (i > N) ? i - N : N - i;
    }


    return 0;
}