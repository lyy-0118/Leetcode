class Solution {
    vector<string> ret;
    string path;
    vector<string> strs = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        ret.clear();
        path.clear();
        if (digits.size() == 0) return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(string digits, int pos) {
        if (pos == digits.size()) {
            ret.push_back(path);
            return;
        }
        string str = strs[digits[pos] - '0']; //”≥…‰
        for (int i = 0; i < str.size(); i++) {
            path.push_back(str[i]);
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};