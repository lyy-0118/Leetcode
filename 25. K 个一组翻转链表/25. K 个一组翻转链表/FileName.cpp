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
//https://leetcode.cn/problems/reverse-nodes-in-k-group/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* dummy = new ListNode(0); //哨兵头节点
        dummy->next = head;
        // pre 指向每个 k-group 的前一个节点
        // end 指向每个 k-group 的最后一个节点
        ListNode* pre = dummy, * end = dummy;

        while (true) {
            // 1. 移动 end 指针，找到当前 k-group 的末尾
            for (int i = 0; i < k && end; i++) {
                end = end->next;
            }
            if (!end) break; //如果 end 为空，说明剩余的节点不足 k 个，结束循环
            // 2. 保存下一组的头节点，并断开当前组与后面链表的连接，方便反转
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = nullptr; // 断开
            // 3. 反转当前 k-group (从 start 到 end)
            // 反转后，start 变成了尾，end 变成了头
            pre->next = reverseList(start); // pre 连接到反转后的新头节点（原来的 end）
            // 4. 将反转后的尾部（原来的 start）连接到下一组的头部
            start->next = next;
            // 5. 重置 pre 和 end，为下一次循环做准备
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
private:
    // 一个辅助函数，用于反转一个链表（或子链表）
    // 返回反转后的新头节点
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
};