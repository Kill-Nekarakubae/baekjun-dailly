#include <iostream>
#include <vector>

using namespace std;

int cnt[4]; // LOVE 각각 count
vector<int> teamCnt(4);
vector<string> teamList;
int percent[50];

void checkName(string s) {
    for (char i: s) {
        if (i == 'L') cnt[0]++;
        if (i == 'O') cnt[1]++;
        if (i == 'V') cnt[2]++;
        if (i == 'E') cnt[3]++;
    }
}

void checkTeam(string s) {
    teamCnt.clear();
    teamCnt.resize(4);
    for (char i: s) {
        if (i == 'L') teamCnt[0]++;
        if (i == 'O') teamCnt[1]++;
        if (i == 'V') teamCnt[2]++;
        if (i == 'E') teamCnt[3]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    cin >> name;
    checkName(name);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string teamName;
        cin >> teamName;
        teamList.emplace_back(teamName);
        checkTeam(teamName);
        int mul = 1;
        for (int s = 0; s <= 2 && mul != 0; s++) {
            for (int e = s + 1; e <= 3 && mul != 0; e++) {
                mul *= cnt[s] + teamCnt[s] + cnt[e] + teamCnt[e];
            }
        }
        mul %= 100;
        percent[i] = mul;
//        cout << percent[i] << endl;
    }

    int maxPercent = -1;
    string teamName;

    for (int i = 0; i < n; i++) {
        if (maxPercent == -1 || percent[i] > maxPercent) {
            teamName = teamList[i];
            maxPercent = percent[i];
        } else if (percent[i] == maxPercent) {
            teamName = (teamList[i] > teamName) ? teamName : teamList[i];
            maxPercent = percent[i];
        }
    }
    cout << teamName << " ";

    return 0;
}
