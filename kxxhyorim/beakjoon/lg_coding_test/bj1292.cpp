#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;


    int sum = 0;

    vector<int> v;

    int num = 1;
    while (v.size() <= b) {
        for (int i = 1; i <= num; i++) {
            v.emplace_back(num);
        }
        num++;
    }

    for (int i = a - 1; i <= b - 1; i++) {
        sum += v[i];
    }

    cout << sum;


    return 0;
}
