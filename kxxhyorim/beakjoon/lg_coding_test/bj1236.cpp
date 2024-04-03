#include <iostream>

using namespace std;

int r, c, n, m;
char map[51][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        string oneLine;
        cin >> oneLine;
        bool isExist = false;
        for (int x = 0; x < m; x++) {
            map[y][x] = oneLine[x];
            if (map[y][x] == 'X') {
                isExist = true;
            }
        }
        if (!isExist) {
            r++;
        }
    }

    for (int x = 0; x < m; x++) {
        bool isExist = false;
        for (int y = 0; y < n; y++) {
            if (map[y][x] == 'X') {
                isExist = true;
                break;
            }
        }
        if (!isExist) {
            c++;
        }
    }
    cout << max(r, c);
    return 0;
}