//枚举所有飞机，如果找到一个排列使得全部飞机成功降落，则输出YES
#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n;
int T[N], D[N], L[N];
bool vis[N];
bool ok;

//dfs枚举  cnt表示当前已降落飞机的数量，now表示当前跑道空闲时间
void dfs(int cnt,int now){
	if(ok) return ;
	
	// 剪枝：如果有未降落飞机已经错过最晚开始时间
    for (int i = 0; i < n; i++) {
        if (!vis[i] && T[i] + D[i] < now) {
            return;
        }
    }
    
	if(cnt==n){
		ok=true;
		return ;
	}
	for(int i=0;i<n;i++){
		if(vis[i]) continue; //当前飞机已经降落，继续枚举下一架
		int start=max(now,T[i]); //这架飞机实际可以开始的时间
		if(start>T[i]+D[i]) continue; //当前时间已经不可以起飞了
		vis[i]=true;
		dfs(cnt+1,start+L[i]);
		vis[i]=false;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> T[i] >> D[i] >> L[i];
        }
        memset(vis, false, sizeof(vis));
        ok = false;
        dfs(0, 0);
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
