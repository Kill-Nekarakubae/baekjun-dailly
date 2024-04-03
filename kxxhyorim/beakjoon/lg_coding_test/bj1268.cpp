#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

vector<map<int, vector<int>>> v(5);
vector<set<int>> sameClass(1003);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int g1, g2, g3, g4, g5;
        cin >> g1 >> g2 >> g3 >> g4 >> g5;
        v[0][g1].emplace_back(i); // 1학년 g1반에 i번 학생이 있었다
        v[1][g2].emplace_back(i);
        v[2][g3].emplace_back(i);
        v[3][g4].emplace_back(i);
        v[4][g5].emplace_back(i);
    }

    for (int i = 0; i < 5; i++) { // 학년별 검사
        map<int, vector<int>> m = v[i];
        for (auto it = m.begin(); it != m.end(); it++) {
            vector<int> students = it->second;
            if (students.size() <= 1) continue;
            for (int j = 0; j < students.size(); j++) {
                for (int k = 0; k < students.size(); k++) {
                    if (j == k) continue;
                    sameClass[students[j]].emplace(students[k]);
                }
            }
        }
    }

    int maxN = 0;
    int answerIdx = 1;
    for (int i = 1; i <= n; i++) {
        if (sameClass[i].size() > maxN) {
            maxN = sameClass[i].size();
            answerIdx = i;
        }
    }
    cout << answerIdx;
    return 0;
}