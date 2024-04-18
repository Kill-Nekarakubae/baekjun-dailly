#include <iostream>
#include <climits>

using namespace std;

// 25% 틀렸습니다 -> 블록 총13개 모양일 수 있는데 12개로만 계산했었음
// 음의 값이 들어올 수 도 있기 때문에 maxSum을 INT_MIN으로 초기화 해줘야 함

int bx[13][4] = {{0, 1, 2, 3},
                 {0, 0, 0, 0},
                 {0, 1, 1, 2},
                 {1, 1, 0, 0},
                 {0, 1, 2, 2},
                 {1, 1, 1, 0},
                 {0, 0, 1, 2},
                 {0, 0, 0, 1},
                 {0, 1, 2, 1},
                 {0, 1, 1, 1},
                 {1, 0, 1, 2},
                 {0, 0, 0, 1},
                 {0, 1, 0, 1}};

int by[13][4] = {{0, 0, 0, 0},
                 {0, 1, 2, 3},
                 {0, 0, 1, 1},
                 {0, 1, 1, 2},
                 {0, 0, 0, 1},
                 {0, 1, 2, 2},
                 {0, 1, 1, 1},
                 {0, 1, 2, 0},
                 {0, 0, 0, 1},
                 {1, 0, 1, 2},
                 {0, 1, 1, 1},
                 {0, 1, 2, 1},
                 {0, 0, 1, 1}};


int map[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tc = 1;

    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cin >> map[y][x];
            }
        }

        int maxSum = INT_MIN;

        for (int i = 0; i < 13; i++) { // 블록 12케이스 검사
            for (int dx = 0; dx < n; dx++) { // 블록 이동
                for (int dy = 0; dy < n; dy++) {
                    bool isInMap = true;
                    int sum = 0;
                    for (int b = 0; b < 4; b++) { // 블록 하나하나 검사
                        int tx = bx[i][b] + dx;
                        int ty = by[i][b] + dy;
                        if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                            sum += map[ty][tx];
                        } else {
                            isInMap = false;
                            break;
                        }
                    }
                    if (isInMap) {
                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }
        cout << tc++ << ". " << maxSum << "\n";
    }


    return 0;
}
