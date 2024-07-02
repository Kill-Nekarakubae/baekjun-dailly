#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int calculateScore(int score, char bonus) {
    switch (bonus) {
        case 'S':
            return score;
        case 'D':
            return score * score;
        case 'T':
            return score * score * score;
        default:
            return -1;
    }
}

int applyOption(int score, char option) {
    switch (option) {
        case '*':
            return score * 2;
        case '#':
            return score * -1;
        default:
            return score;
    }
}

int solution(string dartResult) {
    int scores[3] = {0};
    int idx = 0;

    for (int i = 0; i < dartResult.length(); i++) {
        if (isdigit(dartResult[i])) {
            int score = dartResult[i] - '0';
            if (dartResult[i + 1] == '0') {
                score = 10;
                i++;
            }
            scores[idx] = calculateScore(score, dartResult[i + 1]);
            idx++;
        } else if (dartResult[i] == '*' || dartResult[i] == '#') {
            scores[idx - 1] = applyOption(scores[idx - 1], dartResult[i]);
            if (idx > 1 && dartResult[i] == '*') {
                scores[idx - 2] = applyOption(scores[idx - 2], dartResult[i]);
            }
        }
    }

    return scores[0] + scores[1] + scores[2];
}

int main() {
    string s;
    cin >> s;
    int result = solution(s);
    cout << result << endl;
    return 0;
}
