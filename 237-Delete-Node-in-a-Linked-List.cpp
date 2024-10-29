/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prePrev;
        ListNode* prev = node;
        ListNode* curr =  node->next;
        while(curr){
            prev->val = curr->val;
            curr = curr->next;
            prePrev = prev;
            prev= prev->next;
        }
        prePrev->next = nullptr;
    }
};