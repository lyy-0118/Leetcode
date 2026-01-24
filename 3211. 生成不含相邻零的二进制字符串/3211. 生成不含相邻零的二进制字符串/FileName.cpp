//找出所有长度为n不含00的字符串
//https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/
class Solution {
public:
    void backtrack(vector<string>& ret, string& current_s, int n) {
        //1.当字符串长度达到 n 时停止递归
        if (current_s.size() == n) {
            ret.push_back(current_s);
            return;
        }
        //2.递归步骤
        //a.总是添加‘1’
        current_s.push_back('1');
        backtrack(ret, current_s, n);
        current_s.pop_back();      //回溯
        //b.有条件的添加‘0’
        if (current_s.empty() || current_s.back() != '0') {
            current_s.push_back('0');
            backtrack(ret, current_s, n);
            current_s.pop_back();  //回溯
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        string current_string = "";
        backtrack(result, current_string, n);
        return result;
    }
};