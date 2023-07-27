#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
bool ladder[11][31];

int N, M, H;

bool check() {

}

int rec(int col, int cnt) {
    if (cnt > 3) return 10;
    if (check()) return cnt;

    for (int i = col + 1; i <= M; ++i) {
        for (int j = 1; j < H; ++j) {

        }
    }
}


//todo :
// https://www.acmicpc.net/problem/15684
int main() {
    cin >> N >> M >> H;

    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        ladder[r][c] = true;
    }

    cout << rec(1, 0);

    return 0;
}
