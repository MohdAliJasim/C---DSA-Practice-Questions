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
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* front;
        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr= front;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = rev(head);
        ListNode* temp = head;
        while(temp->next){
            if(temp->val > temp->next->val){
                temp->next = temp->next->next;
            }
            else
            temp = temp->next;
        }
        head = rev(head);
        return head;
    }
};