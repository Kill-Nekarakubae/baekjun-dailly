#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

vector<int> fitDigits {1, 3, 7, 15, 31, 63};

void printBit(long long num) {
    cout<< num<<" - "<< bitset<51> (num) <<endl;
}


int getLargestDigit(long long num) {
    int largestDigit = -1;
    for (long long i=0; i<62; i++) {
        if (num & ((long long) 1<<i)) largestDigit = i+1;
    }
    return largestDigit;
}

int getFitDigit(long long num) {
    int largestDigit = getLargestDigit(num);
    if (largestDigit == -1) return -1;

    // cout<< largestDigit<<endl;

    for (int i=0; i<fitDigits.size(); i++) {
        if (largestDigit <= fitDigits[i]) return fitDigits[i];
    }
    return -1;
}

int dfs(long long num, int begin, int end) {
    // cout<<begin<<' '<<end<<endl;
    // if (end - begin < 3) {
    // }
    if (end - begin == 1) {
        bool p = num & (1LL<<(begin));
        return p? 1 : 0;
    }
    if (end - begin == 3) {
        bool l = num & (1LL<<begin);
        bool p = num & (1LL<<(begin+1));
        bool r = num & (1LL<<(begin+2));

        if (!p && (l||r)) return -1;
        return p? 1 : 0;
    }

    int i = (begin + end) >> 1;

    bool p = num & (1LL<<i);
    int l = dfs(num, begin, i);
    if (l == -1) return -1;
    int r = dfs(num, i+1, end);
    if (r== -1) return -1;

    if (!p && (l||r) ) return -1;
    return p? 1 : 0;
}

bool getResult (long long num) {
    // printBit(num);

    int fitDigit = getFitDigit(num);
    if (fitDigit == -1) return false;

    // cout<< fitDigit<<endl;
    int result = dfs(num,0,fitDigit);

    return (result > 0);
}

vector<int> solution(vector<long long> numbers) {

    vector<int> answer;
    for (auto n : numbers) {
        answer.push_back(getResult(n));
    }
    return answer;
}

// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 128, 129, 16512, 2147516555]
// [0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1]