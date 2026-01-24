//https://leetcode.cn/problems/subsets/ 子集
//解法一
//选择或不选择当前位置
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.clear();
        path.clear();
        dfs(nums, 0);
        return ret;
    }
private:
    void dfs(vector<int>& nums, int n) {
        if (n == nums.size()) {
            ret.push_back(path);
            return;
        }
        //1.选择当前位置
        path.push_back(nums[n]);
        dfs(nums, n + 1);
        path.pop_back(); //回溯

        //2.不选择当前位置
        dfs(nums, n + 1);
    }
};

//解法2 以元素的个数
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.clear();
        path.clear();
        dfs(nums, 0);
        return ret;
    }
private:
    void dfs(vector<int>& nums, int n) {
        ret.push_back(path);
        //1.循环加递归
        for (int i = n; i < nums.size(); i++) {
            ;
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};