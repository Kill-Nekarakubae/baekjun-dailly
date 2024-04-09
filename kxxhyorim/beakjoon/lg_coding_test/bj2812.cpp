#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, popCnt = 0;
    string str;
    cin >> n >> k >> str;
    vector<int> num;
    for (char i: str) {
        num.emplace_back(i - '0');
    }

    stack<int> s;
    int idx = 0;

    while (popCnt < k) {
        while (!s.empty() && s.top() < num[idx] && popCnt < k) {
            s.pop();
            popCnt++;
        }
        if (idx >= n)
            break;
        s.emplace(num[idx++]);
    }

    string temp;
    while (!s.empty()) {
        temp += to_string(s.top());
        s.pop();
    }

    reverse(temp.begin(), temp.end());
    temp += str.substr(idx, n - idx);

    if (popCnt != k) {
        temp = temp.substr(0, n - k);
    }

    cout << temp;

    // stack에 있는거 pop 하하고 reverse
    // index ~ n-1 까지 string 이어 붙이기

    return 0;
}
