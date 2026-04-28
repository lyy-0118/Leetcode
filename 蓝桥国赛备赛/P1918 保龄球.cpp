#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll n;
	cin>>n;
	unordered_map<ll,int> ans; //该位置瓶子个数, 坐标位置
	ans.reserve(n * 2); // 预留空间，减少哈希冲突和重哈希
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		ans[x]=i;  // 瓶子数 -> 位置
	}
	ll Q,m;
	cin>>Q;
	while(Q--){
		cin>>m;
//		if(ans[m]){
//			cout<<ans[m]<<endl;
//		}else{
//			cout<<'0'<<endl;
//		}
		auto it=ans.find(m); // 用 find,find返回的是一个迭代器
		if (it != ans.end()) cout << it->second << '\n';
        else cout << 0 << '\n';
        
	}
	return 0;
}