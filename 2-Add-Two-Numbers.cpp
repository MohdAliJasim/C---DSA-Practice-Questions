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

void insertAtTail(ListNode* &tail , int data){
    ListNode *temp = new ListNode(data);
    if(tail == nullptr){
        tail = temp;
        return ;
    }
    tail->next = temp;
    tail = temp;
}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            insertAtTail(tail, (sum%10));
            carry = sum/10;

            l1 = l1->next;
            l2 = l2->next; 
        }
        while(l1){
            int sum = l1->val + carry;
            insertAtTail(tail, (sum%10));
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            insertAtTail(tail, (sum%10));
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry) insertAtTail(tail, carry);
        head = head->next;
        return head;
    }
};