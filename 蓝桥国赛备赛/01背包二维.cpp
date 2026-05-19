#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;          // n 表示物品数量，m 表示背包容量
int w[N], v[N];    // w[i] 表示第 i 个物品的体积，v[i] 表示第 i 个物品的价值
int dp[N][N];      // dp[i][j] 表示前 i 个物品 容量为 j 的背包能获得的最大价值

//二维背包
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin >> w[i] >> v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			// 不选第 i 个物品
            dp[i][j] = dp[i - 1][j];
            // 如果容量足够，可以选择第 i 个物品
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}