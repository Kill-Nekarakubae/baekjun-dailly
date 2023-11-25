#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void shiftRow(deque<deque<int>> &dq, int rows) {
    for (int i = 0; i < rows; ++i) {
        dq.push_front(dq.back());
        dq.pop_back();
    }
}

void rotate(deque<deque<int>> &dq, int iters) {
    int rows = dq.size(), cols = dq[0].size();
    for (int i = 1; i <= iters; ++i) {
        dq[0].push_front(dq[i].front());
        dq[i].pop_front();

        dq[rows-1].push_back(dq[rows-i-1].back());
        dq[rows-i-1].pop_back();
    }
    for (int i = 1; i+iters <= rows-2 ; ++i) {
        dq[i].push_front(dq[i+iters].front());
        dq[i+iters].pop_front();

        dq[rows-i-1].push_back(dq[rows-i-iters-1].back());
        dq[rows-i-iters-1].pop_back();
    }
    for (int i = iters; i >= 1; --i) {
        dq[rows - i - 1].push_front(dq[rows - 1].front());
        dq[rows - 1].pop_front();

        dq[i].push_back(dq[0].back());
        dq[0].pop_back();
    }
}
void shiftRow(deque<deque<int>*> &dq, deque<int> &left, deque<int> &right) {
    dq.push_front(dq.back());
    dq.pop_back();
    left.push_front(left.back());
    left.pop_back();
    right.push_front(right.back());
    right.pop_back();
}

void rotate(deque<deque<int>*> &dq, deque<int> &left, deque<int> &right) {
    dq[0]->push_front(left.front());
    left.pop_front();
    right.push_front(dq[0]->back());
    dq[0]->pop_back();
    dq[dq.size()-1]->push_back(right.back());
    right.pop_back();
    left.push_back(dq[dq.size()-1]->front());
    dq[dq.size()-1]->pop_front();
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    deque<deque<int>*> dq;
    int rows = rc.size(), cols= rc[0].size();
    deque<int> left, right, rowdq[rows];
    for (int i = 0; i < rows; ++i) {
        vector<int> v = rc[i];
        rowdq[i] =  deque<int> (v.begin() + 1, v.end() - 1);
        dq.push_back(&rowdq[i]);
        left.push_back(v.front());
        right.push_back(v.back());
    }

    vector<int> ops;
    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];
        int count = 1;
        for (i++; i < operations.size(); i++) {
            if (operations[i] != op) {
                i--;
                break;
            }
            count++;
        }
        if (op == "Rotate"){
            if (count > 2 * (rows + cols - 2)) {
                count = count % (2 * (rows + cols - 2));
            }
            ops.push_back(count);
        }
        else { // Shift
            if (count > rows) {
                count  = count % rows;
            }
            ops.push_back(-count);
        }
    }

    for (auto op: ops) {
        if (op > 0) {
            for (int i = 0; i < op; ++i)
                rotate(dq, left, right);
        } else {
            for (int i = 0; i < -op; ++i)
                shiftRow(dq, left, right);
        }
    }

    vector<vector<int>> answer;
    for (int i = 0; i < dq.size(); ++i) {
        vector<int> v;
        v.push_back(left[i]);
        v.insert(v.end(), dq[i]->begin(), dq[i]->end());
        v.push_back(right[i]);
        answer.push_back(v);
    }
    return answer;
}

int main() {

    vector<vector<int>> answer;

    answer = solution(
            {
                    {1, 2, 3,4,5,6,7,8,9,10},
                    {11,12,13,14,15,16,17,18,19,20},
                    {21,22,23,24,25,26,27,28,29,30},
                    {31,32,33,34,35,36,37,38,39,40},
                    {41,42,43,44,45,46,47,48,49,50},
                    {51,52,53,54,55,56,57,58,59,60},
                    {61,62,63,64,65,66,67,68,69,70},
                    {71,72,73,74,75,76,77,78,79,80},
                    {81,82,83,84,85,86,87,88,89,90},
                    {91,92,93,94,95,96,97,98,99,100}
            },
            {"Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate", "Rotate"
//             ,"ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow", "Rotate", "ShiftRow"
            });
    for (auto v: answer) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << endl;

    answer = solution(
            {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}},
            {"Rotate", "ShiftRow"});
    for (auto v: answer) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << endl;

    answer = solution(
            {{8, 6, 3},
             {3, 3, 7},
             {8, 4, 9}},
            {"Rotate", "ShiftRow", "ShiftRow"});
    for (auto v: answer) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << endl;

    answer = solution(
            {{1, 2,  3,  4},
             {5, 6,  7,  8},
             {9, 10, 11, 12}},
            {"ShiftRow", "Rotate", "ShiftRow", "Rotate"});
    for (auto v: answer) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
