#include <bits/stdc++.h>
using namespace std;
//切一刀的收益 = 这刀右边所有数的和。
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
    	int n;
        cin >> n;
        vector<long long> a(n + 1);
        long long total = 0; // total 用来记录整个数组的总和，也就是不切时的答案
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total += a[i];
        }
        vector<long long> cuts; // cuts 用来存储每个切割点的贡献，也就是后缀和        
		long long suffix = 0;   // suffix 表示当前计算到的后缀和
		// 下面从右往左计算每个切割点右边的和
        // 如果在 i - 1 和 i 之间切一刀，那么右边就是 a[i] 到 a[n]
        // 这一刀的贡献就是 a[i] + a[i+1] + ... + a[n]
        for (int i = n; i >= 2; i--) { // 从最后一个数开始往前枚举，i 最小到 2
            suffix += a[i]; // 把 a[i] 加入后缀和，此时 suffix = a[i] + ... + a[n]
            cuts.push_back(suffix); // 保存这个切割点的贡献
        }
        sort(cuts.begin(), cuts.end(), greater<long long>()); // 把所有切割贡献从大到小排序
		vector<long long> ans(n + 1); // ans[k] 表示切成 k 段时的最大答案
		ans[1] = total; // 切成 1 段时不能切，答案就是整个数组总和
		long long add = 0; // add 表示当前已经选择的切割点贡献之和
		for (int k = 2; k <= n; k++) { // 枚举切成 k 段的情况，从 2 段到 n 段
			// 切成 k 段，需要切 k - 1 刀
            // ans[1] 是不切的情况
            // ans[2] 要选 1 个最大贡献
            // ans[3] 要选 2 个最大贡献
            // ...
            // 所以每次在上一次基础上，多加一个最大的未选择贡献
            add += cuts[k - 2]; // 加上第 k-1 大的切割贡献，因为数组下标从 0 开始，所以是 cuts[k-2]
			ans[k] = total + add; // 切成 k 段的最大答案 = 原始总和 + 选中的切割贡献之和		
		}
		for (int k = 1; k <= n; k++) { // 输出 ans[1] 到 ans[n]
            cout << ans[k]; // 输出切成 k 段时的最大答案
            if (k < n) cout << ' '; // 如果不是最后一个数，就输出一个空格
        }
        cout << '\n'; // 当前测试数据输出完后换行
	}
	return 0;
}