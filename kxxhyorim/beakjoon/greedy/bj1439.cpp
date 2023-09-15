#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int n = (int) s.length();
    int zero = 0, one = 0;
    char before = s[0];
    if (before == '0') zero++;
    else one++;

    for (int i = 1; i < n; i++) {
        if (s[i] == before) {
            continue;
        } else {
            if (s[i] == '0') zero++;
            else one++;
        }
        before = s[i];
    }

    cout << min(zero, one);

    return 0;
}
