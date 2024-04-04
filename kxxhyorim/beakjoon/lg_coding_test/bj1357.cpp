#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x, y;
    int rx, ry;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    rx = stoi(x);
    ry = stoi(y);

    int sum = rx + ry;
    string answer = to_string(sum);
    reverse(answer.begin(), answer.end());
    cout << stoi(answer);

    return 0;
}
