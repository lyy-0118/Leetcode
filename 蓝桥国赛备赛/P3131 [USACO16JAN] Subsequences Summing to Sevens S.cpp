#include <bits/stdc++.h>
using namespace std;
//思路：前缀和 + 取模
//求最长：记录第一次位置，record[0] = 0
//1.处理输入
//2.用前缀和快速算区间和 sum[l,r]=sum[r]-sum[l-1]
//如果sum[l,r]%7==0 则符合条件 即(sum[r]-sum[l-1])%7==0
//可以推出 -> 只要当前位置的前缀余数和在前面的位置出现过，则找到一个符合条件的区间[l,r]

//设 pre[i] 表示前 i 头奶牛 ID 和
//如果 pre[r] % 7 == pre[l] % 7，那么区间 (l+1 ~ r) 的和就是 7 的倍数。

int main() {
	int N;
	cin>>N;
	vector<int> record(7,-1); //记录前i个数的前缀和余数
	record[0]=0;              //前0个数余数为0
	int sum=0;  //记录余数
	int ans=0;  //最长合法区间长度
	for(int i=1;i<=N;i++){
		int x;
		cin>>x;
		//更新余数即可
		sum=(sum+x)%7;
		if(record[sum]==-1){ // 如果这个余数第一次出现
			record[sum]=i;  //表示当前余数sum出现的位置为i
		}else{  // 如果这个余数以前出现过
			//更新最大长度
			int len=i-record[sum];
			ans=max(ans,len);
		}
	}
	cout<<ans<<'\n';
	return 0;
}