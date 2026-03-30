#include<bits/stdc++.h>
using namespace std;
//这题用到了二维动态规划 DP
//x是题目输入的数组 dp[i][j]以 (i,j) 这个点作为右下角，所能形成的最大全 1 正方形的边长
//dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
//ans记录最大边长
int x[105][105],dp[105][105];
int ans=0;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]==1){
				//第一行或第一列
				if(i==1||j==1){
					dp[i][j]=1;
				}else{
					// 状态转移：
                    // 取上、左、左上的最小值，再 +1
					dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
				}
				// 更新答案
                ans = max(ans, dp[i][j]);
			}else{
				dp[i][j]=0;
			}
		}
	}
	// 输出最大正方形边长
    cout << ans << endl;
	return 0;
}