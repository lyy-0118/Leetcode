#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];  //a[i]:第 i 个检查点在数轴上的坐标。
	}
	auto check=[&](ll L)-> bool {
		ll need = 0;  // 不使用技能时需要增加的检查点数量
		bool canUseSkill = 0; // 是否存在某段距离 > L 只有在两点距离大于 L 时才能使用技能
		for(int i=1;i<=n;i++){
			ll d=a[i]-a[i-1]; //两点距离d
			if(d>L) canUseSkill = 1;
			
			//这一段需要拆成 ceil(d / L) 段 
			//正确的整数向上取整：
			ll seg=(d + L - 1) / L;
			// 增加的检查点数量 = 段数 - 1
			need += seg-1;
			if(need>m+1){
				return false;  //如果检查点已经超过m+1 则此时L肯定不成立
			}
		}
		// 技能最多可以减少 1 个新增检查点
        if (canUseSkill) {
            need--;
        }
        return need <= m;
	};
	
	//二分查找L
	ll left = 1;
    ll right = a[n];
    ll ans = right;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}