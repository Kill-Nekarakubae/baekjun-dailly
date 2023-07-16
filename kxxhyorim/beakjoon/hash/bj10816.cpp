//
// Created by 김효림 on 2023/07/13.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, temp;
vector<int> v(20000001);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[temp + 10000000]++;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << v[temp + 10000000] << " ";
    }


    return 0;
}
