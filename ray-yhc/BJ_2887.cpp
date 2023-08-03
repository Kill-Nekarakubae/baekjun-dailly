//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
#define pip pair<int, pair<int,int> >

int N;
vector<pair<int, int> > x;
vector<pair<int, int> > y;
vector<pair<int, int> > z;
vector<pip> planet;
int parent[100001];

int find(int u){
    if (parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

bool unionFind(int u, int v) {
    u = find(u);
    v = find(v);

    if (u==v) return false;
    else {
        parent[u] = v;
        return true;
    }
}

int main() {

    cin >> N;


    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < N; ++i) {
        int i1, i2, i3;
        cin >> i1 >> i2 >> i3;
        x.push_back(pair<int,int> (i1,i));
        y.push_back(pair<int, int>(i2, i));
        z.push_back(pair<int, int>(i3, i));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 0; i < N-1; ++i) {
        planet.push_back(pair<int, pair<int, int> >((x[i + 1].first - x[i].first), pair<int, int>(x[i + 1].second, x[i].second)));
        planet.push_back(pair<int, pair<int, int> >((y[i + 1].first - y[i].first), pair<int, int>(y[i + 1].second, y[i].second)));
        planet.push_back(pair<int, pair<int, int> >((z[i + 1].first - z[i].first), pair<int, int>(z[i + 1].second, z[i].second)));
    }

    sort(planet.begin(), planet.end());

    long long totalCost = 0;
    for (int i = 0; i < planet.size(); ++i) {
        int distance = planet[i].first;
        int u = planet[i].second.first;
        int v = planet[i].second.second;

        if (unionFind(u,v)) totalCost += distance;
    }
    cout << totalCost;
    return 0;
}