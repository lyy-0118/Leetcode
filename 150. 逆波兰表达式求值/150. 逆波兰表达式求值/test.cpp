//https://leetcode.cn/problems/evaluate-reverse-polish-notation/?envType=problem-list-v2&envId=array
//用到了栈的知识

class Solution {
public:
    // 修改1：参数加 const string& 避免拷贝，比较时使用双引号
    bool Judge(const string& s) {
        // 注意：这里必须是字符串比较，不能只是 s[0] == '+'，因为负数 "-10" 也有 '-'
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> numst;

        for (const auto& x : tokens) {
            // 如果是运算符
            if (Judge(x)) {
                // 修改2：题目保证表达式有效，直接取数即可，不需要 if(size>1)
                // 取出栈顶两个数字，注意顺序：先出来的是右操作数(n2)，后出来的是左操作数(n1)
                int n2 = numst.top();
                numst.pop();
                int n1 = numst.top();
                numst.pop();

                // 修改3：比较时使用双引号字符串
                if (x == "+") numst.push(n1 + n2);
                else if (x == "-") numst.push(n1 - n2);
                else if (x == "*") numst.push(n1 * n2);
                else if (x == "/") numst.push(n1 / n2);
            }
            else {
                // 如果是数字，直接转int入栈
                numst.push(stoi(x));
            }
        }
        return numst.top();
    }
};
