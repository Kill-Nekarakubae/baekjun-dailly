#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> cow(n);
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }

    vector<bool> isSelected(n);
    for (int i = n - m; i < n; i++) {
        isSelected[i] = true;
    }

    vector<int> possible_sum;

    do {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (isSelected[i]) sum += cow[i];
        }

        if (isPrime(sum)) possible_sum.push_back(sum);

    } while (next_permutation(isSelected.begin(), isSelected.end()));


    vector<int> unique_vector;
    set<int> set;
    if (possible_sum.size() > 0) {
        for (int i = 0; i < possible_sum.size(); i++) {
            set.emplace(possible_sum[i]);
        }
        for(auto it = set.begin(); it != set.end(); it++){
            unique_vector.emplace_back(*it);
        }
        sort(unique_vector.begin(), unique_vector.end());
        for (int i = 0; i < unique_vector.size(); i++) {
            cout << unique_vector[i] << " ";
        }
    } else {
        cout << "-1";
    }


    return 0;
}
