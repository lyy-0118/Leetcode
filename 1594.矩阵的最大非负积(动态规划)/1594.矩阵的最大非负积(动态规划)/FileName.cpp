#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 时间复杂度：O(m * n)
// 空间复杂度：O(m * n)
// 到每个格子时，同时记录“最大积”和“最小积”，因为负数会让最大最小互相转换。
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> maxDp(m, vector<long long>(n));
        vector<vector<long long>> minDp(m, vector<long long>(n));
        maxDp[0][0] = minDp[0][0] = grid[0][0];
        // 第一列
        for (int i = 1; i < m; i++) {
            maxDp[i][0] = minDp[i][0] = maxDp[i - 1][0] * grid[i][0];
        }
        // 第一行
        for (int j = 1; j < n; j++) {
            maxDp[0][j] = minDp[0][j] = maxDp[0][j - 1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long x = grid[i][j];
                long long a = maxDp[i - 1][j] * x;
                long long b = minDp[i - 1][j] * x;
                long long c = maxDp[i][j - 1] * x;
                long long d = minDp[i][j - 1] * x;
                maxDp[i][j] = max({ a, b, c, d });
                minDp[i][j] = min({ a, b, c, d });
            }
        }
        long long ans = maxDp[m - 1][n - 1];
        if (ans < 0) return -1;
        return ans % MOD;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}