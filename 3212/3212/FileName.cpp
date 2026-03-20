class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();

        vector<vector<pair<int, int>>> sums(
            n + 1, vector<pair<int, int>>(m + 1, { 0, 0 }));

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int addx = (grid[i - 1][j - 1] == 'X');
                int addy = (grid[i - 1][j - 1] == 'Y');
                sums[i][j].first = sums[i - 1][j].first + sums[i][j - 1].first -
                    sums[i - 1][j - 1].first + addx;
                sums[i][j].second = sums[i - 1][j].second +
                    sums[i][j - 1].second -
                    sums[i - 1][j - 1].second + addy;
                if (sums[i][j].first == sums[i][j].second &&
                    sums[i][j].first > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};