class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, sum = 0, l = 0, r = 0;
        int n = threshold * k;
        while (r < arr.size()) {
            sum += arr[r];
            if (r - l + 1 == k) {
                if (sum >= n) ans++;
                sum -= arr[l++];
            }
            r++;
        }
        return ans;
    }
};