//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define pip pair<int, pair<int,int> >

int N, M, K;
int parent[1001];
vector<pip> v;

bool compare(pip &a, pip &b){
    if (a.first > b.first) return true;
    else return false;
}

int find(int u) {
    if (u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v) {
    v = find(v);
    u = find(u);

    if (u==v) return false;
    else {
        parent[u] = v;
        return true;
    }
}

void init(int N) {
    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
    }

}

int main() {


    while (true) {
        cin >> N >> M >> K;
        if (N == 0) break;
        // 1. 파란 간선의 최소로 사용하는 스패닝 트리를 구한다.
        init(N);
        v.clear();

        for (int i = 0; i < M; ++i) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            v.push_back(pair<int, pair<int, int> >((c == 'B') ? 1 : 0, pair<int, int>(a, b)));
        }
        std::sort(v.begin(), v.end());

        int min_blue = 0;
        for (int i = 0; i < M; ++i) {
            if(union_node(v[i].second.first, v[i].second.second)) min_blue += v[i].first;
        }

        // 2. 파란 간선의 최대로 사용하는 스패닝 트리를 구한다.
        init(N);
        std::sort(v.begin(), v.end(), compare);

        int max_blue = 0;
        for (int i = 0; i < M; ++i) {
            if(union_node(v[i].second.first, v[i].second.second)) max_blue += v[i].first;
        }

        // 3. K값이 min_blue와  max_blue의 범위에 포함되는지 확인한다.
        int p = (K >= min_blue && K <= max_blue) ? 1 : 0;
        cout << p << endl;
    }

    return 0;
}