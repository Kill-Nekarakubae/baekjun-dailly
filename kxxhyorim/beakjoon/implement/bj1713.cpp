#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, idx;
    deque<pair<pair<int, int>, int>> d; // 추천수, 시점, idx
    cin >> n >> r;
    for (int i = 0; i < r; i++) {
        cin >> idx;
        bool isAlreadyExist = false;
        for (int j = 0; j < d.size(); j++) {
            if (d[j].second == idx) { // idx
                d[j].first.first++; // 이미 있으면 추천수 올림
                isAlreadyExist = true;
            }
        }

        if (!isAlreadyExist) {
            if (d.size() >= n) { // 비어있는 사진틀이 없는 경우
                sort(d.begin(), d.end());
                d.pop_front();
            }
            d.push_front({{1, i}, idx});
        }
    }

    vector<int> answer;
    for (int i = 0; i < n; i++) {
        if (d[i].first.first != 0) {
            answer.emplace_back(d[i].second);
        }
    }
    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
