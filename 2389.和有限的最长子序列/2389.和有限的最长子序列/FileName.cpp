class Solution {
public:
    // 若要在总和不超过 q
    // 的前提下，使选择的元素个数最多，那么一定应该优先选最小的元素。
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> sums(nums.size());
        vector<int> ret(queries.size());
        // 1.排序
        sort(nums.begin(), nums.end());
        // 2.求前缀和
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = nums[i] + sums[i - 1];
        }
        // 3.对每个 query 二分查找
        // 在前缀和数组里面找到 sums[i]<= q
        for (int i = 0; i < queries.size(); i++) {
            ret[i] = upper_bound(sums.begin(), sums.end(), queries[i]) - sums.begin();
        }
        return ret;
    }
};