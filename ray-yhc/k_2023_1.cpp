#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> split(string str, char del) {
    vector<string> result;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, del))
        result.push_back(temp);
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> um;
    vector<int> giftPoint(friends.size(), 0);
    vector<vector<int>> giftMap(friends.size(), vector<int>(friends.size(), 0));
    for (int i = 0; i < friends.size(); ++i)
        um[friends[i]] = i;

    for (string gift: gifts) {
        vector<string> g = split(gift, ' ');
        giftPoint[um[g[0]]]++;
        giftPoint[um[g[1]]]--;
        giftMap[um[g[0]]][um[g[1]]]++;
    }

    vector<int> result(friends.size(), 0);
    for (int i = 0; i < friends.size(); ++i) {
        for (int j = i+1; j < friends.size(); ++j) {
            if (giftMap[i][j] == giftMap[j][i]){
                if (giftPoint[i] == giftPoint[j]) continue;
                int index = (giftPoint[i] > giftPoint[j]) ? i : j;
                result[index]++;
                continue;
            }
            int index = (giftMap[i][j] > giftMap[j][i]) ? i : j;
            if (index == 4)
                cout<<"hi"<<endl;
            result[index]++;
        }
    }

    sort(result.begin(), result.end(), greater<>());
    return result[0];
}


int main() {

    cout << solution({"muzi", "ryan", "frodo", "neo"},
                     {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"});
    cout << endl;

    cout << solution({"joy", "brad", "alessandro", "conan", "david"},
                     {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"});
    cout << endl;

    cout << solution({"a", "b", "c"}, {"a b", "b a", "c a", "a c", "a c", "c a"});
    cout << endl;

    return 0;
}
