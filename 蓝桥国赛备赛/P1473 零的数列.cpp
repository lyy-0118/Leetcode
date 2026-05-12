#include <bits/stdc++.h>
using namespace std;
int N;
char op[10];  // op[i] 表示数字 i 和 i+1 之间的符号

// 计算当前表达式的值
int calc(){
	int sum=0;
	int num=1;   //正在处理的数字,从1开始
	int last_op=op[0];
	for(int i=1;i<N;i++){ //处理符号
		int nextNum=i+1;
		if(op[i]==' '){ //符号为空格，先拼接，下一步再加减
			num=num*10+nextNum;
		}else{          //符号为 + -
			if(last_op=='+') sum+=num;
			else sum-=num;
			
			// 更新符号和当前数字
			last_op=op[i];
			num=nextNum;
		}
	}
	// 处理最后一个数字
    if (last_op == '+') sum += num;
    else sum -= num;
    return sum;
}

// 输出当前表达式
void printExpr() {
    for (int i = 1; i <= N; i++) {
        cout << i;
        if (i < N) cout << op[i];
    }
    cout << '\n';
}

//DFS枚举符号
void dfs(int pos){
	if(pos==N){
		if(calc()==0){
			printExpr();
		}
		return ;
	}
	// 按 ASCII 顺序：空格、+、-
	op[pos]=' ';
	dfs(pos+1);
	op[pos]='+';
	dfs(pos+1);
	op[pos]='-';
	dfs(pos+1);
}

int main() {
    cin >> N;
    op[0]='+';
    dfs(1);
    return 0;
}