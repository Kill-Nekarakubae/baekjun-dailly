#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>

#define ull unsigned long long
#define endl "\n"

using namespace std;
// map : heap - O(logN) 삽입 조회
// unordered_map : hashmap - O(1) 삽입 조회

int n, m, p, l, x;

// < l, p >
priority_queue<pair<int, int>> min_h; // todo - 붙여서 넣고 뺴고
priority_queue<pair<int, int>> max_h;
// map < p, l >
unordered_map<int, int> hashmap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> l;
        min_h.emplace(-l, -p);
        max_h.emplace(l, p);
        hashmap[p] = l;
    }

    cin >> m;
    string command;
    for (int i = 0; i < m; i++) {
        cin >> command;
        // switch 문은 string 사용이 직접적으로 불가함
        if (command == "add") {
            cin >> p >> l;
            min_h.emplace(-l, -p);
            max_h.emplace(l, p);
            hashmap[p] = l;
        } else if (command == "recommend") {
            cin >> x;
            if (x == 1) { // max heap, 빼고 hashmap 변경
                while (true) {
                    l = max_h.top().first;
                    p = max_h.top().second;
                    if (hashmap[p] != -1 && hashmap[p] == l) break;
                    max_h.pop();
                }

                cout << p << endl;
            } else if (x == -1) { // min heap, , 빼고 hashmap 변경
                while (true) {
                    l = -min_h.top().first;
                    p = -min_h.top().second;
                    if (hashmap[p] != -1 && hashmap[p] == l) break;
                    min_h.pop();
                }
                cout << p << endl;
            }
        } else if (command == "solved") {
            cin >> p;
            hashmap[p] = -1;
        } else {
            cout << "unknown command\n";
        }
    }

    return 0;
}