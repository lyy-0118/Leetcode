#include <bits/stdc++.h>
using namespace std;
//无权图最短路问题 : 从一个点到另一个点，最少经过几条边。
//用BFS广度优先
int main() {
	int N, A, B;
    cin >> N >> A >> B;
    vector<int> k(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> k[i];
    }
    vector<int> dist(N + 1, -1); // dist[i] 表示到第 i 层的最少按键次数
    queue<int> q;
    dist[A]=0;
    q.push(A);
    while(!q.empty()){
    	int x=q.front();
    	q.pop();
    	int up=x+k[x]; //能移动多少层，不是固定的，而是由当前楼层上的数字决定的。
    	if (up >= 1 && up <= N && dist[up] == -1) {
            dist[up] = dist[x] + 1;
            q.push(up);
        }
        // 尝试向下走
        int down = x - k[x];
        if (down >= 1 && down <= N && dist[down] == -1) {
            dist[down] = dist[x] + 1;
            q.push(down);
        }
	}
	cout << dist[B] << endl;
	return 0;	
}