#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll arr[N];
//题目目标：
//找一个最长的连续区间
//区间内所有雪花编号都不重复
int main(){
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    int T;
    cin >> T; // 测试数据组数
    while(T--){
        int n; //输入当前这组有几个数据
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<ll,ll> mp; // 记录当前窗口内每个数出现次数
        int l = 0;                 // 滑动窗口左端点
        int ans = 0;               // 最终答案
        for (int r = 0; r < n; r++) {
            mp[arr[r]]++; // 先把右端元素加入窗口
            // 如果当前元素重复了，就不断缩小左边界
            // 直到 arr[r] 在窗口中只出现 1 次
            while (mp[arr[r]] > 1) {
                mp[arr[l]]--;
                l++;
            }
            // 此时窗口 [l, r] 一定没有重复元素
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}