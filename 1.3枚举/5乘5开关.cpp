#include <iostream>
#include <cstring>
using namespace std;

char g[5][6];
char backup_[5][6];

// 按下 (x, y)，翻转自己和上下左右
void press(int x, int y)
{
    backup_[x][y] = (backup_[x][y] == '0') ? '1' : '0';

    if (x - 1 >= 0)
        backup_[x - 1][y] = (backup_[x - 1][y] == '0') ? '1' : '0';
    if (x + 1 < 5)
        backup_[x + 1][y] = (backup_[x + 1][y] == '0') ? '1' : '0';
    if (y - 1 >= 0)
        backup_[x][y - 1] = (backup_[x][y - 1] == '0') ? '1' : '0';
    if (y + 1 < 5)
        backup_[x][y + 1] = (backup_[x][y + 1] == '0') ? '1' : '0';
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        for (int i = 0; i < 5; i++)
            cin >> g[i];

        int ans = 100;

        // 枚举第一行的“操作方案”
        //！！这里是枚举操作方案而不是第一行的状态，枚举完第一行的操作方案就能得到第一行的状态了
        //再根据第一行的状态决定第二行是否需要操作（按或不按）
        //因为如果第一行某列状态为‘0’，第二行必须按，不然就不能全亮
        //最后再判断第五行是否全亮
        for (int state = 0; state < 32; state++)
        {
            memcpy(backup_, g, sizeof(g));
            int step = 0;

            // 按照 state 决定第一行哪些位置要按
            for (int j = 0; j < 5; j++)
            {
                if ((state >> j) & 1)
                {
                    press(0, j);
                    step++;   // 这里一定要加，因为这是真实按了一次
                }
            }

            // 根据上一行状态，决定当前行是否按
            for (int i = 1; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (backup_[i - 1][j] == '0')
                    {
                        press(i, j);
                        step++;   // 这里也是一次真实操作
                    }
                }
            }

            // 检查最后一行是否全1
            bool ok = true;
            for (int j = 0; j < 5; j++)
            {
                if (backup_[4][j] == '0')
                {
                    ok = false;
                    break;
                }
            }

            if (ok) ans = min(ans, step);
        }

        if (ans > 6) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}