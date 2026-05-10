#include <bits/stdc++.h>
using namespace std;

//dfs暴力搜索，枚举2^9种情况，每个 mask 都代表一种点击方案。
//模拟点击后的灯阵状态，判断是否全部为 1。
int a[3][3];
int b[3][3];
// 上下左右和自己
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

// 翻转某个位置及其上下左右
void flip(int x, int y) {
    for (int k = 0; k < 5; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            b[nx][ny] ^= 1; // 0变1，1变0
        }
    }
}
// 判断是否全部亮
bool check() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] == 0) return false;
        }
    }
    return true;
}

// 统计二进制中1的个数，即点击次数
int countOne(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int main(){
	// 读入3×3灯阵
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 10;
    //枚举所有点击方案，2^9种
    for(int mask=0;mask<(1<<9);mask++){
    	// 复制原始状态
    	for(int i=0;i<3;i++){
    		for (int j = 0; j < 3; j++) {
                b[i][j] = a[i][j];
            }
		}
		// 根据mask执行点击
        for (int pos = 0; pos < 9; pos++) {
            if (mask & (1 << pos)) {  //判断：mask 的第 pos 位是不是 1。
                int x = pos / 3;
                int y = pos % 3;
                flip(x, y);
            }
        }
        // 如果全部亮，更新答案
        if (check()) {
            ans = min(ans, countOne(mask));
        }
	}
	cout << ans << endl;
	return 0;
}