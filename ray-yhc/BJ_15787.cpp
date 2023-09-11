//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <unordered_set>

using namespace std;
#define ull unsigned long long
#define pip pair<int, pair<int,int> >
#define pi pair<int, int>

int trains[100000];

void printBits(int n) {
    for (int i = 19; i >= 0; --i) {
        std::cout << ((n & (1 << i)) ? '1' : '0');
    }
    std::cout << std::endl;
}

int main() {
    int N,M;
    cin >> N >> M;

    int mask = (1 << 20) - 1;

    for (int j = 0; j < M; ++j) {
        int c, i, x;
        cin >> c >> i;
        i--;
        switch (c) {
            case 1:
                cin >> x;
                trains[i] = trains[i] | (1 << (x-1));
                break;
            case 2:
                cin >> x;
                trains[i] = trains[i] & (mask ^ (1 << (x-1)));
                break;
            case 3:
                trains[i] <<= 1;
                break;
            case 4:
                trains[i] >>= 1;
                break;
            default:
                break;
        }
        trains[i] = trains[i] & mask;
    }

    unordered_set<int> us;
    for (int i = 0; i < N; ++i) {
        us.insert(trains[i] & mask);
    }

//    printBits(mask);
//    for (int i = 0; i < N; ++i) {
//        printBits(trains[i]);
//    }

    cout << us.size();
    return 0;
}