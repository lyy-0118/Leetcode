#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = -4e18;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    /*
        dp[l][r][t]
        表示区间 [l, r] 内，恰好用了 t 个乘号时的最大值
    */
    vector<vector<vector<ll>>> dp(
        n + 1,
        vector<vector<ll>>(n + 1, vector<ll>(k + 1, NEG))
    );
    // 一个数字不用任何符号，所以乘号数量是 0
    for (int i = 1; i <= n; i++) {
        dp[i][i][0] = a[i];
    }
    // 枚举区间长度，从短到长
    for (int len = 2; len <= n; len++) {
    	// 枚举区间左端点
        for (int l = 1; l + len - 1 <= n; l++){
        	int r = l + len - 1;
            // 枚举断点，把 [l,r] 分成 [l,mid] 和 [mid+1,r]
            for (int mid = l; mid < r; mid++) {
            	int leftLen = mid - l + 1;
            	int rightLen = r - mid;
            	/*
                    左区间最多只能用 leftLen - 1 个乘号
                    右区间最多只能用 rightLen - 1 个乘号
                */
            	int maxLeft = min(k, leftLen - 1);
                int maxRight = min(k, rightLen - 1);
                // 枚举左边用了多少个乘号
                for (int x = 0; x <= maxLeft; x++){
                	if (dp[l][mid][x] == NEG) continue;
                	// 枚举右边用了多少个乘号
                	for (int y = 0; y <= maxRight; y++){
                		if (dp[mid + 1][r][y] == NEG) continue;
                		// 情况一：中间用加号连接 总乘号数量 = 左乘号 + 右乘号
                		int total = x + y;
                		if (total <= k) {
                            dp[l][r][total] = max(
                                dp[l][r][total],
                                dp[l][mid][x] + dp[mid + 1][r][y]
                            );
                        }
                        // 情况二：中间用乘号连接
                        // 总乘号数量 = 左乘号 + 右乘号 + 当前这个乘号
                        total = x + y + 1;
                        if (total <= k) {
                            dp[l][r][total] = max(
                                dp[l][r][total],
                                dp[l][mid][x] * dp[mid + 1][r][y]
                            );
                        }
					}
				}
			}
		}
    }
    cout << dp[1][n][k] << '\n';
    return 0;
}