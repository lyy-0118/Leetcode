#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e7;
//计算前n项和
//如果要求前 n 项的和，我们先要知道：前 n 项里面完整包含了多少个块。
//二分就是在找：最大的 k，使得前 k 块的总长度不超过 n。
ll cal(ll n){
	if(n<=0) return 0;
	ll l=0,r=N;
	ll k=0;
	while(l<=r){
		ll mid=(l+r)/2;
		ll len=mid*(mid+1)/2;
		if(len<=n){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	k=r;  //找到最大的第 k 块
	ll ans=k*(k+1)*(k+2)/6; //求前 k 个完整块的总和
	ll used=(ll)k * (k + 1) / 2; //求前 k 个完整块一共占了多少项
	ll rest=n-used;  //求还剩多少项没有算 还需要从第 k + 1 块里取前 rest 项
	ans+=rest*(rest+1)/2;
	return ans;
} 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
    	ll l,r;
    	cin>>l>>r;
    	ll ans=cal(r)-cal(l-1);
    	cout<<ans<<'\n';
	}
	return 0;
}