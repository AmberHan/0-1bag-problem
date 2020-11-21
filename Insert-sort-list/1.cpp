#include<iostream>
#include<cstdlib>

using namespace std;
struct ListNode {
   int val;
   ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy -> next =  head;
        ListNode *curr = head;
        ListNode *insert,*Prehead;
        while(curr->next){
            if(curr->next->val >= curr->val){
                curr = curr -> next;
                continue;
            }
            insert = curr->next;
            curr->next = curr->next->next;
            Prehead  = dummy;
            while(Prehead ->next->val < insert->val){
                Prehead  = Prehead  ->next;
            }
            insert ->next = Prehead ->next;
            Prehead ->next = insert;
        }
        return dummy->next;
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
    ListNode *m = a.insertionSortList(&node1);
    while(m){
        cout << m->val<<' ';
        m = m->next;
    }
    return 0;
}