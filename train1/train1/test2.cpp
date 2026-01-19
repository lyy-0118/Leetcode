#include <iostream>
// #include <algorithm> // 手写了gcd就不需要这个头文件了，不过留着也没事
using namespace std;

// 手写 GCD 函数：完美
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 辅助函数：求两个数的 LCM (封装起来更清晰)
int lcm(int a, int b) {
    // 这里的逻辑是：先除以最大公约数，再乘以 b
    // 这样可以最大程度防止中间结果溢出
    return (a / gcd(a, b)) * b;
}

int main() {
    int a, b, c;
    // 1. 必须要有输入！
    cin >> a >> b >> c;

    // 2. 第一步：求 a 和 b 的最小公倍数
    int lcm_ab = lcm(a, b);

    // 3. 第二步：求 (a,b的公倍数) 和 c 的最小公倍数
    int ans = lcm(lcm_ab, c);

    cout << ans << endl;

    return 0;
}
