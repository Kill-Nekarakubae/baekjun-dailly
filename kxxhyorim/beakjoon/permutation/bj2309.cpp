//
// Created by 김효림 on 2023/07/26.
//
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> height(9);
    vector<bool> isSelected(9);
    for (int i = 2; i < 9; i++) {
        isSelected[i] = true;
    }
    vector<int> real;

    for (int i = 0; i < 9; i++) {
        cin >> height[i];
    }

    do {
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            if (isSelected[i]) {
                sum += height[i];
            }
        }
        if (sum == 100) {

            for (int i = 0; i < 9; i++) {
                if (isSelected[i]) {
                    real.push_back(height[i]);
                }
            }

            sort(real.begin(), real.end());

            for (int i = 0; i < 7; i++) {
                cout << real[i] << endl;
            }

            break;
        }

    } while (next_permutation(isSelected.begin(), isSelected.end()));


    return 0;
}
