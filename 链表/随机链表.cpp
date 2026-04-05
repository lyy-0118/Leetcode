/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        //1.在原链表后加上新创建的节点
        // 原链表：A -> B -> C
        // 插入后：A -> A' -> B -> B' -> C -> C'
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val); // 创建复制节点
            copy->next = cur->next;          // 复制节点接到原节点后面
            cur->next = copy;
            cur = copy->next;                // 跳到下一个原节点
        }
        //2.利用原节点的 random 设置复制节点的 random
        // 原节点 cur 的复制节点是 cur->next
        // 若 cur->random 指向某个原节点 x
        // 则复制节点的 random 应指向 x 的复制节点，也就是 x->next
        cur = head;
        while (cur) {
            Node* copy = cur->next;
            if (cur->random) {
                copy->random = cur->random->next;
            } else {
                copy->random = nullptr;
            }
            cur = copy->next; // 跳到下一个原节点
        }

        //3.将交错链表拆成原链表和新链表
        Node* newHead = head->next; // 新链表头结点
        cur = head;
        while(cur){
            Node* copy=cur->next;
            cur->next=copy->next;
            //改变新链表next
            if(copy->next) copy->next=copy->next->next;
            else copy->next=nullptr;

            cur=cur->next;
        }
        return newHead;
    }
};