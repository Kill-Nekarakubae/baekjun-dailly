#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

/* 테케만 돌아감..! 정답률 100 코드 아님.. 다음에 다시 볼 것*/

vector<set<int>> friendWith(1003);
int input[1003][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> input[i][j];
        }
    }

    for (int i = 0; i < 5; i++) { // 학년별로 검사
        for (int s1 = 0; s1 < n; s1++) {
            for (int s2 = s1; s2 < n; s2++) {
                if (s1 == s2) continue;
                if (input[i][s1] == input[i][s2]) {
                    int student1 = input[i][s1];
                    int student2 = input[i][s2];
                    friendWith[student1].emplace(student2);
                    friendWith[student2].emplace(student1);
                }
            }
        }
    }

    int maxN = 0;
    int answerIdx = -1;
    for (int i = 1; i <= n; i++) {
        if (friendWith[i].size() > maxN) {
            maxN = friendWith[i].size();
            answerIdx = i;
        }
    }

    if (answerIdx == -1) cout << 1;
    else cout << answerIdx + 1;

    return 0;
}