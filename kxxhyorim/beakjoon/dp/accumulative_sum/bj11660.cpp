#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int map[1025][1025];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }
    // y = 0 고정
    for (int x = 1; x < n; x++) {
        map[0][x] += map[0][x - 1];
    }

    //  x = 0 고정
    for (int y = 1; y < n; y++) {
        map[y][0] += map[y - 1][0];
    }

    for (int y = 1; y < n; y++) {
        for (int x = 1; x < n; x++) {
            map[y][x] = map[y - 1][x] + map[y][x - 1] + map[y][x] - map[y - 1][x - 1];
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0; i < m; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        x2--;
        y1--;
        y2--;
        int big = map[y2][x2];
        int sub1 = (y1 - 1 >= 0) ? map[y1 - 1][x2] : 0;
        int sub2 = (x1 - 1 >= 0) ? map[y2][x1 - 1] : 0;
        int add = (x1 - 1 >= 0 && y1 - 1 >= 0) ? map[y1 - 1][x1 - 1] : 0;
        cout << big - sub1 - sub2 + add << "\n";
    }


    return 0;
}