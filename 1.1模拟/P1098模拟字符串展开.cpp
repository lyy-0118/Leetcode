#include <iostream>
#include <algorithm>

using namespace std;

int p1, p2, p3, n;
string s;
string ret;

// 判断是否是数字字符
bool isdig(char ch)
{
    return ch >= '0' && ch <= '9';
}

// 判断是否是小写字母
bool islet(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

// 把 [left, right] 之间的字符展开
// left, right 这两个字符是不做处理
void add(char left, char right)
{
    string t;

    // 遍历中间的字符
    for(char ch = left + 1; ch < right; ch++)
    {
        char tmp = ch;
        // 处理 p1
        if(p1 == 2 && islet(tmp)) tmp -= 32; // 小写变大写
        else if(p1 == 3) tmp = '*'; // 变成星号

        // 处理 p2
        for(int i = 0; i < p2; i++)
        {
            t += tmp;
        }
    }

    // 处理 p3
    if(p3 == 2) reverse(t.begin(), t.end());

    ret += t;
}

int main()
{
    cin >> p1 >> p2 >> p3 >> s;
    n = s.size();

    for(int i = 0; i < n; i++)
    {
        char ch = s[i];

		//如果当前字符不是减号，或者减号出现在最前面/最后面，那么它不能作为展开符号，直接加入结果
        if(s[i] != '-' || i == 0 || i == n - 1) ret += ch;
        else
        {
            char left = s[i - 1], right = s[i + 1];
            // 判断是否展开
            //可以展开的两种情况：
			//1.左右都是数字，并且右边比左边大
            //2.左右都是小写字母，并且右边比左边大
            if(isdig(left) && isdig(right) && right > left ||
               islet(left) && islet(right) && right > left)
            {
                // 展开
                add(left, right);
            }
            else 
            {
                ret += ch;
            }
        }
    }
    cout << ret << endl;
    return 0;
}