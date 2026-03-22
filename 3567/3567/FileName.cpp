#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans;

        //遍历所有可能的左上坐标
        for (int i = 0; i <= n - k; i++) {
            vector<int> row;
            for (int j = 0; j <= m - k; j++) {
                //找到当前k*k的子矩阵
                vector<int> nums;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        nums.push_back(grid[x][y]);
                    }
                }

                //从小到大排序
                sort(nums.begin(), nums.end());
                int crt_min = INT_MAX;
                for (int z = 1; z < nums.size(); z++) {
                    //注意：题目说求两个 不同值 之间的 最小绝对差 
                    if (nums[z] != nums[z - 1]) {
                        crt_min = min(crt_min, nums[z] - nums[z - 1]);
                    }
                }
                // 如果子矩阵中的所有元素都相同，则答案为 0
                row.push_back(crt_min == INT_MAX ? 0 : crt_min);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}