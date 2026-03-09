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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret(k, nullptr);
        ListNode* cur = head;
        int len = 0, x, y, z;
        // 1. 计算长度
        while (cur) {
            ++len;
            cur = cur->next;
        }
        x = len / k; // 每组最少分的节点数(基础长度)
        y = len % k; // 余数 (前 y 组需要长度 +1)
        z = k - y;   // 剩下的组 (不需要长度 +1)
        cur = head;
        // k组
        for (int i = 0; i < k; i++) {
            // 如果链表已经空了，且还有剩余组（k > len 的情况），
            // ret初始化时已经是 nullptr，直接跳出即可
            if (!cur)
                break;
            ret[i] = cur;                      // 记录当前这一组的头节点
            int cur_len = x + (i < y ? 1 : 0); // 当前组的长度 小于余数则加1
            // 移动 cur 指针到当前这组的【尾部】
            // 因为 cur 已经在第 1 个节点了，所以只需要往后走 currentLength - 1
            // 步
            for (int j = 0; j < cur_len - 1; j++) {
                cur = cur->next;
            }
            ListNode* nextNode = cur->next; // 先保存下一组的头
            cur->next = nullptr;            // 切断
            cur = nextNode;                 // cur 指向下一组，准备下一次循环
        }
        return ret;
    }
};