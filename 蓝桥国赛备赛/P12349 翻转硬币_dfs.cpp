#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<string> a;
int flipRow[25];
ll ans = 0;

// 计算当前 flipRow 方案下的总价值
ll calc() {
    ll res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = (a[i][j] - '0') ^ flipRow[i];
            int cnt = 0;

            // 上
            if (i > 0) {
                int up = (a[i - 1][j] - '0') ^ flipRow[i - 1];
                if (cur == up) cnt++;
            }

            // 下
            if (i + 1 < n) {
                int down = (a[i + 1][j] - '0') ^ flipRow[i + 1];
                if (cur == down) cnt++;
            }

            // 左
            if (j > 0) {
                int left = (a[i][j - 1] - '0') ^ flipRow[i];
                if (cur == left) cnt++;
            }

            // 右
            if (j + 1 < m) {
                int right = (a[i][j + 1] - '0') ^ flipRow[i];
                if (cur == right) cnt++;
            }

            res += 1LL * cnt * cnt;
        }
    }

    return res;
}

// 枚举每一行翻不翻
void dfs(int row) {
    if (row == n) {
        ans = max(ans, calc());
        return;
    }

    // 当前行不翻转
    flipRow[row] = 0;
    dfs(row + 1);

    // 当前行翻转
    flipRow[row] = 1;
    dfs(row + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dfs(0);
	
    cout << ans << '\n';

    return 0;
}