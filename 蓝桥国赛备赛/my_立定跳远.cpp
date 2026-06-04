#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
bool check(const vector<ll>& a,ll L){
	bool canUseSkill = false;
	ll need=0;
	for(int i=1;i<=n;i++){
		ll d=a[i]-a[i-1];
		if(d>L) canUseSkill=true; //只有当距离大于L的时候才能用技能 最后减去一个检查点
		ll seg=(d+L-1)/L; //分成seg段
		need+=seg-1;  //新增检查点=seg-1
		if(need>m+1) return false; //此时L已经不符合条件了，提前剪枝
	}
	if(canUseSkill) need-=1;
	return need<=m;
}
int main(){
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	auto check=[&](ll L) -> bool{
		bool canUseSkill = false;
		ll need=0;
		for(int i=1;i<=n;i++){
			ll d=a[i]-a[i-1];
			if(d>L) canUseSkill=true; //只有当距离大于L的时候才能用技能 最后减去一个检查点
			ll seg=(d+L-1)/L; //分成seg段
			need+=seg-1;  //新增检查点=seg-1
			if(need>m+1) return false; //此时L已经不符合条件了，提前剪枝
		}
		if(canUseSkill) need-=1;
		return need<=m;
	};
	//二分查找L
	ll left=1,right=a[n];
	while(left<=right){
		ll mid=(right-left)/2+left;
		if(check(mid)){
			ans=mid;
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}