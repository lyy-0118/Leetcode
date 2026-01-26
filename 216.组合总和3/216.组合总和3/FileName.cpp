//解法一 循环 多叉树
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ret.clear();
        path.clear();
        // 题目要求是在 1-9 之间选
        dfs(9, k, n);
        return ret;
    }
    //i表示当前可选的数 k一共要选的个数 t表示当前目标和
    void dfs(int i, int k, int t) {
        int d = k - path.size();  //还需选择的数量
        //剪枝1:目标和小于0（和太大）
        //剪枝2:剩余数里最大值都小于目标和 剩下的不用考虑
        if (t<0 || t>(2 * i - d + 1) * d / 2) {
            return;
        }
        //当d=0(已经不需再选)，上面的if(t<0||t>0)，只有t==0时继续运行，此时不用再判断目标和
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        for (int j = i; j > d - 1; j--) {  //剪枝3：i<d
            path.push_back(j);
            dfs(j - 1, k, t - j);
            path.pop_back(); //回溯
        }
    }
};
//解法二 二叉树
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ret.clear();
        path.clear();
        // 题目要求是在 1-9 之间选
        dfs(9, k, n);
        return ret;
    }
    //i表示当前可选的数 k一共要选的个数 t表示当前目标和
    void dfs(int i, int k, int t) {
        //倒序选
        int d = k - path.size();  //还需选择的数量
        //剪枝1:目标和小于0（和太大）
        //剪枝2:剩余数里最大值都小于目标和 剩下的不用考虑
        //剪枝3:i<d
        if (t<0 || t>(2 * i - d + 1) * d / 2 || i < d) {
            return;
        }
        //当d=0(已经不需再选)，上面的if(t<0||t>0)，只有t==0时继续运行，此时不用再判断目标和
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        //1.选择当前位置
        path.push_back(i);
        dfs(i - 1, k, t - i);
        path.pop_back();

        //2.不选当前位置
        if (i > d) {
            dfs(i - 1, k, t);
        }
    }
};