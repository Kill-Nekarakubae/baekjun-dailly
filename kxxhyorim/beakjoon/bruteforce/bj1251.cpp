#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    int n = (int) input.length();
    vector<string> v;


    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            string first = input.substr(0, i);
            string second = input.substr(i, j - i);
            string third = input.substr(j, n - j);
//            cout << first << " " << second << " " << third << endl;
            reverse(first.begin(), first.end());
            reverse(second.begin(), second.end());
            reverse(third.begin(), third.end());
//            cout << first << " " << second << " " << third << endl;
            string concat = first.append(second).append(third);
            v.push_back(concat);
        }
    }
    sort(v.begin(), v.end());
    cout << v[0];


    return 0;
}

