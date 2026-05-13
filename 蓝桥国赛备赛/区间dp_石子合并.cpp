#include <bits/stdc++.h>
using namespace std;
const int N = 305;
typedef long long ll;
const ll INF = 1e18;
ll a[N];
ll pre[N];
ll dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    // 初始化
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    // len 表示当前区间长度
    //设 dp[i][j] 表示将第 i 堆到第 j 堆合并成一堆的最小代价。
    for (int len = 2; len <= n; len++){
        //枚举左、右端点
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=INF;
            //枚举mid，左右两边先各自最优，再加上最后合并整段的代价。
            for(int mid=l;mid<r;mid++){
                ll sum=pre[r]-pre[l-1]; //本次合并代价
                dp[l][r]=min(dp[l][r],dp[l][mid]+dp[mid+1][r]+sum);
            }
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}