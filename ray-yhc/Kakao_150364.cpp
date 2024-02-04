#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    int roadIndex;
    Node* parent;

    Node(int val) : val(val), roadIndex(0) {}

    void switchRoad() {
        if (children.size() <= 1) return;
        if (roadIndex == children.size() - 1) {
            roadIndex = 0;
        } else {
            roadIndex++;
        }
    }

    Node* getNextNode() {
        if (children.size() == 0) return nullptr;
        return children[roadIndex];
    }
};

Node* root;
vector<Node*> nodes;
int countSteps = 0;

void init (vector<vector<int>> edges) {
    nodes = vector<Node*> (edges.size() + 2);
    for (int i = 1; i < nodes.size(); i++) {
        nodes[i] = new Node(i);
    }
    root = nodes[1];

    for (auto e : edges) {
        nodes[e[0]]->children.push_back(nodes[e[1]]);
        nodes[e[1]]->parent = nodes[e[0]];
    }

    for (int i = 1; i < nodes.size(); i++) {
        sort(nodes[i]->children.begin(), nodes[i]->children.end(), [](Node* a, Node* b) {
            return a->val < b->val;
        });
    }
}


vector<int> simulation(int n) {
    vector<int> sequence;
    Node* node;
    Node* prevNode;

    for (int i = 1; i <= n; i++) {
        node = root;
        while (node->getNextNode() != nullptr) {
            prevNode = node;
            node = node->getNextNode();
            prevNode->switchRoad();
        }
        sequence.push_back(node->val);
    }
    return sequence;
}


vector<int> bfs_v2(vector<int> sequence, const vector<int> &target) {
    vector<int> counts (target.size(), 0);
    for (int seq = 0; seq < sequence.size(); ++seq) {
        counts[sequence[seq] - 1]++;

        bool isCorrect = true;
        for (int i = 0; i < target.size(); ++i) {
            if (target[i] < counts[i]) {
                return {-1};
            }
            if (target[i] > counts[i] * 3) isCorrect = false;
        }
        if (!isCorrect) continue;

        vector<deque<int>> numbers;
        for (int i = 0; i < target.size(); ++i) {
            int c = counts[i];
            int t = target[i];
            numbers.push_back(deque<int> ());

            t -= c;
            while (t >= 2) {
                numbers[i].push_front(3);
                t -= 2;
            }
            while (t-- > 0) {
                numbers[i].push_front(2);
            }
            while (numbers[i].size() < c) {
                numbers[i].push_front(1);
            }
        }

        vector<int> answer;
        for (int i = 0; i <= seq; ++i) {
            int n = sequence[i];
            answer.push_back(numbers[n - 1].front());
            numbers[n - 1].pop_front();
        }
        return answer;
    }
    return {-1};
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    init(edges);
    vector<int> sequence = simulation(1000);
    vector<int> answer = bfs_v2(sequence, target);
    return answer;
}



void reset() {
    for (auto n : nodes) {
        if (n == nullptr) continue;
        n->roadIndex = 0;
    }
}

int main() {
    vector<int> v;

    reset();
    v = solution(
            {{2, 4}, {1, 2}, {6, 8}, {1, 3}, {5, 7}, {2, 5}, {3, 6}, {6, 10}, {6, 9}},
            {0, 0, 0, 3, 0, 0, 5, 1, 2, 3}
    );
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl<<countSteps<<endl; // 437 -> 368
    countSteps = 0;

    reset();
    v = solution(
            {{1, 2}, {1, 3}},
            {0, 7, 3}
    );
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl<<countSteps<<endl; // 310 -> 228
    countSteps = 0;


    reset();
    v = solution(
            {{1, 3}, {1, 2}},
            {0, 7, 1}
    );
    for (auto s : v) {
        cout<<s<<", ";
    }
    cout<<endl<<countSteps<<endl;
    countSteps = 0;

    return 0;
}
