#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>


using namespace std;

char table[5][5];
int indexRow[26], indexCol[26];


int main(int argc, char** argv)
{
    string key;
    string input;
    cin>>input;
    cin>>key;

    fill(indexRow, indexRow + 26, -1);

    int index = 0;
    // 하나씩 순서대로 인덱스 채우기
    for (char c : key){
        if (indexRow[c-'A'] == -1) {
            indexRow[c-'A'] = index/5;
            indexCol[c-'A'] = index%5;
            index++;
        }
    }

    for (int i=0; i<26; i++) {
        if (i != 'J' - 'A' && indexRow[i] == -1) {
            indexRow[i] = index/5;
            indexCol[i] = index%5;
            index++;
        }
        table[indexRow[i]][indexCol[i]] = i+'A';
    }
    assert (index == 25);


    // for (int i=0; i<26; i++) {
    // 	cout<<(char)(i+'A') << " ";
    // }
    // cout<<endl;
    // for (int i=0; i<26; i++) {
    // 	cout<< indexRow[i] << " ";
    // }
    // cout<<endl;
    // for (int i=0; i<26; i++) {
    // 	cout<< indexCol[i] << " ";
    // }
    // for(int i=0; i<5; i++) {
    // 	for(int j=0; j<5; j++) {
    // 		cout<<table[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    vector<char> result;
    for (int i=0; i<input.size(); ) {
        //todo : 마지막문자 처리
        int c1, c2 ;
        if (i == input.size() -1) {
            c1 = input[i] - 'A';
            c2 = 'X'-'A';

            i++;
        }else {
            c1 = input[i] - 'A';
            c2 = input[i+1] - 'A';

            if (c1 == c2) {
                c2 = (c1 == 'X'-'A')? 'Q'-'A' :'X' -'A';
                i++;
            } else i += 2;
        }


        // cout<<(char)(c1+'A')<<' '<<(char)(c2+'A')<<"  ";

        if (indexRow[c1] == indexRow[c2]){
            int col1 = (indexCol[c1]==4)? 0 :indexCol[c1]+1;
            int col2 = (indexCol[c2]==4)? 0 :indexCol[c2]+1;

            result.push_back(table[indexRow[c1]][col1]);
            result.push_back(table[indexRow[c2]][col2]);
        } else if (indexCol[c1] == indexCol[c2]){
            int row1 = (indexRow[c1]==4)? 0:indexRow[c1]+1;
            int row2 = (indexRow[c2]==4)? 0:indexRow[c2]+1;

            result.push_back(table[row1][indexCol[c1]]);
            result.push_back(table[row2][indexCol[c2]]);
        } else {
            int col1 = indexCol[c2];
            int col2 = indexCol[c1];

            result.push_back(table[indexRow[c1]][col1]);
            result.push_back(table[indexRow[c2]][col2]);
        }
    }
    // cout<<endl;

    for (auto c : result) {
        cout<<c;
    }



    return 0;
}