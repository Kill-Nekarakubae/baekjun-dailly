//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

struct compare {
    bool operator()(string &i, string &c) {
        return strcmp(c.c_str(), i.c_str())<0;
    }
};

unordered_map<string, int> lmap;
priority_queue<string, vector<string>, compare> smap;

int main() {
    int N, M;
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        lmap[s] = 1;
    }
    for (int i = 0; i < M; ++i) {
        cin >> s;
        auto iter = lmap.find(s);
        if (iter != lmap.end())
            smap.push(s);
    }

    cout << smap.size() << endl;
    while (!smap.empty()) {
        cout << smap.top() << endl;
        smap.pop();
    }

    return 0;
}