#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// utils
int N = 50;
vector<vector<string>> table (N, vector<string>(N, ""));
vector<vector<pair<int,int>>> parent (N, vector<pair<int,int>>(N));

vector<string> split(string str, char del){
    vector<string> answer;
    string temp;
    stringstream ss(str);
    while(getline(ss,temp,del)){
        answer.push_back(temp);
    }
    return answer;
}

pair<int,int> find(int r, int c) {
    if (parent[r][c] == (pair<int,int>) {r,c}) return {r,c};
    pair<int,int> p = find(parent[r][c].first, parent[r][c].second);
    parent[r][c] = p;
    return p;
}

bool union_node(int r1, int c1, int r2, int c2) {
    pair<int,int> p1 = find(r1,c1);
    pair<int,int> p2 = find(r2,c2);
    if (p1 == p2) return false;
    parent[p2.first][p2.second] = p1;
    return true;
}

string getValue(int r, int c) {
    pair<int,int> p = find(r,c);
    return table[p.first][p.second];
}

// features

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            parent[i][j] = {i,j};
            table[i][j] = "";
        }
    }
}

void update(int r, int c, string value) {
    pair<int,int> p = find(r,c);
    table[p.first][p.second] = value;
}

void update(string value1, string value2) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == value1) {
                table[i][j] = value2;
            }
        }
    }
}


void merge (int r1, int c1, int r2, int c2) {
    if (find(r1,c1) == find(r2,c2)) return;
    if (getValue(r1,c1) != "" ) { // r1 c1이 부모!
        if (union_node(r1,c1,r2,c2))
            table[r2][c2] = "";
    } else if (getValue(r2,c2) != "") { // r2 c2가 부모!
        union_node(r2,c2,r1,c1);
    } else { // 둘다 부모가 아님!
        union_node(r1,c1,r2,c2);
    }
}

void unmerge(int r, int c) {
    pair<int,int> p = find(r,c);
    string value = getValue(r,c);
    vector<pair<int,int>> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            if (find(i,j) == p) {
                q.push_back({i,j});
            }
        }
    }

    for (auto p: q) {
        table[p.first][p.second] = "";
        parent[p.first][p.second] = {p.first,p.second};
    }
    if (value != "") table[r][c] = value;
}


vector<string> solution(vector<string> commands) {
    init();

    vector<string> answer;
    for (string c: commands) {
        vector<string> cmd = split(c, ' ');
        for (string t: cmd)
            cout << t << ' ';
        cout << endl;

        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                update(stoi(cmd[1]) - 1, stoi(cmd[2]) - 1, cmd[3]);
            } else {
                update(cmd[1], cmd[2]);
            }
        } else if (cmd[0] == "MERGE") {
            merge(stoi(cmd[1]) - 1, stoi(cmd[2]) - 1, stoi(cmd[3]) - 1, stoi(cmd[4]) - 1);
        } else if (cmd[0] == "UNMERGE") {
            unmerge(stoi(cmd[1]) - 1, stoi(cmd[2]) - 1);
        } else if (cmd[0] == "PRINT") {
            string s = getValue(stoi(cmd[1]) - 1, stoi(cmd[2]) - 1);
            answer.push_back((s.empty())? "EMPTY": s);
        }
    }

    return answer;
}

int main() {

    vector<string> v;

    v = solution({
                         "UPDATE 50 50 A",
                         "UPDATE 50 49 C",
                         "UPDATE A AA",
                         "UPDATE C CC",

                         "PRINT 50 50",
                         "PRINT 50 49"
                 });
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl;

    v = solution({
                         "MERGE 1 1 2 2 ",
                         "UNMERGE 1 1",
                         "UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"
                 });


    v = solution({"UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4", "PRINT 2 2"});
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl;

    v = solution({"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"});
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl;


    v = solution({"UPDATE 1 1 menu", "UPDATE 1 3 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"});
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl;


    v = solution({
                         "UPDATE 1 1 menu", "MERGE 1 1 1 2", "MERGE 1 1 1 3", "MERGE 1 1 1 4", "MERGE 1 2 1 3", "UPDATE 1 1 hansik", "PRINT 1 1", "PRINT 1 2", "PRINT 1 3", "PRINT 1 4"
                 });
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl;

    v = solution({
                         "UPDATE 50 50 A",
                         "UPDATE 1 2 B",
                         "UPDATE 50 49 C",
                         "UPDATE 2 2 D",
                         "UNMERGE 50 49",
                         "PRINT 50 49",
                         "MERGE 50 50 2 2",
                         "PRINT 50 50",
                         "PRINT 2 2",
                         "UNMERGE 2 2",
                         "PRINT 50 50",
                         "PRINT 2 2",

                         "UPDATE 50 50 A",
                         "UPDATE 2 2 D",
                         "MERGE 2 2 50 50",
                         "UPDATE 50 50 E",

                         "PRINT 50 50",
                         "PRINT 2 2"
                 });
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl;

    return 0;
}
