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
        if(!head || !head->next) return head;

        ListNode* prev = nullptr;
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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head || !head->next) return true;



        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHead = reverse(slow);

        ListNode* tempH = head;
        ListNode* tempRH =revHead;

        while(tempRH){
            if(tempRH->val != tempH->val){
                reverse(revHead);
                return false;
            }
            tempRH = tempRH->next;
            tempH = tempH->next;
        }

        reverse(revHead);
        return true;
    }
};