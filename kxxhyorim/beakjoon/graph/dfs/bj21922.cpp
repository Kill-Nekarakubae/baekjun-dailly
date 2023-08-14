#include <iostream>
#include <vector>

using namespace std;

int n, m; // ㅅㅔ로, 가로

int map[2001][2001];
int isVisited[2001][2001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int direction[4] = {0, 1, 2, 3};

#define toUp 0
#define toDown 1
#define toLeft 2
#define toRight 3
// 상 == toUp == 밑에서 위로
// 우 == toRight == 왼쪽에서 오른쪽으로

int getOpposite(int d) {
    if (d == toUp) return toDown;
    if (d == toDown) return toUp;
    if (d == toLeft) return toRight;
    if (d == toRight) return toLeft;
    return -1;
}

void dfs(int x, int y, int direct) {

    if (!(x >= 0 && x < m && y >= 0 && y < n)) return;

    if (isVisited[y][x] != -1) { // 이미 지나간적 있음
        if (map[y][x] == 1 || map[y][x] == 2) {
            if (isVisited[y][x] == getOpposite(direct) || isVisited[y][x] == direct) return; // 하나의 에어컨 바람이면 멈춤
        } else if (map[y][x] == 3 && isVisited[y][x] == direct) {
            return;
        } else if (map[y][x] == 4 && isVisited[y][x] == direct) {
            return;
        }
    }

    isVisited[y][x] = direct;

    switch (map[y][x]) {
        case 9 :
            return;
        case 1 :
            if (direct == toUp) dfs(x, y - 1, toUp);
            if (direct == toDown) dfs(x, y + 1, toDown);
            if (direct == toLeft) dfs(x + 1, y, toRight);
            if (direct == toRight) dfs(x - 1, y, toLeft);
            return;

        case 2:
            if (direct == toUp) dfs(x, y + 1, toDown);
            if (direct == toDown) dfs(x, y - 1, toUp);
            if (direct == toLeft) dfs(x - 1, y, toLeft);
            if (direct == toRight)dfs(x + 1, y, toRight);
            return;

        case 3:
            if (direct == toUp) dfs(x + 1, y, toRight);
            if (direct == toDown) dfs(x - 1, y, toLeft);
            if (direct == toLeft) dfs(x, y + 1, toDown);
            if (direct == toRight)dfs(x, y - 1, toUp);
            return;

        case 4:
            if (direct == toUp)dfs(x - 1, y, toLeft);
            if (direct == toDown) dfs(x + 1, y, toRight);
            if (direct == toLeft) dfs(x, y - 1, toUp);
            if (direct == toRight)dfs(x, y + 1, toDown);
            return;

        case 0:
            if (direct == toUp)dfs(x, y - 1, toUp);
            if (direct == toDown)dfs(x, y + 1, toDown);
            if (direct == toLeft) dfs(x - 1, y, toLeft);
            if (direct == toRight) dfs(x + 1, y, toRight);
            return;

    }

    // 에어컨 = 상하좌우로 이동
    // 아무것도 없음 = 원래 이동하던 방향으로 이동
    // 물건 1 : 상하 이동 가능, 좌우 이동 막힘
    // 물건 2 : 좌우 이동 가능, 상 하 불가
    // 물건 3 : 상 -> 우 / 하 -> 좌 / 좌 -> 하 / 우 -> 상
    // 물건 4 : 상 -> 좌 / 하 -> 우 / 좌 -> 우 / 우 -> 하


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<pair<int, int>> air; // x, y

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            if (map[y][x] == 9)
                air.emplace_back(x, y);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            isVisited[y][x] = -1;
        }
    }


    for (int i = 0; i < air.size(); i++) {
        int x = air[i].first;
        int y = air[i].second;
        isVisited[y][x] = 9;

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            dfs(nx, ny, j);
        }
    }

    int answer = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (isVisited[y][x] != -1) {
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}
