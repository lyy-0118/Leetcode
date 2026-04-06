
class Solution {
public:
    bool Judge(int h1[], int h2[]) {
        for (int i = 0; i < 26; i++) {
            if (h1[i] != h2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int h1[26] = {0}; // 当前窗口的字符频次
        int h2[26] = {0}; // p的字符频次
        vector<int> ret;  // 结果数组
        for (auto ch : p) {
            h2[ch - 'a']++;
        }
        int l = 0, r = 0, len = p.size();
        while (r < s.size()) {
            // 1.进窗口
            h1[s[r] - 'a']++;
            r++;
            while (r - l > len) { // 左闭右开区间 [l, r)
                // 2.出
                h1[s[l] - 'a']--;
                l++;
            }
            // 3.判断
            if (r - l == len && Judge(h1, h2)) {
                ret.push_back(l);
            }
        }
        return ret;
    }
};