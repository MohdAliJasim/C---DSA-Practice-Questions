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
        ListNode* reverse(ListNode* &head){
        ListNode* back = nullptr;
        ListNode* curr = head;

        ListNode* front = head->next;

        while(front){
            curr->next = back;
            back = curr; 
            curr= front;
            front = front->next;
        }
        curr->next = back;
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr){
            if(k == 1) return head;
            ListNode* newHead = reverse(head);
            return newHead;
        }
        ListNode* curr = head;
        ListNode* back = nullptr;
        while(curr){
            ListNode* tempHead = curr;
            ListNode* prev = curr;
            int count = 1;
            while(curr && count <= k){
                prev = curr;
                count++;
                curr = curr->next;
            }
            if(curr == nullptr && count <= k){
              
                if(back) back->next = tempHead;
                return head;
            } 
            prev->next = nullptr;
           ListNode* revHead =  reverse(tempHead);
            if(tempHead == head){
                head = prev;
            }
            if(back) back->next = revHead;
            back = tempHead;
        }
        return head;
    }

};