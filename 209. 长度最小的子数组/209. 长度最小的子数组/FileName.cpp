class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, sum = 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            //移动右端点，再看左端点需不需要更新
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};