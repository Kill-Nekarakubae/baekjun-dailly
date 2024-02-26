//
// Created by 김효림 on 2/26/24.
//
#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

int len;

string toBinary(int dec) {
    string s = "";
    while (dec >= 0) {
        s += to_string(dec % 2);
        dec /= 2;
        if (dec == 0) break;
    }
//    int fill = len - s.length();
//    for (int i = 0; i < fill; i++) { s += "0"; }
    string filled = string(len - s.length(), '0') + s;

    reverse(s.begin(), s.end());

    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    len = n;
    for (int i = 0; i < n; i++) {
        string s1 = toBinary(arr1[i]);
        string s2 = toBinary(arr2[i]);

        string temp;
        for (int j = 0; j < n; j++) {
            if (s1[j] == '0' && s2[j] == '0') temp += " ";
            else temp += "#";
        }
        answer.emplace_back(temp);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v1;//= {9, 20, 28, 18, 11};
    v1.emplace_back(9);
    v1.emplace_back(20);
    v1.emplace_back(28);
    v1.emplace_back(18);
    v1.emplace_back(11);
    vector<int> v2;// = {30, 1, 21, 17, 28};
    v2.emplace_back(30);
    v2.emplace_back(1);
    v2.emplace_back(21);
    v2.emplace_back(17);
    v2.emplace_back(28);

    vector<int> v3; //= {9, 20, 28, 18, 11};
    v3.emplace_back(46);
    v3.emplace_back(33);
    v3.emplace_back(33);
    v3.emplace_back(33);
    v3.emplace_back(22);
    v3.emplace_back(31);
    v3.emplace_back(50);
    vector<int> v4;// = {30, 1, 21, 17, 28};
    v4.emplace_back(27);
    v4.emplace_back(56);
    v4.emplace_back(19);
    v4.emplace_back(14);
    v4.emplace_back(14);
    v4.emplace_back(10);

    solution(5, v1, v2);
//    solution(6, v3, v4);

    return 0;
}
