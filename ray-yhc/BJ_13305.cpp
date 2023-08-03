//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int N;
unsigned long long dist[100001];
unsigned long long price[100001];


int main() {
    scanf("%d", &N);
    unsigned long long totalDistance = 0;
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d", &dist[i]);
        totalDistance += dist[i];
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &price[i]);
    }

    unsigned long long cost= 0;
    unsigned long long localMinimum = price[0];

    for (int i = 0; i < N - 1; ++i) {
        if (price[i] < localMinimum)
            localMinimum = price[i];
        cost += localMinimum * dist[i];
    }

    printf("%lld", cost);

    return 0;
}