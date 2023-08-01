//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> house;
bool wifi[20001];

int main() {
    int N, C;

    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        house.push_back(t);
    }
    sort(house.begin(), house.end());

    int start = 1;
    int end = house[N - 1] - house[0];
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        int wifies = 1;

        int prev = house[0];

        for (int i = 0; i < N; ++i) {
            if (house[i] - prev >= mid) {
                wifies++;
                prev = house[i];
            }
        }

        if (wifies >= C) {
            result = max(result, mid);
            start = mid + 1;
        } else end = mid - 1;

    }
    
    cout << result;

    return 0;
}