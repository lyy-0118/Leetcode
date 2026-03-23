#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    // 48. 旋转图像
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // 遍历对角线上方元素，做转置
                swap(matrix[i][j], matrix[j][i]);
            }
            ranges::reverse(matrix[i]); // 行翻转
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}