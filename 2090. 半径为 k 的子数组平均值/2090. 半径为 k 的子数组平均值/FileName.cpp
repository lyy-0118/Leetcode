class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);
        long long s = 0; // 维护窗口元素和（注意类型！）
        for (int i = 0; i < n; i++) {
            // 1. 进入窗口
            s += nums[i];
            if (i < k * 2) { // 窗口大小不足 2k+1
                continue;
            }
            // 2. 记录答案
            avgs[i - k] = s / (k * 2 + 1);
            // 3. 离开窗口
            s -= nums[i - k * 2];
        }
        return avgs;
    }
};

作者：灵茶山艾府
链接：https ://leetcode.cn/problems/k-radius-subarray-averages/solutions/1126276/on-hua-dong-chuang-kou-by-endlesscheng-jtr5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。