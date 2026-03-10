class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //据题意,有多个峰顶,必存在一个峰顶
        //红色部分为目标峰左侧 蓝色部分为目标峰或其右侧
        //所以查找区间 [0,n-2]
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < nums[mid + 1])
                l = mid + 1; //红色
            else
                r = mid - 1; //蓝色
        }
        //此时l为最左边的蓝色（其中一个峰顶）
        return l;
    }
};