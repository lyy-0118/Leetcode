//解法一：滑动窗口模板
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

//解法二:优化版
//在方法一的基础上，我们不再分别统计滑动窗口和字符串 p 中每种字母的数量，而是统计滑动窗口和字符串 p 中每种字母数量的差；
//并引入变量 differ 来记录当前窗口与字符串 p 中数量不同的字母的个数，并在滑动窗口的过程中维护它。
//在判断滑动窗口中每种字母的数量与字符串 p 中每种字母的数量是否相同时，只需要判断 differ 是否为零即可。

class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int n = s.size(), m = p.size();
        if (n < m)
            return ret;
        //如果 cnt[i] == 0，说明这个字符数量匹配
        //所有 cnt[i] == 0，说明是我们要找的“异位词”
        int cnt[26] = {0}; // 记录p和s串中i字符出现次数的差值数组
        int diff = 0;      // p和s串中有多少个字符种类的计数不为 0
        for (auto ch : p) {
            if (!(cnt[ch - 'a'])) diff++; // 原来匹配，改完可能不匹配
            cnt[ch - 'a']--;
        }
        int l = 0, r = 0;
        while (r < n) {
            char ch = s[r] - 'a';
            // 1.进窗口
            // 右端字符进入窗口前，先看原状态
            if (!(cnt[ch])) diff++;  // 原来匹配，改完可能不匹配
            cnt[ch]++;
            if (!(cnt[ch])) diff--;  // 改完后重新匹配

            //2.出窗口
            if(r-l+1>m){
                char ch2=s[l]- 'a';
                if (!(cnt[ch2])) diff++;  // 原来匹配，改完可能不匹配
                cnt[ch2]--;
                if (!(cnt[ch2])) diff--;  // 改完后重新匹配
                l++;
            }

            //3.判断
            if(r-l+1==m && diff==0){
                ret.push_back(l);
            }
            r++;
        }
        return ret;
    }
};