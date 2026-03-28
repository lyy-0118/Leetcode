#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int>& a, int n, int first) {
    vector<int> x(n + 2, 0); // x[0]=0, x[n+1]=0，边界补 0
    x[1] = first;            // 枚举 x1 是 0 还是 1

    // 特判 n=1
    if (n == 1) {
        // 只有一行时，第二列这个数字只会受到左边 x1 的影响
        // 所以 a1 = x1
        return a[1] == x[1];
    }

    // n >= 2 时，先由 a1 = x1 + x2 推出 x2
    x[2] = a[1] - x[1];

    // x[2] 表示“第 2 行第一列有没有雷”，只能是 0 或 1
    if (x[2] != 0 && x[2] != 1) return false;

    // 递推求后续位置
    for (int i = 2; i <= n - 1; i++) {
        // 由 a[i] = x[i-1] + x[i] + x[i+1]
        // 推出 x[i+1] = a[i] - x[i] - x[i-1]
        x[i + 1] = a[i] - x[i] - x[i - 1];

        // 每个位置只能是“有雷”或“没雷”
        // 即只能取 1 或 0
        if (x[i + 1] != 0 && x[i + 1] != 1) return false;
    }

    // 最后一行要满足 a[n] = x[n-1] + x[n]
    if (a[n] != x[n - 1] + x[n]) return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    if (check(a, n, 0)) ans++;
    if (check(a, n, 1)) ans++;

    cout << ans << endl;
    return 0;
}