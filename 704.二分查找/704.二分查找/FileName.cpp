class Solution {
public:
    //找到第一个大于等于target的数字下标
    //否则返回len(nums)
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int i = lower_bound(nums, target);
        //这地方注意i==nums.size()时访问nums[i]会越界
        if (i == nums.size() || nums[i] != target) return -1;
        else return i;
    }
};