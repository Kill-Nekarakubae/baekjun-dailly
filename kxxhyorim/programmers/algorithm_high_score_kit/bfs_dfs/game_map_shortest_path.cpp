#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<int>> dist;

int solution(vector<vector<int>> maps) {
    int n = maps.size(); // y
    int m = maps[0].size(); // x 사이즈
    dist.resize(n);
    for (int i = 0; i < n; i++) {
        dist[i].resize(m);
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && maps[ny][nx] == 1) {
                if (dist[ny][nx] == 0
                    || dist[ny][nx] > dist[y][x] + 1) { // 이미 값은 있지만 새로 갱신하는 값이 더 최단거리 일떄
                    dist[ny][nx] = dist[y][x] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    int answer = dist[n - 1][m - 1];
    if (answer == 0) answer = -1;
    cout << answer << endl;
    return answer;
}