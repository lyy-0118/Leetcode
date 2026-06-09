//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const ll Y=1e9+7;
//int main(){
//	ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//	int T;
//	cin>>T;
//	while(T--){
//		ll N;
//		cin>>N;
//		vector<string> strs(N+1);
//		strs[1]="0",strs[2]="1",strs[3]="01";
//		for(int i=4;i<=N;i++){
//			strs[i]=strs[i-2]+strs[i-1];
//		}
//		
//		string s=strs[N];
//		ll ans=0,len=s.size();
//		vector<ll> dp(len);
//		
//		if(s[len-1]=='1') dp[len-1]=0;
//		else dp[len-1]=1;
//		
//		for(int i=len-2;i>=0;i--){
//			if(s[i]=='1'){
//				dp[i]=dp[i+1];
//				ans+=dp[i]%Y;
//			}else{
//				dp[i]=dp[i+1]+1;
//			}
//		}
//		cout<<ans%Y<<endl;
//	}
//	
//	return 0;
//}

//拼接字符串 $A+B$ 的逆序对数量 = $A$ 内部逆序对 + $B$ 内部逆序对 + $A$ 中 1 的数量 × $B$ 中 0 的数量。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Y = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<int> q(T);
    int maxN = 0;
    //先读入所有询问，找到最大 N，一次性预处理，避免每个测试点都重复算。
    for (int i = 0; i < T; i++) {
        cin >> q[i];
        maxN = max(maxN, q[i]);
    }
	//  zero[i]：S_i 中 0 的数量
	//	one[i]：S_i 中 1 的数量
	//	ans[i]：S_i 中逆序对数量
	vector<ll> zero(maxN + 1);
    vector<ll> one(maxN + 1);
    vector<ll> ans(maxN + 1);
    // S1 = "0"
    zero[1] = 1;
    one[1] = 0;
    ans[1] = 0;
    // S2 = "1"
    zero[2] = 0;
    one[2] = 1;
    ans[2] = 0;
	//   S_i = S_{i-2} + S_{i-1}，逆序对分三种：
	//	在 S_{i-2} 内部
	//	在 S_{i-1} 内部
	//	左边的 1 来自 S_{i-2}，右边的 0 来自 S_{i-1}
    for (int i = 3; i <= maxN; i++) {
        zero[i] = (zero[i - 2] + zero[i - 1]) % Y;
        one[i] = (one[i - 2] + one[i - 1]) % Y;
        ans[i] = (
            ans[i - 2] +
            ans[i - 1] +
            one[i - 2] * zero[i - 1] % Y
        ) % Y;
    }
    for (int i = 0; i < T; i++) {
        cout << ans[q[i]] << '\n';
    }
}
