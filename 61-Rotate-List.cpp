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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        if(k == 0) return head;
        int size = 0;
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }
        k = k%size;
        for(int i =0 ;i < k ;i++){
            ListNode* temp = head;
            ListNode* prev = nullptr;
            while(temp->next ){
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};