class Solution {
public:
    // 找到第一个大于等于target的数字下标
    // 否则返回len(nums)
    int lower_bound(vector<char>& nums, char target) {
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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = lower_bound(letters, target + 1);
        if (i == letters.size())
            return letters[0];
        else
            return letters[i];
    }
};