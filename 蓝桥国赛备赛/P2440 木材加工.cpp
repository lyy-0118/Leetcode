#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>k;
	vector<ll> len(n+1);
	ll sum=0,max_len=0;
	for(int i=1;i<=n;i++){
		cin>>len[i];
		sum+=len[i];
		max_len=max(len[i],max_len);
	}
	auto check=[&](ll d){
		if(k*d>sum){
			//此时木材长度大于总长
			return false;
		}
		ll num=0;
		for(int i=1;i<=n;i++){
			num+=len[i]/d;
			if(num>=k) return true; //如果数量大于k段 说明可以枚举更大的
		}
		return false;
	};
	
	// 如果总长度都不够切出 k 段 1cm 的木头
	if(sum<k) cout<<'0'<<'\n';
	else{
		//二分枚举木材长度
		ll l=1,r=max_len;
		while(l<=r){
			ll mid=l+(r-l)/2;
			if(check(mid)){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<r<<'\n';
	}
	return 0;
}