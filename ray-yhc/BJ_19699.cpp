//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;
int cow[10];
set<int> result;


bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int sumVector(vector<int> v) {
    int s = 0;
    for (int i = 0; i < v.size(); ++i) {
        s += v[i];
    }
    return isPrime(s) ? s : -1;
}

void combi(vector<int> v, int n, int r, int d) {
    if (v.size() == r) {
        int s = sumVector(v);
        if (s != -1)
            result.insert(s);
        return;
    }
    if (d == n) {
        return;
    }

    combi(v, n, r, d + 1);
    v.push_back(cow[d]);
    combi(v, n, r, d + 1);
    v.pop_back();
}

int main() {
    int M, N;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> cow[i];
    }

    vector<int> v;
    combi(v, N, M, 0);
//    sort(result.begin(), result.end());
    if (result.empty()) {
        cout << -1;
        return 0;
    }

    for (int i : result) {
        cout << i << ' ';
    }


    return 0;
}