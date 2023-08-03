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
int N,s;
vector<int> cow;

struct compare {
    int key;
    compare(int const &i): key(i) {}

    bool operator()(int const &i) {
        return (i <= key);
    }
};

int main() {
    cin >> N >> s;
    bool sIsOdd = (s % 2) != 0;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        cow.push_back(n);
    }

    std::sort(cow.begin(), cow.end(), greater<int>() );

    int result = 0;
    for (int i = 0; i < cow.size(); ++i) {
        int now = cow[i];
        int key = s - now;
        int findIdx = distance(cow.begin(), find_if(cow.begin(), cow.end(), compare(key)));
        int res = (N - findIdx);
        if (i >= findIdx) res--;
        result += res;
    }




    cout << result/2;
    return 0;
}