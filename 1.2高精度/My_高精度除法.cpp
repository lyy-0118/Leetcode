#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
int a[N], b, c[N];
int la, lc;
void My_div(int c[],int a[],int b){
	//记录每次除之后的余数
	ll t=0;
	for(int i=la-1;~i;i--){
		//计算当前的被除数;
		t=t*10+a[i];
		c[i]=t/b;
		t%=b;
	}
	// 处理前导 0
    while(lc > 1 && c[lc - 1] == 0) lc--;
}
//（高精度 / 低精度）
int main(){
	string x;
	cin>>x>>b;
	la=x.size();
	
	for(int i=0;i<la;i++){
		a[la-1-i]=x[i]-'0';  //逆序存储被除数
	}
	// 模拟除法的过程
	//被除数有 la 位时，商的位数最多也是 la 位，
	//所以先把商长度设成 la，再通过去前导 0 得到真正长度。
	lc = la;
	My_div(c,a,b); //c=a/b
	for(int i=lc-1;~i;i--) cout<<c[i];
	
	return 0;
}