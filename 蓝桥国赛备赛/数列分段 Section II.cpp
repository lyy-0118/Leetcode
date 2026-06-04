#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//分割数组，使最大段和最小
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin>>N>>M;
    vector<ll> a(N);
    //答案下界：数组最大值,每段和的最大值最小为数组最大值
    //答案上界：数组总和，每段和的最大值最大为数组总和
    ll left=0,right=0;
    for (int i = 0; i < N; i++){
    	cin>>a[i];
    	left=max(left,a[i]);
    	right+=a[i];
	}
	
	//判断最大段和限制为 limit 时，能否分成不超过 M 段
	auto check = [&](ll limit)-> bool{
		int cnt=1;  //当前已经使用的段数
		ll sum=0;   //当前段的和
		for(int i=0;i<N;i++){
			// 如果当前元素放进当前段不会超过 limit
			if (sum + a[i] <= limit) {
                sum += a[i];
            } else {
                // 否则新开一段
                cnt++;
                sum = a[i];
            }
		}
		return cnt <= M;
	};
	
	//二分枚举
	//能不能让每段和都不超过 x？
	//如果 x 可以，那么更大的值也可以
	//如果 x 不可以，那么更小的也不可以
	ll ans=0;
	while(left<=right){
		ll mid = (right-left) / 2+left;
		if(check(mid)){
			ans=mid;
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;;
}