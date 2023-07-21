//
// Created by 김효림 on 2023/07/19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m, l, discard = 0;
    cin >> n >> k >> m;

    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> l;
        if (l <= k) {
            v[i] = 0; // 폐기
            discard++;
        } else if (l < (2 * k)) // 한쪽 꼬다리만 잘라낸다
            v[i] = l - k;
        else v[i] = l - (2 * k); // 꼬다리 두개 다 잘라냄
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int new_size = n - discard;
    v.resize(new_size);

    int start = 1;
    int end = v[0]; // 젤 큰김밥
    int possible_p = -1;
    while (start <= end) {
        int p = (start + end) / 2; // 김밥길이 1부터 시작

        int count = 0; // 잘린 김밥 개수
        for (int i = 0; i < new_size; i++) {
            count += v[i] / p;
        }
        if (count < m) {
            end = p - 1;
        } else { // 김밥이 너무 많이 잘림, p 키워
            possible_p = p;
            start = p + 1;
        }
    }

    cout << possible_p;

    return 0;
}
