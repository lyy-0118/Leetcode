class Solution {
public:
    // 找到第一个大于等于target的数字下标
    // 否则返回len(nums)
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    int maximumCount(vector<int>& nums) {
        //思路 找>= 0的 和 >=1 的边界
        //[-,zero_edge] [one_edge,nums.size()-1]
        int zero_edge = lower_bound(nums, 0);
        int one_edge = lower_bound(nums, 1);
        int pos = zero_edge, neg = nums.size() - one_edge; //neg=nums.size()-1-one_edge+1;
        return max(pos, neg);
    }
};