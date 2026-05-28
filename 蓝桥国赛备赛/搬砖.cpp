#include <bits/stdc++.h>              
using namespace std;                  

// 自定义排序函数，用来告诉 sort 按什么规则排序
bool cmp(pair<int, int> x, pair<int, int> y) {       // x 和 y 表示两块砖
    return x.first + x.second < y.first + y.second;  // 按照 w + v 从小到大排序
}

int main() {                 

    ios::sync_with_stdio(false);        
    cin.tie(nullptr);                  

    int n;                              // n 表示砖块数量
    cin >> n;                           // 输入砖块数量

    vector<pair<int, int>> a(n);        // 定义一个数组 a，存 n 块砖，每块砖用 pair<int,int> 表示

    int maxW = 0;                       // maxW 用来记录所有砖中最大的重量
    int maxV = 0;                       // maxV 用来记录所有砖中最大的承重/价值

    for (int i = 0; i < n; i++) {       // 循环读入 n 块砖
        int w, v;                       // w 表示当前砖重量，v 表示当前砖承重/价值
        cin >> w >> v;                  // 输入当前砖的重量和承重/价值

        a[i] = {w, v};                  // 把当前砖存入数组，first 存 w，second 存 v

        maxW = max(maxW, w);            // 更新最大重量
        maxV = max(maxV, v);            // 更新最大承重/价值
    }

    sort(a.begin(), a.end(), cmp);      // 按照 w + v 从小到大排序砖块

    int limit = maxW + maxV;            // DP 数组的最大重量范围，一般只需要开到 maxW + maxV

    vector<long long> dp(limit + 1, -1e18); // dp[j] 表示总重量为 j 的塔能获得的最大价值，初始为极小值表示不存在

    dp[0] = 0;                          // 初始状态：什么砖都不选，总重量为 0，价值为 0

    long long ans = 0;                  // ans 用来记录最终答案，也就是最大价值

    for (int i = 0; i < n; i++) {       // 枚举每一块砖

        int w = a[i].first;             // 取出当前砖的重量 w
        int v = a[i].second;            // 取出当前砖的承重/价值 v

        for (int j = v; j >= 0; j--) {  // 枚举当前砖上面已有塔的重量 j，必须满足 j <= v

            if (dp[j] < 0) continue;    // 如果 dp[j] 不存在，说明不能搭出重量为 j 的塔，直接跳过

            int newWeight = j + w;      // 把当前砖放到塔下面后，新塔总重量 = 原塔重量 j + 当前砖重量 w

            if (newWeight <= limit) {   // 判断新重量是否在 DP 数组范围内，防止数组越界

                dp[newWeight] = max(dp[newWeight], dp[j] + v); // 更新新重量下的最大价值

                ans = max(ans, dp[newWeight]); // 用当前新状态更新答案
            }
        }
    }

    cout << ans << '\n';                // 输出最终最大价值

    return 0;                           // 程序正常结束
}