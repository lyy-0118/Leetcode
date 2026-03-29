#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

//设a为初始方阵，b为修改后的方阵
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    //1.遍历题目给的组数
    for (int tc = 1; tc <= T; tc++){
    	//2.输入当前n*n方阵
    	int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int ans = INF;//记录改变的次数
        // 3.枚举最终矩阵 b 的第一行状态
        // mask 的第 j 位表示 b[0][j] 是否为 1
        for (int mask = 0; mask < (1 << n); mask++){
        	vector<vector<int>> b(n, vector<int>(n, 0));
            bool ok = true;
            int changes = 0;
            // 构造第一行，并检查是否和原矩阵冲突
            for (int j = 0; j < n; j++) {
                b[0][j] = (mask >> j) & 1;
                // 原来是 1，不能变成 0
                if (a[0][j] == 1 && b[0][j] == 0) {
                    ok = false;
                    break;
                }
                // 统计 0 -> 1 的修改次数
                if (a[0][j] == 0 && b[0][j] == 1) {
                    changes++;
                }
            }
            if (!ok) continue;
            /*
                4.由前面的行，逐行推出后面的行
                推导公式：
                    b[i][j] = (b[i-2][j] + b[i-1][j-1] + b[i-1][j+1]) % 2
                这个公式的含义是：
                为了让位置 (i-1, j) 的“上下左右邻居和”为偶数，
                那么当前格 b[i][j] 的值只能这样取。
            */
            for (int i = 1; i < n && ok; i++) {
                for (int j = 0; j < n; j++) {
                    int up = (i - 2 >= 0 ? b[i - 2][j] : 0);
                    int left = (j - 1 >= 0 ? b[i - 1][j - 1] : 0);
                    int right = (j + 1 < n ? b[i - 1][j + 1] : 0);
                    // 为了让 (i-1, j) 的邻居和为偶数，
                    // 当前 b[i][j] 必须等于 up+left+right 的奇偶性
                    b[i][j] = (up + left + right) % 2;
                    // 原来是 1，不能推出成 0
                    if (a[i][j] == 1 && b[i][j] == 0) {
                        ok = false;
                        break;
                    }
                    // 统计 0 -> 1
                    if (a[i][j] == 0 && b[i][j] == 1) {
                        changes++;
                    }
                }
        	}
        	if (!ok) continue;
        	// 单独检查最后一行是否满足偶数条件
            for (int j = 0; j < n; j++) {
                int up = (n - 2 >= 0 ? b[n - 2][j] : 0);
                int left = (j - 1 >= 0 ? b[n - 1][j - 1] : 0);
                int right = (j + 1 < n ? b[n - 1][j + 1] : 0);
                if ((up + left + right) % 2 != 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = min(ans, changes);
		}
        if (ans == INF) ans = -1;
        cout << "Case " << tc << ": " << ans << "\n";
	}
    return 0;
}