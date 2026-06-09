#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//如果直接暴力翻倍 某个大的数字翻倍会超出long long的数据范围
//所以我们枚举操作的次数f[i]
//要求 a[i]*2^f[i]>a[i-1]*2^f[i-1]
//假设 当前i的操作次数==i-1的操作次数
//看此时 x y的大小
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> f(n);  //f[i] 表示 a[i] 要乘几次 2(操作次数)
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		f[i]=f[i-1]; //假设操作次数等于上一次的操作次数
		ll x=a[i],y=a[i-1];
		while(x<y){  //此时x太小了 需要翻倍 操作次数++
			x*=2;
			f[i]++;
		}
		while(x>=y*2){ //此时x太大了 需要减去操作次数 可以理解为 x/2>=y
			// 如果当前数已经不需要乘 2 了，也就是 f[i] == 0
        	// 那就不能再减少操作次数，否则会变成负数
			if(f[i] == 0) break;
 			y*=2;
 			f[i]--;
		}
		ans+=f[i];
	}
	cout<<ans<<'\n';
	return 0;
}