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
    ListNode* rev(ListNode* &head){
        if(!head or !head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = front;
            if(front) front = front->next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next; 
        ListNode* temp = head;
        ListNode* tail = NULL;

        while(temp){
            int cnt = 1; 
            ListNode* tempHead = temp;
            while(cnt != k && temp){
                temp = temp->next;
                cnt++;
            }
            if(!temp){
                tail->next = tempHead;
                return head;
            }
            next  = temp->next;
            temp->next = nullptr;
            ListNode* revHead = rev(tempHead);
            if(tempHead == head) head = revHead;
            if(tail) tail->next = revHead;
            tail = tempHead;
            temp = next;
        }
        return head;
    }
};