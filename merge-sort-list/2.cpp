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
    //截取长度为ilen链表，并且队尾指向空，返回下一段头节点
    //可能截取不到，直接返回空
    ListNode* cut(ListNode* head, int n) {
        while(--n && head!=nullptr){
            head = head->next;
        }
        if(head ==nullptr){
            return nullptr;
        }
        ListNode* next = head->next;
        head->next=nullptr;
        return next;
    }
    //双指针，插入排序
    ListNode* mergesort(ListNode* head1,ListNode* head2){
        ListNode* mergedummy = new ListNode(0),*prehead1;
        prehead1 = mergedummy;
        while(head1!=nullptr && head2!=nullptr){
            if(head1->val<head2->val){
                prehead1 ->next = head1;
                prehead1 = prehead1->next;
                head1 = head1->next;
            }
            else{
                prehead1 ->next = head2;
                prehead1 = prehead1->next;
                head2 = head2->next;
            }
        }
        if(head1 != nullptr){
            prehead1->next = head1;
        }
        else if(head2 != nullptr){
            prehead1->next = head2;
        }
        else{
            prehead1->next = nullptr;
        } 
        prehead1 = mergedummy;
        return mergedummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head  == nullptr|| head->next == nullptr)return head;
        ListNode* dummy = new ListNode(0,nullptr); 
        // dummy->next = head;
        ListNode* prehead = dummy;
        ListNode* curr = head,*next;
        ListNode* node = head;
        int length = 0;
        while(node!=nullptr){
            node = node->next;
            length++;
        }
        ListNode* m1,*m2,*n1;
        for(int ilen = 1;ilen < length;ilen<<=1){
            while(curr!=nullptr){
                m1 = curr;
                //截取第一段长度为ilen链表m1，返回第二段头
                m2 = cut(curr,ilen);
                //截取第二段长度为ilen链表m2，返回next
                next = cut(m2,ilen);
                //对m1,m2链表进行插入排序，
                //排序后附加到新的链表，即哑节点之后
                //prehead指向队尾
                prehead->next= mergesort(m1,m2);
                while(prehead->next != nullptr){
                    prehead = prehead->next;
                    // cout << 1;
                }
                curr = next;
            }
            curr = dummy->next;
            prehead = dummy;
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
    ListNode *m = a.sortList(&node1);
    while(m){
        cout << m->val<<' ';
        m = m->next;
    }
    return 0;
}