//
// Created by 조윤호 on 2023/07/12.
//
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<bool> deq;
    string s;
    cin>>s;
    for (char c: s) {
        deq.push_back(c == '0');
    }
    int count = -1;
    while(!deq.empty()) {
        bool sign = deq.front();
        while (!deq.empty() && deq.front() == sign)
            deq.pop_front();
        while (!deq.empty() && deq.back() == sign)
            deq.pop_back();
        count++;
    }
    cout<<count;
    return 0;
}
