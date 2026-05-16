#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
ll pre[N + 5];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	// 预处理前 N 项的前缀和
	int pos = 1; // pos 表示当前生成到了数列的第几个位置
	// block 表示当前正在生成第几块
    // 第 block 块的内容是：1, 2, 3, ..., block
	for (int block = 1; pos <= N; block++) {
    	for (int x = 1; x <= block && pos <= N; x++) {
    		// 当前数列第 pos 项的值就是 x
            // 前 pos 项和 = 前 pos - 1 项和 + 当前项 x
        	pre[pos] = pre[pos - 1] + x;
        	pos++;
    	}
	}
	int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}