#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
bool isVisited[9];
string answer;

void dfs(int cnt) {

    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            answer += to_string(arr[i]);
            answer += " ";
        }
        answer += "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            isVisited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    dfs(0);
    cout << answer;

    return 0;
}
