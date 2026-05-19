#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;          // n 表示物品数量，m 表示背包容量
int w[N], v[N];    // w[i] 表示第 i 个物品的体积，v[i] 表示第 i 个物品的价值
int dp[N];         // dp[j] 表示容量为 j 的背包能获得的最大价值

int main() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    // 枚举每一个物品
    for(int i=1;i<=n;i++){
    	// 倒序枚举容量
    	for(int j=m;j>=w[i];j--){
    		dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout << dp[m] << endl;
    return 0;
}