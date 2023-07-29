//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
#define pip pair<int, pair<int,int> >
int N;
int  w[8];

int countEgg(int order[], int s[], int n, int d){


//    for (int i = 0; i < d; ++i) {
//        cout << order[i];
//    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i]<=0) count++;
    }

//    cout << "==" << count << endl;
    return count;
}

int permutaion(int order[], int s[],  int n, int d) {

    if (d == n) {
        return countEgg(order, s,n, d);
    }

    if (s[d] <= 0) {
        order[d] = -1;
        return permutaion(order, s, n, d + 1);
    }

    int MM = 0;
    bool allFalse = true;
    for (int i = 0; i < n; ++i) {
        if (i == d) continue;
        if (s[i] <= 0) continue;

        allFalse = false;
        order[d] = i;

        // hit
        int tempI = s[i];
        int tempD = s[d];
        s[i] -= w[d];
        s[d] -= w[i];

        MM = max(MM, permutaion(order, s, n, d + 1));

        // return
        s[i] = tempI;
        s[d] = tempD;
    }
    if (allFalse) return countEgg(order, s, n, d);
    return MM;
}

int main() {
    cin >> N;
    int s[8];
    for (int i = 0; i < N; ++i) {
        cin >> s[i] >> w[i];
    }

    int order[8];
    for (int i = 0; i < 8; ++i) {
        order[i] = i;
    }

    cout << permutaion(order,s, N, 0);
    return 0;
}