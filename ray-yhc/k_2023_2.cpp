#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int checkStick (vector<vector<int>> &graph, int node) {
    unordered_set<int> us;
    us.insert(node);
    while(true) {
        // 간선은 반드시 0 혹은 1개여야 함
        if (graph[node].size() >= 2) return -1;
        if (graph[node].size() == 0) return node;

        int next= graph[node][0];

        // 방문한 정점을 다시 방문하면 안됨
        if (us.find(next) != us.end()) return -1;
        us.insert(graph[node][0]);
        node = graph[node][0];
    }
}

int checkDonutOrEight(vector<vector<int>> &graph, int node) {
    unordered_map<int, int> um;
    while (true) {
        if (um[node] >= 2) return node;
        um[node]++;

        if (graph[node].size() == 0) return -1;
        if (graph[node].size() > 2) return -1;
        if (graph[node].size() == 2) {
            int nx1 = graph[node][0];
            int nx2 = graph[node][1];
            node = (um[nx1] > um[nx2]) ? nx2 : nx1;
            continue;
        }
        node = graph[node][0];
    }
}

bool isEight(vector<vector<int>> &graph, int center) {
    return (graph[center].size() == 2);
}

vector<int> solution(vector<vector<int>> edges) {
    vector<vector<int>> graph(1000001, vector<int>());
    for (vector<int> edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    for (int node = 1; node <= 1000000; node++) {
        if (graph[node].size() >= 2) {
            int donut = 0, stick = 0, eight = 0;
            unordered_set<int> eightCenters;
            bool somthingIsWrong = false;

            for (int next : graph[node]) {
                if (checkStick(graph, next) != -1) stick++;
                else {
                    int center = checkDonutOrEight(graph, next);
                    if (center == -1) {
                        somthingIsWrong = true;
                        break;
                    }
                    if (!isEight(graph, center))donut++;
                    else if (eightCenters.find(center) == eightCenters.end()) {
                        eightCenters.insert(center);
                        eight++;
                    }
                }
            }

            if (somthingIsWrong) continue;
            if ( donut + stick + eight >= 2) {
                return {node, donut, stick, eight};
            }
        }
    }
    return {-1, -1, -1, -1};
}






int main() {

    vector<int> v ;
    v = solution (
            {{3,2},{2,3},{4,2},{2,4},{5,6},{6,7},{7,11},{11,5},{7,8},{8,9},{9,10},{10,7}, {12,13},{13,14},{14,12},{14,15},{15,16},{16,14}, {1,2},{1,11},{1,13}}
    );
    for (int i : v)
        cout<<i<<" ";
    cout<<endl;


    v = solution(
    {{2, 3}, {4, 3}, {1, 1}, {2, 1}}
    );
    for (int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    v = solution (
            {{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}}
    );
    for (int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;



    return 0;
}
