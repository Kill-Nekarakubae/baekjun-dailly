//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;
#define pip pair<int, pair<int,int> >

char getNext(char now) {
    switch (now) {
        case 'B':
            return 'O';
        case 'O':
            return 'J';
        case 'J':
            return 'B';
    }
    return 'B';
}

int N, M;

int main() {
    string s;
    cin >> N >> s;
    char now, next;
    int cost = 0;
    for (int i = 0; i < s.size()-1; ) {
        now = s.at(i);
        next = getNext(now);

        int nxIdx = -1;
        for (int j = i + 1; j < s.size(); ++j) {
            if (s.at(j) == next) {
                nxIdx = j;
                break;
            }
        }

        if (nxIdx == -1) {
            cout << -1 << endl;
            return 0;
        }
        cost += (nxIdx - i) * (nxIdx - i);
        i = nxIdx;
    }

    cout<<cost<<endl;
    return 0;
}

// 15
// BJBOJOJOOJOBOJO