#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//统计个数：记录出现次数，cnt[0] = 1

//如果两个前缀和对 K 取模后的余数相同，那么它们之间的区间和就是 K 的倍数。
//因此遍历数组时，维护每种余数出现的次数。
//当前余数是 r，之前出现过 cnt[r] 次，那么以当前位置结尾的合法区间就有 cnt[r] 个。
int main(){
	ll N,K;
	cin>>N>>K;
	vector<ll> cnt(K,0);  //cnt[r] 表示余数 r 出现次数
    //比如前 i 个数的和刚好是 K 的倍数，那么区间 [1,i] 就合法
    //如果没有 record[0] = 1，这种从开头开始的区间会漏掉
	cnt[0]=1;  // 空前缀和为 0，余数是 0
	ll sum=0;
	ll ans=0;
	for(int i=1;i<=N;i++){
		ll x;
		cin>>x;
		sum=(sum+x)%K;
		// 之前有多少个相同余数，就能组成多少个 K 倍区间
		ans+=cnt[sum];
		cnt[sum]++;
	}
	cout<<ans<<'\n';
	return 0;
}