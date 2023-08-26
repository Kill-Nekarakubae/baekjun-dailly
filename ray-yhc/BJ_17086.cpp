//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int smap[1001][1001];
char cho[1001];

int main() {
    int N, M;

    fill(smap[0], smap[1001], -1);

    for (int i = 0; i < N; ++i) {
        cin >> cho[i];
    }
    for (int i = 0; i < M; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        if (cho[a]==cho[b]) continue;
        smap[a][b] = smap[b][a] = d;
    }


    return 0;
}