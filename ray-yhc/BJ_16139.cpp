//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;
int accumulatedCount['z' - 'a' + 1][200000];

int main() {

    int N;
    char c;
    string s;
    fill(accumulatedCount[0], (accumulatedCount[0] + 2000 * ('z' - 'a' + 1)), 0);

    cin >> s;

    accumulatedCount[s.at(0) - 'a'][0] = 1;
    for (int i = 1; i < s.size(); ++i) {
        int charNum = s.at(i) - 'a';
        for (int al = 0; al < 'z' - 'a' + 1; ++al) {
            if (al == charNum) accumulatedCount[al][i] = accumulatedCount[al][i - 1] + 1;
            else accumulatedCount[al][i] = accumulatedCount[al][i - 1];
        }
    }

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> c >> l >> r;

        if (l == 0)
            printf("%d\n", accumulatedCount[c - 'a'][r]);
        else
            printf("%d\n", (accumulatedCount[c - 'a'][r] - accumulatedCount[c - 'a'][l - 1]));
    }

    return 0;
}