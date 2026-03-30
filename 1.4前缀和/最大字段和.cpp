//要使得字段和最大,即f[r]-f[l-1]最大
//f[l-1]越小，字段和最大
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int n;
LL f[N]; // 前缀和数组，f[i] 表示前 i 个数的和
int main()
{
    cin >> n;
    // 读入数据并计算前缀和
    for (int i = 1; i <= n; i++) {
        LL x;
        cin >> x;
        f[i] = f[i - 1] + x;
    }
    LL ret = LLONG_MIN;
    LL pre = 0; //存放最小前缀和的变量，初始有 f[0] = 0，表示子段可以从第 1 个数开始
    for(int i=1;i<=n;i++){
    	// 以 i 作为右端点时，
        // 最大子段和 = 当前前缀和 f[i] - 前面最小前缀和 prevmin
    	ret=max(ret,f[i]-pre);
    	pre=min(pre,f[i]);
	}
    cout<<ret<<endl;

    return 0;
}