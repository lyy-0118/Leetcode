class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //该题目转换为求k的窗口出现最小次数的"W"
        int ans = INT_MAX, cnt = 0;
        //1.入
        for (int i = 0; i < blocks.size(); i++) {
            cnt += blocks[i] == 'W' ? 1 : 0;
            if (i - k + 1 < 0) continue;
            ans = min(cnt, ans);
            cnt -= blocks[i - k + 1] == 'W' ? 1 : 0;
        }
        return ans;
    }
};