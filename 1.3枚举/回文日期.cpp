#include <iostream>
using namespace std;

// 判断闰年
bool isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// 返回某年某月的天数
int getDays(int year, int month) {
    if (month == 2) return isLeap(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int main() {
    int x, y;
    cin >> x >> y;

    int ans = 0;
    int startYear = x / 10000;
    int endYear = y / 10000;

    // 枚举年份
    for (int year = startYear; year <= endYear; year++) {
        // 拆出年份四位
        int a = year / 1000;         // 千位
        int b = year / 100 % 10;     // 百位
        int c = year / 10 % 10;      // 十位
        int d = year % 10;           // 个位

        // 根据回文关系构造月和日
        int month = d * 10 + c;
        int day = b * 10 + a;

        // 判断是否合法日期
        if (month < 1 || month > 12) continue;
        if (day < 1 || day > getDays(year, month)) continue;

        // 拼成完整日期
        int date = year * 10000 + month * 100 + day;

        // 判断是否在区间内
        if (date >= x && date <= y) ans++;
    }

    cout << ans << endl;
    return 0;
}