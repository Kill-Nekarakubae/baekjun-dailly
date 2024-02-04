#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

//bool counterUp(vector<int> &counter) {
//    int i = 0;
//    while (i < counter.size()) {
//        counter[i]++;
//        if (counter[i] >= 6) {
//            counter[i] = 0;
//            i++;
//        } else break;
//    }
//    if (i == counter.size()) return false;
//    return true;
//}
//
//int simulation(vector<vector<int>> &dice, unordered_set<int> &aSet) {
//
//    vector<int> counter(dice.size(), 0);
//    int win = 0;
//
//    while (true) {
//        int a = 0, b = 0;
//        for (int i = 0; i < dice.size(); i++) {
//            if (aSet.find(i) != aSet.end()) a += dice[i][counter[i]];
//            else b += dice[i][counter[i]];
//        }
//        if (a > b) win++;
//        if (!counterUp(counter)) return win;
//    }
//}


int simulation_v2(vector<vector<int>> &dice, unordered_set<int> &aSet) {
    int maxLose = (int) pow(6, dice.size()) / 2;
    vector<int> counter(dice.size(), 0);
    int win = 0, lose = 0;
    int a = 0, b = 0;

    for (int i = 0; i < dice.size(); i++) {
        if (aSet.find(i) != aSet.end()) a += dice[i][counter[i]];
        else b += dice[i][counter[i]];
    }
    if (a > b) win++;
    else if (a < b) lose++;

    while (true) {
        if (lose > maxLose) return -1;

        int i = 0;
        while (i < counter.size()) {
            if (aSet.find(i) != aSet.end()) a -= dice[i][counter[i]];
            else b -= dice[i][counter[i]];

            counter[i]++;
            if (counter[i] >= 6) {
                counter[i] = 0;
                if (aSet.find(i) != aSet.end()) a += dice[i][counter[i]];
                else b += dice[i][counter[i]];
                i++;
            } else {
                if (aSet.find(i) != aSet.end()) a += dice[i][counter[i]];
                else b += dice[i][counter[i]];
                break;
            }
        }
        if (i == counter.size()) return win;
        if (a > b) win++;
        else if (a < b) lose++;
    }
}


pair<int, vector<int>> combination(vector<vector<int>> &dice, unordered_set<int> aSet, int n, int r, int d) {
    if (r == 0) { //todo 반으로 줄일 방법 생각해보기!!!!
        for (auto a: aSet) cout << a << " ";

        int win = simulation_v2(dice, aSet);
        cout << win << endl;

        if (win == -1) return {-1, vector<int>()};

        return {
                win,
                vector<int>(aSet.begin(), aSet.end())
        };
    }
    if (d == n) return {-1, vector<int>()};

    pair<int, vector<int>> p1 = combination(dice, aSet, n, r, d + 1);
    aSet.insert(d);
    pair<int, vector<int>> p2 = combination(dice, aSet, n, r - 1, d + 1);
    return (p1.first > p2.first) ? p1 : p2;
}

vector<vector<int>> table;

pair<int,int> simulation(vector<int> &a, vector<int> &b) {
    int win = 0, lose = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] > b[j]) win++;
            else if (a[i] < b[j]) lose++;
        }
    }
    return {win, lose};
}

vector<int> solution(vector<vector<int>> dice) {
    table = vector<vector<int>>(dice.size(), vector<int>(dice.size(), 0));

    for (int i = 0; i < dice.size(); ++i) {
        for (int j = i+1; j < dice.size(); ++j) {
            pair<int,int> result = simulation(dice[i], dice[j]);
            table[i][j] = result.first;
            table[j][i] = result.second;
        }
    }

    vector<pair<int, int>> numbers;
    pair<int, vector<int>> result = combination(dice, unordered_set<int>(), dice.size(), dice.size() / 2, 0);
    vector<int> myDice = result.second;
    sort(myDice.begin(), myDice.end());
    for (int i=0; i<myDice.size(); i++) myDice[i]++;
    return myDice;
}


int main() {

    vector<int> v;
    v = solution({{1, 2, 3, 4, 5, 6},
                  {3, 3, 3, 3, 4, 4},
                  {1, 3, 3, 4, 4, 4},
                  {1, 1, 4, 4, 5, 5}});
    cout << endl;
    for (int i: v)
        cout << i << " ";
    cout << endl;
    cout << endl;

    v = solution(
            {{1, 2, 3, 4, 5, 6},
             {2, 2, 4, 4, 6, 6}});
    cout << endl;
    for (int i: v)
        cout << i << " ";
    cout << endl;
    cout << endl;

    v = solution({{40, 41, 42, 43, 44, 45},
                  {43, 43, 42, 42, 41, 41},
                  {1,  1,  80, 80, 80, 80},
                  {70, 70, 1,  1,  70, 70}});
    cout << endl;
    for (int i: v)
        cout << i << " ";
    cout << endl;
    cout << endl;


    v = solution(
            {{40, 41, 42, 43, 44, 45}, {43, 43, 42, 42, 41, 41}, {1, 1, 80, 80, 80, 80}, {70, 70, 1, 1, 70, 70}, {1, 2, 3, 4, 5, 6}, {2, 2, 4, 4, 6, 6}, {3, 3, 3, 3, 4, 4}, {1, 3, 3, 4, 4, 4}, {1, 1, 4, 4, 5, 5}, {1, 1, 4, 4, 5, 90}}
    );
    cout << endl;
    for (int i: v)
        cout << i << " ";
    cout << endl;
    cout << endl;

    return 0;
}
