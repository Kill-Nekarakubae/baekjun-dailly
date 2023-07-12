//
// Created by 김효림 on 2023/07/12.
//
#include <iostream>

using namespace std;

string flipString(string original){
    int l = original.length();
    string temp;

    for (int i = l-1 ; i >= 0; i--){
        temp += original[i];
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int max = 0;
    for (int i = 1 ; i <= k; i++){
        int mul_result = n * i;
        string mul_result_original = to_string(mul_result);
        string mul_result_flip = flipString(mul_result_original);
        int mul_flip_result = stoi(mul_result_flip);

        if (mul_flip_result > max){
            max = mul_flip_result;
        }
    }
    cout << max;


    return 0;
}
