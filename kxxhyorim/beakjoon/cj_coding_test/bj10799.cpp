#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    int n = (int) str.length();
    int stackSize = 0;
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        bool isLaser = (str[i] == '(' && str[i + 1] == ')');
        if (isLaser) {
            sum += (int) stackSize;
            i++;
            continue;
        }

        if (str[i] == '(') {
            stackSize++;
        } else {
            stackSize--;
            sum++;
        }
    }

    if (str[n - 1] == ')' && str[n - 2] != '(') {
        sum++;
    }

    cout << sum;

    return 0;
}

