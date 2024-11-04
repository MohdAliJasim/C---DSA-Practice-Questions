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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if(!head || !head->next) return head;
        ListNode* front = curr->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = front;
            if(front) front = front->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        if(!head || !head->next) return true;
        ListNode* fast = head;
        fast = fast->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow->next;
        ListNode* revHead = reverse(newHead);
        ListNode* temp1 = head;
        ListNode* temp2 = revHead;
        while(temp2){
            if(temp1->val != temp2->val){
                newHead = reverse(revHead);
                slow->next = newHead;
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        newHead = reverse(revHead);
        slow->next =newHead;
        return true;
    }
};