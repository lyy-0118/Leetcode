#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
typedef long double ld;
ld p;
ld a[N],b[N];

// 判断能不能坚持 t 秒
bool check(ld t){
	ld need=0;       // 所有设备总共需要充电宝补的电
	ld supply=p*t;   // 充电宝 t 秒内最多能提供的电
	for(int i=1;i<=n;i++){
		// 第 i 个设备在 t 秒内总耗电量
		ld cost=t*a[i];
		// 如果初始电量不够，就需要充电宝补
		if (cost > b[i]) {
            need += cost - b[i];
        }
        // 如果缺口已经超过充电宝能力，提前返回
        if (need > supply) {
            return false;
        }
	}
	return need <= supply;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p;
    ld sumA=0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sumA += a[i];
    }
    // 如果充电宝每秒提供的电量 >= 所有设备每秒总消耗
    // 那么整体电量不会减少，可以无限使用
    if (sumA <= p) {
        cout << -1 << '\n';
        return 0;
    }
    //二分枚举时间
    ld l=0,r=1e18;
    for (int i = 0; i < 100; i++) {
        ld mid = (l + r) / 2;
        if (check(mid)) {
            // mid 秒可以做到，答案可能更大
            l = mid;
        } else {
            // mid 秒做不到，答案只能更小
            r = mid;
        }
    }
    //小数点后保留 10 位
    cout << fixed << setprecision(10) << (double)l << '\n';
	return 0;
}