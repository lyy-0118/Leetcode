#include <bits/stdc++.h>
using namespace std;
const int MAXN = 9999999;
vector<bool> isPrime(MAXN + 1, true);
string s;
int ans;
typedef long long ll;

//质数筛，初始化一个质数表，方便快速判断
void InitPrime(){
	isPrime[0] = isPrime[1] = false;
	for (int i = 2;(ll)i * i <= MAXN; i++){
		if(isPrime[i]){ //一个质数的倍数一定不是质数
			for(ll j=(ll)i*i;j<=MAXN;j+=i){
				isPrime[j]=false;
			}
		}
	}
}

// DFS 枚举所有 * 的替换方案
void dfs(int pos){
	if(ans!=-1) return ;
	if(pos==(int)s.size()){
		ll num=stol(s);
		if(isPrime[num]){
			ans=num;
		}
		return ;
	}
	if(s[pos]!='*'){
		dfs(pos+1);
	}else{
		for(char c='0';c<='9';c++){
			s[pos]=c;
			dfs(pos+1);
			if(ans!=-1) return ;
		}
		s[pos]='*'; //回溯
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InitPrime();
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        ans = -1;
        dfs(0);
        cout << ans << '\n';
    }
    return 0;
}