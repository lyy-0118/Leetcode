#include <iostream>
using namespace std;


int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool check(int year, int month, int day) {
	if (month < 1 || month > 12) return false;
	if (day < 1) return false;

	// 特判闰年的2月
	if (month == 2) {
		//(能被4整除 且 不能被100整除) 或者 (能被400整除)
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
			return day <= 29;
		}
		else return day <= 28;
	}
	// 其他月份直接查表
	return day <= days[month];
}
int main() {
	//输入一个起始日期（8位整数，如 20200202），请找出在这个日期之后（不含）的第一个回文日期。
	int N;
	cin >> N;
	bool found1 = false; // 是否已经找到了普通回文并输出了？
	bool found2 = false; // 是否已经找到了ABAB回文并输出了？
	for (int i = N / 10000; i <= 9999; i++) { //遍历年份，从N年开始
		int current_date = i;
		int x = current_date;//用来取反
		while (x > 0) {
			current_date = current_date * 10 + x % 10;  // 把 x 的最后一位拼到 current_date 后面，构成回文字串
			x /= 10;
		}
		if (check(current_date / 10000, current_date % 10000 / 100, current_date % 100) && current_date > N) //检查是否符合条件
		{
			// 逻辑核心：
			// 如果还没找到普通回文，不仅要标记，还要打印！
			if (!found1) {
				cout << current_date << endl;
				found1 = true;
			}
			// 如果还没找到ABAB回文，判断它是不是ABAB
			if (!found2) {
				// 判断年份 i 是否满足 ABAB
				int num = current_date % 10000; //取出后四位
				if ((num / 1000 == num % 100 / 10) && (num / 100 % 10 == num % 10)) {
					cout << current_date << endl;
					found2 = true; //找到第二个回文日期
				}
			}
			// 只有当两个都找到了，才退出循环
			if (found1 && found2) break;
		}
	}
	return 0;
}