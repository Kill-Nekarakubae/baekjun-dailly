//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;

char imgMap[101][101] = {0};
bool visited[101][101] = {false};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int N, int iy, int ix, char color) {
    if (visited[iy][ix]) return false;

    int count = 0;
    queue<pair<int, int> > que;

    que.push(pair<int, int>(ix, iy));

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[ny][nx]) continue;
            if (imgMap[ny][nx] != color) continue;

            visited[ny][nx] = true;
            que.push(pair<int, int>(nx, ny));
        }
    }
    return true;
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> imgMap[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j]) continue;
            if (bfs(N, i, j, imgMap[i][j])) count++;
        }
    }

    cout << count << " ";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (imgMap[i][j] == 'R')
                imgMap[i][j] = 'G';
            visited[i][j] = false;
        }
    }

    count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j]) continue;
            if (bfs(N, i, j, imgMap[i][j])) count++;
        }
    }

    cout << count << endl;
    return 0;
}