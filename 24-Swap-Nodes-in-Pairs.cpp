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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ans = head->next;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* front = temp;
        while(temp && temp->next){
            front = temp->next->next;
            temp->next->next = nullptr;

            ListNode* newHead = reverse(temp);

            if(prev) prev->next = newHead;
            prev = temp;
            temp = front;
        }
        if(temp) prev->next = temp; 
        return ans;
    }
};