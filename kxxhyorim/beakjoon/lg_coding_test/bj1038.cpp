#include <iostream>

using namespace std;

int n;
int length = 1;// 두자리수부터
int cnt = 9;
int arr[10];
bool isVisited[10];


void dfs(int depth) {

    if (depth == length) { // 배열 다참 후보라는 뜻
        cnt++;
        if (cnt == n) {
            for (int i = 0; i < depth; i++) {
                cout << arr[i];
            }
            exit(0);
        }
    }

    int curr;
    if (depth == 0) {
        curr = 10;
    } else {
        curr = arr[depth - 1];
    }

    for (int i = 0; i < curr; i++) {
        if (!isVisited[i]) {
            arr[depth] = i;
            isVisited[i] = true;
            dfs(depth + 1);
            isVisited[i] = false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if (n >= 0 && n <= 9) {
        cout << n;
        return 0;
    }

    for (int i = 2; i <= 10; i++) { // 숫자 길이
        length = i;
        dfs(0);
    }
    cout << "-1";

    return 0;
}
