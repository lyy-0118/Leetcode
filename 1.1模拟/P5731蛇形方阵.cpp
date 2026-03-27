#include <iostream>

using namespace std;

const int N = 15;

// 定义 右，下，左，上 四个方向
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int arr[N][N];

int main()
{
    int n; cin >> n;

    // 模拟填数过程
    int x = 1, y = 1; // 初始位置
    int cnt = 1; // 当前位置要填的数
    int pos = 0; // 当前的方向

    while(cnt <= n * n)
    {
        arr[x][y] = cnt;

        // 计算下一个位置
        int a = x + dx[pos], b = y + dy[pos];

        // 判断是否越界
        if(a < 1 || a > n || b < 1 || b > n || arr[a][b])
        {
            // 更新出正确的该走的位置
            pos = (pos + 1) % 4;
            a = x + dx[pos], b = y + dy[pos];
        }

        x = a, y = b;
        cnt++;
    }

    // 输出
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        puts("");
    }

    return 0;
}