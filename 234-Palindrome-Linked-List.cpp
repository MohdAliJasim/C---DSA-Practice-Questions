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
        if(head->next == nullptr) return head;

        ListNode* newHead = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head->next == nullptr) return true;
        if(head->next->next == nullptr){
            if(head->next->val != head->val) return false;
            return true;
        }

        while(fast!=nullptr && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* reverseHead = reverse(slow);
      

        while(reverseHead!= nullptr ){
            if(head->val != reverseHead->val) return false;

            head= head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
};