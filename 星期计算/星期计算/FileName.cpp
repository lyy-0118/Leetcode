//题目:已知今天是星期六，请问 20^22天后是星期几？并且用数字 1 到 7 表示星期一到星期日。
#include<iostream>
using namespace std;
int main() {
	int current_day = 6; // 星期六用数字6表示
	int x = 20, y = 22;
	//计算 (20^22) mod 7
	for (int i = 1; i < y; i++) {
		x = (x % 7) * 20 % 7;
	}
	int ans = (x + current_day - 1) % 7 + 1; // 加上当前的星期数，要先 -1 把编号变成 0~6，取模后再 +1 变回 1~7。
	cout << ans << endl; // 输出结果
	return 0;
}