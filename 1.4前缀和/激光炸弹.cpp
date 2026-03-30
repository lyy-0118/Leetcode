#include <bits/stdc++.h>
using namespace std;

const int N = 5002;
int a[N][N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x++, y++;
        a[x][y] += v;
    }

    // 二维前缀和，直接在 a 上做
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    m = min(m, N - 1);
    int ans = 0;

    for (int x2 = m; x2 < N; x2++) {
        for (int y2 = m; y2 < N; y2++) {
            int x1 = x2 - m + 1, y1 = y2 - m + 1;
            int cur = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
            ans = max(ans, cur);
        }
    }

    cout << ans << endl;
    return 0;
}