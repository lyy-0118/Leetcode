#include <iostream>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
int a[N], b, c[N];
int la, lc;

// 高精度除法的模板 - c = a / b （高精度 / 低精度）
void sub(int c[], int a[], int b)
{
    LL t = 0; // 标记每次除完之后的余数
    for(int i = la - 1; i >= 0; i--)
    {
        // 计算当前的被除数
        t = t * 10 + a[i];
        c[i] = t / b;
        t %= b;
    }

    // 处理前导 0
    while(lc > 1 && c[lc - 1] == 0) lc--;
}

int main()
{
    string x; cin >> x >> b;
    la = x.size();

    for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';

    // 模拟除法的过程
    lc = la;
    sub(c, a, b); // c = a / b

    for(int i = lc - 1; i >= 0; i--) cout << c[i];
 

    return 0;
}