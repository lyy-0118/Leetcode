#include <iostream>
#include <vector>
using namespace std;

// 返回x的第k位是否为1
bool getBit(int x, int k) {
    return (x & (1 << k)) != 0;
}

// 把x的第k位置为1
int setBit(int x, int k) {
    return x | (1 << k);
}

// 把x的第k位清零
int clearBit(int x, int k) {
    return x & (~(1 << k));
}

// 把x的第k位翻转
int flipBit(int x, int k) {
    return x ^ (1 << k);
}

// 返回x的最低位1所对应的值
int lowbit(int x) {
    return x & (-x);
}

// 统计二进制中1的个数：Brian Kernighan算法
int countOnes(int x) {
    int cnt = 0;
    while (x) {
        x = x & (x - 1); // 每次去掉最低位的1
        cnt++;
    }
    return cnt;
}

// 判断x是否是2的幂
bool isPowerOfTwo(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

int main() {
    int x = 13; // 二进制：1101

    cout << "x = " << x << endl;
    cout << "x的二进制中1的个数: " << countOnes(x) << endl;

    // 判断奇偶
    if (x & 1) cout << x << " 是奇数" << endl;
    else cout << x << " 是偶数" << endl;

    // 取第2位（从0开始计数）
    cout << "第2位是否为1: " << getBit(x, 2) << endl;

    // 第1位置为1
    cout << "第1位置为1后: " << setBit(x, 1) << endl;

    // 第2位清零
    cout << "第2位清零后: " << clearBit(x, 2) << endl;

    // 第0位翻转
    cout << "第0位翻转后: " << flipBit(x, 0) << endl;

    // lowbit
    cout << "x的lowbit: " << lowbit(x) << endl;

    // 判断是否是2的幂
    cout << "8是否是2的幂: " << isPowerOfTwo(8) << endl;
    cout << "10是否是2的幂: " << isPowerOfTwo(10) << endl;

    // 左移和右移
    cout << "x << 1 = " << (x << 1) << endl; // 相当于乘2
    cout << "x >> 1 = " << (x >> 1) << endl; // 相当于除2（非负数）

    // 内置函数
    cout << "__builtin_popcount(x) = " << __builtin_popcount(x) << endl;

    // 状态压缩：枚举 n=3 的所有状态
    int n = 3;
    cout << "枚举所有状态：" << endl;
    for (int s = 0; s < (1 << n); s++) {
        cout << "状态 " << s << " : ";
        for (int i = n - 1; i >= 0; i--) {
            cout << ((s >> i) & 1);
        }
        cout << endl;
    }

    // 枚举某个状态的所有非空子集
    int s = 13; // 二进制1101
    cout << "状态 " << s << " 的所有非空子集：" << endl;
    for (int sub = s; sub; sub = (sub - 1) & s) {
        cout << sub << endl;
    }

    return 0;
}