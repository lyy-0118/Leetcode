class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, r = 0;
        // 使用 128 覆盖标准 ASCII 码，初始化为 0
        int hash[128] = { 0 };
        while (r < s.size()) {
            //1.入
            hash[s[r]]++;
            //2.出 有重复字符
            while (hash[s[r]] > 1) {
                hash[s[l]]--;
                l++;
            }
            //3.更新
            ans = max(r - l + 1, ans);
            r++;
        }
        return ans;
    }
};