//https://leetcode.cn/problems/combinations/submissions/693820080/ 组合

//解法1 For 循环写法 (N 叉树)：
//逻辑：我现在确定选某一个数 i，然后去剩下的范围选。
//树的形状：第一层有 n 个分支（选1, 选2...），第二层分支变少。
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

//解法2 选或不选当前位置
//逻辑：针对数字 n，我要还是不要？
//树的形状：每个节点只有 2 个分支（左子树选，右子树不选）。
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
        //k-path.size()表示还缺多少数
        if (n < k - path.size()) {
            return; //此时剩下的也不够选了 直接剪枝返回
        }
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        //1.选择当前位置(逆序选)
        path.push_back(n);
        dfs(n - 1, k);
        path.pop_back();

        // 2. 不选当前位置 n
        // 只有库存(n) 大于 需求(rest) 时，才允许奢侈地“跳过”
        if (n > k - path.size()) {
            dfs(n - 1, k);
        }
    }
};