#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> k(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> k[i];
    }

    vector<int> dist(N + 1, -1); // dist[i] 表示到第 i 层的最少按键次数
    //用队列bfs 保证先到达的楼层，先拿出来扩展
    queue<int> q;

    dist[A] = 0;
    q.push(A);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        // 尝试向上走
        int up = x + k[x];
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