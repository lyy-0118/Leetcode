#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll a[25];
int ans = 0;

// 判断素数
bool isPrime(ll x) {
    if(x == 1 || (x != 2 && x % 2 == 0)) return 0;
    for(int i = 3; i * i <= x; i+=2) if(x % i == 0) return 0;
    return 1;
}

// start：下一个可以选择的位置
// cnt：当前已经选了几个数
// sum：当前和
void dfs(int start, int cnt, ll sum) {
    // 选够 k 个数，判断是否为素数
    if (cnt == k) {
        if (isPrime(sum)) ans++;
        return;
    }
    // 剪枝：剩下的数不够选
    if (cnt + (n - start) < k) return;
    
    for (int i = start; i < n; i++) {
        dfs(i + 1, cnt + 1, sum + a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dfs(0, 0, 0);

    cout << ans << '\n';

    return 0;
}