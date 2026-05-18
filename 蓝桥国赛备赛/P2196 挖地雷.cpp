#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int n;
int num[N];  // 每个地窖中的地雷数量
int g[N][N]; // 记录地雷联通关系 g[i][j] = 1 表示 i 可以到 j
int dp[N];   // dp[i] 表示从 i 出发最多能挖到多少地雷
int nxt[N];  // 记录最优路径

int main(){
	cin >> n;
    // 读入每个地窖的地雷数
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    // 读入上三角形式的连接关系
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    // 动态规划，从后往前计算
    for(int i=n;i>=1;i--){
    	dp[i]=num[i]; // 初始情况：只挖当前地窖
    	nxt[i]=0;
    	// 枚举 i 能到达的所有后续地窖
    	for(int j=i+1;j<=n;j++){
    		if (g[i][j]){  //i j之间是联通的
    			if(num[i]+dp[j]>dp[i]){ // 如果从 i 走到 j 可以获得更多地雷，就更新
    				dp[i]=num[i]+dp[j];
    				nxt[i]=j;
				}
			}
		}
	}
	 // 找到最优起点
	 // 因为题目说明可以从任意一点出发，所以要找最优起点
    int start = 1;
    for (int i = 2; i <= n; i++) {
        if (dp[i] > dp[start]) {
            start = i;
        }
    }
    // 输出最优路径
    int cur = start;
    while (cur != 0) {
        cout << cur;
        cur = nxt[cur];
        if (cur != 0) cout << " ";
    }
    cout << '\n';
    // 输出最多能挖到的地雷数
    cout << dp[start] << '\n';
	return 0;
}