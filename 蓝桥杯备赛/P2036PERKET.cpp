#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
    cin >> n;
    vector<int> s(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }
    ll ans = LLONG_MAX;
    //二进制枚举
    //比如mask=5时，二进制为101，表示1选、2不选、3选
    //mask从1开始，因为必须选一个调料
    for(int mask=1;mask<(1<<n);mask++){
    	ll si=1,bi=0;
    	for(int i=0;i<n;i++){
    		if((mask>>i)&1){  //或者mask & (1 << i)
    			//选
    			si*=s[i];
    			bi+=b[i];
			}
		}
		ans=min(abs(si-bi),ans);
	}
	cout<<ans<<'\n';
	return 0;
}