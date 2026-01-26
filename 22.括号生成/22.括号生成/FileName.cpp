class Solution {
    vector<string> ret;
    string path;
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ret;
    }
    void dfs(int n, int left, int right) {
        if (path.size() == 2 * n) {
            ret.push_back(path);
            return;
        }
        //1.当左括号小于要选的个数时 可以选择左括号
        if (left < n) {
            path.push_back('(');
            dfs(n, left + 1, right);
            path.pop_back();  //回溯
        }
        //2.当右括号小于左括号数量 可以选择右括号
        if (right < left) {
            path.push_back(')');
            dfs(n, left, right + 1);
            path.pop_back();  //回溯
        }
    }
};