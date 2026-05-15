//暴力解法:
//O(n^2)枚举每一个区间每一个线段 判断是否被框住

//正解:
//“线段有至少一半的长度被包含在某个区间内，则将其视为被这个区间框住”
//结论 -> 如果区间内包含了线段中点则框住了这个线段
//用一个前缀和数组记录区间内包含线段中点的个数
//由于区间中点可能为小数，计算时都 *2

#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int a[N], s[N];
//s[i] 有多少条线段的「中点 × 2」落在区间 [0, i] 内。
int main(){
	int n,m;
	cin>>n>>m;
	int l,r;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		//记录中点 * 2 的位置
        a[l + r]++;
	}
	// 前缀和
    for (int i = 1; i <= 2e6; i++) {
        s[i] = s[i - 1] + a[i];
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        // 查询中点 * 2 在 [2l, 2r] 内的数量
        cout << s[r * 2] - s[l * 2 - 1] << endl;
    }
	return 0;
}