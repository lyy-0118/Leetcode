#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s[10];
ll b[10];
ll ans=LLONG_MAX;

void dfs(int x,ll si,ll bi,bool chosen){ //x表示当前选到第几种配料了
    //递归出口：所有食材都处理完了
	if(x==n){
		if(chosen){ //至少选一种配料
			ans=min(ans,abs(si-bi));
		}
		return ;
	}
	//选当前配料
	dfs(x+1,si*s[x],bi+b[x],true);
	//不选当前配料
	dfs(x+1,si,bi,chosen);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>b[i];
	}
	dfs(0,1,0,false);
	cout<<ans<<endl;
	return 0;
}