#include<bits/stdc++.h>
using namespace std;

//排列型 DFS + 回溯 + 剪枝。
// 排列型 DFS：因为每一列只能用一次，相当于每一行从还没用过的列中选一个数。
// 回溯：先尝试放一个棋子，递归下一行；如果后面不行，就撤销这一步，换别的列。
// 剪枝：用三个数组快速判断当前位置能不能放

//对于当前行 row，枚举每一个列 col，判断这一列、主对角线、副对角线是否已经有棋子。

int n;
long long total;
vector<int> path;
vector<vector<int>> ans;
vector<bool> colUsed;   //列
vector<bool> diag1Used; //主对角线
vector<bool> diag2Used; //副对角线

void dfs(int row){
    if(row>n){
        total++;
        if((int)ans.size()<3){
            ans.push_back(path);
        }
        return ;
    }
    for(int col=1;col<=n;col++){
        int d1=row-col+n;
        int d2=row+col;
        if (!colUsed[col] && !diag1Used[d1] && !diag2Used[d2]) {
            // 做选择：放置皇后
            path[row] = col;
            colUsed[col] = true;
            diag1Used[d1] = true;
            diag2Used[d2] = true;
            // 递归处理下一行
            dfs(row + 1);
            // 撤销选择：回溯
            colUsed[col] = false;
            diag1Used[d1] = false;
            diag2Used[d2] = false;
        }
    }
}
int main(){
    	cin>>n;
	// 下标从 1 开始更方便
    path.resize(n + 1);
    // 列编号最大到 n
    colUsed.assign(n + 1, false);
    // 对角线数量大约是 2n，开大一点保险
    diag1Used.assign(2 * n + 1, false);
    diag2Used.assign(2 * n + 1, false);
    
    dfs(1);
    // 输出前 3 个解
    for (int i = 0; i < (int)ans.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) cout << " ";
            cout << ans[i][j];
        }
        cout << "\n";
    }
    // 输出总解数
    cout << total << "\n";

    return 0;
}