#include <bits/stdc++.h>
using namespace std;

// 判断一个数是否为好数
bool check(int x) {
    int pos = 1; // pos=1 表示个位，pos=2 表示十位...

    while (x > 0) {
        int d = x % 10; // 取当前最低位

        if (pos % 2 == 1) {
            // 奇数位：必须是奇数
            if (d % 2 == 0) return false;
        } else {
            // 偶数位：必须是偶数
            if (d % 2 == 1) return false;
        }

        x /= 10; // 去掉最低位
        pos++;
    }

    return true; // 所有位都满足
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (check(i)) ans++;
    }

    cout << ans << '\n';
    return 0;
}