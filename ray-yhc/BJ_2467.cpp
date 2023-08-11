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

int N, M;

int dp[10001][2];
vector<int> solution;


void printSol(int s1, int s2) {
    if (s1 < s2)
        cout << s1 << ' ' << s2 << endl;
    else
        cout << s2 << ' ' << s1 << endl;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        solution.push_back(t);
    }

    long long minResult = 2000000001;
    int s1, s2;
    for (int i = 0; i < solution.size(); ++i) {
        int b = 0, e = solution.size();
        long long minSum = 2000000001;
        int j;

        while (b < e) {
            int m = (b + e) / 2;

            // m==i
            long long s = solution[i] + solution[m];

            if (i != m && abs(minSum) > abs(s)) {
                if (s == 0) {
                    printSol(solution[i], solution[m]);
                    return 0;
                }

                minSum = abs(s);
                j = m;
            }

            if (s < 0) {
                b = m + 1;
            } else {
                e = m;
            }
        }

        if (i != j && abs(minResult) > abs(minSum)) {
            minResult = minSum;
            s1 = solution[i];
            s2 = solution[j];
        }
    }
    printSol(s1, s2);
    return 0;
}
