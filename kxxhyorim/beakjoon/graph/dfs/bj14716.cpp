#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[251][251];
bool isVisited[251][251];
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[9] = {-1, -1, -1, 0, 1, 1, 1, 0};
int m, n, cnt;

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.emplace(x, y);
    isVisited[y][x] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !isVisited[ny][nx] && map[ny][nx] == 1) {
                q.emplace(nx, ny);
                isVisited[ny][nx] = true;
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (!isVisited[y][x] && map[y][x] == 1) {
                bfs(x, y);
                cnt++;
            }
        }
    }

    cout << cnt;


    return 0;
}
