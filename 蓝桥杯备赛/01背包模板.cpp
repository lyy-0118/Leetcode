#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, V;
int v[N], w[N];
int dp[N][N];
int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    //问题1：
    //dp[i][j]表示从i个物品中挑选，背包体积不超过j的最大价值
    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i])   不选i物品/选择i物品（前提是j-v[i]>=0）
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][V] << endl;

    //问题2：
    //dp[i][j]表示从i个物品中挑选，背包体积正好等于j的最大价值
    //若dp[i][j]这种情况不存在，规定dp[i][j]=-1
    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i])   不选i物品/选择i物品（前提是dp[i-1][j-v[i]]不等于-1,因为从i个物品选，可能出现背包体积不正好等于j的情况，此时不能直接+w[i]）

    //边界条件赋初值
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= V; j++) {
        dp[0][j] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]&&dp[i-1][j-v[i]]!=-1) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << (dp[n][V]==-1?0:dp[n][V]) << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")