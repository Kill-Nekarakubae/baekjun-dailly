#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char map[250][250];
bool visited[250][250] = {false};
int R, C;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<int, int> bfs(int r, int c) {
    queue<pair<int, int> > q;
    q.push(pair<int, int>(r, c));
    visited[r][c] = true;
    int sheep = 0, wolf = 0;

    while (!q.empty()) {
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (map[rr][cc] == 'k') sheep++;
        else if (map[rr][cc] == 'v') wolf++;

        for (int i = 0; i < 4; ++i) {
            int nr = rr + dy[i];
            int nc = cc + dx[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (visited[nr][nc])continue;
            if (map[nr][nc] == '#')continue;

            visited[nr][nc] = true;

            q.push(pair<int, int>(nr, nc));
        }
    }

    if (sheep > wolf)
        return pair<int, int>(sheep, 0);
    return pair<int, int>(0, wolf);
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> map[i][j];
        }
    }

    int sheep = 0, wolf = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (visited[i][j]) continue;
            if (map[i][j] == '#')continue;

            pair<int, int> res = bfs(i, j);
            sheep += res.first;
            wolf += res.second;
        }
    }

    cout << sheep << " " << wolf << endl;

    return 0;
}