class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; //当k=0或k=1 无子数组乘积严格小于 k
        int l = 0, r = 0, ans = 0;
        long long sum = 1;
        while (r < nums.size()) {
            sum *= nums[r];
            while (sum >= k) { //当乘积大于等于k时,固定右区间,收缩左边界
                sum /= nums[l++];
            }
            ans += r - l + 1; //若区间[l,r]乘积小于k 则[l+1,r] [l+2,r]...[r,r]都小于
            r++;
        }
        return ans;
    }
};