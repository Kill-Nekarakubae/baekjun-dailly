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

pi blue, red;

bool redFirst(int direction) {
    return false;
}

int dfs(vector<vector<int> > visited) {


    for (int d = 0; d < 4; ++d) {
        if (redFirst(d)) {
            int nr = red.first;
            int nc = red.second;
            for (int i = 0;; i++) {
                nr += dr[d];
                nc += dc[d];

                if (mapp[nr][nc] == '#' || (nr == blue.first && nc == blue.second)) {
                    red.first = nr - dr[d];
                    red.second = nc - dc[d];
                    break;
                } else if (mapp[nr][nc] == 'O') {
                    red.first = nr;
                    red.second = nc;
                    break;
                }
            }

            visited[red.first][red.second]++;
            if (visited[red.first][red.second] > 2) return 0;




        } else {

        }


        if (mapp[blue.first][blue.second] == 'O') {
            return 0;
        }
        if (mapp[red.first][red.second] == 'O') {
            return 1;
        }


    }
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
        visited.push_back(vector<int>(M, 0));
    }
    visited[red.first][red.second] = 1;
    cout << dfs(visited);
    return 0;
}