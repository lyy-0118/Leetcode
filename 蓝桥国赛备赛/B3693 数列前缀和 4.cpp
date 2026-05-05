#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
//或 typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<vector<ull>> pre(n + 1, vector<ull>(m + 1, 0));

		//填入前缀和
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ull x;
                cin >> x;

                pre[i][j] = pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1]
                          + x;
            }
        }
	
	    //查询并返回ans
        ull ans = 0;

        while (q--) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;

            ull res = pre[x][y]
                    - pre[u - 1][y]
                    - pre[x][v - 1]
                    + pre[u - 1][v - 1];
			
			//按位异或
            ans ^= res;
        }

        cout << ans << '\n';
    }

    return 0;
}