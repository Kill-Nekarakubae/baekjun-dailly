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
int map[801][801];
int d1[801];
int d2[801];

void dijkstra(int from, int d[]){
    priority_queue<pi > pq;
    pq.push(pi(0, from));
    d[from] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;

        for (int i = 1; i <= N; ++i) {
            if (map[now][i] == -1) continue;
            int cost = dist + map[now][i];
            if (cost < d[i]) {
                d[i] = cost;
                pq.push(pi(-cost, i));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int INF = 100000001;
    fill(map[0], map[801], -1);
    fill(d1, d1 + 801, INF);
    fill(d2, d2 + 801, INF);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a,b,di;
        cin >> a >> b >> di;
        map[b][a] = map[a][b] = di;
    }

    int m1, m2;
    cin >> m1 >> m2;
    dijkstra(m1, d1);
    dijkstra(m2, d2);

//    assert(d1[m2] == d2[m1]);
    if (d1[1] == INF || d1[m2]==INF|| d2[N] ==INF) cout << -1;
    else {
        int mind = (d1[1] + d1[m2] + d2[N]); // 1 -> m1 -> m2 -> N
        mind = min(mind, (d2[1] + d2[m1] + d1[N])); // 1 -> m2 -> m1 -> N
        mind = min(mind, d1[1] * 2 + d2[1] + d2[N]); // 1 -> m1 -> 1 -> m2 -> N
        mind = min(mind, d2[1] * 2 + d1[1] + d1[N]); // 1 -> m2 -> 1 -> m1 -> N
        mind = min(mind, d1[1] + d1[N] + d2[N] * 2); // 1 -> m1 -> N -> m2 -> N
        mind = min(mind, d2[1] + d2[N] + d1[N] * 2); // 1 -> m2 -> N -> m1 -> N

        cout << mind;
    }

    return 0;
}

//4 3
//1 2 1
//1 3 10
//2 4 1
//2 3
// -> 22