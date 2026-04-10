#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[20];
int ans=0;
// 判断 x 是否为质数
bool IsPrime(int x){
	if(x<2) return false;  // 质数必须大于等于 2
	for(int i=2;i*i<=x;i++){  // 枚举到 sqrt(x) 即可
		if(x%i==0) return false;
	}
	return true;
}
void dfs(int start,int cnt,int sum){
	//start表示当前开始的下标，cnt表示选了多少数，sum表示当前所选数字之和
	//已经选了k个，判断是否是质数，是的话ans++
	if(cnt==k){
		if(IsPrime(sum)){
			ans++;
		}
		return ;
	}
	// 剪枝：如果剩余数字数量不足以凑满 k 个，直接返回
    if (n - start < k - cnt) return;
    
    //组合型dfs,从start开始尝试选下个
    for(int i=start;i<n;i++){
    	dfs(i+1,cnt+1,sum+a[i]);
	}
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}