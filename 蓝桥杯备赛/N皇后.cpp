#include <iostream>
#include <vector>
using namespace std;

int n;
long long total = 0;                 // 记录解的总数
vector<int> path;                    // path[i] 表示第 i 行皇后放在哪一列
vector<vector<int>> ans;             // 保存前 3 个解
vector<bool> colUsed;                // 某列是否已被占用
vector<bool> diag1Used;              // 主对角线是否已被占用：row - col + n
vector<bool> diag2Used;              // 副对角线是否已被占用：row + col

void dfs(int row){
	// 如果已经放完了 1~n 行，说明找到一个完整解
	if(row>n){
		total++; //记录总数
		if((int)ans.size()<3){
			ans.push_back(path);
		}
		return ;
	}
	// 为了保证字典序，列从小到大枚举
	for(int col=1;col<=n;col++){
		int d1=row-col+n;   // 主对角线编号
		int d2=row+col;     // 副对角线编号
		// 如果当前列、主对角线、副对角线都没有冲突，则可以放
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