#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int board[5][5]; // 1 表示白棋，0 表示黑棋

bool Win(){
	//检查每一行
	for(int i=0;i<5;i++){
		bool same=true;
		for(int j=1;j<5;j++){
			if(board[i][j]!=board[i][0]){
				//发现一个不相同，则连不成五个
				same=false;
				break;
			}
		}
		if(same) return true; //遍历了一行发现五个相同 则有一方获胜
	}
	//检查每一列
	for(int i=0;i<5;i++){
		bool same=true;
		for(int j=1;j<5;j++){
			if(board[j][i]!=board[0][i]){
				same = false;
                break;
			}
		}
		if (same) return true;
	}
	// 检查主对角线
    bool same = true;
    for (int i = 1; i < 5; i++) {
        if (board[i][i] != board[0][0]) {
            same = false;
            break;
        }
    }
    if (same) return true;
    // 检查副对角线
    same = true;
    for (int i = 1; i < 5; i++) {
        if (board[i][4 - i] != board[0][4]) {
            same = false;
            break;
        }
    }
    if (same) return true;
    return false;
}

//组合型dfs枚举
//白棋13个 黑棋12个
void dfs(int cnt_white,int pos){
	// 白棋超过 13 个，不合法
	if(cnt_white>13) return ;
	// 剩余格子全放白棋也凑不够 13 个，剪枝
	if(25-pos<13-cnt_white) return ;
	// 所有格子都处理完
	if(pos==25){
		if(cnt_white==13&&!Win()){
			ans++;
		}
		return ;
	}
	int x=pos/5;
	int y=pos%5;
	//当前位置放白棋
	board[x][y]=1;
	dfs(cnt_white+1,pos+1);
	//放黑棋
	board[x][y]=0;
	dfs(cnt_white,pos+1);
}
int main(){
	dfs(0,0);
	cout << ans << endl;
	return 0;
}