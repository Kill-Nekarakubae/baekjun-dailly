//
// Created by 김효림 on 2023/07/17.
//
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, strike, ball;
    cin >> n;
    string num;

    set < string > s;


    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                if (i != j && j != k && k != i)
                    s.emplace(to_string(i) + to_string(j) + to_string(k));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> num >> strike >> ball;

        for (auto it = s.begin(); it != s.end();) {
            int strike_num = 0, ball_num = 0;

            string temp = *it;

            // strkie 횟수 검사
            for (int j = 0; j < 3; j++) {
                if (num[j] == temp[j]) strike_num++;
            }
            // ball 횟수 검사
            if (num[0] == temp[1]) ball_num++;
            if (num[0] == temp[2]) ball_num++;
            if (num[1] == temp[0]) ball_num++;
            if (num[1] == temp[2]) ball_num++;
            if (num[2] == temp[0]) ball_num++;
            if (num[2] == temp[1]) ball_num++;

            if (strike_num == strike && ball_num == ball) {
                ++it;
            } else it = s.erase(it);
        }
    }

    cout << s.size();


    return 0;
}
