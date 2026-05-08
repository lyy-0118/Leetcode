#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//思路:记忆化搜索
int dp[25][25][25]; // 存储 w(a,b,c) 的结果，0 表示未计算

int w(ll a, ll b, ll c) {
    // 条件 1：注意要先判断这个 只要有一个 <= 0，答案就是 1
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    // 条件 2：超过 20 都看作 w(20,20,20)
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }

    // 如果已经计算过，直接返回
    if (dp[a][b][c] != 0) {
        return dp[a][b][c];
    }

    // 条件 3 ：a < b < c
    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c - 1)
                    + w(a, b - 1, c - 1)
                    - w(a, b - 1, c);
    } 
    // 条件 4 
    else {
        dp[a][b][c] = w(a - 1, b, c)
                    + w(a - 1, b - 1, c)
                    + w(a - 1, b, c - 1)
                    - w(a - 1, b - 1, c - 1);
    }

    return dp[a][b][c];
}

int main() {
    ll a, b, c;

    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = "
             << w(a, b, c) << endl;
    }

    return 0;
}