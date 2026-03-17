//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Date {
    int y, m, d;
};
//判断闰年
bool isLeap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
//计算某个月有多少天
int getDays(int y, int m) {
    int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && isLeap(y)) return 29;
    return days[m];
}
//判断日期是否合法
bool isValid(Date x) {
    if (x.m < 1 || x.m > 12) return false;
    if (x.d < 1 || x.d > getDays(x.y, x.m)) return false;
    return true;
}
//让日期加一天
void nextDay(Date& x) {
    x.d++;
    if (x.d > getDays(x.y, x.m)) {
        x.d = 1;
        x.m++;
        if (x.m > 12) {
            x.m = 1;
            x.y++;
        }
    }
}
//支持日期比较
bool operator < (const Date& a, const Date& b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

bool operator <= (const Date& a, const Date& b) {
    return !(b < a);
}

int main() {
    Date l, r;
    cin >> l.y >> l.m >> l.d;
    cin >> r.y >> r.m >> r.d;
    //比如从 2024-03-18 遍历到 2024-03-21
    //最后可以在一个日期区间 [l, r] 内逐天遍历
    int cnt = 0;
    for (Date cur = l; cur <= r; nextDay(cur)) {
        cnt++;
    }
	cout << cnt << endl; 
    return 0;
}