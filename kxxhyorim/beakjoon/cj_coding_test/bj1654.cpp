#include <iostream>
#include <vector>

#define ull unsigned long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull k, n, length; // 갖고있는 랜선 개수, 필요한 개수
    cin >> k >> n;
    vector<int> v;
    ull maxLength = 0;

    for (int i = 0; i < k; i++) {
        cin >> length;
        maxLength = max(maxLength, length);
        v.emplace_back(length);
    }

    ull start = 1;
    ull end = maxLength;

    ull answer = 0;

    while (start <= end) {
        ull mid = (start + end) / 2;
        ull sum = 0;
        for (int i = 0; i < k; i++) {
            sum += v[i] / mid;
        }

        if (sum >= n) { // 과하게 많이 자른 경우
            answer = max(answer, mid); // 임시저장 하고
            start = mid + 1;
        } else if (sum < n) { // 조각 개수가 부족하면 더 짧게 잘라야함
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
