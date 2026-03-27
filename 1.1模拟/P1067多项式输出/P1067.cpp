#include <bits/stdc++.h>

using namespace std;

int main()
{
	//按顺序扫描每一项，
	//把非零项按照“符号 + 系数 + x 的形式”格式化输出，
	//重点处理好 0、±1、指数为 1、指数为 0 这些特殊情况。
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n; //输入一元多项式的次数
	for(int i=n;i>=0;i--){
		int a;
		cin>>a; //输入n+1个整数
		if(a == 0) continue; // 处理系数为 0 的情况
		// 1. 符号
        if(a < 0) cout << '-';
        else 
        {
            if(i != n) cout << '+';
        }

        // 2. 数字
        a = abs(a);
        if(a != 1 || (a == 1 && i == 0)) cout << a;

        // 3. 次数
        if(i == 0) continue;
        else if(i == 1) cout << 'x';
        else cout << "x^" << i;
	}
    

    return 0;
}