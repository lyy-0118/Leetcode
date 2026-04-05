#include<bits/stdc++.h>
using namespace std;

//相交链表

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

//方法一：哈希集合
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> h;  //创建一个哈希映射表 <节点地址，有无出现>
        ListNode* p=headA;
        while(p){
            h[p]++; //将链表 headA中的每个节点加入哈希集合中
            p=p->next;
        }
        p=headB;    //然后遍历链表 headB，对于遍历到的每个节点，判断该节点是否在哈希集合中：
        while(p){
            if(h.count(p)) return p;  //如果存在哈希集合中，则是我们要找的相交点
            p=p->next;
        }
        return nullptr;  //遍历完还找不到则返回Null
    }
};

//方法二：双指针
class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *h1 = headA, *h2 = headB;
        if (!h1 || !h2)
            return nullptr;
        while (h1 != h2) {
            h1 = h1 ? h1->next : headB;
            h2 = h2 ? h2->next : headA;
        }
        return h1;
    }
};

int main(){
	
	return 0;
}