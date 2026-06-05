#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<ll> a(n);
		ll total=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			total+=a[i]; //数组总和 切一段的值
		}
		ll suffix=0;
		vector<ll> cuts;
		//算切割点的贡献
		for(int i=n-1;i>=1;i--){
			suffix+=a[i];
			cuts.push_back(suffix);
		}
		//从大到小排序贡献点
		sort(cuts.begin(),cuts.end(),greater<ll>());
		vector<ll> ans(n); //返回值 存放切1、2、3....n段的值
		ans[0]=total;
		//计算切2段、3段、...n段的值
		for(int k=2;k<=n;k++){
			total+=cuts[k-2];
			ans[k-1]=total;
		}
		for(int i=0;i<n;i++){
			if(i==n-1){
				cout<<ans[i]<<'\n';
			}else{
				cout<<ans[i]<<' ';
			}
		}
	}
	return 0;
}