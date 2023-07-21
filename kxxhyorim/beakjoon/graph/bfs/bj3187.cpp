//
// Created by 김효림 on 2023/07/21.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int r, c;
string land[251][251];
bool isVisited[251][251];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int wolf, sheep;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    isVisited[y][x] = true;
    int temp_wolf = 0;
    int temp_sheep = 0;

    if (land[y][x] == "v") temp_wolf++;
    if (land[y][x] == "k") temp_sheep++;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < c && ny >= 0 && ny < r && land[ny][nx] != "#" && !isVisited[ny][nx]) {
                string target = land[ny][nx];
                if (target == "v") temp_wolf++;
                if (target == "k") temp_sheep++;
                q.emplace(nx, ny);
                isVisited[ny][nx] = true;
            }
        }
    }

    if (temp_wolf >= temp_sheep) wolf += temp_wolf;
    else sheep += temp_sheep;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int y = 0; y < r; y++) {
        string oneLine;
        cin >> oneLine;
        for (int x = 0; x < c; x++) {
            land[y][x] = oneLine[x];
        }
    }


    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (!isVisited[y][x] && land[y][x] != "#")
                bfs(x, y);
        }
    }

    cout << sheep << " " << wolf;


    return 0;
}
