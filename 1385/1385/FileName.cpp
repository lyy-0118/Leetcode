class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //给arr2排序 再二分查找arr2是否有[x-d,x+d]区间的值
        ranges::sort(arr2);
        int ans = 0;
        for (auto x : arr1) {
            auto l = ranges::lower_bound(arr2, x - d); //lower_bound返回的是iterator
            if (l == arr2.end() || *l > x + d) { //若l不存在或l的值大于x+d则符合题意
                ans++; //计数
            }
        }
        return ans;
    }
};