//#include <iostream>
//using namespace std;
//
//int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//bool check(int year, int month, int day) {
//	if (month < 1 || month > 12) return false;
//	if (day < 1 ) return false;
//
//	// 特判闰年的2月
//	if (month == 2) {
//		//(能被4整除 且 不能被100整除) 或者 (能被400整除)
//		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
//			return day <= 29;
//		}
//		else return day <= 28;
//	}
//	// 其他月份直接查表
//	return day<=days[month];
//}
//int main() {
//	return 0;
//}