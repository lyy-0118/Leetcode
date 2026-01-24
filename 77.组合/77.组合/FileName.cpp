//https://leetcode.cn/problems/combinations/submissions/693820080/ 组合

class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        ret.clear();
        path.clear();
        dfs(n, k);
        return ret;
    }
    void dfs(int n, int k) { //n代表有多少个数可选 k代表要选多少个数
        int d = k - path.size();      //d为还需要选的数
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        for (int i = n; i > d - 1; i--) {   //倒序找，由于 当前范围的数应>=还要选的数 所以遍历到d
            path.push_back(i);
            dfs(i - 1, k);
            path.pop_back();
        }
    }
};