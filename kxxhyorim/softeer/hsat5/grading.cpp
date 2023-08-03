#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, score_input;
    cin >> n;
    vector<int> rank(n);
    vector<pair<int, int>> score; // score, 참가자idx
    vector<pair<int, int>> score_sum(n); // score, 참가자idx

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> score_input;
            score.emplace_back(score_input, j);
            score_sum[j].first += score_input;
            score_sum[j].second = j;
        }
        sort(score.begin(), score.end());
        reverse(score.begin(), score.end());
        int before = -1;
        int beforeRank = -1;
        for (int j = 0; j < n; j++) {
            int sc = score[j].first;
            int personIdx = score[j].second;
            if (sc == before) {
                rank[personIdx] = beforeRank;
            } else {
                rank[personIdx] = j + 1;
            }
            before = sc;
            beforeRank = rank[personIdx];
        }

        for (int j = 0; j < n; j++) {
            cout << rank[j] << " ";
        }
        cout << endl;
        score.clear();
    }

    sort(score_sum.begin(), score_sum.end());
    reverse(score_sum.begin(), score_sum.end());
    int before = -1;
    int beforeRank = -1;
    for (int j = 0; j < n; j++) {
        int sc = score_sum[j].first;
        int personIdx = score_sum[j].second;
        if (sc == before) {
            rank[personIdx] = beforeRank;
        } else {
            rank[personIdx] = j + 1;
        }
        before = sc;
        beforeRank = rank[personIdx];
    }

    for (int j = 0; j < n; j++) {
        cout << rank[j] << " ";
    }

    return 0;
}