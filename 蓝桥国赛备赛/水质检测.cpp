#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 30;

// s[i][0] 表示第 i 列上面的格子
// s[i][1] 表示第 i 列下面的格子
char s[N][2];

// dp[i][0] 表示处理到第 i 列，连通块最后在上面时的最小新增数量
// dp[i][1] 表示处理到第 i 列，连通块最后在下面时的最小新增数量
int dp[N][2];
void solve(){
	 string t;
    int n;
    // 读入两行字符串
	for(int j = 0; j < 2; j++){
		cin >> t;
        n = t.size();
        // 为了方便处理，这里从下标 1 开始存
    	for(int i = 1; i <= n; i++){
        	s[i][j] = t[i - 1];
   		}
	}
    // st 表示最左边有 # 的列
    // en 表示最右边有 # 的列
    int st = n + 1, en = 0;
    // 找到左右边界
    for(int i = 1; i <= n; i++){
        if(s[i][0] == '#' || s[i][1] == '#'){  //如果此列有 # 时，更新左右边界
            st = min(i, st);
            en = max(en, i);
        }
    }
    // 如果没有任何原始检测器，不需要新增
    if(st == n + 1){
        cout << 0 << endl;
        return;
    }
    // 如果起始列上面不是 #，但我们选择从上面开始，就要新增一个
    if(s[st][0] != '#') dp[st][0] = 1;
    // 如果起始列下面不是 #，但我们选择从下面开始，就要新增一个
    if(s[st][1] != '#') dp[st][1] = 1;
    // 从 st+1 列开始向右 DP
    for(int i=st+1;i<=en;i++){
    	//两个状态转移
    	dp[i][0]=min(
			dp[i-1][0],
			dp[i-1][1]+(s[i][1]!='#')
		)+(s[i][0]!='#');
		
		dp[i][1]=min(
			dp[i-1][1],
			dp[i-1][0]+(s[i][0]!='#')
		)+(s[i][1]!='#');
	}
	// 最后可以停在 en 列上面，也可以停在下面，取最小值
    cout << min(dp[en][0], dp[en][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}