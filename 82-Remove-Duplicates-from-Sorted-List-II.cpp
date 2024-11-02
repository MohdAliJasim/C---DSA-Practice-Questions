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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> map;
        ListNode* temp = head;
        while(temp){
            map[temp->val]++;
            temp = temp->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            if(map[curr->val] > 1){
                if(curr == head){
                    head = curr->next;
                    delete curr;
                    curr = head;
                    continue;
                }
                prev->next= curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = curr; 
                curr = curr->next;
            }
        }
        return head;
    }
};