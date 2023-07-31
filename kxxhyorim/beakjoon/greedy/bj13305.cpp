//
// Created by 김효림 on 2023/07/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

using namespace std;

vector<ull> dist;
vector<ull> price;

ull getDist(int start, int end) {
    ull sum = 0;
    for (int i = start; i < end; i++) {
        sum += dist[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ull oil = 0;
    cin >> n;
    dist.resize(n - 1);
    price.resize(n);

    for (int i = 0; i < n - 1; i++) { cin >> dist[i]; }
    for (int i = 0; i < n; i++) { cin >> price[i]; }

    // 현재 있는곳 보다 싼 곳이 있을때까지 갈수있는 오일 주유
    // 나보다 다 비싼거 밖에 없어 -> 여기서 다 넣음
    for (int i = 0; i < n - 1;) {
        ull curr_oil = price[i];
        ull next_oil = price[i + 1];

        if (curr_oil >= next_oil) {
            oil += price[i] * dist[i];
            i++;
            continue;
        } else {
            bool isFindMin = false;
            int destination;
            for (int j = i + 1; j < n; j++) {
                next_oil = price[j];
                if (next_oil < curr_oil) {

                    destination = j;
                    isFindMin = true;
                    break;
                }
            }
            if (!isFindMin) {
                destination = n - 1;
            }

            oil += curr_oil * getDist(i, destination);
            i += (destination - i);
        }
    }

    cout << oil;

    return 0;
}
