//
// Created by 김효림 on 2023/07/23.
//
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>> v;
bool is_visited[500001];
int edge_count;

void dfs(int node, int depth) {
    is_visited[node] = true;
    bool is_leaf = true;
    for (int i = 0; i < v[node].size(); i++) {
        int connected_node = v[node][i];
        if (!is_visited[connected_node]) {
            is_leaf = false;
            dfs(connected_node, depth + 1);
            is_visited[connected_node] = false;
        }
    }
    if (is_leaf) edge_count += depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    v.resize(n + 1);


    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    dfs(1, 0);
//    cout << edge_count << endl;
    if (edge_count % 2 == 0) cout << "No";
    else cout << "Yes";

    return 0;
}
