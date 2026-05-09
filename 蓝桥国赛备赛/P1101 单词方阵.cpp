#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
char g[N][N];          // 原始字母矩阵
bool vis[N][N];        // 标记是否属于单词
string word = "yizhong";
// 8 个方向：上下左右 + 4 个斜方向
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
// 判断坐标是否在矩阵内
bool inRange(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	//枚举每一个起点
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
			// 单词首字母必须是 y
            if (g[i][j] != 'y') continue;
            // 枚举 8 个方向
            for(int d=0;d<8;d++){
            	bool ok=true;
            	//检查该方向是否能匹配
            	for(int k=0;k<7;k++){
            		int x = i + dx[d] * k;
                    int y = j + dy[d] * k;
                    if (!inRange(x, y) || g[x][y] != word[k]) {
                        ok = false;
                        break;
                    }
				}
				// 如果匹配成功，标记这 7 个位置
                if (ok) {
                    for (int k = 0; k < 7; k++) {
                        int x = i + dx[d] * k;
                        int y = j + dy[d] * k;
                        vis[x][y] = true;
                    }
                }
			}
		}
	}
	// 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j]) cout << g[i][j];
            else cout << '*';
        }
        cout << '\n';
    }
	return 0;
}