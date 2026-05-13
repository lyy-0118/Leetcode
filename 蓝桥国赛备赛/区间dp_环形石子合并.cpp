#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main(){
	int n;
    cin >> n;
	vector<ll> a(2*n+1);
	vector<ll> pre(2*n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i]; //环形石子 将这条链延长两倍，变成 2n 堆
	}
	// 求前缀和
	for (int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
	vector<vector<ll>> maxn(2*n+1,vector<ll>(2*n+1,-INF));  //找最大值
	vector<vector<ll>> minn(2*n+1,vector<ll>(2*n+1,INF)); //找最小值
	// 一个石子堆不需要合并，得分为 0
	for (int i = 1; i <= 2 * n; i++) {
        minn[i][i] = 0;
        maxn[i][i] = 0;
    }
    //枚举区间长度
    for(int len=2;len<=n;len++){
    	for(int l=1;l+len-1<=2*n;l++){
    		int r=l+len-1;
    		ll sum=pre[r]-pre[l-1];
    		//枚举最后一次分界点
    		for(int k=l;k<r;k++){
    			// 最小得分
                minn[l][r]=min(minn[l][r],minn[l][k]+minn[k+1][r]+sum);
                //最大得分
                maxn[l][r]=max(maxn[l][r],maxn[l][k]+maxn[k+1][r]+sum);
			}
		}
	}
	ll ans_min=INF;
	ll ans_max=-INF;
	// 枚举所有长度为 n 的区间，相当于枚举断环位置
	for(int i=1;i<=n;i++){
		int j=i+n-1;
		ans_min=min(ans_min,minn[i][j]);
		ans_max=max(ans_max,maxn[i][j]);
	}
	cout << ans_min << '\n';
    cout << ans_max << '\n';
    return 0;
}