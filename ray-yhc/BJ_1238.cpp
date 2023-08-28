//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int map[1001][1001];
int forwardDist[1001];
int inverseDist[1001];
int N, M,X;
vector<pi > shark;

void dijkstra(int start) {
    priority_queue<pi > pq;
    pq.push(pi(0, start));
    forwardDist[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (forwardDist[now] < dist) continue;

        for (int i = 1; i <= N; ++i) {
            if (map[now][i] == -1) continue;
            int cost = dist + map[now][i];

            if (cost < forwardDist[i]) {
                forwardDist[i] = cost;
                pq.push(pi(-cost, i));
            }
        }
    }
}

void inv_dijkstra(int start) {
    priority_queue<pi > pq;
    pq.push(pi(0, start));
    inverseDist[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (inverseDist[now] < dist) continue;

        for (int i = 1; i <= N; ++i) {
            if (map[i][now] == -1) continue;
            int cost = dist + map[i][now];

            if (cost < inverseDist[i]) {
                inverseDist[i] = cost;
                pq.push(pi(-cost, i));
            }
        }
    }
}

int main() {
    fill(map[0], map[1001], -1);
    fill(forwardDist, forwardDist + 1001, 1000001);
    fill(inverseDist, inverseDist + 1001, 1000001);
    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        map[a][b] = d;
    }

    dijkstra(X);
    inv_dijkstra(X);
    int maxdist = 0;
    for (int i = 1; i <= N; ++i) {
        int d = forwardDist[i] + inverseDist[i];
        maxdist = max(maxdist, d);
    }

    cout << maxdist;

    return 0;
}