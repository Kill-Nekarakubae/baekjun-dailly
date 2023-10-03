//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

#define pip pair<int, pair<int, int> >
#define pi pair<int, int>

using namespace std;
char mapp[21][21];
int N, M;
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

bool redFirst(int direction, pi blue, pi red) {
    bool redIsUp = (red.first <= blue.first);
    bool redIsLeft = (red.second <= blue.second);

    switch (direction) {
        case 0: return redIsUp;
        case 1 : return redIsLeft;
        case 2: return !redIsLeft;
        case 3 : return !redIsUp;
    }
}

int dfs(vector<vector<int> > visited, pi blue, pi red) {
    if (mapp[blue.first][blue.second] == 'O') return 0;
    if (mapp[red.first][red.second] == 'O') return 1;

    int minSteps = 100000;
    for (int d = 0; d < 4; ++d) {
        pi nRed(red);
        pi nBlue(blue);

        if (redFirst(d, nBlue, nRed)) {
            int nr = nRed.first;
            int nc = nRed.second;
            for (int i = 0;; i++) {
                nr += dr[d];
                nc += dc[d];

                if (mapp[nr][nc] == '#' || (nr == nBlue.first && nc == nBlue.second)) {
                    nRed.first = nr - dr[d];
                    nRed.second = nc - dc[d];
                    break;
                } else if (mapp[nr][nc] == 'O') {
                    nRed.first = nr;
                    nRed.second = nc;
                    break;
                }
            }

            visited[nRed.first][nRed.second]++;
            if (visited[nRed.first][nRed.second] > 2) return 0;

            nr = nBlue.first;
            nc = nBlue.second;
            for (int i = 0;; i++) {
                nr += dr[d];
                nc += dc[d];

                if (mapp[nr][nc] == '#' || (nr == nRed.first && nc == nRed.second)) {
                    nBlue.first = nr - dr[d];
                    nBlue.second = nc - dc[d];
                    break;
                } else if (mapp[nr][nc] == 'O') {
                    nBlue.first = nr;
                    nBlue.second = nc;
                    break;
                }
            }
        } else {
            int nr = nBlue.first;
            int nc = nBlue.second;
            for (int i = 0;; i++) {
                nr += dr[d];
                nc += dc[d];

                if (mapp[nr][nc] == '#' || (nr == nRed.first && nc == nRed.second)) {
                    nBlue.first = nr - dr[d];
                    nBlue.second = nc - dc[d];
                    break;
                } else if (mapp[nr][nc] == 'O') {
                    nBlue.first = nr;
                    nBlue.second = nc;
                    break;
                }
            }

            nr = nRed.first;
            nc = nRed.second;
            for (int i = 0;; i++) {
                nr += dr[d];
                nc += dc[d];

                if (mapp[nr][nc] == '#' || (nr == nBlue.first && nc == nBlue.second)) {
                    nRed.first = nr - dr[d];
                    nRed.second = nc - dc[d];
                    break;
                } else if (mapp[nr][nc] == 'O') {
                    nRed.first = nr;
                    nRed.second = nc;
                    break;
                }
            }
            visited[nRed.first][nRed.second]++;
            if (visited[nRed.first][nRed.second] > 2) return 0;
        }
        int steps = dfs(visited, nBlue, nRed);
        if (steps == 0) continue;
        minSteps = min(steps, minSteps);
    }
    if (minSteps == 100000) return 0;
    return minSteps;
}

void printmap() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << mapp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    pi blue, red;
    cin >> N>>M ;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mapp[i][j];
            if (mapp[i][j] == 'B') {
                mapp[i][j] = '.';
                blue = pair<int, int>(i, j);
            } else if (mapp[i][j] == 'R') {
                mapp[i][j] = '.';
                red = pair<int, int>(i, j);
            }
        }
    }


    vector<vector<int> > visited(N);
    for (int i = 0; i < N; ++i) {
        visited[i] = vector<int>(M, 0);
    }
    visited[red.first][red.second] = 1;
    cout << dfs(visited, blue, red);
    return 0;
}