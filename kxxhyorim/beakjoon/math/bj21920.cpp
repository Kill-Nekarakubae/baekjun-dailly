//
// Created by 김효림 on 2023/07/19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    vector<int> v;

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> x;

    double coprimeSum = 0;
    int coprimeCount = 0;

    for (int i = 0; i < n; i++) {
        if (calculateGCD(v[i], x) == 1) { // 최대공약수 1 == 서로소
            coprimeSum += v[i];
            coprimeCount++;
        }
    }
    cout << coprimeSum / coprimeCount;
    return 0;
}
