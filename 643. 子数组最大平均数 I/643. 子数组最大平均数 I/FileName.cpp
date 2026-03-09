class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 1. 初始化 ans 为最小值，避免全负数情况出错
        double ans = -DBL_MAX;
        double sum = 0;
        int l = 0, r = 0;

        while (r < nums.size()) {
            // 1. 入窗口：无条件加入当前元素
            sum += nums[r];

            // 2. 判断窗口大小
            if (r - l + 1 == k) {
                // 更新结果
                ans = max(ans, sum / k);

                // 3. 出窗口：减去左边元素，并右移左指针
                sum -= nums[l++];
            }// 继续移动右指针
            r++;
        }
        return ans;
    }
};