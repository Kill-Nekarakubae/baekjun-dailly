#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int board[501][501];
int dist[501][501];
bool isVisited[501][501];// 유닛의 제일 왼쪽 제일 위의 좌표
int fx[4], fy[4];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, k, startX, startY, endX, endY;
    cin >> n >> m >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        board[y - 1][x - 1] = -1;
    }
    cin >> startY >> startX >> endY >> endX;
    startY--;
    startX--;
    endY--;
    endX--; // index 0 부터 시작함


    fx[1] = b - 1;
    fy[2] = a - 1;
    fx[3] = b - 1;
    fy[3] = a - 1;

    queue<pair<int, int>> q;
    q.emplace(startX, startY);
    isVisited[startY][startX] = true;

    bool isFind = false;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == endX && y == endY) {
            isFind = true;
            break;
        }

        vector<pair<int, int>> four_points(4);
        for (int i = 0; i < 4; i++) { // filter 4개
            int unit_x = x + fx[i];
            int unit_y = y + fy[i];
            four_points[i] = {unit_x, unit_y};
        }

        for (int i = 0; i < 4; i++) { // 4방으로 이동 가능한지
            bool canMove = true;
            // 꼭지점 검사
            int nx = four_points[0].first + dx[i];
            int ny = four_points[0].second + dy[i];
            if (nx < 0 || nx + b - 1 >= m || ny < 0 || ny + a - 1 >= n) {
                canMove = false;
            }
            if (isVisited[ny][nx]) {// 첫번째 유닛(왼쪽 위)이 visited
                canMove = false;
            }
            for (int Y = 0; Y < a; Y++) {
                for (int X = 0; X < b; X++) {
                    int px = nx + X;
                    int py = ny + Y;
//                    cout << px << " " << py << endl;
                    if (board[py][px] == -1) {
                        canMove = false;
                        break;
                    }
                }
            }
//            cout << canMove << endl;
            if (canMove) {
                nx = four_points[0].first + dx[i];
                ny = four_points[0].second + dy[i];
                q.emplace(nx, ny);
                isVisited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }

    if (isFind) cout << dist[endY][endX];
    else cout << -1;

    return 0;
}
