#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL f[N]; // 差分数组


//1.求出每段路经过的次数（差分）
//2.比较哪种花钱方式最少

int main()
{
    cin >> n >> m;
    // 先读入第一个点，作为起点
    int x; cin >> x;
    // 依次读取后面的点，形成 x -> y 的移动
    for(int i = 2; i <= m; i++)
    {
        int y; cin >> y;
         // 从 x 到 y，会经过 min(x,y) ~ max(x,y)-1 这些边
        int l=min(x,y);
        int r=max(x,y);
        // 对边区间 [l, r-1] 进行 +1
        // 差分写法：f[l]++, f[r]--
        f[l]++;
        f[r]--;
        // 更新起点，准备处理下一段路径
        x = y;
    }

    // 利用差分数组，前缀和还原出原数组
    for(int i = 1; i <= n; i++) f[i] += f[i - 1];

    // 直接求结果
    LL ret = 0;
    for(int i = 1; i < n; i++)
    {
        LL a, b, c; cin >> a >> b >> c;
        ret += min(a * f[i], c + b * f[i]);
    }

    cout << ret << endl;

    return 0;
}