class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, vowel = 0;
        for (int i = 0; i < s.size(); i++) {
            // 1.入窗口
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                vowel++;
            }
            int left = i - k + 1;
            if (left < 0) { // 还没有形成窗口 长度不够
                continue;
            }
            // 2.形成窗口，更新
            ans = max(ans, vowel);
            if (ans == k) { // 答案已经等于理论最大值
                break;      // 无需再循环
            }

            // 3.左端点离开窗口，为下一个循环做准备
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                s[left] == 'o' || s[left] == 'u') {
                vowel--;
            }
        }
        return ans;
    }
};