/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // 起码三个节点,否则直接返回
        if (!head || !head->next || !head->next->next)
            return { -1, -1 };
        int minDist = -1, maxDist = -1;
        int first = -1, last = -1;  //first是第一个极值点，last是上个极值点
        int pos = 2; //pos记录当前位置索引 从第二个节点开始
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur->next) {
            ListNode* nxt = cur->next;
            if ((pre->val < cur->val && nxt->val < cur->val) ||
                (pre->val > cur->val && nxt->val > cur->val)) {
                //找到局部极值点
                if (last != -1) {
                    minDist = (minDist == -1) ? (pos - last) : min(pos - last, minDist);
                    maxDist = max(maxDist, pos - first);
                }
                if (first == -1) {
                    first = pos;
                }
                last = pos;
            }
            pre = cur;
            cur = nxt;
            pos++;
        }
        return { minDist, maxDist };
    }
};