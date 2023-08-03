//
// Created by 조윤호 on 2023/07/12.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define pip pair<double, pair<int,int> >

int N, W;
int sensor[1002][3];
int parent[1002];
vector<pip > v;

int find(int u) {
    if (u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v) {
    v = find(v);
    u = find(u);

    if (u == v) return false;
    else {
        parent[u] = v;
        return true;
    }
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    v.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed ;
    cout.precision(6);

    int T;
    cin >> T;
    for (int test = 0; test < T; ++test) {
        cin >> W >> N;

        if (N == 0) {
            cout << W / 2 << endl;
            continue;
        }

        sensor[0][0] = 0;
        sensor[0][1] = 0;
        sensor[0][2] = -1;
        sensor[1][0] = W;
        sensor[1][1] = 0;
        sensor[1][2] = -1;

        for (int i = 2; i < N + 2; ++i) {
            cin >> sensor[i][0] >> sensor[i][1] >> sensor[i][2];
        }

        init(N + 2);

        for (int i = 0; i < N + 2; ++i) {
            for (int j = i + 1; j < N + 2; ++j) {
                double dist = 0;
                if (i < 2) {
                    if (j == 1) continue;
                    double d = (sensor[j][0] - sensor[i][0] >= 0) ? sensor[j][0] - sensor[i][0] : sensor[i][0] -
                                                                                                  sensor[j][0];
                    dist = d - sensor[j][2];
                } else {
                    double x = sensor[j][0] - sensor[i][0];
                    double y = sensor[j][1] - sensor[i][1];
                    dist = sqrt(x * x + y * y) - sensor[j][2] - sensor[i][2];
                }

                v.push_back(pip(dist, pair<int, int>(i, j)));
            }
        }

        sort(v.begin(), v.end());

        double minWidth = 1000000;
        for (int i = 0; i < v.size(); ++i) {
            if (union_node(v[i].second.first, v[i].second.second));
            else continue;


            if (find(0) == find(1)) {
                double t = v[i].first;
                if (t < 0) t = 0;
                minWidth = t;
                break;
            }


//            if (i == v.size() - 1) {
//                assert(false);
//            }
        }

        cout << minWidth / 2 << endl;
//        printf("%.6lf\n", minWidth / 2);
    }

    return 0;
}