//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<pair<int, int> > edge[100001];

int getLongest(int node){

}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        edge[a].push_back(pair<int, int>(b, d));
        edge[b].push_back(pair<int, int>(a, d));
    }

    int a = getLongest(1);
    int b = getLongest(a);
    int bl = getLongest(a,b);
    int al = getLongest(b, a);


    return 0;
}