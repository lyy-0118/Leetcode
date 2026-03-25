#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> p(n, 1), s(n, 1);
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * nums[i - 1];
        }
        for (int j = n - 2; j >= 0; j--) {
            s[j] = s[j + 1] * nums[j + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = p[i] * s[i];
        }
        return ans;

    }
};
//空间复杂度优化版：
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        //先求前缀和
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        //再求后缀和
        int suffix = 1;
        for (int j = n - 1; j >= 0; j--) {
            ans[j] *= suffix;
            suffix *= nums[j];
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}