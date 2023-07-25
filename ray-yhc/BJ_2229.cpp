//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>

using namespace std;

int N;
int point[1000];
int dp[1001][1001];

int maxTree[2000];
int minTree[2000];
int rec=0;

void segmentTreeInit() {
    for (int i = 0; i < N; ++i) {
        minTree[i + N] = point[i];
        maxTree[i + N] = point[i];
    }

    for (int i = N - 1; i > 0; --i) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1 | 1]);
        maxTree[i] = max(maxTree[i << 1], maxTree[i << 1 | 1]);
    }
}

int getMax(int l, int r) {
    int result = 0;

    for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
        if (l & 1) result = max(result, maxTree[l++]);
        if (r & 1) result = max(result, maxTree[--r]);
    }
    return result;
}

int getMin(int l, int r) {
    int result = 1000000;

    for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
        if (l & 1) result = min(result, minTree[l++]);
        if (r & 1) result = min(result, minTree[--r]);
    }
    return result;
}

int getPoint(int l, int r) {

    if (r - l < 2) return 0;
    else if (dp[l][r] != 0) return dp[l][r];

//    rec++;
    return getMax(l, r) - getMin(l, r);
}


int recursive(int l, int r){
    if (r - l < 2) return 0;

//    rec++;
    int maxPoint = getPoint(l, r);
    for (int i = l+2; i < r-1; ++i) {
        int left = (dp[l][i] == 0)? recursive(l, i) : dp[l][i];
        int right = (dp[i][r] == 0)? recursive(i, r) : dp[i][r];
        maxPoint = max(maxPoint, right+left);
        cout << l << ' ' << r << endl;
    }
    dp[l][r] = maxPoint;
    return maxPoint;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> point[i];
    }
    // 해당조 최고점 - 최저점
    // 각 조의 합

    segmentTreeInit();

    cout << recursive(0,N)<<endl;
//    cout << rec << endl;


    return 0;
}