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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* curr =head;
        if(head->next == nullptr) return head;
        ListNode* front = curr->next;
        while(curr){
            while(front != nullptr && curr->val == front->val){
                front = front->next;
            }
            curr->next = front; 
            curr = front;
            if(front) front = front->next;
        }
        return head;
    }
};