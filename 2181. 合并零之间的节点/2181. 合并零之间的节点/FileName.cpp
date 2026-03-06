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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        ListNode* cur = head->next;
        int sum = 0;
        while (cur) {
            int c_val = cur->val;
            if (c_val != 0) sum += c_val;
            else {
                ListNode* node = new ListNode(sum);
                tail->next = node;
                tail = tail->next;
                sum = 0;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};