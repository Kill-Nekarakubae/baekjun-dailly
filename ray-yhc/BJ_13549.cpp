//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int N, M, limit;
int d[200000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int INF = 100000001;
    cin >> N >> M;
    limit = max(N, M) * 2;

    int dist = -N;
    for (int i = 0; i < limit; ++i) {
        d[i] = dist++;
    }






    return 0;
}