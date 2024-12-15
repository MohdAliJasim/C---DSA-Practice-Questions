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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr =head;
        if(!head || !head->next) return head;
        ListNode* front = curr->next;
        while(curr){
            curr->next =prev;
            prev =curr;
            curr = front;
            if(front) front =front->next;
        }
        return prev;
    }
};