#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

queue<int> A, B, C, D;
int N;
int result[200001];

void printQ(int t) {
    cout << t << "//" << A.size() << "//" << B.size() << "//" << C.size() << "//" << D.size() << endl;
}


bool doUntil(int now, int to) {
    bool a = A.empty(), b = B.empty(), c = C.empty(), d = D.empty();
    if (a && b && c && d) return true;
    if (!a && !b && !c && !d) return false;

    while (now < to) {
        // cout<<to<<endl;
        // printQ(now);
        bool a = A.empty(), b = B.empty(), c = C.empty(), d = D.empty();
        if (a && b && c && d) return true;

        //todo
        if (!a && d) {
            int i = A.front();
            A.pop();
            result[i] = now;
        }
        if (!b && a) {
            int i = B.front();
            B.pop();
            result[i] = now;
        }
        if (!c && b) {
            int i = C.front();
            C.pop();
            result[i] = now;
        }
        if (!d && c) {
            int i = D.front();
            D.pop();
            result[i] = now;
        }

        now++;
    }
}


int main(int argc, char **argv) {
    cin >> N;
    fill(result, result + N, -1);
    int nextTime = 0;
    for (int i = 0; i < N; i++) {
        int t;
        char c;
        cin >> t >> c;

        // cout<<nextTime<<endl;
        if (nextTime != t) {
            if (!doUntil(nextTime, t)) break;
            nextTime = t;
        }
        switch (c) {
            case 'A':
                A.push(i);
                break;
            case 'B':
                B.push(i);
                break;
            case 'C':
                C.push(i);
                break;
            case 'D':
                D.push(i);
                break;
        }
    }
    doUntil(nextTime, 1000000001);

    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }


    return 0;
}