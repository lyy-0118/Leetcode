#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin>>n;
	vector<long long> s(n), b(n);
	for(int i=0;i<n;i++){
		cin>>s[i]>>b[i];
	}
	ll ans = LLONG_MAX;
	//二进制枚举
	//从1开始 001，因为必须选一种配料
	for(int mask=1;mask<(1<<n);mask++){
		ll si=1,bi=0;
		for(int i=0;i<n;i++){
			if((mask>>i)&1){
				//选当前位置
				si*=s[i];
				bi+=b[i];
			}
		}
		ans=min(llabs(si-bi),ans);
	}
	cout<<ans<<'\n';
	return 0;
}