//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int c[20001];
int N, M;
vector<pi > edges[20001];

void dijkstra(int from) {
    priority_queue<pi > pq;
    pq.push(pi(0, from));
    c[from] = 0;

    while (!pq.empty()) {
        int nowCost = - pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (c[now] < nowCost) continue;

        for (auto np: edges[now]) {
            int nx = np.first;
            int nd = np.second;

            int cost = nowCost + nd;
            if (cost < c[nx]) {
                c[nx] = cost;
                pq.push(pi(-cost, nx));
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int INF = 100000001;
    fill(c, c + 20001, INF);
    int from;
    cin >> N >> M >> from;
    for (int i = 0; i < M; ++i) {
        int a, b, d;
        cin >> a >> b >> d;

        edges[a].push_back(pi(b, d));
    }

    dijkstra(from);

    for (int i = 1; i <= N; ++i) {
        if (c[i] == INF) cout << "INF" << endl;
        else cout << (c[i]) << endl;
    }

    return 0;
}