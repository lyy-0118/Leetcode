#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	vector<ll> a(N);
	ll ans=LLONG_MAX;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	//枚举长度为M的区间 [i,i+M-1]
	for(int i=0;i+M-1<N;i++){
		ll left=a[i];
		ll right=a[i+M-1];
		ll cur=right*right-left*left;
		ans=min(ans,cur);
	}
	cout<<ans<<'\n';
	return 0;
}