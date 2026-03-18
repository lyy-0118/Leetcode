class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sums(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sums[i][j] = grid[i][j];

                if (i > 0) sums[i][j] += sums[i - 1][j];
                if (j > 0) sums[i][j] += sums[i][j - 1];
                if (i > 0 && j > 0) sums[i][j] -= sums[i - 1][j - 1];

                if (sums[i][j] <= k) ans++;
            }
        }

        return ans;
    }
};