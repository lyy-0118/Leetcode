class Solution {
public:
    //通过比较中点与右端点的关系来判断在哪半区继续搜索
    //右端点要么是最小值 要么在最小值右边
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            //比最右值大
            if (nums[mid] > nums[nums.size() - 1]) {
                l = mid + 1;
            }
            else if (nums[mid] < nums[nums.size() - 1]) {
                r = mid - 1;
            }
            else {}
        }
        return nums[l];
    }
};