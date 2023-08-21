#include<iostream>
#include<queue>
#include<set>

using namespace std;

set<string> s;
set<string> alphabet;

bool isContain(string find) {
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it == find) {
            return true;
        }
    }
    return false;
}

int getIdxByAlpha(string s) {
    char temp = s[0];
    return temp - 'A';
}

int getIdxByAlpha(char c) {
    return c - 'A';
}


int main(int argc, char **argv) {
    string message, key;
    cin >> message >> key;

    queue<string> q;

    // 배열 만들기

    for (int i = 0; i < key.length(); i++) {
        string temp;
        char ch = (char) key[i];
        temp.push_back(ch);
        if (!isContain(temp)) {
            q.emplace(temp);
            s.emplace(temp);
        }
    }


    int remain = 25 - q.size();
    for (int i = 'A'; i <= 'Z' && remain > 0; i++) {
        string temp;
        char ch = i;
        if (ch == 'J') continue;
        temp.push_back(ch);
        if (!isContain(temp)) {
            q.emplace(temp);
            remain--;
        }
    }


    string cipher[5][5];
    vector<pair<int, int>> pos(26); // pos[0] = {0, 2}; // A 의 좌표는 0,2

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cipher[y][x] = q.front();
            char ch = q.front()[0];
            int idx = ch - 'A';
            pos[idx] = {x, y};
            q.pop();
        }
    }

    // message 분석 및 변형

    while (true) {
        int pair_num = message.length() / 2;

        bool isMessageChanged = false;
        for (int i = 0; i < pair_num; i++) {
            char first = message[i * 2];
            char second = message[i * 2 + 1];

            if (first == second) {
                string before = message.substr(0, i * 2 + 1);
                string end = message.substr(i * 2 + 1);
                string add;
                // cout << before << " " << end << endl;
                if (first == 'X') {
                    add = "Q";
                } else {
                    add = "X";
                }
                message = before + add + end;
                isMessageChanged = true;
                break;
            }
        }
        if (isMessageChanged) continue;
        else break;
    }

    if (message.length() % 2 == 1) message += "X";

    // 암호화
    // 글자 두개씩 가져옴
    int pair_num = message.length() / 2;

    for (int i = 0; i < pair_num; i++) {
        char first = message[i * 2];
        char second = message[i * 2 + 1];

        int idx1 = getIdxByAlpha(first);
        int x1 = pos[idx1].first;
        int y1 = pos[idx1].second;

        int idx2 = getIdxByAlpha(second);
        int x2 = pos[idx2].first;
        int y2 = pos[idx2].second;

        if (y1 == y2) {
            cout << cipher[y1][(x1 + 1) % 5] << cipher[y2][(x2 + 1) % 5];
        } else if (x1 == x2) {
            cout << cipher[(y1 + 1) % 5][x1] << cipher[(y2 + 1) % 5][x2];
        } else {
            cout << cipher[y1][x2] << cipher[y2][x1];
        }
    }
    return 0;
}