//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;
#define pip pair<int, pair<int,int> >


int N, M;

int main() {
    string str;
    cin >> str;
    set<string> s;

    int size = str.size();
    for (int i = 0; i < size; ++i) {
        s.insert(str.substr(i, size));
    }

    for (string ss: s) {
        cout << ss << endl;
    }
    return 0;
}

// 15
// BJBOJOJOOJOBOJO