#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long dp[200000][3] = {0};
int lv[200000];

struct node {
    int parent;
    vector<int> childs;
};
node node[200001];

long long recur(int i) {
    if (node[i].childs.empty()) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
        return 0;
    }
    if (dp[i][2] != 0) return dp[i][2];

    long long childSumWithRoots = 0;
    for (int c: node[i].childs) {
        recur(c);
        childSumWithRoots += dp[c][2];
    }

    for (int c: node[i].childs) {
        // dp[i][1] = (i를 멘토링에 넣지 않았을 때, i를 루트로 하는 서브트리의 최대 시너지)
        // dp[parent][1] = max(dp[c][0], dp[c][1])
        dp[i][1] = childSumWithRoots;

        // dp[i][0] = (i를 멘토링에 넣었을 때, i를 루트로 하는 서브트리의 최대 시너지)
        // dp[parent][0] = dp[c][1] + lv(p) * lv(c)
        dp[i][0] = max(dp[i][0],
                       childSumWithRoots - dp[c][2] + dp[c][1] + lv[i] * lv[c]);

    }

    dp[i][2] = max(dp[i][0], dp[i][1]);

    return dp[i][2];
}

int main() {
    int N;
    cin >> N;
    node[1].parent = 1;
    for (int i = 2; i <= N; ++i) {
        int pnum;
        cin >> pnum;
        node[i].parent = pnum;
        node[pnum].childs.push_back(i);
    }

    for (int i = 1; i <= N; ++i) {
        cin >> lv[i];
    }

    cout << recur(1);
    return 0;
}
