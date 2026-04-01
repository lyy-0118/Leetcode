#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=1e6+5;
const int M=2e3+5;
int a[N];       // a[i]代表画第 i 幅画的名师的编号。
int kind;       // 当前窗口内包含了多少种不同画师
int mp[M];      // 统计当前窗口内每个画师出现次数
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1;
	int ret = n + 1; //存储包含所有名师画的最小距离
	int begin = 1;   // 最优区间左端点
	for(int r=1;r<=n;r++){
		 // 1. a[r] 进入窗口
		if(mp[a[r]]++==0) kind++;
		// 2. 如果当前窗口已经包含所有 m 位画师
		while(kind==m){
			int len = r - l + 1;
            // 3. 更新最优答案
            // 这里只写 len < ret 就够了
            // 因为第一次得到某个最短长度时，left 一定最小
            if (len < ret)
            {
                ret = len;
                begin = l;
            }
            // 4. a[left] 出窗口，尝试缩小区间
            if (mp[a[l]]-- == 1) kind--;
            l++;
		}
	}
	cout << begin << " " << begin + ret - 1 << endl;
	return 0;
}