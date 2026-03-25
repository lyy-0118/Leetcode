#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        constexpr int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector p(n, vector<int>(m));

        long long suf = 1; // 后缀乘积
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = suf; // p[i][j] 先初始化成后缀乘积
                suf = suf * grid[i][j] % MOD;
            }
        }

        long long pre = 1; // 前缀乘积
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = p[i][j] * pre % MOD; // 乘上前缀乘积
                pre = pre * grid[i][j] % MOD;
            }
        }

        return p;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}