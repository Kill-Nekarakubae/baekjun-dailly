//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <cmath>

using namespace std;

void addDigit(int *from, int *digit, int decimal) {
    *from = *digit * pow(10, decimal) + *from;
}

int imsii(int N, int K) {
    int ordinal99 = 0;
    int max99 = 0;

    for (int i = 0; i < K; ++i) {
        ordinal99 += N;
        int decimal = 7;
        int temp = ordinal99;
        int reverse99 = 0;
        bool flag = false;

        for (int d = decimal; d >= 0; --d) {
            int digit = temp / (int) pow(10, d);
            if (!flag && digit > 0) {
                decimal = d;
                flag = true;
                addDigit(&reverse99, &digit, decimal - d);
            } else if (flag) addDigit(&reverse99, &digit, decimal - d);

            if (digit > 0) {
                temp -= digit * pow(10, d);
            }
        }

        max99 = max(max99, reverse99);
    }
    return max99;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << imsii(N, K) << endl;
    return 0;
}