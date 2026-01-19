//#include <iostream>
//using namespace std;
//
//// 这是一个功能函数
//int countTwo(int n) {
//	int count = 0;
//	// 请在这里补全：数位拆分逻辑
//	while (n > 0) {
//		if (n % 10 == 2) count++;
//		n /= 10;
//	}
//	return count;
//}
//
//int main() {
//	int total = 0;
//	// 请在这里补全：循环 1 到 2020
//	for (int i = 1; i < 2021; i++) {
//		int n = i;
//		total += countTwo(n);
//	}
//	cout << total << endl;
//	return 0;
//}

#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int total = 0;
	for (int i = 1; i < 2021; i++) {
		string s = to_string(i);
		total += count(s.begin(), s.end(), '2');
	}
	cout << total << endl;
	return 0;
}