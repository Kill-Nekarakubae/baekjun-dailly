//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int N = 9;
    int total = 0;
    vector<int> tall;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        tall.push_back(t);
        total += t;
    }

    int check;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            check = (total - tall[i] - tall[j]);
            if (check == 100) {
                int t1 = tall[i], t2 = tall[j];
                tall.erase(remove(tall.begin(), tall.end(), t1), tall.end());
                tall.erase(remove(tall.begin(), tall.end(), t2), tall.end());
                break;
            }
        }
        if (check == 100) break;
    }


    sort(tall.begin(), tall.end());
    for (int i = 0; i < tall.size(); ++i) {
        cout << tall[i] << endl;
    }

    return 0;
}