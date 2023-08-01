#include<iostream>
#include<cmath>
#include<queue>


using namespace std;

#define parent (i>>1)
#define left (i<<1)
#define right ((i<<1) | 1)

int main(int argc, char** argv)
{
    int tree[2049] = {0};
    queue<int> que[1025];
    queue<int> qLeft[1024];
    queue<int> qRight[1024];
    int H, K, R;
    scanf("%d %d %d", &H,&K,&R);

    for (int i=0; i< (1<<H); i++) {
        for (int k=0; k<K; k++) {
            int t;
            scanf("%d", &t);
            que[i].push(t);
        }
    }

    // for (int i=0; i< (1<<H); i++) {
    // 	while(!que[i].empty()) {
    // 		cout<<que[i].front()<<" ";
    // 		que[i].pop();
    // 	}
    // 	cout<<endl;
    // }


    long long totalWork = 0;
    int maxTreeNum = (1<<(H+1))-1;
    for (int r = 0; r<=R; r++){
        for (int i=0; i<=maxTreeNum; i++) {
            if (i==0) {
                totalWork += tree[1];
                tree[1] = 0;
                continue;
            }
            // if (tree[i] != 0) continue;

            if (left > maxTreeNum) { // 말단 사원
                if (!que[i-(1<<H)].empty()) {
                    tree[i] = que[i-(1<<H)].front();
                    que[i-(1<<H)].pop();
                }
            } else { // 중간 사원
                if (tree[left] != 0) {
                    qLeft[i].push(tree[left]);
                    tree[left] = 0;
                }
                if (tree[right] != 0) {
                    qRight[i].push(tree[right]);
                    tree[right] = 0;
                }

                if (r%2 == 0 && !qLeft[i].empty()) {
                    tree[i] = qLeft[i].front();
                    qLeft[i].pop();
                } else if (!qRight[i].empty()) {
                    tree[i] = qRight[i].front();
                    qRight[i].pop();
                }
            }
        }

//        for (int i=0; i<=maxTreeNum; i++) {
//            cout<<tree[i]<<" ";
//        }
//        cout<<endl;
    }

    cout<<totalWork;

    return 0;
}