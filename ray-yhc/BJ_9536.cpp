//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    int T;
    string dummy;
    cin >> T;
    getline(cin, dummy);
    for (int t = 0; t < T; ++t) {
        string str;
        getline(cin, str);
        vector<string> record = split(str, ' ');

        while (true) {
            string a, goes, c;
            cin >> a >> goes >> c;
            if (goes == "does") {
                getline(cin, str);
                break;
            }

            record.erase(remove(record.begin(), record.end(), c), record.end());
        }

        for (auto s: record) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}