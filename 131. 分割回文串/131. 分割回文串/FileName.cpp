class Solution {
public:
    vector<vector<string>> ret; // 存储最终结果
    vector<string> crt_strs;    // 当前字符串子集
    vector<vector<string>> partition(string s) {
        ret.clear();
        crt_strs.clear();
        dfs(0, s);
        return ret;
    }

private:
    void dfs(int i, string& s) {
        // 终止条件：如果起始位置已经到了字符串末尾，说明找到了一组解
        if (i == s.size()) {
            ret.push_back(crt_strs);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string crt_str(s, i, j - i + 1); // string (const string& str, size_t pos, size_t len = npos);
            if (IsPalindrome(crt_str)) {
                crt_strs.push_back(crt_str);
                dfs(j + 1, s);
                crt_strs.pop_back();
            }
        }
    }
    //判断是否回文串
    bool IsPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};