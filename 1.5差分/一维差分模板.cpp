#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL f[N]; // 差分数组

//差分数组记录的是“相邻两个数的变化量”
//如果要把区间 $[l, r]$ 全部加上 $c$，那么差分数组只需要：
//f[l] += c
//f[r+1] -= c
//原因是：
//
//从位置 l 开始，后面的数都应该多 c
//从位置 r+1 开始，这个影响停止，所以减回去 c
//
//最后对差分数组做一遍前缀和，就能还原出修改后的原数组。
int main(){
	cin >> n >> m;
    // 利用差分数组的性质，创建差分数组
    for(int i = 1; i <= n; i++)
    {
        LL x; cin >> x;
        f[i] += x;
        f[i + 1] -= x;
    }
    // 处理 m 次修改操作
    while(m--)
    {
        LL l, r, k; cin >> l >> r >> k;
        f[l] += k; f[r + 1] -= k;
    }
    // 还原出原始的数组
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i];
        cout << f[i] << " ";
    }
    return 0;
}