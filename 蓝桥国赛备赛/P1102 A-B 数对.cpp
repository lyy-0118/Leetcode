#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	ll C;
	cin>>N>>C;
	unordered_map<ll,ll> cnt;
	for(int i=0;i<N;i++){
		ll x;
		cin>>x;
		cnt[x]++;  //统计每个数出现个数，因为不同位置的算不同的数对
	}
	ll ans=0;
	for(auto p:cnt){
		ll x=p.first;    //当前数字为 x
		ll num=p.second; //当前数字为 x，出现次数为 cnt[x]
		if(cnt.count(x-C)){  //查找值为 x-C 的数是否存在 
			ans+=num*cnt[x-C];  //若 x - C 存在，那么答案增加 cnt[x] * cnt[x-C]
		} 
	}
	cout<<ans<<endl;
	return 0;
}