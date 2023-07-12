//
// Created by 김효림 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;

int n;
string map[101][101];
bool visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void resetVisited() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            visited[y][x] = false;
        }
    }
}

int areaNum = 0;

void bfs_normal(int x, int y) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    visited[y][x] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        string curr = map[y][x];
        if (x == n && y == n) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[ny][nx]) {
                    string next = map[ny][nx];
                    if (curr == next) {
                        q.emplace(nx, ny);
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    areaNum++;
}

int blindAreaNum = 0;

void bfs_blind(int x, int y) {
    queue<pair<int, int> > q;
    q.emplace(x, y);
    visited[y][x] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        string curr = map[y][x];
        if (x == n && y == n) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[ny][nx]) {
                    string next = map[ny][nx];
                    if (curr == next || (curr == "R" && next == "G") || (curr == "G" && next == "R")) {
                        q.emplace(nx, ny);
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    blindAreaNum++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int y = 0; y < n; y++) {
        string one_line;
        cin >> one_line;
        for (int x = 0; x < n; x++) {
            map[y][x] = one_line[x];
        }
    }


    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!visited[y][x])
                bfs_normal(x, y);
        }
    }

    resetVisited();

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!visited[y][x])
                bfs_blind(x, y);
        }
    }
    cout << areaNum << " " << blindAreaNum;

    return 0;
}
