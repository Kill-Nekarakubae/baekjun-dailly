#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, cnt = 0;
char road[1000];
int isVisited[1000];

void bfs(int i) {
    isVisited[i] = cnt;
    queue<int> q;
    q.emplace(i);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        int nx = (road[idx] == 'E') ? idx + 1 : idx - 1;
        if (isVisited[nx] == 0) {
            q.emplace(nx);
            isVisited[nx] = cnt;
        } else {
            isVisited[idx] = isVisited[nx];
            cnt = isVisited[idx];
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        road[i] = s[i];
    }

    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            cnt++;
            bfs(i);
        }
    }

    cout << cnt;

    return 0;
}