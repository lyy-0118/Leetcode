//判断一个 0 是否在圈内，可以反过来想
//问题转化为：
//从边界上的 0 出发，把所有能连通到边界的 0 标记为“圈外”，最后剩下的 0 就是圈内区域。

#include <bits/stdc++.h>
using namespace std;
int n;
int a[35][35];
// 四个方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 判断是否在矩阵范围内
bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
// 从边界的 0 开始 BFS，标记圈外区域
void bfs(int sx,int sy){
	queue<pair<int, int>> q;
	q.push({sx, sy});
	a[sx][sy] = -1; // -1 表示圈外的 0
	while(!q.empty()){
		pair<int, int> cur = q.front();
		int x = cur.first;
		int y = cur.second;
		q.pop();
		//找(x,y)的四个方向
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(inRange(nx,ny)&&a[nx][ny]==0){
				a[nx][ny]=-1;
				q.push({nx, ny});
			}
		}
	}
}
int main(){
	cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
	}
	// 从第一行和最后一行的 0 出发
    for (int j = 0; j < n; j++) {
        if (a[0][j] == 0) bfs(0, j);
        if (a[n - 1][j] == 0) bfs(n - 1, j);
    }
    // 从第一列和最后一列的 0 出发
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0) bfs(i, 0);
        if (a[i][n - 1] == 0) bfs(i, n - 1);
    }
    // 处理最终结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                a[i][j] = 2; // 没有连到边界，说明在圈内
            } else if (a[i][j] == -1) {
                a[i][j] = 0; // 圈外区域还原
            }
        }
    }
    // 输出矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << '\n';
    }
    return 0;
}