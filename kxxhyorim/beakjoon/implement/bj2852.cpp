#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int getSecDiff(int min1, int sec1, int min2, int sec2) {
    return (min2 - min1) * 60 + (sec2 - sec1);
}

string convertTime(int sec) {
    string rtn = "";
    string m = to_string(sec / 60);
    string s = to_string(sec % 60);
    if (m.length() == 1) m = "0" + m;
    if (s.length() == 1) s = "0" + s;
    rtn.append(m).append(":").append(s);
    return rtn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, score1 = 0, score2 = 0;
    int winningTime1 = 0, winningTime2 = 0;
    string time;
    cin >> n;
    int min1 = 0;
    int sec1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> t >> time;
        int min2 = stoi(time.substr(0, 2));
        int sec2 = stoi(time.substr(3, 2));
        int diff = getSecDiff(min1, sec1, min2, sec2);

        if (score1 > score2) { // 1팀이 이기고 있었으면
            winningTime1 += diff;
        }
        if (score2 > score1) {
            winningTime2 += diff;
        }

        min1 = min2;
        sec1 = sec2;
        if (t == 1) score1++;
        else score2++;
    }

    int min2 = 48, sec2 = 0;
    int diff = getSecDiff(min1, sec1, min2, sec2);

    if (score1 > score2) { // 1팀이 이기고 있었으면
        winningTime1 += diff;
    }
    if (score2 > score1) {
        winningTime2 += diff;
    }

    cout << convertTime(winningTime1) << " " << convertTime(winningTime2);


    return 0;
}
