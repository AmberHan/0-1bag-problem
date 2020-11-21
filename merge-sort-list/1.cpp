#include<iostream>
#include<cstdlib>

using namespace std;
struct ListNode {
     int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* sortMerge(ListNode* head){
        if(head == nullptr || head->next == nullptr)return head;
        ListNode* slow=head,* fast=head->next;
        //快慢指针找到中间节点
        while(fast && fast ->next){
            fast = fast ->next->next;
            slow = slow ->next;
        }
        ListNode* nexthead = slow->next;
        slow->next = nullptr;
        //left;head-slow
        ListNode* m1 = sortMerge(head);
        //right;nexthead-
        ListNode* m2 = sortMerge(nexthead);
        //m3哑节点
        ListNode* dummy = new ListNode(0);
        ListNode* prehead = dummy;
        //双指针，插入排序
        while(m1 || m2){
            //m1有:m2没了、m1节点值小
            if(m1 != nullptr && (m2 == nullptr || m1->val <= m2->val)){
                prehead->next = m1;
                m1 = m1->next;
            }
            //m2有:m1没了、m2节点值小
            else if(m2 != nullptr && (m1 == nullptr || m1->val > m2->val)){
                prehead->next = m2;
                m2 = m2->next;
            }
            prehead = prehead->next;
        }
        //列表尾部置空
        prehead->next = nullptr;
        return dummy->next;
    }
 
    ListNode* sortList(ListNode* head) {
        return sortMerge(head);
    }
};
int main(){
    ListNode node1(1);   
    ListNode node2(3);
    ListNode node3(-1);
    ListNode node4(2);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    Solution a;
    ListNode *m = a.sortList(&node1);
    while(m){
        cout << m->val<<' ';
        m = m->next;
    }
    return 0;
}