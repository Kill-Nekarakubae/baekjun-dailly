#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int dp[5000][5000] = {0};
int num[5000];

int doRecursive(int L, int R) {
    if (L >= R) return 0;
    if (dp[L][R] != 0) return dp[L][R];

    if (num[L] == num[R])
        dp[L][R] = doRecursive(L + 1, R - 1);
    else
        dp[L][R] = min(doRecursive(L + 1, R), doRecursive(L, R - 1)) + 1;

    return dp[L][R];
}

int main() {
    int N;
    cin >> N;

    deque<int> deque;
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }

    cout << doRecursive(0, N - 1);

//    int b, e, count = 0;
//    while (deque.size() > 1) {
//        if (deque.front() == deque.back()) {
//            deque.pop_front();
//            deque.pop_back();
//            continue;
//        }
//
//        b = deque.front();
//        deque.pop_front();
//        e = deque.back();
//        deque.pop_back();
//        if (deque.empty()) {
//            count++;
//            break;
//        } else if (b == deque.back()) {
//            count++;
//            deque.pop_back();
//        } else if (e == deque.front()) {
//            count++;
//            deque.pop_front();
//        } else {
//            count += 2;
//        }
//    }
//
//    cout << count;

    return 0;
}

// 1 2 3 4 2
// 1 2 3 4 2 1

// 1 4 2 3 4 3 2
// 2 1 4 2 3 4 3 2
// 2 3 1 4 2 3 4 3 2
// 2 3 1 4 2 3 4 1 3 2
// 2 3 1 4 3 2 3 4 1 3 2
//