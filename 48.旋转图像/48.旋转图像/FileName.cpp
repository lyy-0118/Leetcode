#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //沿对角线翻转求矩阵转置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {   //如果写成 j < matrix[0].size()，会把每一对元素交换两次，导致转置失败。
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //行反转
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}