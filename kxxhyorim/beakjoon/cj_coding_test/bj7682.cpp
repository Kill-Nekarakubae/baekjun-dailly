#include <iostream>
#include <set>

using namespace std;


char board[3][3];
int xN, oN, dotN;


void invalid() {
    cout << "invalid\n";
}

void valid() {
    cout << "valid\n";
}

bool check(char win) {
    set<pair<int, int>> xSet; // y, x 순서!!!!!!!!!!!!!
    set<pair<int, int>> oSet;

    // 가로 빙고
    for (int y = 0; y < 3; y++) {
        if (board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
            if (board[y][0] == 'X') {
                xSet.emplace(y, 0);
                xSet.emplace(y, 1);
                xSet.emplace(y, 2);
            } else if (board[y][0] == 'O') {
                oSet.emplace(y, 0);
                oSet.emplace(y, 1);
                oSet.emplace(y, 2);
            }
        }
    }

    // 세로 빙고
    for (int x = 0; x < 3; x++) {
        if (board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
            if (board[0][x] == 'X') {
                xSet.emplace(0, x);
                xSet.emplace(1, x);
                xSet.emplace(2, x);
            } else if (board[0][x] == 'O') {
                oSet.emplace(0, x);
                oSet.emplace(1, x);
                oSet.emplace(2, x);
            }
        }
    }
    // \ 방향 대각선 빙고
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            xSet.emplace(0, 0);
            xSet.emplace(1, 1);
            xSet.emplace(2, 2);
        } else if (board[0][0] == 'O') {
            oSet.emplace(0, 0);
            oSet.emplace(1, 1);
            oSet.emplace(2, 2);
        }
    }

    // / 방향 대각선 빙고
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            xSet.emplace(0, 2);
            xSet.emplace(1, 1);
            xSet.emplace(2, 0);
        } else if (board[0][2] == 'O') {
            oSet.emplace(0, 2);
            oSet.emplace(1, 1);
            oSet.emplace(2, 0);
        }
    }

    if (dotN == 0) { // 9칸 다 찼을 떄
        if (oSet.size() == 0 && xSet.size() == 0) {
            return true;
        }
    } else {
        if (oSet.size() == 0 && xSet.size() == 0) {
            return false;
        }
    }


    if (win == 'X') {
        if (oSet.size() != 0) {
            return false;
        }
        if (xSet.size() == 3 || xSet.size() == 5) {
            return true;
        } else {
            return false;
        }
    }

    if (win == 'O') {
        if (xSet.size() != 0) {
            return false;
        }
        if (oSet.size() == 3 || oSet.size() == 5) {
            return true;
        } else {
            return false;
        }
    }
    cout << "여기까지 나오면 안됨 check함수 내부 로직 에러\n";
    return false;
}

/** 이따 call by reference 확인해보기 (targetSet) */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string str;
        cin >> str;
        if (str == "end") break;

        int idx = 0;
        xN = oN = dotN = 0;

        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                board[y][x] = str[idx++];
                if (board[y][x] == 'X') xN++;
                if (board[y][x] == 'O') oN++;
                if (board[y][x] == '.') dotN++;
            }
        }

        if (dotN >= 5) {
            invalid();
            continue;
        }

        // 다 채워져있을 떄
        if (dotN == 0) {
            if (xN == 5 && oN == 4) { // 개수 는 맞음
                bool result = check('X'); // x가 이겨야함
                if (result) {
                    valid();
                    continue;
                } else {
                    invalid();
                    continue;
                }
            } else {
                invalid();
            }
        } else { // 다 안찼을 떄
            int round = 9 - dotN;
            if (round % 2 == 0) { // 짝수회 진행됐으면
                if (xN == oN) { // 개수가 맞아야하고
                    bool result = check('O'); // x가 이겨야함
                    if (result) {
                        valid();
                        continue;
                    } else {
                        invalid();
                        continue;
                    }
                    // O의 빙고 있어야함, x의 빙고는 없어야함
                    // O 의 빙고가 붙어있으면 괜찮, 근데 각각 두개 있는건 안됨
                } else {
                    invalid();
                    continue;
                }
            } else { // 홀수회 진행된거면
                if (xN == (oN + 1)) {
                    bool result = check('X'); // x가 이겨야함
                    if (result) {
                        valid();
                        continue;
                    } else {
                        invalid();
                        continue;
                    }
                    // x의 빙고 / 2개 이상일 경우 붙어있는건 괜츈, 따로 있는건 안괜츈
                    // o 빙고는 있으면 안됨
                } else {
                    invalid();
                    continue;
                }
            }
        }


    }
    return 0;
}

// XXX
// OO.
// XXX
// 최종상태 아님 왜냐면 x가 두줄이나 있음 && OX 개수 안맞음

// XOX
// OXO
// XOX
// 정가운데 x 를 마지막에 둔거면 가능

// OXO
// XOX
// OXO
// 다차있는데 O가 더 많다는데서 불가능한 판

// XXO
// OOX
// XOX
// 누구의 승리도 아니지만 다 찼기때문에 최종상태

// XO.
// OX.
// ..X
// 최종상태 ㅇㅇ x가 한줄 있음

// .XX
// X.X
// OOO
// 최종상태 아님 / 왜냐면 x가 하나를 더 놓기 전에 게임이 끝났어야 함

// X.O
// O..
// X..
// 최종상태 아님, 누구의 승리도 아니며, 다 차지도 않았음, 둘다 짝수 개수

// OOX
// XXO
// OXO
// 다 찼는데 O의 개수가 더 많음