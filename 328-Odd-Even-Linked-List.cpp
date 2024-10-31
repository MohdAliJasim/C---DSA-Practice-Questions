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
    ListNode* oddEvenList(ListNode* head) {
        int cnt = 2;
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode* prev = head;
        ListNode *curr = head->next;
        ListNode *evenHead = head->next;
        while(curr->next != NULL){
            prev->next = curr->next;
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(cnt & 1){
            curr->next = evenHead;
            prev->next = nullptr;
        }
        else{
            prev->next = evenHead;
        }
        return head;
    }
};