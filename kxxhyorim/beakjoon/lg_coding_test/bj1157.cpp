#include <iostream>

using namespace std;
int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 소문자 a 97
    // 대문자 A 65

    int diff = 'a' - 'A';

    string s;
    cin >> s;


    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        int idx = c - 'A';
        if (c >= 'a' && c <= 'z') { // 소문자면 대문자로 변환
            idx -= diff;
        }
        cnt[idx]++;
    }

    string answer = "";
    int maxCnt = 0;


    for (int i = 0; i < 26; i++) {
        if (cnt[i] > maxCnt) {
            maxCnt = cnt[i];
            answer = char(i + 'A');
        } else if (cnt[i] == maxCnt) {
            answer = "?";
        }
    }

    cout << answer;
    return 0;
}
