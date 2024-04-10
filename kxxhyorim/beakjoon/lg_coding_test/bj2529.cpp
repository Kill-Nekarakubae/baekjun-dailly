#include <iostream>
#include <vector>
#include <climits>

#define ull unsigned long long

#include <set>

using namespace std;

int k, n;
bool isVisited[10];
char sign[10];
int arr[10];
string answer;

ull minInt = LONG_LONG_MAX;
ull maxInt = 0;
string minStr, maxStr;

void dfs(int depth) {

    if (depth == n) {
        vector<int> candidate;
        for (int i = 0; i < n; i++) {
            candidate.emplace_back(arr[i]);
        }

        bool isAnswer = true;
        for (int i = 0; i < n - 1; i++) {
            int n1 = candidate[i];
            int n2 = candidate[i + 1];
            char s = sign[i];
            if ((s == '<' && n1 > n2) || (s == '>' && n1 < n2)) {
                isAnswer = false;
                break;
            }
        }

        string temp = "";
        if (isAnswer) {
            for (int i = 0; i < n; i++) {
                temp += to_string(candidate[i]);
            }

            if (stoll(temp) < minInt) {
                minInt = stoll(temp);
                minStr = temp;
            }
            if (stoll(temp) > maxInt) {
                maxInt = stoll(temp);
                maxStr = temp;
            }

        }

        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            arr[depth] = i;
            dfs(depth + 1);
            isVisited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    n = k + 1;

    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }

    dfs(0);

    cout << maxStr << "\n" << minStr;


    return 0;
}
