#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#include <string>
#include<map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isContain(string order, vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        char c1 = v[i];
        bool tempResult = false;
        for (int j = 0; j < order.length(); j++) {
            char c = order[j];
            if (c == c1) {
                tempResult = true;
                break;
            }
        }
        if (!tempResult) { return false; }
    }
    return true;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 각 알파벳 별 주문회수
    vector<int> cnt;
    cnt.resize(26);
    for (int i = 0; i < orders.size(); i++) {
        string s = orders[i];
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            int idx = c - 'A';
            cnt[idx]++;
        }
    }

    // 두번 이상 주문된 알파벳
    vector<char> characters;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 2)
            characters.emplace_back(char(i + 'A'));
    }
    int ch_size = characters.size();


    for (int i = 0; i < course.size(); i++) {
        int n = course[i]; // n개로 조합 검사 하기
        vector<bool> isSelected;
        isSelected.resize(ch_size);
        for (int j = ch_size - 1; j > ch_size - 1 - n; j--) {
            if (j < 0) break;
            isSelected[j] = true;
        }
        int maxCnt = -1;
        vector<string> candidate;

        do {
            // 후보 계속 도출
            vector<char> combi;

            for (int j = 0; j < ch_size; j++) {
                if (isSelected[j]) {
                    char c = characters[j];
                    combi.emplace_back(c);

                }
            }

            // ex 조합 A,C 가 Orders에 얼마나 있는지 검사

            int cnt = 0;
            for (int j = 0; j < orders.size(); j++) {
                string order = orders[j];
                if (isContain(order, combi)) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                // 조합 출력

                string s = "";
                for (int j = 0; j < combi.size(); j++) {
                    s += combi[j];
                }


                if (cnt > maxCnt) {
                    maxCnt = cnt;
                    candidate.clear();
                    candidate.emplace_back(s);
                } else if (cnt == maxCnt) {
                    candidate.emplace_back(s);
                }
            }

        } while (next_permutation(isSelected.begin(), isSelected.end()));

        for (int i = 0; i < candidate.size(); i++) {
            answer.emplace_back(candidate[i]);
        }
    } // end for loop

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<string> v2 = {"XYZ", "XWY", "WXA"};
    vector<int> c = {2, 3, 4};
    solution(v2, c);
    return 0;
}
