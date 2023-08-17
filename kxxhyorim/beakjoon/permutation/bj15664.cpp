#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());


    set<vector<int>> s;


    vector<bool> isVisited(n);
    for (int i = n - 1; i >= n - m; i--) {
        isVisited[i] = true;
    }

    do {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (isVisited[i])
                temp.emplace_back(v[i]);
        }
        s.insert(temp);

    } while (next_permutation(isVisited.begin(), isVisited.end()));


    for (auto it = s.begin(); it != s.end(); it++) {
        vector<int> temp = *it;
        for (int j = 0; j < temp.size(); j++) {
            cout << temp[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
