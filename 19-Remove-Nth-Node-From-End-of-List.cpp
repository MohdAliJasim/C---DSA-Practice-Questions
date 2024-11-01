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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return (n==1)? nullptr: head;
        int cnt = 0;
        ListNode * temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int k = cnt - n;
        ListNode* prev = nullptr;
        temp = head;
        for(int i = 1; i<= k ;i++){
            prev = temp;
            temp = temp->next;
        }
        if(!prev) return head->next;
        prev->next = temp->next;
        delete (temp);
        return head;
    }
};