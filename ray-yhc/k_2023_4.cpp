#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<pair<int, int>> findPairs(int s, unordered_set<int> &deck) {
    vector<pair<int, int>> pairs;
    for (auto &i: deck) {
        for (auto &j: deck) {
            if (i >= j) continue;
            if (i + j == s) {
                pairs.push_back({i, j});
            }
        }
    }
    return pairs;
}

int dfs(vector<int> &cards, int i, int coin, unordered_set<int> deck, int round) {
    if (coin < 0) return round - 1;
    if (i >= cards.size()) return round;
    int maxRound = round;
    vector<pair<int, int>> pairs;

    if (coin >= 2) {
        // 둘 다 뽑음
        deck.insert(cards[i]);
        deck.insert(cards[i + 1]);
        pairs = findPairs(cards.size() + 1, deck);

        if (pairs.empty()) return maxRound;
        if (!pairs.empty()) {
            auto &p = pairs[0];
            deck.erase(p.first);
            deck.erase(p.second);
            maxRound = max(maxRound, dfs(cards, i + 2, coin - 2, deck, round + 1));
            deck.insert(p.first);
            deck.insert(p.second);

        }
        deck.erase(cards[i]);
        deck.erase(cards[i + 1]);
    }

    if (coin >= 1) {
        // 첫째 카드 뽑음
        deck.insert(cards[i]);
        pairs = findPairs(cards.size() + 1, deck);
        if (!pairs.empty()) {
            auto &p = pairs[0];
            deck.erase(p.first);
            deck.erase(p.second);
            maxRound = max(maxRound, dfs(cards, i + 2, coin - 1, deck, round + 1));
            deck.insert(p.first);
            deck.insert(p.second);

        }

        // 둘째 카드 뽑음
        deck.erase(cards[i]);
        deck.insert(cards[i + 1]);
        pairs = findPairs(cards.size() + 1, deck);
        if (!pairs.empty()) {
            auto &p = pairs[0];
            deck.erase(p.first);
            deck.erase(p.second);
            maxRound = max(maxRound, dfs(cards, i + 2, coin - 1, deck, round + 1));
            deck.insert(p.first);
            deck.insert(p.second);

        }
        deck.erase(cards[i + 1]);
    }

    // 아무카드도 뽑지 않음
    pairs = findPairs(cards.size() + 1, deck);
    if (!pairs.empty()) {
        auto &p = pairs[0];
        deck.erase(p.first);
        deck.erase(p.second);
        maxRound = max(maxRound, dfs(cards, i + 2, coin, deck, round + 1));
        deck.insert(p.first);
        deck.insert(p.second);

    }

    return maxRound;
}

int solution(int coin, vector<int> cards) {
    int i = 0;
    unordered_set<int> deck;
    for (; i < cards.size() / 3; ++i) {
        deck.insert(cards[i]);
    }

    return dfs(cards, i, coin, deck, 1);
}


int main() {

    cout << solution(4, {3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4}) << endl;
    cout << solution(3, {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12}) << endl;
    cout << solution(2, {5, 8, 1, 2, 9, 4, 12, 11, 3, 10, 6, 7}) << endl;
    cout << solution(10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}) << endl;

    return 0;
}
