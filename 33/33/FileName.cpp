//解法1 两次二分  
class Solution {
public:
    // 有序数组中找 target 的下标
    int lower_bound(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            // 循环不变量：
            // nums[right] >= target
            // nums[left] < target
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1; // 范围缩小到 [left, mid-1]
            }
            else {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            }
        }
        return nums[left] == target ? left : -1;
    }
    // 两次二分
    // 1.第一次先找到最小值i的下标
    // 2.判断t和n[len-1]的关系
    // t>n[len-1] 说明t在[0,i-1]
    // t<=n[len-1] 说明t在[i,n-1]
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] > nums[nums.size() - 1])
                l = mid + 1;
            else if (nums[mid] < nums[nums.size() - 1])
                r = mid - 1;
            else {
            };
        }
        int i = l;
        if (target > nums.back()) {
            return lower_bound(nums, 0, i - 1, target);
        }return lower_bound(nums, i, nums.size() - 1, target);
    }
};
//解法2 一次二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 2;
        int last = nums[nums.size() - 1];
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target) return mid;
            //1.mid 和 target 在不同递归段
            //mid在第一段 target 在第二段
            if (nums[mid] > last && target <= last) l = mid + 1;
            //mid在第二段 target 在第一段
            else if (nums[mid] <= last && target > last) r = mid - 1;
            //2.mid 和 target 在同一递归段
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return (l < nums.size() && nums[l] == target) ? l : -1;
    }
};