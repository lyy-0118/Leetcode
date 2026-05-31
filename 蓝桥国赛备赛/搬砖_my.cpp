#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//比较函数
bool cmp(pair<int,int> x,pair<int,int> y) {
	return x.first+x.second<y.first+y.second;
}
int main() {
	int n;
	cin>>n;
	vector<pair<int,int>> a(n);
	int maxW=0,maxV=0;
	for(int i=0; i<n; i++) {
		int w,v;
		cin>>w>>v;
		a[i]= {w,v};
		maxW=max(maxW,w);
		maxV=max(maxV,v);
	}
	sort(a.begin(), a.end(), cmp);      // 按照 w + v 从小到大排序砖块

// 	测试
//	for(int i=0;i<n;i++){
//		cout<<a[i].first<<" "<<a[i].second<<endl;
//	}
//	cout<<maxW<<" "<<maxV<<endl;

	int limit = maxW + maxV;            // DP 数组的最大重量范围
	vector<ll> dp(limit+5,-1e10); //dp[j]表示重量为 j 时的最大价值
	ll ans=0;
	dp[0]=0; //重量为 0 时最大价值为 0
	for(int i=0; i<n; i++) { //枚举每块砖
		int w=a[i].first;
		int v=a[i].second;
		//上面所有砖的重量和不能超过当前砖的自身价值
		//j<=v 01背包 倒叙枚举防止重复选
		for(int j=v; j>=0; j--) {
			if(dp[j]<0) continue; //重量为j的情况目前不存在
			int newW=j+w;  //加上当前砖 新的总重量
			/*
			对于总重量为 newWeight 的塔，
			原来的最优方案和使用当前砖得到的新方案，
			保留两者中价值更大的那个。
			*/
			dp[newW]=max(dp[newW],dp[j]+v);
			ans=max(ans,dp[newW]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}