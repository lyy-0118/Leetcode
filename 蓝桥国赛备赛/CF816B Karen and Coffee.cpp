#include <bits/stdc++.h>
using namespace std;

const int MAXT = 200000 + 5;

int diffArr[MAXT]; // 差分数组
int pre[MAXT];     // pre[i] 表示 1~i 中可接受温度数量

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    // 1.读入 n 个配方区间,差分
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        // 表示从 l 开始覆盖次数 +1
        diffArr[l]++;

        // 表示从 r+1 开始，这个区间影响结束
        diffArr[r + 1]--;
    }

	//2.第一次前缀和：还原每个温度被多少个配方覆盖
	
    int cnt = 0; // 当前温度被多少个配方推荐
	
    for (int i = 1; i <= 200000; i++) {
        // 滚动数组 cnt,由差分数组还原当前温度的覆盖次数
        // cnt[i] = cut[i-1] + diff[i];
        cnt += diffArr[i];

        // 3.第二次前缀和：统计到每个位置为止，有多少个可接受温度
		// 如果当前温度被至少 k 个配方推荐，就算可接受
        if (cnt >= k) {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }

    // 4. 处理 q 个询问
    while (q--) {
        int a, b;
        cin >> a >> b;

        // [a,b] 中可接受温度数量
        cout << pre[b] - pre[a - 1] << '\n';
    }

    return 0;
}