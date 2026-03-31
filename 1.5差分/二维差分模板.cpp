#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1010;

int n, m, q;
LL f[N][N]; // 差分矩阵

// 差分矩阵的性质
void insert(int x1, int y1, int x2, int y2, LL k)
{
    f[x1][y1] += k; f[x1][y2 + 1] -= k; f[x2 + 1][y1] -= k; f[x2 + 1][y2 + 1] += k;
}

int main()
{
    cin >> n >> m >> q;
    // 预处理差分矩阵
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            LL x; cin >> x;
            //给子矩阵 (i,j) ~ (i,j) 整体加上 x，也就是只给单个点加 x
            //本质是：把原矩阵的每个元素，都当作一次“单点矩形修改”加入差分矩阵中。
			//这样做的好处是：
			//1.输入初始矩阵
			//2.后续 q 次矩形加法操作
			//都统一成同一种操作：insert(...)
            insert(i, j, i, j, x);
        }
    }
    
    // 处理 q 次修改操作
    while(q--)
    {
        LL x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
        insert(x1, y1, x2, y2, k);
    }
    
    // 利用前缀和还原出修改之后的数组
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}