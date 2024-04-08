#include <iostream>
#include <algorithm>

/* isVisited 를 무조건 map 형식으로 조회할 필요는 없음 */

using namespace std;

int r, c;
char board[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool isUsed[26];

int maxCount = 0;
int currCount = 0;

void dfs(int x, int y) {

    currCount++;
    if (currCount > maxCount) maxCount = currCount;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
            char newChar = board[ny][nx];
            bool isCharUsed = isUsed[newChar - 'A'];
            if (!isCharUsed) {
                isUsed[newChar - 'A'] = true;
                dfs(nx, ny);
                isUsed[newChar - 'A'] = false;
            }
        }
    }
    currCount--;
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
            board[y][x] = oneLine[x];
        }
    }

    char alpha = board[0][0];
    isUsed[alpha - 'A'] = true;
    dfs(0, 0);

    cout << maxCount;

    return 0;
}
